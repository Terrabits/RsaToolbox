

#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_VnaSwitchMatrix : public QObject
{
    Q_OBJECT

public:
    test_VnaSwitchMatrix();

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

test_VnaSwitchMatrix::test_VnaSwitchMatrix() {
    cycle = 0;
    appName = "test_VnaSwitchMatrix";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaSwitchMatrix Logs";
    
    // Initialize object here
}

void test_VnaSwitchMatrix::init() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion));
    log->printApplicationHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(log.data());
    vna.printInfo();
    vna.preset();
    vna.clearStatus();
    vna.disconnectLog();
}
void test_VnaSwitchMatrix::cleanup() {
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

void test_VnaSwitchMatrix::function() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("function()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();
    
    // Tests here
    QCOMPARE(QString(), QString("This is not finished!!!"));
    
    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaSwitchMatrix)
#include "test_VnaSwitchMatrix.moc"


