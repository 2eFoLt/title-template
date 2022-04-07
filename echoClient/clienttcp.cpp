#include "clienttcp.h"

clientTCP::clientTCP()
{
    clientSocket = new QTcpSocket;
    host = QHostAddress("127.0.0.1");
}

clientTCP::~clientTCP()
{
    clientSocket->close();
    delete clientSocket;
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
        connection_status = true;
    }
    return connection_status;
}

bool clientTCP::getStatus()
{
    if(clientSocket->isWritable() and clientSocket->isReadable() and connection_status) return true;
    else return false;
}
