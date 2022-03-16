#include "functions.h"

void parsing(QString input_str)
{
    QList input_list = input_str.split('&');
    QString login, pass;
    if(input_list.front() == "reg")
    {
        input_list.pop_front();
        login = input_list.front(); input_list.pop_front();
        pass = input_list.front();
        qDebug() << "parsing() - reg called with" << login << ":" << pass;
    }
    if(input_list.front() == "auth")
    {
        input_list.pop_front();
        login = input_list.front(); input_list.pop_front();
        pass = input_list.front();
        qDebug() << "parsing() - auth called with" << login << ":" << pass;
    }
}
