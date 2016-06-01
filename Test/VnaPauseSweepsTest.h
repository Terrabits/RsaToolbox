#ifndef VNAPAUSESWEEPSTEST_H
#define VNAPAUSESWEEPSTEST_H


// RsaToolbox
#include "VnaTestClass.h"

// Qt
#include <QObject>


class VnaPauseSweepsTest : public RsaToolbox::VnaTestClass
{
    Q_OBJECT
public:
    explicit VnaPauseSweepsTest(QObject *parent = 0);
    explicit VnaPauseSweepsTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent = 0);
    ~VnaPauseSweepsTest();

private slots:
    virtual void initTestCase();

    void singleContinuousChannel();
    void singleManualChannel();
    void manyContinuousChannels();
    void manyManualChannels();
    void mixedChannels();
    void deletedChannels();
    void noPauseInConstructor();
    void noRestoreInConstructor();
    void manualOperation();
};


#endif // VNAPAUSESWEEPSTEST_H
