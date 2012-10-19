#-------------------------------------------------
#
# Project created by QtCreator 2012-10-09T23:19:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pix
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    entityicon.cpp \
    entitymodel.cpp \
    graphicsscene.cpp

HEADERS  += mainwindow.h \
    entityicon.h \
    entitymodel.h \
    graphicsscene.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    EntityModel
