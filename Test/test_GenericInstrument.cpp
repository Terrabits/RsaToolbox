

#include "VisaBus.h"
#include "RsibBus.h"
#include "GenericInstrument.h"
using namespace RsaToolbox;

#include <QtTest>
#include <QSignalSpy>

class test_GenericInstrument : public QObject
{
    Q_OBJECT

public:
    test_GenericInstrument();

private Q_SLOTS:
    void isRohdeSchwarz();
    void idString();
    void optionsList();
    void log();
    void resetBus();
    void lock();
    void scpiCommands();
    void signalEmission();
};

test_GenericInstrument::test_GenericInstrument() {}

void test_GenericInstrument::isRohdeSchwarz() {
    GenericInstrument instrument(TCPIP_CONNECTION, "127.0.0.1");
    QVERIFY(instrument.isRohdeSchwarz());
}
void test_GenericInstrument::idString() {
    GenericInstrument instrument(TCPIP_CONNECTION, "127.0.0.1");
    QVERIFY(instrument.idString().contains("ZNB", Qt::CaseInsensitive));
}
void test_GenericInstrument::optionsList() {
    GenericInstrument instrument(TCPIP_CONNECTION, "127.0.0.1");
    QVERIFY(instrument.optionsString().isEmpty() == false);
}
void test_GenericInstrument::log() {
    GenericInstrument instrument(TCPIP_CONNECTION, "127.0.0.1");
    Log log("../RsaToolboxTest/Results/", "GenericInstrument(log).txt", "GenericInstrument Test", "1.0");
    log.printApplicationHeader();
    instrument.useLog(&log);
    QVERIFY(instrument.isLogConnected());
    instrument.idString();
    instrument.disconnectLog();
    QVERIFY(instrument.isLogDisconnected());
    instrument.useLog(&log);
    QVERIFY(instrument.isLogConnected());
    instrument.optionsString();
    instrument.disconnectLog();
    QVERIFY(instrument.isLogDisconnected());
    instrument.idString();
}
void test_GenericInstrument::resetBus() {
    GenericInstrument instrument(TCPIP_CONNECTION, "127.0.0.1");
    QVERIFY(instrument.isRohdeSchwarz());
    instrument.resetBus();
    QVERIFY(instrument.isDisconnected());
    instrument.resetBus(new VisaBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    QVERIFY(instrument.isConnected());
}
void test_GenericInstrument::lock() {
    GenericInstrument instrument1(new VisaBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    GenericInstrument instrument2(new VisaBus(TCPIP_CONNECTION, "127.0.0.1", 1000));

    QVERIFY(instrument1.lock());
    QVERIFY(instrument2.lock() == false);
    QVERIFY(instrument2.query("*IDN?\n").isEmpty());
    QVERIFY(instrument1.query("*IDN?\n").isEmpty() == false);
    QVERIFY(instrument1.unlock());
    QVERIFY(instrument2.query("*IDN?\n").isEmpty() == false);
}
void test_GenericInstrument::scpiCommands() {
    GenericInstrument instrument(TCPIP_CONNECTION, "127.0.0.1");
    Log log("../RsaToolboxTest/Results/", "GenericInstrument(scpiCommands).txt", "GenericInstrument Test", "1.0");
    log.printApplicationHeader();
    instrument.useLog(&log);
    instrument.preset();
    QVERIFY(instrument.isConnected());
    instrument.preset();
    instrument.wait();
    instrument.pause();
    instrument.initializePolling();
    QVERIFY(instrument.isOperationComplete());
    instrument.clearStatus();
}
void test_GenericInstrument::signalEmission() {
    GenericInstrument instrument = GenericInstrument();
    QSignalSpy connected(&instrument, SIGNAL(connected()));
    QSignalSpy disconnected(&instrument, SIGNAL(disconnected()));
    QSignalSpy busError(&instrument, SIGNAL(busError()));

    instrument.resetBus(new RsibBus(TCPIP_CONNECTION, "127.0.0.1", 1000));
    instrument.preset();
    instrument.resetBus();
    instrument.preset();

    QCOMPARE(connected.count(), 1);
    QCOMPARE(disconnected.count(), 1);
    QCOMPARE(busError.count(), 1);
}


QTEST_APPLESS_MAIN(test_GenericInstrument)
#include "test_GenericInstrument.moc"


