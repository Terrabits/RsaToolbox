
# Requires Qt 5
QT += core gui widgets network printsupport

INCLUDEPATH += $$PWD/Include
DEPENDSPATH  += $$PWD/Library # For RsVisa?

win32 {
    QMAKE_CXXFLAGS += /wd4482 # C++11 enum class warnings:
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

LIBS += -L$$PWD/Library # For RsVisa?