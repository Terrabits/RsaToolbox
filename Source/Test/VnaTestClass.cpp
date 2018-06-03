#include "VnaTestClass.h"


// RsaToolbox
using namespace RsaToolbox;


VnaTestClass::VnaTestClass(QObject *parent) :
    TestClass(parent),
    _applicationName("Test"),
    _version("0.0"),
    _connectionType(ConnectionType::VisaTcpSocketConnection),
    _address("127.0.0.1::5025")
{
    //
}
VnaTestClass::VnaTestClass(ConnectionType type, const QString &address, QObject *parent) :
    TestClass(parent),
    _applicationName("Test"),
    _version("0.0"),
    _connectionType(type),
    _address(address)
{
    //
}
VnaTestClass::~VnaTestClass() {
    _vna.reset();
}

void VnaTestClass::setConnectionType(ConnectionType type) {
    _connectionType = type;
}
void VnaTestClass::setAddress(const QString &address) {
    _address = address;
}

bool VnaTestClass::isZnbFamily() {
    bool isNullPointer = _vna.isNull();
    if (isNullPointer) {
        _vna.reset(new Vna(_connectionType, _address));
    }

    bool isZnx = false;
    if (_vna->isOpen())
        isZnx = _vna->properties().isZnbFamily();

    if (isNullPointer)
        _vna.reset();
    return isZnx;
}
bool VnaTestClass::isZvaFamily() {
    bool isNull = _vna.isNull();
    if (isNull) {
        _vna.reset(new Vna(_connectionType, _address));
    }

    bool isZvx = false;
    if (_vna->isOpen())
        isZvx = _vna->properties().isZvaFamily();

    if (isNull)
        _vna.reset();
    return isZvx;
}

VnaProperties::Model VnaTestClass::model() {
    bool isNull = _vna.isNull();
    if (isNull) {
        _vna.reset(new Vna(_connectionType, _address));
    }

    VnaProperties::Model model = VnaProperties::Model::Unknown;
    if (_vna->isOpen())
        model = _vna->properties().model();

    if (isNull)
        _vna.reset();
    return model;
}

void VnaTestClass::_initTestCase() {
    _vna.reset(new Vna(_connectionType, _address));
    QVERIFY(_vna->isOpen());
    _vna.reset();

    if (_logDir == QDir()) {
        return;
    }

    if (_logDir.exists()) {
        for (int i = 0; i < 100 && _logDir.exists(); i++) {
            _logDir.removeRecursively();
        }
    }
    QVERIFY(!_logDir.exists());

    QDir parent = _logDir;
    parent.cdUp();
    parent.mkpath(_logDir.dirName());
    for (int i = 0; i < 100 && !_logDir.exists(); i++) {
        parent.mkpath(_logDir.dirName());
    }
    QVERIFY(_logDir.exists());
}
void VnaTestClass::_cleanupTestCase() {
    _vna.reset(new Vna(_connectionType, _address));
    if (_vna->isOpen()) {
        _vna->preset();
        _vna->pause();
        _vna->local();
    }
    _vna.reset();
}

void VnaTestClass::_init() {
    const QString logFile
            = _logDir.filePath(_logFilenames.takeFirst());
    _vna.reset(new Vna(_connectionType, _address));
    _vna->startLog(logFile, "", "0.0");

    QVERIFY(_vna->isOpen());

    _vna->clearStatus();
    _vna->preset();
    _vna->pause();
}
void VnaTestClass::_cleanup() {
    _vna->isError();
    _vna->clearStatus();
    _vna.reset();
}

void VnaTestClass::initTestCase() {
    _initTestCase();
}
void VnaTestClass::cleanupTestCase() {
    _cleanupTestCase();
}

void VnaTestClass::init() {
    _init();
}
void VnaTestClass::cleanup() {
    _cleanup();
}
