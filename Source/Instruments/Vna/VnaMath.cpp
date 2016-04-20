

// RsaToolbox includes
#include "VnaMath.h"
#include "VnaTrace.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <QDebug>


VnaMath::VnaMath(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _trace.reset(new VnaTrace());
    _channel = 0;
}

VnaMath::VnaMath(const VnaMath &other) :
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

VnaMath::VnaMath(Vna *vna, VnaTrace *trace, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _trace.reset(new VnaTrace(*trace));
    _channel= trace->channel();
}

VnaMath::VnaMath(Vna *vna, QString traceName, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _trace.reset(new VnaTrace(vna, traceName));
    _channel = _trace->channel();
}
VnaMath::~VnaMath() {

}


bool VnaMath::isOn() {
    QString scpi = ":CALC%1:MATH:STAT?\n";
    scpi = scpi.arg(_channel);

    _trace->select();
    return _vna->query(scpi).trimmed() == "1";
}
bool VnaMath::isOff() {
    return !isOn();
}
void VnaMath::on(bool isOn) {
    QString scpi = ":CALC%1:MATH:STAT %2\n";
    scpi = scpi.arg(_channel);
    if (isOn)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);

    _trace->select();
    _vna->write(scpi);
}
void VnaMath::off(bool isOff) {
    on(!isOff);
}
QString VnaMath::expression() {
    QString scpi = ":CALC%1:MATH:SDEF?\n";
    scpi = scpi.arg(_channel);

    _trace->select();
    return _vna->query(scpi).trimmed().remove("\'");
}
void VnaMath::setExpression(QString expression) {
    QString scpi = ":CALC%1:MATH:SDEF \'%2\'\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(expression);

    _trace->select();
    _vna->write(scpi);
}

void VnaMath::divideBy(QString trace) {
    QString exp = "%1 / %2";
    exp = exp.arg(_trace->name());
    exp = exp.arg(trace);
    setExpression(exp);
    on();
}

void VnaMath::operator=(VnaMath const &other) {
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
bool VnaMath::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
