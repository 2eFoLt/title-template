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
    QList<QPair<int, int>> listOfVerts { {1, 3}, {1, 2}, {2, 3}, {3, 4}, {4, 2} };
    objGraph->setupGraph(listOfVerts);
    ui->label->setPixmap(objGraph->getGraph());
}
