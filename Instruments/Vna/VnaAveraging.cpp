

// RsaToolbox includes
#include "General.h"
#include "VnaAveraging.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>


VnaAveraging::VnaAveraging(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaAveraging::VnaAveraging(const VnaAveraging &other) :
    QObject(other.parent())
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
VnaAveraging::VnaAveraging(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}

VnaAveraging::VnaAveraging(Vna *vna, uint channelIndex, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, channelIndex, this));
    _channelIndex = channelIndex;
}

bool VnaAveraging::isOn() {
    QString scpi = ":SENS%1:AVER?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi) == "1");
}
bool VnaAveraging::isOff() {
    return(!isOn());
}
void VnaAveraging::on(bool isOn) {
    QString scpi = ":SENS%1:AVER %2\n";
    scpi = scpi.arg(_channelIndex);
    if (isOn)
        scpi = scpi.arg("1");
    else
        scpi = scpi.arg("0");
    _vna->write(scpi);
}
void VnaAveraging::off(bool isOff) {
    on(!isOff);
}
void VnaAveraging::reset() {
    QString scpi = ":SENS%1:AVER:CLE\n";
    scpi = scpi.arg(_channelIndex);
    _vna->write(scpi);
}
void VnaAveraging::setNumber(uint numberOfAverages) {
    QString scpi = ":SENS%1:AVER:COUN %2\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(numberOfAverages);
    _vna->write(scpi);
}
uint VnaAveraging::number() {
    QString scpi = ":SENS%1:AVER:COUN?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).toUInt());
}

void VnaAveraging::operator=(VnaAveraging const &other) {
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
bool VnaAveraging::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
