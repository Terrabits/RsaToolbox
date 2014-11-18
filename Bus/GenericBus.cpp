#include "GenericBus.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
// #include <>


/*!
 * \defgroup BusGroup Bus
 * Interchangeable instrument busses for
 * use with \c GenericInstrument subclasses
 */

/*!
 * \brief Converts ConnectionType to a string
 *
 * This function produces a VISA-compatible resource
 * prefix.
 * "No Connection" is returned for \c NO_CONNECTION;
 *
 * \param connectionType
 * \return String representation of \c connectionType
 * \relates GenericBus
 * \relates VisaBus
 */
QString RsaToolbox::toString(ConnectionType connectionType) {
    if (connectionType == TCPIP_CONNECTION)
        return("TCPIP");
    if (connectionType == GPIB_CONNECTION)
        return("GPIB");
    if (connectionType == USB_CONNECTION)
        return("USB");
    // Else
    return("No Connection");
}

/*!
 * \brief Converts connection type string to \c ConnectionType
 *
 * Assumes input is VISA compatible.
 * Defaults to \c NO_CONNECTION for unknown strings.
 *
 * \param scpi Connection type string
 * \return \c ConnectionType
 * \relates GenericBus
 * \relates VisaBus
 */
ConnectionType RsaToolbox::toConnectionType(QString scpi) {
    if (scpi.contains("TCPIP", Qt::CaseInsensitive))
        return(TCPIP_CONNECTION);
    if (scpi.contains("GPIB", Qt::CaseInsensitive))
        return(GPIB_CONNECTION);
    if (scpi.contains("USB", Qt::CaseInsensitive))
        return(USB_CONNECTION);
    //else
    return(NO_CONNECTION);
}

/*!
 * \brief Creates VISA instrument resource string
 *
 * If \c type is \c NO_CONNECTION, an empty string is
 * returned. No other value checking is done. Make sure
 * the address string has a meaningful value.
 *
 * Example:
 * \c toVisaInstrumentResource(TCPIP_BUS, "127.0.0.1")
 * returns \c "TCPIP::127.0.0.1::INSTR"
 *
 * \param type ConnectionType
 * \param address Well-formed address
 * \return VISA resource string
 * \relates GenericBus
 * \relates VisaBus
 */
QString RsaToolbox::toVisaInstrumentResource(ConnectionType type, QString address) {
    if (type == NO_CONNECTION)
        return "";

    QString result = "%1::%2::INSTR";
    result = result.arg(toString(type));
    result = result.arg(address);
    return result;
}

/*!
 * \brief Safely null-character-terminates a
 * c-style string
 *
 * \note If the entire buffer is full (\c bytesUsed equals
 * \c bufferSize_B) no null termination is added.
 * This is to prevent loss of data.
 *
 * \param buffer C-style string
 * \param bufferSize_B String buffer size, in bytes
 * \param bytesUsed Portion of string that contains data, in bytes
 */
void RsaToolbox::nullTerminate(char *buffer, uint bufferSize_B, uint bytesUsed) {
    // Do not null terminate if it means
    // data will be overwritten
    if (bytesUsed < bufferSize_B)
        buffer[bytesUsed] = '\0';
}

/*!
 * \class RsaToolbox::GenericBus
 * \ingroup BusGroup
 * \brief \c %GenericBus is a \c pure \c virtual
 * base class for instrument connection
 * methods.
 *
 * This \c %GenericBus class is \c pure \c virtual
 * and must be implemented in a subclass.
 * See \c VisaBus and \c TcpBus for examples.
 *
 * The \c %GenericBus class should be used to add new
 * connection methods to \c RsaToolbox.
 * When doing so, all \c pure \c virtual methods need to be
 * implemented, the appropriate \c %GenericBus constructors
 * should be called, and, when reimplementing non-virtual
 * functions, the equivalent base class implementation
 * should called.
 *
 * The \c pure \c virtual methods that require reimplementation are
 *
 * \c public:
 * \li \code virtual bool isOpen() const \endcode
 * \li \code virtual bool read(char *buffer, uint bufferSize_B) \endcode
 * \li \code virtual bool write(QString scpi) \endcode
 * \li \code virtual bool binaryRead(char *buffer, int bufferSize_B, uint &bytesRead) \endcode
 * \li \code virtual bool binaryWrite(QByteArray scpi) \endcode
 * \li \code virtual QString status() const \endcode
 * \n
 * \c public slots:
 * \li \code virtual bool lock() \endcode
 * \li \code virtual bool unlock() \endcode
 * \li \code virtual bool local() \endcode
 * \li \code virtual bool remote() \endcode
 *
 * See the documentation for each method for
 * specific details and hints.
 *
 * \sa VisaBus, TcpBus
 */

