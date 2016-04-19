

#include "Keys.h"
#include "LastPath.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_LastPath : public QObject
{
    Q_OBJECT

public:
    test_LastPath();

private:
    QDir src;
    QDir filesDir;

    Keys keys;
    QString key1;
    QString key2;
    QFileInfo key1Path;
    QFileInfo key2Path;

    QString path1;
    QString path2;
    QString path3;
    QString filePathName3;


private Q_SLOTS:
    void init();
    void cleanup();

    void constructor();
    void loadKey();
    void saveKey();
    void setFromFile();
    void operators();
    void shared();
};

test_LastPath::test_LastPath() :
    src(SOURCE_DIR),
    filesDir(QDir(QDir(src.filePath("Files")).filePath("LastPath"))),
    keys(filesDir.path()),
    key1("KEY_1"),
    key2("KEY_2"),
    key1Path(filesDir.filePath(key1)),
    key2Path(filesDir.filePath(key2)),
    path1("C:/Path1"),
    path2("C:/Path2"),
    path3("C:/Path3"),
    filePathName3("C:/Path3/filename.ext")
{
    if (!filesDir.exists())
        QDir(src.filePath("Files")).mkpath("LastPath");
}

void test_LastPath::init() {
    if (key1Path.exists()) {
        filesDir.remove(key1);
        filesDir.refresh();
        key1Path.refresh();
    }
    if (key2Path.exists()) {
        filesDir.remove(key2);
        filesDir.refresh();
        key2Path.refresh();
    }
    QVERIFY(!key1Path.exists());
    QVERIFY(!key2Path.exists());
}
void test_LastPath::cleanup() {
    if (key1Path.exists())
        filesDir.remove(key1);
    if (key2Path.exists())
        filesDir.remove(key2);
}

void test_LastPath::constructor() {
    LastPath last1;
    QVERIFY(last1.isEmpty());
    QVERIFY(!last1.isKey());
    QVERIFY(last1.keys() == NULL);
    QVERIFY(last1.key().isEmpty());
    QVERIFY(last1.toString().isEmpty());

    LastPath last2(path1);
    QVERIFY(!last2.isEmpty());
    QVERIFY(!last2.isKey());
    QVERIFY(last1.keys() == NULL);
    QVERIFY(last1.key().isEmpty());
    QCOMPARE(last2.toString(), path1);

    LastPath last3(&keys, key1);
    QVERIFY(last3.isEmpty());
    QVERIFY(last3.isKey());
    QVERIFY(last3.keys() == &keys);
    QVERIFY(last3.key() == key1);
    QVERIFY(last3.toString().isEmpty());

}
void test_LastPath::loadKey() {
    keys.Set(key1, path1);
    QVERIFY(keys.Exists(key1));
    QVERIFY(key1Path.exists());

    QString value;
    QVERIFY(keys.Get(key1, value));
    QCOMPARE(value, path1);

    LastPath last(&keys, key1);
    QVERIFY(!last.isEmpty());
    QVERIFY(last.isKey());
    QVERIFY(last.keys() == &keys);
    QVERIFY(last.key() == key1);
    QCOMPARE(last.toString(), path1);
}
void test_LastPath::saveKey() {
    QVERIFY(!keys.Exists(key1));
    QVERIFY(!key1Path.exists());

    LastPath last(&keys, key1);
    QVERIFY(last.isEmpty());
    QVERIFY(last.isKey());
    QVERIFY(last.keys() == &keys);
    QVERIFY(last.key() == key1);
    QCOMPARE(last.toString(), QString());

    last.setPath(path1);
    QVERIFY(keys.Exists(key1));
    QVERIFY(key1Path.exists());
    QString value;
    QVERIFY(keys.Get(key1, value));
    QCOMPARE(value, path1);
    QCOMPARE(last.toString(), path1);

}
void test_LastPath::setFromFile() {
    LastPath last(&keys, key1);
    QVERIFY(last.isEmpty());
    QVERIFY(last.isKey());
    QVERIFY(last.keys() == &keys);
    QVERIFY(last.key() == key1);
    QCOMPARE(last.toString(), QString());

    last.setFromFilePath(filePathName3);
    QVERIFY(keys.Exists(key1));
    QVERIFY(key1Path.exists());
    QString value;
    QVERIFY(keys.Get(key1, value));
    QCOMPARE(value, path3);
    QCOMPARE(last.toString(), path3);

}
void test_LastPath::operators() {
    LastPath last(&keys, key1);
    QVERIFY(last.isEmpty());
    QVERIFY(last.isKey());
    QVERIFY(last.keys() == &keys);
    QVERIFY(last.key() == key1);
    QCOMPARE(last.toString(), QString());

    last.setPath(path1);
    QVERIFY(keys.Exists(key1));
    QVERIFY(key1Path.exists());
    QString value;
    QVERIFY(keys.Get(key1, value));
    QCOMPARE(value, path1);
    QCOMPARE(last.toString(), path1);
    QCOMPARE(last.toDir(), QDir(path1));
    QCOMPARE(last.toFileInfo(), QFileInfo(path1));
}
void test_LastPath::shared() {
    SharedLastPath sharedPath = newLastPath();
    QVERIFY(!sharedPath.isNull());
    QVERIFY(sharedPath->isEmpty());

    sharedPath->setPath(path1);
    QCOMPARE(sharedPath->toString(), path1);
    sharedPath.reset();
    QVERIFY(sharedPath.isNull());
}


QTEST_APPLESS_MAIN(test_LastPath)
#include "test_LastPath.moc"


