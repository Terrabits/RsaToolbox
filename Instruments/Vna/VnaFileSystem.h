#ifndef VNAFILESYSTEM_H
#define VNAFILESYSTEM_H


#include "Definitions.h"

#include <QObject>
#include <QScopedPointer>



namespace RsaToolbox {
class Vna;

enum VnaDirectory {
    DEFAULT_DIRECTORY,
    EMBED_DIRECTORY,
    DEEMBED_DIRECTORY,
    CAL_GROUP_DIRECTORY,
    CAL_KIT_DIRECTORY,
    EXTERNAL_TOOLS_DIRECTORY,
    RECALL_SETS_DIRECTORY,
    TRACES_DIRECTORY };

class VnaFileSystem : public QObject
{
private: Q_OBJECT

public:
    explicit VnaFileSystem(QObject *parent = 0);
    VnaFileSystem(VnaFileSystem &other);
    VnaFileSystem(Vna *_vna, QObject *parent = 0);

    bool isFile(QString pathName);
    bool isNotFile(QString pathName);
    bool isDirectory(QString pathName);
    bool isNotDirectory(QString pathName);
    bool isFreeSpace(quint64 bytes);
    bool isFreeSpace(QString path, quint64 bytes);

    QStringList files();
    QStringList files(QString path);
    QStringList directories();
    QStringList directories(QString path);
    quint64 freeSpace_Bytes();
    quint64 freeSpace_Bytes(QString path);
    uint fileSize_Bytes(QString pathName);

    QString directory();
    QString directory(VnaDirectory directory);
    void changeDirectory(QString path);
    void changeDirectory(VnaDirectory directory);

    void createDirectory(QString pathName);
    void moveFile(QString sourcePathName, QString destinationPathName);
    void copyFile(QString sourcePathName, QString destinationPathName);

    void deleteFile(QString pathName);
    void deleteFiles(QStringList pathNames);
    void deleteFiles(QString path);
    void deleteFiles();
    void deleteDirectory(QString pathName);

    void uploadFile(QString sourcePathName, QString destinationPathName);
    void uploadFile(QString sourcePathName, QString destinationFilename, VnaDirectory destinationDirectory);
    void downloadFile(QString sourcePathName, QString destinationPathName);
    void downloadFile(QString sourcePathName, QString destinationPathName, uint bufferSize_B);
    void downloadFile(QString sourceFilename, VnaDirectory sourceDirectory, QString destinationPathName);
    void downloadFile(QString sourceFilename, VnaDirectory sourceDirectory, QString destinationPathName, uint bufferSize_B);

    void operator=(VnaFileSystem const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;

    QString dir();
    void dir(quint64 &totalFileSize_B, quint64 &freeSpace_B,
             QStringList &files, QVector<uint> &fileSizes_B,
             QStringList &directories);
};
}
Q_DECLARE_METATYPE(RsaToolbox::VnaDirectory)

#endif // VNAFILESYSTEM_H
