#ifndef GRAPHFUNCTIONS_H
#define GRAPHFUNCTIONS_H
#include <QtGui>
#include <random>

class Graph
{
private:
    QPixmap objGraph;
    std::random_device rd;
    QPainter *objPainter;
    QPoint genCord();
public:
    Graph();
    ~Graph();
    void setupGraph(QList<QPair<int, int>> sourceList);
    QPixmap getGraph();
};


#endif // GRAPHFUNCTIONS_H
