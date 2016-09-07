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
    Keys(QString path);

    bool exists(QString key) const;
    bool doesNotExist(QString key) const;
    bool isTrue(QString key);
    bool isFalse(QString key);
    QString path() const;

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
    bool remove(QString key);

private:
    QDir _path;
    void addPath(QString &key) const;
};
} // RsaToolbox


#endif // KEYS_H


