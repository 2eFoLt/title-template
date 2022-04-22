#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "graphfunctions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void drawGraph();
private slots:
    void on_buttonDrawLine_clicked();

    void on_buttonClear_clicked();

private:
    Graph* objGraph;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
