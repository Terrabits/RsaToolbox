#include <QDebug>


#include "Vna.h"
#include "TcpBus.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QDir>
#include <QFileInfo>

class test_VnaFileSystem : public QObject
{
    Q_OBJECT

public:
    test_VnaFileSystem();
    ~test_VnaFileSystem();

private:
    Vna vna;
    VnaFileSystem file;
    Log log;

    QString dllFile;
    QString textFile;
    QDir source;
    QDir dest;


    int cycle;

private Q_SLOTS:
    void init();
    void cleanup();

    void changeDirectory();
    void makeDir();
    void copyFile();
    void moveFile();
    void upload();
    void download();
    void vnaFunction();
};

test_VnaFileSystem::test_VnaFileSystem() {
    cycle = 0;
    file = VnaFileSystem(&vna);

    dllFile = "rsib32.dll";
    textFile = "Text.txt";

    source = QDir(SOURCE_DIR);
    source.cd("Files/VnaFileSystem/Source");

    dest = QDir(SOURCE_DIR);
    dest.cd("Files/VnaFileSystem/Destination");
    if (!dest.exists())
        QDir(SOURCE_DIR).mkpath("Files/VnaFileSystem/Destination");
}
test_VnaFileSystem::~test_VnaFileSystem() {
    if (dest.exists())
        dest.removeRecursively();
    QDir(SOURCE_DIR).mkpath("Files/VnaFileSystem/Destination");
}

