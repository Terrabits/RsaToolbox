#ifndef LASTPATH_H
#define LASTPATH_H


#include "Keys.h"

#include <QString>
#include <QDir>
#include <QSharedPointer>

namespace RsaToolbox {
class LastPath;
typedef QSharedPointer<LastPath> SharedLastPath;
SharedLastPath newLastPath();
SharedLastPath newLastPath(QString initialPath);
SharedLastPath newLastPath(Keys *keys, QString key, QString initialPath = "");
SharedLastPath newLastPath(const LastPath &other);

class LastPath
{
public:
    LastPath();
    LastPath(QString initialPath);
    LastPath(Keys *keys, QString key, QString initialPath = "");
    LastPath(const LastPath &other);

    // Save state:
    bool isKey() const;
    QString key() const;
    Keys *keys() const;
    void setKey(Keys *keys, QString key);

    // LastPath:
    bool isEmpty() const;
    bool exists() const;
    void setPath(const QString &toString);
    void setPath(const QDir &dir);
    void setPath(const QFileInfo &dir);
    void setFromFilePath(const QString &filePath);
    void setFromFilePath(const QFileInfo &filePath);

    void operator=(const LastPath &other);
    void operator=(const QString &toString);
    void operator=(const QDir &dir);
    void operator=(const QFileInfo &dir);

    QString toString() const;
    QDir toDir() const;
    QFileInfo toFileInfo() const;
    operator QString() const;
    operator QDir() const;
    operator QFileInfo() const;

private:
    QString _path;
    QString _key;
    Keys *_keys;
};
} // RsaToolbox


#endif // LASTPATH_H
