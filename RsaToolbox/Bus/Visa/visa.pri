# RsaToolbox::VisaBus includes
# Note: Requires base.pri

QT += core

HEADERS     += $$PWD/VisaBus.h
INCLUDEPATH += $$PWD
SOURCES     += $$PWD/VisaBus.cpp
DEPENDPATH  += $$PWD
win32: LIBS += -L$$PWD

