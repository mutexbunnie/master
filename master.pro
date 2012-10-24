#-------------------------------------------------
#
# Project created by QtCreator 2012-08-03T00:48:02
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = master
TEMPLATE = app


SOURCES += main.cpp\
         mainform.cpp \
    entity.cpp \
    activedialog.cpp \
    entitytype.cpp \
    entitytypebutton.cpp \
    fieldmap.cpp \
    projectstore.cpp \
    stringintturple.cpp \
    datasource.cpp \
    mysqldatasource.cpp \
    graphicsscene.cpp \
    entityicon.cpp \
    edge.cpp \
    graphicsview.cpp

HEADERS  +=mainform.h \
    entity.h \
    activedialog.h \
    entitytype.h \
    entitytypebutton.h \
    fielddescription.h \
    fieldmap.h \
    projectstore.h \
    stringintturple.h \
    datasource.h \
    mysqldatasource.h \
    graphicsscene.h \
    entityicon.h \
    edge.h \
    graphicsview.h

FORMS += \
    mainform.ui

RESOURCES += \
    icons.qrc
