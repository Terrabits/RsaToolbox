

#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_VnaChannel : public QObject
{
    Q_OBJECT

public:
    test_VnaChannel();

private:
    Vna vna;
    VnaChannel channel;
    QScopedPointer<Log> log;

    int cycle;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void channels();
    void indexName();
    void triggerSettings();
    void sweepType();
    void balancedPorts();
    void userDefinedPorts();
};

test_VnaChannel::test_VnaChannel() {
    cycle = 0;
    appName = "test_VnaChannel";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaChannel Logs";
    
    // Initialize object here
}

void test_VnaChannel::init() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion));
    log->printApplicationHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(log.data());
    vna.printInfo();

    // Remove User-defined ports (persistent on ZNB):
    QVector<uint> channels = vna.channels();
    foreach(uint i, channels) {
        vna.channel(i).deleteUserDefinedPorts();
    }
    vna.isError();
    vna.preset();
    vna.clearStatus();

    channel = VnaChannel(&vna, 1);
    vna.disconnectLog();
}
void test_VnaChannel::cleanup() {
    vna.disconnectLog();
    log.reset(new Log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();
    vna.isError();
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaChannel::channels() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("channels()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();
    
    QVector<uint> channels;
    QCOMPARE(vna.numberOfChannels(), uint(1));
    QCOMPARE(vna.channels(), QVector<uint>(1, 1));
    channels = vna.channels();
    channels.append(vna.createChannel());
    QCOMPARE(vna.numberOfChannels(), uint(2));
    QCOMPARE(vna.channels(), channels);
    QVERIFY(vna.isChannel(2));
    QVERIFY(vna.isNotChannel(8));
    vna.createChannel(8);
    channels.append(8);
    QCOMPARE(vna.channels(), channels);
    QVERIFY(vna.isChannel(8));
    vna.deleteChannel(8);
    QVERIFY(vna.isNotChannel(8));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaChannel::indexName() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("indexName()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.createChannel(2);
    channel = VnaChannel(&vna, 2);
    QCOMPARE(channel.name(), QString("Ch2"));
    QCOMPARE(channel.index(), uint(2));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaChannel::sweepType() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("sweepType()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.createChannel(2);
    channel = VnaChannel(&vna, 2);
    QVERIFY(channel.isLinearSweep());
    QCOMPARE(channel.sweepType(), LINEAR_SWEEP);
    channel.setSweepType(POWER_SWEEP);
    QVERIFY(channel.isPowerSweep());
    channel.setSweepType(LOG_SWEEP);
    QVERIFY(channel.isLogarithmicSweep());
    channel.setSweepType(CW_SWEEP);
    QVERIFY(channel.isCwSweep());
    channel.setSweepType(TIME_SWEEP);
    QVERIFY(channel.isTimeSweep());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaChannel::triggerSettings() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("triggerSettings()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.createChannel(2);
    channel = VnaChannel(&vna, 2);
    if (vna.properties().isZvaFamily()) {
        channel.isSweepOn();
        channel.sweepOn();
    }
    else {
        channel.sweepOn();
        QVERIFY(channel.isSweepOn());
        channel.sweepOff();
        QVERIFY(channel.isSweepOff());
        channel.sweepOff(false);
        QVERIFY(channel.isSweepOn());
    }

    QVERIFY(channel.isContinuousSweep());
    channel.manualSweepOn();
    QVERIFY(channel.isManualSweep());
    channel.continuousSweepOn();
    QVERIFY(channel.isContinuousSweep());

    QCOMPARE(channel.numberOfSweeps(), uint(1));
    channel.setNumberOfSweeps(10);
    QCOMPARE(channel.numberOfSweeps(), uint(10));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}

void test_VnaChannel::balancedPorts() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("balancedPorts()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.createChannel(2);
    channel = VnaChannel(&vna, 2);
    QVERIFY(channel.isSingleEndedPort(1));
    QCOMPARE(channel.physicalPort(1), uint(1));
    QVERIFY(channel.isBalancedPort(2) == false);
    QCOMPARE(channel.numberOfLogicalPorts(), vna.testPorts());

    channel.createBalancedPort(1, 1, 2);
    QCOMPARE(channel.numberOfLogicalPorts(), uint(vna.testPorts() - 1));
    QVERIFY(channel.isBalancedPort(1));

    uint port1, port2;
    channel.physicalPorts(1, port1, port2);
    QCOMPARE(port1, uint(1));
    QCOMPARE(port2, uint(2));

    channel.deleteBalancedPort(1);
    QCOMPARE(channel.numberOfLogicalPorts(), vna.testPorts());

    channel.createSingleEndedPort(1, 2);
    QCOMPARE(channel.physicalPort(1), uint(2));
    channel.deleteBalancedPorts();
    QCOMPARE(channel.physicalPort(1), uint(1));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}

void test_VnaChannel::userDefinedPorts() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("userDefinedPorts()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    VnaUserDefinedPort userDefinedPort;

    vna.createChannel(2);
    channel = VnaChannel(&vna, 2);
    QVERIFY(channel.isNotUserDefinedPort(1));
    QVERIFY(channel.isNotUserDefinedPort(2));
    QVERIFY(vna.isError() == false);

    userDefinedPort.setSource(2);
    userDefinedPort.setReference(2, RECEIVER_A);
    userDefinedPort.setMeasure(2, RECEIVER_B);
    channel.setUserDefinedPort(1, userDefinedPort);
    QVERIFY(vna.isError() == false);
    QVERIFY(vna.channel(1).isNotUserDefinedPort(1));
    QVERIFY(channel.isNotUserDefinedPort(1));
    QVERIFY(channel.isUserDefinedPort(2));
    QVERIFY(channel.userDefinedPort(2) == userDefinedPort);

    channel.deleteUserDefinedPorts();
    QVERIFY(channel.isNotUserDefinedPort(2));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaChannel)
#include "test_VnaChannel.moc"


