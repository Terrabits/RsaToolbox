#include "NetworkTraceData.h"


// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
//


NetworkTraceData::NetworkTraceData() {
    _parameter = S_PARAMETER;
    _impedance_Ohms = 50;
    _points = 0;

    _xUnits = HERTZ_UNITS;
    _xPrefix = NO_PREFIX;
}
NetworkTraceData::NetworkTraceData(const NetworkTraceData &other) {
    _timestamp = other._timestamp;
    _comment = other._comment;
    _outputPortComment = other._outputPortComment;
    _inputPortComment = other._inputPortComment;

    _parameter = other._parameter;
    _impedance_Ohms = other._impedance_Ohms;
    _points = other._points;

    _outputPort = other._outputPort;
    _inputPort = other._inputPort;


    _x = other._x;
    _xUnits = other._xUnits;
    _xPrefix = other._xPrefix;

    _y = other._y;
}

bool NetworkTraceData::isSParameter() {
    return(_parameter == S_PARAMETER);
}
bool NetworkTraceData::isYParameter() {
    return(_parameter == Y_PARAMETER);
}
bool NetworkTraceData::isZParameter() {
    return(_parameter == Z_PARAMETER);
}
bool NetworkTraceData::isHParameter() {
    return(_parameter == H_PARAMETER);
}
bool NetworkTraceData::isGParameter() {
    return(_parameter == G_PARAMETER);
}
void NetworkTraceData::setParameter(NetworkParameter parameter) {
    _parameter = parameter;
}

QString NetworkTraceData::comment() {
    return(_comment);
}
void NetworkTraceData::setComment(QString comment) {
    _comment = comment;
}
QString NetworkTraceData::timestamp() {
    return(_timestamp.toString());
}

uint NetworkTraceData::outputPort() {
    return(_outputPort.logicalPort());
}
void NetworkTraceData::setOutputPort(uint logicalPort) {
    _outputPort.setSingleEnded();
    _outputPort.setLogicalPort(logicalPort);
}
void NetworkTraceData::outputPort(BalancedPort &port) {
    port = _outputPort;
}
void NetworkTraceData::setOutputPort(BalancedPort port) {
    _outputPort = port;
}
QString NetworkTraceData::outputPortComment() {
    return(_outputPortComment);
}
void NetworkTraceData::setOutputPortComment(QString comment) {
    _outputPortComment = comment;
}

uint NetworkTraceData::inputPort() {
    return(_inputPort.logicalPort());
}
void NetworkTraceData::setInputPort(uint logicalPort) {
    _inputPort.setSingleEnded();
    _inputPort.setLogicalPort(logicalPort);
}
void NetworkTraceData::inputPort(BalancedPort &port) {
    port = _inputPort;
}
void NetworkTraceData::setInputPort(BalancedPort port) {
    _inputPort = port;
}
QString NetworkTraceData::inputPortComment() {
    return(_inputPortComment);
}
void NetworkTraceData::setInputPortComment(QString comment) {
    _inputPortComment = comment;
}

Units NetworkTraceData::xUnits() {
    return(_xUnits);
}
SiPrefix NetworkTraceData::xPrefix() {
    return(_xPrefix);
}
void NetworkTraceData::setXUnits(Units units, SiPrefix prefix) {
    _xUnits = units;
    _xPrefix = prefix;
}

uint NetworkTraceData::points() {
    return(_points);
}
QRowVector NetworkTraceData::x() {
    return(_x);
}
ComplexRowVector NetworkTraceData::y() {
    return(_y);
}
QRowVector NetworkTraceData::y_dB() {
    return(toDb(_y));
}
QRowVector NetworkTraceData::y_magnitude() {
    return(toMagnitude(_y));
}
QRowVector NetworkTraceData::y_phase_deg() {
    return(angle_deg(_y));
}
QRowVector NetworkTraceData::y_phase_rad() {
    return(angle_rad(_y));
}
QRowVector NetworkTraceData::y_vswr() {
    return(toVswr(_y));
}
QRowVector NetworkTraceData::y_real() {
    return(real(_y));
}
QRowVector NetworkTraceData::y_imaginary() {
    return(imaginary(_y));
}
void NetworkTraceData::setData(const QRowVector &x, const ComplexRowVector &y) {
    if (uint(x.size()) == y.size()) {
        _x = x;
        _y = y;
        _points = x.size();
        _timestamp = QDateTime::currentDateTime();
    }
}

void NetworkTraceData::operator=(const NetworkTraceData &other) {
    _timestamp = other._timestamp;
    _comment = other._comment;
    _outputPortComment = other._outputPortComment;
    _inputPortComment = other._inputPortComment;

    _parameter = other._parameter;
    _impedance_Ohms = other._impedance_Ohms;
    _points = other._points;

    _outputPort = other._outputPort;
    _inputPort = other._inputPort;


    _x = other._x;
    _xUnits = other._xUnits;
    _xPrefix = other._xPrefix;

    _y = other._y;
}


