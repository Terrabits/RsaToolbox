#include "TcpBus.h"
using namespace RsaToolbox;

#include <QtTest>
#include <QSignalSpy>

class test_TcpBus : public QObject
{
    Q_OBJECT

public:
    test_TcpBus();

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

test_TcpBus::test_TcpBus() {}

void test_TcpBus::isOpen() {
    QCOMPARE(TcpBus(TCPIP_CONNECTION, "127.0.0.1").isOpen(), true);
    QCOMPARE(TcpBus().isOpen(), false);
}
void test_TcpBus::isClosed() {
    QCOMPARE(TcpBus(TCPIP_CONNECTION, "127.0.0.1").isClosed(), false);
    QCOMPARE(TcpBus().isClosed(), true);
}
void test_TcpBus::setTimeout() {
    TcpBus bus = TcpBus();
    bus.setTimeout(1234);
    QCOMPARE(bus.timeout_ms(), (uint)1234);
}
void test_TcpBus::connectionType() {
    QCOMPARE(TcpBus(TCPIP_CONNECTION, "127.0.0.1").connectionType(), TCPIP_CONNECTION);
}
void test_TcpBus::address() {
    QCOMPARE(TcpBus(TCPIP_CONNECTION, "127.0.0.1").address(), QString("127.0.0.1"));
}

void test_TcpBus::readNotConnected() {
    TcpBus bus(TCPIP_CONNECTION, "1.2.3.4", 100, 100);
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QCOMPARE(bus.query("*IDN?"), QString());
    QCOMPARE(spy.count(), 1);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_TcpBus::readConnected() {
    TcpBus bus(TCPIP_CONNECTION, "127.0.0.1");
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.write("*IDN?"));
    QVERIFY(!bus.read().isEmpty());
    QCOMPARE(spy.count(), 2);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
    QVERIFY(bus.query("*IDN?").contains("Rohde", Qt::CaseInsensitive));
}

void test_TcpBus::writeNotConnected() {
    TcpBus bus(TCPIP_CONNECTION, "1.2.3.4", 100, 100);
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty());
    QVERIFY(spy.count() == 1);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_TcpBus::writeConnected() {
    TcpBus bus(TCPIP_CONNECTION, "127.0.0.1");
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty() == false);
    QVERIFY(spy.count() == 2);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_TcpBus::queryNotConnected() {
    TcpBus bus(TCPIP_CONNECTION, "1.2.3.4", 100, 100);
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty());
    QCOMPARE(spy.count(), 1);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_TcpBus::queryConnected() {
    TcpBus bus(TCPIP_CONNECTION, "127.0.0.1");
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty() == false);
    QCOMPARE(spy.count(), 2);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
    QVERIFY(bus.query("*IDN?").contains("Rohde", Qt::CaseInsensitive));
}

QTEST_APPLESS_MAIN(test_TcpBus)
#include "test_TcpBus.moc"
