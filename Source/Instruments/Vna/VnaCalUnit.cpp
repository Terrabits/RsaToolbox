

// RsaToolbox includes
#include "General.h"
#include "Vna.h"
#include "VnaScpi.h"
#include "VnaCalUnit.h"
using namespace RsaToolbox;

// Qt
#include <QDebug>

// std lib
#include <algorithm>

/*!
 * \class RsaToolbox::VnaCalUnit
 * \ingroup VnaGroup
 * \brief The \c %VnaCalUnit class
 * manipulates a Calibration Unit
 * connected to a Vna.
 */

VnaCalUnit::VnaCalUnit(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _id = QString();
}

VnaCalUnit::VnaCalUnit(const VnaCalUnit &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _id = other._id;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _id = QString();
    }
}

VnaCalUnit::VnaCalUnit(Vna *vna, QString id, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _id = id;
}
VnaCalUnit::~VnaCalUnit() {

}

QString VnaCalUnit::id() const {
    return _id;
}

double VnaCalUnit::minimumFrequency_Hz() {
    select();
    QString scpi = ":SYST:COMM:RDEV:AKAL:FRAN? \'Factory\'\n";
    QStringList result = _vna->query(scpi).trimmed().split(",");
    if (result.size() != 2)
        return 0;
    else
        return result.first().toDouble();
}
double VnaCalUnit::maximumFrequency_Hz() {
    select();
    QString scpi = ":SYST:COMM:RDEV:AKAL:FRAN? \'Factory\'\n";
    QStringList result = _vna->query(scpi).trimmed().split(",");
    if (result.size() != 2)
        return 0;
    else
        return result.last().toDouble();
}
uint VnaCalUnit::ports() {
    // Handle ZVA separately...
    // Does it have
    // ":SYST:COMM:RDEV:AKAL:PORT? \'Factory\'\n"
    // command?
    // NO!
    if (_vna->properties().isZvaFamily()) {
        select();
        _vna->isError();
        _vna->clearStatus();
        uint port = 0;
        while (!_vna->isError()) {
            port++;
            setOpen(port);
        }
        _vna->clearStatus();
        return port-1;
    }

    return uint(physicalConnectors().size());
}
QVector<uint> VnaCalUnit::connectedToPorts() {
    select();

    const uint buffer_B = 500;
    const uint timeout_ms = 20000; // 20 seconds. Auto-detect is slow.
    QString scpi = "SENS:CORR:COLL:AUTO:PORT:CONN?\n";
    QStringList response = _vna->query(scpi, buffer_B, timeout_ms).trimmed().split(",", QString::SkipEmptyParts);
    QVector<uint> ports;
    for (int i = 0; i+1 < response.size(); i+=2) {
        const uint unitPort = response[i+1].toUInt();
        const uint vnaPort  = response[i].toUInt();
        if (unitPort)
            ports << vnaPort;
    }
    return ports;
}

bool VnaCalUnit::hasConnector(Connector connector) {
    return hasConnector("Factory", connector);
}
bool VnaCalUnit::hasConnector(QString calName, Connector connector) {
    return !portsOfType(calName, connector).isEmpty();
}
QMap<uint, Connector> VnaCalUnit::physicalConnectors() {
    return connectorsFrom("Factory");
}
QMap<uint, Connector> VnaCalUnit::connectorsFromLatestCal() {
    return connectorsFrom("");
}
QMap<uint, Connector> VnaCalUnit::connectorsFrom(QString calName) {
    if (_vna->properties().isZvaFamily())
        return QMap<uint, Connector>();

    select();
    QString scpi = ":SYST:COMM:RDEV:AKAL:PORT? \'%1\'\n";
    scpi = scpi.arg(calName);
    QStringList result = _vna->query(scpi).trimmed().remove("\'").split(",");

    if (result.isEmpty() || result.size() % 3 != 0)
        return QMap<uint, Connector>();

    // result[0]: Port (duh!)
    // result[1]: Connector type
    // result[2]: Connector gender
    const int ports = result.size()/3;
    QMap<uint, Connector> connectors;
    for (int i = 0; i < ports; i++) {
        uint currentPort         = result[3*i].toUInt();
        Connector::Type type     = VnaScpi::toConnectorType(result[3*i+1]);
        Connector::Gender gender = VnaScpi::toConnectorGender(result[3*i+2]);
        connectors[currentPort]  = Connector(type, gender);
    }
    return connectors;
}
QVector<uint> VnaCalUnit::portsOfType(Connector connector) {
    return portsOfType("Factory", connector);
}
QVector<uint> VnaCalUnit::portsOfTypeFromLatestCal(Connector connector) {
    return portsOfType("", connector);
}

