/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *buttonDrawLine;
    QLabel *label;
    QPushButton *buttonClear;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineX1;
    QLineEdit *lineY1;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineX2;
    QLineEdit *lineY2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        buttonDrawLine = new QPushButton(centralwidget);
        buttonDrawLine->setObjectName(QString::fromUtf8("buttonDrawLine"));
        buttonDrawLine->setGeometry(QRect(310, 520, 75, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 561, 421));
        buttonClear = new QPushButton(centralwidget);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));
        buttonClear->setGeometry(QRect(400, 520, 75, 24));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 500, 242, 56));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineX1 = new QLineEdit(widget);
        lineX1->setObjectName(QString::fromUtf8("lineX1"));

        horizontalLayout->addWidget(lineX1);

        lineY1 = new QLineEdit(widget);
        lineY1->setObjectName(QString::fromUtf8("lineY1"));

        horizontalLayout->addWidget(lineY1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineX2 = new QLineEdit(widget);
        lineX2->setObjectName(QString::fromUtf8("lineX2"));

        horizontalLayout_2->addWidget(lineX2);

        lineY2 = new QLineEdit(widget);
        lineY2->setObjectName(QString::fromUtf8("lineY2"));

        horizontalLayout_2->addWidget(lineY2);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonDrawLine->setText(QCoreApplication::translate("MainWindow", "Draw line", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        buttonClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        lineX1->setPlaceholderText(QCoreApplication::translate("MainWindow", "x1", nullptr));
        lineY1->setPlaceholderText(QCoreApplication::translate("MainWindow", "y1", nullptr));
        lineX2->setPlaceholderText(QCoreApplication::translate("MainWindow", "x2", nullptr));
        lineY2->setPlaceholderText(QCoreApplication::translate("MainWindow", "y2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
