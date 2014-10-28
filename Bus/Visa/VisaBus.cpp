

// RsaToolbox includes
#include "VisaBus.h"
using namespace RsaToolbox;

// C/C++
#include <cstdio>

// Qt
#include <QDebug>
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
    _resourceManager = NULL;
    _instrument = NULL;

    QString resource = "%1::%2::INSTR";
    switch (connectionType) {
    case TCPIP_CONNECTION:
    case GPIB_CONNECTION:
    case USB_CONNECTION:
        resource = resource.arg(toString(connectionType));
        resource = resource.arg(address);
        break;
    default:
        return;
    }

    visa_library.setFileName(VISA32);
    if (!visa_library.load()) {
        visa_library.setFileName(RSVISA32);
        if (!visa_library.load())
            return;
    }
    getFuncters();

    char buffer[500];
    _status = _viOpenDefaultRM(&_resourceManager);
    _viStatusDesc(_resourceManager, _status, buffer);
    if (_status != VI_SUCCESS) {
        setDisconnected();
        return;
    }

    QByteArray c = resource.toUtf8();
    _status = _viOpen(_resourceManager, c.data(), (ViUInt32)VI_NULL, (ViUInt32)timeout_ms, &_instrument);
    _viStatusDesc(_instrument, _status, buffer);
    if (_status != VI_SUCCESS) {
        _viClose(_resourceManager);
        setDisconnected();
    }
    else {
        setTimeout(_timeout_ms);
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
bool VisaBus::isVisaInstalled() {
    return QLibrary(VISA32).load();
}

/*!
 * \brief Determines if instrument connection is present
 * \return Status of connection
 */
bool VisaBus::isOpen() const {
    return _instrument != NULL;
}

/*!
 * \brief Set timeout, in ms
 */
void VisaBus::setTimeout(uint time_ms) {
    GenericBus::setTimeout(time_ms);
    if (isOpen())
        _viSetAttribute(_instrument, VI_ATTR_TMO_VALUE, time_ms);
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
bool VisaBus::read(char *buffer, uint bufferSize) {
    _status = _viRead(_instrument, (ViBuf)buffer, (ViUInt32)bufferSize, (ViPUInt32)&_byteCount);
    if (!isError()) {
        nullTerminate(buffer, bufferSize, _byteCount);
        printRead(buffer, _byteCount);
        return(true);
    }
    else {
        nullTerminate(buffer, bufferSize, 0);
        printRead(buffer, 0);
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
bool VisaBus::write(QString scpi) {
    return binaryWrite(scpi.toUtf8());
}

/*!
 * \brief VisaBus::binaryRead
 * \param buffer
 * \param bufferSize
 * \param bytesRead
 * \return
 */
bool VisaBus::binaryRead(char *buffer, uint bufferSize,
                         uint &bytesRead)
{
    if (read(buffer, bufferSize)) {
        bytesRead = _byteCount;
        return true;
    }
    else {
        bytesRead = 0;
        return false;
    }
}
/*!
 * \brief Writes binary data to instrument
 * \param scpiCommand
 * \return \c true if write is successful;
 * \c false otherwise
 */
bool VisaBus::binaryWrite(QByteArray scpi) {
    _status = _viWrite(_instrument, (ViBuf)scpi.data(), (ViUInt32)scpi.size(), (ViPUInt32)&_byteCount);
    if (scpi.size() > MAX_PRINT)
        scpi = QByteArray(scpi.data(), MAX_PRINT+1);
    printWrite(scpi);
    if (isError()) {
        emit error();
        return(false);
    }
    else {
        return(true);
    }
}

QString VisaBus::status() const {
    const int bufferSize = 500;
    char buffer[bufferSize];
    _viStatusDesc(_instrument, _status, buffer);

    QString text;
    QTextStream stream(&text);
    stream << "Bytes: " << _byteCount << endl;
    stream << "Status: 0x" << hex << _status << dec;
    stream << " " << QString(buffer).trimmed() << endl;
    stream.flush();
    return text;
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
    _status = _viLock(_instrument, VI_EXCLUSIVE_LOCK, ViUInt32(_timeout_ms), VI_NULL, VI_NULL);
    bool isLocked = !isError();
    if (isLocked)
        emit print("Instrument locked\n" + status() + "\n");
    else {
        if (visa_library.fileName().contains(RSVISA32, Qt::CaseInsensitive))
            emit print("RsVisa does not implement locking mechanism!\n" + status() + "\n");
        else
            emit print("Could not lock instrument\n" + status() + "\n");
    }

    return isLocked;
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
        emit print("Instrument unlocked\n" + status() + "\n");
    else {
        if (visa_library.fileName().contains(RSVISA32, Qt::CaseInsensitive))
            emit print("RsVisa does not implement unlocking mechanism!\n" + status() + "\n");
        else
            emit print("Could not unlock instrument\n" + status() + "\n");
    }

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
    bool isLocal = write("@LOC\n");
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
    bool isRemote = write("@REM\n");
    if (isRemote)
        emit print("Instrument in remote mode\n\n");
    else
        emit print("Could not put instrument into remote mode\n\n");

    return(isRemote);
}

void VisaBus::setDisconnected() {
    _resourceManager = NULL;
    _instrument = NULL;
}
void VisaBus::getFuncters() {
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


