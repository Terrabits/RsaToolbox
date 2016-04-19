#-------------------------------------------------
# 
# Project  : %ProjectName%
# App name : %APPLICATION_NAME%
# 
# 
# RsaToolbox
# Template : Rsa Vna App
#            Version 2.0.1
# 
# (C) Rohde & Schwarz America
# 
#-------------------------------------------------


QT          += core gui widgets
TARGET       = %ProjectName%
TEMPLATE     = app

include(RsaToolbox/rsatoolbox.pri)
#include(RsaToolbox/QuaZip/quazip.pri)

HEADERS     += Settings.h \
               MeasureThread.h\
               mainwindow.h
INCLUDEPATH += $$PWD
SOURCES     += main.cpp \
               MeasureThread.cpp \
               mainwindow.cpp
FORMS       += mainwindow.ui
RESOURCES   += Resources.qrc
OTHER_FILES += DEBUG_LOGFILE.txt

DEFINES     += SOURCE_DIR=\\\"$$PWD\\\"
CONFIG(debug, debug|release):DEFINES += DEBUG_MODE
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

LIBS        += -L$$PWD/
win32: RC_FILE = VS2010Resources.rc

