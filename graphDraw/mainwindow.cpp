#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objGraph = new QPixmap(500, 500);
    objPainter = new QPainter;
    objPainter->begin(objGraph);
    objPainter->eraseRect(0, 0, 500, 500);
    ui->label->setPixmap(*objGraph);
}

MainWindow::~MainWindow()
{
    objPainter->end();
    delete ui;
}

void MainWindow::drawGraph()
{
    objPainter->drawLine(ui->lineX1->text().toInt(), ui->lineY1->text().toInt(),
                         ui->lineX2->text().toInt(), ui->lineY2->text().toInt());
    ui->label->setPixmap(*objGraph);
}

void MainWindow::on_buttonDrawLine_clicked()
{
    drawGraph();
}


void MainWindow::on_buttonClear_clicked()
{
    objPainter->eraseRect(0, 0, 500, 500);
    ui->label->setPixmap(*objGraph);
}

