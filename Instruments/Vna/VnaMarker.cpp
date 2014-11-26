

// RsaToolbox includes
#include "General.h"
#include "VnaMarker.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaMarker
 * \ingroup VnaGroup
 * \brief The \c %VnaMarker class
 * is used to control a marker
 * on a trace.
 */

VnaMarker::VnaMarker(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _trace.reset(new VnaTrace());
    _traceName = QString();
    _index = 0;
}

VnaMarker::VnaMarker(const VnaMarker &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _trace.reset(new VnaTrace(*other._trace.data()));
        _traceName = other._traceName;
        _index = other._index;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _trace.reset(new VnaTrace());
        _traceName = QString();
        _index = 0;

    }
}
VnaMarker::VnaMarker(Vna *vna, VnaTrace *trace, uint index, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _trace.reset(new VnaTrace(*trace));
    _traceName = trace->name();
    _index = index;
}

VnaMarker::VnaMarker(Vna *vna, QString traceName, uint index, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _trace.reset(new VnaTrace(vna, traceName));
    _traceName = traceName;
    _index = index;
}
VnaMarker::~VnaMarker() {

}


QString VnaMarker::name() {
    _trace->select();

    QString scpi = ":CALC%1:MARK%2:NAME?\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(_index);
    return(_vna->query(scpi).trimmed().remove('\''));
}
void VnaMarker::setName(QString name) {
    _trace->select();

    QString scpi = ":CALC%1:MARK%2:NAME \'%3\'\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(_index);
    scpi = scpi.arg(name);
    _vna->write(scpi);
}

bool VnaMarker::isDeltaOn() {
    _trace->select();

    QString scpi = ":CALC%1:MARK%2:DELT?\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(_index);
    return(_vna->query(scpi).trimmed() == "1");
}
bool VnaMarker::isDeltaOff() {
    return(!isDeltaOn());
}

void VnaMarker::deltaOn(bool isOn) {
    _trace->select();

    QString scpi = ":CALC%1:MARK%2:DELT %3\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(_index);
    if (isOn)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
void VnaMarker::deltaOff(bool isOff) {
    deltaOn(!isOff);
}

double VnaMarker::y() {
    _trace->select();

    QString scpi = ":CALC%1:MARK%2:Y?\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(_index);
    return(_vna->query(scpi).trimmed().toDouble());
}
double VnaMarker::x() {
    _trace->select();

    QString scpi = ":CALC%1:MARK%2:X?\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(_index);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaMarker::coordinates(double &x, double &y) {
    x = this->x();
    y = this->y();
}
void VnaMarker::setX(double x, SiPrefix prefix) {
    _trace->select();

    QString scpi = ":CALC%1:MARK%2:X %3\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(_index);
    scpi = scpi.arg(x * toDouble(prefix), 0, 'E', 12);
    _vna->write(scpi);
}

void VnaMarker::searchForMax() {
    _trace->select();

    QString scpi = ":CALC%1:MARK%2:FUNC:EXEC MAX\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(_index);
    _vna->write(scpi);
}
void VnaMarker::searchForMin() {
    _trace->select();

    QString scpi = ":CALC%1:MARK%2:FUNC:EXEC MIN\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(_index);
    _vna->write(scpi);
}
void VnaMarker::searchFor(double y) {
    Q_UNUSED(y);
}
void VnaMarker::searchRightFor(double y) {
    Q_UNUSED(y);
}
void VnaMarker::searchRightForPeak() {

}
void VnaMarker::searchLeftFor(double y) {
    Q_UNUSED(y);
}
void VnaMarker::searchLeftForPeak() {

}
void VnaMarker::setReferenceMarker() {

}

// Calculate:
void VnaMarker::measureBandpassFilter() {

}

void VnaMarker::operator=(VnaMarker const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _trace.reset(new VnaTrace(*other._trace.data()));
        _traceName = other._traceName;
        _index = other._index;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _trace.reset(new VnaTrace());
        _traceName = QString();
        _index = 0;

    }
}

// Private
bool VnaMarker::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
