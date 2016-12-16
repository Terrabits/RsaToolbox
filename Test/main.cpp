

// Tests
#include "UnitsTest.h"
#include "VnaArbitraryFrequencyTest.h"
#include "VnaCalibrateTest.h"
#include "VnaIntermodTest.h"
#include "VnaPauseSweepsTest.h"
#include "VnaSweepTest.h"

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
    QString address = "192.168.1.111::5025";
#ifdef Q_OS_WIN
    type = ConnectionType::VisaTcpSocketConnection;
#else
    type = ConnectionType::TcpSocketConnection;
#endif

    TestRunner testRunner;
    testRunner.addTest(new UnitsTest);
    testRunner.addTest(new VnaArbitraryFrequencyTest(type, address));
    testRunner.addTest(new VnaIntermodTest          (type, address));
    testRunner.addTest(new VnaPauseSweepsTest       (type, address));
    testRunner.addTest(new VnaSweepTest             (type, address));
    testRunner.addTest(new VnaCalibrateTest         (type, address));

    qDebug() << "Global result: " << (testRunner.runTests() ? "PASS" : "FAIL");
    return 0;
}
