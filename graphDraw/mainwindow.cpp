#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objGraph = new QPixmap(500, 300);
    objPainter = new QPainter;
    objPainter->begin(objGraph);
    objPainter->eraseRect(0, 0, 500, 300);
}

MainWindow::~MainWindow()
{
    objPainter->end();
    delete ui;
}

void MainWindow::drawGraph()
{
    objPainter->drawLine(100, 100, 200, 200);
    ui->label->setPixmap(*objGraph);
}

void MainWindow::on_buttonDrawLine_clicked()
{
    drawGraph();
}


void MainWindow::on_buttonClear_clicked()
{
    objPainter->eraseRect(0, 0, 500, 300);
    ui->label->setPixmap(*objGraph);
}

