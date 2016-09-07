#-------------------------------------------------
# Generated from:
# Rohde & Schwarz Vna Macro Template
# (C) 2016 Rohde & Schwarz North America
#
# Requires Qt 5
# Project created by QtCreator <%= Time.zone.now %>
#
#-------------------------------------------------

# Project Settings
QT           += core gui widgets

# Files
include($$PWD/../RsaToolbox/rsatoolbox.pri)
INCLUDEPATH  += $$PWD
DEPENDPATH   += $$PWD/Library

# OS Specific
## Windows (Msvc)
win32 {
  # Libs
  LIBS += -L$$PWD
  CONFIG(debug, release|debug) {
    LIBS += -l$$PWD/Library/Cored
  }
  else {
    LIBS += -l$$PWD/Library/Core
  }
}

## Mac OS X (XCode)
macx {
  # Libs
  LIBS += -stdlib=libc++
  LIBS += -L$$PWD
  CONFIG(debug, release|debug) {
    LIBS += $$PWD/Library/libCored.a
  }
  else {
    LIBS += $$PWD/Library/libCore.a
  }
}

