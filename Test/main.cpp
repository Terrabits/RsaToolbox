

// Tests
#include "VnaArbitraryFrequencyTest.h"
#include "VnaIntermodTest.h"
#include "VnaPauseSweepsTest.h"

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
    testRunner.addTest(new VnaArbitraryFrequencyTest(type, address));
    testRunner.addTest(new VnaIntermodTest          (type, address));
    testRunner.addTest(new VnaPauseSweepsTest       (type, address));

    qDebug() << "Global result: " << (testRunner.runTests() ? "PASS" : "FAIL");
    return 0;
}
