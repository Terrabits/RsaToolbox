

// RsaToolbox includes
#include "VisaBus.h"
using namespace RsaToolbox;

// C/C++
#include <cstdio>

// Qt
#include <QByteArray>


/*!
 * \class RsaToolbox::VisaBus
 * \ingroup BusGroup
 * \brief Establishes a connection with an instrument via the NI-VISA bus
 *
 * \c VisaBus requires that NI-VISA is installed on the target system. To
 * check for this at runtime, use the static function VisaBus::isVisaPresent().
 * Use of VisaBus without NI-VISA present will cause a runtime error.
 *
 * Example use:
 * \code
    #include <VisaBus.h>
    #include <QMessageBox>
    ...
    if (VisaBus::isVisaPresent() == false) {
        QMessageBox::warning(this, "My Application",
            "This application requires NI-VISA. Please install VISA and try again");
        return;
    }

    VisaBus bus(TCPIP_CONNECTION, "192.168.0.1", 1000);
    if (bus.isClosed()) {
        QMessageBox::warning(this, "My Application",
            "Instrument not found at 192.168.0.1; connect instrument and try again.");
        return;
    }


    bus.write("*RST");
    ...
   \endcode
 * \sa GenericBus, RsibBus
 */

/*!
 * \brief Default constructor; constructs empty VisaBus instance.
 *
 * This constructor is provided as a convenience in situations
 * where a default constructor is required, for example when
 * VisaBus is a property in a class. Care should be taken to
 * eventually reconstruct VisaBus with a connection to an instrument.
 *
 * \param parent
 */
VisaBus::VisaBus(QObject *parent)
    :GenericBus(parent) {
    _resourceManager = NULL;
    _instrument = NULL;
}

/*!
 * \brief Constructor for a VisaBus instance that is connected to an instrument.
 *
 * This constructor attempts to connect to the instrument at \c address via the
 * \c connectionType interface. VisaBus::isOpen() and VisaBus::isClosed() test
 * for successful connection to an instrument.
 *
 * \param connectionType
 * \param address
 * \param bufferSize_B
 * \param timeout_ms
 * \param parent
 */
VisaBus::VisaBus(ConnectionType connectionType, QString address,
                 uint bufferSize_B, uint timeout_ms,
                 QObject *parent)
    :GenericBus(connectionType, address,
                bufferSize_B, timeout_ms,
                parent)
{
    char buffer[500];
    _resourceManager = NULL;
    _instrument = NULL;
    visa_library.setFileName(FILENAME);
    QString resource_string;
    if (visa_library.load()) {
        if (connectionType == TCPIP_CONNECTION) {
            resource_string = QString("TCPIP::") + address + QString("::INSTR");
        }
        else if (connectionType == GPIB_CONNECTION) {
            resource_string = QString("GPIB::") + address + QString("::INSTR");
        }
        else if (connectionType == USB_CONNECTION) {
            resource_string = QString("USB::") + address + QString("::INSTR");
        }
        else {
            notConnected();
            return;
        }
        retrieveFunctors();
        _status = _viOpenDefaultRM(&_resourceManager);
        _viStatusDesc(_resourceManager, _status, buffer);
        if (_status != VI_SUCCESS) {
            notConnected();
            return;
        }
        QByteArray c_string = resource_string.toUtf8();
        _status = _viOpen(_resourceManager, c_string.data(), (ViUInt32)VI_NULL, (ViUInt32)timeout_ms, &_instrument);
        _viStatusDesc(_instrument, _status, buffer);
        if (_status != VI_SUCCESS) {
            notConnected();
            return;
        }
        return;
    }
    else {
        // VISA dll cannot be found on the system.
        notConnected();
    }
}

/*!
 * \brief Destructor.
 *
 * The destructor will automatically close the connection to the instrument, if open.
 */
VisaBus::~VisaBus() {
    if (isOpen()) {
        _viClose(_instrument);
        _viClose(_resourceManager);
    }
    visa_library.unload();
}

