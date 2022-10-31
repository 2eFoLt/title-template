QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_task19.cpp \
    ../echoServer/task19.cpp

HEADERS += \
        ../echoServer/task19.h
