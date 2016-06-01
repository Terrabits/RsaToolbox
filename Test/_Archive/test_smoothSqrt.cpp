

#include "General.h"
#include "Log.h"
#include "Figure.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>
#include <QWidget>
#include <QDialog>

ComplexRowVector makeComplex(QRowVector mag, QRowVector phase_rad);

class test_smoothSqrt : public QObject
{
    Q_OBJECT

public:
    test_smoothSqrt();

private:
    QScopedPointer<Log> log;

    int cycle;
    QString appName;
    QString appVersion;
    QString plotFilename;
    QString logFilename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void unwrap_data();
    void unwrap();
    void wrap_data();
    void wrap();
    void smoothSqrt_data();
    void smoothSqrt();
    void phaseAtDc_data();
    void phaseAtDc();
    void fixPhaseAtDc_data();
    void fixPhaseAtDc();
};

test_smoothSqrt::test_smoothSqrt() {
    cycle = 0;
    appName = "test_smoothSqrt";
    appVersion = "0";
    plotFilename = "%1 %2.png";
    logFilename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/smoothSqrt Logs";
    
    // Initialize object here
}

void test_smoothSqrt::init() {
//    log.reset(new Log(logPath, logFilename.arg(cycle++).arg("init()"), appName, appVersion));
//    log.reset();
}
void test_smoothSqrt::cleanup() {
//    log.reset(new Log(logPath, logFilename.arg(cycle++).arg("cleanup()"), appName, appVersion));
//    log.reset();
}


void test_smoothSqrt::unwrap_data() {
    QTest::addColumn<QString>("testCase");
    QTest::addColumn<QRowVector>("data");

    uint points = 201;
    QRowVector mag, phase;
    mag = linearSpacing(.99, 1, points);
    phase = linearSpacing(0, 0, points);
    QTest::newRow("Zero phase") << QString("Zero phase") << RsaToolbox::arg(makeComplex(mag, phase));

    points = 401;
    mag = linearSpacing(.9, 1, points);
    phase = linearSpacing(0, PI, points);
    QTest::newRow("Small phase") << QString("Small phase") << RsaToolbox::arg(makeComplex(mag, phase));

    points = 501;
    mag = linearSpacing(0.9, 1, points);
    phase = linearSpacing(PI/2.0, 10.0*PI, points);
    QTest::newRow("Medium phase") << QString("Medium phase") << RsaToolbox::arg(makeComplex(mag, phase));

    points = 12*2+2;
    mag = linearSpacing(.9, 1, points);
    phase = linearSpacing(3.0*PI, 15.0*PI, points);
    QTest::newRow("Large phase") << QString("Large phase") << RsaToolbox::arg(makeComplex(mag, phase));
}
void test_smoothSqrt::unwrap() {
    log.reset(new Log(logPath, logFilename.arg(cycle++).arg("unwrap()"), appName, appVersion));
    
    QFETCH(QString, testCase);
    QFETCH(QRowVector, data);

    QRowVector result = RsaToolbox::unwrap(data);
    log->printLine(testCase + ":");
    log->printLine(toString(data, ", "));
    log->printLine("Result:");
    log->printLine(toString(result, ", "));

    QString filename = logPath + "/" + plotFilename;
    Figure figure("unwrap", 2, 1);
    figure.select(0, 0);
    figure.addTrace(data, Qt::red);
    figure.select(1, 0);
    figure.addTrace(result, Qt::red);
    figure.savePng(filename.arg(cycle-1).arg(testCase));
    QVERIFY(true);
    log.reset();
}

void test_smoothSqrt::wrap_data() {
    QTest::addColumn<QString>("testCase");
    QTest::addColumn<QRowVector>("data");

    QTest::newRow("Zero phase") << QString("Zero Phase") << linearSpacing(0, 0, 201);
    QTest::newRow("Small phase") << QString("Small phase") << linearSpacing(0, PI, 401);
    QTest::newRow("Medium phase") << QString("Medium phase") << linearSpacing(PI/2.0, 10.0*PI, 501);
    QTest::newRow("Large phase") << QString("Large phase") << linearSpacing(3*PI, 15*PI, 12*2+2);
}
void test_smoothSqrt::wrap() {
    log.reset(new Log(logPath, logFilename.arg(cycle++).arg("wrap()"), appName, appVersion));

    QFETCH(QString, testCase);
    QFETCH(QRowVector, data);

    QRowVector result = RsaToolbox::wrap(data);
    log->printLine(testCase + ":");
    log->printLine(toString(data, ", "));
    log->printLine("Result:");
    log->printLine(toString(result, ", "));

    QString filename = logPath + "/" + plotFilename;
    Figure figure("wrap", 2, 1);
    figure.select(0, 0);
    figure.addTrace(data);
    figure.select(1, 0);
    figure.addTrace(result);
    figure.savePng(filename.arg(cycle-1).arg(testCase));
    QVERIFY(true);
    log.reset();
}

