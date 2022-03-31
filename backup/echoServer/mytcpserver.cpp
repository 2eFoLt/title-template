#include <QCoreApplication>
#include <QDebug>
#include "functions.cpp"
#include "mytcpserver.h"
//!
//! \brief Деструктор объекта сервера
//!
MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    server_status = 0;
}

//! \brief Конструктор объекта сервера
//! \details Проводит инициализвацию объекта сервера с последующим уведомлением в qDebug о статусе сервера.
//! \param parent Родительский объект {QObject}
//!
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "Server is not online";
    }
    else {
        server_status = 1;
        qDebug() << "Server online";
    }
}

//! \brief Слот нового подключения
//! \details Создаёт новый объект сокета, инициализирует его и проводит запись в список активных клиентов.
//!
void MyTcpServer::slotNewConnection(){
    if(server_status == 1)
    {
        QTcpSocket* socket = mTcpServer -> nextPendingConnection();
        int socket_id = socket -> socketDescriptor();
        active_clients[socket] = socket_id;
        qDebug() << "New connection -" << socket_id;
        connect(active_clients.key(socket_id), SIGNAL(readyRead()),
                this, SLOT(slotServerRead()));
        connect(active_clients.key(socket_id), SIGNAL(disconnected()),
                this, SLOT(slotClientDisconnected()));
        foreach(QTcpSocket* i, active_clients.keys())
        {
            qDebug() << i << active_clients[i];
        }
    }
}

//! \brief Слот чтения
//! \details Считывает вводимые клиентом данные и передаёт их в функцию парсера.
//!
void MyTcpServer::slotServerRead(){
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    QString res = "";
    SQLdb* link = &mydb;
    while(clientSocket->bytesAvailable()>0)
    {
        res = clientSocket -> readLine();
    }
    qDebug() << "received on read:" << res;
    QByteArray answer = parsing(res, link).toUtf8();
    clientSocket -> write(answer);
    qDebug() << "sent on read:" << answer << "\n";
}

//! \brief Слот отключения
//! \details Убирает сокет из списка активных и закрывает его.
//!
void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    qDebug() << clientSocket << "disconnected\n";
    active_clients.remove(clientSocket);
    clientSocket -> close();
}
