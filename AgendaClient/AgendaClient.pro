#-------------------------------------------------
#
# Project created by QtCreator 2013-12-05T16:08:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Agenda
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    material.cpp \
    requestmaterials.cpp \
    provider.cpp
HEADERS  += mainwindow.h \
    material.h \
    requestmaterials.h \
    provider.h

FORMS    += mainwindow.ui

QT += webkit webkitwidgets

RESOURCES += \
    Resources.qrc
