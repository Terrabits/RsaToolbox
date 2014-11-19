#include "NetworkData.h"


// RsaToolbox
#include "General.h"
#include "Touchstone.h"
using namespace RsaToolbox;

// Qt
#include <QTextStream>

// Std lib
//


NetworkData::NetworkData() {
    _timestamp = QDateTime::currentDateTime();

    _parameter = NetworkParameter::S;
    _impedance_Ohms = 50;
    _ports = 0;
    _points = 0;

    _xUnits = Units::Hertz;
    _xPrefix = SiPrefix::None;
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

bool NetworkData::isSParameter() {
    return(_parameter == NetworkParameter::S);
}
bool NetworkData::isYParameter() {
    return(_parameter == NetworkParameter::Y);
}
bool NetworkData::isZParameter() {
    return(_parameter == NetworkParameter::Z);
}
bool NetworkData::isHParameter() {
    return(_parameter == NetworkParameter::H);
}
bool NetworkData::isGParameter() {
    return(_parameter == NetworkParameter::G);
}
NetworkParameter NetworkData::parameter() {
    return(_parameter);
}
void NetworkData::setParameter(NetworkParameter parameter) {
    _parameter = parameter;
}

QString NetworkData::comment() {
    return(_comment);
}
void NetworkData::setComment(QString comment) {
    _comment = comment;
}
QString NetworkData::timestamp() {
    return(_timestamp.toString());
}

uint NetworkData::numberOfPorts() {
    return(_ports);
}
void NetworkData::setNumberOfPorts(uint ports) {
    _ports = ports;
}

QString NetworkData::portComment(uint port) {
    return(_portComments[port-1]);
}
void NetworkData::setPortComment(uint port, QString comment) {
    _portComments[port-1] = comment;
}

double NetworkData::referenceImpedance_Ohms() {
    return(_impedance_Ohms);
}
void NetworkData::setReferenceImpedance(double Ohms) {
    _impedance_Ohms = Ohms;
}

Units NetworkData::xUnits() {
    return(_xUnits);
}
SiPrefix NetworkData::xPrefix() {
    return(_xPrefix);
}
void NetworkData::setXUnits(Units units, SiPrefix prefix) {
    _xUnits = units;
    _xPrefix = prefix;
}

uint NetworkData::points() {
    return(_points);
}
QRowVector &NetworkData::x() {
    return(_x);
}
ComplexMatrix3D& NetworkData::y() {
    return(_y);
}
ComplexRowVector NetworkData::y(uint outputPort, uint inputPort) {
    ComplexRowVector crv(_points);
    for (uint i = 0; i < _points; i++) {
        crv[i] = _y[i][outputPort-1][inputPort-1];
    }
    return(crv);
}
QRowVector NetworkData::y_dB(uint outputPort, uint inputPort) {
    QRowVector dB(_points);
    for (uint i = 0; i < _points; i++) {
        dB[i] = toDb(_y[i][outputPort-1][inputPort-1]);
    }
    return(dB);
}
QRowVector NetworkData::y_magnitude(uint outputPort, uint inputPort) {
    QRowVector magnitude(_points);
    for (uint i = 0; i < _points; i++) {
        magnitude[i] = toMagnitude(_y[i][outputPort-1][inputPort-1]);
    }
    return(magnitude);
}
QRowVector NetworkData::y_phase_deg(uint outputPort, uint inputPort) {
    QRowVector phase(_points);
    for (uint i = 0; i < _points; i++) {
        phase[i] = angle_deg(_y[i][outputPort-1][inputPort-1]);
    }
    return(phase);
}
QRowVector NetworkData::y_phase_rad(uint outputPort, uint inputPort) {
    QRowVector phase(_points);
    for (uint i = 0; i < _points; i++) {
        phase[i] = angle_rad(_y[i][outputPort-1][inputPort-1]);
    }
    return(phase);
}
QRowVector NetworkData::y_vswr(uint port) {
    QRowVector vswr(_points);
    for (uint i = 0; i < _points; i++) {
        vswr[i] = toVswr(_y[i][port-1][port-1]);
    }
    return(vswr);
}
QRowVector NetworkData::y_real(uint outputPort, uint inputPort) {
    QRowVector real(_points);
    for (uint i = 0; i < _points; i++) {
        real[i] = _y[i][outputPort-1][inputPort-1].real();
    }
    return(real);
}
QRowVector NetworkData::y_imaginary(uint outputPort, uint inputPort) {
    QRowVector imaginary(_points);
    for (uint i = 0; i < _points; i++) {
        imaginary[i] = _y[i][outputPort-1][inputPort-1].imag();
    }
    return(imaginary);
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
    stream << _ports;
    stream << _points;

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

    qint32 enumInt;
    stream >> enumInt;
    _parameter = NetworkParameter(enumInt);
    stream >> _impedance_Ohms;
    stream >> _ports;
    stream >> _points;

    stream >> _x;
    stream >> enumInt;
    _xUnits = Units(enumInt);
    stream >> enumInt;
    _xPrefix = SiPrefix(enumInt);
    stream >> _y;
}
QDataStream& operator>>(QDataStream &stream, NetworkData &data) {
    data.read(stream);
    return stream;
}




