#include "vnasyncgeneratortest.h"

#include <Definitions.h>
using namespace RsaToolbox;

#include <QDebug>
#include <cassert>

VnaSyncGeneratorTest::VnaSyncGeneratorTest(ConnectionType type, const QString &address, QObject *parent) :
    VnaTestClass(type, address, parent)
{
    _logDir.setPath(SOURCE_DIR);
    _logDir.mkpath("logs/VnaSyncGeneratorTest");
    _logDir.refresh();
    assert(_logDir.cd("logs"));
    assert(_logDir.cd("VnaSyncGeneratorTest"));
}

void VnaSyncGeneratorTest::initTestCase() {
    _initTestCase();
    _vna.reset(new Vna(_connectionType, _address));
    QVERIFY(_vna->properties().isInternalPulseGenerator());
    _vna.reset();
}
void VnaSyncGeneratorTest::init() {
    _init();
    _gen = _vna->channel().syncGenerator();
}

void VnaSyncGeneratorTest::stateTest_data() {
    QTest::addColumn<bool>("state");

    QTest::newRow("on")  << true;
    QTest::newRow("off") << false;

    _logFilenames.clear();
    _logFilenames << "state on.txt";
    _logFilenames << "state off.txt";
}
void VnaSyncGeneratorTest::stateTest() {
    QFETCH(bool, state);

    _gen.on(state);
    QVERIFY (!_vna->isError());
    QCOMPARE(_gen.isOn(), state);
    QVERIFY (!_vna->isError());
}

void VnaSyncGeneratorTest::pulseWidthTest_data() {
    QTest::addColumn<double  >("value"  );
    QTest::addColumn<SiPrefix>("prefix" );
    QTest::addColumn<double  >("pulseWidth_s");

    QTest::newRow("0.007") << 0.007 << SiPrefix::None  << 0.007;
    QTest::newRow("7 ms" ) << 7.0   << SiPrefix::Milli << 0.007;
    QTest::newRow("3 us" ) << 3.0   << SiPrefix::Micro << 3e-6;

    _logFilenames.clear();
    _logFilenames << "pulse width 0.007 s.txt";
    _logFilenames << "pulse width 7 ms.txt";
    _logFilenames << "pulse width 3 us.txt";
}
void VnaSyncGeneratorTest::pulseWidthTest() {
    QFETCH(double,   value );
    QFETCH(SiPrefix, prefix);
    QFETCH(double,   pulseWidth_s);

    _gen.setPulseWidth(value, prefix);
    QVERIFY( !_vna->isError());
    QCOMPARE(_gen.pulseWidth_s(), pulseWidth_s);
    QVERIFY( !_vna->isError());
}

void VnaSyncGeneratorTest::periodTest_data() {
    QTest::addColumn<double  >("value"  );
    QTest::addColumn<SiPrefix>("prefix" );
    QTest::addColumn<double  >("pulseWidth_s");

    QTest::newRow("0.700" ) << 0.700 << SiPrefix::None  << 0.700;
    QTest::newRow("700 ms") << 700   << SiPrefix::Milli << 0.007;
    QTest::newRow("3 us"  ) << 3.0   << SiPrefix::Micro << 3e-6;

    _logFilenames.clear();
    _logFilenames << "period 0.700 s.txt";
    _logFilenames << "period 700 ms.txt";
    _logFilenames << "period 3 us.txt";
}
void VnaSyncGeneratorTest::periodTest() {
    QFETCH(double,   value );
    QFETCH(SiPrefix, prefix);
    QFETCH(double,   period_s);

    _gen.setPeriod(value, prefix);
    QVERIFY( !_vna->isError());
    QCOMPARE(_gen.period_s(), period_s);
    QVERIFY( !_vna->isError());
}

void VnaSyncGeneratorTest::invertedTest_data() {
    QTest::addColumn<bool>("state");

    QTest::newRow("on")  << true;
    QTest::newRow("off") << false;

    _logFilenames.clear();
    _logFilenames << "inverted on.txt";
    _logFilenames << "inverted off.txt";
}
void VnaSyncGeneratorTest::invertedTest() {
    QFETCH(bool, state);

    _gen.setInverted(state);
    QVERIFY( !_vna->isError());
    QCOMPARE(_gen.isInverted(), state);
    QVERIFY( !_vna->isError());
}

void VnaSyncGeneratorTest::channelSpecificTest_data() {
    QTest::addColumn<bool>("state");

    QTest::newRow("on")  << true;
    QTest::newRow("off") << false;

    _logFilenames.clear();
    _logFilenames << "channel specific on.txt";
    _logFilenames << "channel specific off.txt";
}
void VnaSyncGeneratorTest::channelSpecificTest() {
    QFETCH(bool, state);

    _gen.setChannelSpecific(state);
    QVERIFY( !_vna->isError());
    QCOMPARE(_gen.isChannelSpecific(), state);
    QVERIFY( !_vna->isError());
}
