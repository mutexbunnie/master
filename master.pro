#-------------------------------------------------
#
# Project created by QtCreator 2012-08-03T00:48:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = master
TEMPLATE = app


SOURCES += main.cpp\
         mainform.cpp \
    entity.cpp \
    activedialog.cpp

HEADERS  +=mainform.h \
    entity.h \
    activedialog.h

FORMS += \
    mainform.ui

RESOURCES += \
    icons.qrc
