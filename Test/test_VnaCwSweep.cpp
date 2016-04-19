

#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>

class test_VnaCwSweep : public QObject
{
    Q_OBJECT

public:
    test_VnaCwSweep();

private:
    Vna vna;
    VnaCwSweep sweep;
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
    void frequency();
    void power();
    void ifBandwidth();
};

test_VnaCwSweep::test_VnaCwSweep() {
    cycle = 0;
    appName = "test_VnaCwSweep";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaCwSweep Logs";
    
    // Initialize object here
}

void test_VnaCwSweep::init() {
    Log log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion);
    log.printProgramHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(&log);
    vna.printInfo();
    vna.preset();
    vna.clearStatus();
    vna.createChannel();
    vna.channel(2).setSweepType(CW_SWEEP);
    sweep = vna.channel(2).cwSweep();
    vna.disconnectLog();
}
void test_VnaCwSweep::cleanup() {
    Log log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();
    
    // Specific cleanup
    
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaCwSweep::points() {
    Log log(logPath, filename.arg(cycle++).arg("points()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();
    
    sweep.setPoints(301);
    QCOMPARE(sweep.points(), uint(301));
    sweep.setPoints(101);
    QCOMPARE(sweep.points(), uint(101));
    
    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCwSweep::frequency() {
    Log log(logPath, filename.arg(cycle++).arg("frequency()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setFrequency(1, GIGA_PREFIX);
    QCOMPARE(sweep.frequency_Hz(), 1E9);
    sweep.setFrequency(3E9);
    QCOMPARE(sweep.frequency_Hz(), 3E9);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCwSweep::power() {
    Log log(logPath, filename.arg(cycle++).arg("power()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setPower(-35);
    QCOMPARE(sweep.power_dBm(), double(-35));
    sweep.setPower(3.1);
    QCOMPARE(sweep.power_dBm(), 3.1);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCwSweep::ifBandwidth() {
    Log log(logPath, filename.arg(cycle++).arg("ifBandwidth()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setIfBandwidth(1);
    QCOMPARE(sweep.ifBandwidth_Hz(), double(1));
    sweep.setIfBandwidth(10, KILO_PREFIX);
    QCOMPARE(sweep.ifBandwidth_Hz(), 10E3);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaCwSweep)
#include "test_VnaCwSweep.moc"


