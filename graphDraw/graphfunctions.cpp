#include "graphfunctions.h"

Graph::Graph()
{
    objGraph = QPixmap(1000, 1000);
    objPainter = new QPainter;
    objPainter->begin(&objGraph);
    objPainter->eraseRect(0, 0, 1000, 1000);
}

Graph::~Graph()
{
    objPainter->end();
    delete[] objPainter;
}

QPixmap Graph::getGraph()
{
    return objGraph;
}

void Graph::setupGraph(QList<QPair<int, int>> base)
{
    QVector<QPair<QPoint, QPoint>> source;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(10.0, 70.0);
    QPair<QPoint, QPoint> pointPair;
    QPair<int, int> intPair;
    int k = 1;
    QSet<QPoint> points;
    QPoint tempPoint, firstPoint;
    for (int i = 0; i < base.count(); i++)
    {
        if(!tempPoint.isNull())
        {
            pointPair.first = tempPoint;
            pointPair.second.setX(int(round(dist(gen))*10));
            pointPair.second.setY(int(round(dist(gen))*10));
            tempPoint = pointPair.second;
        }
        else
        {
            pointPair.first.setX(int(round(dist(gen))*10));
            pointPair.first.setY(int(round(dist(gen))*10));
            pointPair.second.setX(int(round(dist(gen))*10));
            pointPair.second.setY(int(round(dist(gen))*10));
            tempPoint = pointPair.second;
            if(firstPoint.isNull())
            {
                firstPoint = pointPair.first;
            }
        }
        source.append(pointPair);
        points.insert(pointPair.first);
        points.insert(pointPair.second);
    }
    source.last().second = firstPoint;
    foreach (pointPair, source)
    {
        objPainter->drawPoint(pointPair.first);
        objPainter->drawText(pointPair.first, QString::number(k));
        k++;
        objPainter->drawPoint(pointPair.second);
        objPainter->drawLine(pointPair.first, pointPair.second);
    }
    foreach (intPair, base)
    {
        table[intPair.first] = source.front().first;
        table[intPair.second] = source.front().second;
        source.pop_front();
    }
}

void Graph::clearGraph()
{
    objPainter->eraseRect(0, 0, 1000, 1000);
}
