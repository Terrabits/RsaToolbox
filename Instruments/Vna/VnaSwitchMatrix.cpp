

// RsaToolbox includes
#include "VnaSwitchMatrix.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

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


// To Be Continued...


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
