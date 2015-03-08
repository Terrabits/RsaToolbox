

QT          += network gui
HEADERS     += $$PWD/Command.h \
               $$PWD/Menu.h \
               $$PWD/Parser.h \
               $$PWD/ScpiParser.h \
               $$PWD/Server.h
INCLUDEPATH += $$PWD
SOURCES     += $$PWD/Command.cpp \
               $$PWD/Menu.cpp \
               $$PWD/Parser.cpp \
               $$PWD/ScpiParser.cpp \
               $$PWD/Server.cpp
#FORMS       += $$PWD/
#RESOURCES   += $$PWD/

# To Add:
#  - Router
#  - Action
