

QT += core

DEFINES += NOMINMAX
QZLIB = quazip
CONFIG(debug, debug|release): QZLIB = $$join(QZLIB,,,d)
INCLUDEPATH += $$PWD
DEPENDPATH  += $$PWD
LIBS += -l$$PWD/$$QZLIB
LIBS += -L$$PWD

# ZLIB
INCLUDEPATH += $$PWD/ZLib
DEPENDPATH  += $$PWD/ZLib
win32 {
        LIBS += -l$$PWD/ZLib/zdll
        LIBS += -L$$PWD/ZLib
}
