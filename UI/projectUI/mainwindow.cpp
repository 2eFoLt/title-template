#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_authButton_clicked()
{
    QString login = ui->loginBar->text();
    QString pass = ui->pswdBar->text();
    ui->label->setText(login + " " + pass);
    QString qur = "auth" + login + "&" + pass;
    //притянуть mainwindow->mytcpserver
}

void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();
}

