#-------------------------------------------------
#
# Project created by QtCreator 2016-12-16T17:19:58
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Channels
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

include(../../Install/rsatoolbox.pri)
SOURCES += main.cpp

DEFINES     += SOURCE_DIR=\\\"$$PWD\\\"
