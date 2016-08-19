

// RsaToolbox includes
#include "RsibBus.h"
using namespace RsaToolbox;

// C/C++
#include <cstdio>

// Qt
#include <QByteArray>
#include <QTextStream>
#include <QDebug>

// Rsib
#include "rsib.h"

/*!
 * \class RsaToolbox::RsibBus
 * \ingroup BusGroup
 * \brief Connects to an instrument via the Rohde & Schwarz Instrument Bus (RSIB)
 *
 * The Rohde\&Schwarz Instrument Bus is a <b>TCPIP only</b> connection bus
 * provided as an alternative to direct connection or NI-VISA. It partially conforms
 * to the VISA interface specification, but will only work with Rohde\&Schwarz
 * instruments.
 *
 * The status of the bus is reported in the IEEE 488.2 GPIB bus standard. Three
 * values are returned: \c ibsta, \c iberr and \c ibcntl.
 *
 * \c ibsta contains a bus status value. If \c ibsta indicates a communication error,
 * the \c iberr property will contain an error code corresponding to the specific
 * error. \c ibcntl is mostly used to communicate the amount of data that has been
 * written to or read from the instrument.
 *
 * Below is an example RsibBus::print() signal for a \c write("*IDN?") command:
   <tt><br>
Write:    "*IDN?"<br>
ibsta:    0x100 (IBSTA_CMPL)<br>
iberr:    0<br>
ibcntl:   6 (bytes)<br>
   </tt>
 *
 * In the preceding example, \c ibsta contains a hexadecimal value that indicates
 * the write operation completed successfully. \c iberr, then contains no additional
 * information. And, finally, \c ibcntl indicates that six bytes of data were
 * transferred to the instrument (including the termination character).
 *
 * \note RsibBus does not provide lock, unlock, local or remote mechanisms.
 * Local and remote functionality, however, is provided by the instrument via SCPI.
 *
 * \sa GenericBus, VisaBus
 */

/*!
 * \brief Default constructor.
 *
 * The default constructor is provided for compatibility with certain situations,
 * such as when RsibBus is a property in a class and will not be immediately and
 * properly constructed.
 *
 * A call to the isClosed() method will return false, indicating that a connection
 * to an instrument has not been made.
 *
 * \note A default constructed RsibBus object should not be used for communication.
 * It should be reinstantiated with valid connection information.
 *
 * \param parent
 */
RsibBus::RsibBus(QObject *parent)
    :GenericBus(parent) {
    _instrument = -1;
}

/*!
 * \brief The well-formed constructor returns with an instrument connection, if
 * possible.
 *
 * If \c connectionType is of type TCPIP and \c address is a valid address to a
 * Rohde \& Schwarz instrument, the resulting instance will hold a valid
 * connection to the instrument at \c address. Connection status should be tested
 * with \c isOpen() and \c isClosed() before proceeding. No guarantee is made
 * as to the behavior of RsibBus when no connection is present.
 *
 * \c timeout_ms is the time before an attempted operation is considered
 * unsuccessful.
 *
 * \note Only \c RsaToolbox::TCPIP_CONNECTION is possible with RsibBus. GPIB,
 * USB and other connection methods are not supported.
 *
 * \param connectionType
 * \param address
 * \param bufferSize_B
 * \param timeout_ms
 * \param parent
 */
RsibBus::RsibBus(ConnectionType connectionType, QString address,
                 uint bufferSize_B, uint timeout_ms,
                 QObject *parent)
    :GenericBus(connectionType, address,
                bufferSize_B, timeout_ms,
                parent)
{
    // Only handles TCPIP
    if (connectionType != TCPIP_CONNECTION) {
        _instrument = -1;
        _connectionType = NO_CONNECTION;
        return;
    }

    _instrument = RSDLLibfind(address.toUtf8().data(),
                              &_ibsta, &_iberr, &_ibcntl);

    // Set timeout
    if (isOpen())
        setTimeout(timeout_ms);
}

/*!
 * \brief Destructor
 *
 * The destructor automatically disconnects from the instrument, if
 * necessary.
 */
RsibBus::~RsibBus() {
    if (isOpen())
        RSDLLibonl(_instrument, 0, &_ibsta, &_iberr, &_ibcntl);
}

/*!
 * \brief Determines if instrument connection is present
 * \return Status of connection
 */
bool RsibBus::isOpen() const {
    return(_instrument != -1);
}

/*!
 * \brief Sets the time until timeout for instrument communication
 *
 * \c time_ms is the timeout time used for all future
 * communication. This value will overwrite the value provided in the constructor.
 *
 * \param time_ms Timeout, in milliseconds
 */
