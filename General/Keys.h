#ifndef KEYS_H
#define KEYS_H


// Rsa
#include "General.h"

// Qt
#include <QDir>
#include <QString>
#include <QFile>
#include <QDataStream>
#include <QDebug>


namespace RsaToolbox {

class Keys {

public:
    // Constructor
    Keys(QString path) {
        _path = QDir(path);
    }

    bool exists(QString key) {
        addPath(key);
        return QFile(key).exists();
    }
    bool doesNotExist(QString key) {
        return !exists(key);
    }
    bool isTrue(QString key) {
        bool isTrue;
        if (!get(key, isTrue))
            return false;
        else
            return isTrue;
    }
    bool isFalse(QString key) {
        return !isTrue(key);
    }
    QString path() const {
        return _path.path();
    }

    template <class T>
    bool get(QString key, T &value) {
        addPath(key);
        QFile file(key);
        if (!file.open(QIODevice::ReadOnly))
            return false;

        QDataStream keyfile(&file);
        keyfile >> value;
        file.close();
        return true;
    }
    template <class T>
    bool set(QString key, T value) {
        addPath(key);
        QFile file(key);
        if (!file.open(QIODevice::WriteOnly))
            return false;

        QDataStream keyfile(&file);
        keyfile << value;
        file.close();
        return true;
    }
    bool remove(QString key) {
        addPath(key);
        return QFile(key).remove();
    }

private:
    QDir _path;
    void addPath(QString &key) {
        key = _path.filePath(key);
    }
};
} // RsaToolbox


#endif // KEYS_H