void test_VnaFileSystem::init() {
    QString filename = QString("%1 init() Log.txt").arg(cycle++);
    Log log("../RsaToolboxTest/Results/VnaFileSystem Test Logs", filename, "test_VnaFileSystem", "0");
    log.printApplicationHeader();
    vna.resetBus(new TcpBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(&log);
    vna.printInfo();
    vna.preset();
    vna.clearStatus();
    vna.disconnectLog();
}
void test_VnaFileSystem::cleanup() {
    QString filename = QString("%1 cleanup() Log.txt").arg(cycle++);
    Log log("../RsaToolboxTest/Results/VnaFileSystem Test Logs", filename, "test_VnaFileSystem", "0");
    log.printApplicationHeader();
    vna.useLog(&log);
    vna.printInfo();
    file.changeDirectory(DEFAULT_DIRECTORY);
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaFileSystem::changeDirectory() {
    QString filename = QString("%1 changeDirectory() Log.txt").arg(cycle++);
    Log log("../RsaToolboxTest/Results/VnaFileSystem Test Logs", filename, "test_VnaFileSystem", "0");
    log.printApplicationHeader();
    vna.useLog(&log);
    vna.printInfo();
    file.changeDirectory(DEFAULT_DIRECTORY);
    QString defaultDir = file.directory();
    file.changeDirectory(CAL_GROUP_DIRECTORY);
    QCOMPARE(file.directory(), defaultDir + "\\Calibration\\Data");
    file.changeDirectory(CAL_KIT_DIRECTORY);
    QCOMPARE(file.directory(), defaultDir + "\\Calibration\\Kits");
    file.changeDirectory(EXTERNAL_TOOLS_DIRECTORY);
    QCOMPARE(file.directory(), defaultDir + "\\External Tools");
    file.changeDirectory(RECALL_SETS_DIRECTORY);
    QCOMPARE(file.directory(), defaultDir + "\\RecallSets");
    file.changeDirectory(TRACES_DIRECTORY);
    QCOMPARE(file.directory(), defaultDir + "\\Traces");
    QVERIFY(!vna.isError());
    vna.disconnectLog();
}

void test_VnaFileSystem::makeDir() {
    QString filename = QString("%1 makeDir() Log.txt").arg(cycle++);
    Log log("../RsaToolboxTest/Results/VnaFileSystem Test Logs", filename, "test_VnaFileSystem", "0");
    log.printApplicationHeader();
    vna.useLog(&log);
    vna.printInfo();

    QString dir = "Testing 123";

    file.changeDirectory(TRACES_DIRECTORY);
    QVERIFY(file.isNotDirectory(dir));
    file.createDirectory(dir);
    QVERIFY(file.isDirectory(dir));
    file.deleteDirectory(dir);
    QVERIFY(file.isNotDirectory(dir));

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}

void test_VnaFileSystem::copyFile() {
    QString filename = QString("%1 copyFile() Log.txt").arg(cycle++);
    Log log("../RsaToolboxTest/Results/VnaFileSystem Test Logs", filename, "test_VnaFileSystem", "0");
    log.printApplicationHeader();
    vna.useLog(&log);
    vna.printInfo();

    QString link = "GPIB Explorer.lnk";
    QString linkCopy = "..\\GPIB Explorer.lnk";

    file.changeDirectory(EXTERNAL_TOOLS_DIRECTORY);
    QVERIFY(file.isFile(link));
    if (file.isFile(linkCopy))
        file.deleteFile(linkCopy);
    QVERIFY(file.isNotFile(linkCopy));
    file.copyFile(link, linkCopy);
    QVERIFY(file.isFile(link));
    QVERIFY(file.isFile(linkCopy));
    file.deleteFile(linkCopy);

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}

void test_VnaFileSystem::moveFile() {
    QString filename = QString("%1 moveFile() Log.txt").arg(cycle++);
    Log log("../RsaToolboxTest/Results/VnaFileSystem Test Logs", filename, "test_VnaFileSystem", "0");
    log.printApplicationHeader();
    vna.useLog(&log);
    vna.printInfo();

    QString link = "GPIB Explorer.lnk";
    QString linkCopy = "..\\GPIB Explorer.lnk";
    QString linkMove = "..\\Traces\\GPIB Explorer.lnk";

    file.changeDirectory(EXTERNAL_TOOLS_DIRECTORY);
    QVERIFY(file.isFile(link));
    if (!file.isFile(linkCopy))
        file.copyFile(link, linkCopy);
    if (file.isFile(linkMove))
        file.deleteFile(linkMove);
    QVERIFY(file.isNotFile(linkMove));
    file.moveFile(linkCopy, linkMove);
    QVERIFY(file.isNotFile(linkCopy));
    QVERIFY(file.isFile(linkMove));
    file.deleteFile(linkMove);

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}

void test_VnaFileSystem::upload() {
    QString filename = QString("%1 upload() Log.txt").arg(cycle++);
    Log log("../RsaToolboxTest/Results/VnaFileSystem Test Logs", filename, "test_VnaFileSystem", "0");
    log.printApplicationHeader();
    vna.useLog(&log);
    vna.printInfo();

    file.changeDirectory(EXTERNAL_TOOLS_DIRECTORY);
    if (file.isFile(dllFile))
        file.deleteFile(dllFile);
    QVERIFY(file.isNotFile(dllFile));
    if (file.isFile(textFile))
        file.deleteFile(textFile);
    QVERIFY(file.isNotFile(textFile));

    file.uploadFile(source.filePath(textFile), textFile);
    QVERIFY(!vna.isError());
    QVERIFY(file.isFile(textFile));
    QCOMPARE(qint64(file.fileSize_Bytes(textFile)), QFileInfo(source.filePath(textFile)).size());
    file.deleteFile(textFile);

    file.uploadFile(source.filePath(dllFile), dllFile);
    QVERIFY(!vna.isError());
    QVERIFY(file.isFile(dllFile));
    QCOMPARE(qint64(file.fileSize_Bytes(dllFile)), QFileInfo(source.filePath(dllFile)).size());
    file.deleteFile(dllFile);

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}

void test_VnaFileSystem::download() {
    QString filename = QString("%1 download() Log.txt").arg(cycle++);
    Log log("../RsaToolboxTest/Results/VnaFileSystem Test Logs", filename, "test_VnaFileSystem", "0");
    log.printApplicationHeader();
    vna.useLog(&log);
    vna.printInfo();

    file.changeDirectory(EXTERNAL_TOOLS_DIRECTORY);
    if (file.isNotFile(dllFile))
        file.uploadFile(source.filePath(dllFile), dllFile);
    QVERIFY(file.isFile(dllFile));
    if (file.isNotFile(textFile))
        file.uploadFile(source.filePath(textFile), textFile);
    QVERIFY(file.isFile(textFile));

    file.downloadFile(textFile, dest.filePath(textFile));
    QVERIFY(!vna.isError());
    QVERIFY(dest.exists(textFile));
    QCOMPARE(QFileInfo(dest.filePath(textFile)).size(), QFileInfo(source.filePath(textFile)).size());
    dest.remove(textFile);

    file.downloadFile(dllFile, dest.filePath(dllFile));
    QVERIFY(!vna.isError());
    QVERIFY(dest.exists(dllFile));
    QCOMPARE(QFileInfo(dest.filePath(dllFile)).size(), QFileInfo(source.filePath(dllFile)).size());
    dest.remove(dllFile);


    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaFileSystem::vnaFunction() {
    QString filename = QString("%1 vnaFunction() Log.txt").arg(cycle++);
    Log log("../RsaToolboxTest/Results/VnaFileSystem Test Logs", filename, "test_VnaFileSystem", "0");
    log.printApplicationHeader();
    vna.useLog(&log);
    vna.printInfo();

    QScopedPointer<VnaFileSystem> file(vna.takeFileSystem());
    QVERIFY(file.isNull() == false);
    QVERIFY(file->freeSpace_Bytes() > quint64(0));
    QVERIFY(file->isFreeSpace(1));
    QCOMPARE(file->freeSpace_Bytes(), vna.fileSystem().freeSpace_Bytes());

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}


QTEST_APPLESS_MAIN(test_VnaFileSystem)
#include "test_VnaFileSystem.moc"


