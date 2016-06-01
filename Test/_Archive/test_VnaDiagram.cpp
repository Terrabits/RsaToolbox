

#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_VnaDiagram : public QObject
{
    Q_OBJECT

public:
    test_VnaDiagram();

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

    void channels();
    void traces();
    void title();
    void autoscale();
    void yAxis();
};

test_VnaDiagram::test_VnaDiagram() {
    cycle = 0;
    appName = "test_VnaDiagram";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaDiagram Logs";
    
    // Initialize object here
}

void test_VnaDiagram::init() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion));
    log->printApplicationHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(log.data());
    vna.printInfo();
    vna.preset();
    vna.clearStatus();
    vna.disconnectLog();
}
void test_VnaDiagram::cleanup() {
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

void test_VnaDiagram::channels() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("channels()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaDiagram::traces() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("traces()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaDiagram::title() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("title()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaDiagram::autoscale() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("autoscale()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaDiagram::yAxis() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("yAxis()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}

QTEST_APPLESS_MAIN(test_VnaDiagram)
#include "test_VnaDiagram.moc"