QVector<uint> VnaCalUnit::portsOfType(QString calName, Connector connector) {
    QVector<uint> ports;
    QMap<uint, Connector> connectors = connectorsFrom(calName);
    foreach (uint i, connectors.keys()) {
        if (connectors[i] == connector) {
            ports << i;
        }
    }
    std::sort(ports.begin(), ports.end());
    return ports;
}

QStringList VnaCalUnit::calibrations() {
    select();
    QString scpi = ":SYST:COMM:RDEV:AKAL:CKIT:CAT?\n";
    return _vna->query(scpi).trimmed().remove('\'').split(",", QString::SkipEmptyParts);
}
void VnaCalUnit::frequencyRange(QString calName, double &min_Hz, double &max_Hz) {
    QString scpi = ":SYST:COMM:RDEV:AKAL:FRAN? \'%1\'\n";
    scpi = scpi.arg(calName);
    QStringList result = _vna->query(scpi).trimmed().split(",");
    if (result.size() != 2)
        return;

    min_Hz = result.first().toDouble();
    max_Hz = result.last().toDouble();
}

void VnaCalUnit::exportFactoryCal(QString path) {
    QString scpi = ":MMEM:AKAL:FACT:CONV \'%1\'\n";
    scpi = scpi.arg(path);

    select();
    _vna->write(scpi);
    _vna->pause(10000);
}
void VnaCalUnit::exportLatestCal(QString path) {
    QString scpi = ":MMEM:AKAL:USER:CONV \'%1\'\n";
    scpi = scpi.arg(path);

    select();
    _vna->write(scpi);
    _vna->pause(10000);
}
void VnaCalUnit::exportCalibration(QString calName, QString path) {
    QString scpi = ":MMEM:AKAL:USER:CONV \'%1\',\'%2\'\n";
    scpi = scpi.arg(path);
    scpi = scpi.arg(calName);

    select();
    _vna->write(scpi);
    _vna->pause(10000);
}

bool VnaCalUnit::isWarmedUp() {
    const QString scpi = ":SYST:COMM:RDEV:AKAL:WARM?\n";
    select();
    return _vna->query(scpi).trimmed() == "1";
}
void VnaCalUnit::setOpen(uint port) {
    QString scpi = ":SYST:COMM:AKAL:CONN OPEN,%1\n";
    scpi = scpi.arg(port);

    select();
    _vna->write(scpi);
    _vna->pause(2.0E3);
}
void VnaCalUnit::setOpen(QVector<uint> ports) {
    foreach(uint port, ports)
        setOpen(port);
}
void VnaCalUnit::setOpen() {
    setOpen(range(uint(1), ports()));
}
void VnaCalUnit::setShort(uint port) {
    QString scpi = ":SYST:COMM:AKAL:CONN SHOR,%1\n";
    scpi = scpi.arg(port);

    select();
    _vna->write(scpi);
    _vna->pause(2.0E3);
}
void VnaCalUnit::setShort(QVector<uint> ports) {
    foreach(uint port, ports)
        setShort(port);
}
void VnaCalUnit::setShort() {
    setShort(range(uint(1), ports()));
}
void VnaCalUnit::setMatch(uint port) {
    QString scpi = ":SYST:COMM:AKAL:CONN MATC,%1\n";
    scpi = scpi.arg(port);

    select();
    _vna->write(scpi);
    _vna->pause(2.0E3);
}
void VnaCalUnit::setMatch(QVector<uint> ports) {
    foreach(uint port, ports)
        setMatch(port);
}
void VnaCalUnit::setMatch() {
    setMatch(range(uint(1), ports()));
}
void VnaCalUnit::setThru(uint port1, uint port2) {
    QString scpi = ":SYST:COMM:AKAL:CONN THR,%1,%2\n";
    scpi = scpi.arg(port1);
    scpi = scpi.arg(port2);

    select();
    _vna->write(scpi);
    _vna->pause(2.0E3);
}


void VnaCalUnit::operator=(VnaCalUnit const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _id = other._id;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _id = QString();
    }
}

// Private
bool VnaCalUnit::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}

void VnaCalUnit::select() {
    QString scpi = ":SYST:COMM:RDEV:AKAL:ADDR \'%1\'\n";
    scpi = scpi.arg(_id);
    _vna->write(scpi);
}
