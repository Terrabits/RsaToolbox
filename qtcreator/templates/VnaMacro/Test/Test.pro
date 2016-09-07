QT      += core gui widgets testlib
TEMPLATE = app
TARGET   = Test
CONFIG  += testcase

include(../Core/core.pri)
HEADERS += ExampleTest.h
SOURCES += main.cpp \
           ExampleTest.cpp

DEFINES += SOURCE_DIR=\\\"$$PWD/\\\"


