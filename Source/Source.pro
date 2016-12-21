#-------------------------------------------------
#
# Project created by QtCreator 2013-11-15T14:00:31
#
#-------------------------------------------------

QT       += core gui

TEMPLATE =  lib
CONFIG   += staticlib
CONFIG   += debug_and_release build_all

include(core.pri)
include(Bus/Tcp/tcp.pri)
include(Bus/No/no.pri)
include(Bus/Visa/visa.pri)
include(Instruments/Vna/vna.pri)
include(Test/test.pri)

DEFINES     += SOURCE_DIR=\\\"$$PWD\\\"
CONFIG(debug, debug|release) {
    TARGET  = RsaToolboxd
}
else {
    TARGET  = RsaToolbox
    DEFINES += QT_NO_DEBUG_OUTPUT
}
win32 {
    QMAKE_CXXFLAGS += /wd4482
}
macx {
    # I have a feeling -std=c++11 is being overridden by a -std=gnu++11 flag...
    QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++ -Wno-trigraphs
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7
}
