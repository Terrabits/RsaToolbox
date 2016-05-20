#ifndef VNATESTCLASS_H
#define VNATESTCLASS_H


// RsaToolbox
#include "Log.h"
#include "TestClass.h"
#include "Vna.h"
#include "VnaProperties.h"

// Qt
#include <QDir>
#include <QScopedPointer>
#include <QTest>


namespace RsaToolbox {

class VnaTestClass : public TestClass
{
    Q_OBJECT
public:
    explicit VnaTestClass(QObject *parent = 0);
    ~VnaTestClass();

protected:
    QString _applicationName;
    QString _version;

    QDir _logDir;
    QStringList _logFilenames;
    QScopedPointer<Log> _log;

    ConnectionType _connectionType;
    QString _address;
    QScopedPointer<Vna> _vna;

    bool isZnbFamily();
    bool isZvaFamily();
    VnaProperties::Model model();

    // Expose init and cleanup
    // methods

    // Once
    void _initTestCase();
    void _cleanupTestCase();

    // Per Test
    void _init();
    void _cleanup();

private slots:
    // Once
     virtual void initTestCase();
     virtual void cleanupTestCase();

    // Per test
    virtual void init();
    virtual void cleanup();

};
}
#endif // VNATESTCLASS_H
