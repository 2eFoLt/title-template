#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clientSoc = new QTcpSocket;
    ui->answerBox->hide();
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
    if(clientSoc->isWritable() and clientSoc->isReadable()) ui->connectionStatus->setText("Подключение успешно!");
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
        QString funcType;
        if(ui->regButton->isChecked()) funcType = "reg";
            else funcType = "auth";
        query = funcType+"&"+login+"&"+pswd;
        clientSoc -> write(query.toUtf8()); qDebug() << "sent:" << query;
        clientSoc -> waitForReadyRead();
        query = clientSoc -> readLine(); qDebug() << "received:" << query << "\n";
        if(query == "auth-success")
        {
            ui->connectionStatus->setText("Авторизация успешна!");
            ui->connectBox->hide();
            ui->answerBox->show();
        }
        if(query == "register-success") ui->connectionStatus->setText("Регистрация успешна!");
        if(query == "wrong-password") ui->connectionStatus->setText("Неверный пароль.");
        if(query == "user-already-exist") ui->connectionStatus->setText("Пользователь с данным логином уже существует.");
        if(query == "no-such-user") ui->connectionStatus->setText("Пользователь с данным логином не найден.");
    }
}

void MainWindow::on_sendTaskButton_clicked()
{
    QString query = ui->taskLine->text() + "%" + ui->spinBox->text();
    qDebug() << "sent:" << query << "\n";
}

