#include "functions.h"
#include "msqldatabase.h"
#include "task3.h"
void twist(QPair<int, int>& pairObject)
{
    int temp = pairObject.first;
    pairObject.first = pairObject.second;
    pairObject.second = temp;
}
void countEntrances(QVector<int> &target, QList<QPair<int, int>> source)
{
    QPair<int , int> tempPair;
    foreach (tempPair, source)
    {
        target[tempPair.first-1] += 1;
        target[tempPair.second-1] += 1;
    }
}
QList<QPair<int, int>> unwrap(QString strLines){
    QList<QPair<int, int>> res;
    QList listBase = strLines.split('_'); //4#4, 3#4
    foreach (QString item, listBase){
        QPair<int, int> pairOfVerts = {item.split('#').first().toInt(), item.split('#').last().toInt()};
        res.append(pairOfVerts);
    }
    return res;
}
QString solveTask3(int variant, bool globalAnswer, QMap<int, QString>* linkDBTasks)
{
    QList<QPair<int, int>> source = unwrap(linkDBTasks->value(variant));
    QPair<int, int> pair;
    int globalMax = 0, localMax = 0, temp = 0;
    bool localAnswer;
    foreach (pair, source)
    {
        localMax = pair.first > pair.second ? pair.first : pair.second;
        globalMax = localMax > globalMax ? localMax : globalMax;
    }
    QVector<int> tableOfEntrances = QVector<int>().fill(0, globalMax);
    countEntrances(tableOfEntrances, source);
    foreach(int item, tableOfEntrances){ if(item % 2 != 0) temp++; }
    localAnswer = temp > 0 ? false : true;
    QString result = globalAnswer == localAnswer ? "ok" : "not ok";
    if(localAnswer)
    {
        QString eilerCycle;
        eilerCycle = getMax(findCycle(source));
        qDebug() << eilerCycle << result;
        return result;
    }
    else
    {
        qDebug() << "Not an Eiler : " << result;
        return result;
    }
}

//! \brief Функция аутентификации пользователя
//! \details Функция обращается к базе данных, проверяет наличие введённой пары и проводит валидацию данных.
//! \param login Логин пользователя {char, max 20 символов}
//! \param pass Пароль пользователя {char, max 20 символов}
//! \return Возвращает сигнал true, если в базе данных найдена введённая пара логин\пароль
//!
QString auth(QString login, QString pass, SQLdb* link)
{
    qDebug() << "auth called with" << login << pass;
    return link -> auth(login, pass);
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

//!
//! \brief Функция вывода содержимого БД
//! \param link Ссылка на объект БД
//! \return Статус функции
//!
QString printdb(SQLdb* link)
{
    link -> print_db();
    return "db-print";
}
//! \brief Функция парсинга
//! \details Функция анализа вводимого текста. Воспринимает шаблоны xxx&xxx&xxx как вызовы функций, остальное выводит на экран пользователя.
//! \param input_str Переменная для хранения разбитой функции
//! \return Возвращает статус вызова функции. Приведено к человекочитаемому формату.
//!
QString parsing(QString input_str, SQLdb* link, QMap<int, QString>* linkDBTasks)
{
    if(input_str.contains('#')) //answer%variant
    {
        QList input_list = input_str.split('#');
        int ans = input_list.front().toInt();
        int variant = input_list.back().toInt();
        if(linkDBTasks->contains(variant))
        {
            QString res = "+"+solveTask3(variant, ans == 1 ? true : false, linkDBTasks);
            return linkDBTasks->value(variant)+res;
        }
            else return "wrong-variant";
    }
    if(input_str.contains('&'))
    {
        QList input_list = input_str.split('&');
        QString login, pass, arg1, arg2, arg3;
        if(input_list.front() == "print")
        {
            return printdb(link);
        }
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
            else return auth(login, pass, link);
        }
        else return "unknown-func";
    }
    else
    {
        return "respond-string";
    }
}
