

// RsaToolbox includes
#include "General.h"
#include "VnaPowerCalibrate.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaPowerCalibrate
 * \ingroup VnaGroup
 * \brief The \c %VnaPowerCalibrate class
 * is used to perform calibration.
 */

VnaPowerCalibrate::VnaPowerCalibrate(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _isChannelSpecific = false;
    _channelIndex = 0;
}
VnaPowerCalibrate::VnaPowerCalibrate(VnaPowerCalibrate &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _isChannelSpecific = other._isChannelSpecific;
        if (_isChannelSpecific) {
            _channel.reset(new VnaChannel(*other._channel.data()));
            _channelIndex = other._channelIndex;
        }
        else {
            _channelIndex = 0;
        }
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _isChannelSpecific = false;
        _channelIndex = 0;
    }
}
VnaPowerCalibrate::VnaPowerCalibrate(Vna *vna, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _isChannelSpecific = false;
    _channelIndex = 0;
}
VnaPowerCalibrate::VnaPowerCalibrate(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _isChannelSpecific = true;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}
VnaPowerCalibrate::VnaPowerCalibrate(Vna *vna, uint channelIndex, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _isChannelSpecific = true;
    _channel.reset(new VnaChannel(vna, channelIndex, this));
    _channelIndex = channelIndex;
}

bool VnaPowerCalibrate::isRawDataKept() {
    return(false);
}

void VnaPowerCalibrate::setConnector(uint port, Connector connector) {
    Q_UNUSED(port);
    Q_UNUSED(connector);
}
void VnaPowerCalibrate:: setConnectors(Connector connector) {
    Q_UNUSED(connector);
}

Connector VnaPowerCalibrate:: connector(uint port) {
    Q_UNUSED(port);
    return(Connector());
}
QVector<Connector> VnaPowerCalibrate:: connectors() {
    return(QVector<Connector>());
}

void VnaPowerCalibrate:: start(QString calibrationName, uint port) {
    Q_UNUSED(calibrationName);
    Q_UNUSED(port);
}
void VnaPowerCalibrate:: keepRawData(bool isKept) {
    Q_UNUSED(isKept);
}
void VnaPowerCalibrate:: apply() {

}

void VnaPowerCalibrate::operator=(VnaPowerCalibrate const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _isChannelSpecific = other._isChannelSpecific;
        _channel.reset(new VnaChannel(*other._channel.data()));
        _channelIndex = other._channelIndex;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _isChannelSpecific = false;
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
    }
}

// Private
bool VnaPowerCalibrate::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}

void VnaPowerCalibrate::selectChannels() {

}
