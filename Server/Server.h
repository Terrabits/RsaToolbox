#ifndef SERVER_H
#define SERVER_H


// RsaToolbox
#include "Parser.h"

// Qt
#include <QNetworkSession>
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

    bool isRunning() const;
    bool isConnected() const;
    uint connections() const;

    QHostAddress address() const;
    quint16 port() const;
    void setAddress(const QHostAddress &address = QHostAddress::Any, const quint16 &port = 0);

    void run();
    void run(const QHostAddress &address, const quint16 &port);
    void stop();

    // All active IPv4 addresses on host machine:
    static QList<QHostAddress> allAddresses();

    bool isParser() const;
    Parser *parser() const;
    void setParser(Parser *parser);

signals:
    void running();
    void connected();
    void stopped();

private slots:
    void sessionOpened();

    // Client
    void connectionPending();
    void read();
    void write(QByteArray data);
    void disconnected();

private:
    QHostAddress _address;
    quint16 _port;

    QNetworkSession *_session;
    QTcpServer *_server;

    bool isCurrentClient() const;
    QTcpSocket *_currentClient;
    QList<QTcpSocket*> _clients;

    bool isSessionOpen() const;

    void openSession();
    bool startServer();

    void disconnectFromClients();
    void closeSession();
    void stopServer();

    Parser *_parser;
    void removeParser();
};
}


#endif
