

// RsaToolbox includes
#include "VnaCalUnit.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt
#include <QDebug>


/*!
 * \class RsaToolbox::VnaCalUnit
 * \ingroup VnaGroup
 * \brief The \c %VnaCalUnit class
 * manipulates a Calibration Unit
 * connected to a Vna.
 */

VnaCalUnit::VnaCalUnit(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _id = QString();
}

VnaCalUnit::VnaCalUnit(const VnaCalUnit &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _id = other._id;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _id = QString();
    }
}

VnaCalUnit::VnaCalUnit(Vna *vna, QString id, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _id = id;
}
VnaCalUnit::~VnaCalUnit() {

}

void VnaCalUnit::operator=(VnaCalUnit const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _id = other._id;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _id = QString();
    }
}

// Private
bool VnaCalUnit::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
