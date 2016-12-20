#-------------------------------------------------
#
# Project created by QtCreator 2016-12-16T18:47:45
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Traces
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

include(../../_install/rsatoolbox.pri)
SOURCES += main.cpp

DEFINES     += SOURCE_DIR=\\\"$$PWD\\\"
