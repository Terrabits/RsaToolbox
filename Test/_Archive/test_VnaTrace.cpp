

#include "General.h"
#include "Vna.h"
#include "TcpBus.h"
#include "VisaBus.h"
#include "Touchstone.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_VnaTrace : public QObject
{
    Q_OBJECT

public:
    test_VnaTrace();

private:
    Vna vna;
    QScopedPointer<Log> log;
    VnaTrace trace1;
    VnaTrace trace2;

    int cycle;
    QString appName;
    QString appVersion;
    QString filename;
    QString logPath;

private Q_SLOTS:
    void init();
    void cleanup();

    void createTrace();
    void diagram();
    void scale();
    void channel();

    void networkParameter();
    void waveQuantity();
    void waveRatio();
    void impedance();
    void admittance();

    void format();
    void displayProperties();
    void setYAxis();

    void measure();
    void dataToMemory();
    void write();
    void limits();

};

test_VnaTrace::test_VnaTrace() {
    cycle = 0;
    appName = "test_VnaTrace";
    appVersion = "0";
    filename = "%1 %2 Log.txt";
    logPath = "../RsaToolboxTest/Results/VnaTrace Logs";
    
    // Initialize object here
}

void test_VnaTrace::init() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("init()"), appName, appVersion));
    log->printApplicationHeader();
    vna.resetBus(TCPIP_CONNECTION, "127.0.0.1");
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(vna.isConnected());
    vna.preset();
    vna.wait();
    vna.clearStatus();

    QVERIFY(vna.properties().isKnownModel());

    trace1 = vna.trace();
    QCOMPARE(trace1.name(), QString("Trc1"));
    QVERIFY(vna.traces().contains(trace1.name()));
    QVERIFY(vna.isTrace(trace1.name()));

    vna.createChannel(2);
    QVERIFY(vna.isChannel(2));

    vna.createTrace("myTrace", 2);
    trace2 = vna.trace("myTrace");
    QVERIFY(vna.isTrace(trace2.name()));

    vna.disconnectLog();
}
void test_VnaTrace::cleanup() {
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

void test_VnaTrace::createTrace() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("createTrace()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(vna.isTrace(trace1.name()));
    QVERIFY(vna.isTrace(trace2.name()));

    QVERIFY(vna.isError() == false);
}
void test_VnaTrace::diagram() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("diagram()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(trace1.isVisible());
    QVERIFY(vna.isDiagram(1));
    QCOMPARE(trace1.diagram(), uint(1));

    QVERIFY(trace2.isHidden());
    QVERIFY(vna.isNotDiagram(2));
    vna.createDiagram(2);
    QVERIFY(vna.isDiagram(2));
    trace2.setDiagram(2);
    QCOMPARE(trace2.diagram(), uint(2));

    QVERIFY(trace2.isVisible());
    trace2.hide();
    QVERIFY(trace2.isHidden());
    trace2.show();
    QVERIFY(trace2.isVisible());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaTrace::channel() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("channel()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QCOMPARE(trace1.channel(), uint(1));
    QCOMPARE(trace2.channel(), uint(2));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaTrace::scale() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("scale()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    trace1.autoscale();

    trace2.setDiagram(1);
    trace2.autoscale();

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaTrace::networkParameter() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("networkParameter()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(trace1.isNetworkParameter());
    trace1.setNetworkParameter(Y_PARAMETER, 2, 2);
    NetworkParameter parameter;
    uint outputPort, inputPort;
    trace2.networkParameter(parameter, outputPort, inputPort);
    QCOMPARE(parameter, Y_PARAMETER);
    QCOMPARE(outputPort, uint(2));
    QCOMPARE(inputPort, uint(2));

    vna.channel(1).createBalancedPort(1, 1, 2);
    vna.channel(1).createSingleEndedPort(2, 3);
    vna.channel(1).createSingleEndedPort(3, 4);

    BalancedPort output(1), input(2);
    input.setSingleEnded();
    output.setDifferential();
    trace1.setNetworkParameter(Z_PARAMETER, output, input);

    BalancedPort outputRead, inputRead;
    trace1.networkParameter(parameter, outputRead, inputRead);
    QCOMPARE(parameter, Z_PARAMETER);
    QCOMPARE(outputRead.logicalPort(), uint(1));
    QVERIFY(outputRead.isDifferential());
    QCOMPARE(inputRead.logicalPort(), uint(2));
    QVERIFY(inputRead.isSingleEnded());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaTrace::waveQuantity() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("waveQuantity()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(trace1.isWaveQuantity() == false);
    trace1.setWaveQuantity(A_WAVE, 1);

    QVERIFY(trace1.isWaveQuantity());
    QVERIFY(trace1.isWaveRatio() == false);
    WaveQuantity wave;
    uint port;
    trace1.waveQuantity(wave, port);
    QCOMPARE(wave, A_WAVE);
    QCOMPARE(port, uint(1));

    trace1.setWaveQuantity(B_WAVE, 2);

    QVERIFY(trace1.isWaveQuantity());
    QVERIFY(trace1.isWaveRatio() == false);
    trace1.waveQuantity(wave, port);
    QCOMPARE(wave, B_WAVE);
    QCOMPARE(port, uint(2));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaTrace::waveRatio() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("waveRatio()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(trace1.isWaveQuantity() == false);
    trace1.setWaveRatio(B_WAVE, 1, A_WAVE, 1);

    QVERIFY(trace1.isWaveQuantity() == false);
    QVERIFY(trace1.isWaveRatio());
    WaveQuantity nWave, dWave;
    uint nPort, dPort;
    trace1.waveRatio(nWave, nPort, dWave, dPort);
    QCOMPARE(nWave, B_WAVE);
    QCOMPARE(nPort, uint(1));
    QCOMPARE(dWave, A_WAVE);
    QCOMPARE(dPort, uint(1));

    trace1.setWaveRatio(B_WAVE, 3, B_WAVE, 2);
    QVERIFY(trace1.isWaveQuantity() == false);
    QVERIFY(trace1.isWaveRatio());
    trace1.waveRatio(nWave, nPort, dWave, dPort);
    QCOMPARE(nWave, B_WAVE);
    QCOMPARE(nPort, uint(3));
    QCOMPARE(dWave, B_WAVE);
    QCOMPARE(dPort, uint(2));

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaTrace::impedance() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("impedance()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(trace1.isImpedance() == false);
    trace1.setImpedance(2, 2);
    uint outputPort, inputPort;
    trace2.impedance(outputPort, inputPort);
    QVERIFY(trace1.isImpedance());
    QCOMPARE(outputPort, uint(2));
    QCOMPARE(inputPort, uint(2));

    vna.channel(1).createBalancedPort(1, 1, 2);
    vna.channel(1).createSingleEndedPort(2, 3);
    vna.channel(1).createSingleEndedPort(3, 4);

    BalancedPort output(1), input(2);
    input.setSingleEnded();
    output.setDifferential();
    trace1.setImpedance(output, input);

    BalancedPort outputRead, inputRead;
    trace1.impedance(outputRead, inputRead);
    QVERIFY(trace1.isImpedance());
    QCOMPARE(outputRead.logicalPort(), uint(1));
    QVERIFY(outputRead.isDifferential());
    QCOMPARE(inputRead.logicalPort(), uint(2));
    QVERIFY(inputRead.isSingleEnded());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaTrace::admittance() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("admittance()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(trace1.isAdmittance() == false);
    trace1.setAdmittance(2, 2);
    uint outputPort, inputPort;
    trace2.admittance(outputPort, inputPort);
    QVERIFY(trace1.isAdmittance());
    QCOMPARE(outputPort, uint(2));
    QCOMPARE(inputPort, uint(2));

    vna.channel(1).createBalancedPort(1, 1, 2);
    vna.channel(1).createSingleEndedPort(2, 3);
    vna.channel(1).createSingleEndedPort(3, 4);

    BalancedPort output(1), input(2);
    input.setSingleEnded();
    output.setDifferential();
    trace1.setAdmittance(output, input);

    BalancedPort outputRead, inputRead;
    trace1.admittance(outputRead, inputRead);
    QVERIFY(trace1.isAdmittance());
    QCOMPARE(outputRead.logicalPort(), uint(1));
    QVERIFY(outputRead.isDifferential());
    QCOMPARE(inputRead.logicalPort(), uint(2));
    QVERIFY(inputRead.isSingleEnded());

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaTrace::format() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("format()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QCOMPARE(trace1.format(), DB_MAGNITUDE_TRACE);
    trace1.setFormat(PHASE_DEG_TRACE);
    QCOMPARE(trace1.format(), PHASE_DEG_TRACE);
    trace1.setFormat(SMITH_CHART_TRACE);
    QCOMPARE(trace1.format(), SMITH_CHART_TRACE);
    trace1.setFormat(POLAR_CHART_TRACE);
    QCOMPARE(trace1.format(), POLAR_CHART_TRACE);
    trace1.setFormat(VSWR_TRACE);
    QCOMPARE(trace1.format(), VSWR_TRACE);
    trace1.setFormat(UNWRAP_PHASE_DEG_TRACE);
    QCOMPARE(trace1.format(), UNWRAP_PHASE_DEG_TRACE);
    trace1.setFormat(LINEAR_MAGNITUDE_TRACE);
    QCOMPARE(trace1.format(), LINEAR_MAGNITUDE_TRACE);
    trace1.setFormat(LINEAR_MAGNITUDE_TRACE);
    QCOMPARE(trace1.format(), LINEAR_MAGNITUDE_TRACE);
    trace1.setFormat(INVERSE_SMITH_CHART_TRACE);
    QCOMPARE(trace1.format(), INVERSE_SMITH_CHART_TRACE);
    trace1.setFormat(REAL_PART_TRACE);
    QCOMPARE(trace1.format(), REAL_PART_TRACE);
    trace1.setFormat(IMAGINARY_PART_TRACE);
    QCOMPARE(trace1.format(), IMAGINARY_PART_TRACE);
    trace1.setFormat(DELAY_TRACE);
    QCOMPARE(trace1.format(), DELAY_TRACE);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaTrace::displayProperties() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("displayProperties()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaTrace::setYAxis() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("setYAxis()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(false);

    QVERIFY(vna.isError() == false);
    vna.disconnectLog();
}
void test_VnaTrace::dataToMemory() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("dataToMemory()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QVERIFY(!vna.isTrace("TEST"));
    trace1.toMemory("TEST");
    QVERIFY(vna.isTrace("TEST"));

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaTrace::measure() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("measure()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QCOMPARE(trace1.points(), uint(trace1.x().size()));

    QRowVector data;
    trace1.y(data);
    QCOMPARE(trace1.points(), uint(data.size()));

    ComplexRowVector complexData;
    trace1.y(complexData);
    QCOMPARE(trace1.points(), uint(complexData.size()));

    NetworkTraceData networkData;
    trace1.measure(networkData);
    QCOMPARE(networkData.points(), trace1.points());

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}
void test_VnaTrace::write() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("write()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QDir path(SOURCE_DIR);
    path = path.filePath("Touchstone Files");
    NetworkData data;
    QVERIFY(Touchstone::Read(data, path.filePath("Maximum.s2p")));

    QVERIFY(vna.isTrace(trace1.name()));
    uint i = trace1.channel();
    vna.channel(i).manualSweepOn();
    vna.channel(i).setFrequencies(data.x());
    vna.channel(i).startSweep();
    vna.pause();
    QVERIFY(!vna.isError());
    QCOMPARE(vna.channel(i).segmentedSweep().points(), data.points());
    QCOMPARE(vna.channel(i).segmentedSweep().start_Hz(), data.x().first());
    QCOMPARE(vna.channel(i).segmentedSweep().stop_Hz(), data.x().last());

    trace1.toMemory("TEST");
    QVERIFY(!vna.isError());
    QVERIFY(vna.isTrace("TEST"));

    VnaTrace test = vna.trace("TEST");
    if (vna.diagrams().isEmpty())
        vna.createDiagram();
    test.setDiagram(vna.diagrams().first());
    QVERIFY(!vna.isError());
    QVERIFY(test.diagram() != 0);

    test.write(data.y(1,1));
    QVERIFY(!vna.isError());

    QRowVector traceData;
    test.y(traceData);
    QVERIFY(!vna.isError());
    QVERIFY(!traceData.isEmpty());
    QCOMPARE(traceData.first(), data.y_dB(1,1).first());
    QCOMPARE(traceData.last(), data.y_dB(1,1).last());

    vna.disconnectLog();
}
void test_VnaTrace::limits() {
    log.reset(new Log(logPath, filename.arg(cycle++).arg("limits()"), appName, appVersion));
    log->printApplicationHeader();
    vna.useLog(log.data());
    vna.printInfo();

    QDir path(SOURCE_DIR);
    path = path.filePath("Touchstone Files");
    NetworkData data;
    QVERIFY(Touchstone::Read(data, path.filePath("Maximum.s2p")));

    QVERIFY(vna.isTrace(trace1.name()));
    uint i = trace1.channel();
    vna.channel(i).manualSweepOn();
    vna.channel(i).setFrequencies(data.x());
    vna.channel(i).startSweep();
    vna.pause();
    trace1.toMemory("TEST");
    VnaTrace test = vna.trace("TEST");
    if (vna.diagrams().isEmpty())
        vna.createDiagram();
    test.setDiagram(vna.diagrams().first());
    test.write(data.y(1,1));

    trace1.limits().setUpper(test.name());
    trace1.limits().show();
    trace1.limits().on();
    QVERIFY(trace1.limits().isFail());

    vna.preset();
    vna.wait();

    if (!vna.isChannel(trace1.channel()))
        vna.createChannel(trace1.channel());
    if (!vna.isTrace(trace1.name()))
        vna.createTrace(trace1.name(), trace1.channel());
    trace1.setFormat(PHASE_DEG_TRACE);
    trace1.limits().addUpper(data.x(), multiply(data.y(2,1), ComplexDouble(1.0, 0.2)));
    trace1.limits().addLower(data.x(), multiply(data.y(2,1), ComplexDouble(1.0, -0.2)));
    QVERIFY(trace1.limits().isVisible());
    QVERIFY(trace1.limits().isOn());
    QVERIFY(trace1.limits().isFail());

    QVERIFY(!vna.isError());
    vna.disconnectLog();
}

QTEST_APPLESS_MAIN(test_VnaTrace)
#include "test_VnaTrace.moc"


