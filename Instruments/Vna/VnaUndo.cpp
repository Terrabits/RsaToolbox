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
    qDebug() << "VnaUndo default constructor";
}
VnaUndo::VnaUndo(Vna *vna, bool recallOnDestruction) :
    _vna(vna),
    _recallOnDestruction(recallOnDestruction)
{
    qDebug() << "VnaUndo *vna constructor";
    save();
}
VnaUndo::~VnaUndo() {
    qDebug() << "VnaUndo destructor";
    if (!isVna() || !isSet())
        return;

    if (_recallOnDestruction)
        recall();
    else
        discard();
}

void VnaUndo::setRecallOnDestruction(bool recall) {
    qDebug() << "VnaUndo::setRecallOnDestruction: " << recall;
    _recallOnDestruction = recall;
}
void VnaUndo::setVna(Vna *vna) {
    _vna = vna;
}

void VnaUndo::save() {
    qDebug() << "VnaUndo::save";
    if (!isVna())
        return;
    if (isSet())
        discard();

    _setName = generateUniqueName();
    _vna->saveActiveSet(_setName);

    // Hide this file so the firmware doesn't delete it!
    QString newSetName = generateUniqueName();
    newSetName += "." + QFileInfo(_setName).suffix();

    QString currentDir = _vna->fileSystem().directory();
    _vna->fileSystem().changeDirectory(VnaFileSystem::Directory::RECALL_SETS_DIRECTORY);
    _vna->fileSystem().copyFile(_setName, newSetName);

    qDebug() << "_setName: " << _setName;
    qDebug() << "newSetName: " << newSetName;
    qDebug() << "Current dir: " << _vna->fileSystem().directory();
    qDebug() << "Files: " << _vna->fileSystem().files();
    qDebug() << "Do both files exist? " << _vna->fileSystem().isFile(_setName) << _vna->fileSystem().isFile(newSetName);

    _vna->fileSystem().deleteFile(_setName);
    _vna->fileSystem().changeDirectory(currentDir);

    _setName = newSetName;
}
void VnaUndo::recall() {
    qDebug() << "VnaUndo::recall";
    if (!isVna() || !isSet())
        return;

    _vna->closeActiveSet();
    _vna->openSet(_setName);
    _vna->deleteSet(_setName);
    _setName.clear();
}
void VnaUndo::discard() {
    qDebug() << "VnaUndo::discard";
    if (!isVna() || !isSet())
        return;

    _vna->deleteSet(_setName);
    _setName.clear();
}

QString VnaUndo::generateUniqueName() const {
    return QUuid::createUuid().toString().remove('{').remove('}').remove('-');
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


