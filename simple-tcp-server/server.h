#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDataStream>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <memory>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    void run();
    QString getPort() const { return port; }

signals:
    void newMessage(QString message);

private:
    void handleConnection();
    void handleMessage();

    std::unique_ptr<QTcpServer> server;
    std::unique_ptr<QTcpSocket> socketToClient;
    QString port;
    QDataStream stream;

};

#endif // SERVER_H
