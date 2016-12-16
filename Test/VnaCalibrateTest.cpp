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
    bool isSimulatedCal = false;
    if (!_vna->isCalUnit()) {
        if (_vna->properties().isZnbFamily()) {
            isSimulatedCal = true;
            _vna->settings().serviceFunction("0.1.0.20.8", "894129");
            _vna->pause();
        }
        else {
            qDebug() << "Need cal unit for test";
            return;
        }
    }

    QString calId = _vna->calUnits().first();

    QVector<uint> ports;
    ports << 1
          << 2;
    QCOMPARE(_vna->calUnit(calId).connectedToPorts(), ports);

    _vna->channel().calibrate().autoCalibrate(ports);
    QVERIFY(_vna->channel().isCalibrated());

    if (isSimulatedCal) {
        _vna->settings().serviceFunction("0.1.0.20.0", "894129");
    }
}
