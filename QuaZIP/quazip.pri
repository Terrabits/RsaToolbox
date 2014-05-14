

QT += core
INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/ZLib

QZLIB = quazip
CONFIG(debug, debug|release): QZLIB = $$join(QZLIB,,,d)

LIBS += -l$$PWD/$$QZLIB
LIBS += -L$$PWD
LIBS += -L$$PWD/ZLib
