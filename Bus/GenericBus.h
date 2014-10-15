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

    virtual bool isClosed() const;

    ConnectionType connectionType() const;
    QString address() const;

    uint bufferSize_B() const;
    void setBufferSize(uint size_B);

    uint timeout_ms() const;
    virtual void setTimeout(uint time_ms);

    QString read();
    QString query(QString scpi);
    QByteArray binaryRead();
    QByteArray binaryQuery(QByteArray scpi);

    // Reimplement:
    virtual bool isOpen() const = 0;
    virtual bool read(char *buffer, uint bufferSize_B) = 0;
    virtual bool write(QString scpi) = 0;
    virtual bool binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead) = 0;
    virtual bool binaryWrite(QByteArray scpi) = 0;
    virtual QString status() const = 0;

    static void nullTerminate(char *buffer, uint bufferSize_B, uint bytesRead);

public slots:
    // Reimplement:
    virtual bool lock() = 0;
    virtual bool unlock() = 0;
    virtual bool local() = 0;
    virtual bool remote()  = 0;

signals:
    void error() const;
    void print(QString text) const;

protected:
    ConnectionType _connectionType;
    QString _address;
    uint _timeout_ms;

    static const int MAX_PRINT = 100;
    void printRead(char *buffer, uint bytesRead) const;
    void printWrite(QString scpi) const;

private:
    uint _bufferSize_B;
    QScopedArrayPointer<char> _buffer;
};
}
Q_DECLARE_METATYPE(RsaToolbox::ConnectionType)


#endif