/*!
 * \brief Determines if NI-VISA is installed
 *
 * NI-VISA is required to create an instance of the VisaBus class. Use this function
 * to check for NI-VISA and prevent a runtime error. If NI-VISA is not present, consider
 * either warning the user and exiting or connecting with a different bus, such as
 * RsibBus.
 *
 * \return Presence of NI-VISA installation
 * \sa RsibBus
 */
bool VisaBus::isVisaPresent() {
    return(QLibrary(FILENAME).load());
}

/*!
 * \brief Determines if instrument connection is present
 * \return Status of connection
 */
bool VisaBus::isOpen() const {
    return(_connectionType != NO_CONNECTION);
}

/*!
 * \brief Sets the time until timeout for instrument communication
 *
 * \c time_ms is the timeout time used for all future
 * communication. This value will overwrite the value provided in the constructor.
 *
 * \param time_ms Timeout, in milliseconds
 */
void VisaBus::setTimeout(uint time_ms) {
    GenericBus::setTimeout(time_ms);
}

/*!
 * \brief Read data from the instrument
 *
 * \c read will request data from the instrument and place it into the \c buffer
 * of size \c bufferSize. \c read is usually proceeded by a \c write command that
 * elicits a response (for example, \c "*IDN?"). It is important to ensure that the
 * data to be read does not exceed \c bufferSize bytes in size. When reading more
 * data than \c bufferSize, a partial read will occur and a subsequent read will
 * be necessary to retrieve the rest of the data.
 *
 * True is returned upon a successful read; false otherwise.
 *
 * \param buffer Buffer of type \c char*
 * \param bufferSize The size (in \c char or bytes) of the buffer
 * \return \c true if read is successful;
 * \c false otherwise
 */
bool VisaBus::_read(char *buffer, uint bufferSize) {
    QString text;
    QTextStream stream(&text);
    _status = _viRead(_instrument, (uchar *)buffer, (ViUInt32)bufferSize, &_bytesRead);
    if (_status >= VI_SUCCESS) {
        terminateCString(buffer, bufferSize);
        stream << "Received: ";
        stream << truncateCString(buffer);
        stream << endl;
        printStatus(stream);
        stream << endl;
        stream.flush();
        emit print(text);
        return(true);
    }
    else { // error
        buffer[0] = '\0';
        stream << "Error reading from instrument." << endl;
        printStatus(stream);
        stream << endl;
        stream.flush();
        emit print(text);
        emit error();
        return(false);
    }
}
/*!
 * \brief Writes a string of \c char data to the instrument
 *
 * The string contained in scpiCommand is converted to type \ char* and written to the
 * instrument. It is important that all characters in scpiCommand be ASCII compatible.
 *
 * \param scpiCommand String to be written to the instrument
 * \return \c true if write is successful;
 * \c false otherwise
 */
bool VisaBus::_write(QString scpiCommand) {
    QString text;
    QTextStream stream(&text);
    QByteArray c_string = scpiCommand.toUtf8();
    _status = _viWrite(_instrument, (uchar *)c_string.data(), c_string.size(), &_bytesRead);
    if (_status >= VI_SUCCESS) {
        stream << "Sent:     \"" << scpiCommand.trimmed() <<  "\"" << endl;
        printStatus(stream);
        stream << endl;
        stream.flush();
        emit print(text);
        return(true);
    }
    else { // error
        stream << "Error sending \"" << scpiCommand.trimmed() << "\"" << endl;
        printStatus(stream);
        stream << endl;
        stream.flush();
        emit print(text);
        emit error();
        return(false);
    }
}

/*!
 * \brief VisaBus::binaryRead
 * \param buffer
 * \param bufferSize
 * \param bytesRead
 * \return
 */
