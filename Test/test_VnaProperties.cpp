

#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>

class test_VnaProperties : public QObject
{
    Q_OBJECT

public:
    test_VnaProperties();

private:
    Vna vna;
    VnaProperties properties;
    Log log;

    int cycle;
    bool isZva;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void model();
    void serialNumber();
    void firmwareVersion();
    void isFamily();
    void isUnknownModel();
    void physicalPorts();
    void minimumFrequency();
    void maximumFrequency();
    void ifBandwidth();
    void minimumPower();
    void maximumPower();
    void sourceAttenuation();
    void receiverAttenuation();
    void maximumPoints();
};

test_VnaProperties::test_VnaProperties() {
    cycle = 0;
    isZva = true;
    appName = "test_VnaProperties";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaProperties Logs";
    
    properties = VnaProperties(&vna);
}

void test_VnaProperties::init() {
    Log log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion);
    log.printProgramHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(&log);
    vna.preset();
    vna.clearStatus();
    vna.disconnectLog();
}
void test_VnaProperties::cleanup() {
    Log log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    
    // Specific cleanup
    
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaProperties::model() {
    Log log(logPath, filename.arg(cycle++).arg("model()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    if (isZva)
        QCOMPARE(properties.model(), ZVA_MODEL);
    else
        QCOMPARE(properties.model(), ZNB_MODEL);
    QVERIFY(properties.isUnknownModel() == false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::serialNumber() {
    Log log(logPath, filename.arg(cycle++).arg("serialNumber()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    QVERIFY(properties.serialNumber().isEmpty() == false);
    if (isZva)
        QCOMPARE(properties.serialNumber(), QString("1145101099999999"));
    else
        QCOMPARE(properties.serialNumber(), QString("1311601044100104"));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::firmwareVersion() {
    Log log(logPath, filename.arg(cycle++).arg("firmwareVersion()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    QVERIFY(properties.firmwareVersion().isEmpty() == false);
    if (isZva)
        QCOMPARE(properties.firmwareVersion(), QString("3.20.1.17"));
    else
        QCOMPARE(properties.firmwareVersion(), QString("1.93.2.45"));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::isFamily() {
    Log log(logPath, filename.arg(cycle++).arg("isFamily()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    if (isZva) {
        QVERIFY(properties.isZvaFamily());
        QVERIFY(properties.isZnbFamily() == false);
    }
    else {
        QVERIFY(properties.isZnbFamily());
        QVERIFY(properties.isZvaFamily() == false);
    }

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::isUnknownModel() {
    Log log(logPath, filename.arg(cycle++).arg("isUnknownModel()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    QVERIFY(properties.isUnknownModel() == false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::physicalPorts() {
    Log log(logPath, filename.arg(cycle++).arg("physicalPorts()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    if (isZva)
        QCOMPARE(properties.physicalPorts(), uint(4));
    else
        QCOMPARE(properties.physicalPorts(), uint(4));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::minimumFrequency() {
    Log log(logPath, filename.arg(cycle++).arg("minimumFrequency()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    if (isZva)
        QCOMPARE(properties.minimumFrequency_Hz(), double(300E3));
    else
        QCOMPARE(properties.minimumFrequency_Hz(), double(9E3));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::maximumFrequency() {
    Log log(logPath, filename.arg(cycle++).arg("maximumFrequency()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    if (isZva)
        QCOMPARE(properties.maximumFrequency_Hz(), double(8E9));
    else
        QCOMPARE(properties.maximumFrequency_Hz(), double(8.5E9));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::ifBandwidth() {
    Log log(logPath, filename.arg(cycle++).arg("ifBandwidth()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    if (isZva) {
        QCOMPARE(properties.ifBandwidthMantissa_Hz().count(), 18);
        QCOMPARE(properties.ifBandwidthMantissa_KHz().count(), 18);
        QCOMPARE(properties.ifBandwidthMantissa_MHz().count(), 7);
    }
    else {
        QCOMPARE(properties.ifBandwidthMantissa_Hz().count(), 9);
        QCOMPARE(properties.ifBandwidthMantissa_KHz().count(), 9);
        QCOMPARE(properties.ifBandwidthMantissa_MHz().count(), 6);
    }

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::minimumPower() {
    Log log(logPath, filename.arg(cycle++).arg("minimumPower()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    if (isZva)
        QCOMPARE(properties.minimumPower_dBm(), double(-150));
    else
        QCOMPARE(properties.minimumPower_dBm(), double(-40));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::maximumPower() {
    Log log(logPath, filename.arg(cycle++).arg("maximumPower()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    if (isZva)
        QCOMPARE(properties.maximumPower_dBm(), double(100));
    else
        QCOMPARE(properties.maximumPower_dBm(), double(10));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::sourceAttenuation() {
    Log log(logPath, filename.arg(cycle++).arg("sourceAttenuation()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    QVERIFY(properties.hasSourceAttenuators() == false);
    QVERIFY(properties.sourceAttenuations_dB().isEmpty() == false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::receiverAttenuation() {
    Log log(logPath, filename.arg(cycle++).arg("receiverAttenuation()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    QVERIFY(properties.hasReceiverAttenuators());
    QVERIFY(properties.receiverAttenuations_dB().isEmpty() == false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaProperties::maximumPoints() {
    Log log(logPath, filename.arg(cycle++).arg("maximumPoints()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);

    if (isZva)
        QCOMPARE(properties.maximumPoints(), uint(100001));
    else
        QCOMPARE(properties.maximumPoints(), uint(60001));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaProperties)
#include "test_VnaProperties.moc"


