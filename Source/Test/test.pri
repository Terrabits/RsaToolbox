

QT          += core testlib
HEADERS     += $$PWD/TestRunner/TestRunner.h \
               $$PWD/SpeedTracker/SpeedTracker.h \
               $$PWD/SpeedTracker/SpeedTrackerChild.h \
               $$PWD/Test.h \
               $$PWD/TestClass.h \
               $$PWD/VnaTestClass.h \
               $$PWD/MockBus.h
INCLUDEPATH += $$PWD \
               $$PWD/TestRunner \
               $$PWD/SpeedTracker
SOURCES     += $$PWD/TestRunner/TestRunner.cpp \
               $$PWD/SpeedTracker/SpeedTracker.cpp \
               $$PWD/SpeedTracker/SpeedTrackerChild.cpp \
               $$PWD/Test.cpp \
               $$PWD/TestClass.cpp \
               $$PWD/VnaTestClass.cpp \
               $$PWD/MockBus.cpp
