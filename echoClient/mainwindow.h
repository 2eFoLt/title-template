#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clienttcp.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//!
//! \brief Класс клиента
//! \details В данном классе реализованы функции для обработки действий пользователя и пересылки данных на сервер.
//!
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_connectButton_clicked();
    void on_execButton_clicked();
    void on_sendTaskButton_clicked();

private:
    Ui::MainWindow *ui;
    clientTCP* clientObj;
};
#endif // MAINWINDOW_H
