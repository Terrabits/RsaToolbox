

#include "General.h"
#include "VnaPowerSweep.h"
#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>

class test_VnaPowerSweep : public QObject
{
    Q_OBJECT

public:
    test_VnaPowerSweep();

private:
    Vna vna;
    VnaPowerSweep sweep;
    Log log;

    int cycle;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void points();
    void start();
    void stop();
    void frequency();
    void ifBandwidth();
};

test_VnaPowerSweep::test_VnaPowerSweep() {
    cycle = 0;
    appName = "test_VnaPowerSweep";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaPowerSweep Logs";
    
    // Initialize object here
}

void test_VnaPowerSweep::init() {
    Log log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion);
    log.printProgramHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(&log);
    vna.printInfo();
    vna.preset();
    vna.clearStatus();
    vna.createChannel(2);
    QVERIFY(vna.isChannel(2));
    vna.channel(2).setSweepType(POWER_SWEEP);
    sweep = vna.channel(2).powerSweep();
    vna.disconnectLog();
}
void test_VnaPowerSweep::cleanup() {
    Log log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();
    
    // Specific cleanup
    
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaPowerSweep::points() {
    Log log(logPath, filename.arg(cycle++).arg("points()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setPoints(1001);
    QCOMPARE(sweep.points(), uint(1001));
    sweep.setPoints(201);
    QCOMPARE(sweep.points(), uint(201));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaPowerSweep::start() {
    Log log(logPath, filename.arg(cycle++).arg("start()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setStart(vna.properties().minimumPower_dBm());
    QCOMPARE(sweep.start_dBm(), vna.properties().minimumPower_dBm());
    sweep.setStart(-10);
    QCOMPARE(sweep.start_dBm(), double(-10));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaPowerSweep::stop() {
    Log log(logPath, filename.arg(cycle++).arg("stop()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setStop(vna.properties().maximumPower_dBm());
    QCOMPARE(sweep.stop_dBm(), vna.properties().maximumPower_dBm());
    sweep.setStop(10);
    QCOMPARE(sweep.stop_dBm(), double(10));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaPowerSweep::frequency() {
    Log log(logPath, filename.arg(cycle++).arg("frequency()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setFrequency(4, GIGA_PREFIX);
    QCOMPARE(sweep.frequency_Hz(), 4E9);
    sweep.setFrequency(1E9);
    QCOMPARE(sweep.frequency_Hz(), 1E9);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaPowerSweep::ifBandwidth() {
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


QTEST_APPLESS_MAIN(test_VnaPowerSweep)
#include "test_VnaPowerSweep.moc"


