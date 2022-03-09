#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QMap>
#include <QString>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();

private:
    QTcpServer* mTcpServer;
    QTcpSocket* mTcpSocket;
    int server_status;
    QMap<QTcpSocket*, int> active_clients;
    QMap<QString, QString> auth_db;
};
#endif // MYTCPSERVER_H







