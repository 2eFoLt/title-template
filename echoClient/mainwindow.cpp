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
    QByteArray ans = "null";
    clientSoc->connectToHost(host, 33333);
    if(clientSoc->isWritable() and clientSoc->isReadable()) ui->connectionStatus->setText("Connected!");
    if(clientSoc->bytesAvailable()==0) qDebug() << "channel is empty, ready to write";
    clientSoc-> write("catch"); qDebug() << "sent: catch";
    clientSoc -> waitForReadyRead();
    ans = clientSoc->readLine(); qDebug() << "received:" << ans << "\n";
    ui->connectButton->hide();
}


void MainWindow::on_execButton_clicked()
{
    if(clientSoc->isOpen() and clientSoc->isWritable())
    {
        QString query = "NaN";
        QString login = ui->loginLine->text();
        QString pswd = ui->pswdLine->text();
        QString funcType = ui->funcLine->text();
        query = funcType+"&"+login+"&"+pswd;
        clientSoc -> write(query.toUtf8()); qDebug() << "sent:" << query;
        clientSoc -> waitForReadyRead();
        query = clientSoc -> readLine(); qDebug() << "received:" << query << "\n";
        ui->connectionStatus->setText(query);
    }
}

