#ifndef TESTBUS_H
#define TESTBUS_H


// RsaToolbox
#include "GenericBus.h"

// Qt
#include <QString>
#include <QStringList>


namespace RsaToolbox {

class TestBus : public GenericBus {
    Q_OBJECT

public:
    explicit TestBus(QObject *parent = 0);
    TestBus(ConnectionType type, QString address,
        uint bufferSize_B = 500, uint timeout_ms = 1000,
        QObject *parent = 0);
    ~TestBus();

    using GenericBus::read;
    using GenericBus::query;
    using GenericBus::binaryRead;
    using GenericBus::binaryQuery;

    virtual bool isOpen() const;
    virtual bool isClosed() const;

    void addResponses(const QStringList &responses);
    virtual bool read(char *buffer, uint bufferSize_B);
    virtual bool write(QString scpi);

    void addResponses(const QVector<QByteArray> &responses);
    virtual bool binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead);
    virtual bool binaryWrite(QByteArray scpi);

    virtual QString status() const;

private:
    uint _bytes;
    QVector<QByteArray> _responses;

} // TestBus
} // RsaToolbox


#endif