

// RsaToolbox includes
#include "General.h"
#include "VnaPowerCorrections.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaPowerCorrections
 * \ingroup VnaGroup
 * \brief The \c %VnaPowerCorrections class
 * controls and queries the measurement
 * corrections applied to a channel.
 */

VnaPowerCorrections::VnaPowerCorrections(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaPowerCorrections::VnaPowerCorrections(VnaPowerCorrections &other)
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
VnaPowerCorrections::VnaPowerCorrections(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}

VnaPowerCorrections::VnaPowerCorrections(Vna *vna, uint channelIndex, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, channelIndex, this));
    _channelIndex = channelIndex;
}
VnaPowerCorrections::~VnaPowerCorrections() {

}


// Calibrated corrections
bool VnaPowerCorrections::isOn(uint port) {
    Q_UNUSED(port);
    return(false);
}
bool VnaPowerCorrections::isOff(uint port) {
    return(!isOn(port));
}
bool VnaPowerCorrections::isPresent(uint port) {
    Q_UNUSED(port);
    return(false);
}
bool VnaPowerCorrections::isNotPresent(uint port) {
    return(!isPresent(port));
}
bool VnaPowerCorrections::isInterpolated(uint port) {
    Q_UNUSED(port);
    return(false);
}
bool VnaPowerCorrections::isNotInterpolated(uint port) {
    return(!isInterpolated(port));
}
void VnaPowerCorrections::on(uint port, bool isOn) {
    Q_UNUSED(port);
    Q_UNUSED(isOn);
}
void VnaPowerCorrections::off(uint port, bool isOff) {
    on(port, !isOff);
}
QString VnaPowerCorrections::calGroup() {
    QString scpi = ":MMEM:LOAD:CORR? %1\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().remove("\'"));
}
void VnaPowerCorrections::setCalGroup(QString calGroup) {
    if (calGroup.contains(".cal", Qt::CaseInsensitive) == false)
        calGroup = calGroup + ".cal";
    QString scpi = ":MMEM:LOAD:CORR %1,\'%2\'\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(calGroup);
    _vna->write(scpi);
}
void VnaPowerCorrections::saveToCalGroup(QString calGroup) {
    if (calGroup.contains(".cal", Qt::CaseInsensitive) == false)
        calGroup = calGroup + ".cal";
    QString scpi = ":MMEM:STOR:CORR %1,\'%2\'\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(calGroup);
    _vna->write(scpi);
}
void VnaPowerCorrections::dissolveCalGroupLink() {
    QString scpi = ":MMEM:LOAD:CORR:RES %1\n";
    scpi = scpi.arg(_channelIndex);
    _vna->write(scpi);
}
void VnaPowerCorrections::clear() {
//    _vna->fileSystem().uploadFile();
//    _vna->importCalGroup("DELETE");
//    setCalGroup("DELETE");
//    dissolveCalGroupLink();
//    _vna->deleteCalGroup("DELETE");
} //?


void VnaPowerCorrections::operator=(VnaPowerCorrections const &other) {
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

// Private
bool VnaPowerCorrections::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
VnaPowerCorrections::CorrectionState VnaPowerCorrections::correctionState(uint port) {
    Q_UNUSED(port);
    return(NO_CORRECTIONS);
}
VnaPowerCorrections::CorrectionState VnaPowerCorrections::toCorrectionState(QString scpi) {
    Q_UNUSED(scpi);
    return(NO_CORRECTIONS);
}
