#include "VnaUndo.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QUuid>


VnaUndo::VnaUndo() :
    _vna(0),
    _recallOnDestruction(false)
{

}
VnaUndo::VnaUndo(Vna *vna, bool recallOnDestruction) :
    _vna(vna),
    _recallOnDestruction(recallOnDestruction)
{
    save();
}
VnaUndo::~VnaUndo() {
    if (!_recallOnDestruction)
        return;

    if (isVna() && isSet())
        recall();
}

void VnaUndo::setVna(Vna *vna) {
    _vna = vna;
}
void VnaUndo::save() {
    if (!isVna())
        return;
    if (isSet())
        discard();

    _setName = QUuid::createUuid().toString().remove('{').remove('}').remove('-');
    // May be more concise and complete:
    // _setName = QUuid::createUuid().toString().remove(QRegExp("***not characters or numbers***"));
    _vna->saveActiveSet(_setName);
}
void VnaUndo::recall() {
    if (!isVna() || !isSet())
        return;

    _vna->closeActiveSet();
    _vna->openSet(_setName);
    _vna->deleteSet(_setName);
    _setName.clear();
}
void VnaUndo::discard() {
    if (!isVna() || !isSet())
        return;

    _vna->deleteSet(_setName);
    _setName.clear();
}

bool VnaUndo::isVna() {
    if (!_vna)
        return false;
    if (!_vna->isConnected())
        return false;
    return !_vna->idString().isEmpty();
}
bool VnaUndo::isSet() {
    if (!isVna())
        return false;
    return !_setName.isEmpty();

//    if (_setName.isEmpty())
//        return false;
//    return _vna->sets().contains(_setName, Qt::CaseInsensitive);
}


