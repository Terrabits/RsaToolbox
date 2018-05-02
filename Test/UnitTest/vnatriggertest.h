#ifndef VNATRIGGERTEST_H
#define VNATRIGGERTEST_H

#include <VnaTestClass.h>

#include <QObject>

class VnaTriggerTest : public RsaToolbox::VnaTestClass
{
    Q_OBJECT
public:
    explicit VnaTriggerTest(QObject *parent = 0);
    explicit VnaTriggerTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent=0);

private slots:
    virtual void init();

    void sourceTest_data();
    void sourceTest();

    void manualTriggerTest_data();
    void manualTriggerTest();

    void onEdgeTest_data();
    void onEdgeTest();

    void sequenceTest_data();
    void sequenceTest();

    void delayTest_data();
    void delayTest();

private:
    RsaToolbox::VnaTrigger _trigger;
};

#endif // VNATRIGGERTEST_H
