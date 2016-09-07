#include <QDebug>

// RsaToolbox includes
#include "General.h"
#include "VnaSweepSegment.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaSweepSegment
 * \ingroup VnaGroup
 * \brief The \c %VnaSweepSegment class
 * manipulates a particular sweep segment
 * that will be used in a segmented sweep
 * measurement.
 */

VnaSweepSegment::VnaSweepSegment(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaSweepSegment::VnaSweepSegment(VnaSweepSegment &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _channel.reset(new VnaChannel(*other._channel.data()));
        _channelIndex = other._channelIndex;
        _segmentIndex = other._segmentIndex;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
        _segmentIndex = 0;
    }
}
VnaSweepSegment::VnaSweepSegment(Vna *vna, VnaChannel *channel, uint index, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
    _segmentIndex = index;
}
VnaSweepSegment::VnaSweepSegment(Vna *vna, uint channelIndex, uint segmentIndex, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, channelIndex, this));
    _channelIndex = channelIndex;
    _segmentIndex = segmentIndex;
}
VnaSweepSegment::~VnaSweepSegment() {

}


bool VnaSweepSegment::isOn() {
    return(false);
}
bool VnaSweepSegment::isOff() {
    return(!isOn());
}
void VnaSweepSegment::on() {

}
void VnaSweepSegment::off() {

}
uint VnaSweepSegment::points() {
    QString scpi = ":SENS%1:SEGM%2:SWE:POIN?\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(_segmentIndex);
    return(_vna->query(scpi).trimmed().toUInt());
}
void VnaSweepSegment::setPoints(uint numberOfPoints) {
    QString scpi = ":SENS%1:SEGM%2:SWE:POIN %3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(_segmentIndex);
    scpi = scpi.arg(numberOfPoints);
    _vna->write(scpi);
}
double VnaSweepSegment::start_Hz() {
    QString scpi = ":SENS%1:SEGM%2:FREQ:STAR?\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(_segmentIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaSweepSegment::setStart(double frequency, SiPrefix prefix) {
    QString scpi = ":SENS%1:SEGM%2:FREQ:STAR %3%4\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(_segmentIndex);
    scpi = scpi.arg(formatDouble(frequency, 12));
    scpi = scpi.arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}
double VnaSweepSegment::stop_Hz() {
    QString scpi = ":SENS%1:SEGM%2:FREQ:STOP?\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(_segmentIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaSweepSegment::setStop(double frequency, SiPrefix prefix) {
    QString scpi = ":SENS%1:SEGM%2:FREQ:STOP %3%4\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(_segmentIndex);
    scpi = scpi.arg(formatDouble(frequency, 12)); // Do not truncate!
    scpi = scpi.arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}
void VnaSweepSegment::setSingleFrequency(double frequency, SiPrefix prefix) {
    setPoints(1);
    setStart(frequency, prefix);
    setStop(frequency, prefix);
}

double VnaSweepSegment::power_dBm() {
    // [SENSe<Ch>:]SEGMent<Seg>:POWer[:LEVel] <IntSourcePow>
    QString scpi = "SENS%1:SEGM%2:POW?";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(_segmentIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaSweepSegment::setPower(double power_dBm) {
    // [SENSe<Ch>:]SEGMent<Seg>:POWer[:LEVel] <IntSourcePow>
    QString scpi = "SENS%1:SEGM%2:POW %3";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(_segmentIndex);
    scpi = scpi.arg(power_dBm);
    _vna->write(scpi);
}

void VnaSweepSegment::operator=(VnaSweepSegment const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _channel.reset(new VnaChannel(*other._channel.data()));
        _channelIndex = _channel->index();
        _segmentIndex = other._segmentIndex;
    }
    else {
        _vna = placeholder.data();
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
        _segmentIndex = 0;
    }
}

// Private
bool VnaSweepSegment::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
