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
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

QT += webkit webkitwidgets

RESOURCES += \
    Resources.qrc



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AgendaModel/release/ -lAgendaModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AgendaModel/debug/ -lAgendaModel
else:unix: LIBS += -L$$OUT_PWD/../AgendaModel/ -lAgendaModel

INCLUDEPATH += $$PWD/../AgendaModel
DEPENDPATH += $$PWD/../AgendaModel





win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AgendaDB/release/ -lAgendaDB
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AgendaDB/debug/ -lAgendaDB

INCLUDEPATH += $$PWD/../AgendaDB
DEPENDPATH += $$PWD/../AgendaDB
