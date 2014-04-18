#include <QDebug>

// RsaToolbox includes
#include "General.h"
#include "VnaPowerSweep.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaPowerSweep
 * \ingroup VnaGroup
 * \brief The \c %VnaPowerSweep class
 * configures and controls a power
 * sweep with linearly-spaced
 * measurement points.
 */

VnaPowerSweep::VnaPowerSweep(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaPowerSweep::VnaPowerSweep(VnaPowerSweep &other)
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
VnaPowerSweep::VnaPowerSweep(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}
VnaPowerSweep::VnaPowerSweep(Vna *vna, uint index, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, index, this));
    _channelIndex = index;
}


uint VnaPowerSweep::points() {
    QString scpi = ":SENS%1:SWE:POIN?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toUInt());
}
void VnaPowerSweep::setPoints(uint numberOfPoints) {
    QString scpi = ":SENS%1:SWE:POIN %2\n";
    scpi = scpi.arg(_channelIndex).arg(numberOfPoints);
    _vna->write(scpi);
}
double VnaPowerSweep::start_dBm() {
    QString scpi = "SOUR%1:POW:STAR?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaPowerSweep::setStart(double power_dBm) {
    QString scpi = "SOUR%1:POW:STAR %2\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(power_dBm);
    _vna->write(scpi);
}
double VnaPowerSweep::stop_dBm() {
    QString scpi = "SOUR%1:POW:STOP?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaPowerSweep::setStop(double power_dBm) {
    QString scpi = "SOUR%1:POW:STOP %2\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(power_dBm);
    _vna->write(scpi);
}
QVector<double> VnaPowerSweep::powers_dBm() {
    return(QVector<double>());
}
double VnaPowerSweep::frequency_Hz() {
    QString scpi = ":SOUR%1:FREQ?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaPowerSweep::setFrequency(double frequency, SiPrefix prefix) {
    QString scpi = ":SOUR%1:FREQ %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(frequency).arg(toString(prefix, HERTZ_UNITS));
    _vna->write(scpi);
}
double VnaPowerSweep::ifBandwidth_Hz() {
    QString scpi = "SENS%1:BAND?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaPowerSweep::setIfbandwidth(double bandwidth, SiPrefix prefix) {
    QString scpi = "SENS%1:BAND %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(bandwidth);
    scpi = scpi.arg(toString(prefix, HERTZ_UNITS));
    _vna->write(scpi);
}

void VnaPowerSweep::operator=(VnaPowerSweep const &other) {
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

//void VnaPowerSweep::moveToThread(QThread *thread) {
//    QObject::moveToThread(thread);
//    if (_channel.isNull() == false)
//        _channel->moveToThread(thread);
//}

// Private
bool VnaPowerSweep::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
