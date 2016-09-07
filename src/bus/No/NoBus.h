#ifndef NO_BUS_H
#define NO_BUS_H


// RsaToolbox
#include "GenericBus.h"


namespace RsaToolbox {


class NoBus : public GenericBus {
    Q_OBJECT

public:
    explicit NoBus(QObject *parent = 0);
    NoBus(ConnectionType type, QString address,
           uint bufferSize_B = 500, uint timeout_ms = 1000,
           QObject *parent = 0);
    ~NoBus();

    using GenericBus::read;
    using GenericBus::query;
    using GenericBus::binaryRead;
    using GenericBus::binaryQuery;

    bool isOpen() const;
    bool read(char *buffer, uint bufferSize_B);
    bool write(QString scpi);
    bool binaryRead(char *buffer, uint bufferSize_B,
                             uint &bytesRead);
    bool binaryWrite(QByteArray data);
    QString status() const;

public slots:
    bool lock();
    bool unlock();
    bool local();
    bool remote();
};
}


#endif // NO_BUS_H
