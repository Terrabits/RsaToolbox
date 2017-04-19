#include "RsibBus.h"
using namespace RsaToolbox;

#include <QtTest>
#include <QSignalSpy>

class test_RsibBus : public QObject
{
    Q_OBJECT

public:
    test_RsibBus();

private Q_SLOTS:
    void isOpen();
    void isClosed();
    void setTimeout();
    void connectionType();
    void address();

    void readNotConnected();
    void readConnected();
    void writeNotConnected();
    void writeConnected();
    void queryNotConnected();
    void queryConnected();

//    void lock();
//    void unlock();
//    void local();
//    void remote();
};

test_RsibBus::test_RsibBus() {}

void test_RsibBus::isOpen() {
    QCOMPARE(RsibBus(TCPIP_CONNECTION, "127.0.0.1").isOpen(), true);
    QCOMPARE(RsibBus().isOpen(), false);
}
void test_RsibBus::isClosed() {
    QCOMPARE(RsibBus(TCPIP_CONNECTION, "127.0.0.1").isClosed(), false);
    QCOMPARE(RsibBus().isClosed(), true);
}
void test_RsibBus::setTimeout() {
    RsibBus bus = RsibBus();
    bus.setTimeout(1234);
    QCOMPARE(bus.timeout_ms(), (uint)1234);
}
void test_RsibBus::connectionType() {
    QCOMPARE(RsibBus(TCPIP_CONNECTION, "127.0.0.1").connectionType(), TCPIP_CONNECTION);
}
void test_RsibBus::address() {
    QCOMPARE(RsibBus(TCPIP_CONNECTION, "127.0.0.1").address(), QString("127.0.0.1"));
}

void test_RsibBus::readNotConnected() {
    RsibBus bus(TCPIP_CONNECTION, "1.2.3.4", 100, 100);
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty());
    QCOMPARE(spy.count(), 1);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_RsibBus::readConnected() {
    RsibBus bus(TCPIP_CONNECTION, "127.0.0.1");
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty() == false);
    QCOMPARE(spy.count(), 2);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
    QVERIFY(bus.query("*IDN?").contains("Rohde", Qt::CaseInsensitive));
}

void test_RsibBus::writeNotConnected() {
    RsibBus bus(TCPIP_CONNECTION, "1.2.3.4", 100, 100);
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty());
    QVERIFY(spy.count() == 1);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_RsibBus::writeConnected() {
    RsibBus bus(TCPIP_CONNECTION, "127.0.0.1");
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty() == false);
    QVERIFY(spy.count() == 2);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_RsibBus::queryNotConnected() {
    RsibBus bus(TCPIP_CONNECTION, "1.2.3.4", 100, 100);
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty());
    QCOMPARE(spy.count(), 1);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_RsibBus::queryConnected() {
    RsibBus bus(TCPIP_CONNECTION, "127.0.0.1");
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty() == false);
    QCOMPARE(spy.count(), 2);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
    QVERIFY(bus.query("*IDN?").contains("Rohde", Qt::CaseInsensitive));
}

QTEST_APPLESS_MAIN(test_RsibBus)
#include "test_RsibBus.moc"
