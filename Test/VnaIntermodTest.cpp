

// Tests
#include "VnaIntermod.h"
#include "VnaIntermodTest.h"
using namespace RsaToolbox;

// RsaToolbox
#include "Definitions.h"
#include "Test.h"

// Qt
#include <QScopedPointer>


VnaIntermodTest::VnaIntermodTest(QObject *parent) :
    VnaTestClass(parent)
{
}
VnaIntermodTest::VnaIntermodTest(ConnectionType type, const QString &address, QObject *parent) :
    VnaTestClass(parent)
{
    setConnectionType(type);
    setAddress(address);
}

VnaIntermodTest::~VnaIntermodTest()
{

}

void VnaIntermodTest::initTestCase() {
    _applicationName = "VnaIntermod Test";
    _version        = "0.0";

    _logDir.setPath(SOURCE_DIR);
    _logDir.mkpath("VnaIntermodTest");
    _logDir.cd("VnaIntermodTest");
    if (isZvaFamily()) {
        QString logpath = SOURCE_DIR;
        logpath += "/VnaIntermodTest/Zva/Logs";
        _logDir.setPath(logpath);
    }
    else if (isZnbFamily()) {
        QString logpath = SOURCE_DIR;
        logpath += "/VnaIntermodTest/Znb/Logs";
        _logDir.setPath(logpath);
    }

    _logFilenames << "1 - Basic Test.txt";

    _initTestCase();
}

void VnaIntermodTest::basicTest() {
    VnaIntermod im = _vna->channel().intermod();
    im.setToneDistance(1, SiPrefix::Kilo);
    QVERIFY(!_vna->isError());
    QCOMPARE(im.toneDistance_Hz(), 1000.0);
    QVERIFY(!_vna->isError());

    im.setToneDistance(1, SiPrefix::Mega);
    QVERIFY(!_vna->isError());
    QCOMPARE(im.toneDistance_Hz(), 1.0E6);
    QVERIFY(!_vna->isError());

    im.setLowerTonePort(4);
    QVERIFY(!_vna->isError());
    QCOMPARE(im.lowerTonePort(), uint(4));
    QVERIFY(!_vna->isError());

    im.setLowerTonePort(1);
    QVERIFY(!_vna->isError());
    QCOMPARE(im.lowerTonePort(), uint(1));
    QVERIFY(!_vna->isError());

    VnaIntermod::ToneSource source;
    source.setPort(4);
    im.setUpperToneSource(source);
    QVERIFY(!_vna->isError());
    QCOMPARE(source, im.upperToneSource());
    QVERIFY(!_vna->isError());

    source.setPort(3);
    im.setUpperToneSource(source);
    QVERIFY(!_vna->isError());
    QCOMPARE(source, im.upperToneSource());
    QVERIFY(!_vna->isError());

    // Test generator
//    source.setGenerator(1);
//    im.setUpperToneSource(source);
//    QVERIFY(!_vna->isError());
//    QCOMPARE(source, im.upperToneSource());
//    QVERIFY(!_vna->isError());

    im.setReceivingPort(4);
    QVERIFY(!_vna->isError());
    QCOMPARE(im.receivingPort(), uint(4));
    QVERIFY(!_vna->isError());

    im.setReceivingPort(2);
    QVERIFY(!_vna->isError());
    QCOMPARE(im.receivingPort(), uint(2));
    QVERIFY(!_vna->isError());

    im.order3On();
    QVERIFY(!_vna->isError());
    im.order5On();
    QVERIFY(!_vna->isError());
    im.order7On();
    QVERIFY(!_vna->isError());
    im.order9On();
    QVERIFY(!_vna->isError());
    im.orderOn(3);
    QVERIFY(!_vna->isError());
    im.orderOn(5);
    QVERIFY(!_vna->isError());
    im.orderOn(7);
    QVERIFY(!_vna->isError());
    im.orderOn(9);
    QVERIFY(!_vna->isError());
}
