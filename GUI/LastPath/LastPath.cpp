#include "LastPath.h"
using namespace RsaToolbox;

// Qt
#include <QDebug>

SharedLastPath RsaToolbox::newLastPath() {
    return SharedLastPath(new LastPath());
}
SharedLastPath RsaToolbox::newLastPath(QString initialPath) {
    return SharedLastPath(new LastPath(initialPath));
}
SharedLastPath RsaToolbox::newLastPath(Keys *keys, QString key, QString initialPath) {
    return SharedLastPath(new LastPath(keys, key, initialPath));
}
SharedLastPath RsaToolbox::newLastPath(const LastPath &other) {
    return SharedLastPath(new LastPath(other));
}

LastPath::LastPath() {
    _path = "";
    _keys = NULL;
}
LastPath::LastPath(QString initialPath) {
    _path = initialPath;
    _keys = NULL;
}
LastPath::LastPath(Keys *keys, QString key, QString initialPath) {
    qDebug() << "LastPath::LastPath " << keys << key << initialPath;
    _path = "";
    _keys = NULL;

    setPath(initialPath);
    setKey(keys, key);
}
LastPath::LastPath(const LastPath &other) {
    _path = other._path;
    _keys = other._keys;
    _key = other._key;
}


bool LastPath::isKey() const {
    qDebug() << "LastPath::isKey " << _keys << _key;
    qDebug() << "_keys != NULL? " << (_keys != NULL);
    qDebug() << "!_key.isEmpty()? " << (!_key.isEmpty());
    return ((_keys != NULL) && (!_key.isEmpty()));
}
QString LastPath::key() const {
    return _key;
}
Keys *LastPath::keys() const {
    return _keys;
}
void LastPath::setKey(Keys *keys, QString key) {
    qDebug() << "LastPath::setKey " << keys << key;
    _keys = keys;
    _key = key;

    qDebug() << "Attempting to dereference... " << _keys->Exists(_key);

    if (isKey()) {
        qDebug() << "...isKey!";
        if (_keys->Exists(_key)) {
            qDebug() << "...Key exists!";
            _keys->Get(_key, _path);
            qDebug() << "...Got key";
        }
    }
    else {
        qDebug() << "No key!";
    }
}

bool LastPath::isEmpty() const {
    return _path.isEmpty();
}
bool LastPath::exists() const {
    if (isEmpty())
        return false;

    return toDir().exists();
}

void LastPath::setPath(const QString &path) {
    qDebug() << "LastPath::setPath " << path;
    if (_path == path)
        return;

    if (path == ".")
        _path = "";
    else
        _path = path;
    if (isKey())
        _keys->Set(_key, _path);
}
void LastPath::setPath(const QDir &dir) {
    setPath(dir.path());
}
void LastPath::setPath(const QFileInfo &dir) {
    setPath(dir.filePath());
}
void LastPath::setFromFilePath(const QString &filePath) {
    setPath(QFileInfo(filePath).path());
}
void LastPath::setFromFilePath(const QFileInfo &filePath) {
    setPath(filePath.path());
}

void LastPath::operator=(const LastPath &other) {
    _path = other._path;
}
void LastPath::operator=(const QString &path) {
    setPath(path);
}
void LastPath::operator=(const QDir &dir) {
    setPath(dir);
}
void LastPath::operator=(const QFileInfo &dir) {
    setPath(dir);
}

QString LastPath::toString() const {
    return _path;
}
QDir LastPath::toDir() const {
    return this->operator QDir();
}
QFileInfo LastPath::toFileInfo() const {
    return this->operator QFileInfo();
}
LastPath::operator QString() const {
    return _path;
}
LastPath::operator QDir() const {
    return QDir(_path);
}
LastPath::operator QFileInfo() const {
    return QFileInfo(_path);
}
