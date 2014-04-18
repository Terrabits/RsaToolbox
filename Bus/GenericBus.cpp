

// RsaToolbox
#include "GenericBus.h"
using namespace RsaToolbox;

// Qt
//

/*!
 * \defgroup BusGroup Bus
 * Interchangeable instrument busses for
 * use with \c GenericInstrument subclasses
 */

/*!
 * \class RsaToolbox::GenericBus
 * \ingroup BusGroup
 * \brief \c %GenericBus is a pure virtual base class for
 *           an instrument connection bus.
 *
 * The \c %GenericBus class should be used as a template for
 * implementing bus connections for use with the \c RsaToolbox
 * framework. Most of the methods are purely virtual and
 * need to be implemented. Those that are not pure virtual
 * can be reimplemented and should call the equivalent
 * method in this base class.
 *
 * Protected variables \c _connectionType, \c _address and
 * \c _timeout_ms are set in the GenericBus constructors,
 * which should be called by a subclass.
 *
 * The \c _address property is the appropriately formatted,
 * \a bus-independent address of the instrument. For example,
 * for a local TCPIP connection address may be "127.0.0.1".
 * Similarly, an instrument connected via GPIB at address
 * 17 should have an \c _address value of "17".
 *
 * The setTimeout() method is virtual and can be
 * reimplemented by a base class if necessary. For most
 * instrument buses, such as Rsib and Visa, timeout is a
 * parameter send with each function call. In this situation
 * it is not necessary to reimplement setTimeout. In the
 * event that an action is required (in addition to updating
 * the \c _timeout_ms property), setTimeout() should be
 * reimplemented.
 *
 * read(), write() and query() are pure virtual, and
 * need to be reimplemented to work with the specific
 * instrument bus of the base class.
 *
 * lock(), unlock(), local() and remote() functions may
 * not be implemented in certain connection methods. For
 * example, TCPIP does not have any of these mechanisms. Visa
 * has an implementation of lock() and unlock(), but local()
 * and remote() only work with GPIB. In the event that a
 * particular instrument bus does not implement this
 * functionality, implement these functions to emit a print()
 * signal with a warning message; this will help document the
 * lack of functionality in a log file for troubleshooting.
 *
 * \sa RsibBus, VisaBus
 *
 */

/*!
 * \fn GenericBus::print(QString text)
 * \brief Emits text to be printed to a log file
 *
 * As methods are called, \c print provides text summaries
 * that can be logged for troubleshooting. For example, a \c write
 * command would emit \c print with text containing the command
 * written and the status of the instrument bus upon completion.
 *
 * The \c print signal should be connected to a logging device, such
 * as RsaToolbox::Log.
 *
 * The exact contents of \c print are bus-dependent.
 * \sa Log, VisaBus, RsibBus
 */


/*!
 * \brief The default constructor
 *
 * This constructor is provided for
 * compatibility in instances where a default
 * constructor is important, for example when a GenericBus
 * subclass is used as a property in a class.
 *
 * Instances created with this constructor are not meant to
 * be used. Such instances will return isOpen() == false or
 * isClosed() == true. Any other method calls (such as read
 * write or query) may cause the application to crash.
 *
 * Subclasses of GenericBus can call this constructor to
 * initialize the protected properties of this class:
 * \code
   _connectionType = NO_CONNECTION;
   _address.clear();
   _timeout_ms = 0;
   \endcode
 *
 * \note As a general rule, the RsaToolbox::NO_CONNECTION value
 * can be used when a connection is not or cannot be
 * established, although this is not enforced by GenericBus.
 *
 * \param parent
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
 * \brief Constructor for a GenericBus instance
 *
 * Subclasses of GenericBus can call this constructor to
 * initialize the QObject base class, as well as the
 * protected properties of this class:
 * \code
    ConnectionType _connectionType;
    QString _address;
    uint _bufferSize_B;
    uint _timeout_ms;

    QScopedArrayPointer<char> _buffer;
   \endcode
 *
 * \note If \c bufferSize_B is not greater than zero,
 * a default value of 500 Bytes will be used.
 *
 * \param connectionType
 * \param address
 * \param bufferSize_B
 * \param timeout_ms
 * \param parent
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

/*!
 * \return Whether or not the connection is closed.
 * \sa isOpen()
 */
bool GenericBus::isClosed() const {
    return(!isOpen());
}

/*!
 * \return The RsaToolbox::ConnectionType to the instrument.
 */
ConnectionType GenericBus::connectionType() const {
    return(_connectionType);
}
/*!
 * \return Address for this connection
 */
QString GenericBus::address() const {
    return(_address);
}

