#include "VnaChannelTest.h"


// RsaToolbox
using namespace RsaToolbox;


VnaChannelTest::VnaChannelTest(QObject *parent) : VnaTestClass(parent)
{

}
VnaChannelTest::VnaChannelTest(ConnectionType type, const QString &address, QObject *parent) :
    VnaTestClass(type, address, parent)
{

}
VnaChannelTest::~VnaChannelTest()
{

}

void VnaChannelTest::initTestCase() {
    QString path;
    path = "%1/VnaChannelTest/%2/Logs";
    path = path.arg(SOURCE_DIR);
    if (isZvaFamily())
        path = path.arg("ZVA");
    else if (isZnbFamily())
        path = path.arg("ZNB");
    else
        path = path.arg("UNKNOWN");
    _logDir.setPath(path);

    _logFilenames << "1 - Test1.txt";

    _initTestCase();
}
