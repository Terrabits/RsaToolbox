

// RsaToolbox includes
#include "VnaSwitchMatrix.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt
#include <QDebug>

/*!
 * \class RsaToolbox::VnaSwitchMatrix
 * \ingroup VnaGroup
 * \brief The \c %VnaSwitchMatrix class
 * controls a switch matrix that is
 * connected to a Vna.
 */

VnaSwitchMatrix::VnaSwitchMatrix(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _index = 0;
}

VnaSwitchMatrix::VnaSwitchMatrix(const VnaSwitchMatrix &other)
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

VnaSwitchMatrix::VnaSwitchMatrix(Vna *vna, uint index, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _index = index;
}
VnaSwitchMatrix::~VnaSwitchMatrix() {

}


QString VnaSwitchMatrix::driver() {
    QStringList result = defineQuery();
    if (result.size() < 4)
        return "";

    return result[1];
}
ConnectionType VnaSwitchMatrix::connectionType() {
    QStringList result = defineQuery();
    if (result.size() < 4)
        return "";

    return VnaScpi::toMatrixConnection(result[2]);
}
QString VnaSwitchMatrix::address() {
    QStringList result = defineQuery();
    if (result.size() < 4)
        return "";

    return result[3];
}

PortMap VnaSwitchMatrix::matrixToVnaConnections() {
    QString scpi = "";
}


void VnaSwitchMatrix::operator=(VnaSwitchMatrix const &other) {
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
bool VnaSwitchMatrix::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
QStringList VnaSwitchMatrix::defineQuery() {
    QString scpi = ":SYST:COMM:RDEV:SMAT%1:DEF?\n";
    scpi = scpi.arg(_index);

    // result[0]: Unused/Empty;
    // result[1]: Driver (usually switch matrix model)
    // result[2]: Interface (LAN, USB)
    // result[3]: Address (eg "127.0.0.1");
    return _vna->query(scpi).trimmed().remove("\'").split(",",QString::KeepEmptyParts);
}
