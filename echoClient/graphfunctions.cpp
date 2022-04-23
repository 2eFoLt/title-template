#include "graphfunctions.h"

Graph::Graph()
{
    objGraph = QPixmap(525, 525);
    objPainter = new QPainter;
    objPainter->begin(&objGraph);
    objPainter->eraseRect(0, 0, 525, 525);
    listOfVerts = { {1, 3}, {1, 2}, {2, 3}, {3, 4}, {4, 2} };
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

QList<QPair<int, int>> Graph::getListOfVerts()
{
    return listOfVerts;
}

QPoint Graph::genCord()
{
    QPoint pt;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(10.0, 50.0);
    pt.setX(int(round(dist(gen))*10));
    pt.setY(int(round(dist(gen))*10));
    return pt;
}

void Graph::setupGraph(QList<QPair<int, int>> baseLines)
{
    listOfVerts = baseLines;
    objPainter->eraseRect(0, 0, 525, 525);
    QMap<int, QPoint> mapVerticalsToPoints;
    QPair<int, int> pairOfVerticals;
    QLine currLine;
    QVector<QLine> listOfLines;
    foreach (pairOfVerticals, baseLines)
    {
        if(mapVerticalsToPoints[pairOfVerticals.first].isNull()) mapVerticalsToPoints[pairOfVerticals.first] = genCord();
        if(mapVerticalsToPoints[pairOfVerticals.second].isNull()) mapVerticalsToPoints[pairOfVerticals.second] = genCord();
        currLine = QLine(mapVerticalsToPoints[pairOfVerticals.first], mapVerticalsToPoints[pairOfVerticals.second]);
        listOfLines.append(QLine(currLine));
        objPainter->drawText(mapVerticalsToPoints[pairOfVerticals.first], QString::number(pairOfVerticals.first));
        objPainter->drawText(mapVerticalsToPoints[pairOfVerticals.second], QString::number(pairOfVerticals.second));
    }
    objPainter->drawLines(listOfLines);
}