bool VisaBus::_binaryRead(char *buffer, uint bufferSize, uint &bytesRead)
{
    bool isSuccessful
            = _read(buffer, bufferSize);
    if (isSuccessful)
        bytesRead = _bytesRead;
    else
        bytesRead = 0;

    return(isSuccessful);
}
/*!
 * \brief Writes binary data to instrument
 * \param scpiCommand
 * \return \c true if write is successful;
 * \c false otherwise
 */
bool VisaBus::_binaryWrite(QByteArray scpiCommand) {
    QString text;
    QTextStream stream(&text);
    ViUInt32 writeCount;
    _status = _viWrite(_instrument, (uchar*)scpiCommand.data(), scpiCommand.size(), &writeCount);
    if (_status >= VI_SUCCESS) {
        stream << "Sent:     " << truncateCString(scpiCommand.constData()) << endl;
        printStatus(stream);
        stream << endl;
        stream.flush();
        emit print(text);
        return(true);
    }
    else { // error
        stream << "Error sending " << truncateCString(scpiCommand.constData()) << endl;
        printStatus(stream);
        stream << endl;
        stream.flush();
        emit print(text);
        emit error();
        return(false);
    }
}

/*!
 * \brief Requests exclusive remote access to the instrument
 *
 * VISA provides the capability for multiple applications to access an instrument
 * simultaneously. To prevent conflict, it also provides a lock\\unlock mechanism.
 * Locking an instrument within an application guarantees exclusive remote access;
 * unlocking the instrument releases it for possible use by another application.
 *
 * While locking/unlocking is not required, it can be good practice in applications
 * where simultaneous access poses a problem.
 *
 * \note The instrument is automatically unlocked in the VisaBus destructor.
 *
 *
* \return \c true if lock is successful;
* \c false otherwise
 * \sa VisaBus::unlock()
 */
bool VisaBus::lock() {
    _status = _viLock(_instrument, VI_EXCLUSIVE_LOCK, (ViUInt32)_timeout_ms, VI_NULL, VI_NULL);
    bool isLocked = _status >= VI_SUCCESS;
    if (isLocked)
        emit print("Instrument locked\n\n");
    else
        emit print("Could not lock instrument\n\n");

    return(isLocked);
}
/*!
 * \brief Unlocks the instrument, making it available for remote access by
 * another application
 *
 * VISA provides the capability for multiple applications to access an instrument
 * simultaneously. To prevent conflict, it also provides a lock\\unlock mechanism.
 * Locking an instrument within an application guarantees exclusive remote access;
 * unlocking the instrument releases it for possible use by another application.
 *
 * While locking/unlocking is not required, it can be good practice in applications
 * where simultaneous access poses a problem.
 *
 * \note The instrument is automatically unlocked in the VisaBus destructor.
 *
 *
 * \return \c true if unlock is successful;
 * \c false otherwise
 * \sa VisaBus::lock()
 */
bool VisaBus::unlock() {
    _status = _viUnlock(_instrument);
    bool isUnlocked = _status >= VI_SUCCESS;
    if (isUnlocked)
        emit print("Instrument unlocked\n\n");
    else
        emit print("Could not unlock instrument\n\n");

    return(isUnlocked);
}
/*!
 * \brief Places the instrument in local mode
 *
 * Instruments usually modify their behavior when accessed remotely; for example,
 * by turning off the screen or hiding softkey input. The local/remote methods
 * explicitly command the instrument to a local or remote behavioral mode. This can
 * be useful in applications that require user-instrument interaction.
 *
 * \note A \c remote or \c local message at the bus level may not always
 * work. Instruments in general have a SCPI command for this
 * (such as "@LOC" and "@REM" for local and remote, respectively, with
 * Rohde \& Schwarz VNAs).
 *
 * \return \c true if local is successful;
 * \c false otherwise
 * \sa VisaBus::remote()
 */
