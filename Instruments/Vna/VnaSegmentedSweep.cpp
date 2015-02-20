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
    return(points);
}

double VnaSegmentedSweep::start_Hz() {
    return(min(frequencies_Hz()));
}
double VnaSegmentedSweep::stop_Hz() {
    return(max(frequencies_Hz()));
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
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaSegmentedSweep::setPower(double power_dBm) {
    QString scpi = ":SOUR%1:POW %2\n";
    scpi = scpi.arg(_channelIndex).arg(power_dBm);
    _vna->write(scpi);
}
double VnaSegmentedSweep::ifBandwidth_Hz() {
    QString scpi = QString("SENS%1:BAND?\n").arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
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
    return(_vna->query(scpi).trimmed().toUInt());
}
uint VnaSegmentedSweep::addSegment() {
    uint index = segments() + 1;
    QString scpi = ":SENS%1:SEGM%2:ADD\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(index);
    _vna->write(scpi);
    return(index);
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
    return(*_segment.data());
}

QVector<uint> VnaSegmentedSweep::sParameterGroup() {
    return(_channel->linearSweep().sParameterGroup());
}
void VnaSegmentedSweep::setSParameterGroup(QVector<uint> ports) {
    _channel->linearSweep().setSParameterGroup(ports);
}
void VnaSegmentedSweep::clearSParameterGroup() {
    _channel->linearSweep().clearSParameterGroup();
}
ComplexMatrix3D VnaSegmentedSweep::readSParameterGroup() {
    return(_channel->linearSweep().readSParameterGroup());
}
uint VnaSegmentedSweep::sweepTime_ms() {
    QString scpi = ":SENS%1:SEGM:SWE:TIME:SUM?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toUInt();
}

NetworkData VnaSegmentedSweep::measure(uint port1) {
    QVector<uint> ports;
    ports << port1;
    return(measure(ports));
}
NetworkData VnaSegmentedSweep::measure(uint port1, uint port2) {
    QVector<uint> ports;
    ports << port1 << port2;
    return(measure(ports));
}
NetworkData VnaSegmentedSweep::measure(uint port1, uint port2, uint port3) {
    QVector<uint> ports;
    ports << port1 << port2 << port3;
    return(measure(ports));
}
NetworkData VnaSegmentedSweep::measure(uint port1, uint port2, uint port3, uint port4) {
    QVector<uint> ports;
    ports << port1 << port2 << port3 << port4;
    return(measure(ports));
}
NetworkData VnaSegmentedSweep::measure(QVector<uint> ports) {
    return(_channel->linearSweep().measure(ports));
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
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
uint VnaSegmentedSweep::frequencyBufferSize(uint points) {
    const uint SIZE_PER_POINT = 20;
    return(SIZE_PER_POINT * points);
}
