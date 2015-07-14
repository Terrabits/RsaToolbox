#include "NetworkData.h"


// RsaToolbox
#include "General.h"
#include "Touchstone.h"
using namespace RsaToolbox;

// Qt
#include <QTextStream>

// Std lib
//


NetworkData::NetworkData() :
    _timestamp(QDateTime::currentDateTime()),
    _parameter(NetworkParameter::S),
    _impedance_Ohms(50.0),
    _ports(0),
    _points(0),
    _xUnits(Units::Hertz),
    _xPrefix(SiPrefix::None)
{
}
NetworkData::NetworkData(const NetworkData &other) {
    _timestamp = other._timestamp;
    _comment = other._comment;
    _portComments = other._portComments;

    _parameter = other._parameter;
    _impedance_Ohms = other._impedance_Ohms;
    _ports = other._ports;
    _points = other._points;

    _x = other._x;
    _xUnits = other._xUnits;
    _xPrefix = other._xPrefix;

    _y = other._y;
}

bool NetworkData::isSParameter() const {
    return(_parameter == NetworkParameter::S);
}
bool NetworkData::isYParameter() const {
    return(_parameter == NetworkParameter::Y);
}
bool NetworkData::isZParameter() const {
    return(_parameter == NetworkParameter::Z);
}
bool NetworkData::isHParameter() const {
    return(_parameter == NetworkParameter::H);
}
bool NetworkData::isGParameter() const {
    return(_parameter == NetworkParameter::G);
}
NetworkParameter NetworkData::parameter() const {
    return(_parameter);
}
void NetworkData::setParameter(NetworkParameter parameter) {
    _parameter = parameter;
}

QString NetworkData::comment() const {
    return(_comment);
}
void NetworkData::setComment(const QString &comment) {
    _comment = comment;
}
QString NetworkData::timestamp() const {
    return(_timestamp.toString());
}
void NetworkData::setTimestamp(const QDateTime &dateTime) {
    _timestamp = dateTime;
}

uint NetworkData::ports() const {
    return _ports;
}
void NetworkData::setPorts(uint ports) {
    _ports = ports;
    resize(ports, _points);
}

QString NetworkData::portComment(uint port) const {
    return(_portComments[port-1]);
}
void NetworkData::setPortComment(uint port, const QString &comment) {
    _portComments[port-1] = comment;
}

double NetworkData::referenceImpedance_Ohms() const {
    return(_impedance_Ohms);
}
void NetworkData::setReferenceImpedance(double Ohms) {
    _impedance_Ohms = Ohms;
}

Units NetworkData::xUnits() const {
    return(_xUnits);
}
SiPrefix NetworkData::xPrefix() const {
    return(_xPrefix);
}
void NetworkData::setXUnits(Units units, SiPrefix prefix) {
    _xUnits = units;
    _xPrefix = prefix;
}

