# RsaToolbox::Vna includes
# Note: Requires
#   base.pri
#   rsib.pri
#   visa.pri

QT += gui

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
           $$PWD/VnaTimeDomain.h \
           $$PWD/VnaDiagram.h \
           $$PWD/Vna.h \
           $$PWD/Dialogs/getCalibrationDialog.h \
           $$PWD/Dialogs/getChannelDialog.h \
           $$PWD/Dialogs/getPortsDialog.h

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
           $$PWD/VnaTimeDomain.cpp \
           $$PWD/VnaDiagram.cpp \
           $$PWD/Vna.cpp \
           $$PWD/Dialogs/getCalibrationDialog.cpp \
           $$PWD/Dialogs/getChannelDialog.cpp \
           $$PWD/Dialogs/getPortsDialog.cpp

FORMS += $$PWD/Dialogs/getCalibrationDialog.ui \
         $$PWD/Dialogs/getChannelDialog.ui \
         $$PWD/Dialogs/getPortsDialog.ui

INCLUDEPATH += $$PWD \
               $$PWD/Dialogs
