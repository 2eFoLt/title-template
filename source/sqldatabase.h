#ifndef SQLDB_H
#define SQLDB_H
#include <QVariant>
#include <QCoreApplication>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QString>

class SQLdb
{
private:
    QSqlQuery query;
    QSqlDatabase db;
public:
    SQLdb();
    ~SQLdb();
    QString insert_new(QString log, QString pssw);
    void print_db();

};

#endif // SQLDB_H
