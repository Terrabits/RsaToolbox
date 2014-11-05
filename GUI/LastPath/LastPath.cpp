#include "LastPath.h"
using namespace RsaToolbox;

LastPath::LastPath() {
    _path = "";
    _keys = NULL;
}
LastPath::LastPath(QString initialPath) {
    _path = initialPath;
    _keys = NULL;
}
LastPath::LastPath(Keys *keys, QString key, QString initialPath) {
    _keys = keys;
    _key = key;
    _path = initialPath;
    if (isKey()) {
        if (_keys->Exists(key))
            _keys->Get(_key, _path);
    }
}
LastPath::LastPath(const LastPath &other) {
    _path = other._path;
    _keys = other._keys;
    _key = other._key;
}


bool LastPath::isKey() const {
    return (_keys != NULL) && (!_key.isEmpty());
}
QString LastPath::key() const {
    return _key;
}
Keys *LastPath::keys() const {
    return _keys;
}
void LastPath::setKey(Keys *keys, QString key) {
    _keys = keys;
    _key = key;
}

bool LastPath::isEmpty() const {
    return _path.isEmpty();
}
bool LastPath::isPath() const {
    return !isEmpty();
}

QString LastPath::path() const {
    return _path;
}
void LastPath::setPath(const QString &path) {
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

LastPath::operator QString() const {
    return _path;
}
LastPath::operator QDir() const {
    return QDir(_path);
}
LastPath::operator QFileInfo() const {
    return QFileInfo(_path);
}
