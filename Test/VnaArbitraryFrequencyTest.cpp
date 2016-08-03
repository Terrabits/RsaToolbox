#include "VnaArbitraryFrequencyTest.h"


// RsaToolbox
#include "VnaArbitraryFrequency.h"
using namespace RsaToolbox;


VnaArbitraryFrequencyTest::VnaArbitraryFrequencyTest(ConnectionType type, QString address, QObject *parent) :
    VnaTestClass(type, address, parent)
{

}

VnaArbitraryFrequencyTest::~VnaArbitraryFrequencyTest()
{

}

void VnaArbitraryFrequencyTest::initTestCase() {
    _applicationName = "Vna Arbitrary Frequency Test";
    _version        = "0.0";

    _logDir.setPath(SOURCE_DIR);
    _logDir.mkpath("VnaArbitraryFrequencyTest");
    _logDir.cd("VnaArbitraryFrequencyTest");
    if (isZvaFamily()) {
        QString logpath = SOURCE_DIR;
        logpath += "/VnaArbitraryFrequencyTest/Zva/Logs";
        _logDir.setPath(logpath);
    }
    else if (isZnbFamily()) {
        QString logpath = SOURCE_DIR;
        logpath += "/VnaArbitraryFrequencyTest/Znb/Logs";
        _logDir.setPath(logpath);
    }

    _logFilenames << "1 - Struct Test.txt"
                  << "2 - RF Off Test.txt"
                  << "3 - Generator Test.txt"
                  << "4 - Accessors.txt";

    _initTestCase();
}

void VnaArbitraryFrequencyTest::structTest() {
    // defaults
    VnaArbitraryFrequency af;
    QCOMPARE( af.numerator  (), 1.0);
    QCOMPARE( af.denominator(), 1.0);
    QCOMPARE( af.offset_Hz  (), 0.0);
    QVERIFY (!af.isGeneratorPort());
    QVERIFY (!af.isRfOff        ());
    QVERIFY (!af.isOn           ());

    // generator
    af.setGeneratorPort(true);
    QVERIFY( af.isGeneratorPort());
    QVERIFY( af.isOn           ());
    af.setGeneratorPort(false);
    QVERIFY(!af.isGeneratorPort());
    QVERIFY(!af.isOn           ());

    // rf off
    af.rfOff(true);
    QVERIFY( af.isRfOff());
    QVERIFY( af.isOn   ());
    af.rfOn(true);
    QVERIFY(!af.isRfOff());
    QVERIFY(!af.isOn   ());

    // numerator
    af.setNumerator(2.0);
    QCOMPARE( af.numerator(), 2.0);
    QVERIFY ( af.isOn     ());
    af.setNumerator(1.0);
    QCOMPARE( af.numerator(), 1.0);
    QVERIFY (!af.isOn     ());

    // denominator
    af.setDenominator(2.0);
    QCOMPARE( af.denominator(), 2.0);
    QVERIFY ( af.isOn       ());
    af.setDenominator(1.0);
    QCOMPARE( af.denominator(), 1.0);
    QVERIFY (!af.isOn       ());

    // offset
    af.setOffset(1.0, SiPrefix::Mega);
    QCOMPARE( af.offset_Hz(), 1.0E6);
    QVERIFY ( af.isOn     ());
    af.setOffset(0.0);
    QCOMPARE( af.offset_Hz(),   0.0);
    QVERIFY (!af.isOn     ());

    af.setGeneratorPort(true);
    af.rfOff         (true);
    af.setNumerator  (2.0 );
    af.setDenominator(2.0 );
    af.setOffset     (1.0 );
    QVERIFY( af.isOn ());
    af.clear         () ;
    QVERIFY(!af.isOn ());
}
void VnaArbitraryFrequencyTest::rfOff() {

}
void VnaArbitraryFrequencyTest::generator() {

}
void VnaArbitraryFrequencyTest::accessors() {

}