void test_smoothSqrt::smoothSqrt_data() {
    QTest::addColumn<QString>("testCase");
    QTest::addColumn<ComplexRowVector>("data");

    uint points = 201;
    QRowVector mag, phase;
    mag = linearSpacing(.99, 1, points);
    phase = linearSpacing(0, 0, points);
    QTest::newRow("Zero phase") << QString("Zero phase") << makeComplex(mag, phase);

    points = 401;
    mag = linearSpacing(.9, 1, points);
    phase = linearSpacing(0, PI, points);
    QTest::newRow("Small phase") << QString("Small phase") << makeComplex(mag, phase);

    points = 501;
    mag = linearSpacing(0.9, 1, points);
    phase = linearSpacing(PI/2.0, 10.0*PI, points);
    QTest::newRow("Medium phase") << QString("Medium phase") << makeComplex(mag, phase);

    points = 12*2+2;
    mag = linearSpacing(.9, 1, points);
    phase = linearSpacing(3.0*PI, 15.0*PI, points);
    QTest::newRow("Large phase") << QString("Large phase") << makeComplex(mag, phase);
}
void test_smoothSqrt::smoothSqrt() {
    log.reset(new Log(logPath, logFilename.arg(cycle++).arg("smoothSqrt()"), appName, appVersion));

    QFETCH(QString, testCase);
    QFETCH(ComplexRowVector, data);

    ComplexRowVector result = RsaToolbox::smoothSqrt(data);
    log->printLine(testCase + ":");
    log->printLine(toString(arg(data), ", "));
    log->printLine("Result:");
    log->printLine(toString(arg(result), ", "));

    QString filename = logPath + "/" + plotFilename;
    Figure figure("wrap", 2, 1);
    figure.select(0, 0);
    figure.addTrace(RsaToolbox::unwrap(arg(data)));
    figure.select(1, 0);
    figure.addTrace(RsaToolbox::unwrap(arg(result)));
    figure.savePng(filename.arg(cycle-1).arg(testCase));

    log.reset();
    QVERIFY(true);
}

void test_smoothSqrt::phaseAtDc_data() {
    QTest::addColumn<QString>("testCase");
    QTest::addColumn<QRowVector>("x");
    QTest::addColumn<ComplexRowVector>("y");

    uint points = 201;
    QRowVector mag, phase;
    mag = linearSpacing(.99, 1, points);
    phase = linearSpacing(0, 0, points);
    QRowVector x = linearSpacing(1, 2, points);
    QTest::newRow("Zero phase") << QString("Zero phase") << x << makeComplex(mag, phase);

    points = 401;
    mag = linearSpacing(.9, 1, points);
    phase = linearSpacing(0, PI, points);
    x = linearSpacing(1, 2, points);
    QTest::newRow("Small phase") << QString("Small phase") << x <<  makeComplex(mag, phase);

    points = 501;
    mag = linearSpacing(0.9, 1, points);
    phase = linearSpacing(PI/2.0, 10.0*PI, points);
    x = linearSpacing(1, 2, points);
    QTest::newRow("Medium phase") << QString("Medium phase") << x <<  makeComplex(mag, phase);

    points = 12*2+2;
    mag = linearSpacing(.9, 1, points);
    phase = linearSpacing(3.0*PI, 15.0*PI, points);
    x = linearSpacing(1, 2, points);
    QTest::newRow("Large phase") << QString("Large phase") << x <<  makeComplex(mag, phase);
}
void test_smoothSqrt::phaseAtDc() {
    log.reset(new Log(logPath, logFilename.arg(cycle++).arg("phaseAtDc()"), appName, appVersion));

    QFETCH(QString, testCase);
    QFETCH(QRowVector, x);
    QFETCH(ComplexRowVector, y);

    double result = RsaToolbox::phaseAtDc_rad(x, y);
    log->printLine(testCase + " x:");
    log->printLine(toString(x, ", "));
    log->printLine(testCase + " y:");
    log->printLine(toString(y, " "));
    log->printLine("Result:");
    log->printLine(formatValue(result, 2, RADIANS_UNITS));

    QString filename = logPath + "/" + plotFilename;
    Figure figure("wrap");
    figure.select(0, 0);
    figure.addTrace(x, RsaToolbox::unwrap(arg(y)));
    figure.addTrace(QRowVector(1, 0), QRowVector(1, result));
    figure.plot(0,0)->graph(1)->setScatterStyle(QCP::ssCircle);
    figure.savePng(filename.arg(cycle-1).arg(testCase));

    log.reset();
    QVERIFY(true);
}

