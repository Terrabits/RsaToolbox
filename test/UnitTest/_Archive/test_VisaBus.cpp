 #include "VisaBus.h"
 using namespace RsaToolbox;

// Qt
#include <QDebug>
#include <QtTest>
#include <QSignalSpy>

class test_VisaBus : public QObject
{
    Q_OBJECT

public:
    test_VisaBus();

private Q_SLOTS:
    void isVisaPresent();
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

    void lock();
    void unlock();
//    void local();
//    void remote();
};

test_VisaBus::test_VisaBus() { }

void test_VisaBus::isVisaPresent() {
    QCOMPARE(VisaBus::isVisaInstalled(), true);
}
void test_VisaBus::isOpen() {
    QCOMPARE(VisaBus(TCPIP_CONNECTION, "127.0.0.1", 1000).isOpen(), true);
    QCOMPARE(VisaBus().isOpen(), false);
}
void test_VisaBus::isClosed() {
    QCOMPARE(VisaBus(TCPIP_CONNECTION, "127.0.0.1", 1000).isClosed(), false);
    QCOMPARE(VisaBus().isClosed(), true);
}
void test_VisaBus::setTimeout() {
    VisaBus bus = VisaBus();
    bus.setTimeout(1234);
    QCOMPARE(bus.timeout_ms(), (uint)1234);
}
void test_VisaBus::connectionType() {
    QCOMPARE(VisaBus(TCPIP_CONNECTION, "127.0.0.1", 1000).connectionType(), TCPIP_CONNECTION);
}
void test_VisaBus::address() {
    QCOMPARE(VisaBus(TCPIP_CONNECTION, "127.0.0.1", 1000).address(), QString("127.0.0.1"));
}

void test_VisaBus::readNotConnected() {
    VisaBus bus(TCPIP_CONNECTION, "1.2.3.4", 100);
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty());
    QCOMPARE(spy.count(), 1);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_VisaBus::readConnected() {
    VisaBus bus(TCPIP_CONNECTION, "127.0.0.1");
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty() == false);
    QCOMPARE(spy.count(), 2);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
    QVERIFY(bus.query("*IDN?").contains("Rohde", Qt::CaseInsensitive));
}

void test_VisaBus::writeNotConnected() {
    VisaBus bus(TCPIP_CONNECTION, "1.2.3.4", 100);
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    bus.write("*RST");
    QVERIFY(spy.count() == 1);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_VisaBus::writeConnected() {
    VisaBus bus(TCPIP_CONNECTION, "127.0.0.1");
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    bus.write("*RST");
    QVERIFY(spy.count() == 1);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_VisaBus::queryNotConnected() {
    VisaBus bus(TCPIP_CONNECTION, "1.2.3.4", 100);
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty());
    QCOMPARE(spy.count(), 1);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
}
void test_VisaBus::queryConnected() {
    VisaBus bus(TCPIP_CONNECTION, "127.0.0.1");
    QSignalSpy spy(&bus, SIGNAL(print(QString)));
    QVERIFY(bus.query("*IDN?").isEmpty() == false);
    QCOMPARE(spy.count(), 2);
    QVERIFY(spy.takeFirst().first().toString().isEmpty() == false);
    QVERIFY(bus.query("*IDN?").contains("Rohde", Qt::CaseInsensitive));
}

void test_VisaBus::lock() {
    VisaBus bus1(TCPIP_CONNECTION, "127.0.0.1", 1000);
    VisaBus bus2(TCPIP_CONNECTION, "127.0.0.1", 1000);

    QVERIFY(bus1.lock());
    QVERIFY(bus2.query("*IDN?").isEmpty());
}
void test_VisaBus::unlock() {
    VisaBus bus1(TCPIP_CONNECTION, "127.0.0.1", 1000);
    VisaBus bus2(TCPIP_CONNECTION, "127.0.0.1", 1000);

    bus1.lock();
    QVERIFY(bus2.query("*IDN?").isEmpty());
    bus1.unlock();
    QVERIFY(!bus2.query("*IDN?").isEmpty());
}

QTEST_APPLESS_MAIN(test_VisaBus)
#include "test_VisaBus.moc"
