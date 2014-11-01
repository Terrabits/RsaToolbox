# RsaToolbox::Vna includes
# Note: Requires
#   core.pri
#   tcp.pri
#   visa.pri
#   ... a lot of other things I need to add!

QT += core gui widgets

include($$PWD/Dialogs/vnadialogs.pri)
include($$PWD/Models/vnamodels.pri)
include($$PWD/Views/vnaviews.pri)

HEADERS += $$PWD/VnaUserDefinedPort.h \
           $$PWD/VnaStandardModel.h \
           $$PWD/VnaCalStandard.h \
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
           $$PWD/VnaAveraging.h \
           $$PWD/VnaCalibrate.h \
           $$PWD/VnaCorrections.h \
           $$PWD/VnaPowerCalibrate.h \
           $$PWD/VnaPowerCorrections.h \
           $$PWD/VnaTrace.h \
           $$PWD/VnaMarker.h \
           $$PWD/VnaReferenceMarker.h \
           $$PWD/VnaLimits.h \
           $$PWD/VnaMath.h \
           $$PWD/VnaTimeDomain.h \
           $$PWD/VnaDiagram.h \
           $$PWD/Vna.h
INCLUDEPATH += $$PWD
SOURCES += $$PWD/VnaUserDefinedPort.cpp \
           $$PWD/VnaStandardModel.cpp \
           $$PWD/VnaCalStandard.cpp \
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
           $$PWD/VnaAveraging.cpp \
           $$PWD/VnaCalibrate.cpp \
           $$PWD/VnaCorrections.cpp \
           $$PWD/VnaPowerCalibrate.cpp \
           $$PWD/VnaPowerCorrections.cpp \
           $$PWD/VnaTrace.cpp \
           $$PWD/VnaMarker.cpp \
           $$PWD/VnaReferenceMarker.cpp \
           $$PWD/VnaLimits.cpp \
           $$PWD/VnaMath.cpp \
           $$PWD/VnaTimeDomain.cpp \
           $$PWD/VnaDiagram.cpp \
           $$PWD/Vna.cpp
