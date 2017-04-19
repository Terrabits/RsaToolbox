#include "VnaCalStandard.h"
using namespace RsaToolbox;

#include <QtTest>

class test_CalStandard : public QObject
{
    Q_OBJECT

public:
    test_CalStandard() {}

private Q_SLOTS:
    void displayText_data();
    void displayText();
    void displayType_data();
    void displayType();
    void isType_data();
    void isType();
    void singlePortGender_data();
    void singlePortGender();
    void twoPortGender_data();
    void twoPortGender();
    void isSinglePortSpecific_data();
    void isSinglePortSpecific();
    void isTwoPortSpecific_data();
    void isTwoPortSpecific();
    void isSinglePort_data();
    void isSinglePort();
    void isLikeThis_data();
    void isLikeThis();
};
void test_CalStandard::displayText_data() {
    QTest::addColumn<VnaCalStandard>("standard");
    QTest::addColumn<QString>("result");

    QTest::newRow("Open N 50 Ohm Male") << VnaCalStandard(OPEN_STANDARD_TYPE, Connector(N_50_OHM_CONNECTOR, MALE_GENDER))
                                      << QString("Open N 50 Ohm Male");
    QTest::newRow("Short N 75 Ohm Female") << VnaCalStandard(SHORT_STANDARD_TYPE, Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER))
                                      << QString("Short N 75 Ohm Female");
    QTest::newRow("Match 7 mm Neutral") << VnaCalStandard(MATCH_STANDARD_TYPE, Connector(mm_7_CONNECTOR, NEUTRAL_GENDER))
                                      << QString("Match 7 mm Neutral");
    QTest::newRow("Sliding Match (P1)") << VnaCalStandard(SLIDING_MATCH_STANDARD_TYPE, 1)
                                      << QString("Sliding Match (P1)");
    QTest::newRow("Thru 3.5 mm Male-3.5 mm Male") << VnaCalStandard(THRU_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, MALE_GENDER), Connector(mm_3_5_CONNECTOR, MALE_GENDER))
                                      << QString("Thru 3.5 mm Male-3.5 mm Male");
    QTest::newRow("Attenuation (P1P2)") << VnaCalStandard(ATTENUATION_STANDARD_TYPE, 1,2)
                                      << QString("Attenuation (P1P2)");
}
void test_CalStandard::displayText() {
    QFETCH(VnaCalStandard, standard);
    QFETCH(QString, result);
    QCOMPARE(standard.displayText(), result);
}
void test_CalStandard::displayType_data() {
    QTest::addColumn<VnaCalStandard>("standard");
    QTest::addColumn<QString>("result");

    QTest::newRow("Open") << VnaCalStandard(OPEN_STANDARD_TYPE, Connector(N_50_OHM_CONNECTOR, MALE_GENDER))
                                      << QString("Open");
    QTest::newRow("Short") << VnaCalStandard(SHORT_STANDARD_TYPE, Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER))
                                      << QString("Short");
    QTest::newRow("Offset Short 1") << VnaCalStandard(OFFSET_SHORT_STANDARD_TYPE, Connector(mm_7_CONNECTOR, NEUTRAL_GENDER))
                                      << QString("Offset Short 1");
    QTest::newRow("Offset Short 2") << VnaCalStandard(OFFSET_SHORT2_STANDARD_TYPE, 1)
                                      << QString("Offset Short 2");
    QTest::newRow("Offset Short 3") << VnaCalStandard(OFFSET_SHORT3_STANDARD_TYPE, 2)
                                      << QString("Offset Short 3");
    QTest::newRow("Match") << VnaCalStandard(MATCH_STANDARD_TYPE, 3)
                                      << QString("Match");
    QTest::newRow("Sliding Match") << VnaCalStandard(SLIDING_MATCH_STANDARD_TYPE, 3)
                                      << QString("Sliding Match");
    QTest::newRow("Reflection") << VnaCalStandard(REFLECT_STANDARD_TYPE, 3)
                                      << QString("Reflection");
    QTest::newRow("Thru") << VnaCalStandard(THRU_STANDARD_TYPE, 1, 2)
                                      << QString("Thru");
    QTest::newRow("Line") << VnaCalStandard(LINE_STANDARD_TYPE, 1, 2)
                                      << QString("Line");
    QTest::newRow("Line 2") << VnaCalStandard(LINE2_STANDARD_TYPE, 1, 2)
                                      << QString("Line 2");
    QTest::newRow("Line 3") << VnaCalStandard(LINE3_STANDARD_TYPE, 1, 2)
                                      << QString("Line 3");
    QTest::newRow("Attenuation") << VnaCalStandard(ATTENUATION_STANDARD_TYPE, 1, 2)
                                      << QString("Attenuation");
    QTest::newRow("Symmetric Network") << VnaCalStandard(SYMMETRIC_NETWORK_STANDARD_TYPE, 1, 2)
                                      << QString("Symmetric Network");
}
void test_CalStandard::displayType() {
    QFETCH(VnaCalStandard, standard);
    QFETCH(QString, result);
    QCOMPARE(standard.displayType(), result);
}
void test_CalStandard::isType_data() {
    QTest::addColumn<VnaCalStandard>("standard");
    QTest::addColumn<CalStandardType>("type");
    QTest::addColumn<bool>("isType");

    QTest::newRow("Open == OPEN?") << VnaCalStandard(OPEN_STANDARD_TYPE, 1) << OPEN_STANDARD_TYPE << true;
    QTest::newRow("Open == SHORT?") << VnaCalStandard(OPEN_STANDARD_TYPE, 1) << SHORT_STANDARD_TYPE << false;
    QTest::newRow("Thru == MATCH?") << VnaCalStandard(THRU_STANDARD_TYPE, 1, 2) << MATCH_STANDARD_TYPE << false;
    QTest::newRow("Thru == UNKNOWN?") << VnaCalStandard(THRU_STANDARD_TYPE, 1, 2) << UNKNOWN_STANDARD_TYPE << false;
    QTest::newRow("Unknown == REFLECT?") << VnaCalStandard() << REFLECT_STANDARD_TYPE << false;
}
void test_CalStandard::isType() {
    QFETCH(VnaCalStandard, standard);
    QFETCH(CalStandardType, type);
    QFETCH(bool, isType);

    QCOMPARE(standard.isType(type), isType);
    QCOMPARE(standard.isNotType(type), !isType);
}
void test_CalStandard::singlePortGender_data() {
    QTest::addColumn<VnaCalStandard>("standard");
    QTest::addColumn<ConnectorGender>("gender");
    QTest::addColumn<bool>("isGender");
    QTest::addColumn<bool>("isMale");
    QTest::addColumn<bool>("isFemale");
    QTest::addColumn<bool>("isPortSpecific");

    QTest::newRow("Male == MALE?") << VnaCalStandard(OPEN_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, MALE_GENDER))
                                   << MALE_GENDER << true
                                   << true << false << false;
    QTest::newRow("Female == MALE?") << VnaCalStandard(OPEN_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, FEMALE_GENDER))
                                   << MALE_GENDER << false
                                   << false << true << false;
    QTest::newRow("Neutral == MALE?") << VnaCalStandard(OPEN_STANDARD_TYPE, Connector(mm_7_CONNECTOR, NEUTRAL_GENDER))
                                   << MALE_GENDER << false
                                   << false << false << false;
    QTest::newRow("Female == NEUTRAL?") << VnaCalStandard(OPEN_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, FEMALE_GENDER))
                                   << NEUTRAL_GENDER << false
                                   << false << true << false;
    QTest::newRow("P1 == MALE?") << VnaCalStandard(OPEN_STANDARD_TYPE, 1)
                                   << MALE_GENDER << false
                                   << false << false << true;
    QTest::newRow("Thru MF == MALE?") << VnaCalStandard(THRU_STANDARD_TYPE, Connector(N_50_OHM_CONNECTOR, MALE_GENDER), Connector(N_50_OHM_CONNECTOR, FEMALE_GENDER))
                                   << MALE_GENDER << false
                                   << false << false << false;
    QTest::newRow("Thru (P1P2) == FEMALE?") << VnaCalStandard(THRU_STANDARD_TYPE, 1, 2)
                                   << FEMALE_GENDER << false
                                   << false << false << true;
}
void test_CalStandard::singlePortGender() {
    QFETCH(VnaCalStandard, standard);
    QFETCH(ConnectorGender, gender);
    QFETCH(bool, isGender);
    QFETCH(bool, isMale);
    QFETCH(bool, isFemale);
    QFETCH(bool, isPortSpecific);

    QCOMPARE(standard.isGender(gender), isGender);
    QCOMPARE(standard.isMale(), isMale);
    QCOMPARE(standard.isFemale(), isFemale);
    QCOMPARE(standard.isPortSpecific(), isPortSpecific);
}
void test_CalStandard::twoPortGender_data() {
    QTest::addColumn<VnaCalStandard>("standard");
    QTest::addColumn<ConnectorGender>("gender1");
    QTest::addColumn<ConnectorGender>("gender2");
    QTest::addColumn<bool>("isGender");
    QTest::addColumn<bool>("isMale");
    QTest::addColumn<bool>("isFemale");
    QTest::addColumn<bool>("isPortSpecific");

    QTest::newRow("Male == MALE-MALE?") << VnaCalStandard(OPEN_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, MALE_GENDER))
                                   << MALE_GENDER << MALE_GENDER << false
                                   << true << false << false;
    QTest::newRow("Male-Male == MALE-MALE?") << VnaCalStandard(THRU_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, MALE_GENDER), Connector(mm_3_5_CONNECTOR, MALE_GENDER))
                                   << MALE_GENDER << MALE_GENDER << true
                                   << false << false << false;
    QTest::newRow("Male-Female == MALE-MALE?") << VnaCalStandard(THRU_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, MALE_GENDER), Connector(mm_3_5_CONNECTOR, FEMALE_GENDER))
                                   << MALE_GENDER << MALE_GENDER << false
                                   << false << false << false;
    QTest::newRow("P1P2 == MALE-MALE?") << VnaCalStandard(THRU_STANDARD_TYPE, 1, 2)
                                   << MALE_GENDER << MALE_GENDER << false
                                   << false << false << true;
}
void test_CalStandard::twoPortGender() {
    QFETCH(VnaCalStandard, standard);
    QFETCH(ConnectorGender, gender1);
    QFETCH(ConnectorGender, gender2);
    QFETCH(bool, isGender);
    QFETCH(bool, isMale);
    QFETCH(bool, isFemale);
    QFETCH(bool, isPortSpecific);

    QCOMPARE(standard.isGender(gender1, gender2), isGender);
    QCOMPARE(standard.isMale(), isMale);
    QCOMPARE(standard.isFemale(), isFemale);
    QCOMPARE(standard.isPortSpecific(), isPortSpecific);
}
void test_CalStandard::isSinglePortSpecific_data() {
    QTest::addColumn<VnaCalStandard>("standard");
    QTest::addColumn<bool>("isPortSpecific");
    QTest::addColumn<uint>("port");
    QTest::addColumn<bool>("isPortThePort");

    QTest::newRow("P1 == P1?") << VnaCalStandard(OPEN_STANDARD_TYPE, 1) << true
                               << uint(1) << true;
    QTest::newRow("P1 == P2?") << VnaCalStandard(OPEN_STANDARD_TYPE, 1) << true
                               << uint(2) << false;
    QTest::newRow("P1P2 == P2?") << VnaCalStandard(THRU_STANDARD_TYPE, 1, 2) << true
                               << uint(2) << false;
    QTest::newRow("Male == P2?") << VnaCalStandard(OPEN_STANDARD_TYPE, Connector(N_50_OHM_CONNECTOR, MALE_GENDER)) << false
                               << uint(2) << false;
    QTest::newRow("Male-Male == P2?") << VnaCalStandard(THRU_STANDARD_TYPE, Connector(N_50_OHM_CONNECTOR, MALE_GENDER), Connector(N_50_OHM_CONNECTOR, MALE_GENDER)) << false
                               << uint(2) << false;
}
void test_CalStandard::isSinglePortSpecific() {
    QFETCH(VnaCalStandard, standard);
    QFETCH(bool, isPortSpecific);
    QFETCH(uint, port);
    QFETCH(bool, isPortThePort);

    QCOMPARE(standard.isPortSpecific(), isPortSpecific);
    QCOMPARE(standard.isPortSpecific(port), isPortThePort);
}
void test_CalStandard::isTwoPortSpecific_data() {
    QTest::addColumn<VnaCalStandard>("standard");
    QTest::addColumn<bool>("isPortSpecific");
    QTest::addColumn<uint>("port1");
    QTest::addColumn<uint>("port2");
    QTest::addColumn<bool>("isPortsThePorts");

    QTest::newRow("P1P2 == P1P2?") << VnaCalStandard(THRU_STANDARD_TYPE, 1, 2) << true
                                   << uint(1) << uint(2) << true;
    QTest::newRow("P1P2 == P1P3?") << VnaCalStandard(THRU_STANDARD_TYPE, 1, 2) << true
                                   << uint(1) << uint(3) << false;
    QTest::newRow("P2P3 == P1P3?") << VnaCalStandard(THRU_STANDARD_TYPE, 2, 3) << true
                                   << uint(1) << uint(3) << false;
    QTest::newRow("P1 == P1P2?") << VnaCalStandard(OPEN_STANDARD_TYPE, 1) << true
                                 << uint(1) << uint(2) << false;
}
void test_CalStandard::isTwoPortSpecific() {
    QFETCH(VnaCalStandard, standard);
    QFETCH(bool, isPortSpecific);
    QFETCH(uint, port1);
    QFETCH(uint, port2);
    QFETCH(bool, isPortsThePorts);

    QCOMPARE(standard.isPortSpecific(), isPortSpecific);
    QCOMPARE(standard.isPortSpecific(port1, port2), isPortsThePorts);
}
void test_CalStandard::isSinglePort_data() {
    QTest::addColumn<VnaCalStandard>("standard");
    QTest::addColumn<bool>("isSinglePort");

    QTest::newRow("Open") << VnaCalStandard(OPEN_STANDARD_TYPE, 1) << true;
    QTest::newRow("Short") << VnaCalStandard(SHORT_STANDARD_TYPE, 1) << true;
    QTest::newRow("Offset Short 1") << VnaCalStandard(OFFSET_SHORT_STANDARD_TYPE, 1) << true;
    QTest::newRow("Offset Short 2") << VnaCalStandard(OFFSET_SHORT2_STANDARD_TYPE, 1) << true;
    QTest::newRow("Offset Short 3") << VnaCalStandard(OFFSET_SHORT3_STANDARD_TYPE, 1) << true;
    QTest::newRow("Match") << VnaCalStandard(MATCH_STANDARD_TYPE, 1) << true;
    QTest::newRow("Sliding Match") << VnaCalStandard(SLIDING_MATCH_STANDARD_TYPE, 1) << true;
    QTest::newRow("Reflection") << VnaCalStandard(REFLECT_STANDARD_TYPE, 1) << true;
    QTest::newRow("Thru") << VnaCalStandard(THRU_STANDARD_TYPE, 1, 2) << false;
    QTest::newRow("Line") << VnaCalStandard(LINE_STANDARD_TYPE, 1, 2) << false;
    QTest::newRow("Line2") << VnaCalStandard(LINE2_STANDARD_TYPE, 1, 2) << false;
    QTest::newRow("Line3") << VnaCalStandard(LINE3_STANDARD_TYPE, 1, 2) << false;
    QTest::newRow("Attenuation") << VnaCalStandard(ATTENUATION_STANDARD_TYPE, 1, 2) << false;
    QTest::newRow("Symmetric Network") << VnaCalStandard(SYMMETRIC_NETWORK_STANDARD_TYPE, 1, 2) << false;
}
void test_CalStandard::isSinglePort() {
    QFETCH(VnaCalStandard, standard);
    QFETCH(bool, isSinglePort);

    QCOMPARE(standard.isSinglePort(), isSinglePort);
    QCOMPARE(standard.isTwoPort(), !isSinglePort);
}

