

// RsaToolbox includes
#include "General.h"
#include "VnaLimits.h"
#include "VnaTrace.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>


VnaLimits::VnaLimits(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _trace.reset(new VnaTrace());
    _channel = 0;
}

VnaLimits::VnaLimits(const VnaLimits &other) :
    QObject(other.parent())
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _trace.reset(new VnaTrace(*other._trace.data()));
        _channel = other._channel;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _trace.reset(new VnaTrace());
        _channel = 0;
    }
}
VnaLimits::VnaLimits(Vna *vna, VnaTrace *trace, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _trace.reset(new VnaTrace(*trace));
    _channel= trace->channel();
}

VnaLimits::VnaLimits(Vna *vna, QString traceName, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _trace.reset(new VnaTrace(vna, traceName));
    _channel = _trace->channel();
}

bool VnaLimits::isOn() {
    _trace->select();
    QString scpi = ":CALC%1:LIM:STAT?\n";
    scpi = scpi.arg(_channel);
    return _vna->query(scpi).trimmed() == "1";
}
bool VnaLimits::isOff() {
    return !isOn();
}
void VnaLimits::on(bool isOn) {
    _trace->select();
    QString scpi = ":CALC%1:LIM:STAT %2\n";
    scpi = scpi.arg(_channel);
    if (isOn)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
void VnaLimits::off(bool isOff) {
    on(!isOff);
}
bool VnaLimits::isPass() {
    return !isFail();
}
bool VnaLimits::isFail() {
    _trace->select();
    QString scpi = ":CALC%1:LIM:FAIL?\n";
    scpi = scpi.arg(_channel);
    return _vna->query(scpi).trimmed() == "1";
}

bool VnaLimits::isVisible() {
    _trace->select();
    QString scpi = ":CALC%1:LIM:DISP?\n";
    scpi = scpi.arg(_channel);
    return _vna->query(scpi).trimmed() == "1";
}
bool VnaLimits::isHidden() {
    return !isVisible();
}
void VnaLimits::show(bool isVisible) {
    _trace->select();
    QString scpi = ":CALC%1:LIM:DISP %2\n";
    scpi = scpi.arg(_channel);
    if (isVisible)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
void VnaLimits::hide(bool isHidden) {
    show(!isHidden);
}

void VnaLimits::setUpper(QString trace, double xOffset, double yOffset) {
    _trace->select();
    QString scpi = ":CALC%1:LIM:UPP:FEED %2,%3,\'%4\'\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(xOffset);
    scpi = scpi.arg(yOffset);
    scpi = scpi.arg(trace);
    _vna->write(scpi);
}
void VnaLimits::setUpper(QRowVector frequencies_Hz, QRowVector values) {
    uint channel = _vna->createChannel();
    QString name = "__________";
    _vna->createTrace(name, channel);
    _vna->trace(name).write(frequencies_Hz, values);
    setUpper(name, 0, 0);
    _vna->deleteTrace(name);
    _vna->deleteChannel(channel);
}
void VnaLimits::setLower(QString trace, double xOffset, double yOffset) {
    _trace->select();
    QString scpi = ":CALC%1:LIM:UPP:FEED %2,%3,\'%4\'\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(xOffset);
    scpi = scpi.arg(yOffset);
    scpi = scpi.arg(trace);
    _vna->write(scpi);
}
void VnaLimits::setLower(QRowVector frequencies_Hz, QRowVector values) {
    uint channel = _vna->createChannel();
    QString name = "__________";
    _vna->createTrace(name, channel);
    _vna->trace(name).write(frequencies_Hz, values);
    setLower(name, 0, 0);
    _vna->deleteTrace(name);
    _vna->deleteChannel(channel);
}
void VnaLimits::deleteAll() {
    QString scpi = ":CALC%1:LIM:DEL:ALL\n";
    scpi = scpi.arg(_channel);
    _vna->write(scpi);
}

void VnaLimits::operator=(VnaLimits const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _trace.reset(new VnaTrace(other._trace.data()));
        _channel = other._channel;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _trace.reset(new VnaTrace());
        _channel = 0;
    }
}

// Private
bool VnaLimits::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
