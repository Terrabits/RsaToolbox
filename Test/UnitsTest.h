#ifndef UNITSTEST_H
#define UNITSTEST_H


// RsaToolbox
#include "TestClass.h"

//Qt
#include <QObject>


class UnitsTest : public RsaToolbox::TestClass
{
    Q_OBJECT
public:
    explicit UnitsTest(QObject *parent = 0);

private slots:
    void units_data();
    void units();

    void prefix_data();
    void prefix();

    void formatValue_data();
    void formatValue();
};

#endif // UNITSTEST_H
