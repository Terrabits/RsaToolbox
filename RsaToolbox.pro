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
    IO.cpp \
    Log.cpp \
    Network.cpp \
    General.cpp \
    Touchstone.cpp

HEADERS += \
    Vna.h \
    Trace.h \
    Network.h \
    Key.h \
    IO.h \
    Definitions.h \
    Log.h \
    General.h \
    Touchstone.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

QMAKE_CXXFLAGS += /D_CRT_SECURE_NO_WARNINGS
