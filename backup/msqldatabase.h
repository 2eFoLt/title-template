#ifndef SQLDB_H
#define SQLDB_H
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>
//!
//! \brief Класс для работы с БД
//! \details В данном классе реализованы необходимые для удобной работы с БД функции и объекты.
class SQLdb
{
private:
    QSqlQuery query;
    QSqlDatabase db;
public:
    SQLdb();
    ~SQLdb();
    QString insert_new(QString log, QString pssw);
    QString auth(QString log, QString pssw);
    void print_db();

};

#endif // SQLDB_H
