#ifndef GRAPHFUNCTIONS_H
#define GRAPHFUNCTIONS_H
#include <QtGui>
#include <random>
#include <QDebug>

class Graph
{
private:
    QPixmap objGraph;
    std::random_device rd;
    QPainter *objPainter;
    QMap<int, QPoint> table;
public:
    Graph();
    ~Graph();
    void setupGraph(QList<QPair<int, int>> sourceList);
    void clearGraph();
    QPixmap getGraph();
};


#endif // GRAPHFUNCTIONS_H
