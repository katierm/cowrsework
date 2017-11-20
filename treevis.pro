#-------------------------------------------------
#
# Project created by QtCreator 2017-11-18T14:23:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = treevis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    codetree.cpp \
    treewidget.cpp \
    treeview.cpp \
    codetree1.cpp \
    haffman.cpp

HEADERS  += mainwindow.h \
    codetree.h \
    treewidget.h \
    treeview.h \
    codetree1.h \
    haffman.h \
    priority_queue.h

FORMS    += mainwindow.ui
