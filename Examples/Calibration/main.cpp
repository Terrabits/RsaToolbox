

// RsaToolbox
#include "Vna.h"
using namespace RsaToolbox;

// Qt
#include <QCoreApplication>
#include <QDir>
#include <QVector>


void main()
{
    Vna vna(ConnectionType::VisaTcpConnection, "127.0.0.1");

    // Is cal unit?
    vna.isCalUnit();

    // List of connected
    // cal units by ID
    vna.calUnits();

    // Get cal unit interface
    QString id = vna.calUnits().first();
    VnaCalUnit calUnit = vna.calUnit(id);

    // Cal unit properties
    calUnit.ports(); // Number of ports
    calUnit.maximumFrequency_Hz();
    calUnit.minimumFrequency_Hz();

    // Warmed up?
    calUnit.isWarmedUp();

    // Vna ports connected
    calUnit.connectedToPorts();

    // Use cal unit to calibrate
    // ports in channel
    QVector<uint> ports;
    ports << 1 << 2 << 3 << 4;
    VnaChannel ch1 = vna.channel(1);
    ch1.calibrate().autoCalibrate(ports, id);

    // Is channel 1 calibrated?
    ch1.isCalibrated();

    // Save calibration
    ch1.saveCalibration("my_cal_group.cal");

    // Recall calibration
    ch1.setCalGroup("my_cal_group.cal");
}
