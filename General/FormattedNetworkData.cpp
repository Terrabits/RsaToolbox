#include "FormattedNetworkData.h"


// RsaToolbox
#include "General.h"
#include "FormattedTouchstone.h"
using namespace RsaToolbox;

// Qt
#include <QTextStream>

// Std lib
//


FormattedNetworkData::FormattedNetworkData() {
    _timestamp = QDateTime::currentDateTime();

    _parameter = S_PARAMETER;
    _impedance_Ohms = 50;
    _format = REAL_IMAGINARY_COMPLEX;
    _ports = 0;
    _points = 0;

    _xUnits = HERTZ_UNITS;
    _xPrefix = NO_PREFIX;
}
FormattedNetworkData::FormattedNetworkData(const FormattedNetworkData &other) {
    _timestamp = other._timestamp;
    _comment = other._comment;
    _portComments = other._portComments;

    _parameter = other._parameter;
    _impedance_Ohms = other._impedance_Ohms;
    _format = other._format;
    _ports = other._ports;
    _points = other._points;

    _x = other._x;
    _xUnits = other._xUnits;
    _xPrefix = other._xPrefix;

    _y = other._y;
}

bool FormattedNetworkData::isSParameter() {
    return(_parameter == S_PARAMETER);
}
bool FormattedNetworkData::isYParameter() {
    return(_parameter == Y_PARAMETER);
}
bool FormattedNetworkData::isZParameter() {
    return(_parameter == Z_PARAMETER);
}
bool FormattedNetworkData::isHParameter() {
    return(_parameter == H_PARAMETER);
}
bool FormattedNetworkData::isGParameter() {
    return(_parameter == G_PARAMETER);
}
NetworkParameter FormattedNetworkData::parameter() {
    return(_parameter);
}
void FormattedNetworkData::setParameter(NetworkParameter parameter) {
    _parameter = parameter;
}

QString FormattedNetworkData::comment() const {
    return(_comment);
}
void FormattedNetworkData::setComment(QString comment) {
    _comment = comment;
}
QString FormattedNetworkData::timestamp() const {
    return(_timestamp.toString());
}

ComplexFormat FormattedNetworkData::format() const {
    return _format;
}
void FormattedNetworkData::setFormat(ComplexFormat format) {
    _format = format;
}

uint FormattedNetworkData::numberOfPorts() const {
    return(_ports);
}
void FormattedNetworkData::setNumberOfPorts(uint ports) {
    _ports = ports;
}

QString FormattedNetworkData::portComment(uint port) const {
    return(_portComments[port-1]);
}
void FormattedNetworkData::setPortComment(uint port, QString comment) {
    _portComments[port-1] = comment;
}

double FormattedNetworkData::referenceImpedance_Ohms() const {
    return(_impedance_Ohms);
}
void FormattedNetworkData::setReferenceImpedance(double Ohms) {
    _impedance_Ohms = Ohms;
}

Units FormattedNetworkData::xUnits() const {
    return(_xUnits);
}
SiPrefix FormattedNetworkData::xPrefix() const {
    return(_xPrefix);
}
void FormattedNetworkData::setXUnits(Units units, SiPrefix prefix) {
    _xUnits = units;
    _xPrefix = prefix;
}

