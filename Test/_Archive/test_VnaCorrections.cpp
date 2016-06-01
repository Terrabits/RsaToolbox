

#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>

class test_VnaCorrections : public QObject
{
    Q_OBJECT

public:
    test_VnaCorrections();

private:
    Vna vna;
    VnaCorrections corrections;
    Log log;

    int cycle;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void state();
    void calGroups();
    void clear();
};

test_VnaCorrections::test_VnaCorrections() {
    cycle = 0;
    appName = "test_VnaCorrections";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaCorrections Logs";
    
    // Initialize object here
}

void test_VnaCorrections::init() {
    Log log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion);
    log.printProgramHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(&log);
    vna.printInfo();
    vna.preset();
    vna.pause();
    vna.clearStatus();

    vna.createChannel();
    corrections = vna.channel(2).corrections();

    vna.disconnectLog();
}
void test_VnaCorrections::cleanup() {
    Log log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();
    
    // Specific cleanup
    
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaCorrections::state() {
    Log log(logPath, filename.arg(cycle++).arg("state()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();
    
    QVERIFY(corrections.isOff());
    QVERIFY(corrections.isOn() == false);
    QVERIFY(corrections.isPresent() == false);
    QVERIFY(corrections.isNotInterpolated());

    corrections.setCalGroup("Test");
    corrections.on();
    vna.channel(2).manualSweepOn();
    vna.channel(2).startSweep();
    vna.pause();
    vna.channel(2).continuousSweepOn();
    QVERIFY(corrections.isOn());
    QVERIFY(corrections.isOff() == false);
    QVERIFY(corrections.isPresent());
    QVERIFY(corrections.isNotInterpolated());

    vna.channel(2).linearSweep().setPoints(401);
    vna.channel(2).manualSweepOn();
    vna.channel(2).startSweep();
    vna.pause();
    vna.channel(2).continuousSweepOn();
    QVERIFY(corrections.isOn());
    QVERIFY(corrections.isOff() == false);
    QVERIFY(corrections.isPresent());
    QVERIFY(corrections.isInterpolated());

    vna.channel(2).corrections().off();
    vna.channel(2).manualSweepOn();
    vna.channel(2).startSweep();
    vna.pause();
    vna.channel(2).continuousSweepOn();
    QVERIFY(corrections.isOn() == false);
    QVERIFY(corrections.isOff());
    QVERIFY(corrections.isPresent());
    QVERIFY(corrections.isNotInterpolated());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCorrections::calGroups() {
    Log log(logPath, filename.arg(cycle++).arg("calGroups()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    QCOMPARE(corrections.calGroup(), QString());
    corrections.setCalGroup("Test");
    QCOMPARE(corrections.calGroup(), QString("Test.cal"));
    corrections.dissolveCalGroupLink();
    QCOMPARE(corrections.calGroup(), QString());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCorrections::clear() {
    Log log(logPath, filename.arg(cycle++).arg("clear()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    corrections.isOff(); // Create trace, diagram
    vna.channel(2).manualSweepOn();
    corrections.setCalGroup("Test");
    corrections.dissolveCalGroupLink();
    vna.channel(2).startSweep();
    vna.pause();

    vna.channel(2).corrections().clear();
    vna.channel(2).startSweep();
    vna.pause();
    QVERIFY(corrections.isNotPresent());
    vna.channel(2).continuousSweepOn();

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaCorrections)
#include "test_VnaCorrections.moc"
