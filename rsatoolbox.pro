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
include(Gui/gui.pri)
include(Gui/FocusAwareWidgets/focusawarewidgets.pri)
include(Instruments/Vna/vna.pri)
include(Test/test.pri)
include(QCustomPlot/qcustomplot.pri)
include(Server/server.pri)
OTHER_FILES += rsatoolbox.pri

DESTDIR     = $$PWD
DEFINES     += SOURCE_DIR=\\\"$$PWD\\\"
CONFIG(debug, debug|release) {
    TARGET  = RsaToolboxd
    DEFINES += DEBUG_MODE
}
else {
    TARGET  = RsaToolbox
    DEFINES += QT_NO_DEBUG_OUTPUT
}
win32 {
    QMAKE_CXXFLAGS += /wd4482
}
macx {
    QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7
}
