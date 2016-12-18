#ifndef VNATRACETEST_H
#define VNATRACETEST_H


// RsaToolbox
#include <VnaTestClass.h>

// Qt
#include <QObject>


class VnaTraceTest : public RsaToolbox::VnaTestClass
{
    Q_OBJECT
public:
    explicit VnaTraceTest(QObject *parent = 0);
    explicit VnaTraceTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent = 0);
    ~VnaTraceTest();

private slots:
    virtual void initTestCase();

    // Additional tests
    // ...

private:


};

#endif // VNATRACETEST_H
