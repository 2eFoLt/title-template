#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objGraph = new Graph;
    ui->label->setPixmap(objGraph->getGraph());
}

MainWindow::~MainWindow()
{
    objGraph->~Graph();
    delete ui;
}

void MainWindow::on_buttonDrawLine_clicked()
{
    QList<QPair<int, int>> listOfVerts;
    QPair<int, int> intPair;
    for(int i = 1; i < 14; i+=2)
    {
        intPair.first = i; intPair.second = i+1;
        listOfVerts.append(intPair);
    }
    objGraph->setupGraph(listOfVerts);
    ui->label->setPixmap(objGraph->getGraph());
}


void MainWindow::on_buttonClear_clicked()
{
    objGraph->clearGraph();
    ui->label->setPixmap(objGraph->getGraph());
}

