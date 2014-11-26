

// RsaToolbox includes
#include "General.h"
#include "VnaTimeSweep.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaTimeSweep
 * \ingroup VnaGroup
 * \brief The \c %VnaTimeSweep class
 * configures and controls a measurement
 * conducted over a configurable
 * period of time.
 */

VnaTimeSweep::VnaTimeSweep(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaTimeSweep::VnaTimeSweep(VnaTimeSweep &other)
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
VnaTimeSweep::VnaTimeSweep(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}

VnaTimeSweep::VnaTimeSweep(Vna *vna, uint channelIndex, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, channelIndex));
    _channelIndex = channelIndex;
}
VnaTimeSweep::~VnaTimeSweep() {

}


uint VnaTimeSweep::points() {
    QString scpi = ":SENS%1:SWE:POIN?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toUInt());
}
void VnaTimeSweep::setPoints(uint numberOfPoints) {
    QString scpi = ":SENS%1:SWE:POIN %2\n";
    scpi = scpi.arg(_channelIndex).arg(numberOfPoints);
    _vna->write(scpi);
}
double VnaTimeSweep::frequency_Hz() {
    QString scpi = ":SOUR%1:FREQ?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaTimeSweep::setFrequency(double frequency, SiPrefix prefix) {
    QString scpi = ":SOUR%1:FREQ %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(frequency).arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}
double VnaTimeSweep::power_dBm() {
    QString scpi = ":SOUR%1:POW?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaTimeSweep::setPower(double power_dBm) {
    QString scpi = ":SOUR%1:POW %2\n";
    scpi = scpi.arg(_channelIndex).arg(power_dBm);
    _vna->write(scpi);
}
double VnaTimeSweep::ifBandwidth_Hz() {
    QString scpi = QString("SENS%1:BAND?\n").arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaTimeSweep::setIfBandwidth(double bandwidth, SiPrefix prefix) {
    QString scpi = "SENS%1:BAND %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(bandwidth);
    scpi = scpi.arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}
double VnaTimeSweep::time_s() {
    QString scpi = QString("SENS%1:SWE:TIME?\n").arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaTimeSweep::setTime(double time, SiPrefix prefix) {
    QString scpi = "SENS%1:SWE:TIME %2\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(time * toDouble(prefix));
    _vna->write(scpi);
}


void VnaTimeSweep::operator=(VnaTimeSweep const &other) {
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

//void VnaTimeSweep::moveToThread(QThread *thread) {
//    QObject::moveToThread(thread);
//    if (_channel.isNull() == false)
//        _channel->moveToThread(thread);
//}

// Private
bool VnaTimeSweep::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
