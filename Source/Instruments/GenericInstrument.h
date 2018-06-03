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
    GenericInstrument(ConnectionType type, QString address, QObject *parent = 0);

    ConnectionType connectionType() const;
    QString address       () const;
    bool    isOpen        () const;
    bool    isResponding  ();
    QString idString      ();
    QString optionsString ();
    bool    isRohdeSchwarz();
    virtual QString info  ();

    bool isLogging() const;
    bool startLog (QString filename, QString application = QString(), QString version = QString());
    void stopLog  ();

    bool open(ConnectionType type, const QString &address);
    void close(); // todo: rename close()
    void setBus(GenericBus* bus);

    // Todo: clean up all these
    // read and write methods!
    bool read(char *buffer, uint bufferSize_B, uint timeout_ms = 1000);
    QString read(uint bufferSize_B = 500, uint timeout_ms = 1000);
    void write(QString scpiCommand);
    QString query(QString scpiCommand, uint bufferSize_B = 500, uint timeout_ms = 1000);

    bool binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead, uint timeout_ms = 1000);
    QByteArray binaryRead(uint bufferSize_B = 500, uint timeout_ms = 1000);
    void binaryWrite(QByteArray scpiCommand);
    QByteArray binaryQuery(QByteArray scpiCommand,
                           uint bufferSize_B = 500, uint timeout_ms = 1000);

    void wait ();
    bool pause();
    bool pause(uint timeout_ms);
    void initializePolling   ();
    bool isOperationComplete ();

signals:
    void busError    (QString text = QString());
    void connected   ();
    void disconnected();

public slots:
    bool lock  ();
    bool unlock();
    bool local ();
    bool remote();
    void preset();
    void clearStatus();
    void print(QString text);

private:
    GenericBus *_bus;
    Log        *_log;
    void init     ();
    void printInfo();
};
}

#endif // GENERICINSTRUMENT_H
