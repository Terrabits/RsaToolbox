#ifndef SERVER_H
#define SERVER_H


// RsaToolbox
#include "Parser.h"

// Qt
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>


namespace RsaToolbox {


class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);
    ~Server();

    // status
    bool isRunning() const;
    bool isConnected() const;
    uint connections() const;

    // address, port
    QHostAddress address() const;
    quint16 port() const;
    void setAddress(const QHostAddress &address = QHostAddress::Any, const quint16 &port = 0);

    // start, stop
    void run();
    void run(const QHostAddress &address, const quint16 &port);
    void stop();

    // All active IPv4 addresses on host machine:
    static QList<QHostAddress> allAddresses();

    // parser
    bool isParser() const;
    Parser *parser() const;
    void setParser(Parser *parser);

signals:
    void running();
    void connected();
    void stopped();

private slots:

    // Client
    void connectionPending();
    void read();
    void write(QByteArray data);
    void disconnected();

private:

    // server
    QHostAddress _address;
    quint16 _port;
    QTcpServer *_server;

    // clients
    bool isCurrentClient() const;
    QTcpSocket *_currentClient;
    QList<QTcpSocket*> _clients;

    // start
    bool startServer();

    // stop
    void disconnectFromClients();
    void stopServer();

    // parser
    Parser *_parser;
    void removeParser();
};
}


#endif
