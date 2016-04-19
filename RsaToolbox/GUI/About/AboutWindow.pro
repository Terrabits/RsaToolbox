#-------------------------------------------------
#
# Project created by QtCreator 2014-12-15T09:28:08
#
#-------------------------------------------------

QT          += core gui widgets
TARGET      = AboutWindow
TEMPLATE    = app

SOURCES     += main.cpp\
             About.cpp
HEADERS     += About.h
FORMS       += About.ui
RESOURCES   += AboutResources.qrc

DEFINES     += SOURCE_DIR=\\\"$$PWD\\\"
CONFIG(debug, debug|release) {
    DEFINES += DEBUG_MODE
}
else {
    DEFINES += QT_NO_DEBUG_OUTPUT
}
