#-------------------------------------------------
#
# Project created by QtCreator 2014-05-05T14:40:27
#
#-------------------------------------------------

QT       += network sql xml xmlpatterns

QT       -= gui

TARGET = AgendaDB
TEMPLATE = lib

DEFINES += AGENDADB_LIBRARY

SOURCES += agendadb.cpp \
    providerdb.cpp \
    connectionfactory.cpp \
    materialdb.cpp \
    requestmaterialsdb.cpp

HEADERS += agendadb.h\
        agendadb_global.h \
    providerdb.h \
    connectionfactory.h \
    DB.h \
    materialdb.h \
    requestmaterialsdb.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}




win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AgendaModel/release/ -lAgendaModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AgendaModel/debug/ -lAgendaModel

INCLUDEPATH += $$PWD/../AgendaModel
DEPENDPATH += $$PWD/../AgendaModel



INCLUDEPATH += $$PWD/../../Agenda
DEPENDPATH += $$PWD/../../Agenda
