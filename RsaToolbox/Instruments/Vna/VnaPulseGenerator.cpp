

// RsaToolbox includes
#include "General.h"
#include "VnaPulseGenerator.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
#include <QString>


VnaPulseGenerator::VnaPulseGenerator(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaPulseGenerator::VnaPulseGenerator(const VnaPulseGenerator &other)
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
VnaPulseGenerator::VnaPulseGenerator(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}

VnaPulseGenerator::VnaPulseGenerator(Vna *vna, uint channelIndex, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, channelIndex, this));
    _channelIndex = channelIndex;
}
VnaPulseGenerator::~VnaPulseGenerator() {

}

bool VnaPulseGenerator::isOn() {
    QString scpi = ":SENS%1:PULS:GEN1?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed() == "1";
}
void VnaPulseGenerator::on(bool isOn) {
    QString scpi;
    if (isOn)
        scpi = ":SENS%1:PULS:GEN1 1\n";
    else
        scpi = ":SENS%1:PULS:GEN1 0\n";
    scpi = scpi.arg(_channelIndex);
    _vna->write(scpi);
}
void VnaPulseGenerator::off(bool isOff) {
    on(!isOff);
}

double VnaPulseGenerator::delay_s() {
    QString scpi = ":SENS%1:PULS:GEN1:DEL?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaPulseGenerator::setDelay(double value, SiPrefix prefix) {
    QString scpi = ":SENS%1:PULS:GEN1:DEL %2\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(value);
    if (prefix != SiPrefix::None)
        scpi = scpi + " " + toString(prefix, Units::Seconds);
    _vna->write(scpi);
}

double VnaPulseGenerator::pulseWidth_s() {
    QString scpi = ":SENS%1:PULS:GEN1:WIDT?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaPulseGenerator::setPulseWidth(double value, SiPrefix prefix) {
    QString scpi = ":SENS%1:PULS:GEN1:WIDT %2\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(value);
    if (prefix != SiPrefix::None)
        scpi = scpi + " " + toString(prefix, Units::Seconds);
    _vna->write(scpi);
}

double VnaPulseGenerator::period_s() {
    QString scpi = ":SENS%1:PULS:GEN1:PER?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaPulseGenerator::setPeriod(double value, SiPrefix prefix) {
    QString scpi = ":SENS%1:PULS:GEN1:PER %2\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(value);
    if (prefix != SiPrefix::None)
        scpi = scpi + " " + toString(prefix, Units::Seconds);
    _vna->write(scpi);
}

void VnaPulseGenerator::operator=(VnaPulseGenerator const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _channel.reset(new VnaChannel(other._channel.data()));
        _channelIndex = other._channelIndex;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
    }
}

// Private
bool VnaPulseGenerator::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
