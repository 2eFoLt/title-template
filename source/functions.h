#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>
#include <QList>
#include <QDebug>

//! \brief Файл с некоторыми функциями сервера.
//! \details Здесь реализованы функции регистрации\аутентификации пользователя и анализа вводимого текста.
//!
QString parsing();
QString auth(QString login, QString pass);
QString reg(QString login, QString pass);
QString custom_func(QString arg1, QString arg2, QString arg3);
QString printdb();

#endif // FUNCTIONS_H
