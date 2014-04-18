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
    RsibBus(QObject *parent = 0);
    RsibBus(ConnectionType connectionType, QString address,
            uint bufferSize_B = 500, uint timeout_ms = 1000,
            QObject *parent = 0);
    ~RsibBus();

    bool isOpen() const;
    void setTimeout(uint time_ms);

protected:
    bool _read(char *buffer, uint bufferSize);
    bool _write(QString scpiCommand);

    bool _binaryRead(char *buffer, uint bufferSize,
                    uint &bytesRead);
    bool _binaryWrite(QByteArray scpiCommand);

public slots:
    bool lock();
    bool unlock();
    bool local();
    bool remote();

    void printStatus() const;

private:
    short instrument;
    short ibsta, iberr;
    ulong ibcntl;
    static const int MAX_PRINT = 100;


    void printStatus(QTextStream &stream) const;
    bool isError() const;
    void terminateCString(char *buffer, uint bufferSize);
    static QString truncateCString(const char *buffer);
};
}

#endif // RSIB_BUS_H