/*!
 * \brief The default constructor
 *
 * The default constructor initializes a
 * \c GenericBus object that is not connected to
 * anything.
 *
 * That is:
 * \c connectionType() returns \c NO_CONNECTION
 * \c address() returns \c ""
 * and \c isOpen is \c false.
 *
 * Default constructors in base classes should call
 * this first.
 *
 * Calling \c read and \c write functions on a
 * disconnected bus will cause timeouts and other
 * errors to occur. A pointer to a \c NoBus
 * instance can be safely used as a placeholder
 * in the event your code may try to use it anyway.
 *
 * \note As a general rule, the RsaToolbox::NO_CONNECTION value
 * should be used when a connection is not or cannot be
 * established, although this is not enforced by GenericBus.
 * Always check \c isOpen and \c isClosed for a definitive
 * answer.
 *
 * \param parent Optional parent \c QObject
 */
GenericBus::GenericBus(QObject *parent) :
    QObject(parent)
{
    _connectionType = NO_CONNECTION;
    _address.clear();
    _bufferSize_B = 0;
    _timeout_ms = 0;
}
/*!
 * \brief \c GenericBus constructor for instrument
 * connection
 *
 * In the event \c bufferSize_B is \c 0, the
 * default value of \c 500 bytes will be used.
 * Similarly, a \c timeout_ms of \c 0 will be
 * replaced by a timeout of \c 1 second.
 *
 * \note Subclasses of GenericBus should call this
 * constructor, \b then establish a connection to the
 * instrument. Base class constructors in C++ are
 * unable to call virtual methods in the subclass
 * until both constructors are executed.
 *
 * \param connectionType
 * \param address
 * \param bufferSize_B Buffer size (in bytes) must be greater than zero
 * \param timeout_ms Timeout, in milliseconds. Must be greater than zero.
 * \param parent Optional parent \c QObject
 */
GenericBus::GenericBus(ConnectionType connectionType,
                       QString address,
                       uint bufferSize_B, uint timeout_ms,
                       QObject *parent) :
    QObject(parent)
{
    _connectionType = connectionType;
    _address = address;

    if (timeout_ms > 0)
        _timeout_ms = timeout_ms;
    else
        _timeout_ms = 1000;

    if (bufferSize_B > 0)
        setBufferSize(bufferSize_B);
    else
        setBufferSize(500);
}

/*! \fn bool GenericBus::isOpen()
 * \brief Returns connection status
 *
 * This method is \c pure \c virtual and must
 * be overloaded in base class implementations.
 *
 * \returns \c true if instrument is connected
 * \sa isClosed()
 */

/*!
 * \brief Returns bus state
 * \return /c true if connection is not open.
 * \sa isOpen()
 */
bool GenericBus::isClosed() const {
    return(!isOpen());
}

/*!
 * \brief Gets the connection type
 * \return \c ConnectionType
 */
ConnectionType GenericBus::connectionType() const {
    return(_connectionType);
}
/*!
 * \brief Gets the address
 * \return Address for connection
 */
QString GenericBus::address() const {
    return(_address);
}

/*!
 * \brief Gets the buffer size
 *
 * Gets the internal buffer size, in bytes,
 * that is currently being used.
 *
 * \return Buffer size, in Bytes
 */
uint GenericBus::bufferSize_B() const {
    return(_bufferSize_B);
}
/*!
 * \brief Gets the buffer size
 *
 * Gets the internal buffer size, in bytes,
 * that is currently being used.
 *
 * \note Size must be greater than zero.
 *
 * \param size_B Buffer size, in bytes
 */
void GenericBus::setBufferSize(uint size_B) {
    if (size_B > 0) {
        _bufferSize_B = size_B;
        _buffer.reset(new char[size_B]);
    }
}

/*!
 * \brief Gets the time until timeout
 * \return Timeout, in milliseconds
 */
uint GenericBus::timeout_ms() const {
    return(_timeout_ms);
}
/*!
 * \brief Sets the time until timeout
 * \param time_ms Timeout, in milliseconds
 */
void GenericBus::setTimeout(uint time_ms) {
    if (time_ms > 0)
        _timeout_ms = time_ms;
}