// isSameStandardAs

void test_CalStandard::isLikeThis_data() {
    QTest::addColumn<VnaCalStandard>("standard");
    QTest::addColumn<bool>("isOpen");
    QTest::addColumn<bool>("isMaleOpen");
    QTest::addColumn<bool>("isFemaleOpen");
    QTest::addColumn<bool>("isShort");
    QTest::addColumn<bool>("isMaleShort");
    QTest::addColumn<bool>("isFemaleShort");
    QTest::addColumn<bool>("isMatch");
    QTest::addColumn<bool>("isMaleMatch");
    QTest::addColumn<bool>("isFemaleMatch");
    QTest::addColumn<bool>("isThru");
    QTest::addColumn<bool>("isThruMM");
    QTest::addColumn<bool>("isThruMF");
    QTest::addColumn<bool>("isThruFF");

    QTest::newRow("Open Male") << VnaCalStandard(OPEN_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, MALE_GENDER))
                               << true << true << false // open
                               << false << false << false // short
                               << false << false << false // match
                               << false << false << false << false; // thru
    QTest::newRow("Short Female") << VnaCalStandard(SHORT_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, FEMALE_GENDER))
                               << false << false << false // open
                               << true << false << true // short
                               << false << false << false // match
                               << false << false << false << false; // thru
    QTest::newRow("Match Neutral") << VnaCalStandard(MATCH_STANDARD_TYPE, Connector(mm_7_CONNECTOR, NEUTRAL_GENDER))
                               << false << false << false // open
                               << false << false << false // short
                               << true << false << false // match
                               << false << false << false << false; // thru
    QTest::newRow("Reflection Female") << VnaCalStandard(REFLECT_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, FEMALE_GENDER))
                               << false << false << false // open
                               << false << false << false // short
                               << false << false << false // match
                               << false << false << false << false; // thru
    QTest::newRow("Thru MM") << VnaCalStandard(THRU_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, MALE_GENDER), Connector(mm_3_5_CONNECTOR, MALE_GENDER))
                               << false << false << false // open
                               << false << false << false // short
                               << false << false << false // match
                               << true << true << false << false; // thru
    QTest::newRow("Thru MF") << VnaCalStandard(THRU_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, MALE_GENDER), Connector(mm_3_5_CONNECTOR, FEMALE_GENDER))
                               << false << false << false // open
                               << false << false << false // short
                               << false << false << false // match
                               << true << false << true << false; // thru
    QTest::newRow("Thru FF") << VnaCalStandard(THRU_STANDARD_TYPE, Connector(mm_3_5_CONNECTOR, FEMALE_GENDER), Connector(mm_3_5_CONNECTOR, FEMALE_GENDER))
                               << false << false << false // open
                               << false << false << false // short
                               << false << false << false // match
                               << true << false << false << true; // thru

}
void test_CalStandard::isLikeThis() {
    QFETCH(VnaCalStandard, standard);
    QFETCH(bool, isOpen);
    QFETCH(bool, isMaleOpen);
    QFETCH(bool, isFemaleOpen);
    QFETCH(bool, isShort);
    QFETCH(bool, isMaleShort);
    QFETCH(bool, isFemaleShort);
    QFETCH(bool, isMatch);
    QFETCH(bool, isMaleMatch);
    QFETCH(bool, isFemaleMatch);
    QFETCH(bool, isThru);
    QFETCH(bool, isThruMM);
    QFETCH(bool, isThruMF);
    QFETCH(bool, isThruFF);

    QCOMPARE(standard.isOpen(), isOpen);
    QCOMPARE(standard.isMaleOpen(), isMaleOpen);
    QCOMPARE(standard.isFemaleOpen(), isFemaleOpen);
    QCOMPARE(standard.isShort(), isShort);
    QCOMPARE(standard.isMaleShort(), isMaleShort);
    QCOMPARE(standard.isFemaleShort(), isFemaleShort);
    QCOMPARE(standard.isMatch(), isMatch);
    QCOMPARE(standard.isMaleMatch(), isMaleMatch);
    QCOMPARE(standard.isFemaleMatch(), isFemaleMatch);
    QCOMPARE(standard.isThru(), isThru);
    QCOMPARE(standard.isThruMM(), isThruMM);
    QCOMPARE(standard.isThruMF(), isThruMF);
    QCOMPARE(standard.isThruFF(), isThruFF);
}

QTEST_APPLESS_MAIN(test_CalStandard)
#include "test_CalStandard.moc"
