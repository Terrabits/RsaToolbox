#ifndef TESTCLASS_H
#define TESTCLASS_H


// Qt
#include <QObject>


namespace RsaToolbox {

class TestClass : public QObject
{
    Q_OBJECT
public:
    explicit TestClass(QObject *parent = 0);
    ~TestClass();

private slots:
    // Once
    virtual void initTestCase();
    virtual void cleanupTestCase();

    // Per test
    virtual void init();
    virtual void cleanup();
};
}

#endif // TESTCLASS_H
