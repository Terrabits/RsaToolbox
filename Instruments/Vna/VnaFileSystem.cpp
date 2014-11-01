

#include "VnaFileSystem.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt
#include <QFileInfo>
#include <QDir>
#include <QFile>
#include <QByteArray>
#include <QScopedArrayPointer>
#include <QDebug>

/*!
 * \class RsaToolbox::VnaFileSystem
 * \ingroup VnaGroup
 * \brief The \c %VnaFileSystem class
 * manipulates the file system.
 */

VnaFileSystem::VnaFileSystem(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
}

VnaFileSystem::VnaFileSystem(VnaFileSystem &other)
{
    this->_vna = other._vna;
}

VnaFileSystem::VnaFileSystem(Vna *vna, QObject *parent) :
    QObject(parent)
{
    this->_vna = vna;
}

bool VnaFileSystem::isFile(QString pathName) {
    QFileInfo fileInfo(pathName);
    QString name = fileInfo.fileName();
    QString fileDirectory = fileInfo.path();
    fileDirectory = fileDirectory.replace("/", "\\") + "\\";

    if (fileDirectory.isEmpty() == false) {
        QString currentDirectory = directory();
        changeDirectory(fileDirectory);
        bool isPresent = files().contains(name, Qt::CaseInsensitive);
        changeDirectory(currentDirectory);
        return(isPresent);
    }
    else {
        return(files().contains(name, Qt::CaseInsensitive));
    }
}
bool VnaFileSystem::isNotFile(QString pathName) {
    return(!isFile(pathName));
}
bool VnaFileSystem::isDirectory(QString pathName) {
    if (pathName.isEmpty()== false &&
            (pathName.endsWith('\\') || pathName.endsWith('/')))
            pathName.chop(1);

    QFileInfo fileInfo(pathName);
    QString name = fileInfo.fileName();
    QString fileDirectory = fileInfo.path();
    fileDirectory = fileDirectory.replace("/", "\\") + "\\";

    if (fileDirectory.isEmpty() == false) {
        QString currentDirectory = directory();
        changeDirectory(fileDirectory);
        bool isPresent = directories().contains(name, Qt::CaseInsensitive);
        changeDirectory(currentDirectory);
        return(isPresent);
    }
    else {
        return(directories().contains(name, Qt::CaseInsensitive));
    }
}
bool VnaFileSystem::isNotDirectory(QString pathName) {
    return(!isDirectory(pathName));
}
bool VnaFileSystem::isFreeSpace(quint64 bytes) {
    return(freeSpace_Bytes() >= bytes);
}
bool VnaFileSystem::isFreeSpace(QString path, quint64 bytes) {
    QString currentDirectory = directory();
    changeDirectory(path);
    bool returnValue = isFreeSpace(bytes);
    changeDirectory(currentDirectory);
    return(returnValue);
}

QString VnaFileSystem::directory() {
    return(_vna->query(":MMEM:CDIR?\n").trimmed().remove('\''));
}
QString VnaFileSystem::directory(Directory directory) {
    QString currentDirectory = this->directory();
    changeDirectory(directory);
    QString returnValue = this->directory();
    changeDirectory(currentDirectory);
    return(returnValue);
}
QStringList VnaFileSystem::files() {
    quint64 totalFileSize_B;
    quint64 freeSpace_B;
    QStringList files;
    QVector<uint> fileSizes_B;
    QStringList directories;
    dir(totalFileSize_B, freeSpace_B,
        files, fileSizes_B,
        directories);
    return(files);
}
QStringList VnaFileSystem::files(QString path) {
    QString currentDirectory = directory();
    changeDirectory(path);
    QStringList returnValue = files();
    changeDirectory(currentDirectory);
    return(returnValue);
}
quint64 VnaFileSystem::freeSpace_Bytes() {
    quint64 totalFileSize_B;
    quint64 freeSpace_B;
    QStringList files;
    QVector<uint> fileSizes_B;
    QStringList directories;
    dir(totalFileSize_B, freeSpace_B,
        files, fileSizes_B,
        directories);
    return(freeSpace_B);
}
quint64 VnaFileSystem::freeSpace_Bytes(QString path) {
    QString currentDirectory = directory();
    changeDirectory(path);
    uint returnValue = freeSpace_Bytes();
    changeDirectory(currentDirectory);
    return(returnValue);
}
uint VnaFileSystem::fileSize_Bytes(QString pathName) {
    QFileInfo fileInfo(pathName);
    QString name = fileInfo.fileName();
    QString fileDirectory = fileInfo.path();
    fileDirectory = fileDirectory.replace("/", "\\") + "\\";

    QString currentDirectory = directory();
    changeDirectory(fileDirectory);

    quint64 totalFileSize_B;
    quint64 freeSpace_B;
    QStringList files;
    QVector<uint> fileSizes_B;
    QStringList directories;
    dir(totalFileSize_B, freeSpace_B,
        files, fileSizes_B,
        directories);
    changeDirectory(currentDirectory);
    if (files.contains(name, Qt::CaseInsensitive)) {
        int numberOfFiles = files.size();
        for (int i = 0; i < numberOfFiles; i++) {
            if (files[i].compare(name, Qt::CaseInsensitive) == 0)
                return(fileSizes_B[i]);
        }
        // else
        return(0);
    }
    else
        return(0);
}

