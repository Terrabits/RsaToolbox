QT      += core gui widgets testlib
TEMPLATE = app
TARGET   = Test
CONFIG  += testcase

include(../_install/rsatoolbox.pri)
HEADERS += VnaIntermodTest.h \
           VnaPauseSweepsTest.h \
    VnaArbitraryFrequencyTest.h \
    VnaSweepTest.h
SOURCES += main.cpp \
           VnaIntermodTest.cpp \
           VnaPauseSweepsTest.cpp \
    VnaArbitraryFrequencyTest.cpp \
    VnaSweepTest.cpp

DEFINES += SOURCE_DIR=\\\"$$PWD/\\\"
