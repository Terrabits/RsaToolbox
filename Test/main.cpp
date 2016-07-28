

// Tests
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
    ConnectionType connectionType;
    QString address = "127.0.0.1::5025";
#ifdef Q_OS_WIN
    connectionType = ConnectionType::VisaTcpSocketConnection;
#else
    connectionType = ConnectionType::TcpSocketConnection;
#endif

    TestRunner testRunner;
    testRunner.addTest(new    VnaIntermodTest(connectionType, address));
    testRunner.addTest(new VnaPauseSweepsTest(connectionType, address));

    qDebug() << "Global result: " << (testRunner.runTests() ? "PASS" : "FAIL");
    return 0;
}
