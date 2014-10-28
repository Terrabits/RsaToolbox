#ifndef TCP_BUS_H
#define TCP_BUS_H


// RsaToolbox
#include "GenericBus.h"

// Qt
#include <QTcpSocket>


namespace RsaToolbox {


class TcpBus : public GenericBus {
    Q_OBJECT

public:
    explicit TcpBus(QObject *parent = 0);
    TcpBus(ConnectionType type, QString address,
           uint bufferSize_B = 500, uint timeout_ms = 1000,
           QObject *parent = 0);
    ~TcpBus();

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

private:
    static const quint16 PORT = 5025;
    QTcpSocket _tcp;
    qint64 _blockSize;

    QString stateString() const;
};
}


#endif // TCP_BUS_H
