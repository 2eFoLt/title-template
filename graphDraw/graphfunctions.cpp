#include "graphfunctions.h"

Graph::Graph()
{
    objGraph = QPixmap(800, 800);
    objPainter = new QPainter;
    objPainter->begin(&objGraph);
    objPainter->eraseRect(0, 0, 800, 800);
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

QPoint Graph::genCord()
{
    QPoint pt;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(10.0, 70.0);
    pt.setX(int(round(dist(gen))*10));
    pt.setY(int(round(dist(gen))*10));
    return pt;
}

void Graph::setupGraph(QList<QPair<int, int>> baseLines)
{
    objPainter->eraseRect(0, 0, 800, 800);
    QMap<int, QPoint> mapVerticalsToPoints;
    QPair<int, int> pairOfVerticals;
    QVector<QLine> listOfLines;
    foreach (pairOfVerticals, baseLines)
    {
        if(mapVerticalsToPoints[pairOfVerticals.first].isNull()) mapVerticalsToPoints[pairOfVerticals.first] = genCord();
        if(mapVerticalsToPoints[pairOfVerticals.second].isNull()) mapVerticalsToPoints[pairOfVerticals.second] = genCord();
        objPainter->drawText(mapVerticalsToPoints[pairOfVerticals.first], QString::number(pairOfVerticals.first));
        objPainter->drawText(mapVerticalsToPoints[pairOfVerticals.second], QString::number(pairOfVerticals.second));
        listOfLines.append(QLine(mapVerticalsToPoints[pairOfVerticals.first],
                           mapVerticalsToPoints[pairOfVerticals.second]));
    }
    objPainter->drawLines(listOfLines);
}
