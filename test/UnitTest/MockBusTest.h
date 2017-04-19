#ifndef MOCKBUSTEST_H
#define MOCKBUSTEST_H


// RsaToolbox
#include <TestClass.h>

// Qt
#include <QObject>


class MockBusTest : public RsaToolbox::TestClass
{
    Q_OBJECT

public:
    MockBusTest();

private slots:
    void read_data();
    void read();

    void write_data();
    void write();

};

#endif // MOCKBUSTEST_H
