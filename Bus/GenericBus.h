#ifndef GENERIC_BUS_H
#define GENERIC_BUS_H


// RsaToolbox
//

// Qt
#include <QObject>
#include <QMetaType>
#include <QString>
#include <QByteArray>
#include <QScopedArrayPointer>


namespace RsaToolbox {

enum ConnectionType {
    TCPIP_CONNECTION,
    GPIB_CONNECTION,
    USB_CONNECTION,
    NO_CONNECTION };
QString toString(ConnectionType connection_type);
ConnectionType toConnectionType(QString scpi);

class GenericBus : public QObject {
private: Q_OBJECT

public:
    explicit GenericBus(QObject *parent = 0);
    GenericBus(ConnectionType connectionType, QString address,
               uint bufferSize_B = 500, uint timeout_ms = 1000,
               QObject *parent = 0);

    virtual bool isOpen() const = 0;
    bool isClosed() const;

    ConnectionType connectionType() const;
    QString address() const;

    uint bufferSize_B() const;
    void setBufferSize(uint size_B);

    uint timeout_ms() const;
    virtual void setTimeout(uint time_ms);

    bool read(char *buffer, uint bufferSize_B);
    QString read();
    void write(QString scpiCommand);
    QString query(QString scpiCommand);

    bool binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead);
    QByteArray binaryRead();
    void binaryWrite(QByteArray scpiCommand);
    QByteArray binaryQuery(QByteArray scpiCommand);

public slots:
    virtual bool lock() = 0;
    virtual bool unlock() = 0;
    virtual bool local() = 0;
    virtual bool remote()  = 0;

    virtual void printStatus() const = 0;

signals:
    void error() const;
    void print(QString text) const;

protected:
    ConnectionType _connectionType;
    QString _address;
    uint _bufferSize_B;
    uint _timeout_ms;

    QScopedArrayPointer<char> _buffer;

    virtual bool _read(char *buffer, uint bufferSize) = 0;
    virtual bool _write(QString scpiCommand) = 0;

    virtual bool _binaryRead(char *buffer, uint bufferSize,
                             uint &bytesRead) = 0;
    virtual bool _binaryWrite(QByteArray scpiCommand) = 0;
};
}
Q_DECLARE_METATYPE(RsaToolbox::ConnectionType)


#endif


