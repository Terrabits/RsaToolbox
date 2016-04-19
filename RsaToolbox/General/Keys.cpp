#include "Keys.h"
using namespace RsaToolbox;


// Constructor
Keys::Keys(QString path) {
    _path = QDir(path);
}

bool Keys::exists(QString key) const {
    addPath(key);
    return QFile(key).exists();
}
bool Keys::doesNotExist(QString key) const {
    return !exists(key);
}
bool Keys::isTrue(QString key) {
    bool isTrue;
    if (!get(key, isTrue))
        return false;
    else
        return isTrue;
}
bool Keys::isFalse(QString key) {
    return !isTrue(key);
}
QString Keys::path() const {
    return _path.path();
}
bool Keys::remove(QString key) {
    addPath(key);
    return QFile(key).remove();
}

void Keys::addPath(QString &key) const {
    key = _path.filePath(key);
}
