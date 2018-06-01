#ifndef GENERICINSTRUMENTTEST_H
#define GENERICINSTRUMENTTEST_H

// RsaToolbox
#include "TestClass.h"

// Qt
#include <QObject>

class GenericInstrumentTest : public RsaToolbox::TestClass
{
    Q_OBJECT
public:
    explicit GenericInstrumentTest(QObject *parent = nullptr);

private slots:
    void cannotConnect_data();
    void cannotConnect();
};

#endif // GENERICINSTRUMENTTEST_H