bool VisaBus::local() {
    bool isLocal = _write("@LOC\n");
    if (isLocal)
        emit print("Instrument in local mode\n\n");
    else
        emit print("Could not put instrument into local mode\n\n");

    return(isLocal);
}
/*!
 * \brief Places the instrument in remote mode
 *
 * Instruments usually modify their behavior when accessed remotely; for example,
 * by turning off the screen or hiding softkey input. The local/remote methods
 * explicitly command the instrument to a local or remote behavioral mode. Placing
 * an instrument in remote mode usually prevents the user from interacting with it.
 * This can be very useful depending on the application.
 *
 * \note Most instruments will automatically switch to remote mode upon establishing
 * a remote connection or after receiving the first SCPI command.
 *
 * \note A \c remote or \c local message at the bus level may not always
 * work. Instruments in general have a SCPI command for this
 * (such as "@LOC" and "@REM" for local and remote, respectively, with
 * Rohde \& Schwarz VNAs).
 *
 * \return \c true if remote is successful;
 * \c false otherwise
 * \sa VisaBus::remote()
 */
bool VisaBus::remote() {
    bool isRemote = _write("@REM\n");
    if (isRemote)
        emit print("Instrument in remote mode\n\n");
    else
        emit print("Could not put instrument into remote mode\n\n");

    return(isRemote);
}

/*!
 * \brief Emits \c VisaBus::print() with a user-friendly status message
 *
 * This method documents the health of the VisaBus connection. It contains
 * both a hexadecimal status code and a human-readable status message. See the NI-VISA
 * documentation for an explanation of the hexadecimal status code.
 *
 * Example:
 * <tt> ViStatus: 0x0 Operation completed successfully.</tt>
 */
void VisaBus::printStatus() const {
    QString text;
    QTextStream stream(&text);
    printStatus(stream);
    emit print(text);
}

// Private
void VisaBus::printStatus(QTextStream &stream) const {
    const int bufferSize = 500;
    char buffer[bufferSize];
    _viStatusDesc(_instrument, _status, buffer);
    stream << "ViStatus: 0x" << hex << _status << dec;
    stream << " " << QString(buffer).trimmed() << endl;
    stream.flush();
}

void VisaBus::notConnected() {
    // Handle unknown/unconnectable device situation
    _connectionType = NO_CONNECTION;
    _resourceManager = NULL;
    _instrument = NULL;
}
void VisaBus::retrieveFunctors() {
    _viStatusDesc = (_statusDescFuncter)visa_library.resolve("viStatusDesc");
    _viOpenDefaultRM = (_openDefaultRmFuncter)visa_library.resolve("viOpenDefaultRM");
    _viOpen = (_openFuncter)visa_library.resolve("viOpen");
    _viGetAttribute = (_getAttributeFuncter)visa_library.resolve("viGetAttribute");
    _viSetAttribute = (_setAttributeFuncter)visa_library.resolve("viSetAttribute");
    _viRead = (_readFuncter)visa_library.resolve("viRead");
    _viWrite = (_writeFuncter)visa_library.resolve("viWrite");
    _viClear = (_clearFuncter)visa_library.resolve("viClear");
    _viLock = (_lockFuncter)visa_library.resolve("viLock");
    _viUnlock = (_unlockFuncter)visa_library.resolve("viUnlock");
    _viClose = (_closeFuncter)visa_library.resolve("viClose");
}
bool VisaBus::isError() {
    return(_status < VI_SUCCESS);
}
void VisaBus::terminateCString(char *buffer, uint buffer_size) {
    // Null-terminate string:
    // R&S VNA firmware adds '\n' to the VERY END of a transfer
    // (ie only one '\n' at the ver end if multiple reads are necessary
    // to retrieve a single query response)
    if (_bytesRead < buffer_size)
        buffer[_bytesRead] = '\0';
    else
        /*buffer[buffer_size - 1] = '\0'*/; // Could overwrite data?
}
QString VisaBus::truncateCString(const char *buffer) {
    QString text = QString(buffer).trimmed();
    if (text.length() > MAX_PRINT) {
        text.truncate(MAX_PRINT);
        text += "...";
    }
    text = "\"" + text + "\"";
    return(text);
}


