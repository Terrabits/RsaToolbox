# RsaToolbox core includes

QT += core

HEADERS +=     $$PWD/General/Definitions.h \
               $$PWD/General/General.h \
               $$PWD/General/NameLabel.h \
               $$PWD/General/IndexName.h \
               $$PWD/General/Connector.h \
               $$PWD/General/BalancedPort.h \
               $$PWD/General/NetworkData.h \
               $$PWD/General/NetworkTraceData.h \
               $$PWD/Log/Log.h \
               $$PWD/Bus/GenericBus.h \
               $$PWD/Instruments/GenericInstrument.h

INCLUDEPATH += $$PWD \
               $$PWD/General \
               $$PWD/Log \
               $$PWD/Bus \
               $$PWD/Instruments

SOURCES +=     $$PWD/General/General.cpp \
               $$PWD/General/NameLabel.cpp \
               $$PWD/General/IndexName.cpp \
               $$PWD/General/Connector.cpp \
               $$PWD/General/BalancedPort.cpp \
               $$PWD/General/NetworkData.cpp \
               $$PWD/General/NetworkTraceData.cpp \
               $$PWD/Log/Log.cpp \
               $$PWD/Bus/GenericBus.cpp \
               $$PWD/Instruments/GenericInstrument.cpp
