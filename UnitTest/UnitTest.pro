QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_task3_unittest.cpp \
    ../echoServer/task3.cpp

HEADERS += \
    ../echoServer/task3.h
