


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
    stream << "Bytes: " << _blockSize;
    stream << "State: " << _tcp.state();
    stream << "Status: " << _tcp.error() << _tcp.errorString();
    stream.flush();
    return text;
}

bool TcpBus::read(char *buffer, uint bufferSize_B) {
    qDebug() << "TcpBus::read";
    QDataStream stream(&_tcp);
    _tcp.waitForReadyRead(_timeout_ms);
    stream >> _blockSize;
    qDebug() << "block size: " << _blockSize;
    _tcp.waitForReadyRead(_timeout_ms);
    _blockSize = _tcp.read(buffer, bufferSize_B);
    qDebug() << "block size: " << _blockSize;
    if (_blockSize == -1) {
        buffer[0] = '\0';
        printRead(buffer, 0);
        emit error();
        return false;
    }

    nullTerminate(buffer, bufferSize_B, _blockSize);
    printRead(buffer, _blockSize);
    return(true);
}
bool TcpBus::write(QString scpi) {
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
    qDebug() << "TcpBus::binaryWrite" << scpi;
    _blockSize = _tcp.write(scpi);
    qDebug() << "block size: " << _blockSize;
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


