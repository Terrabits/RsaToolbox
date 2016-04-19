#include <QDebug>


#include "Connector.h"
#include "NameLabel.h"
#include "TcpBus.h"
#include "Vna.h"
using namespace RsaToolbox;

#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_Vna : public QObject
{
    Q_OBJECT

public:
    test_Vna();

private:
    Vna vna;

    QScopedPointer<Log> log;

    int cycle;
    bool isZva;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void isError();

    void connectors();
    void calKits();
    void importCalKit();
    void exportCalKit();

    void channels();
    void createChannel();

    void traces();
    void createTrace();

    void diagrams();
    void createDiagram();
};

test_Vna::test_Vna() {
    cycle = 0;
    isZva = false;
    appName = "test_VnaSettings";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/Vna Test Logs";
}

void test_Vna::init() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion));
    log->printApplicationHeader();
    vna.resetBus(new TcpBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(log.data());
    vna.printInfo();
    vna.settings().setEmulationOff();
    QVERIFY(vna.settings().isEmulationOff());
    vna.settings().resetIdString();
    vna.settings().resetOptionsString();
    vna.settings().userPresetOff();
    vna.settings().calibrationPresetOff();
    vna.preset();
    vna.clearStatus();
    vna.disconnectLog();
}
void test_Vna::cleanup() {
    vna.disconnectLog();
    log.reset(new Log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_Vna::isError() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("isError()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    int code;
    QString msg;
    vna.clearStatus();
    vna.write("Even more; junk!\n");
    QVERIFY(vna.nextError(code, msg));
    QVERIFY(code != 0);
    QVERIFY(!msg.isEmpty());

    QVERIFY(vna.nextError(code, msg));
    QVERIFY(code != 0);
    QVERIFY(!msg.isEmpty());
    QVERIFY(!vna.nextError(code, msg));
    QVERIFY(code == 0);
    QVERIFY(msg.isEmpty());

    vna.clearStatus();
    vna.write("JUNK\n");
    QVERIFY(vna.isError());
    vna.clearStatus();
    QVERIFY(!vna.isError());

    QVERIFY(!vna.isError());
    vna.clearStatus();
    vna.disconnectLog();
}
void test_Vna::connectors() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("connectors()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVector<Connector> types = vna.connectorTypes();
    bool hasN50 = false;
    Connector N50(N_50_OHM_CONNECTOR, MALE_GENDER);
    foreach(Connector type, types) {
        hasN50 = hasN50 || type.isType(N50);
    }
    QVERIFY(hasN50);
    QVERIFY(vna.isConnectorType(N50));

    QVERIFY(vna.isError() == false);
        vna.disconnectLog();
}
void test_Vna::calKits() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("calKits()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVector<NameLabel> kits = vna.calKits();
    NameLabel n50Ideal("N 50 Ohm Ideal Kit", "");
    bool hasN50Ideal = false;
    foreach (NameLabel kit, kits) {
        hasN50Ideal = hasN50Ideal || (kit == n50Ideal);
    }
    QVERIFY(hasN50Ideal);
    QVERIFY(vna.isCalKit(n50Ideal));

    QVERIFY(vna.isError() == false);
        vna.disconnectLog();
}
void test_Vna::importCalKit() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("importCalKit()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QString pathName;
    NameLabel calkit;
    if (isZva) {
        calkit = NameLabel("importCalKit","");
        pathName = "C:\\Rohde&Schwarz\\Nwa\\Calibration\\Kits\\importCalKit.calkit";
    }
    else {
        calkit = NameLabel();
        pathName = "";
    }
    QVERIFY(vna.isNotCalKit(calkit));
    vna.importCalKit(pathName);
    QVERIFY(vna.isCalKit(calkit));
    vna.deleteCalKit(calkit);
    QVERIFY(vna.isNotCalKit(calkit));

    QVERIFY(vna.isError() == false);
        vna.disconnectLog();
}
void test_Vna::exportCalKit() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("exportCalKit()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QString pathName;
    NameLabel calkit;
    if (isZva) {
        calkit = NameLabel("exportCalKit","");
        pathName = "C:\\Rohde&Schwarz\\Nwa\\Calibration\\Kits\\exportCalKit.calkit";
    }
    else {
        calkit = NameLabel("","");
        pathName = "";
    }
    QVERIFY(vna.isCalKit(calkit));
    QVERIFY(vna.fileSystem().isNotFile(pathName));
    vna.exportCalKit(calkit, pathName);
    QVERIFY(vna.fileSystem().isFile(pathName));
    vna.fileSystem().deleteFile(pathName);
    QVERIFY(vna.fileSystem().isNotFile(pathName));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_Vna::channels() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("channels()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVector<uint> channels = vna.channels();
    QVERIFY(channels.isEmpty() == false);
    QCOMPARE(channels.first(), uint(1));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_Vna::createChannel() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("createChannel()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    uint myChannel = vna.createChannel();
    QVERIFY(vna.isChannel(myChannel));
    vna.deleteChannel(myChannel);
    QVERIFY(vna.isNotChannel(myChannel));
    vna.createChannel();
    vna.createChannel();
    vna.createChannel();
    vna.deleteChannels();
    QVERIFY(vna.channels().isEmpty());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_Vna::traces() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("traces()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QStringList traces = vna.traces();
    QVERIFY(traces.isEmpty() == false);
    QCOMPARE(traces.first(), QString("Trc1"));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_Vna::createTrace() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("createTrace()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QString myTrace = "myTrace";
    vna.createTrace(myTrace, 1);
    QVERIFY(vna.isTrace(myTrace));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_Vna::diagrams() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("diagrams()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVector<uint> diagrams = vna.diagrams();
    QVERIFY(diagrams.isEmpty() == false);
    QCOMPARE(diagrams.first(), uint(1));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_Vna::createDiagram() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("createDiagrams()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    uint myDiagram = vna.createDiagram();
    QVERIFY(vna.isDiagram(myDiagram));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_Vna)
#include "test_Vna.moc"


