#-------------------------------------------------
#
# Project created by QtCreator 2014-05-05T14:44:32
#
#-------------------------------------------------

QT       -= gui

TARGET = AgendaModel
TEMPLATE = lib

DEFINES += AGENDAMODEL_LIBRARY

SOURCES += agendamodel.cpp \
    material.cpp \
    requestmaterials.cpp \
    provider_material.cpp


HEADERS += agendamodel.h\
        agendamodel_global.h \
    material.h \
    requestmaterials.h \
    provider_material.h


unix {
    target.path = /usr/lib
    INSTALLS += target
}
