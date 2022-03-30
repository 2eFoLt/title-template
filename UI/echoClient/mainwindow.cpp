#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clientSoc = new QTcpSocket;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connectButton_clicked()
{
    QHostAddress host = QHostAddress("127.0.0.1");
    clientSoc->connectToHost(host, 33333);
    if(clientSoc->isWritable()) ui->connectionStatus->setText("Connected!");
    ui->connectButton->hide();
    emit clientSoc -> readyRead();
}


void MainWindow::on_execButton_clicked()
{
    if(clientSoc->isOpen() and clientSoc->isWritable())
    {
        QString login = ui->loginLine->text();
        QString pswd = ui->pswdLine->text();
        QString funcType = ui->funcLine->text();
        QString query = funcType+"&"+login+"&"+pswd;
        clientSoc->write(query.toUtf8());
        ui->connectionStatus->setText(clientSoc->readLine());
    }
}

