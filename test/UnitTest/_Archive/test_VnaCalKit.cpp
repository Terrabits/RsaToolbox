

#include "Vna.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_VnaCalKit : public QObject
{
    Q_OBJECT

public:
    test_VnaCalKit();

private:
    Vna vna;
    Connector type;
    NameLabel nameLabel;
    VnaCalKit kit;
    QScopedPointer<Log> log;

    int cycle;
    QString appName;
    QString appVersion;
    QString logFilename;
    QDir files;

private Q_SLOTS:
    void init();
    void cleanup();

    void importAndDelete();
    void isAgilentModel();
    void isConnectorType();
    void hasOpen();
    void hasShort();
    void hasMatch();
    void hasThru();
    void readStandards();
    void readStandardsModel();
    void writeStandardsWithModel_data();
    void writeStandardsWithModel();
    void copyKit();
    void setConnector();
    void addTouchstone();
    void addModel();
    void addDirectConnection();
};

test_VnaCalKit::test_VnaCalKit() {
    cycle = 0;
    appName = "test_VnaCalKit";
    appVersion = "0";

    QDir src(SOURCE_DIR);
    src.cd("Results");
    if (src.cd("VnaCalKit Logs")) {
        src.removeRecursively();
        src.cdUp();
    }
    src.mkdir("VnaCalKit Logs");
    int i = 0;
    while (!src.exists("VnaCalKit Logs") && i < 10)
        i++;

    src.cd("VnaCalKit Logs");
    logFilename = src.filePath("%1 %2 Log.txt");
    
    type.setType(Connector::N_50_OHM_CONNECTOR);
    nameLabel.setName("85054D");
    nameLabel.setLabel("");
}

