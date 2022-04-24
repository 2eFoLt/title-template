#include "clienttcp.h"
clientTCP* clientTCP::clientInstance = nullptr;
QHostAddress clientTCP::host = QHostAddress("127.0.0.1");
QTcpSocket* clientTCP::clientSocket = new QTcpSocket;

clientTCP::clientTCP(){}

clientTCP::~clientTCP()
{
    clientSocket->close();
    delete clientSocket;
}
clientTCP* clientTCP::getInstance()
{
    if(!clientInstance) clientInstance = new clientTCP();
    return clientInstance;
}

QString clientTCP::sendToServer(QString msg)
{
    QString serverRespond = "NaN";
    if(!(clientSocket -> isWritable())) return "cannot-write";
    if(!(clientSocket -> bytesAvailable()==0)) return "busy-stream";
    clientSocket -> write(msg.toUtf8()); qDebug() << "sent:" << msg;
    clientSocket -> waitForReadyRead();
    serverRespond = clientSocket -> readLine(); qDebug() << "received:" << serverRespond << "\n";
    return serverRespond;
}

bool clientTCP::connectToServer()
{
    clientSocket->connectToHost(host, 33333);
    if(clientSocket->isWritable() and clientSocket->isReadable())
    {
        return clientSocket->isWritable();
    }
    return false;
}

bool clientTCP::getStatus()
{
    if(clientSocket->isWritable() and clientSocket->isReadable()) return true;
    else return false;
}
