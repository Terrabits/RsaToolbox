QT += core
QT -= gui

CONFIG += c++11

TARGET = TimeDomain
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

include(../../Install/rsatoolbox.pri)
SOURCES += main.cpp

DEFINES     += SOURCE_DIR=\\\"$$PWD\\\"
