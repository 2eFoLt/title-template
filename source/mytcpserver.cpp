#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include "functions.cpp"
//!
//! \brief MyTcpServer::~MyTcpServer
//!
MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    server_status = 0;
}

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

void MyTcpServer::slotNewConnection(){
    if(server_status == 1)
    {
        QTcpSocket* socket = mTcpServer -> nextPendingConnection();
        int socket_id = socket -> socketDescriptor();
        active_clients[socket] = socket_id;
        //client_list.append(mTcpSocket);
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

void MyTcpServer::slotServerRead(){
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    QString res = "";
    while(clientSocket->bytesAvailable()>0)
    {
        res = clientSocket -> readLine();
    }
    clientSocket -> write(QTime::currentTime().toString().toUtf8() + ' ' + parsing(res).toUtf8());
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    qDebug() << clientSocket << "disconnected\n";
    active_clients.remove(clientSocket);
    clientSocket -> close();
}
