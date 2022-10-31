#include <QtTest>
#include "../echoServer/task19.h"
// add necessary includes here

class task19 : public QObject
{
    Q_OBJECT

public:
    task19();
    ~task19();

private slots:
    void test_case1();

};

task19::task19()
{

}

task19::~task19()
{

}

void task19::test_case1()
{
    QVector<int> emptyVec;
    QCOMPARE(true, pruferCodeVoid(emptyVec).isEmpty());
}

QTEST_APPLESS_MAIN(task19)

#include "tst_task19.moc"
