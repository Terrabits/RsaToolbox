

#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_VnaMarker : public QObject
{
    Q_OBJECT

public:
    test_VnaMarker();

private:
    Vna vna;
    // Object to test
    QScopedPointer<Log> log;

    int cycle;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void createMarker();
    void name();
    void coordinates();
    void max();
    void min();
    void searchRight();
    void searchLeft();

    void referenceMarker();
    void delta();
    //void measureBandpassFilter();

};

test_VnaMarker::test_VnaMarker() {
    cycle = 0;
    appName = "test_VnaMarker";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaMarker Logs";
    
    // Initialize object here
}

void test_VnaMarker::init() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion));
    log->printApplicationHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(log.data());
    vna.printInfo();
    vna.preset();
    vna.clearStatus();
    vna.disconnectLog();
}
void test_VnaMarker::cleanup() {
    vna.disconnectLog();
    log.reset(new Log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();
    
    // Specific cleanup
    
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaMarker::createMarker() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("createMarker()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(vna.trace().isNotMarkers());

    vna.trace().createMarker(1);
    QVERIFY(vna.trace().isMarker(1));
    QVERIFY(vna.trace().isMarkers());
    QVERIFY(vna.trace().markers().size() == 1);

    vna.trace().createMarker();
    QVERIFY(vna.trace().isMarker(2));
    QVERIFY(vna.trace().isMarkers());
    QVERIFY(vna.trace().markers().size() == 2);

    vna.trace().deleteMarker(1);
    QVERIFY(vna.trace().isNotMarker(1));
    QVERIFY(vna.trace().isMarker(2));
    QVERIFY(vna.trace().isMarkers());
    QVERIFY(vna.trace().markers().size() == 1);

    vna.trace().createMarker(3);
    QVERIFY(vna.trace().isMarker(2));
    QVERIFY(vna.trace().isMarker(3));
    QVERIFY(vna.trace().markers().size() == 2);

    vna.trace().deleteMarkers();
    QVERIFY(vna.trace().isNotMarkers());
    QVERIFY(vna.trace().markers().size() == 0);

    QVERIFY(vna.isError() == false);
}
void test_VnaMarker::name() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("name()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.trace().createMarker(1);
    QCOMPARE(vna.trace().marker(1).name(), QString("M1"));

    vna.trace().marker(1).setName("myMarker");
    QCOMPARE(vna.trace().marker(1).name(), QString("myMarker"));

    QVERIFY(vna.isError() == false);
}
void test_VnaMarker::coordinates() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("coordinates()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.channel().linearSweep().setStart(1, GIGA_PREFIX);
    vna.channel().linearSweep().setStop(2, GIGA_PREFIX);

    vna.trace().createMarker(1);
    vna.trace().marker(1).setX(1, GIGA_PREFIX);
    QCOMPARE(vna.trace().marker(1).x(), double(1E9));

    vna.trace().marker(1).setX(1.5, GIGA_PREFIX);
    QCOMPARE(vna.trace().marker(1).x(), double(1.5E9));

    double x, y;
    vna.trace().marker(1).setX(1.75E9);
    vna.trace().marker(1).coordinates(x, y);
    QCOMPARE(x, double(1.75E9));

    QVERIFY(vna.isError() == false);
}
void test_VnaMarker::max() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("max()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.channel().manualSweepOn();
    vna.startSweeps();
    vna.wait();

    vna.trace().createMarker(1);
    vna.trace().marker(1).searchForMax();

    double x, y;
    vna.trace().marker(1).coordinates(x, y);
    // How to verify?

    vna.trace().createMarker(2);
    vna.trace().marker(2).searchForMin();

    QVERIFY(vna.trace().marker(1).x() != vna.trace().marker(2).x());
    QVERIFY(vna.trace().marker(1).y() > vna.trace().marker(2).y());

    QVERIFY(vna.isError() == false);
}
void test_VnaMarker::min() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("min()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.channel().manualSweepOn();
    vna.startSweeps();
    vna.wait();

    vna.trace().createMarker(1);
    vna.trace().marker(1).searchForMin();

    double x, y;
    vna.trace().marker(1).coordinates(x, y);
    // How to verify?

    vna.trace().createMarker(2);
    vna.trace().marker(2).searchForMax();

    QVERIFY(vna.trace().marker(1).x() != vna.trace().marker(2).x());
    QVERIFY(vna.trace().marker(1).y() < vna.trace().marker(2).y());

    QVERIFY(vna.isError() == false);
}
void test_VnaMarker::searchRight() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("searchRight()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.channel().manualSweepOn();
    vna.startSweeps();
    vna.wait();

    double max;
    vna.trace().createMarker(1);
    vna.trace().marker(1).searchForMax();
    max = vna.trace().marker(1).y();

    double min;
    vna.trace().marker(1).searchForMin();
    min = vna.trace().marker(1).y();

    vna.trace().marker(1).setX(vna.channel().linearSweep().start_Hz());
    vna.trace().marker(1).searchRightFor((max - min)/2.0 + min);
    QCOMPARE(vna.trace().marker(1).y(), (max - min)/2.0 + min);

    vna.trace().marker(1).setX(vna.channel().linearSweep().start_Hz());
    vna.trace().marker(1).searchRightForPeak();
    double x, y;
    vna.trace().marker(1).coordinates(x, y);
    // How to verify?

    QVERIFY(vna.isError() == false);
}
void test_VnaMarker::searchLeft() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("searchLeft()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.channel().manualSweepOn();
    vna.startSweeps();
    vna.wait();

    double max;
    vna.trace().createMarker(1);
    vna.trace().marker(1).searchForMax();
    max = vna.trace().marker(1).y();

    double min;
    vna.trace().marker(1).searchForMin();
    min = vna.trace().marker(1).y();

    vna.trace().marker(1).setX(vna.channel().linearSweep().stop_Hz());
    vna.trace().marker(1).searchLeftFor((max - min)/2.0 + min);
    QCOMPARE(vna.trace().marker(1).y(), (max - min)/2.0 + min);

    vna.trace().marker(1).setX(vna.channel().linearSweep().stop_Hz());
    vna.trace().marker(1).searchLeftForPeak();
    double x, y;
    vna.trace().marker(1).coordinates(x, y);
    // How to verify?

    QVERIFY(vna.isError() == false);
}
void test_VnaMarker::referenceMarker() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("referenceMarker()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.channel().manualSweepOn();
    vna.startSweeps();
    vna.wait();

    QVERIFY(vna.trace().referenceMarker().isOff());

    vna.trace().referenceMarker().on();
    QVERIFY(vna.trace().referenceMarker().isOn());

    vna.trace().createMarker(1);
    vna.trace().marker(1).searchForMax();
    vna.trace().marker(1).setReferenceMarker();

    QCOMPARE(vna.trace().referenceMarker().x(), vna.trace().marker(1).x());
    QCOMPARE(vna.trace().referenceMarker().y(), vna.trace().marker(1).y());

    QVERIFY(vna.isError() == false);
}
void test_VnaMarker::delta() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("delta()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    vna.channel().manualSweepOn();
    vna.startSweeps();
    vna.wait();

    double min;
    vna.trace().createMarker(1);
    vna.trace().marker(1).searchForMin();
    min = vna.trace().marker(1).y();

    vna.trace().referenceMarker().on();
    vna.trace().marker(1).setReferenceMarker();

    double max;
    vna.trace().marker(1).searchForMax();
    max = vna.trace().marker(1).y();

    QVERIFY(vna.trace().marker(1).isDeltaOff());
    vna.trace().marker(1).deltaOn();
    QVERIFY(vna.trace().marker(1).isDeltaOn());
    QCOMPARE(vna.trace().marker(1).y(), max - min);

    QVERIFY(vna.isError() == false);
}


QTEST_APPLESS_MAIN(test_VnaMarker)
#include "test_VnaMarker.moc"