uint NetworkData::points() const {
    return(_points);
}
QRowVector &NetworkData::x() {
    return(_x);
}
ComplexMatrix3D& NetworkData::y() {
    return(_y);
}
ComplexRowVector NetworkData::y(uint outputPort, uint inputPort) const {
    ComplexRowVector crv(_points);
    for (uint i = 0; i < _points; i++) {
        crv[i] = _y[i][outputPort-1][inputPort-1];
    }
    return(crv);
}
QRowVector NetworkData::y_dB(uint outputPort, uint inputPort) const {
    QRowVector dB(_points);
    for (uint i = 0; i < _points; i++) {
        dB[i] = toDb(_y[i][outputPort-1][inputPort-1]);
    }
    return(dB);
}
QRowVector NetworkData::y_magnitude(uint outputPort, uint inputPort) const {
    QRowVector magnitude(_points);
    for (uint i = 0; i < _points; i++) {
        magnitude[i] = toMagnitude(_y[i][outputPort-1][inputPort-1]);
    }
    return(magnitude);
}
QRowVector NetworkData::y_phase_deg(uint outputPort, uint inputPort) const {
    QRowVector phase(_points);
    for (uint i = 0; i < _points; i++) {
        phase[i] = angle_deg(_y[i][outputPort-1][inputPort-1]);
    }
    return(phase);
}
QRowVector NetworkData::y_phase_rad(uint outputPort, uint inputPort) const {
    QRowVector phase(_points);
    for (uint i = 0; i < _points; i++) {
        phase[i] = angle_rad(_y[i][outputPort-1][inputPort-1]);
    }
    return(phase);
}
QRowVector NetworkData::y_vswr(uint port) const {
    QRowVector vswr(_points);
    for (uint i = 0; i < _points; i++) {
        vswr[i] = toVswr(_y[i][port-1][port-1]);
    }
    return(vswr);
}
QRowVector NetworkData::y_real(uint outputPort, uint inputPort) const {
    QRowVector real(_points);
    for (uint i = 0; i < _points; i++) {
        real[i] = _y[i][outputPort-1][inputPort-1].real();
    }
    return(real);
}
QRowVector NetworkData::y_imaginary(uint outputPort, uint inputPort) const {
    QRowVector imaginary(_points);
    for (uint i = 0; i < _points; i++) {
        imaginary[i] = _y[i][outputPort-1][inputPort-1].imag();
    }
    return(imaginary);
}

void NetworkData::clear() {
    _points = 0;
    _ports = 0;
    _portComments.clear();
    _x.clear();
    _y.clear();
}
void NetworkData::resize(uint ports, uint points) {
    if (ports <= 0)
        return;
    if (points <= 0)
        return;

    _ports = ports;
    _points = points;

    while (uint(_portComments.size()) > ports)
        _portComments.removeLast();
    while (uint(_portComments.size()) < ports)
        _portComments << QString();

    _x.resize(points);
    _y.resize(points);
    for (uint i = 0; i < points; i++) {
        _y[i].resize(ports);
        for (uint j = 0; j < ports; j++) {
            _y[i][j].resize(ports);
        }
    }
}
void NetworkData::setPoints(uint points) {
    _points = points;
    resize(_ports, points);
}
void NetworkData::setData(const QRowVector &x, const ComplexMatrix3D &y) {
    if (uint(x.size()) == y.size()) {
        _x = x;
        _y = y;
        _points = uint(x.size());
        _ports = uint(_y[0].size());
        _timestamp = QDateTime::currentDateTime();
    }
}

void NetworkData::operator=(const NetworkData &other) {
    _timestamp = other._timestamp;
    _comment = other._comment;
    _portComments = other._portComments;

    _parameter = other._parameter;
    _impedance_Ohms = other._impedance_Ohms;
    _points = other._points;
    _ports = other._ports;

    _x = other._x;
    _xUnits = other._xUnits;
    _xPrefix = other._xPrefix;

    _y = other._y;
}


void NetworkData::write(QDataStream &stream) const {
    stream << _timestamp;
    stream << _comment;
    stream << _portComments;

    stream << qint32(_parameter);
    stream << _impedance_Ohms;
    stream << quint32(_ports);
    stream << quint32(_points);

    stream << _x;
    stream << _xUnits;
    stream << _xPrefix;
    stream << _y;
}
QDataStream& operator<<(QDataStream &stream, const NetworkData &data) {
    data.write(stream);
    return stream;
}
void NetworkData::read(QDataStream &stream) {
    stream >> _timestamp;
    stream >> _comment;
    stream >> _portComments;

    qint32 _qint32;
    stream >> _qint32;
    _parameter = NetworkParameter(_qint32);
    stream >> _impedance_Ohms;
    quint32 _quint32;
    stream >> _quint32;
    _ports = _quint32;
    stream >> _quint32;
    _points = _quint32;

    stream >> _x;
    stream >> _qint32;
    _xUnits = Units(_qint32);
    stream >> _qint32;
    _xPrefix = SiPrefix(_qint32);
    stream >> _y;
}
QDataStream& operator>>(QDataStream &stream, NetworkData &data) {
    data.read(stream);
    return stream;
}




