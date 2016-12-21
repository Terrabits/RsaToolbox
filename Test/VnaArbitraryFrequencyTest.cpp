#include "VnaArbitraryFrequencyTest.h"


// RsaToolbox
#include "Definitions.h"
#include "Test.h"
#include "VnaArbitraryFrequency.h"
#include "VnaChannel.h"
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
                  << "2 - Port RF Off.txt"
                  << "3 - Port as Generator.txt"
                  << "4 - Port Source Arbitrary Freq.txt"
                  << "5 - Receiver Arbitrary Freq.txt"
                  << "6 - Generator RF Off.txt"
                  << "7 - Generator Perm On.txt";

    _initTestCase();
}

void VnaArbitraryFrequencyTest::structTest() {
    // defaults
    VnaArbitraryFrequency af;
    QCOMPARE( af.numerator  (), 1.0);
    QCOMPARE( af.denominator(), 1.0);
    QCOMPARE( af.offset_Hz  (), 0.0);
    QVERIFY (!af.isOn           ());

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

    af.setNumerator  (2.0 );
    af.setDenominator(2.0 );
    af.setOffset     (1.0 );
    QVERIFY( af.isOn ());
    af.clear         () ;
    QVERIFY(!af.isOn ());
}
void VnaArbitraryFrequencyTest::portRfOff() {
    // Create 2nd channel
    // Make sure it doesn't change
    create2ndChannel();

    const uint port1 = 1;
    const uint port2 = 2;
    VnaChannel c1   = _vna->channel(1);
    VnaChannel c2   = _vna->channel(2);
    QVERIFY(!c1.port(port1).isRfOff());
    QVERIFY(!c1.port(port2).isRfOff());
    QVERIFY(!c2.port(port1).isRfOff());
    QVERIFY(!c2.port(port2).isRfOff());
    c1.port(port1).rfOff();
    QVERIFY( c1.port(port1).isRfOff());
    QVERIFY(!c1.port(port2).isRfOff());
    QVERIFY(!c2.port(port1).isRfOff());
    QVERIFY(!c2.port(port2).isRfOff());
    c1.port(port1).rfOff(false);
    QVERIFY(!c1.port(port1).isRfOff());
    QVERIFY(!c1.port(port2).isRfOff());
    QVERIFY(!c2.port(port1).isRfOff());
    QVERIFY(!c2.port(port2).isRfOff());
}
void VnaArbitraryFrequencyTest::portAsGenerator() {
    // Create 2nd channel
    // Make sure it doesn't change
    create2ndChannel();

    const uint port1 = 1;
    const uint port2 = 2;
    VnaChannel c1   = _vna->channel(1);
    VnaChannel c2   = _vna->channel(2);
    QVERIFY(!c1.port(port1).isGenerator());
    QVERIFY(!c1.port(port2).isGenerator());
    QVERIFY(!c2.port(port1).isGenerator());
    QVERIFY(!c2.port(port2).isGenerator());
    c1.port(port1).setGenerator();
    QVERIFY( c1.port(port1).isGenerator());
    QVERIFY(!c1.port(port2).isGenerator());
    QVERIFY(!c2.port(port1).isGenerator());
    QVERIFY(!c2.port(port2).isGenerator());
    c1.port(port1).setGenerator(false);
    QVERIFY(!c1.port(port1).isGenerator());
    QVERIFY(!c1.port(port2).isGenerator());
    QVERIFY(!c2.port(port1).isGenerator());
    QVERIFY(!c2.port(port2).isGenerator());
}
void VnaArbitraryFrequencyTest::portSourceArbFreq() {
    // Create 2nd channel
    // Make sure it doesn't change
    create2ndChannel();

    VnaArbitraryFrequency af;
    af.setNumerator    (2.0 );
    af.setDenominator  (3.0 );
    af.setOffset       (4.0 , SiPrefix::Mega);

    const uint port = 1;
    VnaChannel c1   = _vna->channel(1);
    c1.port(port).setArbitrarySourceFrequency(af);
    VnaArbitraryFrequency _af = c1.port(port).arbitrarySourceFrequency();
    QVERIFY(af == _af);

    VnaChannel c2 = _vna->channel(2);
    QVERIFY(!c2.port(port).arbitrarySourceFrequency().isOn());
}
void VnaArbitraryFrequencyTest::receiverArbFreq() {
    if (!_vna->properties().isZvaFamily()) {
        qDebug() << "ZVA ONLY";
        return;
    }

    // Create 2nd channel
    // Make sure it doesn't change
    create2ndChannel();

    VnaArbitraryFrequency af;
    af.setNumerator    (2.0 );
    af.setDenominator  (3.0 );
    af.setOffset       (4.0 , SiPrefix::Mega);

    VnaChannel c1   = _vna->channel(1);
    c1.setArbitraryReceiverFrequency(af);
    VnaArbitraryFrequency _af = c1.arbitraryReceiverFrequency();
    QVERIFY(af == _af);

    VnaChannel c2 = _vna->channel(2);
    QVERIFY(!c2.arbitraryReceiverFrequency().isOn());
}
void VnaArbitraryFrequencyTest::generatorRfOff() {
    if (_vna->generators().isEmpty()) {
        qDebug() << "REQUIRES GENERATOR";
        return;
    }

    create2ndChannel();
    VnaChannel c1 = _vna->channel(1);
    VnaChannel c2 = _vna->channel(2);

    c1.generator(1).rfOff(true);
    QVERIFY( c1.generator(1).isRfOff());
    QVERIFY(!c2.generator(1).isRfOff());
    c1.generator(1).rfOff(false);
    QVERIFY(!c1.generator(1).isRfOff());
    QVERIFY(!c2.generator(1).isRfOff());
}
void VnaArbitraryFrequencyTest::generatorPerm() {
    if (_vna->generators().isEmpty()) {
        qDebug() << "REQUIRES GENERATOR";
        return;
    }

    create2ndChannel();
    VnaChannel c1 = _vna->channel(1);
    VnaChannel c2 = _vna->channel(2);
    c1.generator(1).setPermanentlyOn();
    QVERIFY( c1.generator(1).isPermanentlyOn());
    QVERIFY(!c2.generator(1).isPermanentlyOn());
    c1.generator(1).setPermanentlyOn(false);
    QVERIFY(!c1.generator(1).isPermanentlyOn());
    QVERIFY(!c2.generator(1).isPermanentlyOn());
}
void VnaArbitraryFrequencyTest::create2ndChannel() {
    _vna->createChannel(2);
    _vna->createTrace("Trc2", 2);
    _vna->trace("Trc2").setDiagram(1);
}
