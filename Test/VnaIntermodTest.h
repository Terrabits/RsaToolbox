#ifndef VnaIntermodTest_H
#define VnaIntermodTest_H


// RsaToolbox
#include "VnaTestClass.h"

// Qt
#include <QObject>


class VnaIntermodTest : public RsaToolbox::VnaTestClass
{
    Q_OBJECT
public:
    explicit VnaIntermodTest(QObject *parent = 0);
    explicit VnaIntermodTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent = 0);
    ~VnaIntermodTest();

private slots:
    virtual void initTestCase();

    void basicTest();

};


#endif // VnaIntermodTest_H
