

// RsaToolbox includes
#include "General.h"
#include "VnaTrigger.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
#include <QString>


VnaTrigger::VnaTrigger(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaTrigger::VnaTrigger(const VnaTrigger &other)
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
VnaTrigger::VnaTrigger(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}

VnaTrigger::VnaTrigger(Vna *vna, uint channelIndex, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, channelIndex, this));
    _channelIndex = channelIndex;
}
VnaTrigger::~VnaTrigger() {

}

VnaTriggerSource VnaTrigger::source() {
    QString scpi = ":TRIG%1:SOUR?\n";
    scpi = scpi.arg(_channelIndex);
    return vnaTriggerSourceFromScpi(_vna->query(scpi));
}
void VnaTrigger::setSource(VnaTriggerSource source) {
    QString scpi = ":TRIG:SOUR %1\n";
    scpi = scpi.arg(toScpi(source));
    _vna->write(scpi);
}

void VnaTrigger::manualTrigger() {
    QString scpi = "*TRG\n";
    _vna->write(scpi);
}

bool VnaTrigger::isOnPositiveEdge() {
    QString scpi = ":TRIG%1:SLOP?\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = _vna->query(scpi).trimmed();
    return scpi.startsWith("POS", Qt::CaseInsensitive);
}
void VnaTrigger::setOnPositiveEdge(bool positive) {
    QString scpi = ":TRIG%1:SLOP %2\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(positive? "POS" : "NEG");
    _vna->write(scpi);
}

VnaTrigger::Sequence VnaTrigger::sequence() {
    QString scpi = ":TRIG%1:LINK?\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = _vna->query(scpi).trimmed().remove("\'");
    return vnaTriggerSequenceFromScpi(scpi);
}
void VnaTrigger::setSequence(Sequence sequence) {
    QString scpi = ":TRIG%1:LINK \'%2\'\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(toScpi(sequence));
    _vna->write(scpi);
}

double VnaTrigger::delay_s() {
    QString scpi = ":TRIG%1:HOLD?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaTrigger::setDelay(double time, SiPrefix prefix) {
    QString scpi = ":TRIG%1:HOLD %2\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(time);
    if (prefix != SiPrefix::None) {
        const QString units = toString(prefix, Units::Seconds);
        scpi = scpi.trimmed();
        scpi = QString("%1 %2\n").arg(scpi).arg(units);
    }
    _vna->write(scpi);
}

void VnaTrigger::operator=(VnaTrigger const &other) {
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
bool VnaTrigger::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
