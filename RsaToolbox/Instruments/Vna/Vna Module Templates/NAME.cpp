

// RsaToolbox includes
#include "%NAME%.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>


%NAME%::%NAME%(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
}

%NAME%::%NAME%(const %NAME% &other) :
    QObject(other.parent())
{
    _vna = other._vna;
}

%NAME%::%NAME%(Vna *vna, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
}

// Etc

// Private
bool %NAME%::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}