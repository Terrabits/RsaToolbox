# QCustomPlot includes
# Assumes QCustomPlot has been compiled
# for use as a dynamically linked
# library

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

HEADERS += $$PWD/Figure.h
INCLUDEPATH += $$PWD
SOURCES += $$PWD/Figure.cpp
FORMS += $$PWD/Figure.ui

# Link with debug version of qcustomplot if compiling in debug mode, else with release library:
CONFIG(debug, release|debug) {
  win32:QCPLIB = qcustomplotd1
  else: QCPLIB = qcustomplotd
}
else {
  win32:QCPLIB = qcustomplot1
  else: QCPLIB = qcustomplot
}
LIBS += -l$$PWD/$$QCPLIB
LIBS += -L$$PWD/
