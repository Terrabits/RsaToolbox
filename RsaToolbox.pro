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
    Log.cpp \
    NetworkData.cpp \
    General.cpp \
    Touchstone.cpp \
    GenericBus.cpp \
    RsibBus.cpp \
    Vna.cpp \
    TraceData.cpp \
    VisaBus.cpp

HEADERS += \
    Vna.h \
    NetworkData.h \
    Key.h \
    Definitions.h \
    Log.h \
    General.h \
    Touchstone.h \
    GenericBus.h \
    RsibBus.h \
    rsib.h \
    TraceData.h \
    visatype.h \
    VisaBus.h \
    visa.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

QMAKE_CXXFLAGS += /D_CRT_SECURE_NO_WARNINGS

OTHER_FILES +=
