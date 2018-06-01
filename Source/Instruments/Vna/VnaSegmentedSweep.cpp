#include <QDebug>

// RsaToolbox includes
#include "General.h"
#include "VnaSegmentedSweep.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaSegmentedSweep
 * \ingroup VnaGroup
 * \brief The \c %VnaSegmentedSweep class
 * configures and controls a frequency sweep
 * with arbitrarily-defined measurement
 * points.
 */

VnaSegmentedSweep::VnaSegmentedSweep(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaSegmentedSweep::VnaSegmentedSweep(VnaSegmentedSweep &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _channel.reset(new VnaChannel(*other._channel.data()));
        _channelIndex = other._channelIndex;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
    }
}
VnaSegmentedSweep::VnaSegmentedSweep(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}
VnaSegmentedSweep::VnaSegmentedSweep(Vna *vna, uint index, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, index));
    _channelIndex = index;
}
VnaSegmentedSweep::~VnaSegmentedSweep() {

}


uint VnaSegmentedSweep::points() {
    uint numberOfSegments = segments();
    uint points = 0;
    for (uint i = 1; i <= numberOfSegments; i++) {
        points += segment(i).points();
    }
    return points;
}

double VnaSegmentedSweep::start_Hz() {
    return min(frequencies_Hz());
}
double VnaSegmentedSweep::stop_Hz() {
    return max(frequencies_Hz());
}
QRowVector VnaSegmentedSweep::frequencies_Hz() {
    QString scpi = ":CALC%1:DATA:STIM?\n";
    scpi = scpi.arg(_channelIndex);
    uint bufferSize = frequencyBufferSize(points());
    return _vna->queryVector(scpi, bufferSize);
}
double VnaSegmentedSweep::power_dBm() {
    QString scpi = ":SOUR%1:POW?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaSegmentedSweep::setPower(double power_dBm) {
    QString scpi = ":SOUR%1:POW %2\n";
    scpi = scpi.arg(_channelIndex).arg(power_dBm);
    _vna->write(scpi);
}
double VnaSegmentedSweep::ifBandwidth_Hz() {
    QString scpi = QString("SENS%1:BAND?\n").arg(_channelIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaSegmentedSweep::setIfbandwidth(double bandwidth, SiPrefix prefix) {
    QString scpi = "SENS%1:BAND %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(bandwidth);
    scpi = scpi.arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}

uint VnaSegmentedSweep::segments() {
    QString scpi = ":SENS%1:SEGM:COUN?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toUInt();
}
void VnaSegmentedSweep::addSegment(uint index) {
    QString scpi = ":SENS%1:SEGM%2:ADD\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(index);
    _vna->write(scpi);
}
uint VnaSegmentedSweep::addSegment() {
    uint index = segments() + 1;
    QString scpi = ":SENS%1:SEGM%2:ADD\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(index);
    _vna->write(scpi);
    return index;
}
void VnaSegmentedSweep::deleteSegment(uint index) {
    QString scpi = ":SENS%1:SEGM%2:DEL\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(index);
    _vna->write(scpi);
}
void VnaSegmentedSweep::deleteSegments() {
    QString scpi = ":SENS%1:SEGM:DEL:ALL\n";
    scpi = scpi.arg(_channelIndex);
    _vna->write(scpi);
}
VnaSweepSegment &VnaSegmentedSweep::segment(uint index) {
    _segment.reset(new VnaSweepSegment(_vna, _channel.data(), index));
    return *_segment.data();
}

QVector<uint> VnaSegmentedSweep::sParameterGroup() {
    return _channel->linearSweep().sParameterGroup();
}
void VnaSegmentedSweep::setSParameterGroup(QVector<uint> ports) {
    _channel->linearSweep().setSParameterGroup(ports);
}
void VnaSegmentedSweep::clearSParameterGroup() {
    _channel->linearSweep().clearSParameterGroup();
}
ComplexMatrix3D VnaSegmentedSweep::readSParameterGroup() {
    // data size
    const uint ports = sParameterGroup().size();
    const uint points = this->points();
    if (ports == 0 || points == 0) {
        return ComplexMatrix3D();
    }

    // sweep
    bool isContinuousSweep = _channel->isContinuousSweep();
    _channel->manualSweepOn();
    const uint timeout_ms = sweepTime_ms() * _channel->sweepCount();
    _channel->startSweep();
    _vna->pause(timeout_ms);

    // query, return data
    QString scpi = ":CALC%1:DATA:SGR? SDAT\n";
    scpi         = scpi.arg(_channelIndex);
    const uint bufferSize = dataBufferSize(ports, points);
    ComplexRowVector data = _vna->queryComplexVector(scpi, bufferSize);
    _channel->continuousSweepOn(isContinuousSweep);
    return toComplexMatrix3D(data, points, ports, ports);
}

uint VnaSegmentedSweep::sweepTime_ms() {
    // Is this fixed as of ZNB firmware v2.60 beta,
    // ZVA firmware v3.50?
    // It appears to be working now...
    QString scpi = ":SENS%1:SEGM:SWE:TIME:SUM?\n";
    scpi = scpi.arg(_channelIndex);
    return ceil(_vna->query(scpi).trimmed().toDouble() * 1000);
//    return 600000; // 10 minutes!
}

NetworkData VnaSegmentedSweep::measure(uint port1) {
    QVector<uint> ports;
    ports << port1;
    return measure(ports);
}
NetworkData VnaSegmentedSweep::measure(uint port1, uint port2) {
    QVector<uint> ports;
    ports << port1 << port2;
    return measure(ports);
}
NetworkData VnaSegmentedSweep::measure(uint port1, uint port2, uint port3) {
    QVector<uint> ports;
    ports << port1 << port2 << port3;
    return measure(ports);
}
NetworkData VnaSegmentedSweep::measure(uint port1, uint port2, uint port3, uint port4) {
    QVector<uint> ports;
    ports << port1 << port2 << port3 << port4;
    return measure(ports);
}
NetworkData VnaSegmentedSweep::measure(QVector<uint> ports) {
    NetworkData network;

    if (ports.size() <= 0)
        return network;
    if (_channel->isCwSweep() || _channel->isTimeSweep())
        return network;

    const QRowVector freq_Hz = frequencies_Hz();
    if (freq_Hz.isEmpty()) {
        return network;
    }

    setSParameterGroup(ports);
    const ComplexMatrix3D s = readSParameterGroup(); // sweeps
    if (s.empty()) {
        return network;
    }

    network.setParameter(NetworkParameter::S);
    network.setReferenceImpedance(50);
    network.setXUnits(Units::Hertz);
    network.setData(freq_Hz, s);
    return network;
}


void VnaSegmentedSweep::operator=(VnaSegmentedSweep const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _channel.reset(new VnaChannel(*other._channel.data()));
        _channelIndex = _channel->index();
    }
    else {
        _vna = placeholder.data();
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
    }
}

//void VnaSegmentedSweep::moveToThread(QThread *thread) {
//    QObject::moveToThread(thread);
//    if (_channel.isNull() == false)
//        _channel->moveToThread(thread);
//    if (_segment.isNull() == false)
//        _segment->moveToThread(thread);
//}

// Private
bool VnaSegmentedSweep::isFullyInitialized() const {
    if (_vna == NULL)
        return false;
    if (_vna == placeholder.data())
        return false;

    //else
    return true;
}
uint VnaSegmentedSweep::frequencyBufferSize(uint points) {
    const uint SIZE_PER_POINT = 20;
    return SIZE_PER_POINT * points;
}
uint VnaSegmentedSweep::dataBufferSize(uint ports, uint points) {
    const uint HEADER_MAX_SIZE = 11;
    const uint SIZE_PER_POINT = 16;
    const uint INSURANCE = 20;
    return HEADER_MAX_SIZE + SIZE_PER_POINT*points*pow(double(ports), 2.0) + INSURANCE;
}
