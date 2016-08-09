#include "VnaSweepTest.h"


// RsaToolbox
#include "Test.h"
using namespace RsaToolbox;

// Qt
#include <QTest>


VnaSweepTest::VnaSweepTest(QObject *parent) :
    VnaTestClass(parent)
{

}
VnaSweepTest::VnaSweepTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent) :
    VnaTestClass(type, address, parent)
{

}

VnaSweepTest::~VnaSweepTest()
{

}

// Setup
void VnaSweepTest::initTestCase() {
    QString path;
    path = "%1/VnaSweepTest/%2/Logs";
    path = path.arg(SOURCE_DIR);
    if (isZvaFamily())
        path = path.arg("ZVA");
    else if (isZnbFamily())
        path = path.arg("ZNB");
    else
        path = path.arg("UNKNOWN");
    _logDir.setPath(path);

    _logFilenames << "1 - Basic Sweep Test.txt";

    _initTestCase();
}
void VnaSweepTest::init() {
    // Connect, preset:
    // Ch1, Trc1, diagram 1
    _init();

    // Ch2, Trc2
    _vna->createChannel(2);
    _vna->createTrace("Trc2", 2);
    _vna->trace("Trc2").setDiagram(1);

    // Ch3, Trc3
    _vna->createChannel(3);
    _vna->createTrace("Trc3", 3);
    _vna->trace("Trc3").setDiagram(1);

    // Ch4, Trc4
    _vna->createChannel(4);
    _vna->createTrace("Trc4", 4);
    _vna->trace("Trc4").setDiagram(1);
}

// Tests
void VnaSweepTest::basic() {
    _vna->manualSweepOn();
    _vna->pause();

    rememberData();
    QTest::qSleep(250 /*ms*/);
    QVERIFY(isNoNewData());

    _vna->channel(2).startSweep();
    _vna->pause();
    QVERIFY(isNewDataOnlyInChannel(2));

    rememberData();
    _vna->continuousSweepOn();
    QTest::qSleep(250 /*ms*/);
    QVERIFY(isAllNewData());

    rememberData();
    QTest::qSleep(250 /*ms*/);
    QVERIFY(isAllNewData());

    _vna->manualSweepOn();
    _vna->pause();
    rememberData();
    QTest::qSleep(250 /*ms*/);
    QVERIFY(isNoNewData());

    _vna->startSweeps();
    _vna->pause();
    QVERIFY(isAllNewData());

    rememberData();
    QTest::qSleep(250 /*ms*/);
    QVERIFY(isNoNewData());

    if (!_vna->properties().isZvaFamily()) {
        _vna->channel(2).continuousSweepOn();
        QTest::qSleep(250 /*ms*/);
        QVERIFY(isNewDataOnlyInChannel(2));
        rememberData();
        QTest::qSleep(250 /*ms*/);
        QVERIFY(isNewDataOnlyInChannel(2));
    }

    QVERIFY(!_vna->isError());
}

QList<ComplexRowVector> VnaSweepTest::retrieveData() {
    QList<ComplexRowVector> newData;
    newData << _vna->trace("Trc1").y();
    newData << _vna->trace("Trc2").y();
    newData << _vna->trace("Trc3").y();
    newData << _vna->trace("Trc4").y();
    return newData;
}
void VnaSweepTest::rememberData() {
    _data = retrieveData();
}
bool VnaSweepTest::isNewDataOnlyInChannel(uint channel) {
    QList<ComplexRowVector> newData = retrieveData();
    QList<uint> channels;
    channels << 1 << 2 << 3 << 4;
    foreach(const uint c, channels) {
        const int i = c - 1;
        if (c == channel) {
            // Should be new
            if (newData[i] == _data[i])
                return false;
        }
        else {
            // Should be same
            if (newData[i] != _data[i])
                return false;
        }
    }

    return true;
}
bool VnaSweepTest::isAllNewData() {
    QList<ComplexRowVector> newData = retrieveData();
    QList<uint> channels;
    channels << 1 << 2 << 3 << 4;
    foreach(const uint c, channels) {
        const uint i = c - 1;
        // Should be new
        if (newData[i] == _data[i])
            return false;
    }

    return true;
}
bool VnaSweepTest::isNoNewData() {
    QList<ComplexRowVector> newData = retrieveData();
    QList<uint> channels;
    channels << 1 << 2 << 3 << 4;
    foreach(const uint c, channels) {
        const uint i = c - 1;
        // Should be same
        if (newData[i] != _data[i])
            return false;
    }

    return true;
}
