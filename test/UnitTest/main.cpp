﻿

// Tests
#include "genericinstrumenttest.h"
#include "MockBusTest.h"
#include "UnitsTest.h"
#include "visabustest.h"
#include "VnaArbitraryFrequencyTest.h"
#include "VnaCalibrateTest.h"
#include "VnaChannelTest.h"
#include "VnaIntermodTest.h"
#include "VnaPauseSweepsTest.h"
#include "vnapulsegeneratortest.h"
#include "VnaSweepTest.h"
#include "vnasyncgeneratortest.h"
#include "VnaTraceTest.h"
#include "vnatriggertest.h"
#include "vnaundotest.h"

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
//#ifdef Q_OS_WIN
//    type = ConnectionType::VisaTcpSocketConnection;
//#else
//    type = ConnectionType::TcpSocketConnection;
//#endif

    type            = ConnectionType::VisaTcpSocketConnection;
    QString address = "localhost::5025";

    TestRunner testRunner;
    testRunner.addTest(new GenericInstrumentTest);
    testRunner.addTest(new MockBusTest);
    testRunner.addTest(new VnaUndoTest(type, address));
    testRunner.addTest(new VisaBusTest);
    testRunner.addTest(new VnaPulseGeneratorTest(type, address));
    testRunner.addTest(new VnaSyncGeneratorTest(type, address));
    testRunner.addTest(new VnaTriggerTest(type, address));
    testRunner.addTest(new UnitsTest);
    testRunner.addTest(new VnaChannelTest           (type, address));
    testRunner.addTest(new VnaArbitraryFrequencyTest(type, address));
    testRunner.addTest(new VnaIntermodTest          (type, address));
    testRunner.addTest(new VnaSweepTest             (type, address));
    testRunner.addTest(new VnaCalibrateTest         (type, address));
    testRunner.addTest(new VnaPauseSweepsTest       (type, address));
    testRunner.addTest(new VnaTraceTest             (type, address));

    qDebug() << "Global result: " << (testRunner.runTests() ? "PASS" : "FAIL");
    return 0;
}
