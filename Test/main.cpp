

// Tests
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
    ConnectionType connectionType = ConnectionType::VisaTcpSocketConnection;
    QString address = "127.0.0.1::5025";

    TestRunner testRunner;
    testRunner.addTest(new VnaPauseSweepsTest(connectionType, address));

    qDebug() << "Global result: " << (testRunner.runTests() ? "PASS" : "FAIL");
    return 0;
}
