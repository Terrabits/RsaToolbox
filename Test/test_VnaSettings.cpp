

#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>

class test_VnaSettings : public QObject
{
    Q_OBJECT

public:
    test_VnaSettings();

private:
    Vna vna;
    // Object to test
    Log log;

    int cycle;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void setIdString();
    void setOptionsString();
    void emulationMode();
    void display();
    void displayErrors();
    void colorScheme();
    void fontSize();
    void userPreset();
    void calibrationPreset();
    void portPowerLimits();
    void rfOutput();
    void dynamicIFBandwidth();
    void lowPowerAutocal();
};

test_VnaSettings::test_VnaSettings() {
    cycle = 0;
    appName = "test_VnaSettings";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaSettings Logs";
    
    // Initialize object here
}

void test_VnaSettings::init() {
    Log log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion);
    log.printProgramHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    QVERIFY(vna.isConnected());
    vna.useLog(&log);
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
void test_VnaSettings::cleanup() {
    Log log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();
    vna.settings().setEmulationOff();
    QVERIFY(vna.settings().isEmulationOff());
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaSettings::setIdString() {
    Log log(logPath, filename.arg(cycle++).arg("setIdString()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    if (vna.properties().isZvaFamily() == false) {
        QString originalId= vna.idString();
        QString myIdString = "Hello World!";
        vna.settings().setIdString(myIdString);
        QCOMPARE(vna.idString(), myIdString);
        vna.settings().resetIdString();
        QCOMPARE(vna.idString(), originalId);
    }

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::setOptionsString() {
    Log log(logPath, filename.arg(cycle++).arg("setOptionsString()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    if (vna.properties().isZvaFamily() == false) {
        vna.settings().resetOptionsString();
        QString originalOptions= vna.optionsString();
        QString myOptionsString = "Hello World!";
        vna.settings().setOptionsString(myOptionsString);
        QCOMPARE(vna.optionsString(), myOptionsString);
        vna.settings().resetOptionsString();
        QCOMPARE(vna.optionsString(), originalOptions);
    }

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::emulationMode() {
    Log log(logPath, filename.arg(cycle++).arg("emulationMode()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    vna.settings().setEmulationOff();
    QVERIFY(vna.settings().isEmulationOff());
    vna.settings().setEmulationMode(HP_8720_EMULATION);
    QCOMPARE(vna.settings().emulationMode(), HP_8720_EMULATION);
    QVERIFY(vna.idString().contains("Hewlett", Qt::CaseInsensitive));
    vna.settings().setEmulationOff();
    QVERIFY(vna.settings().isEmulationOff());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::display() {
    Log log(logPath, filename.arg(cycle++).arg("display()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    vna.settings().displayOn();
    QVERIFY(vna.settings().isDisplayOn());
    vna.settings().displayOff();
    QVERIFY(vna.settings().isDisplayOff());
    vna.settings().displayOn();
    QVERIFY(vna.settings().isDisplayOn());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::displayErrors() {
    Log log(logPath, filename.arg(cycle++).arg("displayErrors()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    vna.settings().errorDisplayOn();
    QVERIFY(vna.settings().isErrorDisplayOn());
    vna.settings().errorDisplayOff();
    QVERIFY(vna.settings().isErrorDisplayOff());
    vna.settings().errorDisplayOn();
    QVERIFY(vna.settings().isErrorDisplayOn());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::colorScheme() {
    Log log(logPath, filename.arg(cycle++).arg("colorScheme()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    vna.settings().setDefaultColorScheme();
    QCOMPARE(vna.settings().colorScheme(), DARK_BACKGROUND);
    vna.settings().setColorScheme(LIGHT_BACKGROUND);
    QCOMPARE(vna.settings().colorScheme(), LIGHT_BACKGROUND);
    vna.settings().setDefaultColorScheme();
    QVERIFY(vna.settings().isColorScheme(DARK_BACKGROUND));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::fontSize() {
    Log log(logPath, filename.arg(cycle++).arg("fontSize()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    uint defaultFontSize = 100;
    vna.settings().resetFontSize();
    QCOMPARE(vna.settings().fontSize_percent(), defaultFontSize);
    vna.settings().setFontSize(80);
    QCOMPARE(vna.settings().fontSize_percent(), uint(80));
    vna.settings().resetFontSize();
    QCOMPARE(vna.settings().fontSize_percent(), defaultFontSize);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::userPreset() {
    Log log(logPath, filename.arg(cycle++).arg("userPreset()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    QString set;
    if (vna.properties().isZvaFamily())
        set = "Test.zvx";
    else
        set = "Test.znx";

    vna.settings().userPresetOff();
    vna.settings().setUserPreset("");
    QVERIFY(vna.settings().isUserPresetOff());
    QCOMPARE(vna.settings().userPreset(), QString());
    vna.settings().userPresetOn();
    vna.settings().setUserPreset(set);
    QVERIFY(vna.settings().userPreset().contains(set));
    QVERIFY(vna.settings().isUserPresetOn());
    vna.settings().userPresetOff();
    vna.settings().setUserPreset("");
    QVERIFY(vna.settings().isUserPresetOff());
    QCOMPARE(vna.settings().userPreset(), QString());


    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::calibrationPreset() {
    Log log(logPath, filename.arg(cycle++).arg("calibrationPreset()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    if (vna.properties().isZnbFamily()) {
        vna.settings().calibrationPresetOff();
        QVERIFY(vna.settings().isCalibrationPresetOff());
        QCOMPARE(vna.settings().calibrationPreset(), QString());
        vna.settings().setCalibrationPreset("Test.cal");
        QVERIFY(vna.settings().isCalibrationPresetOn());
        QCOMPARE(vna.settings().calibrationPreset(), QString("Test"));
        vna.settings().calibrationPresetOff();
        vna.settings().setCalibrationPreset("");
        QVERIFY(vna.settings().isCalibrationPresetOff());
        QCOMPARE(vna.settings().calibrationPreset(), QString());
    }

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::portPowerLimits() {
    Log log(logPath, filename.arg(cycle++).arg("portPowerLimits()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    vna.settings().portPowerLimitsOff();
    QVERIFY(vna.settings().isPortPowerLimitOff());
    vna.settings().portPowerLimitOn(1);
    vna.settings().setPortPowerLimit(1, -5.2);
    QVERIFY(vna.settings().isPortPowerLimitOn(1));
    QVERIFY(vna.settings().isPortPowerLimitOn());
    QCOMPARE(vna.settings().portPowerLimit_dBm(1), double(-5.2));
    vna.settings().portPowerLimitsOff();
    QVERIFY(vna.settings().isPortPowerLimitOff(1));
    QVERIFY(vna.settings().isPortPowerLimitOff());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::rfOutput() {
    Log log(logPath, filename.arg(cycle++).arg("rfOutput()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    vna.settings().rfOutputPowerOn();
    QVERIFY(vna.settings().isRfOutputPowerOn());
    vna.settings().rfOutputPowerOff();
    QVERIFY(vna.settings().isRfOutputPowerOff());
    vna.settings().rfOutputPowerOn();
    QVERIFY(vna.settings().isRfOutputPowerOn());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::dynamicIFBandwidth() {
    Log log(logPath, filename.arg(cycle++).arg("dynamicIFBandwidth()"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    if (vna.properties().isZnbFamily()) {
        QVERIFY(vna.settings().isDynamicIfBandwidthOff());
    }
    else {
        vna.settings().dynamicIfBandwidthOn();
        QVERIFY(vna.settings().isDynamicIfBandwidthOn());
        vna.settings().dynamicIfBandwidthOff();
        QVERIFY(vna.settings().isDynamicIfBandwidthOff());
        vna.settings().dynamicIfBandwidthOn();
        QVERIFY(vna.settings().isDynamicIfBandwidthOn());
    }

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaSettings::lowPowerAutocal() {
    Log log(logPath, filename.arg(cycle++).arg("lowPowerAutocal"), appName, appVersion);
    log.printProgramHeader();
    vna.useLog(&log);
    vna.printInfo();

    vna.settings().lowPowerAutoCalOn();
    QVERIFY(vna.settings().isLowPowerAutoCalOn());
    vna.settings().lowPowerAutoCalOff();
    QVERIFY(vna.settings().isLowPowerAutoCalOff());
    vna.settings().lowPowerAutoCalOn();
    QVERIFY(vna.settings().isLowPowerAutoCalOn());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaSettings)
#include "test_VnaSettings.moc"


