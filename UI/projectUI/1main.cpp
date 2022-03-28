#include <QCoreApplication>
#include "mytcpserver.h"
//! \brief Тело программы
//! \param argc Параметр запуска 1, int
//! \param argv Параметр запуска 2, char[]
//! \return Производит запуск программы.
//!
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer myserv;
    return a.exec();
}
