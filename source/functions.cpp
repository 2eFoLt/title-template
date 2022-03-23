#include "functions.h"
#include "msqldatabase.h"
//! \brief Функция аутентификации пользователя
//! \details Функция обращается к базе данных, проверяет наличие введённой пары и проводит валидацию данных.
//! \param login Логин пользователя {char, max 20 символов}
//! \param pass Пароль пользователя {char, max 20 символов}
//! \return Возвращает сигнал true, если в базе данных найдена введённая пара логин\пароль
//!
QString auth(QString login, QString pass)
{
    qDebug() << "auth called with" << login << pass;
    return "auth";
}

//! \brief Функция регистрации нового пользователя
//! \details Функция обращается к базе данных, проверяет отсутствие введённой пары и проводит запись пары в базу данных.
//! \param login Логин пользователя {char, max 20 символов}
//! \param pass Пароль пользователя {char, max 20 символов}
//! \return Возвращает сигнал true, если в базе данных введённая пара ранее отсутствовала и была успешно добавлена.
//!
QString reg(QString login, QString pass, SQLdb* link)
{
    qDebug() << "reg called with" << login << pass;
    return link -> insert_new(login, pass);
}

//! \brief Шаблон специализированной функции
//! \details Заготовка трёхаргументной функции с заглушкой.
//! \param arg1 Аргумент 1
//! \param arg2 Аргумент 2
//! \param arg3 Аргумент 3
//! \return Возвращает что-то...
//!
QString custom_func(QString arg1, QString arg2, QString arg3)
{
    qDebug() << "custom_func called with" << arg1 << arg2 << arg3;
    return "custom-called";
}

//! \brief Функция парсинга
//! \details Функция анализа вводимого текста. Воспринимает шаблоны xxx&xxx&xxx как вызовы функций, остальное выводит на экран пользователя.
//! \param input_str Переменная для хранения разбитой функции
//! \return Возвращает статус вызова функции. Приведено к человекочитаемому формату.
//!
QString parsing(QString input_str, SQLdb* link)
{
    if(input_str.contains('&'))
    {
        QList input_list = input_str.split('&');
        QString login, pass, arg1, arg2, arg3;
        qDebug() << input_list.count();
        if(input_list.front() != "reg" and input_list.front() != "auth")
        {
            if(input_list.count() < 4) return "not-enough-arguments";
            input_list.pop_front();
            arg1 = input_list.front(); input_list.pop_front();
            arg2 = input_list.front(); input_list.pop_front();
            arg3 = input_list.front();
            if(arg1 == "" or arg2 == "" or arg3 == "") return "empty-arguments";
            else return custom_func(arg1, arg2, arg3);
        }
        if(input_list.front() == "reg")
        {
            if(input_list.count() < 3) return "not-enough-arguments";
            input_list.pop_front();
            login = input_list.front(); input_list.pop_front();
            pass = input_list.front();
            if(login == "" or pass == "") return "empty-arguments";
            else return reg(login, pass, link);
        }
        if(input_list.front() == "auth")
        {
            if(input_list.count() < 3) return "not-enough-arguments";
            input_list.pop_front();
            login = input_list.front(); input_list.pop_front();
            pass = input_list.front();
            if(login == "" or pass == "") return "empty-arguments";
            else return auth(login, pass);
        }
        else return "unknown-func";
    }
    else
    {
        return input_str;
    }
}
