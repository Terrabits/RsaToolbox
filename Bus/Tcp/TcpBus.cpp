


// RsaToolbox
#include "TcpBus.h"
using namespace RsaToolbox;

// C++
#include <cstdio>

// Qt
#include <QTextStream>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>


/*!
 * \class RsaToolbox::TcpBus
 * \ingroup BusGroup
 * \brief Connects to an intrument via Tcp socket
 * over Ethernet or WiFi.
 *
 * \b Warning: \c %TcpBus relies on \c QTcpSocket,
 * which has well-documented, long-standing
 * reliability issues on Windows platforms. If you
 * are deploying to Windows, consider using
 * \c VisaBus instead. Mac OS X, Linux, iOS and
 * Android should work well.
 *
 * \note \c %TcpBus only supports \c TCPIP_CONNECTION
 * methods
 */

/*!
 * \brief Default constructor
 *
 * \note \c %TcpBus instances created with the
 * default constructor are not connected to
 * an instrument
 *
 * \param parent Optional parent \c QObject
 * \sa GenericBus::GenericBus
 */
TcpBus::TcpBus(QObject *parent)
    : GenericBus(parent)
{
    _blockSize = 0;
}

/*!
 * \brief Constructs \c %TcpBus and attempts to connect
 * to an instrument
 *
 * Connection status should be checked with
 * \c isOpen or \c isClosed.
 *
 * \param type Connection type
 * \param address Instrument address
 * \param bufferSize_B Size of internal buffer, in bytes
 * \param timeout_ms Time out time, in milliseconds
 * \param parent Optional parent \c QObject
 * \sa GenericBus::GenericBus
 */
TcpBus::TcpBus(ConnectionType type, QString address,
               uint bufferSize_B, uint timeout_ms,
               QObject *parent)
    : GenericBus(type, address,
                 bufferSize_B, timeout_ms,
                 parent)
{
    _blockSize = 0;
    if (type != TCPIP_CONNECTION)
        return;

    _tcp.connectToHost(address, PORT);
    _tcp.waitForConnected(timeout_ms);
}

/*!
 * \brief Destructor
 */
TcpBus::~TcpBus() {
    _tcp.close();
}

/*!
 * \brief Returns status of connection
 * \return \c true if connected
 * \sa GenericBus::isOpen
 */
bool TcpBus::isOpen() const {
    return _tcp.isValid();
}

/*!
 * \brief Tcp does not have a locking mechanism.
 *
 * This method does nothing and returns false.
 *
 * You may consider using another bus implementation,
 * such as \c VisaBus, that offers this feature.
 * It is also possible to use this along with an
 * external access control, such as
 * a \c QMutex or \c QReadWriteLock instance.
 *
 * \return \c false
 * \sa VisaBus::lock, VisaBus::unlock
 */
bool TcpBus::lock() {
    emit print("Cannot lock instrument via TcpBus.");
    return false;
}

/*!
 * \brief Tcp does not have a locking mechanism.
 *
 * This method does nothing and returns false.
 *
 * You may consider using another bus implementation,
 * such as \c VisaBus, that offers this feature.
 * It is also possible to use this along with an
 * external access control, such as
 * a \c QMutex or \c QReadWriteLock instance.
 *
 * \return \c false
 * \sa VisaBus::lock, VisaBus::unlock
 */
bool TcpBus::unlock() {
    emit print("Cannot unlock instrument via TcpBus.");
    return false;
}

/*!
 * \brief Tcp does not have a remote/local
 * mechanism.
 *
 * This method does nothing and returns false.
 *
 * You may consider using the SCPI commands
 * \c "@LOC" and \c "@REM", so long as they
 * are supported by the instrument.
 * These commands are supported,
 * for example, by Rohde & Schwarz VNAs.
 *
 * You may also consider using a bus that
 * supports this feature, such as VisaBus.
 *
 * \return \c false
 * \sa VisaBus::local, VisaBus::remote
 */
bool TcpBus::local() {
    emit print("Cannot put instrument into local mode via TcpBus.");
    return false;
}

/*!
 * \brief Tcp does not have a remote/local
 * mechanism.
 *
 * This method does nothing and returns false.
 *
 * You may consider using the SCPI commands
 * \c "@LOC" and \c "@REM", so long as they
 * are supported by the instrument.
 * These commands are supported,
 * for example, by Rohde & Schwarz VNAs.
 *
 * You may also consider using a bus that
 * supports this feature, such as VisaBus.
 *
 * \return \c false
 * \sa VisaBus::local, VisaBus::remote
 */
