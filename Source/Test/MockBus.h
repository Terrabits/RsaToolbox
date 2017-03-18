#ifndef MOCKBUS_H
#define MOCKBUS_H

// RsaToolbox
#include "GenericBus.h"

// Qt
#include <QObject>

namespace RsaToolbox {

class MockBus : public GenericBus
{
public:
    explicit MockBus(QObject *parent = 0);
    MockBus(ConnectionType connectionType, QString address,
            uint bufferSize_B = 500, uint timeout_ms = 1000,
            QObject *parent = 0);

    void setConnectionType(ConnectionType type);
    void setAddress(const QString &address);

    virtual bool isOpen() const;
    virtual bool read(char *buffer, uint bufferSize_B);
    virtual bool write(QString scpi);
    virtual bool binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead);
    virtual bool binaryWrite(QByteArray scpi);
    virtual QString status() const;

    virtual bool lock();
    virtual bool unlock();
    virtual bool local();
    virtual bool remote();
};
}

#endif // MOCKBUS_H
