

// RsaToolbox includes
#include "VnaDiagram.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaDiagram
 * \ingroup VnaGroup
 * \brief The \c %VnaDiagram class
 * manipulates a diagram.
 */

VnaDiagram::VnaDiagram(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _index = 0;
}

VnaDiagram::VnaDiagram(const VnaDiagram &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _index = other._index;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _index = 0;
    }
}

VnaDiagram::VnaDiagram(Vna *vna, uint index, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _index = index;
}

QVector<uint> VnaDiagram::channels() {
    return(QVector<uint>());
}

QStringList VnaDiagram::traces() {
    return(QStringList());
}
void VnaDiagram::deleteTraces() {

}

QString VnaDiagram::title() {
    return(QString());
}
void VnaDiagram::setTitle(QString title) {
    Q_UNUSED(title);
}

void VnaDiagram::autoscale() {

}
void VnaDiagram::setYAxisMinimum(double min) {
    QStringList traces = _vna->traces();
    foreach (QString trace, traces)
        _vna->trace(trace).setYAxisMinimum(min);
}
void VnaDiagram::setYAxisMaximum(double max) {
    QStringList traces = _vna->traces();
    foreach (QString trace, traces)
        _vna->trace(trace).setYAxisMaximum(max);
}
void VnaDiagram::setYAxis(double min, double max) {
    QStringList traces = _vna->traces();
    foreach (QString trace, traces)
        _vna->trace(trace).setYAxis(min, max);
}

void VnaDiagram::operator=(VnaDiagram const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _index = other._index;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _index = 0;
    }
}

// Private
bool VnaDiagram::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
