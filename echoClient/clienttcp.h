#ifndef CLIENTTCP_H
#define CLIENTTCP_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QString>


class clientTCP
{
    private:
        bool connection_status = false;
        QTcpSocket* clientSocket;
        QHostAddress host;

    public:
        clientTCP();
        ~clientTCP();
        bool connectToServer();
        //static bool connectToServer();
        QString sendToServer(QString msg);
        bool getStatus();
};

#endif // CLIENTTCP_H
