#include "UnitsTest.h"


// RsaToolbox
#include "Definitions.h"
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QString>


UnitsTest::UnitsTest(QObject *parent) :
    TestClass(parent)
{
}

void UnitsTest::units_data() {
    QTest::addColumn<Units>("units");
    QTest::addColumn<QString>("string");

    QTest::newRow("seconds") << Units::Seconds << "s";
    QTest::newRow("hertz"  ) << Units::Hertz   << "Hz";
    QTest::newRow("radians") << Units::Radians << "Rad";
    QTest::newRow("degrees") << Units::Degrees << "Deg";
    QTest::newRow("ohms"   ) << Units::Ohms    << "Ohm";
    QTest::newRow("siemens") << Units::Siemens << "S";
    QTest::newRow("watts"  ) << Units::Watts   << "W";
    QTest::newRow("dB"     ) << Units::dB      << "dB";
    QTest::newRow("dBW"    ) << Units::dBW     << "dBW";
    QTest::newRow("dBm"    ) << Units::dBm     << "dBm";

}
void UnitsTest::units() {
    QFETCH(Units, units);
    QFETCH(QString, string);

    QCOMPARE(toString(units), string);
}

void UnitsTest::prefix_data() {
    QTest::addColumn<SiPrefix>("prefix");
    QTest::addColumn<double>("value");
    QTest::addColumn<QString>("string");

    QTest::newRow("tera")  << SiPrefix::Tera  << 1.0E12  << "T";
    QTest::newRow("giga")  << SiPrefix::Giga  << 1.0E9   << "G";
    QTest::newRow("mega")  << SiPrefix::Mega  << 1.0E6   << "M";
    QTest::newRow("kilo")  << SiPrefix::Kilo  << 1.0E3   << "K";
    QTest::newRow("none")  << SiPrefix::None  << 1.0     << "" ;
    QTest::newRow("milli") << SiPrefix::Milli << 1.0E-3  << "m";
    QTest::newRow("micro") << SiPrefix::Micro << 1.0E-6  << "u";
    QTest::newRow("nano")  << SiPrefix::Nano  << 1.0E-9  << "n";
    QTest::newRow("pico")  << SiPrefix::Pico  << 1.0E-12 << "p";
    QTest::newRow("femto") << SiPrefix::Femto << 1.0E-15 << "f";
}
void UnitsTest::prefix() {
    QFETCH(SiPrefix, prefix);
    QFETCH(double, value);
    QFETCH(QString, string);

    QCOMPARE(toDouble(prefix),   value);
    QCOMPARE(toString(prefix),   string);
    QCOMPARE(toSiPrefix(string), prefix);
}

void UnitsTest::formatValue_data() {
    QTest::addColumn<double>("value");
    QTest::addColumn<int>("decimals");
    QTest::addColumn<SiPrefix>("prefix");
    QTest::addColumn<Units>("units");
    QTest::addColumn<QString>("result");

    //Columns:     test           value    decimals   prefix            units           result
    QTest::newRow("10 MHz")    << 10.0  << 3 << SiPrefix::Mega << Units::Hertz << "10 MHz";
    QTest::newRow("1 GHz")     <<  1.0  << 3 << SiPrefix::Giga << Units::Hertz << "1 GHz";
    QTest::newRow("1.234 dBm") << 1.234 << 3 << SiPrefix::Giga << Units::Watts << "1.234 GW";
}
void UnitsTest::formatValue() {
    QFETCH(double, value);
    QFETCH(int, decimals);
    QFETCH(SiPrefix, prefix);
    QFETCH(Units, units);
    QFETCH(QString, result);

    QCOMPARE(RsaToolbox::formatValue(value, decimals, units, prefix), result);
}