QStringList VnaFileSystem::directories() {
    quint64 totalFileSize_B;
    quint64 freeSpace_B;
    QStringList files;
    QVector<uint> fileSizes_B;
    QStringList directories;
    dir(totalFileSize_B, freeSpace_B,
        files, fileSizes_B,
        directories);
    return(directories);
}
QStringList VnaFileSystem::directories(QString path) {
    QString currentDirectory = directory();
    changeDirectory(path);
    QStringList returnValue = directories();
    changeDirectory(currentDirectory);
    return(returnValue);
}

void VnaFileSystem:: changeDirectory(QString path) {
    QString scpi = ":MMEM:CDIR \'%1\'\n";
    scpi = scpi.arg(path);
    _vna->write(scpi);
}
void VnaFileSystem::changeDirectory(Directory directory) {
    switch(directory) {
    case DEFAULT_DIRECTORY:
        _vna->write(":MMEM:CDIR DEF\n");
        break;
    case EMBED_DIRECTORY:
        _vna->write(":MMEM:CDIR DEF\n");
        changeDirectory(".\\Embedding");
        break;
    case DEEMBED_DIRECTORY:
        _vna->write(":MMEM:CDIR DEF\n");
        changeDirectory(".\\Deembedding");
        break;
    case CAL_GROUP_DIRECTORY:
        _vna->write(":MMEM:CDIR DEF\n");
        changeDirectory(".\\Calibration\\Data");
        break;
    case CAL_KIT_DIRECTORY:
        _vna->write(":MMEM:CDIR DEF\n");
        changeDirectory(".\\Calibration\\Kits");
        break;
    case EXTERNAL_TOOLS_DIRECTORY:
        _vna->write(":MMEM:CDIR DEF\n");
        changeDirectory(".\\External Tools");
        break;
    case RECALL_SETS_DIRECTORY:
        _vna->write(":MMEM:CDIR DEF\n");
        changeDirectory(".\\RecallSets");
        break;
    case TRACES_DIRECTORY:
        _vna->write(":MMEM:CDIR DEF\n");
        changeDirectory(".\\Traces");
        break;
    default:
        break;
    }
}

void VnaFileSystem::createDirectory(QString pathName) {
    QString scpi = ":MMEM:MDIR \'%1\'\n";
    scpi = scpi.arg(pathName);
    _vna->write(scpi);
}
void VnaFileSystem::moveFile(QString sourcePathName, QString destinationPathName) {
    QString scpi = ":MMEM:MOVE \'%1\',\'%2\'\n";
    scpi = scpi.arg(sourcePathName, destinationPathName);
    _vna->write(scpi);
}
void VnaFileSystem::copyFile(QString sourcePathName, QString destinationPathName) {
    QString scpi = ":MMEM:COPY \'%1\',\'%2\'\n";
    scpi = scpi.arg(sourcePathName, destinationPathName);
    _vna->write(scpi);
}

void VnaFileSystem::deleteFile(QString pathName) {
    QString scpi = ":MMEM:DEL \'%1\',FORC\n";
    scpi = scpi.arg(pathName);
    _vna->write(scpi);
}
void VnaFileSystem::deleteFiles(QStringList pathNames) {
    foreach (QString path, pathNames)
            deleteFile(path);
}
void VnaFileSystem::deleteFiles(QString path) {
    QString currentDirectory = directory();
    if (isDirectory(path)) {
        changeDirectory(path);
        deleteFiles();
        changeDirectory(currentDirectory);
    }
}
void VnaFileSystem::deleteFiles() {
    QStringList fileList = files();
    foreach (QString file, fileList)
        deleteFile(file);
}

void VnaFileSystem::deleteDirectory(QString pathName) {
    QString scpi = ":MMEM:RDIR \'%1\'\n";
    scpi = scpi.arg(pathName);
    _vna->write(scpi);
}

