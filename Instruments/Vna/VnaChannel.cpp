#include <QDebug>

// RsaToolbox includes
#include "General.h"
#include "IndexName.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaChannel
 * \ingroup VnaGroup
 * \brief The \c %VnaChannel class
 * manipulates a channel.
 */

VnaChannel::VnaChannel(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _index = 0;
}
VnaChannel::VnaChannel(VnaChannel const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _index = other._index;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _index = 0;
    }
}
VnaChannel::VnaChannel(Vna *vna, uint index, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _index = index;
}

uint VnaChannel::index() {
    return(_index);
}
QString VnaChannel::name() {
    QString scpi = ":CONF:CHAN%1:NAME?\n";
    scpi = scpi.arg(_index);
    return(_vna->query(scpi).remove("\'").trimmed());
}
void VnaChannel::setName(QString name) {
    QString scpi = ":CONF:CHAN%1:NAME \'%2\'\n";
    scpi = scpi.arg(_index).arg(name);
    _vna->write(scpi);
}

QVector<uint> VnaChannel::diagrams() {
    return(QVector<uint>());
}
QStringList VnaChannel::traces() {
    // This function does not exist on a ZVA
    if (_vna->properties().isZvaFamily())
        return(zvaTraces());

    QString scpi = ":CONF:CHAN%1:TRAC:CAT?";
    scpi = scpi.arg(_index);
    QString result = _vna->query(scpi, 1000, 1000);
    QVector<IndexName> indexNames;
    indexNames = IndexName::parse(result, ",", "\'");
    return(IndexName::names(indexNames));
}

