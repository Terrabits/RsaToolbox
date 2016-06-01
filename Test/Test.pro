QT      += core gui widgets testlib
TEMPLATE = app
TARGET   = Test
CONFIG  += testcase

include(../_install/rsatoolbox.pri)
HEADERS += VnaPauseSweepsTest.h
SOURCES += main.cpp \
           VnaPauseSweepsTest.cpp

DEFINES += SOURCE_DIR=\\\"$$PWD/\\\"
