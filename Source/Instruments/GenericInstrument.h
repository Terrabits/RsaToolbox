#ifndef GENERICINSTRUMENT_H
#define GENERICINSTRUMENT_H


// RsaToolbox
#include "Definitions.h"
#include "GenericBus.h"
#include "Log.h"

// Qt
#include <QObject>
#include <QScopedPointer>
#include <QTextStream>

namespace RsaToolbox {

class GenericInstrument : public QObject
{
    Q_OBJECT

public:
    explicit GenericInstrument(QObject *parent = 0);
    GenericInstrument(GenericBus *bus, QObject *parent = 0);
    GenericInstrument(ConnectionType type, QString address, QObject *parent = 0);

    ConnectionType connectionType() const;
    QString address() const;

    bool isConnected() const;
    bool isDisconnected() const;

    bool isLogOpen() const;
    bool isLogConnected() const;
    bool isLogDisconnected() const;

    bool isRohdeSchwarz();
    QString idString();
    QString optionsString();

    Log* log();
    void useLog(Log *log);
    void disconnectLog();

    void print(QString text);
    void printLine(QString text = "");
    void printInfo();
    virtual void printInfo(QString &info);

    GenericBus* takeBus();
    void resetBus();
    void resetBus(GenericBus* bus);
    void resetBus(ConnectionType type, QString address);

    bool read(char *buffer, uint bufferSize_B, uint timeout_ms = 1000);
    QString read(uint bufferSize_B = 500, uint timeout_ms = 1000);
    void write(QString scpiCommand);
    QString query(QString scpiCommand, uint bufferSize_B = 500, uint timeout_ms = 1000);

    bool binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead, uint timeout_ms = 1000);
    QByteArray binaryRead(uint bufferSize_B = 500, uint timeout_ms = 1000);
    void binaryWrite(QByteArray scpiCommand);
    QByteArray binaryQuery(QByteArray scpiCommand,
                           uint bufferSize_B = 500, uint timeout_ms = 1000);

    void wait();
    bool pause();
    bool pause(uint timeout_ms);
    void initializePolling();
    bool isOperationComplete();

signals:
    void busError() const;
    void connected() const;
    void disconnected() const;

public slots:
    bool lock();
    bool unlock();
    bool local();
    bool remote();

    void preset();
    void clearStatus();

private:
    QScopedPointer<GenericBus> _bus;
    Log *_log;
    Log _tempLog;

    void connectLog();
};
}

#endif // GENERICINSTRUMENT_H