uint FormattedNetworkData::points() const {
    return(_points);
}
QRowVector &FormattedNetworkData::x() {
    return(_x);
}
FormattedComplexMatrix3D &FormattedNetworkData::y() {
    return(_y);
}
FormattedComplexRowVector FormattedNetworkData::y(uint outputPort, uint inputPort) const {
    FormattedComplexRowVector result(_points);
    for (uint i = 0; i < _points; i++) {
        result[i] = _y[i][outputPort-1][inputPort-1];
    }
    return(result);
}
QRowVector FormattedNetworkData::y_dB(uint outputPort, uint inputPort) const {
    QRowVector dB(_points);
    for (uint i = 0; i < _points; i++) {
        dB[i] = _y[i][outputPort-1][inputPort-1].dB();
    }
    return(dB);
}
QRowVector FormattedNetworkData::y_magnitude(uint outputPort, uint inputPort) const {
    QRowVector magnitude(_points);
    for (uint i = 0; i < _points; i++) {
        magnitude[i] = _y[i][outputPort-1][inputPort-1].magnitude();
    }
    return(magnitude);
}
QRowVector FormattedNetworkData::y_phase_deg(uint outputPort, uint inputPort) const {
    QRowVector phase(_points);
    for (uint i = 0; i < _points; i++) {
        phase[i] = _y[i][outputPort-1][inputPort-1].angle_deg();
    }
    return(phase);
}
QRowVector FormattedNetworkData::y_phase_rad(uint outputPort, uint inputPort) const {
    QRowVector phase(_points);
    for (uint i = 0; i < _points; i++) {
        phase[i] = _y[i][outputPort-1][inputPort-1].angle_rad();
    }
    return(phase);
}
QRowVector FormattedNetworkData::y_vswr(uint port) const {
    QRowVector vswr(_points);
    for (uint i = 0; i < _points; i++) {
        vswr[i] = toVswr(_y[i][port-1][port-1].magnitude());
    }
    return(vswr);
}
QRowVector FormattedNetworkData::y_real(uint outputPort, uint inputPort) const {
    QRowVector real(_points);
    for (uint i = 0; i < _points; i++) {
        real[i] = _y[i][outputPort-1][inputPort-1].real();
    }
    return(real);
}
QRowVector FormattedNetworkData::y_imaginary(uint outputPort, uint inputPort) const {
    QRowVector imaginary(_points);
    for (uint i = 0; i < _points; i++) {
        imaginary[i] = _y[i][outputPort-1][inputPort-1].imaginary();
    }
    return(imaginary);
}
void FormattedNetworkData::setData(const QRowVector &x, const FormattedComplexMatrix3D &y) {
    if (uint(x.size()) == y.size()) {
        _x = x;
        _y = y;
        _points = uint(x.size());
        _ports = uint(_y[0].size());
        _timestamp = QDateTime::currentDateTime();
    }
}

void FormattedNetworkData::operator=(const FormattedNetworkData &other) {
    _timestamp = other._timestamp;
    _comment = other._comment;
    _portComments = other._portComments;

    _parameter = other._parameter;
    _format = other._format;
    _impedance_Ohms = other._impedance_Ohms;
    _points = other._points;

    _x = other._x;
    _xUnits = other._xUnits;
    _xPrefix = other._xPrefix;

    _y = other._y;
}


void FormattedNetworkData::write(QDataStream &stream) const {
    stream << _timestamp;
    stream << _comment;
    stream << _portComments;
    stream << qint32(_parameter);
    stream << qint32(_format);
    stream << _impedance_Ohms;
    stream << quint32(_ports);
    stream << quint32(_points);
    stream << _x;
    stream << qint32(_xUnits);
    stream << qint32(_xPrefix);
    stream << _y;
}
QDataStream& operator<<(QDataStream &stream, const RsaToolbox::FormattedNetworkData &data) {
    data.write(stream);
    return stream;
}
void FormattedNetworkData::read(QDataStream &stream) {
    stream >> _timestamp;
    stream >> _comment;
    stream >> _portComments;

    qint32 enumInt;
    stream >> enumInt;
    _parameter = NetworkParameter(enumInt);

    stream >> enumInt;
    _format = ComplexFormat(enumInt);

    stream >> _impedance_Ohms;

    quint32 safeUint;
    stream >> safeUint;
    _ports = safeUint;

    stream >> safeUint;
    _points = safeUint;

    stream >> _x;

    stream >> enumInt;
    _xUnits = Units(enumInt);

    stream >> enumInt;
    _xPrefix = SiPrefix(enumInt);
    stream >> _y;
}
QDataStream& operator>>(QDataStream &stream, RsaToolbox::FormattedNetworkData &data) {
    data.read(stream);
    return stream;
}

