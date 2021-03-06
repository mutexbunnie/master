#-------------------------------------------------
#
# Project created by QtCreator 2012-08-03T00:48:02
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += xml
LIBS +=  -lkparts -lkdecore -lgvc -lgraph -lcdt
INCLUDEPATH+="/usr/include/graphviz"

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = master
TEMPLATE = app


SOURCES += main.cpp\
         mainform.cpp \
    entitytype.cpp \
    projectstore.cpp \
    graphicsscene.cpp \
    entityicon.cpp \
    edge.cpp \
    graphicsview.cpp \
    entitysource.cpp \
    projectsheet.cpp \
    datasource.cpp \
    autolink.cpp \
    graphicsheet.cpp \
    gvgraph.cpp \
    scenetoolbar.cpp

HEADERS  +=mainform.h \
    entitytype.h \
    projectstore.h \
    graphicsscene.h \
    entityicon.h \
    edge.h \
    graphicsview.h \
    entitysource.h \
    projectsheet.h \
    datasource.h \
    autolink.h \
    graphicsheet.h \
    gvgraph.h \
    scenetoolbar.h

FORMS += \
    mainform.ui

RESOURCES += \
    icons.qrc
