

// RsaToolbox includes
#include "General.h"
#include "VnaReferenceMarker.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaReferenceMarker
 * \ingroup VnaGroup
 * \brief The \c %VnaReferenceMarker class
 * controls a reference marker on a trace.
 */

VnaReferenceMarker::VnaReferenceMarker(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _trace.reset(new VnaTrace());
    _traceName = QString();
}

VnaReferenceMarker::VnaReferenceMarker(const VnaReferenceMarker &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _trace.reset(new VnaTrace(*other._trace.data()));
        _traceName = other._traceName;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _trace.reset(new VnaTrace());
        _traceName = QString();

    }
}
VnaReferenceMarker::VnaReferenceMarker(Vna *vna, VnaTrace *trace, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _trace.reset(new VnaTrace(*trace));
    _traceName = trace->name();
}

VnaReferenceMarker::VnaReferenceMarker(Vna *vna, QString traceName, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _trace.reset(new VnaTrace(vna, traceName));
    _traceName = traceName;
}
VnaReferenceMarker::~VnaReferenceMarker() {

}


bool VnaReferenceMarker::isOn() {
    _trace->select();

    QString scpi = ":CALC%1:MARK:REF?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi).trimmed() == "1");
}
void VnaReferenceMarker::on(bool isOn) {
    _trace->select();

    QString scpi = ":CALC%1:MARK:REF %2\n";
    scpi = scpi.arg(_trace->channel());
    if (isOn)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
bool VnaReferenceMarker::isOff() {
    return(!isOn());
}
void VnaReferenceMarker::off(bool isOff) {
    on(!isOff);
}

QString VnaReferenceMarker::name() {
    _trace->select();

    QString scpi = ":CALC%1:MARK:REF:NAME?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi).trimmed().remove('\''));
}
void VnaReferenceMarker::setName(QString name) {
    _trace->select();

    QString scpi = ":CALC%1:MARK:REF:NAME \'%2\'\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(name);
    _vna->write(scpi);
}

double VnaReferenceMarker::x() {
    _trace->select();

    QString scpi = ":CALC%1:MARK:REF:X?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi).trimmed().toDouble());
}
double VnaReferenceMarker::y() {
    _trace->select();

    QString scpi = ":CALC%1:MARK:REF:Y?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaReferenceMarker::coordinates(double &x, double &y) {
    x = this->x();
    y = this->y();
}
void VnaReferenceMarker::setX(double x, SiPrefix prefix) {
    _trace->select();

    QString scpi = ":CALC%1:MARK:REF:X %2\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(x * toDouble(prefix), 0, 'E', 12);
    _vna->write(scpi);
}
void VnaReferenceMarker::setToMarker(uint markerIndex) {
    _trace->select();

    QString scpi = ":CALC%1:MARK:REF:X %2";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(_trace->marker(markerIndex).x(), 0, 'E', 12);
    _vna->write(scpi);
}

void VnaReferenceMarker::operator=(VnaReferenceMarker const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _trace.reset(new VnaTrace(*other._trace.data()));
        _traceName = other._traceName;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _trace.reset(new VnaTrace());
        _traceName = QString();

    }
}

// Private
bool VnaReferenceMarker::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
