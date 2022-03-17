#include <QCoreApplication>
#include "mytcpserver.h"
//!
//! \brief main
//! \param argc
//! \param argv
//! \return
//!
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer myserv;
    return a.exec();
}
