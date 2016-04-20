#-------------------------------------------------
# RsaToolbox
# Qt Creator Project Template
# Copyright (C) 2016 Rohde & Schwarz America 
#
# Author:
# Nick Lalic
# VNA Software Developer
# Rohde & Schwarz North America
# https://vna.rs-us.net/rsatoolbox.html
#
# Project  : %ProjectName%
# App name : %ApplicationName%
# Template : Vna Script
# 
#-------------------------------------------------


QT          += core gui widgets
TARGET       = %ProjectName%
TEMPLATE     = app

include(RsaToolbox/rsatoolbox.pri)
#include(RsaToolbox/QuaZip/quazip.pri)
HEADERS     += Settings.h
INCLUDEPATH += $$PWD
SOURCES     += main.cpp
RESOURCES   += Resources.qrc
OTHER_FILES += DEBUG_LOGFILE.txt

# Executable Icon
win32: RC_FILE = VS2010Resources.rc

DEFINES     += SOURCE_DIR=\\\"$$PWD\\\"
CONFIG(debug, debug|release):DEFINES += DEBUG_MODE
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT
