#ifndef TESTRUNNER_H
#define TESTRUNNER_H


// Modified from Stack Overflow:
// http://stackoverflow.com/questions/1524390/what-unit-testing-framework-should-i-use-for-qt
// Specifically, from answer:
// http://stackoverflow.com/a/12683094/1390788
//   by mlvjr


// Qt
#include <QList>
#include <QStringList>
#include <QObject>


namespace RsaToolbox {

class TestRunner: public QObject
{
    Q_OBJECT

public:
    TestRunner(QObject *parent = 0);
    ~TestRunner();

    void addTest(QObject * test, const QStringList &args = QStringList());
    bool runTests();

private slots:
    void run();

private:
    bool _allTestsPassed;
    QList<QObject*> _tests;
    QList<QStringList> _args;

    void doRunTests();
}; // TestRunner

} // RsaToolbox


#endif // TESTRUNNER_H
