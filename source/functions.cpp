#include "functions.h"
//!
//! \brief auth
//! \param login
//! \param pass
//! \return
//!
bool auth(QString login, QString pass)
{
    qDebug() << "auth called with" << login << pass;
    return true;
}
bool reg(QString login, QString pass)
{
    qDebug() << "reg called with" << login << pass;
    return true;
}
bool custom_func(QString arg1, QString arg2, QString arg3)
{
    qDebug() << "custom_func called with" << arg1 << arg2 << arg3;
    return true;
}
QString parsing(QString input_str)
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
            if(custom_func(arg1, arg2, arg3)) return "custom_func_success";
        }
        if(input_list.front() == "reg")
        {
            if(input_list.count() < 3) return "not-enough-arguments";
            input_list.pop_front();
            login = input_list.front(); input_list.pop_front();
            pass = input_list.front();
            if(login == "" or pass == "") return "empty-arguments";
            if(reg(login, pass)) return "reg_success";
        }
        if(input_list.front() == "auth")
        {
            if(input_list.count() < 3) return "not-enough-arguments";
            input_list.pop_front();
            login = input_list.front(); input_list.pop_front();
            pass = input_list.front();
            if(login == "" or pass == "") return "empty-arguments";
            if(auth(login, pass)) return "auth_success";
                else return "auth_failure";
        }
        else return "unknown-func";
    }
    else
    {
        return input_str;
    }
}
