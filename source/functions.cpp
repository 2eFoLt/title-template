#include "functions.h"

void parsing(QString input_str)
{
    QList input_list = input_str.split('&');
    QString login, pass;
    if(input_list.front() == "reg")
    {
        input_list.pop_front();
        login = input_list.front(); input_list.pop_front();
        pass = input_list.front(); input_list.pop_front();
        qDebug() << "reg called with" << login << ":" << pass;
    }
    if(input_list.front() == "auth")
    {
        qDebug() << "parsing auth called";
        login = input_list.front(); input_list.pop_front();
        pass = input_list.front(); input_list.pop_front();
        qDebug() << "auth called with" << login << ":" << pass;
    }
}
