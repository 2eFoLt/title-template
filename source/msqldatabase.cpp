#include "msqldatabase.h"
//!
//! \brief Конструктор объекта класса SQLdb
//!
SQLdb::SQLdb()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("client-db");
    if(!db.open())
        qDebug()<<db.lastError().text();
    query = QSqlQuery(db);//создали таблицу
    query.exec("CREATE TABLE User("
               "login VARCHAR(20) NOT NULL, "
               "password VARCHAR(20) NOT NULL"
               ")");
}

//!
//! \brief Деструктор объекта класса SQLdb
//!
SQLdb::~SQLdb()
{
    query.exec("DROP TABLE User");
    db.close();
}

//!
//! \brief Функция для добавления новой записи в БД
//! \param log Логин пользователя
//! \param pssw Пароль пользователя
//! \return Если пара найдена в базе, то регистрация считается успешной. Если в БД найден только логин, а пароль не совпадает - регистрация провалена.
//!
QString SQLdb::insert_new(QString log, QString pssw)
{
    if(query.isNull(log))
    {
        query.prepare("INSERT INTO User(login, password) "
                          "VALUES (:login, :password)");
        query.bindValue(":password", pssw); query.bindValue(":login", log);
        query.exec();// выполнить запрос
        return "register-success";
    }
    else if(query.value(log) != pssw) return "wrong-password";
    else return "user-already-exist";
}

//!
//! \brief Функция вывода всех записей БД
//!
void SQLdb::print_db()
{
    query.exec("SELECT * FROM User");
    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");
    const int passwordIndex = rec.indexOf("password");
    while(query.next())
        qDebug() << query.value(loginIndex).toString()
         << "\t" << query.value(passwordIndex) << "\n";
}
