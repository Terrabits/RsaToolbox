

INCLUDEPATH += $$PWD
DEPENDPATH  += $$PWD
win32 {
    LIBS += -l$$PWD/zdll
    LIBS += -L$$PWD
}
macx {
    LIBS += /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk/usr/lib/libz.dylib
}
