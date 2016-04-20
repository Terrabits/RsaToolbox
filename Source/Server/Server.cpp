#include "Server.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QtWidgets>
#include <QtNetwork>

// C++ Std Lib
//#include <stdlib.h>


Server::Server(QObject *parent) :
    QObject(parent),
    _session(0),
    _server(0),
    _currentClient(0),
    _parser(0)
{ }
Server::~Server() {
    stop();
}

bool Server::isCurrentClient() const {
    return _currentClient != NULL;
}

bool Server::isSessionOpen() const {
    return _session != NULL && _session->isOpen();
}
void Server::openSession() {
    qDebug() << "Opening session";
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        QNetworkConfiguration config = manager.defaultConfiguration();
        if (!config.isValid()) {
            qDebug() << "Could not get network configuration";
            return;
        }

        _session = new QNetworkSession(config, this);
        connect(_session, SIGNAL(opened()), this, SLOT(sessionOpened()));
        _session->open();
    }
    else {
        sessionOpened();
    }
}

void Server::sessionOpened()
{
    if (isSessionOpen())
        disconnect(_session, SIGNAL(opened()), this, SLOT(sessionOpened()));
    startServer();
}
bool Server::startServer() {
    qDebug() << "Starting server";
    _server = new QTcpServer(this);
    if (!_server->listen(_address, _port)) {
        qDebug() << "Error: " << _server->errorString();
        return false;
    }

    qDebug() << "Server started";
    _address = _server->serverAddress();
    _port = _server->serverPort();
    qDebug() << "Listening on " << address().toString() << " port " << port();
    connect(_server, SIGNAL(newConnection()), this, SLOT(connectionPending()));
    emit running();
    return true;
}

void Server::disconnectFromClients() {
    qDebug() << "Disconnecting from client";
    if (_clients.isEmpty())
        return;

    _currentClient = NULL;
    while (!_clients.isEmpty()) {
        QTcpSocket *client = _clients.takeLast();
        disconnect(client, SIGNAL(readyRead()),
                   this, SLOT(read()));
        disconnect(client, SIGNAL(disconnected()),
                   this, SLOT(disconnected()));
        if (client->isOpen())
            client->disconnectFromHost();
        client->deleteLater();
    }
}
void Server::closeSession() {
    if (isSessionOpen()) {
        qDebug() << "Closing session";
        _session->close();
        _session->deleteLater();
        _session = NULL;
    }
}
void Server::stopServer() {
    if (isRunning()) {
        qDebug() << "Stopping server";
        _server->close();
        _server->deleteLater();
        _server = NULL;
        emit stopped();
    }
}

void Server::removeParser() {
    if (!isParser())
        return;

    disconnect(_parser, SIGNAL(write(QByteArray)),
               this, SLOT(write(QByteArray)));
    _parser->deleteLater();
    _parser = NULL;
}

QHostAddress Server::address() const {
    if (isRunning())
        return _server->serverAddress();
    else
        return _address;
}

quint16 Server::port() const {
    if (isRunning())
        return _server->serverPort();
    else
        return _port;
}
void Server::setAddress(const QHostAddress &address, const quint16 &port) {
    if (isRunning())
        return;

    qDebug() << "Setting address";
    _address = address;
    _port = port;
}

QList<QHostAddress> Server::allAddresses() {
    QList<QHostAddress> iPv4;
    QList<QHostAddress> all = QNetworkInterface::allAddresses();
    foreach (QHostAddress i, all) {
        if (i != QHostAddress::LocalHost && i != QHostAddress::LocalHostIPv6) {
            if (i.toIPv4Address() != 0)
                iPv4 << i;
         // else:
         //     support IPv6?
        }
    }
    return iPv4;
}

bool Server::isRunning() const {
    return _server != NULL && _server->isListening();
}
bool Server::isConnected() const {
    return !_clients.isEmpty();
}
uint Server::connections() const {
    return _clients.size();
}

void Server::run() {
    if (isRunning())
        return;

    openSession();
}
void Server::run(const QHostAddress &address, const quint16 &port) {
    if (isRunning())
        return;

    setAddress(address, port);
    openSession();
}
void Server::stop() {
    if (isRunning()) {
        disconnectFromClients();

        stopServer();
        closeSession();
        emit stopped();
    }
}

bool Server::isParser() const {
    return _parser != NULL;
}
Parser *Server::parser() const {
    return _parser;
}
void Server::setParser(Parser *parser) {
    if (isParser()) {
        removeParser();
    }

    if (parser == NULL)
        return;

    _parser = parser;
    _parser->setParent(this);
    connect(parser, SIGNAL(write(QByteArray)),
            this, SLOT(write(QByteArray)));
}

void Server::connectionPending() {
    qDebug() << "Connection pending";
    bool newConnection = false;
    while (_server->hasPendingConnections()) {
        newConnection = true;
        qDebug() << "New connection";
        QTcpSocket *client = _server->nextPendingConnection();
        _clients << client;
        connect(client, SIGNAL(readyRead()),
                this, SLOT(read()));
        connect(client, SIGNAL(disconnected()),
                this, SLOT(disconnected()));
    }
    if (newConnection) {
        qDebug() << "Connections: " << _clients.size();
        emit connected();
    }
}
void Server::read() {
    QTcpSocket *client = qobject_cast<QTcpSocket*>(QObject::sender());
    if (client == NULL)
        return;

    _currentClient = client;
    qDebug() << "Reading from " << client->peerAddress().toString() << client->peerPort();
    QByteArray data = _currentClient->readAll();
    if (isParser())
        _parser->read(data);
}
void Server::write(QByteArray data) {
    if (isCurrentClient()) {
        qDebug() << "Writing to " << _currentClient->peerAddress().toString() << _currentClient->peerPort();
        _currentClient->write(data);
    }
}

void Server::disconnected() {
    QTcpSocket *client = qobject_cast<QTcpSocket*>(QObject::sender());
    if (client == NULL)
        return;

    disconnect(client, SIGNAL(readyRead()),
               this, SLOT(read()));
    disconnect(client, SIGNAL(disconnected()),
               this, SLOT(disconnected()));
    if (_currentClient == client)
        _currentClient = NULL;
    _clients.removeOne(client);
    client->deleteLater();
}
