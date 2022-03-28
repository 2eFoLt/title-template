#include <QApplication>
#include <QCoreApplication>
#include "mainwindow.h"
#include "mytcpserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	MyTcpServer myserv;
    w.show();
    return a.exec();
}
