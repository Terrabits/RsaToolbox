QT      += core gui widgets
TEMPLATE = app
TARGET   = DoubleEditTest
CONFIG  += testcase

include(../../../_install/rsatoolbox.pri)
SOURCES += main.cpp

DEFINES += SOURCE_DIR=\\\"$$PWD/\\\"
