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
    QPoint genCord();
    QList<QPair<int, int>> listOfVerts;
public:
    Graph();
    ~Graph();
    QList<QPair<int, int>> unwrap(QString strLines);
    void setupGraph(QList<QPair<int, int>> sourceList);
    QPixmap getGraph();
    QList<QPair<int, int>> getListOfVerts();
};


#endif // GRAPHFUNCTIONS_H