void VnaFileSystem::uploadFile(QString sourcePathName, QString destinationPathName) {
    QFileInfo sourceInfo(sourcePathName);
    if (sourceInfo.exists() == false)
        return;

    qint64 fileSize = sourceInfo.size();
    QString fileSizeString = QVariant(fileSize).toString();
    QString header = "#";
    header += QVariant(fileSizeString.size()).toString();
    header += fileSizeString;

    QByteArray blockData = header.toUtf8();
    QFile file(sourcePathName);
    file.open(QFile::ReadOnly);
    blockData += file.readAll();
    file.close();

    QString scpi = "\n:MMEM:DATA \'%1\', ";
    scpi = scpi.arg(destinationPathName);
    blockData = scpi.toUtf8() + blockData;
    blockData += "\n";
    _vna->binaryWrite(blockData);
}
void VnaFileSystem::uploadFile(QString sourcePathName, QString destinationFilename, Directory destinationDirectory) {
    QString currentDirectory = directory();
    changeDirectory(destinationDirectory);
    uploadFile(sourcePathName, destinationFilename);
    changeDirectory(currentDirectory);
}
void VnaFileSystem::downloadFile(QString sourcePathName, QString destinationPathName) {
    uint bufferSize = fileSize_Bytes(sourcePathName) + 20;
    downloadFile(sourcePathName, destinationPathName, bufferSize);
}
void VnaFileSystem::downloadFile(QString sourcePathName, QString destinationPathName, uint bufferSize_B) {
    if (isNotFile(sourcePathName))
        return;
    QFile file(destinationPathName);
    if (!file.open(QFile::WriteOnly))
        return;
    if (bufferSize_B < 20)
        bufferSize_B = 20;

    QString scpi = ":MMEM:DATA? \'%1\'\n";
    scpi = scpi.arg(sourcePathName);
    _vna->write(scpi);

    uint bytesRead;
    QScopedArrayPointer<char> buffer(new char[bufferSize_B]);
    _vna->binaryRead(buffer.data(), bufferSize_B, bytesRead);
    if (bytesRead <= 0) {
        file.close();
        return;
    }

    // Header
    QByteArray result = QByteArray::fromRawData(buffer.data(), bytesRead);
    if (result.at(0) != '#') {
        file.close();
        return;
    }
    uint sizeSize = result.mid(1,1).toUInt();
    uint headerSize = 2 + sizeSize;
    qint64 bytesLeft = result.mid(2, sizeSize).toUInt();
    if (bytesLeft <= 0) {
        file.close();
        return;
    }

    if (bytesRead < headerSize) {
        file.close();
        return;
    }
    bytesRead -= headerSize;
    result = QByteArray::fromRawData(buffer.data() + headerSize, bytesRead);
    do {
        if (bytesRead >= bytesLeft) {
            file.write(result.mid(0, bytesLeft));
            bytesLeft = 0;
        }
        else {
            file.write(result);
            bytesLeft -= bytesRead;
            _vna->binaryRead(buffer.data(), bufferSize_B, bytesRead);
            result = QByteArray::fromRawData(buffer.data(), bytesRead);
        }
    } while (bytesLeft > 0 && bytesRead > 0);
    file.close();
}
void VnaFileSystem::downloadFile(QString sourceFilename, Directory sourceDirectory, QString destinationPathName) {
    QString currentDirectory = directory();
    changeDirectory(sourceDirectory);
    downloadFile(sourceFilename, destinationPathName);
    changeDirectory(currentDirectory);
}
void VnaFileSystem::downloadFile(QString sourceFilename, Directory sourceDirectory, QString destinationPathName, uint bufferSize_B) {
    QString currentDirectory = directory();
    changeDirectory(sourceDirectory);
    downloadFile(sourceFilename, destinationPathName, bufferSize_B);
    changeDirectory(currentDirectory);
}

void VnaFileSystem::operator=(VnaFileSystem const &other) {
    this->_vna = other._vna;
}

// private
QString VnaFileSystem::dir() {
    return(_vna->query(":MMEM:CAT?\n", 10000, 1000).trimmed());
}
void VnaFileSystem::dir(quint64 &totalFileSize_B, quint64 &freeSpace_B,
                        QStringList &files, QVector<uint> &fileSizes_B,
                        QStringList &directories) {
    QStringList list = dir().split(",");
    if (list.size() < 2)
        return;

    files.clear();
    fileSizes_B.clear();
    directories.clear();

    totalFileSize_B = list.takeFirst().trimmed().toULongLong();
    freeSpace_B = list.takeFirst().trimmed().toULongLong();
    int listSize = list.size();

    bool isError = false;

    for (int i = 0; i+2 < listSize; i += 3) {
        if (list[i+1].contains("<Dir>", Qt::CaseInsensitive)) {
            directories << list[i].trimmed();
        }
        else if (list[i+1] == " ") {
            files << list[i].trimmed();
            fileSizes_B << list[i+2].trimmed().toUInt();
        }
        else {
            // possible mis-read;
            isError = true;
        }
    }

    if (isError && _vna->isLogConnected()) {
        _vna->log()->print(QString()
                           + "This MMEM:DIR? call may have failed because one of the files\n"
                           + "in the directory contains a \',\' in the file name. This is a\n"
                           + "limitation of the SCPI command, which happens to use comma separators.\n\n");
    }
}
