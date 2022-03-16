#include "functions.h"

/* to-ask-list:
 * try-catch not working (?)
 * template function (?)
 * why auth()/reg()::QString?
 */

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
QString parsing(QString input_str)
{
    if(input_str.contains('&'))
    {
        QList input_list = input_str.split('&');
        QString login, pass;
        qDebug() << input_list.count();
        if(input_list.front() != "reg" and input_list.front() != "auth")
        { //dummy for func1&arg1&arg2
            qDebug() << "parsing() - custom-template-func called";
            return "template-func-call";
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
