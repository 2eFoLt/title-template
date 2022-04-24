#include "mainwindow.h"
#include "ui_mainwindow.h"

//!
//! \brief Конструктор объекта приложения
//! \param parent Родительский объект интерфейса
//!
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clientTCP::getInstance();
    objGraph = new Graph;
    ui->label_3->setPixmap(objGraph->getGraph());
    ui->label_3->hide();
    ui->answerBox->hide();
}

//!
//! \brief Деструктор объекта приложения
//!
MainWindow::~MainWindow()
{
    delete clientTCP::getInstance();
    delete ui;
}

//!
//! \brief Функция кнопки подключения
//! \details Обрабатывает взаимодействие с сервером и проверяет успешное подключение к нему
//!
void MainWindow::on_connectButton_clicked()
{
    QString ans = "null";
    QByteArray qbAns = ans.toUtf8();
    qDebug() << sizeof(ans) << sizeof(qbAns);
    clientTCP::connectToServer();
    if(clientTCP::getStatus())
    {
        ans = clientTCP::sendToServer("catch");
    }
    if(ans == "respond-string") ui->connectionStatus->setText("Успешно подключено!");
    ui->connectButton->hide();
}

//!
//! \brief Функция кнопки-обработчика запросов
//! \details Обрабатывает вводимые пользователем данные и пересылает их на сервер, далее обрабатывает ответ сервера и выводит результат на экран
//!
void MainWindow::on_execButton_clicked()
{
    if(clientTCP::getStatus())
    {
        QString query = "NaN";
        QString login = ui->loginLine->text();
        QString pswd = ui->pswdLine->text();
        QString funcType;
        if(ui->regButton->isChecked()) funcType = "reg";
            else funcType = "auth";
        query = funcType+"&"+login+"&"+pswd;
        query = clientTCP::sendToServer(query);
        if(query == "auth-success")
        {
            ui->connectionStatus->setText("Авторизация успешна!");
            ui->connectBox->hide();
            ui->answerBox->show();
            ui->label_3->show();
        }
        if(query == "register-success") ui->connectionStatus->setText("Регистрация успешна!");
        if(query == "wrong-password") ui->connectionStatus->setText("Неверный пароль.");
        if(query == "user-already-exist") ui->connectionStatus->setText("Пользователь с данным логином уже существует.");
        if(query == "no-such-user") ui->connectionStatus->setText("Пользователь с данным логином не найден.");
    }
}

//!
//! \brief Функция кнопки-обработчика проверки ответов на задания
//! \details Обрабатывает вводимые пользователям данные о задаче и пересылает их на сервер, далее обрабатывает ответ сервера и выводит результат на экран
//!
void MainWindow::on_sendTaskButton_clicked()
{
    QString query = ui->taskLine->text() + "#" + ui->answerLine->text();
    query = clientTCP::sendToServer(query);
    if(query.contains('#')) ui->answerStatusLabel->setText("Ответ зачтён");
            else ui->answerStatusLabel->setText("Данный вариант отсутствует в базе");
    objGraph->setupGraph(objGraph->unwrap(query));
    ui->label_3->setPixmap(objGraph->getGraph());
}

void MainWindow::on_rerollGraph_clicked()
{
    objGraph->setupGraph(objGraph->getListOfVerts());
    ui->label_3->setPixmap(objGraph->getGraph());
}

