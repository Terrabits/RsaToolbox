
// Requires Qt 5
QT += core gui widgets network printsupport

INCLUDEPATH += $$PWD \
               $$PWD/General \
               $$PWD/Log \
               $$PWD/Bus \
               $$PWD/Bus/Tcp \
               $$PWD/Bus/Rsib \
               $$PWD/Bus/Visa \
               $$PWD/Instruments \
               $$PWD/Instruments/Vna \
               $$PWD/Instruments/Vna/Dialogs \
               $$PWD/Instruments/Vna/Models \
               $$PWD/Instruments/Vna/Views \
               $$PWD/Gui/ErrorLabel \
               $$PWD/Gui/GetSnpFile \
               $$PWD/Gui/ListPanel \
               $$PWD/Gui/PortsLineEdit \
               $$PWD/Gui/Wizard \
               $$PWD/QCustomPlot

# Rsib, RsVisa:
win32: LIBS += -L$$PWD/Bus/Rsib -lrsib32
win32: LIBS += -L$$PWD/Bus/Visa

CONFIG(debug, release|debug) {
  LIBS += -l$$PWD/RsaToolboxd
  LIBS += -l$$PWD/QCustomPlot/qcustomplotd
}
else {
  LIBS += -l$$PWD/RsaToolbox
  LIBS += -l$$PWD/QCustomPlot/qcustomplot
}
LIBS += -L$$PWD
LIBS += -L$$PWD/QCustomPlot/
