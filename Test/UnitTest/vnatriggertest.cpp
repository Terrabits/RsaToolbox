#include "vnatriggertest.h"

#include "VnaTrigger.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QtTest>

#include <cassert>

VnaTriggerTest::VnaTriggerTest(QObject *parent) :
    VnaTestClass(parent)
{
    assert(false);
}

VnaTriggerTest::VnaTriggerTest(ConnectionType type, const QString &address, QObject *parent) :
    VnaTestClass(type, address, parent)
{
    _logDir.setPath(SOURCE_DIR);
    _logDir.mkpath("logs/VnaTriggerTest");
    _logDir.refresh();
    assert(_logDir.cd("logs"));
    assert(_logDir.cd("VnaTriggerTest"));
}

void VnaTriggerTest::init() {
    _init();
    _trigger = _vna->channel(1).trigger();
}

void VnaTriggerTest::sourceTest_data() {
    QTest::addColumn<VnaTriggerSource>("source");

    QTest::newRow("free run") << VnaTriggerSource::FreeRun;
    QTest::newRow("external") << VnaTriggerSource::External;
    QTest::newRow("manual") << VnaTriggerSource::Manual;
//    QTest::newRow("timed") << VnaTriggerSource::Timed; // ZNB
//    QTest::newRow("pulse gen") << VnaTriggerSource::PulseGenerator; // ZVA-K27

    _logFilenames.clear();
    _logFilenames << "source free run.txt";
    _logFilenames << "source external.txt";
    _logFilenames << "source manual.txt";
    _logFilenames << "source timed.txt";
    _logFilenames << "pulse gen.txt";
}
void VnaTriggerTest::sourceTest() {
    QFETCH(VnaTriggerSource, source);

    _trigger.setSource(source);
    QCOMPARE(_trigger.source(), source);
}

void VnaTriggerTest::manualTriggerTest_data() {
    QTest::addColumn<bool>("dummy");

    QTest::newRow("manual trigger") << true;

    _logFilenames.clear();
    _logFilenames << "manual trigger.txt";
}

void VnaTriggerTest::manualTriggerTest() {
    QFETCH(bool, dummy);
    Q_UNUSED(dummy);

    _trigger.setSource(VnaTriggerSource::Manual);
    _trigger.manualTrigger();
    QVERIFY(!_vna->isError());
}

void VnaTriggerTest::onEdgeTest_data() {
    QTest::addColumn<bool>("isOnPositiveEdge");

    QTest::newRow("on pos") << true;
    QTest::newRow("on neg") << false;

    _logFilenames.clear();
    _logFilenames << "trigger on pos edge.txt";
    _logFilenames << "trigger on neg edge.txt";
}
void VnaTriggerTest::onEdgeTest() {
    QFETCH(bool, isOnPositiveEdge);

    _trigger.setOnPositiveEdge(isOnPositiveEdge);
    QCOMPARE(_trigger.isOnPositiveEdge(), isOnPositiveEdge);
}

void VnaTriggerTest::sequenceTest_data() {
    QTest::addColumn<VnaTrigger::Sequence>("sequence");

    QTest::newRow("sweep") << VnaTrigger::Sequence::Sweep;
    QTest::newRow("segment") << VnaTrigger::Sequence::Segment;
    QTest::newRow("point") << VnaTrigger::Sequence::Point;
    QTest::newRow("partial point") << VnaTrigger::Sequence::PartialPoint;

    _logFilenames.clear();
    _logFilenames << "sequence sweep.txt";
    _logFilenames << "sequence segment.txt";
    _logFilenames << "sequence point.txt";
    _logFilenames << "sequence partial point.txt";
}
void VnaTriggerTest::sequenceTest() {
    QFETCH(VnaTrigger::Sequence, sequence);

    _trigger.setSequence(sequence);
    QCOMPARE(_trigger.sequence(), sequence);
}

void VnaTriggerTest::delayTest_data() {
    QTest::addColumn<double>("value");
    QTest::addColumn<SiPrefix>("prefix");
    QTest::addColumn<double>("expected");

    QTest::newRow("1 ms") << 1.0 << SiPrefix::Milli << 1.0e-3;

    _logFilenames.clear();
    _logFilenames << "delay 1 ms.txt";
    _logFilenames << ".txt";/*
    _logFilenames << ".txt";
    _logFilenames << ".txt";*/
}
void VnaTriggerTest::delayTest() {
    QFETCH(double, value);
    QFETCH(SiPrefix, prefix);
    QFETCH(double, expected);

    _trigger.setDelay(value, prefix);
    QCOMPARE(_trigger.delay_s(), expected);
}
