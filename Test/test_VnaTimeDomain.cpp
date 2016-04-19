

#include "General.h"
#include "Vna.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_VnaTimeDomain : public QObject
{
    Q_OBJECT

public:
    test_VnaTimeDomain();

private:
    Vna vna;
    VnaTrace trace1;
    VnaTrace trace2;
    QScopedPointer<Log> log;

    int cycle;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void isOn();
    void responseType();
    void dcExtrapolation();
    void resolutionFactor();
    void window();
    void limits();
    void setRiseAndRange();
};

test_VnaTimeDomain::test_VnaTimeDomain() {
    cycle = 0;
    appName = "test_VnaTimeDomain";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaTimeDomain Logs";
    
    trace1 = vna.trace();
    vna.createChannel(2);
    vna.createTrace("Trc2", 2);
    vna.createDiagram(2);
    trace2 = vna.trace("Trc2");
    trace2.setDiagram(2);
}

void test_VnaTimeDomain::init() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion));
    log->printApplicationHeader();
    vna.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    vna.useLog(log.data());
    vna.printInfo();
    vna.preset();
    vna.clearStatus();
    vna.disconnectLog();
}
void test_VnaTimeDomain::cleanup() {
    vna.isError();
    vna.disconnectLog();
    log.reset(new Log(logPath, filename.arg(cycle++).arg("cleanup()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();
    
    // Specific cleanup
    
    vna.isError();
    vna.clearStatus();
    vna.resetBus();
    vna.disconnectLog();
}

void test_VnaTimeDomain::isOn() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("isOn()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(trace1.timeDomain().isOff());
    trace1.timeDomain().on();
    QVERIFY(trace1.timeDomain().isOn());
    trace1.timeDomain().off();
    QVERIFY(trace1.timeDomain().isOff());

    QVERIFY(vna.isError() == false);
}
void test_VnaTimeDomain::responseType() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("responseType()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    VnaTimeDomain time1 = trace1.timeDomain();
    time1.on();

    time1.setBandpassImpulseResponse();
    QVERIFY(time1.isBandpassImpulseResponse());
    QVERIFY(time1.isLowpassImpulseResponse() == false);
    QVERIFY(time1.isLowpassStepResponse() == false);

    time1.setLowpassImpulseResponse();
    QVERIFY(time1.isBandpassImpulseResponse() == false);
    QVERIFY(time1.isLowpassImpulseResponse());
    QVERIFY(time1.isLowpassStepResponse() == false);

    time1.setLowpassStepResponse();
    QVERIFY(time1.isBandpassImpulseResponse() == false);
    QVERIFY(time1.isLowpassImpulseResponse() == false);
    QVERIFY(time1.isLowpassStepResponse());

    QVERIFY(vna.isError() == false);
}
void test_VnaTimeDomain::dcExtrapolation() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("dcExtrapolation()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    VnaTimeDomain time1 = trace1.timeDomain();
    time1.on();

    QVERIFY(time1.isManualDcExtrapolation());

    time1.adjustChannelPoints();
    QVERIFY(vna.isError() == false);

    QVERIFY(time1.isManualDcExtrapolation());
    QVERIFY(time1.isAutomaticDcExtrapolation() == false);
    QCOMPARE(time1.extrapolatedDcValue(), double(0.0));
    time1.setExtrapolatedDcValue(0.5);
    QCOMPARE(time1.extrapolatedDcValue(), double(0.5));
    time1.automaticDcExtrapolationOn();
    QVERIFY(time1.isAutomaticDcExtrapolation());
    QVERIFY(time1.isManualDcExtrapolation() == false);

    QVERIFY(vna.isError() == false);
}
void test_VnaTimeDomain::resolutionFactor() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("resolutionFactor()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    VnaTimeDomain time1 = trace1.timeDomain();
    time1.on();

    QVERIFY(time1.isResolutionEnhancementOn() == false);
    QVERIFY(time1.isResolutionEnhancementOff());
    QCOMPARE(time1.resolutionEnhancementFactor(), double(1.0));

    time1.setResolutionEnhancement(5.2);
    QVERIFY(time1.isResolutionEnhancementOn());
    QVERIFY(time1.isResolutionEnhancementOff() == false);
    QCOMPARE(time1.resolutionEnhancementFactor(), double(5.2));

    time1.resolutionEnhancementOff();
    QVERIFY(time1.isResolutionEnhancementOn() == false);
    QVERIFY(time1.isResolutionEnhancementOff());
    QCOMPARE(time1.resolutionEnhancementFactor(), double(1.0));

    QVERIFY(vna.isError() == false);
}
void test_VnaTimeDomain::window() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("window()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    VnaTimeDomain time1 = trace1.timeDomain();
    time1.on();

    time1.setWindow(REGULAR_WINDOW_FUNCTION);
    QVERIFY(time1.isWindow(REGULAR_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(HAMMING_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(HANN_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(BOHMAN_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(DOLPH_CHEBYCHEV_WINDOW_FUNCTION) == false);
    QCOMPARE(time1.window(), REGULAR_WINDOW_FUNCTION);

    time1.setWindow(HAMMING_WINDOW_FUNCTION);
    QVERIFY(time1.isWindow(REGULAR_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(HAMMING_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(HANN_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(BOHMAN_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(DOLPH_CHEBYCHEV_WINDOW_FUNCTION) == false);
    QCOMPARE(time1.window(), HAMMING_WINDOW_FUNCTION);

    time1.setWindow(HANN_WINDOW_FUNCTION);
    QVERIFY(time1.isWindow(REGULAR_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(HAMMING_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(HANN_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(BOHMAN_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(DOLPH_CHEBYCHEV_WINDOW_FUNCTION) == false);
    QCOMPARE(time1.window(), HANN_WINDOW_FUNCTION);

    time1.setWindow(BOHMAN_WINDOW_FUNCTION);
    QVERIFY(time1.isWindow(REGULAR_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(HAMMING_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(HANN_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(BOHMAN_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(DOLPH_CHEBYCHEV_WINDOW_FUNCTION) == false);
    QCOMPARE(time1.window(), BOHMAN_WINDOW_FUNCTION);

    time1.setWindow(DOLPH_CHEBYCHEV_WINDOW_FUNCTION);
    QVERIFY(time1.isWindow(REGULAR_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(HAMMING_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(HANN_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(BOHMAN_WINDOW_FUNCTION) == false);
    QVERIFY(time1.isWindow(DOLPH_CHEBYCHEV_WINDOW_FUNCTION) == false);
    QCOMPARE(time1.window(), DOLPH_CHEBYCHEV_WINDOW_FUNCTION);

    QVERIFY(vna.isError() == false);
}
void test_VnaTimeDomain::limits() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("limits()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    double value;
    QString string;
    QTextStream stream(&string);
    stream << "Time Domain Conversion Limits:\n";

    stream << "Fastest Rise Time: ";
    value = trace1.timeDomain().fastestRiseTime_s();
    stream << formatValue(value, 2, SECONDS_UNITS);
    stream << "\n";

    stream << "Slowest Rise Time: ";
    value = trace1.timeDomain().slowestRiseTime_s();
    stream << formatValue(value, 2, SECONDS_UNITS);
    stream << "\n";

    stream << "Longest Range: ";
    value = trace1.timeDomain().longestRange_s();
    stream << formatValue(value, 2, SECONDS_UNITS);
    stream << "\n";

    stream << "Shortest Range: ";
    value = trace1.timeDomain().shortestRange_s();
    stream << formatValue(value, 2, SECONDS_UNITS);
    stream << "\n\n";

    stream.flush();
    vna.print(string);

    QVERIFY(vna.isError() == false);
}
void test_VnaTimeDomain::setRiseAndRange() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("setRiseAndRange()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    VnaTimeDomain time1 = trace1.timeDomain();

    double percentError = 0.10;
    double riseTime_s = 1E-9;
    double range_s = 30E-9;

    time1.setupChannel(riseTime_s, RISETIME_10_TO_90, range_s);
    time1.setupTrace();
    trace1.setWaveQuantity(A_WAVE, 1);
    trace1.setYAxisMinimum(0);
    trace1.setYAxisMaximum(50E-3);

    QVERIFY(abs(riseTime_s - time1.riseTime_s(RISETIME_10_TO_90)) <= percentError * riseTime_s);
    QVERIFY(time1.unambiguousRange_s() >= range_s);

    QVERIFY(vna.isError() == false);
}


QTEST_APPLESS_MAIN(test_VnaTimeDomain)
#include "test_VnaTimeDomain.moc"


