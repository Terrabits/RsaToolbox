#include "visabustest.h"

#include "VisaBus.h"
using namespace RsaToolbox;

VisaBusTest::VisaBusTest(QObject *parent) : TestClass(parent)
{

}

void VisaBusTest::isVisa() {
    QStringList paths = QString(qgetenv("PATH")).split(";");
    foreach (const QString &path, paths) {
        qDebug() << path;
    }
    if (VisaBus::isVisaInstalled()) {
        return;
    }
    QVERIFY(QLibrary("RsVisa32").load());
}

void VisaBusTest::cannotConnect_data() {
    QTest::addColumn<ConnectionType>("connection");
    QTest::addColumn<QString       >("address"   );

    QTest::newRow("no addr") << ConnectionType::VisaTcpConnection        << QString();
    QTest::newRow("usb"   )  << ConnectionType::VisaUsbConnection        << "0x000:0:0:0...?";
    QTest::newRow("gpib"  )  << ConnectionType::VisaGpibConnection       << "13";
    QTest::newRow("tcp"   )  << ConnectionType::VisaTcpConnection        << "1.2.3.4";
    QTest::newRow("socket")  << ConnectionType::VisaTcpSocketConnection  << "1.2.3.4::5025";
}
void VisaBusTest::cannotConnect() {
    QFETCH(ConnectionType, connection);
    QFETCH(QString,        address);

    VisaBus bus(connection, address);
    QVERIFY(!bus.isOpen());
}

void VisaBusTest::connect() {
    VisaBus bus(ConnectionType::VisaTcpSocketConnection, "127.0.0.1::5025");
    QVERIFY(bus.isOpen());
    QVERIFY(!bus.query("*IDN?\n").trimmed().isEmpty());
    QVERIFY(bus.local());
}
