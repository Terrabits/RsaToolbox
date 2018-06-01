#ifndef VISABUSTEST_H
#define VISABUSTEST_H

// RsaToolbox
#include "TestClass.h"

// Qt
#include <QObject>

class VisaBusTest : public RsaToolbox::TestClass
{
    Q_OBJECT
public:
    explicit VisaBusTest(QObject *parent = nullptr);

private slots:
    void isVisa();
    void cannotConnect_data();
    void cannotConnect();

    void connect();
};

#endif // VISABUSTEST_H
