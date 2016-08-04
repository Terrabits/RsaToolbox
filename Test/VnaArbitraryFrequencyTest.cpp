#include "VnaArbitraryFrequencyTest.h"


// RsaToolbox
#include "Definitions.h"
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
    // Create 2nd channel
    // Make sure it doesn't change
    create2ndChannel();

    const uint port = 1;
    VnaChannel c1   = _vna->channel(1);
    VnaChannel c2   = _vna->channel(2);
    QVERIFY(!c1.isRfOff(port));
    QVERIFY(!c2.isRfOff(port));
    c1.rfOff(port);
    QVERIFY( c1.isRfOff(port));
    QVERIFY(!c2.isRfOff(port));
    c1.rfOn(port);
    QVERIFY(!c1.isRfOff(port));
    QVERIFY(!c2.isRfOff(port));
}
void VnaArbitraryFrequencyTest::generator() {
    // Create 2nd channel
    // Make sure it doesn't change
    create2ndChannel();

    const uint port = 1;
    VnaChannel c1   = _vna->channel(1);
    VnaChannel c2   = _vna->channel(2);
    QVERIFY(!c1.isGeneratorPort(port));
    QVERIFY(!c2.isGeneratorPort(port));
    c1.generatorPortOn(port);
    QVERIFY( c1.isGeneratorPort(port));
    QVERIFY(!c2.isGeneratorPort(port));
    c1.generatorPortOff(port);
    QVERIFY(!c1.isGeneratorPort(port));
    QVERIFY(!c2.isGeneratorPort(port));
}
void VnaArbitraryFrequencyTest::accessors() {
    // Create 2nd channel
    // Make sure it doesn't change
    create2ndChannel();

    VnaArbitraryFrequency af;
    af.setGeneratorPort(true);
    af.rfOff           (true);
    af.setNumerator    (2.0 );
    af.setDenominator  (3.0 );
    af.setOffset       (4.0 , SiPrefix::Mega);

    const uint port = 1;
    VnaChannel c1   = _vna->channel(1);
    c1.setArbitraryFrequency(port, af);
    QVERIFY(c1.isGeneratorPort(port));
    QVERIFY(c1.isRfOff(port));
    VnaArbitraryFrequency _af = c1.arbitraryFrequency(port);
    QVERIFY(af == _af);

    VnaChannel c2 = _vna->channel(2);
    QVERIFY(!c2.arbitraryFrequency(port).isOn());
}

void VnaArbitraryFrequencyTest::create2ndChannel() {
    _vna->createChannel(2);
    _vna->createTrace("Trc2", 2);
    _vna->trace("Trc2").setDiagram(1);
}
