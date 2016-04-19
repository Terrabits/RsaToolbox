
# Requires Qt 5
QT += core gui widgets network printsupport

INCLUDEPATH += $$PWD/RsaToolbox/General \
               $$PWD/RsaToolbox/Log \
               $$PWD/RsaToolbox/Bus \
               $$PWD/RsaToolbox/Bus/Tcp \
               $$PWD/RsaToolbox/Bus/No \
               $$PWD/RsaToolbox/Bus/Visa \
               $$PWD/RsaToolbox/Instruments \
               $$PWD/RsaToolbox/Instruments/Vna \
               $$PWD/RsaToolbox/Instruments/Vna/Dialogs/getCalGroupDialog \
               $$PWD/RsaToolbox/Instruments/Vna/Dialogs/getChannelDialog \
               $$PWD/RsaToolbox/Instruments/Vna/Dialogs/getPortsDialog \
               $$PWD/RsaToolbox/Instruments/Vna/Models/VnaModel \
               $$PWD/RsaToolbox/Instruments/Vna/Models/ChannelsModel \
               $$PWD/RsaToolbox/Instruments/Vna/Models/CalGroupsModel \
               $$PWD/RsaToolbox/Instruments/Vna/Views/VnaForm \
               $$PWD/RsaToolbox/Instruments/Vna/Views/CalGroupPanel \
               $$PWD/RsaToolbox/Gui/About \
               $$PWD/RsaToolbox/Gui/DecibelEdit \
               $$PWD/RsaToolbox/Gui/ConnectButton \
               $$PWD/RsaToolbox/Gui/ConnectionTypeComboBox \
               $$PWD/RsaToolbox/Gui/DecibelEdit \
               $$PWD/RsaToolbox/Gui/ErrorLabel \
               $$PWD/RsaToolbox/Gui/Figure \
               $$PWD/RsaToolbox/Gui/FrequencyEdit \
               $$PWD/RsaToolbox/Gui/getSaveFileNameWidget \
               $$PWD/RsaToolbox/Gui/GetSnpFile \
               $$PWD/RsaToolbox/Gui/LastPath \
               $$PWD/RsaToolbox/Gui/ListPanel \
               $$PWD/RsaToolbox/Gui/PointsEdit \
               $$PWD/RsaToolbox/Gui/PortsLineEdit \
               $$PWD/RsaToolbox/Gui/PowerEdit \
               $$PWD/RsaToolbox/Gui/TimedProgressBar \
               $$PWD/RsaToolbox/Gui/Update \
               $$PWD/RsaToolbox/Gui/Wizard \
               $$PWD/RsaToolbox/Test \
               $$PWD/RsaToolbox/Test/TestRunner \
               $$PWD/RsaToolbox/Test/SpeedTracker \
               $$PWD/RsaToolbox/QCustomPlot \
               $$PWD/RsaToolbox/Server

win32 {
    # C++11 enum class warnings:
    QMAKE_CXXFLAGS += /wd4482

    LIBS += -L$$PWD/RsaToolbox/Bus/Visa # RsVisa
    LIBS += -L$$PWD
    LIBS += -L$$PWD/QCustomPlot/
    CONFIG(debug, release|debug) {
        LIBS += -l$$PWD/RsaToolboxd
        LIBS += -l$$PWD/QCustomPlot/qcustomplotd
    }
    else {
        LIBS += -l$$PWD/RsaToolbox
        LIBS += -l$$PWD/QCustomPlot/qcustomplot
    }
}
macx {
    QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7
    LIBS += -stdlib=libc++
    LIBS += -L$$PWD \
            -L$$PWD/QCustomPlot
    CONFIG(debug, release|debug) {
        LIBS += $$PWD/libRsaToolboxd.a
    }
    else {
        LIBS += $$PWD/libRsaToolbox.a
    }
}
