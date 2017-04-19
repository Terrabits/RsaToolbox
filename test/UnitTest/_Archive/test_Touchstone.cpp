

#include "General.h"
#include "Touchstone.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QtTest>
#include <QDir>

class test_Touchstone : public QObject
{
    Q_OBJECT

public:
    test_Touchstone();

private:
    QDir path;

private Q_SLOTS:
    void init();
    void cleanup();

    void ports();
    void read();
    void write();
};

test_Touchstone::test_Touchstone() {
    path = QDir(SOURCE_DIR);
    path.cd("Touchstone Files");
}

void test_Touchstone::init() {

}
void test_Touchstone::cleanup() {

}

void test_Touchstone::ports() {
    QVERIFY(path.exists("Maximum.s2p"));
    QCOMPARE(Touchstone::ports(path.filePath("Maximum.s2p")), uint(2));
    QCOMPARE(Touchstone::ports(path.filePath("Minimum.s2p")), uint(2));
    QCOMPARE(Touchstone::ports("My craaaazy filename.s5p"), uint(5));
    QCOMPARE(Touchstone::ports(""), uint(0));
}
void test_Touchstone::read() {
    NetworkData data;
    Touchstone::Read(data, path.filePath("Maximum.s2p"));

    QCOMPARE(data.numberOfPorts(), uint(2));
    QCOMPARE(data.points(), uint(8));
    QCOMPARE(data.x().first(), 1.0E9);
    QCOMPARE(data.x().last(), 8.0E9);
    QCOMPARE(data.y_dB(1,1).first(), -8.0);
    QCOMPARE(data.y_phase_deg(2,2).first(), 0.0);
    QCOMPARE(data.y_dB(1,1).last(), -8.0);
    QCOMPARE(data.y_dB(2,1).last(), -1.0);
}
void test_Touchstone::write() {
    QCOMPARE("Did you finish this?", "Yes");
}


QTEST_APPLESS_MAIN(test_Touchstone)
#include "test_Touchstone.moc"


