#include "MockBusTest.h"


// RsaToolbox
#include <MockBus.h>
using namespace RsaToolbox;

// Qt
#include <QByteArray>
#include <QVariant>

MockBusTest::MockBusTest()
{

}

void MockBusTest::read_data() {
    QTest::addColumn<QVariantList>("reads");

    QVariantList reads;
    reads << QByteArray("one");
    reads << QByteArray("two");
    reads << QByteArray("three");
    QTest::newRow("three strings") << reads;
}
void MockBusTest::read() {
    QFETCH(QVariantList, reads);
    MockBus bus(ConnectionType::VisaTcpConnection, "1.2.3.4");
    bus.setReads(reads);

    QVariantList result;
    for (int i = 0; i < reads.size(); i++) {
        result << QVariant(bus.binaryRead());
    }

    QCOMPARE(result, reads);
}

void MockBusTest::write_data() {
    QTest::addColumn<QVariantList>("writes");

    QVariantList writes;
    writes << QByteArray("one");
    writes << QByteArray("two");
    writes << QByteArray("three");
    QTest::newRow("three strings") << writes;
}
void MockBusTest::write() {
    QFETCH(QVariantList, writes);

    MockBus bus(ConnectionType::VisaTcpConnection, "1.2.3.4");
    foreach(QVariant i, writes) {
        bus.binaryWrite(i.toByteArray());
    }

    QCOMPARE(writes, bus.writes());
}