void test_smoothSqrt::fixPhaseAtDc_data() {
    QTest::addColumn<QString>("testCase");
    QTest::addColumn<QRowVector>("x");
    QTest::addColumn<ComplexRowVector>("y");

    uint points = 201;
    QRowVector mag, phase;
    mag = linearSpacing(.99, 1, points);
    phase = linearSpacing(0, 0, points);
    QRowVector x = linearSpacing(1, 2, points);
    QTest::newRow("Zero phase") << QString("Zero phase") << x << makeComplex(mag, phase);

    points = 401;
    mag = linearSpacing(.9, 1, points);
    phase = linearSpacing(0, PI, points);
    x = linearSpacing(1, 2, points);
    QTest::newRow("Small phase") << QString("Small phase") << x <<  makeComplex(mag, phase);

    points = 501;
    mag = linearSpacing(0.9, 1, points);
    phase = linearSpacing(PI/2.0, 10.0*PI, points);
    x = linearSpacing(1, 2, points);
    QTest::newRow("Medium phase") << QString("Medium phase") << x <<  makeComplex(mag, phase);

    points = 12*2+2;
    mag = linearSpacing(.9, 1, points);
    phase = linearSpacing(3.0*PI, 15.0*PI, points);
    x = linearSpacing(1, 2, points);
    QTest::newRow("Large phase") << QString("Large phase") << x <<  makeComplex(mag, phase);
}
void test_smoothSqrt::fixPhaseAtDc() {
    log.reset(new Log(logPath, logFilename.arg(cycle++).arg("fixPhaseAtDc()"), appName, appVersion));

    QFETCH(QString, testCase);
    QFETCH(QRowVector, x);
    QFETCH(ComplexRowVector, y);

    ComplexRowVector result = RsaToolbox::fixPhaseAtDc(x, y);
    log->printLine(testCase + " x:");
    log->printLine(toString(x, ", "));
    log->printLine(testCase + " y:");
    log->printLine(toString(y, " "));
    log->printLine("Result:");
    log->printLine(toString(result, " "));

    QString filename = logPath + "/" + plotFilename;
    Figure figure("wrap");
    figure.select(0, 0);
    figure.addTrace(x, RsaToolbox::unwrap(arg(y)));
    figure.addTrace(QRowVector(1, 0), QRowVector(1, RsaToolbox::phaseAtDc_rad(x, y)));
    figure.plot(0,0)->graph(1)->setScatterStyle(QCP::ssCircle);
    figure.addTrace(x, RsaToolbox::unwrap(arg(result)), Qt::red);
    figure.addTrace(QRowVector(1, 0), QRowVector(1, RsaToolbox::phaseAtDc_rad(x, result)), Qt::red);
    figure.plot(0,0)->graph(3)->setScatterStyle(QCP::ssCircle);
    figure.savePng(filename.arg(cycle-1).arg(testCase));

    log.reset();
    QVERIFY(true);
}

ComplexRowVector makeComplex(QRowVector mag, QRowVector phase_rad) {
    uint size = mag.size();
    ComplexRowVector result(size);
    ComplexDouble j(0, 1);
    for (uint i = 0; i < size; i++) {
        ComplexDouble c;
        c = mag[i]*exp(j*phase_rad[i]);
        result[i] = c;
    }
    return(result);
}

QTEST_MAIN(test_smoothSqrt)
#include "test_smoothSqrt.moc"


