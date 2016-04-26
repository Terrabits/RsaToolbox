#include "VnaTestClass.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QTest>


VnaTestClass::VnaTestClass(QObject *parent) :
    TestClass(parent),
    _applicationName("Test"),
    _version("0.0"),
    _connectionType(ConnectionType::VisaTcpSocketConnection),
    _address("127.0.0.1::5025")
{
    //
}
VnaTestClass::~VnaTestClass() {
    _vna.reset();
    _log.reset();
}

void VnaTestClass::initTestCase() {
    if (_logDir == QDir())
        return;

    if (!_logDir.exists()) {
        QDir dir(_logDir);
        dir.cdUp();
        dir.mkpath(_logDir.dirName());
    }
    else {
        foreach (QString file, _logDir.entryList(QDir::Files)) {
            _logDir.remove(file);
        }
    }

    _vna.reset(new Vna(_connectionType, _address));
    QVERIFY(_vna->isConnected());
    _vna.reset();
}
void VnaTestClass::cleanupTestCase() {
    _vna.reset();
    _log.reset();
}

void VnaTestClass::init() {
    _vna.reset(new Vna(_connectionType, _address));
    const QString logFilename = _logDir.filePath(_logFilenames.takeFirst());
    _log.reset(new Log(logFilename, "", "0.0"));

    _log->printHeader();
    _vna->useLog(_log.data());
    _vna->printInfo();

    QVERIFY(_vna->isConnected());

    _vna->clearStatus();
    _vna->preset();
    _vna->pause();
}
void VnaTestClass::cleanup() {
    _vna->isError();
    _vna->clearStatus();
    _vna->local();
    _vna.reset();

    _log->close();
    _log.reset();
}
