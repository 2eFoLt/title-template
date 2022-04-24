#include "mainwindow.h"

#include <QApplication>

//!
//! \brief Тело клиента
//! \param argc Аргумент запуска №1
//! \param argv Аргумент запуска №2
//! \return Запускает клиентское приложение
//!
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
