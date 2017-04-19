

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

    _logFilenames << "1 - Settings Test.txt"
                  << "2 - Traces Test.txt";

    _initTestCase();
}

void VnaIntermodTest::settings() {
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

void VnaIntermodTest::traces() {
    VnaChannel channel   = _vna->channel();
    VnaLinearSweep sweep = channel.linearSweep();
    VnaIntermod intermod = channel.intermod();

    sweep.setStart(          1, SiPrefix::Giga);
    sweep.setStop(           2, SiPrefix::Giga);
    sweep.setIfbandwidth(    1, SiPrefix::Kilo);
    intermod.setToneDistance(1, SiPrefix::Mega);

    VnaIntermod::ToneSource upperSource;
    upperSource.setPort(3);
    intermod.setUpperToneSource(upperSource);
    intermod.setLowerTonePort(1);
    intermod.setReceivingPort(2);
    intermod.order3On();
    intermod.order5On();
    intermod.order7On();
    intermod.order9On();
    QVERIFY(!_vna->isError());

    // Original tones
    VnaTrace trc1 = _vna->trace();
    trc1.setIntermodTone(VnaTrace::Side::Lower, VnaTrace::At::Input);
    QCOMPARE(trc1.parameter(), QString("LTI"));
    trc1.setIntermodTone(VnaTrace::Side::Lower, VnaTrace::At::Output);
    QCOMPARE(trc1.parameter(), QString("LTO"));
    trc1.setIntermodTone(VnaTrace::Side::Upper, VnaTrace::At::Input);
    QCOMPARE(trc1.parameter(), QString("UTI"));
    trc1.setIntermodTone(VnaTrace::Side::Upper, VnaTrace::At::Output);
    QCOMPARE(trc1.parameter(), QString("UTO"));

    // Intermod
    trc1.setIntermod(3, VnaTrace::Side::Lower);
    QCOMPARE(trc1.parameter(), QString("IM3LO"));
    trc1.setIntermod(5, VnaTrace::Side::Upper);
    QCOMPARE(trc1.parameter(), QString("IM5UO"));
    trc1.setIntermod(7, VnaTrace::Side::Major);
    QCOMPARE(trc1.parameter(), QString("IM7MO"));

    // Intermod rejection
    trc1.setIntermodRejection(5, VnaTrace::Side::Lower);
    QCOMPARE(trc1.parameter(), QString("IM5LOR"));
    trc1.setIntermodRejection(7, VnaTrace::Side::Upper);
    QCOMPARE(trc1.parameter(), QString("IM7UOR"));
    trc1.setIntermodRejection(9, VnaTrace::Side::Major);
    QCOMPARE(trc1.parameter(), QString("IM9MOR"));

    // Intercept Point
    trc1.setIntermodIntercept(3, VnaTrace::Side::Lower);
    QCOMPARE(trc1.parameter(), QString("IP3LO"));
    trc1.setIntermodIntercept(5, VnaTrace::Side::Upper);
    QCOMPARE(trc1.parameter(), QString("IP5UO"));
    trc1.setIntermodIntercept(7, VnaTrace::Side::Major);
    QCOMPARE(trc1.parameter(), QString("IP7MO"));
}
