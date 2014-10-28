#include <QDebug>

// RsaToolbox includes
#include "General.h"
#include "VnaLogSweep.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaLogSweep
 * \ingroup VnaGroup
 * \brief The \c %VnaLogSweep class
 * configures and controls a frequency
 * sweep with logarithmically-spaced
 * measurement points.
 */

VnaLogSweep::VnaLogSweep(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaLogSweep::VnaLogSweep(VnaLogSweep &other)
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
VnaLogSweep::VnaLogSweep(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}
VnaLogSweep::VnaLogSweep(Vna *vna, uint index, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, index, this));
    _channelIndex = index;
}


uint VnaLogSweep::points() {
    QString scpi = ":SENS%1:SWE:POIN?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toUInt());
}
void VnaLogSweep::setPoints(uint numberOfPoints) {
    QString scpi = ":SENS%1:SWE:POIN %2\n";
    scpi = scpi.arg(_channelIndex).arg(numberOfPoints);
    _vna->write(scpi);
}
double VnaLogSweep::start_Hz() {
    QString scpi = ":SENS%1:FREQ:STAR?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaLogSweep::setStart(double frequency, SiPrefix prefix) {
    QString scpi = ":SENS%1:FREQ:STAR %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(frequency).arg(toString(prefix, HERTZ_UNITS));
    _vna->write(scpi);
}
double VnaLogSweep::stop_Hz() {
    QString scpi = ":SENS%1:FREQ:STOP?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaLogSweep::setStop(double frequency, SiPrefix prefix) {
    QString scpi = ":SENS%1:FREQ:STOP %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(frequency).arg(toString(prefix, HERTZ_UNITS));
    _vna->write(scpi);
}
QVector<double> VnaLogSweep::frequencies_Hz() {
    QString scpi = ":CALC%1:DATA:STIM?\n";
    scpi = scpi.arg(_channelIndex);
    uint bufferSize = frequencyBufferSize(points());
    return(parseQRowVector(_vna->query(scpi, bufferSize).trimmed()));
}
double VnaLogSweep::power_dBm() {
    QString scpi = ":SOUR%1:POW?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaLogSweep::setPower(double power_dBm) {
    QString scpi = ":SOUR%1:POW %2\n";
    scpi = scpi.arg(_channelIndex).arg(power_dBm);
    _vna->write(scpi);
}
double VnaLogSweep::ifBandwidth_Hz() {
    QString scpi = "SENS%1:BAND?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaLogSweep::setIfbandwidth(double bandwidth, SiPrefix prefix) {
    QString scpi = "SENS%1:BAND %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(bandwidth);
    scpi = scpi.arg(toString(prefix, HERTZ_UNITS));
    _vna->write(scpi);
}

QVector<uint> VnaLogSweep::sParameterGroup() {
    return(_channel->linearSweep().sParameterGroup());
}
void VnaLogSweep::setSParameterGroup(QVector<uint> ports) {
    _channel->linearSweep().setSParameterGroup(ports);
}
void VnaLogSweep::clearSParameterGroup() {
    _channel->linearSweep().clearSParameterGroup();
}
ComplexMatrix3D VnaLogSweep::readSParameterGroup() {
    return(_channel->linearSweep().readSParameterGroup());
}

NetworkData VnaLogSweep::measure(uint port1) {
    QVector<uint> ports;
    ports << port1;
    return(measure(ports));
}
NetworkData VnaLogSweep::measure(uint port1, uint port2) {
    QVector<uint> ports;
    ports << port1 << port2;
    return(measure(ports));
}
NetworkData VnaLogSweep::measure(uint port1, uint port2, uint port3) {
    QVector<uint> ports;
    ports << port1 << port2 << port3;
    return(measure(ports));
}
NetworkData VnaLogSweep::measure(uint port1, uint port2, uint port3, uint port4) {
    QVector<uint> ports;
    ports << port1 << port2 << port3 << port4;
    return(measure(ports));
}
NetworkData VnaLogSweep::measure(QVector<uint> ports) {
    return(_channel->linearSweep().measure(ports));
}

void VnaLogSweep::operator=(VnaLogSweep const &other) {
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

//void VnaLogSweep::moveToThread(QThread *thread) {
//    QObject::moveToThread(thread);
//    if (_channel.isNull() == false)
//        _channel->moveToThread(thread);
//}

// Private
bool VnaLogSweep::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
uint VnaLogSweep::frequencyBufferSize(uint points) {
    const uint SIZE_PER_POINT = 20;
    return(SIZE_PER_POINT * points);
}
