#ifndef MOCKBUS_H
#define MOCKBUS_H

// RsaToolbox
#include "GenericBus.h"

// Qt
#include <QObject>
#include <QVariant>


namespace RsaToolbox {

class MockBus : public GenericBus
{
public:
    explicit MockBus(QObject *parent = 0);
    MockBus(ConnectionType connectionType, QString address,
            uint bufferSize_B = 500, uint timeout_ms = 1000,
            QObject *parent = 0);

    bool isReadsLeft() const;
    int  readsLeft() const;
    void setReads(const QVariantList &reads);
    QVariantList writes() const;
    void clearWrites();

    virtual bool isOpen() const;
    virtual bool read(char *buffer, uint bufferSize_B);
    QString read();
    virtual bool write(QString scpi);
    virtual bool binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead);
    QByteArray binaryRead();
    virtual bool binaryWrite(QByteArray scpi);
    virtual QString status() const;

    virtual bool lock();
    virtual bool unlock();
    virtual bool local();
    virtual bool remote();

private:
    bool _isOpen;
    QVariantList _reads;
    QVariantList _writes;

    static void nullString(char *buffer, const uint size);
};
}

#endif // MOCKBUS_H
