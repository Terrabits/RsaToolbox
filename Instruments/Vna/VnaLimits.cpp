

// RsaToolbox includes
#include "General.h"
#include "VnaLimits.h"
#include "VnaTrace.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
#include <QDebug>


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
VnaLimits::~VnaLimits() {

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
    if (_vna->channel(_channel).isManualSweep())
        _vna->channel(_channel).startSweep();
    _vna->wait();
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
    QString scpi = ":CALC%1:LIM:UPP:FEED %2,%3,\'%4\'\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(xOffset);
    scpi = scpi.arg(yOffset);
    scpi = scpi.arg(trace);

    _trace->select();
    _vna->write(scpi);
    show();
    on();
}
void VnaLimits::addUpper(QRowVector frequencies_Hz, ComplexRowVector values) {
    QRowVector v;
    switch (_trace->format()) {
    case TraceFormat::DecibelMagnitude:
        v = toDb(values);
        break;
    case TraceFormat::Phase:
        v = angle_deg(values);
        break;
    case TraceFormat::Vswr:
        v = toVswr(values);
        break;
    case TraceFormat::UnwrappedPhase:
        v = unwrap(angle_deg(values));
        break;
    case TraceFormat::Magnitude:
        v = toMagnitude(values);
        break;
    case TraceFormat::Real:
        v = real(values);
        break;
    case TraceFormat::Imaginary:
        v = imaginary(values);
        break;
    default:
        return;
    }
    addUpper(frequencies_Hz, v);
}
void VnaLimits::addUpper(QRowVector f, QRowVector v) {
    int points = v.size();
    if (f.size() != points)
        return;
    if (points < 2)
        return;

    QString scpi = ":CALC%1:LIM:DATA ";
    scpi = scpi.arg(_channel);
    QString firstSegment = "1,%1,%2,%3,%4";
    QString nextSegment = "," + firstSegment;
    scpi += firstSegment.arg(f[0]).arg(f[1]).arg(v[0]).arg(v[1]);
    for (int i = 2; i < points; i++)
        scpi += nextSegment.arg(f[i-1]).arg(f[i]).arg(v[i-1]).arg(v[i]);
    scpi += "\n";

    _trace->select();
    _vna->write(scpi);
    show();
    on();
}
void VnaLimits::setLower(QString trace, double xOffset, double yOffset) {
    QString scpi = ":CALC%1:LIM:LOW:FEED %2,%3,\'%4\'\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(xOffset);
    scpi = scpi.arg(yOffset);
    scpi = scpi.arg(trace);

    _trace->select();
    _vna->write(scpi);
    show();
    on();
}
void VnaLimits::addLower(QRowVector frequencies_Hz, ComplexRowVector values) {
    QRowVector v;
    switch (_trace->format()) {
    case TraceFormat::DecibelMagnitude:
        v = toDb(values);
        break;
    case TraceFormat::Phase:
        v = angle_deg(values);
        break;
    case TraceFormat::Vswr:
        v = toVswr(values);
        break;
    case TraceFormat::UnwrappedPhase:
        v = unwrap(angle_deg(values));
        break;
    case TraceFormat::Magnitude:
        v = toMagnitude(values);
        break;
    case TraceFormat::Real:
        v = real(values);
        break;
    case TraceFormat::Imaginary:
        v = imaginary(values);
        break;
    default:
        return;
    }
    addLower(frequencies_Hz, v);
}
void VnaLimits::addLower(QRowVector f, QRowVector v) {
    int points = v.size();
    if (f.size() != points)
        return;
    if (points < 2)
        return;

    QString scpi = ":CALC%1:LIM:DATA ";
    scpi = scpi.arg(_channel);
    QString firstSegment = "2,%1,%2,%3,%4";
    QString nextSegment = "," + firstSegment;
    scpi += firstSegment.arg(f[0]).arg(f[1]).arg(v[0]).arg(v[1]);
    for (int i = 2; i < points; i++)
        scpi += nextSegment.arg(f[i-1]).arg(f[i]).arg(v[i-1]).arg(v[i]);
    scpi += "\n";

    _trace->select();
    _vna->write(scpi);
    show();
    on();
}
void VnaLimits::deleteAll() {
    QString scpi = ":CALC%1:LIM:DEL:ALL\n";
    scpi = scpi.arg(_channel);

    _trace->select();
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
