#ifndef VNAPULSEGENERATORTEST_H
#define VNAPULSEGENERATORTEST_H

#include <GenericBus.h>
#include <VnaPulseGenerator.h>
#include <VnaTestClass.h>

#include <QObject>
#include <QString>

class VnaPulseGeneratorTest : public RsaToolbox::VnaTestClass
{
    Q_OBJECT
public:
    explicit VnaPulseGeneratorTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent = 0);

private slots:

    virtual void initTestCase();
    virtual void init();

    void stateTest_data();
    void stateTest();

    void delayTest_data();
    void delayTest();

    void pulseWidthTest_data();
    void pulseWidthTest();

    void periodTest_data();
    void periodTest();

    void invertedTest_data();
    void invertedTest();

    void channelSpecificTest_data();
    void channelSpecificTest();

private:
    RsaToolbox::VnaPulseGenerator _gen;
};

#endif // VNAPULSEGENERATORTEST_H
