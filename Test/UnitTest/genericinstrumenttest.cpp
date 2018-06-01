#include "genericinstrumenttest.h"

#include "GenericInstrument.h"
using namespace RsaToolbox;

GenericInstrumentTest::GenericInstrumentTest(QObject *parent) : TestClass(parent)
{

}

void GenericInstrumentTest::cannotConnect_data() {
    QTest::addColumn<ConnectionType>("connection");
    QTest::addColumn<QString       >("address"   );

    QTest::newRow("usb"   ) << ConnectionType::VisaUsbConnection       << "0x000:0:0:0...?";
    QTest::newRow("gpib"  ) << ConnectionType::VisaGpibConnection      << "13";
    QTest::newRow("tcp"   ) << ConnectionType::VisaTcpConnection       << "1.2.3.4";
    QTest::newRow("socket") << ConnectionType::VisaTcpSocketConnection << "1.2.3.4::5025";
}
void GenericInstrumentTest::cannotConnect() {
    QFETCH(ConnectionType, connection);
    QFETCH(QString,        address);

    GenericInstrument instr(connection, address);
    QVERIFY(!instr.isConnected());
}
