

// Tests
#include "VnaPauseSweepsTest.h"
#include "VnaPauseSweeps.h"
using namespace RsaToolbox;

// RsaToolbox
#include "Test.h"

// Qt
#include <QScopedPointer>


VnaPauseSweepsTest::VnaPauseSweepsTest(QObject *parent) :
    VnaTestClass(parent)
{
}
VnaPauseSweepsTest::VnaPauseSweepsTest(ConnectionType type, const QString &address, QObject *parent) :
    VnaTestClass(parent)
{
    setConnectionType(type);
    setAddress(address);
}

VnaPauseSweepsTest::~VnaPauseSweepsTest()
{

}

void VnaPauseSweepsTest::initTestCase() {
    _applicationName = "VnaPauseSweeps Test";
    _version        = "0.0";

    _logDir.setPath(SOURCE_DIR);
    _logDir.mkpath("VnaPauseSweepsTest");
    _logDir.cd("VnaPauseSweepsTest");
    if (isZvaFamily()) {
        QString logpath = SOURCE_DIR;
        logpath += "/VnaPauseSweepsTest/Zva/Logs";
        _logDir.setPath(logpath);
    }
    else if (isZnbFamily()) {
        QString logpath = SOURCE_DIR;
        logpath += "/VnaPauseSweepsTest/Znb/Logs";
        _logDir.setPath(logpath);
    }

    _logFilenames << "1 - Single Continuous Channel.txt"
                  << "2 - Single Manual Channel.txt"
                  << "3 - Many Continuous Channels.txt"
                  << "4 - Many Manual Channels.txt"
                  << "5 - Mixed Channels.txt"
                  << "6 - Deleted Channels.txt.txt"
                  << "7 - No Pause in Constructor.txt"
                  << "8 - No Restore in Constructor.txt"
                  << "9 - Manual Operation.txt";

    _initTestCase();
}

