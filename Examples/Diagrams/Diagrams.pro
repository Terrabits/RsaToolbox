#-------------------------------------------------
#
# Project created by QtCreator 2016-12-16T17:54:58
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Diagrams
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

include(../../Install/rsatoolbox.pri)
SOURCES += main.cpp

DEFINES     += SOURCE_DIR=\\\"$$PWD\\\"
