
# Requires Qt 5
QT += core gui widgets network printsupport

INCLUDEPATH +=   $$PWD/Include
DEPENDPATH  +=   $$PWD/Library
LIBS        += -L$$PWD/Library

win32 {
    CONFIG(debug, release|debug) {
        LIBS += -l$$PWD/Library/RsaToolboxd
    }
    else {
        LIBS += -l$$PWD/Library/RsaToolbox
    }
}
macx {
    QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7
    LIBS += -stdlib=libc++ # Redundant?
    CONFIG(debug, release|debug) {
        LIBS += $$PWD/Library/libRsaToolboxd.a
    }
    else {
        LIBS += $$PWD/Library/libRsaToolbox.a
    }
}
