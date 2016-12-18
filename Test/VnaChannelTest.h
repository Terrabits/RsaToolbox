#ifndef VNACHANNELTEST_H
#define VNACHANNELTEST_H


// RsaToolbox
#include <VnaTestClass.h>

// Qt
#include <QObject>


class VnaChannelTest : public RsaToolbox::VnaTestClass
{
    Q_OBJECT
public:
    explicit VnaChannelTest(QObject *parent = 0);
    explicit VnaChannelTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent = 0);
    ~VnaChannelTest();

private slots:
    virtual void initTestCase();

    // Additional tests
    // ...

private:

};

#endif // VNACHANNELTEST_H