// Trigger
void VnaChannel::startSweep() {
    QString scpi = QString(":INIT%1\n").arg(_index);
    _vna->write(scpi);
}
uint VnaChannel::numberOfSweeps() {
    QString scpi = ":SENS%1:SWE:COUN?\n";
    scpi = scpi.arg(_index);
    QString result = _vna->query(scpi);
    return(result.trimmed().toUInt());
}
void VnaChannel::setNumberOfSweeps(uint sweeps) {
    QString scpi = ":SENS%1:SWE:COUN %2\n";
    scpi = scpi.arg(_index).arg(sweeps);
    _vna->write(scpi);
}
bool VnaChannel::isSweepOn() {
    if (_vna->properties().isZvaFamily()) {
        if (_vna->isLogConnected())
            *_vna->log() << "WARNING: isSweepOn() not available on ZVA-family instrument.\n\n";
        return(true);
    }

    QString scpi = ":CONF:CHAN%1:MEAS?\n";
    scpi = scpi.arg(_index);
    return(_vna->query(scpi).trimmed() == "1");
}
bool VnaChannel::isSweepOff() {
    return(!isSweepOn());
}
void VnaChannel::sweepOn(bool isOn) {
    if (_vna->properties().isZvaFamily()) {
        if (_vna->isLogConnected())
            *_vna->log() << "WARNING: sweepOn() not available on ZVA-family instrument.\n\n";
        return;
    }

    QString scpi = ":CONF:CHAN%1:MEAS %2\n";
    scpi = scpi.arg(_index);
    if (isOn)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
void VnaChannel::sweepOff(bool isOff) {
    sweepOn(!isOff);
}
bool VnaChannel::isContinuousSweep() {
    QString scpi = ":INIT%1:CONT?\n";
    scpi = scpi.arg(_index);
    return(_vna->query(scpi).trimmed() == "1");
}
bool VnaChannel::isManualSweep() {
    return(!isContinuousSweep());
}
void VnaChannel::continuousSweepOn(bool isOn) {
    QString scpi = QString(":INIT%1:CONT %2\n");
    scpi = scpi.arg(_index);
    if (isOn)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
void VnaChannel::manualSweepOn(bool isOn) {
    continuousSweepOn(!isOn);
}

// Sweep
bool VnaChannel::isLinearSweep() {
    return(sweepType() == LINEAR_SWEEP);
}
bool VnaChannel::isLogarithmicSweep() {
    return(sweepType() == LOG_SWEEP);
}
bool VnaChannel::isSegmentedSweep() {
    return(sweepType() == SEGMENTED_SWEEP);
}
bool VnaChannel::isPowerSweep() {
    return(sweepType() == POWER_SWEEP);
}
bool VnaChannel::isCwSweep() {
    return(sweepType() == CW_SWEEP);
}
bool VnaChannel::isTimeSweep() {
    return(sweepType() == TIME_SWEEP);
}
VnaSweepType VnaChannel::sweepType() {
    QString scpi = ":SENS%1:SWE:TYPE?\n";
    scpi = scpi.arg(_index);
    return(toVnaSweepType(_vna->query(scpi)));
}
void VnaChannel::setSweepType(VnaSweepType sweepType) {
    QString scpi = ":SENS%1:SWE:TYPE %2\n";
    scpi = scpi.arg(_index).arg(toScpi(sweepType));
    _vna->write(scpi);
}

VnaLinearSweep &VnaChannel::linearSweep() {
    _frequencySweep.reset(new VnaLinearSweep(_vna, this, this));
    return(*_frequencySweep.data());
}
VnaLinearSweep *VnaChannel::takeLinearSweep() {
    return(new VnaLinearSweep(_vna, _index, this));
}
VnaLogSweep &VnaChannel::logSweep() {
    _logSweep.reset(new VnaLogSweep(_vna, this, this));
    return(*_logSweep.data());
}
VnaLogSweep *VnaChannel::takeLogSweep() {
    return(new VnaLogSweep(_vna, _index));
}
VnaSegmentedSweep &VnaChannel::segmentedSweep() {
    _segmentedSweep.reset(new VnaSegmentedSweep(_vna, this, this));
    return(*_segmentedSweep.data());
}
VnaSegmentedSweep *VnaChannel::takeSegmentedSweep() {
    return(new VnaSegmentedSweep(_vna, _index));
}
VnaPowerSweep &VnaChannel::powerSweep() {
    _powerSweep.reset(new VnaPowerSweep(_vna, this, this));
    return(*_powerSweep.data());
}
VnaPowerSweep *VnaChannel::takePowerSweep() {
    return(new VnaPowerSweep(_vna, _index));
}
VnaCwSweep &VnaChannel::cwSweep() {
    _cwSweep.reset(new VnaCwSweep(_vna, this, this));
    return(*_cwSweep.data());
}
VnaCwSweep *VnaChannel::takeCwSweep() {
    return(new VnaCwSweep(_vna, _index));
}
VnaTimeSweep &VnaChannel::timeSweep() {
    _timeSweep.reset(new VnaTimeSweep(_vna, this, this));
    return(*_timeSweep.data());
}
VnaTimeSweep *VnaChannel::takeTimeSweep() {
    return(new VnaTimeSweep(_vna, _index));
}

// Balanced ports
uint VnaChannel::numberOfLogicalPorts() {
    uint ports = _vna->testPorts();
    for (uint i = 1; i < ports; i++) {
        if (isBalancedPort(i))
            ports--;
    }
    return(ports);
}
bool VnaChannel::isSingleEndedPort(uint logicalPort) {
    return(physicalPorts(logicalPort).size() == 1);
}
uint VnaChannel::physicalPort(uint logicalPort) {
    QVector<uint> ports = physicalPorts(logicalPort);
    if (ports.size() == 1)
        return(ports.first());
    else
        return(0);
}
bool VnaChannel::isBalancedPort(uint logicalPort) {
    return(physicalPorts(logicalPort).size() == 2);
}
QVector<uint> VnaChannel::physicalPorts(uint logicalPort) {
    QString scpi = ":SOUR%1:LPOR%2?\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(logicalPort);
    return(parseUints(_vna->query(scpi), ","));
}
void VnaChannel::physicalPorts(uint logicalPort, uint &physicalPort1, uint &physicalPort2) {
    QVector<uint> ports = physicalPorts(logicalPort);
    if (ports.size() == 2) {
        physicalPort1 = ports.first();
        physicalPort2 = ports.last();
    }
    else {
        physicalPort1 = 0;
        physicalPort2 = 0;
    }
}
void VnaChannel::createSingleEndedPort(uint logicalPort, uint physicalPort) {
    QString scpi = ":SOUR%1:LPOR%2 %3\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(logicalPort);
    scpi = scpi.arg(physicalPort);
    _vna->write(scpi);
}
void VnaChannel::createBalancedPort(uint logicalPort, uint physicalPort1, uint physicalPort2) {
    QString scpi = ":SOUR%1:LPOR%2 %3,%4\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(logicalPort);
    scpi = scpi.arg(physicalPort1);
    scpi = scpi.arg(physicalPort2);
    _vna->write(scpi);
}
void VnaChannel::deleteBalancedPort(uint logicalPort) {
    QString scpi = ":SOUR%1:LPOR%2:CLE\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(logicalPort);
    _vna->write(scpi);
}
void VnaChannel::deleteBalancedPorts() {
    QString scpi = ":SOUR%1:LPOR:CLE ALL\n";
    scpi = scpi.arg(_index);
    _vna->write(scpi);
}

// User-defined ports
bool VnaChannel::isUserDefinedPortOn(uint physicalPort) {
    QString scpi = ":SENS%1:UDSP%2:ACT?\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(physicalPort);
    return(_vna->query(scpi).trimmed() == "1");
}
bool VnaChannel::isUserDefinedPortOff(uint physicalPort) {
    return(!isUserDefinedPortOn(physicalPort));
}
void VnaChannel::userDefinedPortOn(uint physicalPort) {
    QString scpi = ":SENS%1:UDSP%2:ACT 1\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(physicalPort);
    _vna->write(scpi);
}
void VnaChannel::userDefinedPortOff(uint physicalPort) {
    QString scpi = ":SENS%1:UDSP%2:ACT 0\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(physicalPort);
    _vna->write(scpi);
}
bool VnaChannel::isUserDefinedPort(uint physicalPort) {
    return(isUserDefinedPortOn(physicalPort));
}
bool VnaChannel::isNotUserDefinedPort(uint physicalPort) {
    return(isUserDefinedPortOff(physicalPort));
}
VnaUserDefinedPort VnaChannel::userDefinedPort(uint physicalPort) {
    QString scpi = ":SENS%1:UDSP%2:PAR?\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(physicalPort);

    return(toUserDefinedPort(_vna->query(scpi).trimmed().remove("\'")));
}
void VnaChannel::setUserDefinedPort(uint physicalPort, VnaUserDefinedPort userDefinedPort) {
    QString scpi = ":SENS%1:UDSP%2:PAR \'%3\'\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(physicalPort);
    scpi = scpi.arg(toScpi(userDefinedPort));
    _vna->write(scpi);
    userDefinedPortOn(physicalPort);
}
void VnaChannel::deleteUserDefinedPort(uint physicalPort) {
    userDefinedPortOff(physicalPort);
}
void VnaChannel::deleteUserDefinedPorts() {
    if (_vna->properties().isZvaFamily()) {
        QVector<uint> ports = range(uint(1), _vna->testPorts());
        foreach(uint port, ports) {
            deleteUserDefinedPort(port);
        }
        return;
    }

    QString scpi = ":SENS%1:UDSP:ACT 0\n";
    scpi = scpi.arg(_index);
    _vna->write(scpi);
}

// Corrections/Calibrate
bool VnaChannel::isCalibrated() {
    QString scpi = ":SENS%1:CORR:DATA:PAR:COUN?\n";
    scpi = scpi.arg(_index);
    return(_vna->query(scpi).toInt() > 0);
}
bool VnaChannel::isCalGroup() {
    return(calGroup().isEmpty() == false);
}
void VnaChannel::saveCalibration(QString calGroup) {
    if (calGroup.contains(".cal", Qt::CaseInsensitive) == false)
        calGroup += ".cal";

    QString scpi = ":MMEM:STOR:CORR %1,\'%2\'\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(calGroup);
    _vna->write(scpi);
}
void VnaChannel::setCalGroup(QString calGroup) {
    if (calGroup.endsWith(".cal", Qt::CaseInsensitive) == false)
        calGroup += ".cal";

    QString scpi = ":MMEM:LOAD:CORR %1,\'%2\'\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(calGroup);
    _vna->write(scpi);
}
QString VnaChannel::calGroup() {
    QString scpi = ":MMEM:LOAD:CORR? %1\n";
    scpi = scpi.arg(_index);
    return(_vna->query(scpi).remove("\'").remove(".cal"));
}
QString VnaChannel::calGroupFile() {
    QString scpi = ":MMEM:LOAD:CORR? %1\n";
    scpi = scpi.arg(_index);
    QString filePathName = _vna->query(scpi).remove("\'");
    filePathName = _vna->fileSystem().directory(CAL_GROUP_DIRECTORY) + "\\" + filePathName;
    return(filePathName);
}
void VnaChannel::dissolveCalGroup() {
    QString scpi = ":MMEM:LOAD:CORR:RES %1\n";
    scpi = scpi.arg(_index);
    _vna->write(scpi);
}

VnaCorrections &VnaChannel::corrections() {
    _corrections.reset(new VnaCorrections(_vna, this, this));
    return(*_corrections.data());
}
VnaCalibrate &VnaChannel::calibrate() {
    _calibrate.reset(new VnaCalibrate(_vna, this, this));
    return(*_calibrate.data());
}
VnaCalibrate *VnaChannel::takeCalibrate() {
    return(new VnaCalibrate(_vna, _index));
}

void VnaChannel::operator=(VnaChannel const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _index = other._index;
    }
}

//void VnaChannel::moveToThread(QThread *thread) {
//    if (_frequencySweep.isNull() == false)
//        _frequencySweep->moveToThread(thread);
//    if (_logSweep.isNull() == false)
//        _logSweep->moveToThread(thread);
//    if (_segmentedSweep.isNull() == false)
//        _segmentedSweep->moveToThread(thread);
//    if (_powerSweep.isNull() == false)
//        _powerSweep->moveToThread(thread);
//    if (_timeSweep.isNull() == false)
//        _timeSweep->moveToThread(thread);
//    if (_cwSweep.isNull() == false)
//        _cwSweep->moveToThread(thread);
//    if (_corrections.isNull() == false)
//        _corrections->moveToThread(thread);
//    if (_calibrate.isNull() == false)
//        _calibrate->moveToThread(thread);

//}

// Private
bool VnaChannel::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);
    if (_index == 0)
        return(false);
    //else
    return(true);
}
QStringList VnaChannel::zvaTraces() {
    QStringList traces = _vna->traces();
    QStringList result;
//    foreach(QString trace, traces) {
//        if (_vna->trace(trace).channel() == _index)
//            result << trace;
//    }
    return(result);
}

QString RsaToolbox::toScpi(VnaSweepType sweepType) {
    switch(sweepType) {
    case LINEAR_SWEEP:
        return("LIN");
    case LOG_SWEEP:
        return("LOG");
    case SEGMENTED_SWEEP:
        return("SEGM");
    case POWER_SWEEP:
        return("POW");
    case CW_SWEEP:
        return("CW");
    case TIME_SWEEP:
        return("POIN");
    default:
        return("LIN");
    }
}
VnaSweepType RsaToolbox::toVnaSweepType(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "LIN")
            return(LINEAR_SWEEP);
        if (scpi == "LOG")
            return(LOG_SWEEP);
        if (scpi == "SEGM")
            return(SEGMENTED_SWEEP);
        if (scpi == "POW")
            return(POWER_SWEEP);
        if (scpi == "CW")
            return(CW_SWEEP);
        if (scpi == "POIN")
            return(TIME_SWEEP);
        // Default
        return(LINEAR_SWEEP);
}
