

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
    _vna          = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaPulseGenerator::VnaPulseGenerator(const VnaPulseGenerator &other)
{
    if (other.isFullyInitialized()) {
        _vna          = other._vna;
        _channel.reset(new VnaChannel(*other._channel.data()));
        _channelIndex = other._channelIndex;
    }
    else {
        placeholder.reset(new Vna());
        _vna          = placeholder.data();
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
    }
}
VnaPulseGenerator::VnaPulseGenerator(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna          = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}

VnaPulseGenerator::VnaPulseGenerator(Vna *vna, uint channelIndex, QObject *parent) :
    QObject(parent)
{
    _vna          = vna;
    _channel.reset(new VnaChannel(vna, channelIndex, this));
    _channelIndex = channelIndex;
}
VnaPulseGenerator::~VnaPulseGenerator() {

}

bool VnaPulseGenerator::isOn() {
    QString scpi = ":SENS%1:PULS:GEN?\n";
    scpi         = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed() == "1";
}
void VnaPulseGenerator::on(bool isOn) {
    QString scpi = ":SENS%1:PULS:GEN %2\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(isOn? "1" : "0");
    _vna->write(scpi);
}
void VnaPulseGenerator::off(bool isOff) {
    on(!isOff);
}

VnaPulseType VnaPulseGenerator::type() {
    QString type = ":SENS%1:PULS:GEN1:TYPE?\n";
            type = type.arg(_channelIndex);
            type = _vna->query(type).trimmed();
    return vnaPulseTypeFromScpi(type);
}
void VnaPulseGenerator::setType(VnaPulseType type) {
    QString scpi = ":SENS%1:PULS:GEN1:TYPE %2\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(toScpi(type));
    _vna->write(scpi);
}

double VnaPulseGenerator::pulseWidth_s() {
    QString scpi = ":SENS%1:PULS:GEN1:WIDT?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaPulseGenerator::setPulseWidth(double value, SiPrefix prefix) {
    QString scpi = ":SENS%1:PULS:GEN1:WIDT %2 %3\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(value);
    scpi         = scpi.arg(toString(prefix, Units::Seconds));
    _vna->write(scpi);
}

double VnaPulseGenerator::period_s() {
    QString scpi = ":SENS%1:PULS:GEN1:PER?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaPulseGenerator::setPeriod(double value, SiPrefix prefix) {
    QString scpi = ":SENS%1:PULS:GEN1:PER %2 %3\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(value);
    scpi         = scpi.arg(toString(prefix, Units::Seconds));
    _vna->write(scpi);
}

bool VnaPulseGenerator::isInverted() {
    QString scpi = ":SENS%1:PULS:GEN1:POL?\n";
    scpi         = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed() == "INV";
}
void VnaPulseGenerator::setInverted(bool isInverted) {
    QString scpi = ":SENS%1:PULS:GEN1:POL %2\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(isInverted? "INV" : "NORM");
    _vna->write(scpi);
}

bool VnaPulseGenerator::isChannelSpecific() {
    QString scpi = "SENS%1:PULS:GEN1:MODE?\n";
    scpi         = scpi.arg(_channelIndex);
    const QString result = _vna->query(scpi).trimmed();
    return result.startsWith("CSP", Qt::CaseInsensitive);
}
void VnaPulseGenerator::setChannelSpecific(bool isSpecific) {
    QString scpi = "SENS%1:PULS:GEN1:MODE %2\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(isSpecific? "CSP" : "CONT");
    _vna->write(scpi);
}

void VnaPulseGenerator::operator=(VnaPulseGenerator const &other) {
    if (other.isFullyInitialized()) {
        _vna          = other._vna;
        _channel.reset(new VnaChannel(*other._channel.data()));
        _channelIndex = other._channelIndex;
    }
    else {
        placeholder.reset(new Vna());
        _vna          = placeholder.data();
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
