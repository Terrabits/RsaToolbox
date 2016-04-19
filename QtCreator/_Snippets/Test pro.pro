

QT        += core testlib
TEMPLATE   = app
TARGET     = UnitTests
CONFIG    -= app_bundle
CONFIG    += console \
             testcase

#include(../Core/core.pri)
#HEADERS   += Test1.h
SOURCES   += main.cpp #\
#             Test1.cpp

DEFINES   += SOURCE_DIR=\\\"$$PWD/\\\"
