#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>
#include <QList>
#include <QDebug>

//! \brief Файл с некоторыми функциями сервера.
//! \details Здесь реализованы функции регистрации\аутентификации пользователя и анализа вводимого текста.
//!
void parsing();
bool auth(QString login, QString pass);
bool reg(QString login, QString pass);
bool custom_func(QString arg1, QString arg2, QString arg3);

#endif // FUNCTIONS_H
