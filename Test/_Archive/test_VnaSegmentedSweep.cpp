

#include "General.h"
#include "VnaSegmentedSweep.h"
#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>

class test_VnaSegmentedSweep : public QObject
{
    Q_OBJECT

public:
    test_VnaSegmentedSweep();

private:
    Vna vna;
    VnaSegmentedSweep sweep;
    Log log;

    int cycle;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    // segment(i)
    void segments();
    void isOn();
    void start();
    void stop();
    void points();

    // sweep:
    void power();
    void ifBandwidth();
    void sweepPoints();
    void frequencies();
    void sweepStart();
    void sweepStop();
};

test_VnaSegmentedSweep::test_VnaSegmentedSweep() {
    cycle = 0;
    appName = "test_VnaSegmentedSweep";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaSegmentedSweep Logs";
    
    // Initialize object here
}

void test_VnaSegmentedSweep::init() {
    Log log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion);
    log.printProgramHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(&log);
    vna.printInfo();
    vna.preset();
    vna.clearStatus();
    vna.createChannel(2);
    QVERIFY(vna.isChannel(2));
    sweep = vna.channel(2).segmentedSweep();
    vna.disconnectLog();
}
void test_VnaSegmentedSweep::cleanup() {
    Log log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();
    
    // Specific cleanup
    
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaSegmentedSweep::segments() {
    Log log(logPath, filename.arg(cycle++).arg("segments()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.removeSegments();
    QCOMPARE(sweep.segments(), uint(0));

    sweep.addSegment();
    sweep.segment(1).setSingleFrequency(1E9);
    sweep.addSegment();
    sweep.segment(2).setSingleFrequency(1E9);
    sweep.addSegment();
    QCOMPARE(sweep.segments(), uint(3));

    sweep.removeSegment(3);
    QCOMPARE(sweep.segments(), uint(2));

    sweep.removeSegments();
    QCOMPARE(sweep.segments(), uint(0));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSegmentedSweep::isOn() {
    Log log(logPath, filename.arg(cycle++).arg("isOn()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();



    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSegmentedSweep::start() {
    Log log(logPath, filename.arg(cycle++).arg("start()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.addSegment();
    QCOMPARE(sweep.segments(), uint(1));
    sweep.segment(1).setStart(1, GIGA_PREFIX);
    QCOMPARE(sweep.segment(1).start_Hz(), double(1E9));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSegmentedSweep::stop() {
    Log log(logPath, filename.arg(cycle++).arg("stop()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.addSegment();
    QCOMPARE(sweep.segments(), uint(1));
    sweep.segment(1).setStop(8, GIGA_PREFIX);
    QCOMPARE(sweep.segment(1).stop_Hz(), double(8E9));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSegmentedSweep::points() {
    Log log(logPath, filename.arg(cycle++).arg("points()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.addSegment();
    QCOMPARE(sweep.segments(), uint(1));
    sweep.segment(1).setPoints(201);
    QCOMPARE(sweep.segment(1).points(), uint(201));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}

void test_VnaSegmentedSweep::power() {
    Log log(logPath, filename.arg(cycle++).arg("power()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setPower(-10);
    QCOMPARE(sweep.power_dBm(), double(-10));
    sweep.setPower(-20);
    QCOMPARE(sweep.power_dBm(), double(-20));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSegmentedSweep::ifBandwidth() {
    Log log(logPath, filename.arg(cycle++).arg("ifBandwidth()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setIfbandwidth(10, KILO_PREFIX);
    QCOMPARE(sweep.ifBandwidth_Hz(), double(10E3));
    sweep.setIfbandwidth(1E3);
    QCOMPARE(sweep.ifBandwidth_Hz(), double(1E3));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSegmentedSweep::frequencies() {
    Log log(logPath, filename.arg(cycle++).arg("frequencies()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.addSegment();
    sweep.segment(1).setStart(1E9);
    sweep.segment(1).setStop(8E9);
    sweep.segment(1).setPoints(8);
    vna.channel(2).setSweepType(SEGMENTED_SWEEP);

    QVector<double> freq;
    freq.append(1E9);
    freq.append(2E9);
    freq.append(3E9);
    freq.append(4E9);
    freq.append(5E9);
    freq.append(6E9);
    freq.append(7E9);
    freq.append(8E9);
    QCOMPARE(sweep.frequencies_Hz(), freq);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSegmentedSweep::sweepStart() {
    Log log(logPath, filename.arg(cycle++).arg("sweepStart()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.addSegment();
    sweep.segment(1).setPoints(1);
    sweep.segment(1).setStart(1, MEGA_PREFIX);
    sweep.segment(1).setStop(1, MEGA_PREFIX);
    sweep.addSegment();
    sweep.segment(2).setStart(1E9);
    sweep.segment(2).setStop(8E9);
    sweep.segment(2).setPoints(101);
    vna.channel(2).setSweepType(SEGMENTED_SWEEP);

    QCOMPARE(sweep.points(), uint(102));
    QCOMPARE(sweep.start_Hz(), 1E6);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSegmentedSweep::sweepStop() {
    Log log(logPath, filename.arg(cycle++).arg("sweepStop()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.addSegment();
    sweep.segment(1).setStart(1E9);
    sweep.segment(1).setStop(2E9);
    sweep.segment(1).setPoints(101);
    sweep.addSegment();
    sweep.segment(2).setSingleFrequency(8, GIGA_PREFIX);
    vna.channel(2).setSweepType(SEGMENTED_SWEEP);

    QCOMPARE(sweep.points(), uint(102));
    QCOMPARE(sweep.stop_Hz(), 8E9);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSegmentedSweep::sweepPoints() {
    Log log(logPath, filename.arg(cycle++).arg("sweepPoints()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.addSegment();
    sweep.segment(1).setStart(1E9);
    sweep.segment(1).setStop(2E9);
    sweep.segment(1).setPoints(101);
    sweep.addSegment();
    sweep.segment(2).setStart(4E9);
    sweep.segment(2).setStop(7E9);
    sweep.segment(2).setPoints(457);
    sweep.addSegment();
    sweep.segment(3).setSingleFrequency(8, GIGA_PREFIX);
    vna.channel(2).setSweepType(SEGMENTED_SWEEP);

    QCOMPARE(sweep.points(), uint(101 + 457 + 1));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaSegmentedSweep)
#include "test_VnaSegmentedSweep.moc"