void VnaPauseSweepsTest::singleContinuousChannel() {
    if (!_vna->isChannel(1))
        _vna->createChannel(1);
    _vna->channel().continuousSweepOn();
    QScopedPointer<VnaPauseSweeps> pauseSweeps(new VnaPauseSweeps(_vna.data()));
    QVERIFY(_vna->channel().isManualSweep());
    pauseSweeps.reset();
    QVERIFY(_vna->channel().isContinuousSweep());
    QVERIFY(!_vna->isError());
}
void VnaPauseSweepsTest::singleManualChannel() {
    if (!_vna->isChannel(1))
        _vna->createChannel(1);
    _vna->channel().manualSweepOn();
    QScopedPointer<VnaPauseSweeps> pauseSweeps(new VnaPauseSweeps(_vna.data()));
    QVERIFY(_vna->channel().isManualSweep());
    pauseSweeps.reset();
    QVERIFY(_vna->channel().isManualSweep());
    QVERIFY(!_vna->isError());
}
void VnaPauseSweepsTest::manyContinuousChannels() {
    if (!_vna->isChannel(1))
        _vna->createChannel(1);
    _vna->createChannel(2);
    _vna->createChannel(3);
    _vna->createChannel(4);

    _vna->channel(1).continuousSweepOn();
    _vna->channel(2).continuousSweepOn();
    _vna->channel(3).continuousSweepOn();
    _vna->channel(4).continuousSweepOn();

    QScopedPointer<VnaPauseSweeps> pauseSweeps(new VnaPauseSweeps(_vna.data()));
    QVERIFY(_vna->channel(1).isManualSweep());
    QVERIFY(_vna->channel(2).isManualSweep());
    QVERIFY(_vna->channel(3).isManualSweep());
    QVERIFY(_vna->channel(4).isManualSweep());
    pauseSweeps.reset();
    QVERIFY(_vna->channel(1).isContinuousSweep());
    QVERIFY(_vna->channel(2).isContinuousSweep());
    QVERIFY(_vna->channel(3).isContinuousSweep());
    QVERIFY(_vna->channel(4).isContinuousSweep());
    QVERIFY(!_vna->isError());
}
void VnaPauseSweepsTest::manyManualChannels() {
    if (!_vna->isChannel(1))
        _vna->createChannel(1);
    _vna->createChannel(2);
    _vna->createChannel(3);
    _vna->createChannel(4);

    _vna->channel(1).manualSweepOn();
    _vna->channel(2).manualSweepOn();
    _vna->channel(3).manualSweepOn();
    _vna->channel(4).manualSweepOn();

    QScopedPointer<VnaPauseSweeps> pauseSweeps(new VnaPauseSweeps(_vna.data()));
    QVERIFY(_vna->channel(1).isManualSweep());
    QVERIFY(_vna->channel(2).isManualSweep());
    QVERIFY(_vna->channel(3).isManualSweep());
    QVERIFY(_vna->channel(4).isManualSweep());
    pauseSweeps.reset();
    QVERIFY(_vna->channel(1).isManualSweep());
    QVERIFY(_vna->channel(2).isManualSweep());
    QVERIFY(_vna->channel(3).isManualSweep());
    QVERIFY(_vna->channel(4).isManualSweep());
    QVERIFY(!_vna->isError());
}
void VnaPauseSweepsTest::mixedChannels() {
    if (_vna->properties().isZvaFamily()) {
        qDebug() << "ZVA doesn\'t support mixed manual sweep mode";
        return;
    }

    if (!_vna->isChannel(1))
        _vna->createChannel(1);
    _vna->createChannel(2);
    _vna->createChannel(3);
    _vna->createChannel(4);

    _vna->channel(1).manualSweepOn();
    _vna->channel(2).continuousSweepOn();
    _vna->channel(3).manualSweepOn();
    _vna->channel(4).continuousSweepOn();

    QScopedPointer<VnaPauseSweeps> pauseSweeps(new VnaPauseSweeps(_vna.data()));
    QVERIFY(_vna->channel(1).isManualSweep());
    QVERIFY(_vna->channel(2).isManualSweep());
    QVERIFY(_vna->channel(3).isManualSweep());
    QVERIFY(_vna->channel(4).isManualSweep());
    pauseSweeps.reset();
    QVERIFY(_vna->channel(1).isManualSweep());
    QVERIFY(_vna->channel(2).isContinuousSweep());
    QVERIFY(_vna->channel(3).isManualSweep());
    QVERIFY(_vna->channel(4).isContinuousSweep());
    QVERIFY(!_vna->isError());
}
void VnaPauseSweepsTest::deletedChannels() {
    if (_vna->properties().isZvaFamily()) {
        qDebug() << "ZVA doesn\'t support mixed manual sweep mode";
        return;
    }

    if (!_vna->isChannel(1))
        _vna->createChannel(1);
    _vna->createChannel(2);
    _vna->createChannel(3);
    _vna->createChannel(4);

    _vna->channel(1).manualSweepOn();
    _vna->channel(2).continuousSweepOn();
    _vna->channel(3).continuousSweepOn();
    _vna->channel(4).manualSweepOn();

    QScopedPointer<VnaPauseSweeps> pauseSweeps(new VnaPauseSweeps(_vna.data()));
    QVERIFY(_vna->channel(1).isManualSweep());
    QVERIFY(_vna->channel(2).isManualSweep());
    QVERIFY(_vna->channel(3).isManualSweep());
    QVERIFY(_vna->channel(4).isManualSweep());

    _vna->createChannel(5);
    _vna->channel(5).continuousSweepOn();

    _vna->deleteChannel(1);
    _vna->deleteChannel(3);
    pauseSweeps.reset();

    QVERIFY(_vna->channel(2).isContinuousSweep());
    QVERIFY(_vna->channel(4).isManualSweep());
    QVERIFY(_vna->channel(5).isContinuousSweep());
    QVERIFY(!_vna->isError());
}
void VnaPauseSweepsTest::noPauseInConstructor() {
    if (!_vna->isChannel(1))
        _vna->createChannel(1);
    _vna->createChannel(2);
    _vna->createChannel(3);
    _vna->createChannel(4);

    _vna->channel(1).continuousSweepOn();
    _vna->channel(2).continuousSweepOn();
    _vna->channel(3).continuousSweepOn();
    _vna->channel(4).continuousSweepOn();

    QScopedPointer<VnaPauseSweeps> pauseSweeps(new VnaPauseSweeps(_vna.data(), false));
    QVERIFY(_vna->channel(1).isContinuousSweep());
    QVERIFY(_vna->channel(2).isContinuousSweep());
    QVERIFY(_vna->channel(3).isContinuousSweep());
    QVERIFY(_vna->channel(4).isContinuousSweep());
    pauseSweeps.reset();
    QVERIFY(_vna->channel(1).isContinuousSweep());
    QVERIFY(_vna->channel(2).isContinuousSweep());
    QVERIFY(_vna->channel(3).isContinuousSweep());
    QVERIFY(_vna->channel(4).isContinuousSweep());
    QVERIFY(!_vna->isError());
}
void VnaPauseSweepsTest::noRestoreInConstructor() {
    if (!_vna->isChannel(1))
        _vna->createChannel(1);
    _vna->createChannel(2);
    _vna->createChannel(3);
    _vna->createChannel(4);

    _vna->channel(1).continuousSweepOn();
    _vna->channel(2).continuousSweepOn();
    _vna->channel(3).continuousSweepOn();
    _vna->channel(4).continuousSweepOn();

    QScopedPointer<VnaPauseSweeps> pauseSweeps(new VnaPauseSweeps(_vna.data(), true, false));
    QVERIFY(_vna->channel(1).isManualSweep());
    QVERIFY(_vna->channel(2).isManualSweep());
    QVERIFY(_vna->channel(3).isManualSweep());
    QVERIFY(_vna->channel(4).isManualSweep());
    pauseSweeps.reset();
    QVERIFY(_vna->channel(1).isManualSweep());
    QVERIFY(_vna->channel(2).isManualSweep());
    QVERIFY(_vna->channel(3).isManualSweep());
    QVERIFY(_vna->channel(4).isManualSweep());
    QVERIFY(!_vna->isError());
}
void VnaPauseSweepsTest::manualOperation() {
    if (!_vna->isChannel(1))
        _vna->createChannel(1);
    _vna->createChannel(2);
    _vna->createChannel(3);
    _vna->createChannel(4);

    _vna->channel(1).continuousSweepOn();
    _vna->channel(2).continuousSweepOn();
    _vna->channel(3).continuousSweepOn();
    _vna->channel(4).continuousSweepOn();

    QScopedPointer<VnaPauseSweeps> pauseSweeps(new VnaPauseSweeps(_vna.data(), false, false));
    QVERIFY(_vna->channel(1).isContinuousSweep());
    QVERIFY(_vna->channel(2).isContinuousSweep());
    QVERIFY(_vna->channel(3).isContinuousSweep());
    QVERIFY(_vna->channel(4).isContinuousSweep());

    pauseSweeps->pause();
    QVERIFY(_vna->channel(1).isManualSweep());
    QVERIFY(_vna->channel(2).isManualSweep());
    QVERIFY(_vna->channel(3).isManualSweep());
    QVERIFY(_vna->channel(4).isManualSweep());

    pauseSweeps->resume();
    QVERIFY(_vna->channel(1).isContinuousSweep());
    QVERIFY(_vna->channel(2).isContinuousSweep());
    QVERIFY(_vna->channel(3).isContinuousSweep());
    QVERIFY(_vna->channel(4).isContinuousSweep());

    pauseSweeps->pause();
    QVERIFY(_vna->channel(1).isManualSweep());
    QVERIFY(_vna->channel(2).isManualSweep());
    QVERIFY(_vna->channel(3).isManualSweep());
    QVERIFY(_vna->channel(4).isManualSweep());

    pauseSweeps->resumeOnDestruction();
    pauseSweeps.reset();
    QVERIFY(_vna->channel(1).isContinuousSweep());
    QVERIFY(_vna->channel(2).isContinuousSweep());
    QVERIFY(_vna->channel(3).isContinuousSweep());
    QVERIFY(_vna->channel(4).isContinuousSweep());
    QVERIFY(!_vna->isError());
}
