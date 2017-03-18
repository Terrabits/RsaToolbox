#include "MockBus.h"


// RsaToolbox
using namespace RsaToolbox;

// stdlib
#include <cstring>


MockBus::MockBus(QObject *parent) :
    GenericBus(parent)
{
    _isOpen = false;
}
MockBus::MockBus(ConnectionType connectionType, QString address, uint bufferSize_B, uint timeout_ms, QObject *parent) :
    GenericBus(connectionType, address,
               bufferSize_B, timeout_ms, parent)
{
    _isOpen = true;
}

bool MockBus::isReadsLeft() const {
    return readsLeft() > 0;
}
int MockBus::readsLeft() const {
    return _reads.size();
}
void MockBus::setReads(const QVariantList &reads) {
    _reads = reads;
}
QVariantList MockBus::writes() const {
    return _writes;
}

bool MockBus::isOpen() const {
    return _isOpen;
}
bool MockBus::read(char *buffer, uint bufferSize_B) {
    QByteArray bytes = _reads.takeFirst().toByteArray();
    strncpy(buffer, bytes.constData(), bufferSize_B);
    return true;
}
QString MockBus::read() {
    return _reads.takeFirst().toString();
}

bool MockBus::write(QString scpi) {
    _writes << QVariant(scpi);
    return true;
}
bool MockBus::binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead) {
    QByteArray bytes = _reads.takeFirst().toByteArray();
    strncpy(buffer, bytes.constData(), bufferSize_B);
    bytesRead = (bufferSize_B >= uint(bytes.size())? bufferSize_B : bytes.size());
    return true;
}
QByteArray MockBus::binaryRead() {
    return _reads.takeFirst().toByteArray();
}

bool MockBus::binaryWrite(QByteArray scpi) {
    _writes << QVariant(scpi);
    return true;
}
QString MockBus::status() const {
    return "Mockbus: Fake it \'till you make it.";
}

bool MockBus::lock() {
    return true;
}
bool MockBus::unlock() {
    return true;
}
bool MockBus::local() {
    return true;
}
bool MockBus::remote() {
    return true;
}
