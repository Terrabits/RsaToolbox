# QCustomPlot includes
# Assumes QCustomPlot has been compiled
# for use as a dynamically linked
# library

QT += core gui widgets printsupport

#HEADERS += $$PWD/.h
INCLUDEPATH += $$PWD
#SOURCES += $$PWD/.cpp
#FORMS += $$PWD/.ui

# Use library
DEFINES += QCUSTOMPLOT_USE_LIBRARY

# Link debug|release version:
QCPLIB = qcustomplot
CONFIG(debug, debug|release): QCPLIB = $$join(QCPLIB,,,d)
#win32: QCPLIB = $$join(QCPLIB,,,1)
LIBS += -l$$PWD/$$QCPLIB
LIBS += -L$$PWD/
