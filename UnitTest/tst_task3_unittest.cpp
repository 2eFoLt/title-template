#include <QtTest>
#include "../echoServer/task3.h"
// add necessary includes here

class task3_unittest : public QObject
{
    Q_OBJECT

public:
    task3_unittest();
    ~task3_unittest();

private slots:
    void test_case_findCycle_false();

};

task3_unittest::task3_unittest()
{
}

task3_unittest::~task3_unittest()
{
}

void task3_unittest::test_case_findCycle_false()
{
    QVector<QPair<int, int>> emptyVector;
    QCOMPARE(true, findCycle(emptyVector).isEmpty());
}

QTEST_APPLESS_MAIN(task3_unittest)

#include "tst_task3_unittest.moc"
