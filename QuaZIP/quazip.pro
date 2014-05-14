

QT += core
QT -= gui

TEMPLATE = lib
CONFIG += shared debug_and_release build_all
DESTDIR = $$PWD
TARGET = quazip
CONFIG(debug, debug|release): TARGET = $$join(TARGET,,,d)

DEFINES += QUAZIP_BUILD
win32: DEFINES += NOMINMAX

include(ZLib/zlib.pri)
HEADERS += $$PWD/crypt.h \
           $$PWD/ioapi.h \
           $$PWD/JlCompress.h \
           $$PWD/quaadler32.h \
           $$PWD/quachecksum32.h \
           $$PWD/quacrc32.h \
           $$PWD/quagzipfile.h \
           $$PWD/quaziodevice.h \
           $$PWD/quazipdir.h \
           $$PWD/quazipfile.h \
           $$PWD/quazipfileinfo.h \
           $$PWD/quazip_global.h \
           $$PWD/quazip.h \
           $$PWD/quazipnewinfo.h \
           $$PWD/unzip.h \
           $$PWD/zip.h
INCLUDEPATH += $$PWD
SOURCES += $$PWD/qioapi.cpp \
           $$PWD/JlCompress.cpp \
           $$PWD/quaadler32.cpp \
           $$PWD/quacrc32.cpp \
           $$PWD/quagzipfile.cpp \
           $$PWD/quaziodevice.cpp \
           $$PWD/quazip.cpp \
           $$PWD/quazipdir.cpp \
           $$PWD/quazipfile.cpp \
           $$PWD/quazipfileinfo.cpp \
           $$PWD/quazipnewinfo.cpp \
           $$PWD/unzip.c \
           $$PWD/zip.c
DEPENDPATH += $$PWD
symbian: LIBS += -lezip
