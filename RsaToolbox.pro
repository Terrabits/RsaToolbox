#-------------------------------------------------
#
# Project created by QtCreator 2013-03-06T15:10:50
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = RsaToolbox
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    Key.cpp \
    IO.cpp \
    Log.cpp \
    Network.cpp

HEADERS += \
    Vna.h \
    Trace.h \
    Network.h \
    Key.h \
    IO.h \
    Definitions.h \
    Log.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
