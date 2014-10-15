

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network printsupport

INCLUDEPATH += $$PWD \
               $$PWD/GUI \
               $$PWD/General \
               $$PWD/Log \
               $$PWD/Bus \
               $$PWD/Bus/Tcp \
               $$PWD/Bus/Rsib \
               $$PWD/Bus/Visa \
               $$PWD/Instruments \
               $$PWD/Instruments/Vna \
               $$PWD/Instruments/Vna/Dialogs \
               $$PWD/QCustomPlot

# Rsib:
win32: LIBS += -L$$PWD/Bus/Rsib -lrsib32

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
