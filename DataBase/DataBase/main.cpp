#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db =
            QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("client-db");

    if(!db.open())
        qDebug()<<db.lastError().text();
    QSqlQuery query(db);
    //создали таблицу
    query.exec("CREATE TABLE User("
               "login VARCHAR(20) NOT NULL, "
               "password VARCHAR(20) NOT NULL"
               ")");

    //добавить запись в таблицу
    query.prepare("INSERT INTO User(login, password) "
                      "VALUES (:login, :password)");
    query.bindValue(":password","123");
    query.bindValue(":login","admin");

    query.exec();// выполнить запрос

    query.prepare("INSERT INTO User(login, password) "
                      "VALUES (:login, :password)");

    query.bindValue(":password","123");
    query.bindValue(":login","user");

    query.exec();// выполнить запрос

    query.exec("SELECT * FROM User");


    // вывести на экран
    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");//номер "столбца"
    const int passwordIndex = rec.indexOf("password");

    while(query.next())
        qDebug()<<query.value(loginIndex).toString()
               <<"\t"<<query.value(passwordIndex)<<"\n";

    //закрыть соединение
    //удалить таблицу
   // query.exec("DROP TABLE User");
    //закрываем базу данных
    db.close();
    return a.exec();
}
