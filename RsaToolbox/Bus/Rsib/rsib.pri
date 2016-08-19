# RsaToolbox::RsibBus Requirements
# Note: Requires base.pri

HEADERS += $$PWD/rsib.h \
           $$PWD/RsibBus.h
INCLUDEPATH += $$PWD

SOURCES += $$PWD/RsibBus.cpp

win32: LIBS += -L$$PWD -lrsib32
