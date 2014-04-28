

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

INCLUDEPATH += $$PWD \
               $$PWD/General \
               $$PWD/Log \
               $$PWD/Bus \
               $$PWD/Bus/Rsib \
               $$PWD/Bus/Visa \
               $$PWD/Instruments \
               $$PWD/Instruments/Vna \
               $$PWD/QCustomPlot

# Rsib:
win32: LIBS += -L$$PWD/Bus/Rsib -lrsib32

CONFIG(debug, release|debug) {
  LIBS += -l$$PWD/RsaToolboxd
  win32:QCPLIB = qcustomplotd1
  else: QCPLIB = qcustomplotd
}
else {
  LIBS += -l$$PWD/RsaToolbox
  win32:QCPLIB = qcustomplot1
  else: QCPLIB = qcustomplot
}
LIBS += -l$$PWD/QCustomPlot/$$QCPLIB
LIBS += -L$$PWD/QCustomPlot/
