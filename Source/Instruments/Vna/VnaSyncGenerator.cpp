

// RsaToolbox includes
#include "General.h"
#include "VnaSyncGenerator.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
#include <QString>


VnaSyncGenerator::VnaSyncGenerator(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna          = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaSyncGenerator::VnaSyncGenerator(const VnaSyncGenerator &other)
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
VnaSyncGenerator::VnaSyncGenerator(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna          = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}

VnaSyncGenerator::VnaSyncGenerator(Vna *vna, uint channelIndex, QObject *parent) :
    QObject(parent)
{
    _vna          = vna;
    _channel.reset(new VnaChannel(vna, channelIndex, this));
    _channelIndex = channelIndex;
}
VnaSyncGenerator::~VnaSyncGenerator() {

}

bool VnaSyncGenerator::isOn() {
    QString scpi = ":SENS%1:PULS:GEN?\n";
    scpi         = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed() == "1";
}
void VnaSyncGenerator::on(bool isOn) {
    QString scpi = ":SENS%1:PULS:GEN %2\n";
    scpi.arg(_channelIndex);
    scpi.arg(isOn? "1" : "0");
    scpi = scpi.arg(_channelIndex);
    _vna->write(scpi);
}
void VnaSyncGenerator::off(bool isOff) {
    on(!isOff);
}

VnaPulseType VnaSyncGenerator::type() {
    QString type = ":SENS%1:PULS:GEN2:TYPE?\n";
            type = type.arg(_channelIndex);
            type = _vna->query(type).trimmed();
    return vnaPulseTypeFromScpi(type);
}
void VnaSyncGenerator::setType(VnaPulseType type) {
    QString scpi = ":SENS%1:PULS:GEN2:TYPE %2\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(toScpi(type));
    _vna->write(scpi);
}

double VnaSyncGenerator::pulseWidth_s() {
    QString scpi = ":SENS%1:PULS:GEN2:WIDT?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaSyncGenerator::setPulseWidth(double value, SiPrefix prefix) {
    QString scpi = ":SENS%1:PULS:GEN2:WIDT %2\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(value);
    if (prefix != SiPrefix::None) {
        const QString units = toString(prefix, Units::Seconds);
        scpi = QString("%1 %2").arg(scpi).arg(units);
    }
    _vna->write(scpi);
}

double VnaSyncGenerator::period_s() {
    QString scpi = ":SENS%1:PULS:GEN2:PER?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaSyncGenerator::setPeriod(double value, SiPrefix prefix) {
    QString scpi = ":SENS%1:PULS:GEN2:PER %2\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(value);
    if (prefix != SiPrefix::None) {
        const QString units = toString(prefix, Units::Seconds);
        scpi = QString("%1 %2").arg(scpi).arg(units);
    }
    _vna->write(scpi);
}

bool VnaSyncGenerator::isInverted() {
    QString scpi = ":SENS%1:PULS:GEN2:POL?\n";
    scpi         = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed() == "1";
}
void VnaSyncGenerator::setInverted(bool isInverted) {
    QString scpi = ":SENS%1:PULS:GEN2:POL %2\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(isInverted? "INV" : "NORM");
    _vna->write(scpi);
}

bool VnaSyncGenerator::isChannelSpecific() {
    QString scpi = "SENS%1:PULS:GEN2:MODE?\n";
    scpi         = scpi.arg(_channelIndex);
    const QString result = _vna->query(scpi).trimmed();
    return result.startsWith("CSP", Qt::CaseInsensitive);
}
void VnaSyncGenerator::setChannelSpecific(bool isSpecific) {
    QString scpi = "SENS%1:PULS:GEN2:MODE %2\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(isSpecific? "CSP" : "CONT");
    _vna->write(scpi);
}

void VnaSyncGenerator::operator=(VnaSyncGenerator const &other) {
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
bool VnaSyncGenerator::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
