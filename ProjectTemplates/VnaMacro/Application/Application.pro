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
QT          += core gui widgets
TARGET       = VnaMacro # <%= app.name %>
TEMPLATE     = app

# Files
include(../Core/core.pri)
SOURCES     += main.cpp\
               mainwindow.cpp
HEADERS     += mainwindow.h
FORMS       += mainwindow.ui
RESOURCES   += Resources.qrc
OTHER_FILES += ./_Debug/Log.txt

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
    RC_FILE = MsvcResources.rc
}

## Mac
macx {
    # Mac-ros :-P
}

