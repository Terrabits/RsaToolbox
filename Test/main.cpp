

// Tests
#include "MockBusTest.h"
#include "UnitsTest.h"
#include "VnaArbitraryFrequencyTest.h"
#include "VnaCalibrateTest.h"
#include "VnaChannelTest.h"
#include "VnaIntermodTest.h"
#include "VnaPauseSweepsTest.h"
#include "VnaSweepTest.h"
#include "VnaTraceTest.h"

// RsaToolbox
#include "GenericBus.h"
#include "TestRunner.h"
using namespace RsaToolbox;

// Qt
#include <QApplication>
#include <QDebug>
#include <QTest>


int main()
{
    ConnectionType type;
    QString address = "127.0.0.1::5025";
#ifdef Q_OS_WIN
    type = ConnectionType::VisaTcpSocketConnection;
#else
    type = ConnectionType::TcpSocketConnection;
#endif

    TestRunner testRunner;
    testRunner.addTest(new MockBusTest);
//    testRunner.addTest(new UnitsTest);
//    testRunner.addTest(new VnaChannelTest           (type, address));
//    testRunner.addTest(new VnaArbitraryFrequencyTest(type, address));
//    testRunner.addTest(new VnaIntermodTest          (type, address));
//    testRunner.addTest(new VnaSweepTest             (type, address));
//    testRunner.addTest(new VnaCalibrateTest         (type, address));
//    testRunner.addTest(new VnaPauseSweepsTest       (type, address));
//    testRunner.addTest(new VnaTraceTest             (type, address));

    qDebug() << "Global result: " << (testRunner.runTests() ? "PASS" : "FAIL");
    return 0;
}
