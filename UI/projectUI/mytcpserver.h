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
#include <QTime>
#include "msqldatabase.h"
//! \brief Родительский класс сервера с базовыми настройками.
//! В данном классе реализованы слоты под подключение клиентов, отслеживание активных клиентов-соединений.
//!
class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
    SQLdb* getInstance();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();

private:
    QTcpServer* mTcpServer;
    SQLdb mydb;
    SQLdb* db_link;
    int server_status;
    QMap<QTcpSocket*, int> active_clients;
};
#endif // MYTCPSERVER_H







