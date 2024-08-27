QT      += core gui widgets
TEMPLATE = app
TARGET   = DoubleEditTest
CONFIG  += testcase

include(../../../Install/rsatoolbox.pri)
SOURCES += main.cpp

DEFINES += SOURCE_DIR=\\\"$$PWD/\\\"
