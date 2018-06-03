#include "VnaUndo.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QUuid>
#include <QDebug>


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
    if (!isSet() || !isVna())
        return;

    if (_recallOnDestruction)
        recall();
    else
        discard();
}

void VnaUndo::setRecallOnDestruction(bool recall) {
    _recallOnDestruction = recall;
}
void VnaUndo::setVna(Vna *vna) {
    _vna = vna;
}

void VnaUndo::save() {
    if (!isVna())
        return;
    if (isSet())
        discard();

    _setName = generateUniqueName();
    _vna->saveActiveSet(_setName);
}
void VnaUndo::recall() {
    if (!isSet() || !isVna())
        return;

    _vna->closeActiveSet();
    _vna->openSet(_setName);
    _vna->deleteSet(_setName);
    _setName.clear();
}
void VnaUndo::discard() {
    if (!isSet() || !isVna())
        return;

    _vna->deleteSet(_setName);
    _setName.clear();
}

QString VnaUndo::generateUniqueName() {
    return QUuid::createUuid().toString().remove('{').remove('}').remove('-');
}
bool VnaUndo::isVna() {
    if (!_vna)
        return false;
    if (!_vna->isOpen())
        return false;
    return !_vna->idString().isEmpty();
}
bool VnaUndo::isSet() {
    return !_setName.isEmpty();
}


