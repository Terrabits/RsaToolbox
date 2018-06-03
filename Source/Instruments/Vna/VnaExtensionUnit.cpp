

// RsaToolbox includes
#include "General.h"
#include "VnaExtensionUnit.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>


VnaExtensionUnit::VnaExtensionUnit(QObject *parent) :
    QObject(parent)
{
    _placeholder.reset(new Vna());
    _vna = _placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaExtensionUnit::VnaExtensionUnit(const VnaExtensionUnit &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _channel.reset(new VnaChannel(*other._channel.data()));
        _channelIndex = other._channelIndex;
    }
    else {
        _placeholder.reset(new Vna());
        _vna = _placeholder.data();
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
    }
}
VnaExtensionUnit::VnaExtensionUnit(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}

VnaExtensionUnit::VnaExtensionUnit(Vna *vna, uint channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, channel, this));
    _channelIndex = channel;
}
VnaExtensionUnit::~VnaExtensionUnit() {

}

QString VnaExtensionUnit::idString() {
    QString scpi = ":SYST:COMM:RDEV:TEUN:IDN?\n";
    return _vna->query(scpi).trimmed();
}
QStringList VnaExtensionUnit::options() {
    QString scpi = ":SYST:COMM:RDEV:TEUN:OPT?\n";
    return _vna->query(scpi).trimmed().split(",", QString::SkipEmptyParts);
}

bool VnaExtensionUnit::isPulseModulatorOn(uint path) {
    QString scpi = ":SENS%1:PULS:GEN%2?\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(path);
    return _vna->query(scpi).trimmed() == "1";
}
void VnaExtensionUnit::pulseModulatorOn(uint path, bool isOn) {
    QString scpi;
    if (isOn)
        scpi = ":SENS%1:PULS:GEN%2 1\n";
    else
        scpi = ":SENS%1:PULS:GEN%2 0\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(path);
    _vna->write(scpi);
}
void VnaExtensionUnit::pulseModulatorOff(uint path, bool isOff) {
    pulseModulatorOn(path, !isOff);
}

void VnaExtensionUnit::operator=(VnaExtensionUnit const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _channel.reset(new VnaChannel(other._channel.data()));
        _channelIndex = other._channelIndex;
    }
    else {
        _placeholder.reset(new Vna());
        _vna = _placeholder.data();
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
    }
}

// Private
bool VnaExtensionUnit::isFullyInitialized() const {
    if (!_vna) {
        return false;
    }
    if (_vna == _placeholder.data()) {
        return false;
    }

    return true;
}
