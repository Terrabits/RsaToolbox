# RsaToolbox core includes

QT += core

HEADERS +=     $$PWD/General/Definitions.h \
               $$PWD/General/General.h \
               $$PWD/General/NameLabel.h \
               $$PWD/General/IndexName.h \
               $$PWD/General/Connector.h \
               $$PWD/General/BalancedPort.h \
               $$PWD/General/Keys.h \
               $$PWD/General/NetworkTraceData.h \
               $$PWD/General/NetworkData.h \
               $$PWD/General/Touchstone.h \
               $$PWD/General/SnpStreamReader.h \
               $$PWD/General/SnpStreamWriter.h \
               $$PWD/General/FormattedComplex.h \
               $$PWD/General/FormattedNetworkData.h \
               $$PWD/General/FormattedTouchstone.h \
               $$PWD/General/Version.h \
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
               $$PWD/General/Keys.cpp \
               $$PWD/General/NetworkTraceData.cpp \
               $$PWD/General/NetworkData.cpp \
               $$PWD/General/Touchstone.cpp \
               $$PWD/General/SnpStreamReader.cpp \
               $$PWD/General/SnpStreamWriter.cpp \
               $$PWD/General/FormattedComplex.cpp \
               $$PWD/General/FormattedNetworkData.cpp \
               $$PWD/General/FormattedTouchstone.cpp \
               $$PWD/General/Version.cpp \
               $$PWD/Log/Log.cpp \
               $$PWD/Bus/GenericBus.cpp \
               $$PWD/Instruments/GenericInstrument.cpp
