#-------------------------------------------------
# Generated from:
# Rohde & Schwarz Vna Macro Template
# (C) 2016 Rohde & Schwarz North America
#
# Requires Qt 5
# Project created by QtCreator <%= Time.zone.now %>
#
#-------------------------------------------------

# Project Settings
QT           += core gui widgets
TEMPLATE      = lib
CONFIG       += staticlib
DESTDIR       = $$PWD/Library
win32: TARGET = Core
macx:  TARGET = libCore
CONFIG(debug, debug|release) {
       TARGET = $$join(TARGET,,,d)
}

# Files
include(../RsaToolbox/rsatoolbox.pri)
HEADERS += Example.h \
           Settings.h
SOURCES += Example.cpp

# Defines
DEFINES += SOURCE_DIR=\\\"$$PWD\\\"
CONFIG(debug, debug|release) {
    DEFINES += DEBUG_MODE
}
CONFIG(release, debug|release) {
    DEFINES += QT_NO_DEBUG_OUTPUT
}

# OS Specific
## Windows
win32 {
    # Windows macros
}

## Mac
macx {
    # Mac-ros :-P
}

