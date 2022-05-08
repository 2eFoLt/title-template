#include "task3.h"
QString print(QVector<QPair<int, int>> source1)
{
    QString res = "";
    for(QPair<int, int> pair : source1)
    {
        res += "{" + QString::number(pair.first) + ", " + QString::number(pair.second) + "}";
    }
    return res;
}
bool sortStringSize(QString str1, QString str2)
{
    return (str1.size() > str2.size());
}
QString getMax(QVector<QString> source)
{
    std::sort(source.begin(), source.end(), sortStringSize);
    return source[0];
}
QVector<QString> findCycle(QVector<QPair<int, int>> source)
{
    int point;
    QVector<QPair<int, int>> copy_source;
    QVector<QPair<int, int>> vault;
    QVector<QPair<int, int>> main_source = source;
    QPair<int, int> pairMain;
    QPair<int, int> pairSub;
    QString cycle;
    QVector<QString> cycles;
    while(!main_source.empty())
    {
        cycle = "";
        vault.clear();
        pairMain = main_source.front();
        point = pairMain.second;
        cycle = QString::number(pairMain.first) + QString::number(pairMain.second);
        //main_source.erase(remove(main_source.begin(), main_source.end(), pairMain), main_source.end());
        main_source.removeOne(pairMain);
        copy_source = source;
       // copy_source.erase(remove(copy_source.begin(), copy_source.end(), pairMain), copy_source.end());
        copy_source.removeOne(pairMain);
        while(true)
        {
            if(!copy_source.empty())
            {
                pairSub = copy_source.front();
                if(point == pairSub.first)
                    {
                        cycle += QString::number(pairSub.second);
                        point = pairSub.second;
                        //copy_source.erase(remove(copy_source.begin(), copy_source.end(), pairSub), copy_source.end());
                        copy_source.removeOne(pairSub);
                    }
                else
                    {
                        if(point == pairSub.second)
                        {
                            cycle += QString::number(pairSub.first);
                            point = pairSub.first;
                            //copy_source.erase(remove(copy_source.begin(), copy_source.end(), pairSub), copy_source.end());
                            copy_source.removeOne(pairSub);
                        }
                        else
                        {
                            vault.push_back(pairSub);
                            //copy_source.erase(remove(copy_source.begin(), copy_source.end(), pairSub), copy_source.end());
                            copy_source.removeOne(pairSub);
                        }
                    }
                if(cycle.front() == cycle.back())
                {
                    cycles.push_back(cycle);
                    cycle = "";
                    break;
                }
            }
            else
            {
                if(!vault.empty())
                {
                    copy_source = vault;
                    vault.clear();
                }
            }
        }
    }
    return cycles;
}
