

QT          += testlib
HEADERS     += $$PWD/TestRunner/TestRunner.h \
               $$PWD/SpeedTracker/SpeedTracker.h \
               $$PWD/SpeedTracker/SpeedTrackerChild.h
INCLUDEPATH += $$PWD \
               $$PWD/TestRunner \
               $$PWD/SpeedTracker
SOURCES     += $$PWD/TestRunner/TestRunner.cpp \
               $$PWD/SpeedTracker/SpeedTracker.cpp \
               $$PWD/SpeedTracker/SpeedTrackerChild.cpp
