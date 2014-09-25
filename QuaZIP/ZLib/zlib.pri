

INCLUDEPATH += $$PWD
DEPENDPATH  += $$PWD
win32 {
        LIBS += -l$$PWD/zdll
	LIBS += -L$$PWD
}
