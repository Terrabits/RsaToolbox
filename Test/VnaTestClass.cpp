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

void VnaTestClass::init() {
    _vna.reset(new Vna(_connectionType, _address));
    const QString logFilename = _logDir.filePath(_logFilenames.takeFirst());
    _log.reset(new Log(_logFilenames.takeFirst(), "", "0.0"));

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
    _vna.reset();

    _log->close();
    _log.reset();
}
