QT += gui

# RsaToolbox includes
HEADERS += $$PWD/Definitions.h \
           $$PWD/General.h \
           $$PWD/NameLabel.h \
           $$PWD/IndexName.h \
           $$PWD/Connector.h \
           $$PWD/BalancedPort.h \
           $$PWD/VnaUserDefinedPort.h \
           $$PWD/VnaStandardModel.h \
           $$PWD/VnaCalStandard.h \
           $$PWD/Key.h \
           $$PWD/Log.h \
           $$PWD/GenericBus.h \
           $$PWD/RsibBus.h \
           $$PWD/rsib.h \
           $$PWD/VisaBus.h \
           $$PWD/visa.h \
           $$PWD/visatype.h \
           $$PWD/GenericInstrument.h \
           $$PWD/VnaProperties.h \
           $$PWD/VnaSettings.h \
           $$PWD/VnaFileSystem.h \
           $$PWD/VnaSwitchMatrix.h \
           $$PWD/VnaCalUnit.h \
           $$PWD/VnaCalKit.h \
           $$PWD/VnaChannel.h \
           $$PWD/VnaLinearSweep.h \
           $$PWD/VnaLogSweep.h \
           $$PWD/VnaSegmentedSweep.h \
           $$PWD/VnaSweepSegment.h \
           $$PWD/VnaPowerSweep.h \
           $$PWD/VnaCwSweep.h \
           $$PWD/VnaTimeSweep.h \
           $$PWD/VnaCalibrate.h \
           $$PWD/VnaCorrections.h \
           $$PWD/VnaPowerCalibrate.h \
           $$PWD/VnaPowerCorrections.h \
           $$PWD/VnaTrace.h \
           $$PWD/VnaMarker.h \
           $$PWD/VnaReferenceMarker.h \
           $$PWD/VnaTimeDomain.h \
           $$PWD/VnaDiagram.h \
           $$PWD/Vna.h
 INCLUDEPATH += $$PWD/

SOURCES += $$PWD/General.cpp \
           $$PWD/NameLabel.cpp \
           $$PWD/IndexName.cpp \
           $$PWD/Connector.cpp \
           $$PWD/BalancedPort.cpp \
           $$PWD/VnaUserDefinedPort.cpp \
           $$PWD/VnaStandardModel.cpp \
           $$PWD/VnaCalStandard.cpp \
           $$PWD/Log.cpp \
           $$PWD/GenericBus.cpp \
           $$PWD/RsibBus.cpp \
           $$PWD/VisaBus.cpp \
           $$PWD/GenericInstrument.cpp \
           $$PWD/VnaProperties.cpp \
           $$PWD/VnaSettings.cpp \
           $$PWD/VnaFileSystem.cpp \
           $$PWD/VnaSwitchMatrix.cpp \
           $$PWD/VnaCalUnit.cpp \
           $$PWD/VnaCalKit.cpp \
           $$PWD/VnaChannel.cpp \
           $$PWD/VnaLinearSweep.cpp \
           $$PWD/VnaLogSweep.cpp \
           $$PWD/VnaSegmentedSweep.cpp \
           $$PWD/VnaSweepSegment.cpp \
           $$PWD/VnaPowerSweep.cpp \
           $$PWD/VnaCwSweep.cpp \
           $$PWD/VnaTimeSweep.cpp \
           $$PWD/VnaCalibrate.cpp \
           $$PWD/VnaCorrections.cpp \
           $$PWD/VnaPowerCalibrate.cpp \
           $$PWD/VnaPowerCorrections.cpp \
           $$PWD/VnaTrace.cpp \
           $$PWD/VnaMarker.cpp \
           $$PWD/VnaReferenceMarker.cpp \
           $$PWD/VnaTimeDomain.cpp \
           $$PWD/VnaDiagram.cpp \
           $$PWD/Vna.cpp

win32: LIBS += -L$$PWD/ -lrsib32
