

#include "General.h"
#include "VnaLogSweep.h"
#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>

class test_VnaLogSweep : public QObject
{
    Q_OBJECT

public:
    test_VnaLogSweep();

private:
    Vna vna;
    VnaLogSweep sweep;
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
    void power();
    void ifBandwidth();
    void frequencies();
};

test_VnaLogSweep::test_VnaLogSweep() {
    cycle = 0;
    appName = "test_VnaLogSweep";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaLogSweep Logs";
    
    // Initialize object here
}

void test_VnaLogSweep::init() {
    Log log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion);
    log.printProgramHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(&log);
    vna.printInfo();
    vna.preset();
    vna.clearStatus();
    vna.createChannel(2);
    QVERIFY(vna.isChannel(2));
    vna.channel(2).setSweepType(LOG_SWEEP);
    sweep = vna.channel(2).logSweep();
    vna.disconnectLog();
}
void test_VnaLogSweep::cleanup() {
    Log log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();
    
    // Specific cleanup
    
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaLogSweep::points() {
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
void test_VnaLogSweep::start() {
    Log log(logPath, filename.arg(cycle++).arg("start()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setStart(1, GIGA_PREFIX);
    QCOMPARE(sweep.start_Hz(), double(1E9));
    sweep.setStart(vna.properties().minimumFrequency_Hz());
    QCOMPARE(sweep.start_Hz(), vna.properties().minimumFrequency_Hz());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaLogSweep::stop() {
    Log log(logPath, filename.arg(cycle++).arg("stop()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setStop(6, GIGA_PREFIX);
    QCOMPARE(sweep.stop_Hz(), double(6E9));
    sweep.setStop(vna.properties().maximumFrequency_Hz());
    QCOMPARE(sweep.stop_Hz(), vna.properties().maximumFrequency_Hz());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaLogSweep::power() {
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
void test_VnaLogSweep::ifBandwidth() {
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
void test_VnaLogSweep::frequencies() {
    Log log(logPath, filename.arg(cycle++).arg("frequencies()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setStart(1E9);
    sweep.setStop(2E9);
    sweep.setPoints(10);

    QVector<double> frequencies = sweep.frequencies_Hz();
    QVector<double> expected;
    logSpacing(expected, 1E9, 2E9, 10);
    double tolerance = 1;
    for (int i = 0; i < 10; i++)
        QVERIFY(abs(frequencies[i] - expected[i]) < tolerance);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaLogSweep)
#include "test_VnaLogSweep.moc"