/*!
 * \fn virtual bool GenericBus::read(char *buffer, uint bufferSize_B)
 * \brief Reads from instrument using c-style
 * character buffer
 *
 * This method is \c pure \c virtual and must
 * be overloaded in base class implementations.
 * This function should call \c printRead internally.
 *
 * This function assumes that the read value is a
 * c-style string that is \b null \b terminated. As such,
 * it is assumed that the data to be read does not
 * contain invalid or reserved values (such as the
 * null character). \c binaryRead does not make
 * this assumption.
 *
 * A failed read should return \c false and return an empty
 * c-string:
 * \code
 * buffer[0] = '\0';
 * \endcode
 *
 * \note GenericBus uses this function, along with an
 * internal buffer, to implement other higher-level read
 * functions.
 *
 * \param buffer C-style character buffer
 * \param bufferSize_B Size of \c buffer, in bytes
 * \return \c true if read is successful
 */

/*!
 * \brief Reads C-string compatible data from
 * the instrument
 *
 * \note Certain characters (such as the null character) will
 * cause this function to truncate the c-string. Also note
 * that bufferSize_B() should be greater than or equal
 * to the expected read size (including null termination).
 * If you want to perform a read without these limitations,
 * (for example, when reading raw binary data in multiple
 * transactions) use \c binaryRead instead.
 *
 * \return Read response from instrument
 */
QString GenericBus::read() {
    if (read(_buffer.data(), _bufferSize_B))
        return(QString(_buffer.data()));
    else
        return(QString());
}

/*!
 * \fn virtual bool GenericBus::write(QString scpi)
 * \brief Writes \c scpi to the connected instrument
 *
 * This method is \c pure \c virtual and must
 * be overloaded in base class implementations.
 *
 * If in implementing this function
 * a C-style \c const \c char* representation of
 * \c scpi is necessary
 * (in a US-ASCII/Latin-1 character set) it
 * can be retrieved by calling:
 * \code
 * scpi.toLatin1().constData()
 * \endcode
 *
 * It is important to recognize
 * that the above pointer only
 * exists ephemerally, during the execution
 * of this line of code. This is because
 * \c const \c char* is pointing to
 * an internal buffer in QByteArray, which
 * disappears after this line is executed.
 *
 * If you need a persistent pointer,
 * use the verbose snippet below:
 * \code
 * QByteArray byteArray = scpi.toLatin1();
 * const char* cstring = byteArray.constData();
 * \endcode
 *
 * \note \c bufferSize_B does not limit \c write
 * comamnds, as the internal buffer is not used.
 *
 * \return \c true if successul
 */

/*!
 * \brief Queries for a string response to
 * \c scpi
 *
 * Internally \c query is a combination of
 * \c read and \c write. The limitations of
 * those methods inherently apply to \c query
 *
 * \param scpi Query command to be written
 * \return Result of the query \c scpi
 * \sa GenericBus::write(QString scpi), QString GenericBus::read()
 */
QString GenericBus::query(QString scpi) {
    if (write(scpi))
        return(read());
    else
        return(QString());
}

/*!
 * \brief Reads binary response from the
 * instrument
 *
 * The data is read and returned as-is;
 * no assumptions of content or string
 * terminations are made.
 * An example use-case would be in transferring
 * the raw, arbitrary contents of a file.
 *
 * \note Partial reads are allowed, and occur
 * when \c bufferSize_B is less than the total
 * read size. In this case, \c binaryRead should
 * be called until all data is read. It is the
 * responsibility of the callee to reassemble
 * the data correctly.
 *
 * \return Raw data read from the instrument
 */
QByteArray GenericBus::binaryRead() {
    uint bytesRead;
    if (binaryRead(_buffer.data(), _bufferSize_B, bytesRead))
        return(QByteArray(_buffer.data(), bytesRead));
    else
        return(QByteArray());
}

/*!
 * \fn virtual bool GenericBus::binaryWrite(QByteArray scpi)
 * \brief Writes raw data to the instrument
 *
 * This method is \c pure \c virtual and must
 * be overloaded in base class implementations.
 *
 * All data contained in \c scpi is written
 * as-is. The buffer size does not effect
 * this operation.
 *
 * \note \c scpi is not necessarily an actual
 * SCPI command.
 *
 * \param scpi Raw data to write
 * \return \c true if successful
 */

