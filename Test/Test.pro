QT      += core gui widgets testlib
TEMPLATE = app
TARGET   = Test
CONFIG  += testcase

include(../_install/rsatoolbox.pri)
HEADERS += VnaIntermodTest.h \
           VnaPauseSweepsTest.h \
           VnaArbitraryFrequencyTest.h \
           VnaSweepTest.h \
           UnitsTest.h \
           VnaCalibrateTest.h \
    VnaChannelTest.h \
    VnaTraceTest.h
SOURCES += main.cpp \
           VnaIntermodTest.cpp \
           VnaPauseSweepsTest.cpp \
           VnaArbitraryFrequencyTest.cpp \
           VnaSweepTest.cpp \
           UnitsTest.cpp \
           VnaCalibrateTest.cpp \
    VnaChannelTest.cpp \
    VnaTraceTest.cpp

DEFINES += SOURCE_DIR=\\\"$$PWD/\\\"