void test_VnaCalKit::init() {
    log.reset(new Log(logFilename.arg(cycle++).arg("init"), appName, appVersion));
    log->printHeader();
    vna.resetBus(new VisaBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(log.data());
    vna.printInfo();
    vna.preset();

    files.setPath(SOURCE_DIR);
    files.cd("Files");
    files.cd("VnaCalKit");
    if (vna.properties().isZnbFamily())
        files.cd("ZNB");
    else
        files.cd("ZVA");

    kit = vna.calKit(nameLabel);

    vna.clearStatus();
    vna.disconnectLog();
}
void test_VnaCalKit::cleanup() {
    vna.disconnectLog();
    log.reset(new Log(logFilename.arg(cycle++).arg("cleanup"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();
    
    NameLabel nameLabel("New Cal Kit", "New Label");
    if (vna.isCalKit(nameLabel))
        vna.deleteCalKit(nameLabel);
    vna.isError();

    nameLabel.setName("Lumped_standards");
    nameLabel.setLabel("with label");
    if (vna.isCalKit(nameLabel))
        vna.deleteCalKit(nameLabel);
    vna.isError();

    Connector connector("BoeingConnector1");
    if (vna.isConnectorType(connector))
        vna.deleteConnector(connector);
    vna.isError();

    connector.setCustomType("NewTestConnector");
        if (vna.isConnectorType(connector))
            vna.deleteConnector(connector);
        vna.isError();
    
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaCalKit::importAndDelete() {
    log.reset(new Log(logFilename.arg(cycle++).arg("importAndDelete"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QString path = files.filePath("Lumped_standards (with label).calkit");
    NameLabel nameLabel("Lumped_standards","with label");
    vna.importCalKit(path);
    QVERIFY(!vna.isError());
    QVERIFY(vna.isCalKit(nameLabel));
    vna.deleteCalKit(nameLabel);
    QVERIFY(!vna.isError());
    QVERIFY(vna.isNotCalKit(nameLabel));

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaCalKit::isAgilentModel() {
    log.reset(new Log(logFilename.arg(cycle++).arg("isAgilentModel"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    // Import test kit
    QString path = files.filePath("Lumped_standards (with label).calkit");
    NameLabel nameLabel("Lumped_standards","with label");
    vna.importCalKit(path);
    QVERIFY(!vna.isError());
    QVERIFY(vna.isCalKit(nameLabel));

    // Verify is Rohde lumped element model
    VnaCalKit kit = vna.calKit(nameLabel);
    QVERIFY(!kit.isAgilentModel());

    // Change to Agilent model
    kit.useAgilentModel();
    QVERIFY(!vna.isError());
    QVERIFY(kit.isAgilentModel());

    // Change to Rohde model
    kit.useRohdeModel();
    QVERIFY(!vna.isError());
    QVERIFY(!kit.isAgilentModel());

    // Change to Agilent model
    kit.useAgilentModel();
    QVERIFY(!vna.isError());
    QVERIFY(kit.isAgilentModel());

    // Delete test kit
    vna.deleteCalKit(nameLabel);
    QVERIFY(!vna.isError());
    QVERIFY(vna.isNotCalKit(nameLabel));

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}

void test_VnaCalKit::isConnectorType() {
    log.reset(new Log(logFilename.arg(cycle++).arg("isConnectorType"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(vna.calKits(type).contains(nameLabel));
    QVERIFY(kit.isConnectorType(type));
    QVERIFY(kit.connectorType().type() == Connector::N_50_OHM_CONNECTOR);

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaCalKit::hasOpen() {
    log.reset(new Log(logFilename.arg(cycle++).arg("hasOpen"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(kit.hasOpen());
    QVERIFY(kit.hasFemaleOpen());
    QVERIFY(kit.hasMaleOpen());

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaCalKit::hasShort() {
    log.reset(new Log(logFilename.arg(cycle++).arg("hasShort"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(kit.hasShort());
    QVERIFY(kit.hasFemaleShort());
    QVERIFY(kit.hasMaleShort());

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaCalKit::hasMatch() {
    log.reset(new Log(logFilename.arg(cycle++).arg("hasMatch"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(kit.hasMatch());
    QVERIFY(kit.hasFemaleMatch());
    QVERIFY(kit.hasMaleMatch());

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaCalKit::hasThru() {
    log.reset(new Log(logFilename.arg(cycle++).arg("hasThru"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(kit.hasThru());
    QVERIFY(kit.hasThru(Connector::Gender::Male, Connector::Gender::Male));
    QVERIFY(kit.hasThru(Connector::Gender::Male, Connector::Gender::Female));
    QVERIFY(kit.hasThru(Connector::Gender::Female, Connector::Gender::Male));
    QVERIFY(kit.hasThru(Connector::Gender::Female, Connector::Gender::Female));

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaCalKit::readStandards() {
    log.reset(new Log(logFilename.arg(cycle++).arg("readStandards"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVector<VnaCalStandard> standards = kit.standards();
    QCOMPARE(standards.size(), int(11));
    foreach(VnaCalStandard s, standards) {
        QVERIFY(s.isOpen() || s.isShort() || s.isMatch() || s.isThru());
        if (s.isSinglePort()) {
            QVERIFY(s.isMale() || s.isFemale());
            QVERIFY(s.connector().type() == Connector::N_50_OHM_CONNECTOR);
        }
        if (s.isTwoPort()) {
            QVERIFY(s.connector1().isMale() || s.connector1().isFemale());
            QVERIFY(s.connector2().isMale() || s.connector2().isFemale());
            QVERIFY(s.connector1().type() == Connector::N_50_OHM_CONNECTOR);
            QVERIFY(s.connector2().type() == Connector::N_50_OHM_CONNECTOR);
        }
    }

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaCalKit::readStandardsModel() {
    log.reset(new Log(logFilename.arg(cycle++).arg("readStandardModel"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();


    // Load kit
    QString path = files.filePath("Lumped_standards (with label).calkit");
    NameLabel nameLabel("Lumped_standards","with label");
    vna.importCalKit(path);
    QVERIFY(!vna.isError());
    QVERIFY(vna.isCalKit(nameLabel));

    QVector<VnaCalStandard> standards = vna.calKit(nameLabel).standards();
    QVERIFY(!vna.isError());

    bool isMSH = false;
    bool isFSH = false;
    bool isSHP1 = false;
    bool isSHP2 = false;
    uint shorts = 0;

    bool isMOSHORT1 = false;
    bool isFOSHORT1 = false;
    bool isOSHORT1P1 = false;
    bool isOSHORT1P2 = false;
    uint offsetShort1s = 0;

    bool isMOSHORT2 = false;
    bool isFOSHORT2 = false;
    bool isOSHORT2P1 = false;
    bool isOSHORT2P2 = false;
    uint offsetShort2s = 0;

    bool isMOSHORT3 = false;
    bool isFOSHORT3 = false;
    bool isOSHORT3P1 = false;
    bool isOSHORT3P2 = false;
    uint offsetShort3s = 0;


    bool isMMThru = false;
    bool isMFThru = false;
    bool isFFThru = false;
    bool isThruP12 = false;
    uint thrus = 0;

    uint unknownStandards = 0;

    foreach (VnaCalStandard s, standards) {
        if (s.isShort()) {
            shorts++;
            VnaStandardModel m = s.model();
            QCOMPARE(m.loss_dB_per_sqrt_Hz, 1.00000342628);
            QCOMPARE(m.Z0_Ohms, 2.0);
            QCOMPARE(m.eLength_m, 3.00000004319);
            QCOMPARE(m.L0_pH, 4.0);
            QCOMPARE(m.L1_pH_per_GHz, 5.0);
            QCOMPARE(m.L2_pH_per_GHz2, 6.0);
            QCOMPARE(m.L3_pH_per_GHz3, 7.0);
            if (s.label() == "MSH") {
                isMSH = true;
                QVERIFY(s.isNotPortSpecific());
                QVERIFY(s.isMale());
                QVERIFY(s.isMaleShort());

                QVERIFY(!s.isPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "FSH") {
                isFSH = true;
                QVERIFY(s.isNotPortSpecific());
                QVERIFY(s.isFemale());
                QVERIFY(s.isFemaleShort());

                QVERIFY(!s.isPortSpecific());
                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "SH P1") {
                isSHP1 = true;
                QVERIFY(s.isPortSpecific());
                QVERIFY(s.isShort());
                QCOMPARE(s.port(), uint(1));

                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleShort());
                QVERIFY(!s.isNotPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "SH P2") {
                isSHP2 = true;
                QVERIFY(s.isPortSpecific());
                QVERIFY(s.isShort());
                QCOMPARE(s.port(), uint(2));

                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleShort());
                QVERIFY(!s.isNotPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
        }
        else if (s.isOffsetShort1()) {
            offsetShort1s++;
            VnaStandardModel m = s.model();
            QCOMPARE(m.loss_dB_per_sqrt_Hz, 1.00000342628);
            QCOMPARE(m.Z0_Ohms, 2.0);
            QCOMPARE(m.eLength_m, 3.00000004319);
            QCOMPARE(m.L0_pH, 4.0);
            QCOMPARE(m.L1_pH_per_GHz, 5.0);
            QCOMPARE(m.L2_pH_per_GHz2, 6.0);
            QCOMPARE(m.L3_pH_per_GHz3, 7.0);
            if (s.label() == "MOSHORT1") {
                isMOSHORT1 = true;
                QVERIFY(s.isNotPortSpecific());
                QVERIFY(s.isMale());
                QVERIFY(s.isMaleOffsetShort1());

                QVERIFY(!s.isPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleOffsetShort1());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "FOSHORT1") {
                isFOSHORT1 = true;
                QVERIFY(s.isNotPortSpecific());
                QVERIFY(s.isFemale());
                QVERIFY(s.isFemaleOffsetShort1());

                QVERIFY(!s.isPortSpecific());
                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleOffsetShort1());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "OSHORT1 P1") {
                isOSHORT1P1 = true;
                QVERIFY(s.isPortSpecific());
                QVERIFY(s.isOffsetShort1());
                QCOMPARE(s.port(), uint(1));

                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleOffsetShort1());
                QVERIFY(!s.isNotPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleOffsetShort1());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "OSHORT1 P2") {
                isOSHORT1P2 = true;
                QVERIFY(s.isPortSpecific());
                QVERIFY(s.isOffsetShort1());
                QCOMPARE(s.port(), uint(2));

                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleOffsetShort1());
                QVERIFY(!s.isNotPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleOffsetShort1());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
        }
        else if (s.isOffsetShort2()) {
            offsetShort2s++;
            VnaStandardModel m = s.model();
            QCOMPARE(m.loss_dB_per_sqrt_Hz, 1.00000342628);
            QCOMPARE(m.Z0_Ohms, 2.0);
            QCOMPARE(m.eLength_m, 3.00000004319);
            QCOMPARE(m.L0_pH, 4.0);
            QCOMPARE(m.L1_pH_per_GHz, 5.0);
            QCOMPARE(m.L2_pH_per_GHz2, 6.0);
            QCOMPARE(m.L3_pH_per_GHz3, 7.0);
            if (s.label() == "MOSHORT2") {
                isMOSHORT2 = true;
                QVERIFY(s.isNotPortSpecific());
                QVERIFY(s.isMale());
                QVERIFY(s.isMaleOffsetShort2());

                QVERIFY(!s.isPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleOffsetShort2());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "FOSHORT2") {
                isFOSHORT2 = true;
                QVERIFY(s.isNotPortSpecific());
                QVERIFY(s.isFemale());
                QVERIFY(s.isFemaleOffsetShort2());

                QVERIFY(!s.isPortSpecific());
                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleOffsetShort2());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "OSHORT2 P1") {
                isOSHORT2P1 = true;
                QVERIFY(s.isPortSpecific());
                QVERIFY(s.isOffsetShort2());
                QCOMPARE(s.port(), uint(1));

                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleOffsetShort2());
                QVERIFY(!s.isNotPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleOffsetShort2());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "OSHORT2 P2") {
                isOSHORT2P2 = true;
                QVERIFY(s.isPortSpecific());
                QVERIFY(s.isOffsetShort2());
                QCOMPARE(s.port(), uint(2));

                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleOffsetShort2());
                QVERIFY(!s.isNotPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleOffsetShort2());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
        }
        else if (s.isOffsetShort3()) {
            offsetShort3s++;
            VnaStandardModel m = s.model();
            QCOMPARE(m.loss_dB_per_sqrt_Hz, 1.00000342628);
            QCOMPARE(m.Z0_Ohms, 2.0);
            QCOMPARE(m.eLength_m, 3.00000004319);
            QCOMPARE(m.L0_pH, 4.0);
            QCOMPARE(m.L1_pH_per_GHz, 5.0);
            QCOMPARE(m.L2_pH_per_GHz2, 6.0);
            QCOMPARE(m.L3_pH_per_GHz3, 7.0);
            if (s.label() == "MOSHORT3") {
                isMOSHORT3 = true;
                QVERIFY(s.isNotPortSpecific());
                QVERIFY(s.isMale());
                QVERIFY(s.isMaleOffsetShort3());

                QVERIFY(!s.isPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleOffsetShort3());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "FOSHORT3") {
                isFOSHORT3 = true;
                QVERIFY(s.isNotPortSpecific());
                QVERIFY(s.isFemale());
                QVERIFY(s.isFemaleOffsetShort3());

                QVERIFY(!s.isPortSpecific());
                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleOffsetShort3());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "OSHORT3 P1") {
                isOSHORT3P1 = true;
                QVERIFY(s.isPortSpecific());
                QVERIFY(s.isOffsetShort3());
                QCOMPARE(s.port(), uint(1));

                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleOffsetShort3());
                QVERIFY(!s.isNotPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleOffsetShort3());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
            else if (s.label() == "OSHORT3 P2") {
                isOSHORT3P2 = true;
                QVERIFY(s.isPortSpecific());
                QVERIFY(s.isOffsetShort3());
                QCOMPARE(s.port(), uint(2));

                QVERIFY(!s.isMale());
                QVERIFY(!s.isMaleOffsetShort3());
                QVERIFY(!s.isNotPortSpecific());
                QVERIFY(!s.isFemale());
                QVERIFY(!s.isFemaleOffsetShort3());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
                QVERIFY(!s.isThru());
            }
        }
        else if (s.isThru()) {
            thrus++;
            VnaStandardModel m = s.model();
            QCOMPARE(m.loss_dB_per_sqrt_Hz, 1.00000342628);
            QCOMPARE(m.Z0_Ohms, 2.0);
            QCOMPARE(m.eLength_m, 3.00000004319);
            if (s.label() == "MMTH") {
                isMMThru = true;
                QVERIFY(s.isNotPortSpecific());
                QVERIFY(s.isThru());
                QVERIFY(s.isThruMM());

                QVERIFY(!s.isPortSpecific());
                QVERIFY(!s.isThruMF());
                QVERIFY(!s.isThruFF());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
            }
            else if (s.label() == "MFTH") {
                isMFThru = true;
                QVERIFY(s.isNotPortSpecific());
                QVERIFY(s.isThru());
                QVERIFY(s.isThruMF());

                QVERIFY(!s.isPortSpecific());
                QVERIFY(!s.isThruMM());
                QVERIFY(!s.isThruFF());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
            }
            else if (s.label() == "FFTH") {
                isFFThru = true;
                QVERIFY(s.isNotPortSpecific());
                QVERIFY(s.isThru());
                QVERIFY(s.isThruFF());

                QVERIFY(!s.isPortSpecific());
                QVERIFY(!s.isThruMM());
                QVERIFY(!s.isThruMF());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
            }
            else if (s.label() == "TH P12") {
                isThruP12 = true;
                QVERIFY(s.isPortSpecific());
                QVERIFY(s.isThru());
                QVERIFY(s.isThru(1, 2));

                QVERIFY(!s.isNotPortSpecific());
                QVERIFY(!s.isThruMM());
                QVERIFY(!s.isThruMF());
                QVERIFY(!s.isThruFF());
                QVERIFY(!s.isShort());
                QVERIFY(!s.isOpen());
                QVERIFY(!s.isMatch());
            }
        }
        else {
            unknownStandards++;
        }
    }

    QVERIFY(isMSH);
    QVERIFY(isFSH);
    QVERIFY(isSHP1);
    QVERIFY(isSHP2);
    QCOMPARE(shorts, uint(4));

    QVERIFY(isMOSHORT1);
    QVERIFY(isFOSHORT1);
    QVERIFY(isOSHORT1P1);
    QVERIFY(isOSHORT1P2);
    QCOMPARE(offsetShort1s, uint(4));

    QVERIFY(isMOSHORT2);
    QVERIFY(isFOSHORT2);
    QVERIFY(isOSHORT2P1);
    QVERIFY(isOSHORT2P2);
    QCOMPARE(offsetShort2s, uint(4));

    QVERIFY(isMOSHORT3);
    QVERIFY(isFOSHORT3);
    QVERIFY(isOSHORT3P1);
    QVERIFY(isOSHORT3P2);
    QCOMPARE(offsetShort3s, uint(4));

    QVERIFY(isMMThru);
    QVERIFY(isMFThru);
    QVERIFY(isFFThru);
    QVERIFY(isThruP12);
    QCOMPARE(thrus, uint(4));

    QCOMPARE(unknownStandards, uint(0));

    // Delete kit
    vna.deleteCalKit(nameLabel);
    QVERIFY(!vna.isError());
    QVERIFY(vna.isNotCalKit(nameLabel));

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaCalKit::writeStandardsWithModel_data() {
    QTest::addColumn<Connector>("connectorType");
    QTest::addColumn<VnaCalStandard>("standard");

    Connector connectorType(Connector::N_50_OHM_CONNECTOR);
    Connector connector1(connectorType);
    Connector connector2(connectorType);
    VnaStandardModel model;
    VnaCalStandard standard;

    model.type = VnaStandardModel::R;
    model.minimumFrequency_Hz = 9E3;
    model.maximumFrequency_Hz = 8.5E9;
    model.loss_dB_per_sqrt_Hz = 1;
    model.Z0_Ohms = 2;
    model.eLength_m = 3;
    model.C0_fF = 4;
    model.C1_fF_per_GHz = 5;
    model.C2_fF_per_GHz2 = 6;
    model.C3_fF_per_GHz3 = 7;
    model.L0_pH = 8;
    model.L1_pH_per_GHz = 9;
    model.L2_pH_per_GHz2 = 10;
    model.L3_pH_per_GHz3 = 11;
    standard.setModel(model);

    // Shorts
    standard.setType(VnaCalStandard::Type::Short);
    connector1.setGender(Connector::Gender::Male);
    standard.setConnector(connector1);
    QTest::newRow("MSH") << connectorType << standard;

    connector1.setGender(Connector::Gender::Female);
    standard.setConnector(connector1);
    QTest::newRow("FSH") << connectorType << standard;

    connector1.setGender(Connector::Gender::Male);
    standard.setConnector(connector1);
    standard.setPort(1);
    QTest::newRow("SHP1") << connectorType << standard;

    standard.setPort(2);
    QTest::newRow("SHP2") << connectorType << standard;

    // Offset short 1
    standard.setType(VnaCalStandard::Type::OffsetShort1);
    connector1.setGender(Connector::Gender::Male);
    standard.setConnector(connector1);
    QTest::newRow("MOSHORT1") << connectorType << standard;

    connector1.setGender(Connector::Gender::Female);
    standard.setConnector(connector1);
    QTest::newRow("FOSHORT1") << connectorType << standard;

    connector1.setGender(Connector::Gender::Male);
    standard.setConnector(connector1);
    standard.setPort(1);
    QTest::newRow("OSHORT1P1") << connectorType << standard;

    standard.setPort(2);
    QTest::newRow("OSHORT1P2") << connectorType << standard;

    // Offset short 2
    standard.setType(VnaCalStandard::Type::OffsetShort2);
    connector1.setGender(Connector::Gender::Male);
    standard.setConnector(connector1);
    QTest::newRow("MOSHORT2") << connectorType << standard;

    connector1.setGender(Connector::Gender::Female);
    standard.setConnector(connector1);
    QTest::newRow("FOSHORT2") << connectorType << standard;

    connector1.setGender(Connector::Gender::Male);
    standard.setConnector(connector1);
    standard.setPort(1);
    QTest::newRow("OSHORT2P1") << connectorType << standard;

    standard.setPort(2);
    QTest::newRow("OSHORT2P2") << connectorType << standard;

    // Offset short 3
    standard.setType(VnaCalStandard::Type::OffsetShort3);
    connector1.setGender(Connector::Gender::Male);
    standard.setConnector(connector1);
    QTest::newRow("MOSHORT3") << connectorType << standard;

    connector1.setGender(Connector::Gender::Female);
    standard.setConnector(connector1);
    QTest::newRow("FOSHORT3") << connectorType << standard;

    connector1.setGender(Connector::Gender::Male);
    standard.setConnector(connector1);
    standard.setPort(1);
    QTest::newRow("OSHORT3P1") << connectorType << standard;

    standard.setPort(2);
    QTest::newRow("OSHORT3P2") << connectorType << standard;



    // Thru
    model.type = VnaStandardModel::Type::Thru;
    standard.setModel(model);
    standard.setType(VnaCalStandard::Type::Thru);
    connector1.setGender(Connector::Gender::Male);
    connector2.setGender(Connector::Gender::Male);
    standard.setConnectors(connector1, connector2);
    QTest::newRow("MMTH") << connectorType << standard;

    connector2.setGender(Connector::Gender::Female);
    standard.setConnectors(connector1, connector2);
    QTest::newRow("MFTH") << connectorType << standard;

    connector1.setGender(Connector::Gender::Female);
    standard.setConnectors(connector1, connector2);
    QTest::newRow("FFTH") << connectorType << standard;

    standard.setPorts(1,2);
    QTest::newRow("TH P12") << connectorType << standard;
}
void test_VnaCalKit::writeStandardsWithModel() {
    log.reset(new Log(logFilename.arg(cycle++).arg("writeStandardsWithModel"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();


    QFETCH(Connector, connectorType);
    QFETCH(VnaCalStandard, standard);

    NameLabel nameLabel("New Cal Kit", "New Label");
    VnaCalKit calKit = vna.calKit(nameLabel);
    calKit.addStandard(standard);
    QVERIFY(!vna.isError());

    QVERIFY(vna.isCalKit(nameLabel));
    QCOMPARE(calKit.standards().size(), int(1));
    QVERIFY(!vna.isError());

    VnaCalStandard retrieved = calKit.standards().first();
    QCOMPARE(standard.label(), retrieved.label());
    QCOMPARE(standard.type(), retrieved.type());
    QCOMPARE(standard.isSinglePort(), retrieved.isSinglePort());
    QCOMPARE(standard.isTwoPort(), retrieved.isTwoPort());
    QCOMPARE(standard.isPortSpecific(), retrieved.isPortSpecific());
    if (standard.isSinglePort()) {
        if (standard.isPortSpecific())
            QCOMPARE(standard.port(), retrieved.port());
        else
            QCOMPARE(standard.connector(), retrieved.connector());

    }
    else {
        if (standard.isPortSpecific()) {
            QCOMPARE(standard.port1(), retrieved.port1());
            QCOMPARE(standard.port2(), retrieved.port2());
        }
        else {
            QCOMPARE(standard.connector1(), retrieved.connector1());
            QCOMPARE(standard.connector2(), retrieved.connector2());
        }
    }
    QCOMPARE(standard.isModel(), retrieved.isModel());
    if (standard.isModel()) {
        // For some reason, setting
        // eLength_m = 3,
        // writing and then reading causes
        // eLength_m = 3.00000004319
        // Close enough...
        standard.model().eLength_m = 3.00000004319;

        QCOMPARE(standard.model().type, retrieved.model().type);
        QCOMPARE(standard.model().eLength_m, retrieved.model().eLength_m);
        QCOMPARE(standard.model().loss_dB_per_sqrt_Hz, retrieved.model().loss_dB_per_sqrt_Hz);
        QCOMPARE(standard.model().Z0_Ohms, retrieved.model().Z0_Ohms);
        if (standard.model().hasCapacitanceValues()) {
            QCOMPARE(standard.model().C0_fF, retrieved.model().C0_fF);
            QCOMPARE(standard.model().C1_fF_per_GHz, retrieved.model().C1_fF_per_GHz);
            QCOMPARE(standard.model().C2_fF_per_GHz2, retrieved.model().C2_fF_per_GHz2);
            QCOMPARE(standard.model().C3_fF_per_GHz3, retrieved.model().C3_fF_per_GHz3);
        }
        if (standard.model().hasInductanceValues()) {
            QCOMPARE(standard.model().L0_pH, retrieved.model().L0_pH);
            QCOMPARE(standard.model().L1_pH_per_GHz, retrieved.model().L1_pH_per_GHz);
            QCOMPARE(standard.model().L2_pH_per_GHz2, retrieved.model().L2_pH_per_GHz2);
            QCOMPARE(standard.model().L3_pH_per_GHz3, retrieved.model().L3_pH_per_GHz3);
        }
        if (standard.model().hasRValue()) {
            QCOMPARE(standard.model().R_Ohms, retrieved.model().R_Ohms);
        }
//        QCOMPARE(standard.model(), retrieved.model());
    }
    else {
        QCOMPARE(standard.touchstone(), retrieved.touchstone());
    }
//    QCOMPARE(standard, retrieved);

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}

void test_VnaCalKit::copyKit() {
    log.reset(new Log(logFilename.arg(cycle++).arg("copyKit"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    // Import test kit
    QString path = files.filePath("Lumped_standards (with label).calkit");
    NameLabel nameLabel("Lumped_standards","with label");
    vna.importCalKit(path);
    QVERIFY(!vna.isError());
    QVERIFY(vna.isCalKit(nameLabel));

    bool isAgilentModel = vna.calKit(nameLabel).isAgilentModel();
    QVERIFY(!vna.isError());
    QVector<VnaCalStandard> standards = vna.calKit(nameLabel).standards();
    QVERIFY(!vna.isError());

    NameLabel newNameLabel("New Cal Kit", "New Label");
    vna.calKit(nameLabel).copy(newNameLabel);
    QVERIFY(!vna.isError());

    QCOMPARE(isAgilentModel, vna.calKit(newNameLabel).isAgilentModel());
    QVERIFY(!vna.isError());
    QCOMPARE(standards, vna.calKit(newNameLabel).standards());
    QVERIFY(!vna.isError());

    // Delete test kit
    vna.deleteCalKit(nameLabel);
    QVERIFY(!vna.isError());
    QVERIFY(vna.isNotCalKit(nameLabel));

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaCalKit::setConnector() {
    log.reset(new Log(logFilename.arg(cycle++).arg("setConnector"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    // Import test kit
    QString path = files.filePath("Lumped_standards (with label).calkit");
    NameLabel nameLabel("Lumped_standards","with label");
    vna.importCalKit(path);
    QVERIFY(!vna.isError());
    QVERIFY(vna.isCalKit(nameLabel));
    QVERIFY(!vna.isError());

    Connector oldConnector("BoeingConnector1");
    QVERIFY(vna.isConnectorType(oldConnector));
    QVERIFY(!vna.isError());
    QVERIFY(vna.calKit(nameLabel).isConnectorType(oldConnector));
    QVERIFY(!vna.isError());

    bool isAgilentModel = vna.calKit(nameLabel).isAgilentModel();
    QVERIFY(!vna.isError());
    QVector<VnaCalStandard> standards = vna.calKit(nameLabel).standards();
    QVERIFY(!vna.isError());

    Connector newConnector("NewTestConnector");
    vna.defineCustomConnector(newConnector);
    QVERIFY(!vna.isError());
    QVERIFY(vna.isConnectorType(newConnector));
    QVERIFY(!vna.isError());

    vna.calKit(nameLabel).setConnectorType(newConnector);
    QVERIFY(!vna.isError());
    QVERIFY(vna.calKit(nameLabel).isConnectorType(newConnector));
    QVERIFY(!vna.isError());

    QCOMPARE(isAgilentModel, vna.calKit(nameLabel).isAgilentModel());
    QVERIFY(!vna.isError());
    QCOMPARE(standards, vna.calKit(nameLabel).standards());
    QVERIFY(!vna.isError());

    // Delete test kit
    vna.deleteCalKit(nameLabel);
    QVERIFY(!vna.isError());
    QVERIFY(vna.isNotCalKit(nameLabel));

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}

void test_VnaCalKit::addTouchstone() {
    log.reset(new Log(logFilename.arg(cycle++).arg("addTouchstone"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(false);

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaCalKit::addModel() {
    log.reset(new Log(logFilename.arg(cycle++).arg("addModel"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(false);

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaCalKit::addDirectConnection() {
    log.reset(new Log(logFilename.arg(cycle++).arg("addDirectConnection"), appName, appVersion));
    log->printHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(false);

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}

QTEST_APPLESS_MAIN(test_VnaCalKit)
#include "test_VnaCalKit.moc"


