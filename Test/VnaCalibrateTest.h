#ifndef VNACALIBRATETEST_H
#define VNACALIBRATETEST_H


// RsaToolbox
#include "VnaTestClass.h"

// Qt
#include <QObject>


class VnaCalibrateTest : public RsaToolbox::VnaTestClass
{
    Q_OBJECT
public:
    explicit VnaCalibrateTest(QObject *parent = 0);
    explicit VnaCalibrateTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent = 0);
    ~VnaCalibrateTest();

private slots:
    virtual void initTestCase();

    void autoCalibrate();
};

#endif // VNACALIBRATETEST_H
