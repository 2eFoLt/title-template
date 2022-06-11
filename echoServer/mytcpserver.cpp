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
    mapOfGraphs.insert(1, "1#2_1#3_1#5_1#6_2#3_2#4_2#6_3#4_3#5_4#5_4#6_5#6");
    mapOfGraphs.insert(2, "1#4_1#5_1#6_1#7_2#4_2#7_3#4_3#5_3#6_3#7_4#7");
    mapOfGraphs.insert(3, "1#6_1#8_2#6_2#7_3#4_3#5_3#6_3#8_4#5_4#6_4#8_7#8");
    mapOfGraphs.insert(4, "1#6_1#8_2#6_2#7_3#4_3#5_3#6_3#8_4#5_4#6_4#8_7#3_7#8");
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
    QByteArray answer = parsing(res, link, &mapOfGraphs).toUtf8();
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
