#include "VnaChannelTest.h"


// RsaToolbox
#include "Test.h"
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

    _logFilenames << "1 - Number of logical ports.txt";

    _initTestCase();
}

void VnaChannelTest::numberOfLogicalPorts() {
    // No balanced ports
    VnaChannel ch1 = _vna->channel(1);
    QCOMPARE(_vna->testPorts(), ch1.numberOfLogicalPorts());

    // Last port is balanced
    const uint ports = _vna->testPorts();
    ch1.createBalancedPort(ports-1, ports-1, ports);
    QCOMPARE(_vna->testPorts()-1, ch1.numberOfLogicalPorts());

    _vna->preset();
    _vna->pause();

    // First port is balanced
    ch1.createBalancedPort(1, 1, 2);
    for (uint i = 2; i < ports; i++) {
        ch1.createSingleEndedPort(i, i+1);
    }
    QCOMPARE(_vna->testPorts()-1, ch1.numberOfLogicalPorts());

    _vna->preset();
    _vna->pause();

    ch1.deleteBalancedPorts();
}
