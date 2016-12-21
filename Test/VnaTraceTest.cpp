#include "VnaTraceTest.h"


// RsaToolbox
using namespace RsaToolbox;


VnaTraceTest::VnaTraceTest(QObject *parent) :
    VnaTestClass(parent)
{

}
VnaTraceTest::VnaTraceTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent) :
    VnaTestClass(type, address, parent)
{

}

VnaTraceTest::~VnaTraceTest()
{

}

void VnaTraceTest::initTestCase() {
    QString path;
    path = "%1/VnaTraceTest/%2/Logs";
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
