#ifndef RSIB_BUS_H
#define RSIB_BUS_H

// RsaToolbox:
#include "GenericBus.h"

// Qt
#include <QObject>
#include <QString>
#include <QTextStream>


namespace RsaToolbox {

class RsibBus : public GenericBus {
private: Q_OBJECT

public:
    explicit RsibBus(QObject *parent = 0);
    RsibBus(ConnectionType connectionType, QString address,
            uint bufferSize_B = 500, uint timeout_ms = 1000,
            QObject *parent = 0);
    ~RsibBus();

    void setTimeout(uint time_ms);

    using GenericBus::read;
    using GenericBus::query;
    using GenericBus::binaryRead;
    using GenericBus::binaryQuery;

    bool isOpen() const;
    bool read(char *buffer, uint bufferSize);
    bool write(QString scpi);
    bool binaryRead(char *buffer, uint bufferSize,
                    uint &bytesRead);
    bool binaryWrite(QByteArray scpi);
    QString status() const;

public slots:
    bool lock();
    bool unlock();
    bool local();
    bool remote();

private:
    short _instrument;
    short _ibsta, _iberr;
    ulong _ibcntl;

    bool isError() const;
};
}

#endif // RSIB_BUS_H


