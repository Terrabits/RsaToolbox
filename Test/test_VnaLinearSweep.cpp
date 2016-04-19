

#include "General.h"
#include "VnaLinearSweep.h"
#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>

class test_VnaLinearSweep : public QObject
{
    Q_OBJECT

public:
    test_VnaLinearSweep();

private:
    Vna vna;
    VnaLinearSweep sweep;
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
    void center();
    void span();
    void spacing();
    void power();
    void ifBandwidth();
    void frequencies();
};

test_VnaLinearSweep::test_VnaLinearSweep() {
    cycle = 0;
    appName = "test_VnaLinearSweep";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaLinearSweep Logs";
    
    // Initialize object here
}

void test_VnaLinearSweep::init() {
    Log log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion);
    log.printProgramHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(&log);
    vna.printInfo();
    vna.preset();
    vna.clearStatus();
    vna.createChannel(2);
    QVERIFY(vna.isChannel(2));
    sweep = vna.channel(2).linearSweep();
    vna.disconnectLog();
}
void test_VnaLinearSweep::cleanup() {
    Log log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();
    
    // Specific cleanup
    
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaLinearSweep::points() {
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
void test_VnaLinearSweep::start() {
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
void test_VnaLinearSweep::stop() {
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
void test_VnaLinearSweep::center() {
    Log log(logPath, filename.arg(cycle++).arg("center()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setCenter(4, GIGA_PREFIX);
    QCOMPARE(sweep.center_Hz(), double(4E9));
    sweep.setCenter(4.5E9);
    QCOMPARE(sweep.center_Hz(), double(4.5E9));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaLinearSweep::span() {
    Log log(logPath, filename.arg(cycle++).arg("span()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setSpan(1, GIGA_PREFIX);
    QCOMPARE(sweep.span_Hz(), double(1E9));
    sweep.setSpan(2E9);
    QCOMPARE(sweep.span_Hz(), double(2E9));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaLinearSweep::spacing() {
    Log log(logPath, filename.arg(cycle++).arg("spacing()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    double tolerance = 1E3;
    double start = sweep.start_Hz();
    double stop = sweep.stop_Hz();
    uint points = 401;
    double spacing = (stop - start) / (points - 1);
    sweep.setSpacing(spacing * 1E-6, MEGA_PREFIX);
    QVERIFY(abs(sweep.spacing_Hz() - spacing) < tolerance);

    points = 101;
    spacing = (stop - start) / (points - 1);
    sweep.setSpacing(spacing);
    QVERIFY(abs(sweep.spacing_Hz() - spacing) < tolerance);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaLinearSweep::power() {
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
void test_VnaLinearSweep::ifBandwidth() {
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
void test_VnaLinearSweep::frequencies() {
    Log log(logPath, filename.arg(cycle++).arg("frequencies()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    sweep.setStart(1E9);
    sweep.setStop(8E9);
    sweep.setPoints(8);
    QVector<double> frequencies;
    linearSpacing(frequencies, 1E9, 8E9, 8);
    QCOMPARE(sweep.frequencies_Hz(), frequencies);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaLinearSweep)
#include "test_VnaLinearSweep.moc"


