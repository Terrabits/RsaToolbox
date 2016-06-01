

#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_VnaPowerCalibrate : public QObject
{
    Q_OBJECT

public:
    test_VnaPowerCalibrate();

private:
    Vna vna;
    // Object to test
    QScopedPointer<Log> log;

    int cycle;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void function();
};

test_VnaPowerCalibrate::test_VnaPowerCalibrate() {
    cycle = 0;
    appName = "test_VnaPowerCalibrate";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaPowerCalibrate Logs";
    
    // Initialize object here
}

void test_VnaPowerCalibrate::init() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion));
    log->printApplicationHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(log.data());
    vna.printInfo();
    vna.preset();
    vna.clearStatus();
    vna.disconnectLog();
}
void test_VnaPowerCalibrate::cleanup() {
    vna.disconnectLog();
    log.reset(new Log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();
    
    // Specific cleanup
    
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaPowerCalibrate::function() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("function()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();
    
    // Tests here
    QCOMPARE(QString(), QString("This is not finished yet!!!"));
    
    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaPowerCalibrate)
#include "test_VnaPowerCalibrate.moc"


