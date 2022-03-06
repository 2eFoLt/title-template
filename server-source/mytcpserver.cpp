#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    qDebug() << "Server shut";
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
    if(server_status == 1){
        mTcpSocket = mTcpServer -> nextPendingConnection();
        int userid_soc = mTcpSocket -> socketDescriptor();
        active_clients[userid_soc] = mTcpSocket;
        qDebug() << "New connection -" << userid_soc << "\n";
        connect(active_clients[userid_soc], SIGNAL(readyRead()),
                this, SLOT(slotServerRead()));
        connect(active_clients[userid_soc], SIGNAL(disconnected()),
                this, SLOT(slotClientDisconnected()));
        foreach(int i, active_clients.keys())
        {
            qDebug() << active_clients[i]
                        << active_clients[i]->socketDescriptor();
        }
        }
}

void MyTcpServer::slotServerRead(){
    QByteArray array;
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    int clientSocket_id = clientSocket->socketDescriptor();
    QString res = "";
    while(clientSocket->bytesAvailable()>0)
    {
        array = clientSocket -> readAll();
        res += array;
    }
    qDebug() << clientSocket_id << "called write()";
    clientSocket -> write(res.toUtf8());
}
// копия натива active_clients
void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    int userid = clientSocket->socketDescriptor();
    qDebug() << "Client " <<userid<< " dc";
    clientSocket -> close();
    active_clients.remove(userid);
//    foreach(int i, active_clients.keys())
//    {
//        qDebug() << active_clients[i]
//                    << active_clients[i]->socketDescriptor();
//    }
}
