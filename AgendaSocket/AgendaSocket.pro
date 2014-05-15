#-------------------------------------------------
#
# Project created by QtCreator 2014-05-14T17:19:25
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = AgendaSocket
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    socket.cpp

HEADERS += \
    socket.h


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AgendaModel/release/ -lAgendaModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AgendaModel/debug/ -lAgendaModel

INCLUDEPATH += $$PWD/../AgendaModel
DEPENDPATH += $$PWD/../AgendaModel