/*!
 * \brief Queries raw data response to scpi
 *
 * This method uses \c binaryWrite and
 * \c binaryRead internally. As such, it
 * has the same inherent restrictions as
 * those methods.
 *
 * \param scpi Query command
 * \return Raw data read from query
 * \sa binaryWrite, binaryRead
 */
QByteArray GenericBus::binaryQuery(QByteArray scpi) {
    if (binaryWrite(scpi))
        return(binaryRead());
    else
        return(QByteArray());
}

/*!
 * \fn virtual QString GenericBus::status() const
 * \brief Retrieves a human-readable bus
 * status message
 *
 * This method is \c pure \c virtual and must
 * be overloaded in base class implementations.
 *
 * This method is used internally to \c print
 * bus health information periodically to
 * log files.
 *
 * \return status message.
 * \sa printRead, printWrite
 */

/*!
 * \fn virtual bool GenericBus::lock()
 * \brief
 *
 * This method is \c pure \c virtual and must
 * be overloaded in base class implementations.
 *
 * For a connection method that does not implement
 * locking, this method should return false
 * and \c emit \c print to log an appropriate
 * warning.
 *
 * \return \c true if successful
 * \sa unlock
 */

/*!
 * \fn virtual bool GenericBus::unlock()
 * \brief
 *
 * This method is \c pure \c virtual and must
 * be overloaded in base class implementations.
 *
 * For a connection method that does not implement
 * locking, this method should return false
 * and \c emit \c print to log an appropriate
 * warning.
 *
 * \return \c true if successful
 * \sa lock
 */

/*!
 * \fn virtual bool GenericBus::local()
 * \brief
 *
 * This method is \c pure \c virtual and must
 * be overloaded in base class implementations.
 *
 * For a connection method that does not implement
 * this, this method should return false
 * and \c emit \c print to log an appropriate
 * warning.
 *
 * \return \c true if successful
 * \sa remote
 */

/*!
 * \fn virtual bool GenericBus::remote()
 * \brief
 *
 * This method is \c pure \c virtual and must
 * be overloaded in base class implementations.
 *
 * For a connection method that does not implement
 * this, this method should return false
 * and \c emit \c print to log an appropriate
 * warning.
 *
 * \return \c true if successful
 * \sa local
 */

/*!
 * \fn void GenericBus::error() const
 * \brief Emitted when a bus error occurs
 *
 * When creating methods for a \c %GenericBus
 * subclass, make sure to \c emit \c error()
 * when errors occur.
 */

/*!
 * \fn void GenericBus::print(QString text)
 * \brief Emits log info as necessary
 *
 * The \c print signal should be connected
 * to a logging device, such as
 * \c RsaToolbox::Log. \c GenericInstrument
 * does this for you.
 *
 * Messages are bus-dependent.
 *
 * \sa status, Log, GenericInstrument, Vna
 */

/*!
 * \brief Emits a pretty \c print summary for
 * a read operation
 *
 * This method should be called from subclass
 * implementations of \c read and \c binaryRead
 * to ensure correct logging occurs.
 *
 * \param buffer Read buffer
 * \param bytesRead Amount of data (in bytes) in \c buffer
 */
void GenericBus::printRead(char *buffer, uint bytesRead) const {
    QString text;
    if (bytesRead > MAX_PRINT) {
        text = QString(QByteArray(buffer, MAX_PRINT));
        text = text.trimmed();
        text += "...";
    }
    else {
        text = QString(QByteArray(buffer, bytesRead));
        text = text.trimmed();
    }
    text = QString("Read:     \"%1\"\n").arg(text);
    text += status();
    text += "\n";
    emit print(text);
}

/*!
 * /property static const int MAX_PRINT
 *
 * This property contains the truncated
 * size (100 characters) of long SCPI
 * commands when logging via
 * \c printWrite.
 *
 * \sa printWrite
 */

/*!
 * \brief Emits a pretty \c print summary for
 * a write operation
 *
 * This method should be called from subclass
 * implementations of \c write and \c binaryWrite
 * to ensure correct logging occurs.
 *
 * \note Long scpi commands are truncated
 * to \c MAX_PRINT characters.
 *
 * \param scpi Command written to the instrument
 * \sa MAX_PRINT
 */
void GenericBus::printWrite(QString scpi) const {
    QString text;
    scpi = scpi.trimmed();
    if (scpi.size() > MAX_PRINT) {
        scpi.truncate(MAX_PRINT);
        scpi += "...";
    }
    text = QString("Write:    \"%1\"\n").arg(scpi);
    text += status();
    text += "\n";
    emit print(text);
}
