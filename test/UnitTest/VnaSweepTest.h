#ifndef VNASWEEPTEST_H
#define VNASWEEPTEST_H


// RsaToolbox
#include "Definitions.h"
#include "GenericBus.h"
#include "VnaTestClass.h"

// Qt
#include <QList>


class VnaSweepTest : public RsaToolbox::VnaTestClass
{
    Q_OBJECT
public:
    explicit VnaSweepTest(QObject *parent = 0);
    explicit VnaSweepTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent = 0);
    ~VnaSweepTest();

private slots:
    virtual void initTestCase();

    // Each test starts from preset,
    // plus the following:
    //   Ch1: Trc1
    //   Ch2: Trc2
    //   Ch3: Trc3
    //   Ch4: Trc4
    //   Diagrams: 1
    // All channels continuous sweep
    virtual void init();

    void basic();

private:
    QList<RsaToolbox::ComplexRowVector> _data;
    QList<RsaToolbox::ComplexRowVector> retrieveData();
    void rememberData();
    bool isNewDataOnlyInChannel(uint channel);
    bool isAllNewData();
    bool isNoNewData ();
};

#endif // VNASWEEPTEST_H
