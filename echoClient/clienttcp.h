#ifndef CLIENTTCP_H
#define CLIENTTCP_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QString>


class clientTCP
{
    private:
        static clientTCP* clientInstance;
        static QTcpSocket *clientSocket;
        static QHostAddress host;
        clientTCP();
        clientTCP(const clientTCP &);
        clientTCP& operator = (clientTCP &);

    public:
        ~clientTCP();
        static clientTCP* getInstance();
        static bool connectToServer();
        static QString sendToServer(QString msg);
        static bool getStatus();
};

#endif // CLIENTTCP_H
