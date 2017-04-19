#ifndef VNAARBITRARYFREQUENCYTEST_H
#define VNAARBITRARYFREQUENCYTEST_H


// RsaToolbox
#include "GenericBus.h"
#include "VnaTestClass.h"

// Qt
#include <QObject>
#include <QString>


class VnaArbitraryFrequencyTest : public RsaToolbox::VnaTestClass
{
    Q_OBJECT
public:
    explicit VnaArbitraryFrequencyTest(RsaToolbox::ConnectionType type, QString address, QObject *parent = 0);
    ~VnaArbitraryFrequencyTest();

    virtual void initTestCase();

private slots:
    void structTest     ();
    void portRfOff      ();
    void portAsGenerator();
    void portSourceArbFreq();
    void receiverArbFreq();
    void generatorRfOff ();
    void generatorPerm  ();

private:
    void create2ndChannel();

};

#endif // VNAARBITRARYFREQUENCYTEST_H
