#include "VnaCalibrateTest.h"


// RsaToolbox
#include "Test.h"
using namespace RsaToolbox;


VnaCalibrateTest::VnaCalibrateTest(QObject *parent) :
    VnaTestClass(parent)
{

}
VnaCalibrateTest::VnaCalibrateTest(ConnectionType type, const QString &address, QObject *parent) :
    VnaTestClass(type, address, parent)
{

}

VnaCalibrateTest::~VnaCalibrateTest()
{

}

void VnaCalibrateTest::initTestCase() {
    _applicationName = "VnaCalbrate Test";
    _version        = "0.0";

    _logDir.setPath(SOURCE_DIR);
    _logDir.mkpath("VnaCalibrateTest");
    _logDir.cd("VnaCalibrateTest");
    if (isZvaFamily()) {
        QString logpath = SOURCE_DIR;
        logpath += "/VnaCalibrateTest/Zva/Logs";
        _logDir.setPath(logpath);
    }
    else if (isZnbFamily()) {
        QString logpath = SOURCE_DIR;
        logpath += "/VnaCalibrateTest/Znb/Logs";
        _logDir.setPath(logpath);
    }

    _logFilenames << "1 - Auto Calibrate.txt";

    _initTestCase();
}

void VnaCalibrateTest::autoCalibrate() {
    if (!_vna->isCalUnit()) {
        qDebug() << "Need cal unit for test";
        return;
    }
    QStringList calUnits = _vna->calUnits();
    if (calUnits.size() == 1 && calUnits.first() == "SimulatedCalu") {
        qDebug() << "Need real cal unit for test";
        return;
    }

    // Cal unit
    QString calId;
    if (calUnits.first() != "SimulatedCalu")
        calId = calUnits.first();
    else
        calId = calUnits.last();

    // Ports
    QVector<uint> ports;
    ports << 1
          << 2;

    // Ports connected
    QCOMPARE(_vna->calUnit(calId).connectedToPorts(),        ports);

    // Calibrate
    _vna->channel().calibrate().autoCalibrate(ports);
    QVERIFY(_vna->channel().isCalibrated());
    QVERIFY(!_vna->isError());
}
