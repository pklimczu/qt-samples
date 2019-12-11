#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{

}

void Server::run()
{
    server.reset(new QTcpServer(this));
    server->listen();
    port = QString::number(static_cast<int>(server->serverPort()));

    connect(server.get(), &QTcpServer::newConnection,
            this, &Server::handleConnection);
}

void Server::handleConnection()
{
    socketToClient.reset(server->nextPendingConnection());
    stream.setDevice(socketToClient.get());
    connect(socketToClient.get(), &QTcpSocket::readyRead,
            this, &Server::handleMessage);
}

void Server::handleMessage()
{
    QString message = socketToClient->readAll();
    qDebug() << message;
    Q_EMIT newMessage(message);
}
