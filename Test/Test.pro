QT      += core gui widgets testlib
TEMPLATE = app
TARGET   = Test
CONFIG  += testcase

include(../_install/rsatoolbox.pri)
HEADERS += VnaIntermodTest.h \
           VnaPauseSweepsTest.h
SOURCES += main.cpp \
           VnaIntermodTest.cpp \
           VnaPauseSweepsTest.cpp

DEFINES += SOURCE_DIR=\\\"$$PWD/\\\"
