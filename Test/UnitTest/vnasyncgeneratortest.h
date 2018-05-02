#ifndef VNASYNCGENERATORTEST_H
#define VNASYNCGENERATORTEST_H

#include <GenericBus.h>
#include <VnaSyncGenerator.h>
#include <VnaTestClass.h>

#include <QObject>
#include <QString>

class VnaSyncGeneratorTest : public RsaToolbox::VnaTestClass
{
    Q_OBJECT
public:
    explicit VnaSyncGeneratorTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent = 0);

private slots:

    virtual void initTestCase();
    virtual void init();

    void stateTest_data();
    void stateTest();

    void pulseWidthTest_data();
    void pulseWidthTest();

    void periodTest_data();
    void periodTest();

    void invertedTest_data();
    void invertedTest();

    void channelSpecificTest_data();
    void channelSpecificTest();

private:
    RsaToolbox::VnaSyncGenerator _gen;
};

#endif // VNASYNCGENERATORTEST_H