void RsibBus::setTimeout(uint time_ms) {
    GenericBus::setTimeout(time_ms);
    RSDLLibtmo(_instrument, (short)_timeout_ms, &_ibsta, &_iberr, &_ibcntl);
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
 * \param buffer
 * \param bufferSize
* \return \c true if read is successful; \c false otherwise
 * \sa write(), query()
 */
bool RsibBus::read(char *buffer, unsigned int bufferSize) {
    RSDLLilrd(_instrument, buffer, bufferSize, &_ibsta, &_iberr, &_ibcntl);
    if (!isError()) {
        nullTerminate(buffer, bufferSize, _ibcntl);
        printRead(buffer, _ibcntl);
        return(true);
    }
    else {
        buffer[0] = '\0';
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
 * \param scpiCommand
 * \return \c true if write is successful; \c false otherwise
 * \sa read(), query()
 */
bool RsibBus::write(QString scpi) {
    return binaryWrite(scpi.toUtf8());
}

/*!
 * \brief Reads binary data from instrument
 *
 * \note bufferSize must be greater than the
 * amount of data to be read, otherwise an
 * incomplete read will occur.
 *
 * \param buffer
 * \param bufferSize
 * \param bytesRead
 * \return \c true if read is successful;
 * \c false otherwise
 * \sa read(), write(), query()
 */
bool RsibBus::binaryRead(char *buffer, uint bufferSize,
                         uint &bytesRead)
{
    if (read(buffer, bufferSize)) {
        bytesRead = _ibcntl;
        return true;
    }
    else {
        bytesRead = 0;
        return false;
    }
}
/*!
 * \brief Writes binary data from instrument
 * \param scpiCommand
 * \return \c true if write is successful;
 * \c false otherwise
 * \sa read(), write(), query()
 */
bool RsibBus::binaryWrite(QByteArray scpi) {
    RSDLLilwrt(_instrument, scpi.data(), scpi.size(), &_ibsta, &_iberr, &_ibcntl);
    if (scpi.size() > MAX_PRINT)
        scpi = QByteArray(scpi.data(), MAX_PRINT+1);
    printWrite(scpi);

    if (isError()) {
        emit error();
        return false;
    }
    else {
        return true;
    }
}

/*!
 * \brief Placeholder for compatibility with \c GenericBus.
 *
 * RSIB (and therefore \c RsibBus) <b>does not</b> provide a
 * lock\\unlock mechanism. This method will emit \c print() with the
 * message "Lock not available via RSIB".
 *
 * \note \c VisaBus provides a lock\\unlock mechanism. If the
 * application requires it, use VisaBus instead.
 *
 * \return false
 * \sa VisaBus, VisaBus::lock(), VisaBus::unlock()
 */
bool RsibBus::lock() {
    emit print("Lock not available via RSIB\n\n");
    return(false);
}

/*!
 * \brief Placeholder for compatibility with \c GenericBus.
 *
 * RSIB (and therefore \c RsibBus) <b>does not</b> provide a
 * lock\\unlock mechanism. This method will emit \c print() with the
 * message "Unlock not available via RSIB".
 *
 * \note \c VisaBus provides a lock\\unlock mechanism. If the
 * application requires it, use VisaBus instead.
 *
 * \return false
 * \sa VisaBus, VisaBus::lock(), VisaBus::unlock()
 */
bool RsibBus::unlock() {
    emit print("Unlock not available via RSIB\n\n");
    return(false);
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
* \return \c true if operation is successful; \c false otherwise
 * \sa VisaBus::remote()
 */
bool RsibBus::local() {
    RSDLLibsre(_instrument, 0, &_ibsta, &_iberr, &_ibcntl);
    emit print("Instrument in local mode\n\n");
    return(true);
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
* \return \c true if operation is successful; \c false otherwise
 * \sa VisaBus::remote()
 */
bool RsibBus::remote() {
    RSDLLibsre(_instrument, 1, &_ibsta, &_iberr, &_ibcntl);
    emit print("Instrument in remote mode\n\n");
    return(true);
}

/*!
 * \brief Emits \c RsibBus::print() with a user-friendly status message
 *
 * This method documents the health of the RsibBus connection. It contains
 * the \c ibsta, \c iberr and \c ibcntl property values with brief
 * explanations.
 *
 * Example \c print() signal contents:
   <tt><br>
    ibsta:    0x100 (IBSTA_CMPL)<br>
    iberr:    0<br>
    ibcntl:   17 (bytes)<br>
   </tt>
 */
QString RsibBus::status() const {
    QString text;
    QTextStream stream(&text);

    // Print ibsta
    stream << "ibsta:    0x" << hex << _ibsta;
    if ((_ibsta & IBSTA_ERR) != 0)
        stream << " IBSTA_ERR";
    if ((_ibsta & IBSTA_TIMO) != 0)
        stream << " IBSTA_TIMO";
    if ((_ibsta & IBSTA_CMPL) != 0)
        stream << " IBSTA_CMPL";
    stream << endl;

    // Print iberr
    stream << "iberr:    " << dec << _iberr;
    if (isError()) {
        if ((_iberr & IBERR_DEVICE_REGISTER) != 0)
            stream << " IBERR_DEVICE_REGISTER";
        if ((_iberr & IBERR_CONNECT) != 0)
            stream << " IBERR_CONNECT";
        if ((_iberr & IBERR_NO_DEVICE) != 0)
            stream << " IBERR_NO_DEVICE";
        if ((_iberr & IBERR_MEM) != 0)
            stream << " IBERR_MEM";
        if ((_iberr & IBERR_TIMEOUT) != 0)
            stream << " IBERR_TIMEOUT";
        if ((_iberr & IBERR_BUSY) != 0)
            stream << " IBERR_BUSY";
        if ((_iberr & IBERR_FILE) != 0)
            stream << " IBERR_FILE";
        if ((_iberr & IBERR_UNKNOWN) != 0)
            stream << " IBERR_UNKNOWN";
    }
    stream << endl;

    // Print ibcntl
    stream << "ibcntl:   " << _ibcntl << " (bytes)" << endl;

    stream.flush();
    return text;
}

// Private
bool RsibBus::isError() const {
    return((_ibsta & IBSTA_ERR) != 0);
}