/*!
 * \brief Returns the buffer size used for
 * read/query commands
 * \return Buffer size, in Bytes
 */
uint GenericBus::bufferSize_B() const {
    return(_bufferSize_B);
}
/*!
 * \brief Sets the buffer size used for
 * read/query commands
 *
 * \note Size must be greater than zero.
 *
 * \param size_B New buffer size, in Bytes
 */
void GenericBus::setBufferSize(uint size_B) {
    if (size_B > 0) {
        _bufferSize_B = size_B;
        _buffer.reset(new char[size_B]);
    }
}

/*!
 * \return The time until timeout, in milliseconds
 */
uint GenericBus::timeout_ms() const {
    return(_timeout_ms);
}
/*!
 * \brief Sets the timeout, in milliseconds
 * \param time_ms Time before timeout, in milliseconds
 */
void GenericBus::setTimeout(uint time_ms) {
    if (time_ms > 0)
        _timeout_ms = time_ms;
}

/*!
 * \brief GenericBus::read
 * \param buffer
 * \param bufferSize_B
 * \return
 */
bool GenericBus::read(char *buffer, uint bufferSize_B) {
    return(_read(buffer, bufferSize_B));
}

/*!
 * \brief Reads ASCII response from the
 * instrument
 *
 * \note bufferSize_B() must be equal to or
 * greater than the amount of data to be read,
 * otherwise a partial read will occur.
 *
 * \return Readback from instrument
 */
QString GenericBus::read() {
    if (_read(_buffer.data(), _bufferSize_B))
        return(QString(_buffer.data()));
    else
        return(QString());
}
/*!
 * \brief writes null-terminated, ASCII command to the
 * instrument
 * \param scpiCommand
 */
void GenericBus::write(QString scpiCommand) {
    _write(scpiCommand);
}
/*!
 * \brief Queries ASCII response from the
 * instrument
 *
 * \note bufferSize_B() must be equal to or
 * greater than the amount of data to be read,
 * otherwise a partial read will occur.
 *
 * \return Query result
 */
QString GenericBus::query(QString scpiCommand) {
    if (_write(scpiCommand))
        return(read());
    else
        return(QString());
}

/*!
 * \brief GenericBus::binaryRead
 * \param buffer
 * \param bufferSize_B
 * \param bytesRead
 */
bool GenericBus::binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead) {
    return(_binaryRead(buffer, bufferSize_B, bytesRead));
}

/*!
 * \brief Reads binary response from the
 * instrument
 *
 * The data read is returned to the caller as-is;
 * no null-terminations or assumentions are made.
 * This is appropriate when standard string
 * formatting would interfere with the read
 * operation, such as when transferring the
 * raw binary contents of a file.
 *
 * \note bufferSize_B() must be equal to or
 * greater than the amount of data to be read,
 * otherwise a partial read will occur.
 *
 * \return Readback from instrument
 */
QByteArray GenericBus::binaryRead() {
    uint bytesRead;
    if (_binaryRead(_buffer.data(), _bufferSize_B, bytesRead))
        return(QByteArray(_buffer.data(), bytesRead));
    else
        return(QByteArray());
}
/*!
 * \brief Writes binary data to instrument.
 *
 * The data contained in scpiCommand is written
 * to the instrument as-is; no null-terminations
 * or assumentions are made. This is appropriate
 * when standard string formatting would interfere
 * with the write operation, such as when
 * transferring the raw binary contents of a file.
 *
 * \param scpiCommand Command, including any binary parameters.
 */
void GenericBus::binaryWrite(QByteArray scpiCommand) {
    _binaryWrite(scpiCommand);
}
/*!
 * \brief Queries binary response to scpiCommand
 * from the instrument
 *
 * The data read is returned to the caller as-is;
 * no null-terminations or assumentions are made.
 * This is appropriate when standard string
 * formatting would interfere with the read
 * operation, such as when transferring the
 * raw binary contents of a file.
 *
 * \note bufferSize_B() must be equal to or
 * greater than the amount of data to be read,
 * otherwise a partial read will occur.
 *
 * \return Readback from instrument
 */
QByteArray GenericBus::binaryQuery(QByteArray scpiCommand) {
    if (_binaryWrite(scpiCommand))
        return(binaryRead());
    else
        return(QByteArray());
}

QString RsaToolbox::toString(ConnectionType connection_type) {
    if (connection_type == TCPIP_CONNECTION)
        return("TCPIP");
    if (connection_type == GPIB_CONNECTION)
        return("GPIB");
    if (connection_type == USB_CONNECTION)
        return("USB");
    // Else
    return("No Connection");
}
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
