


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


TcpBus::TcpBus(QObject *parent)
    : GenericBus(parent)
{
    _blockSize = 0;
}
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
TcpBus::~TcpBus() {
    _tcp.close();
}

bool TcpBus::isOpen() const {
    return _tcp.isValid();
}

bool TcpBus::lock() {
    emit print("Cannot lock instrument via TcpBus.");
    return false;
}
bool TcpBus::unlock() {
    emit print("Cannot unlock instrument via TcpBus.");
    return false;
}
bool TcpBus::local() {
    emit print("Cannot put instrument into local mode via TcpBus.");
    return false;
}
bool TcpBus::remote() {
    emit print("Cannot put instrument into remote mode via TcpBus.");
    return false;
}
 
QString TcpBus::status() const {
    QString text;
    QTextStream stream(&text);
    stream << "Bytes: " << _blockSize << endl;
    stream << "State: " << _tcp.state() << endl;
    stream << "Status: " << _tcp.error() << " " << _tcp.errorString() << endl;
    stream.flush();
    return text;
}

bool TcpBus::read(char *buffer, uint bufferSize_B) {
    while (_tcp.bytesAvailable() <= 0) {
        if (!_tcp.waitForReadyRead(_timeout_ms)) {
            nullTerminate(buffer, bufferSize_B, 0);
            printRead(buffer, 0);
            emit error();
            return false;
        }
    }
    _blockSize = _tcp.read(buffer, bufferSize_B);
    if (_blockSize == -1) {
        nullTerminate(buffer, bufferSize_B, 0);
        printRead(buffer, 0);
        emit error();
        return false;
    }

    nullTerminate(buffer, bufferSize_B, _blockSize);
    printRead(buffer, _blockSize);
    return(true);
}
bool TcpBus::write(QString scpi) {
    if (!scpi.endsWith("\n"))
        scpi += "\n";
    return binaryWrite(scpi.toUtf8());
}
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
bool TcpBus::binaryWrite(QByteArray scpi) {
    _blockSize = _tcp.write(scpi);
    _tcp.waitForBytesWritten(_timeout_ms);
    if (scpi.size() > MAX_PRINT)
        scpi = QByteArray(scpi.data(), MAX_PRINT+1);
    printWrite(scpi);

    if (_blockSize == -1) {
        emit error();
        return false;
    }
    else {
        return true;
    }
}


