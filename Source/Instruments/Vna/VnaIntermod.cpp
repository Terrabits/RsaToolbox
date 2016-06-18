

// RsaToolbox includes
#include "General.h"
#include "VnaIntermod.h"
#include "VnaChannel.h"
#include "Vna.h"
#include "VnaScpi.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>


// ToneSource
VnaIntermod::ToneSource::ToneSource() :
    _type(Type::None),
    _port(0),
    _generator(0)
{
    // De nada
}
VnaIntermod::ToneSource::~ToneSource() {
    // De nada
}

bool VnaIntermod::ToneSource::isUndefined() const {
    return _type == Type::None;
}
VnaIntermod::ToneSource::Type VnaIntermod::ToneSource::type() const {
    return _type;
}

bool VnaIntermod::ToneSource::isPort() const {
    return _type == Type::Port;
}
uint VnaIntermod::ToneSource::port() const {
    return _port;
}
void VnaIntermod::ToneSource::setPort(uint port) {
    _type = Type::Port;
    _generator = 0;
    _port = port;
}

bool VnaIntermod::ToneSource::isGenerator() const {
    return _type == Type::Generator;
}
uint VnaIntermod::ToneSource::generator() const {
    return _generator;
}
void VnaIntermod::ToneSource::setGenerator(uint index) {
    _type = Type::Generator;
    _port = 0;
    _generator = index;
}

void VnaIntermod::ToneSource::clear() {
    _type = Type::None;
    _port = 0;
    _generator = 0;
}

// VnaIntermod
VnaIntermod::VnaIntermod(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaIntermod::VnaIntermod(const VnaIntermod &other) :
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
VnaIntermod::VnaIntermod(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}

VnaIntermod::VnaIntermod(Vna *vna, uint channelIndex, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, channelIndex, this));
    _channelIndex = channelIndex;
}

double VnaIntermod::toneDistance_Hz() {
    QString scpi = ":SENS%1:FREQ:IMOD:TDIS?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toDouble();
}
void VnaIntermod::setToneDistance(double distance_Hz, SiPrefix prefix) {
    QString scpi = ":SENS%1:FREQ:IMOD:TDIS %2 %3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(distance_Hz);
    scpi = scpi.arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}

uint VnaIntermod::lowerTonePort() {
    QString scpi = ":SENS%1:FREQ:IMOD:LTON?\n";
    scpi = scpi.arg(_channelIndex);
    scpi = _vna->query(scpi).trimmed();
    QStringList results = scpi.split(",");
    if (results.size() != 2)
        return 0;
    return results.last().trimmed().toUInt();
}
void VnaIntermod::setLowerTonePort(uint port) {
    QString scpi = ":SENS%1:FREQ:IMOD:LTON PORT,%2\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(port);
    _vna->write(scpi);
}

VnaIntermod::ToneSource VnaIntermod::upperToneSource() {
    QString scpi = ":SENS%1:FREQ:IMOD:UTON?\n";
    scpi = scpi.arg(_channelIndex);
    scpi = _vna->query(scpi).trimmed();
    QStringList result = scpi.split(",");
    ToneSource source;
    if (result.size() != 2) {
        return source;
    }
    ToneSource::Type type = VnaScpi::toToneSourceType(result.first());
    if (type == ToneSource::Type::Port) {
        const uint p = result.last().toUInt();
        source.setPort(p);
    }
    if (type == ToneSource::Type::Generator) {
        const uint g = result.last().toUInt();
        source.setGenerator(g);
    }
    return source;
}
void VnaIntermod::setUpperToneSource(ToneSource source) {
    if (source.isUndefined())
        return;

    QString scpi = ":SENS%1:FREQ:IMOD:UTON %2,%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(VnaScpi::toString(source.type()));
    if (source.isPort()) {
        scpi = scpi.arg(source.port());
    }
    if (source.isGenerator()) {
        scpi = scpi.arg(source.generator());
    }
    _vna->write(scpi);
}

uint VnaIntermod::receivingPort() {
    QString scpi = ":SENS%1:FREQ:IMOD:REC?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->query(scpi).trimmed().toUInt();
}
void VnaIntermod::setReceivingPort(uint port) {
    QString scpi = ":SENS%1:FREQ:IMOD:REC %2\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(port);
    _vna->write(scpi);
}

void VnaIntermod::order3On(bool on) {
    orderOn(3, on);
}
void VnaIntermod::order5On(bool on) {
    orderOn(5, on);
}
void VnaIntermod::order7On(bool on) {
    orderOn(7, on);
}
void VnaIntermod::order9On(bool on) {
    orderOn(9, on);
}
void VnaIntermod::orderOn(uint n, bool on) {
    QString scpi = ":SENS%1:FREQ:IMOD:ORD%2 %3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(n);
    if (on)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}

void VnaIntermod::operator=(VnaIntermod const &other) {
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
bool VnaIntermod::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}

bool operator!=(const RsaToolbox::VnaIntermod::ToneSource &lsrc, const RsaToolbox::VnaIntermod::ToneSource &rsrc) {
    // Any differences?
    if (lsrc.type() != rsrc.type())
        return true;
    if (lsrc.isUndefined())
        return true;
    if (lsrc.isPort() && lsrc.port() != rsrc.port())
        return true;
    if (lsrc.isGenerator() && lsrc.generator() != rsrc.generator())
        return true;

    // No difference found
    return false;
}
bool operator==(const RsaToolbox::VnaIntermod::ToneSource &lsrc, const RsaToolbox::VnaIntermod::ToneSource &rsrc) {
    return !(lsrc != rsrc);
}