bool TcpBus::remote() {
    emit print("Cannot put instrument into remote mode via TcpBus.");
    return false;
}

/*!
 * \brief Retrieves a pretty print status message
 *
 * Example:
 * <tt>
   Bytes:    47
   State:    3 Connected
   Status:   Ok
   </tt>
 *
 *
 * \return User-friendly status message
 * \sa GenericBus::status, GenericBus::printRead, GenericBus::printWrite
 */
QString TcpBus::status() const {
    QString text;
    QTextStream stream(&text);
    stream << "Bytes:    " << _blockSize << endl;
    stream << "State:    " << _tcp.state() << " " << stateString() << endl;


    QAbstractSocket::SocketError error = _tcp.error();
    QString errorString = _tcp.errorString();
    if (error == -1 && errorString == "Unknown error")
        stream << "Status:   Ok" << endl;
    else
        stream << "Status:   " << _tcp.error() << " " << _tcp.errorString() << endl;
    stream.flush();
    return text;
}

/*!
 * \brief Reads from instrument into \c buffer
 * \param buffer C-style character array buffer
 * \param bufferSize_B Buffer size, in bytes
 * \return \c true if successful
 * \sa GenericBus::read, binaryRead
 */
bool TcpBus::read(char *buffer, uint bufferSize_B) {
    _blockSize = -1;
    nullTerminate(buffer, bufferSize_B, 0);

    while (_tcp.bytesAvailable() <= 0) {
        if (!_tcp.waitForReadyRead(_timeout_ms)) {
            printRead(buffer, 0);
            emit print("QTcpSocket::waitForReadyRead returned false\n\n");
            emit error();
            return false;
        }
    }
    _blockSize = _tcp.read(buffer, bufferSize_B);
    if (_blockSize == -1) {
        nullTerminate(buffer, bufferSize_B, 0);
        printRead(buffer, 0);
        emit print("QTcpSocket::read returned -1\n\n");
        emit error();
        return false;
    }

    nullTerminate(buffer, bufferSize_B, _blockSize);
    printRead(buffer, _blockSize);
    return(true);
}

/*!
 * \brief Writes \c scpi to instrument
 * \param scpi Command to send
 * \return \c true if successful
 * \sa GenericBus::write, binaryWrite
 */
bool TcpBus::write(QString scpi) {
    if (!scpi.endsWith("\n"))
        scpi += "\n";
    return binaryWrite(scpi.toUtf8());
}

/*!
 * \brief Reads raw data from instrument into \c buffer
 *
 * \c bytesRead contains the number of bytes of
 * raw data read into \c buffer.
 *
 * \param buffer C-style character array buffer
 * \param bufferSize_B Buffer size, in bytes
 * \param bytesRead Bytes read into \c buffer
 * \return \c true if successful
 * \sa GenericBus::binaryRead, read
 */
bool TcpBus::binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead) {
    if (read(buffer, bufferSize_B)) {
        bytesRead = _blockSize;
        return true;
    }
    else {
        bytesRead = 0;
        return false;
    }
}

/*!
 * \brief Writes raw data in \c data to instrument
 * \param data Raw data to write
 * \return \c true if successful
 */
bool TcpBus::binaryWrite(QByteArray data) {
    _blockSize = _tcp.write(data);
    bool isWritten = _tcp.waitForBytesWritten(_timeout_ms);
    if (data.size() > MAX_PRINT)
        data = QByteArray(data.data(), MAX_PRINT+1);
    printWrite(data);

    if (_blockSize == -1) {
        emit print("QTcpSocket::write returned -1\n\n");
        emit error();
        return false;
    }
    else if (!isWritten) {
        emit print("QTcpSocket::waitForBytesWritten returned false\n\n");
        emit error();
        return false;
    }
    else {
        return true;
    }
}

QString TcpBus::stateString() const {
    switch (_tcp.state()) {
    case QAbstractSocket::UnconnectedState:
        return "Not connected";
    case QAbstractSocket::HostLookupState:
        return "Performing host name lookup";
    case QAbstractSocket::ConnectingState:
        return "Establishing connection";
    case QAbstractSocket::ConnectedState:
        return "Connected";
    case QAbstractSocket::BoundState:
        return "Socket is bound to an address and port";
    case QAbstractSocket::ClosingState:
        return "Closing";
    case QAbstractSocket::ListeningState:
        return "ListeningState";
    default:
        return "UNKNOWN";
    }
}


