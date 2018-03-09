#include "vnaundotest.h"
using namespace RsaToolbox;

#include "VnaUndo.h"
#include <QScopedPointer>

VnaUndoTest::VnaUndoTest(QObject *parent) : VnaTestClass(parent)
{

}

VnaUndoTest::VnaUndoTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent) :
    VnaTestClass(type, address, parent)
{
    _logDir.setPath(SOURCE_DIR);
    _logDir.mkpath("VnaUndoTest");
    _logDir.cd("VnaUndoTest");
    _logDir.setFilter(QDir::Files);
    foreach (const QString file, _logDir.entryList()) {
        _logDir.remove(file);
    }
    _logFilenames << "directory handling test log.txt";
}

void VnaUndoTest::directoryHandlingTest() {
    VnaFileSystem fs = _vna->fileSystem();
    fs.changeDirectory(VnaFileSystem::Directory::DEFAULT_DIRECTORY);
    if (!fs.isDirectory("__TEMP__")) {
        fs.createDirectory("__TEMP__");
        _vna->pause();
    }
    QVERIFY(fs.isDirectory("__TEMP__"));
    QVERIFY(!_vna->isError());

    fs.changeDirectory("__TEMP__");
    _vna->pause();
    QVERIFY(!_vna->isError());

    QScopedPointer<VnaUndo> undo(new VnaUndo(_vna.data(), true));
    QVERIFY(!_vna->isError());

    undo.reset();
    QVERIFY(!_vna->isError());
}
