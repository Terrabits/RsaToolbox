

#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
#include "VnaCalibrate.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_VnaCalibrate : public QObject
{
    Q_OBJECT

public:
    test_VnaCalibrate();

private:
    Vna vna;
    QScopedPointer<Log> log;

    int cycle;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void singleChannelConnector();
    void singleChannelSelectKit();
    void singleChannelKeepRawData();

    void singleChannelOSM();
    void singleChannelUOSM();
    void singleChannelTOSM();

    void allChannelsConnector();
    void allChannelsSelectKit();
    void allChannelsKeepRawData();

    void allChannelsOSM();
    void allChannelsUOSM();
    void allChannelsTOSM();
};

test_VnaCalibrate::test_VnaCalibrate() {
    cycle = 0;
    appName = "test_VnaCalibrate";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaCalibrate Logs";
    
    // Initialize object here
}

void test_VnaCalibrate::init() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion));
    log->printProgramHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(log.data());
    vna.printInfo();
    vna.preset();
    vna.pause();
    vna.clearStatus();
    vna.disconnectLog();
}
void test_VnaCalibrate::cleanup() {
    vna.disconnectLog();
    log.reset(new Log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();
    vna.isError();
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaCalibrate::singleChannelConnector() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("singleChannelConnector()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.createChannel();
    VnaChannel channel = vna.channel(2);
    VnaCalibrate calibrate = vna.channel(2).calibrate();

    vna.connectorTypes();

    calibrate.setConnector(1, Connector(N_50_OHM_CONNECTOR));
    QCOMPARE(calibrate.connector(1), Connector(N_50_OHM_CONNECTOR));
    calibrate.setConnector(1, Connector(mm_3_5_CONNECTOR, FEMALE_GENDER));
    QCOMPARE(calibrate.connector(1), Connector(mm_3_5_CONNECTOR, FEMALE_GENDER));

    uint ports = vna.properties().physicalPorts();
    calibrate.setConnector(ports, Connector(mm_3_5_CONNECTOR, MALE_GENDER));
    QVector<Connector> connectors = calibrate.connectors();
    QCOMPARE(connectors.first(), Connector(mm_3_5_CONNECTOR, FEMALE_GENDER));
    QCOMPARE(connectors.last(), Connector(mm_3_5_CONNECTOR, MALE_GENDER));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCalibrate::singleChannelSelectKit() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("singleChannelSelectKit()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.createChannel();
    VnaChannel channel = vna.channel(2);
    VnaCalibrate calibrate = vna.channel(2).calibrate();

    NameLabel firstKit, secondKit, thirdKit;
    firstKit = NameLabel("3650-1"); // 3.5 mm
    secondKit = NameLabel("3653"); // N50
    thirdKit = NameLabel("85052D"); // 3.5 mm

    calibrate.selectKit(firstKit);
    calibrate.selectKit(secondKit);
    if (vna.properties().isZnbFamily())
        QCOMPARE(calibrate.selectedKit(mm_3_5_CONNECTOR), firstKit);
    else
        QCOMPARE(calibrate.selectedKit(QString("PC 3.5")), firstKit);
    QCOMPARE(calibrate.selectedKit(N_50_OHM_CONNECTOR), secondKit);

    calibrate.selectKit(thirdKit);
    if (vna.properties().isZnbFamily())
        QCOMPARE(calibrate.selectedKit(mm_3_5_CONNECTOR), thirdKit);
    else
        QCOMPARE(calibrate.selectedKit(QString("PC 3.5")), thirdKit);
    QCOMPARE(calibrate.selectedKit(N_50_OHM_CONNECTOR), secondKit);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCalibrate::singleChannelKeepRawData() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("singleChannelKeepRawData()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.createChannel();
    VnaChannel channel = vna.channel(2);
    VnaCalibrate calibrate = vna.channel(2).calibrate();

    calibrate.start("singleChannelKeepRawData", OSM_CAL_TYPE, QVector<uint>(1,1));
    calibrate.keepRawData();
    QVERIFY(calibrate.isRawDataKept());
    calibrate.keepRawData(false);
    QVERIFY(calibrate.isRawDataKept() == false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}

void test_VnaCalibrate::singleChannelOSM() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("singleChannelOSM()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.settings().displayOn();
    vna.createChannel();
    VnaChannel channel = vna.channel(2);
    VnaCalibrate calibrate = vna.channel(2).calibrate();

    QVERIFY(channel.corrections().isNotPresent());
    QVERIFY(vna.channel(1).corrections().isNotPresent());

    QVector<uint> ports;
    QVector<Connector> portTypes;

    NameLabel kit("3.5 mm Ideal Kit");
    ports << 1;
    portTypes << Connector(mm_3_5_CONNECTOR, MALE_GENDER);
    calibrate.selectKit(kit);
    calibrate.setConnector(1, portTypes.first());

    calibrate.start("singleChannelOSM", OSM_CAL_TYPE, ports);
    calibrate.measureOpen(1);
    vna.pause();
    calibrate.measureShort(1);
    vna.pause();
    calibrate.measureMatch(1);
    vna.pause();
    calibrate.apply();
    vna.pause();

    QVERIFY(channel.corrections().isPresent());
    QVERIFY(vna.channel(1).corrections().isNotPresent());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCalibrate::singleChannelUOSM() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("singleChannelUOSM()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.settings().displayOn();
    vna.createChannel();
    VnaChannel channel = vna.channel(2);
    VnaCalibrate calibrate = vna.channel(2).calibrate();

    QVERIFY(channel.corrections().isNotPresent());
    QVERIFY(vna.channel(1).corrections().isNotPresent());

    QVector<uint> ports;
    QVector<Connector> portTypes;

    NameLabel port1Kit("3.5 mm Ideal Kit");
    ports << 1;
    portTypes << Connector(mm_3_5_CONNECTOR, MALE_GENDER);
    calibrate.selectKit(port1Kit);
    calibrate.setConnector(1, portTypes.first());

    NameLabel port2Kit("N 50 Ohm Ideal Kit");
    ports << 2;
    portTypes << Connector(N_50_OHM_CONNECTOR, FEMALE_GENDER);
    calibrate.selectKit(port2Kit);
    calibrate.setConnector(2, portTypes.last());

    calibrate.start("singleChannelUOSM", UOSM_CAL_TYPE, ports);
    calibrate.measureOpen(1);
    vna.pause();
    calibrate.measureShort(1);
    vna.pause();
    calibrate.measureMatch(1);
    vna.pause();
    calibrate.measureOpen(2);
    vna.pause();
    calibrate.measureShort(2);
    vna.pause();
    calibrate.measureMatch(2);
    vna.pause();
    calibrate.measureThru(1, 2);
    vna.pause();
    calibrate.apply();
    vna.pause();

    QVERIFY(channel.corrections().isPresent());
    QVERIFY(vna.channel(1).corrections().isNotPresent());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCalibrate::singleChannelTOSM() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("singleChannelTOSM()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.settings().displayOn();
    vna.createChannel();
    VnaChannel channel = vna.channel(2);
    VnaCalibrate calibrate = vna.channel(2).calibrate();

    QVERIFY(channel.corrections().isNotPresent());
    QVERIFY(vna.channel(1).corrections().isNotPresent());

    QVector<uint> ports;
    QVector<Connector> portTypes;

    NameLabel kit("3.5 mm Ideal Kit");
    ports << 1;
    portTypes << Connector(mm_3_5_CONNECTOR, MALE_GENDER);
    calibrate.selectKit(kit);
    calibrate.setConnector(1, portTypes.first());

    ports << 2;
    portTypes << Connector(mm_3_5_CONNECTOR, FEMALE_GENDER);
    calibrate.setConnector(2, portTypes.last());

    calibrate.start("singleChannelTOSM", TOSM_CAL_TYPE, ports);
    calibrate.measureOpen(1);
    vna.pause();
    calibrate.measureShort(1);
    vna.pause();
    calibrate.measureMatch(1);
    vna.pause();
    calibrate.measureOpen(2);
    vna.pause();
    calibrate.measureShort(2);
    vna.pause();
    calibrate.measureMatch(2);
    vna.pause();
    calibrate.measureThru(1, 2);
    vna.pause();
    calibrate.apply();
    vna.pause();

    QVERIFY(channel.corrections().isPresent());
    QVERIFY(vna.channel(1).corrections().isNotPresent());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}

void test_VnaCalibrate::allChannelsConnector() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("allChannelsConnector()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.createChannel();
    VnaCalibrate calibrate = vna.calibrate();

    calibrate.setConnector(1, N_50_OHM_CONNECTOR);
    QCOMPARE(calibrate.connector(1), Connector(N_50_OHM_CONNECTOR));
    QCOMPARE(vna.channel(1).calibrate().connector(1), vna.channel(2).calibrate().connector(1));
    calibrate.setConnector(1, mm_3_5_CONNECTOR);
    QCOMPARE(calibrate.connector(1), Connector(mm_3_5_CONNECTOR));
    QCOMPARE(vna.channel(1).calibrate().connector(1), vna.channel(2).calibrate().connector(1));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCalibrate::allChannelsSelectKit() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("allChannelsSelectKit()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.createChannel();
    VnaCalibrate calibrate = vna.calibrate();


    NameLabel firstKit, secondKit, thirdKit;
    firstKit = NameLabel("3650-1"); // 3.5 mm
    secondKit = NameLabel("3653"); // N50
    thirdKit = NameLabel("85052D"); // 3.5 mm


    calibrate.selectKit(firstKit);
    calibrate.selectKit(secondKit);
    if (vna.properties().isZnbFamily())
        QCOMPARE(calibrate.selectedKit(mm_3_5_CONNECTOR), firstKit);
    else
        QCOMPARE(calibrate.selectedKit(QString("PC 3.5")), firstKit);
    QCOMPARE(calibrate.selectedKit(N_50_OHM_CONNECTOR), secondKit);

    calibrate.selectKit(thirdKit);
    if (vna.properties().isZnbFamily())
        QCOMPARE(calibrate.selectedKit(mm_3_5_CONNECTOR), thirdKit);
    else
        QCOMPARE(calibrate.selectedKit(QString("PC 3.5")), thirdKit);
    QCOMPARE(calibrate.selectedKit(N_50_OHM_CONNECTOR), secondKit);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCalibrate::allChannelsKeepRawData() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("allChannelsKeepRawData()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.createChannel();
    VnaCalibrate calibrate = vna.calibrate();

    calibrate.start("singleChannelKeepRawData", OSM_CAL_TYPE, QVector<uint>(1,1));
    calibrate.keepRawData();
    QVERIFY(calibrate.isRawDataKept());
    calibrate.keepRawData(false);
    QVERIFY(calibrate.isRawDataKept() == false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}

void test_VnaCalibrate::allChannelsOSM() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("allChannelsOSM()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    if (vna.properties().isZvaFamily()) {
        log->print("Zva firmware doesn\'t support calibrating multiple channels at once\n\n");
    }
    else {
        vna.settings().displayOn();
        vna.createChannel();
        VnaChannel channel1 = vna.channel(1);
        VnaChannel channel2 = vna.channel(2);
        VnaCalibrate calibrate = vna.calibrate();

        QVERIFY(channel1.corrections().isNotPresent());
        QVERIFY(channel2.corrections().isNotPresent());

        NameLabel kit;
        QVector<uint> ports;
        QVector<Connector> portTypes;

        kit = NameLabel("3.5 mm Ideal Kit");
        ports << 1;
        portTypes << Connector(mm_3_5_CONNECTOR, MALE_GENDER);
        calibrate.selectKit(kit);
        calibrate.setConnector(1, portTypes.first());

        calibrate.start("allChannelsOSM", OSM_CAL_TYPE, ports);
        calibrate.measureOpen(1);
        vna.pause();
        calibrate.measureShort(1);
        vna.pause();
        calibrate.measureMatch(1);
        vna.pause();
        calibrate.apply();
        vna.pause();

        QVERIFY(channel1.corrections().isPresent());
        QVERIFY(channel2.corrections().isPresent());
    }

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCalibrate::allChannelsUOSM() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("allChannelsUOSM()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    if (vna.properties().isZvaFamily()) {
        log->print("Zva firmware doesn\'t support calibrating multiple channels at once\n\n");
    }
    else {
        vna.settings().displayOn();
        vna.createChannel();
        VnaCalibrate calibrate = vna.calibrate();

        QVERIFY(vna.channel(1).corrections().isNotPresent());
        QVERIFY(vna.channel(2).corrections().isNotPresent());

        QVector<uint> ports;
        QVector<Connector> portTypes;

        NameLabel port1Kit("3.5 mm Ideal Kit");
        ports << 1;
        portTypes << Connector(mm_3_5_CONNECTOR, MALE_GENDER);
        calibrate.selectKit(port1Kit);
        calibrate.setConnector(1, portTypes.first());

        NameLabel port2Kit("N 50 Ohm Ideal Kit");
        ports << 2;
        portTypes << Connector(N_50_OHM_CONNECTOR, FEMALE_GENDER);
        calibrate.selectKit(port2Kit);
        calibrate.setConnector(2, portTypes.last());

        calibrate.start("allChannelsUOSM", UOSM_CAL_TYPE, ports);
        calibrate.measureOpen(1);
        vna.pause();
        calibrate.measureShort(1);
        vna.pause();
        calibrate.measureMatch(1);
        vna.pause();
        calibrate.measureOpen(2);
        vna.pause();
        calibrate.measureShort(2);
        vna.pause();
        calibrate.measureMatch(2);
        vna.pause();
        calibrate.measureThru(1, 2);
        vna.pause();
        calibrate.apply();
        vna.pause();

        QVERIFY(vna.channel(1).corrections().isPresent());
        QVERIFY(vna.channel(2).corrections().isPresent());
    }

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaCalibrate::allChannelsTOSM() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("allChannelsTOSM()"), appName, appVersion));
    log->printProgramHeader();
    vna.useLog(log.data());
    vna.printInfo();

    if (vna.properties().isZvaFamily()) {
        log->print("Zva firmware doesn\'t support calibrating multiple channels at once\n\n");
    }
    else {
        vna.settings().displayOn();
        vna.createChannel();
        VnaCalibrate calibrate = vna.calibrate();

        QVERIFY(vna.channel(1).corrections().isNotPresent());
        QVERIFY(vna.channel(2).corrections().isNotPresent());

        QVector<uint> ports;
        QVector<Connector> portTypes;

        NameLabel kit("3.5 mm Ideal Kit");
        ports << 1;
        portTypes << Connector(mm_3_5_CONNECTOR, MALE_GENDER);
        calibrate.selectKit(kit);
        calibrate.setConnector(1, portTypes.first());

        ports << 2;
        portTypes << Connector(mm_3_5_CONNECTOR, FEMALE_GENDER);
        calibrate.setConnector(2, portTypes.last());

        calibrate.start("allChannelsTOSM", TOSM_CAL_TYPE, ports);
        calibrate.measureOpen(1);
        vna.pause();
        calibrate.measureShort(1);
        vna.pause();
        calibrate.measureMatch(1);
        vna.pause();
        calibrate.measureOpen(2);
        vna.pause();
        calibrate.measureShort(2);
        vna.pause();
        calibrate.measureMatch(2);
        vna.pause();
        calibrate.measureThru(1, 2);
        vna.pause();
        calibrate.apply();
        vna.pause();

        QVERIFY(vna.channel(1).corrections().isPresent());
        QVERIFY(vna.channel(2).corrections().isPresent());
    }

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaCalibrate)
#include "test_VnaCalibrate.moc"


