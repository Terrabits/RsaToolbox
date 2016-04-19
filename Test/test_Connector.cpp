#include "Connector.h"
using namespace RsaToolbox;

#include <QtTest>

class test_Connector : public QObject
{
    Q_OBJECT

public:
    test_Connector();

private Q_SLOTS:
    void defaultConstructor();

    void displayText_data();
    void displayText();
    void displayType_data();
    void displayType();
    void displayGender_data();
    void displayGender();
    void genderAbbreviation_data();
    void genderAbbreviation();

    void isType();
    void isNotType();
    void isCustomType();
    void isNotCustomType();

    void isGender_data();
    void isGender();
    void isMale_data();
    void isMale();
    void isFemale_data();
    void isFemale();
    void isGenderNeutral_data();
    void isGenderNeutral();

    void type_data();
    void type();
    void customType_data();
    void customType();
    void gender_data();
    void gender();

    void getMatingConnector_data();
    void getMatingConnector();

    void setType();
    void setCustomType();
    void setGender();
};

test_Connector::test_Connector() {}

void test_Connector::defaultConstructor() {
    Connector connector = Connector();
    QCOMPARE(connector.type(), UNKNOWN_CONNECTOR);
    QCOMPARE(connector.gender(), NEUTRAL_GENDER);
}

void test_Connector::displayText_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<QString>("result");

    QTest::newRow("N50M") << Connector(N_50_OHM_CONNECTOR, MALE_GENDER)
                           << QString("N 50 Ohm Male");
    QTest::newRow("N75F") << Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER)
                           << QString("N 75 Ohm Female");
    QTest::newRow("7mmN") << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER)
                           << QString("7 mm Neutral");
    QTest::newRow("3.5mm M") << Connector(mm_3_5_CONNECTOR, MALE_GENDER)
                           << QString("3.5 mm Male");
    QTest::newRow("2.92mm M") << Connector(mm_2_92_CONNECTOR, MALE_GENDER)
                           << QString("2.92 mm Male");
    QTest::newRow("2.4mm M") << Connector(mm_2_4_CONNECTOR, MALE_GENDER)
                           << QString("2.4 mm Male");
    QTest::newRow("1.85mm M") << Connector(mm_1_85_CONNECTOR, MALE_GENDER)
                           << QString("1.85 mm Male");
    QTest::newRow("7/16M") << Connector(in_7_16_CONNECTOR, MALE_GENDER)
                           << QString("7/16 Male");
    QTest::newRow("F75M") << Connector(TYPE_F_75_OHM_CONNECTOR, MALE_GENDER)
                           << QString("Type F (75) Male");
    QTest::newRow("BNC50M") << Connector(BNC_50_OHM_CONNECTOR, MALE_GENDER)
                           << QString("BNC 50 Ohm Male");
    QTest::newRow("BNC75M") << Connector(BNC_75_OHM_CONNECTOR, MALE_GENDER)
                           << QString("BNC 75 Ohm Male");
    QTest::newRow("SMA M") << Connector("SMA", MALE_GENDER)
                           << QString("SMA Male");
}
void test_Connector::displayText() {
    QFETCH(Connector, connector);
    QFETCH(QString, result);
    QCOMPARE(connector.displayText(), result);
}
void test_Connector::displayType_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<QString>("result");

    QTest::newRow("N50M") << Connector(N_50_OHM_CONNECTOR, MALE_GENDER)
                           << QString("N 50 Ohm");
    QTest::newRow("N75F") << Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER)
                           << QString("N 75 Ohm");
    QTest::newRow("7mmN") << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER)
                           << QString("7 mm");
    QTest::newRow("3.5mm M") << Connector(mm_3_5_CONNECTOR, MALE_GENDER)
                           << QString("3.5 mm");
    QTest::newRow("2.92mm M") << Connector(mm_2_92_CONNECTOR, MALE_GENDER)
                           << QString("2.92 mm");
    QTest::newRow("2.4mm M") << Connector(mm_2_4_CONNECTOR, MALE_GENDER)
                           << QString("2.4 mm");
    QTest::newRow("1.85mm M") << Connector(mm_1_85_CONNECTOR, MALE_GENDER)
                           << QString("1.85 mm");
    QTest::newRow("7/16M") << Connector(in_7_16_CONNECTOR, MALE_GENDER)
                           << QString("7/16");
    QTest::newRow("F75M") << Connector(TYPE_F_75_OHM_CONNECTOR, MALE_GENDER)
                           << QString("Type F (75)");
    QTest::newRow("BNC50M") << Connector(BNC_50_OHM_CONNECTOR, MALE_GENDER)
                           << QString("BNC 50 Ohm");
    QTest::newRow("BNC75M") << Connector(BNC_75_OHM_CONNECTOR, MALE_GENDER)
                           << QString("BNC 75 Ohm");
    QTest::newRow("SMA M") << Connector("SMA", MALE_GENDER)
                           << QString("SMA");
}
void test_Connector::displayType() {
    QFETCH(Connector, connector);
    QFETCH(QString, result);
    QCOMPARE(connector.displayType(), result);
}
void test_Connector::displayGender_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<QString>("result");

    QTest::newRow("N50M") << Connector(N_50_OHM_CONNECTOR, MALE_GENDER)
                           << QString("Male");
    QTest::newRow("N75F") << Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER)
                           << QString("Female");
    QTest::newRow("7mmN") << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER)
                           << QString("Neutral");
}
void test_Connector::displayGender() {
    QFETCH(Connector, connector);
    QFETCH(QString, result);
    QCOMPARE(connector.displayGender(), result);
}
void test_Connector::genderAbbreviation_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<QString>("result");

    QTest::newRow("N50M") << Connector(N_50_OHM_CONNECTOR, MALE_GENDER)
                           << QString("M");
    QTest::newRow("N75F") << Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER)
                           << QString("F");
    QTest::newRow("7mmN") << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER)
                           << QString("N");
}
void test_Connector::genderAbbreviation() {
    QFETCH(Connector, connector);
    QFETCH(QString, result);
    QCOMPARE(connector.genderAbbreviation(), result);
}

void test_Connector::isType() {
    Connector connector = Connector();
    Connector same = Connector();
    Connector different(N_50_OHM_CONNECTOR, MALE_GENDER);
    QVERIFY(connector.isType(same));
    QVERIFY(connector.isType(different) == false);
}
void test_Connector::isNotType() {
    Connector connector = Connector();
    Connector same = Connector();
    Connector different(N_50_OHM_CONNECTOR, MALE_GENDER);
    QVERIFY(connector.isNotType(same) == false);
    QVERIFY(connector.isNotType(different));
}
void test_Connector::isCustomType() {
    Connector connector("SMA", MALE_GENDER);
    QVERIFY(connector.isCustomType());

    connector.setType(mm_7_CONNECTOR);
    QVERIFY(connector.isCustomType() == false);
}
void test_Connector::isNotCustomType() {
    Connector connector("SMA", MALE_GENDER);
    QVERIFY(connector.isNotCustomType() == false);

    connector.setType(mm_7_CONNECTOR);
    QVERIFY(connector.isNotCustomType());
}

void test_Connector::isGender_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<bool>("resultM");
    QTest::addColumn<bool>("resultF");
    QTest::addColumn<bool>("resultN");

    QTest::newRow("N50M") << Connector(N_50_OHM_CONNECTOR, MALE_GENDER)
                          << true << false << false;
    QTest::newRow("N75F") << Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER)
                           << false << true << false;
    QTest::newRow("7mmN") << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER)
                           << false << false << true;
}
void test_Connector::isGender() {
    QFETCH(Connector, connector);
    QFETCH(bool, resultM);
    QFETCH(bool, resultF);
    QFETCH(bool, resultN);
    QCOMPARE(connector.isGender(MALE_GENDER), resultM);
    QCOMPARE(connector.isGender(FEMALE_GENDER), resultF);
    QCOMPARE(connector.isGender(NEUTRAL_GENDER), resultN);
}
void test_Connector::isMale_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<bool>("result");

    QTest::newRow("N50M") << Connector(N_50_OHM_CONNECTOR, MALE_GENDER)
                          << true;
    QTest::newRow("N75F") << Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER)
                           << false;
    QTest::newRow("7mmN") << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER)
                           << false;
}
void test_Connector::isMale() {
    QFETCH(Connector, connector);
    QFETCH(bool, result);
    QCOMPARE(connector.isMale(), result);
    QCOMPARE(connector.isNotMale(), !result);
}
void test_Connector::isFemale_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<bool>("result");

    QTest::newRow("N50M") << Connector(N_50_OHM_CONNECTOR, MALE_GENDER)
                          << false;
    QTest::newRow("N75F") << Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER)
                           << true;
    QTest::newRow("7mmN") << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER)
                           << false;
}
void test_Connector::isFemale() {
    QFETCH(Connector, connector);
    QFETCH(bool, result);
    QCOMPARE(connector.isFemale(), result);
    QCOMPARE(connector.isNotFemale(), !result);
}
void test_Connector::isGenderNeutral_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<bool>("result");

    QTest::newRow("N50M") << Connector(N_50_OHM_CONNECTOR, MALE_GENDER)
                          << false;
    QTest::newRow("N75F") << Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER)
                           << false;
    QTest::newRow("7mmN") << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER)
                           << true;
}
void test_Connector::isGenderNeutral() {
    QFETCH(Connector, connector);
    QFETCH(bool, result);
    QCOMPARE(connector.isGenderNeutral(), result);
    QCOMPARE(connector.isGenderSpecific(), !result);
}

void test_Connector::type_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<ConnectorType>("result");

    QTest::newRow("N50M") << Connector(N_50_OHM_CONNECTOR, MALE_GENDER)
                           << N_50_OHM_CONNECTOR;
    QTest::newRow("N75F") << Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER)
                           << N_75_OHM_CONNECTOR;
    QTest::newRow("7mmN") << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER)
                           << mm_7_CONNECTOR;
    QTest::newRow("3.5mm M") << Connector(mm_3_5_CONNECTOR, MALE_GENDER)
                           << mm_3_5_CONNECTOR;
    QTest::newRow("2.92mm M") << Connector(mm_2_92_CONNECTOR, MALE_GENDER)
                           << mm_2_92_CONNECTOR;
    QTest::newRow("2.4mm M") << Connector(mm_2_4_CONNECTOR, MALE_GENDER)
                           << mm_2_4_CONNECTOR;
    QTest::newRow("1.85mm M") << Connector(mm_1_85_CONNECTOR, MALE_GENDER)
                           << mm_1_85_CONNECTOR;
    QTest::newRow("7/16M") << Connector(in_7_16_CONNECTOR, MALE_GENDER)
                           << in_7_16_CONNECTOR;
    QTest::newRow("F75M") << Connector(TYPE_F_75_OHM_CONNECTOR, MALE_GENDER)
                           << TYPE_F_75_OHM_CONNECTOR;
    QTest::newRow("BNC50M") << Connector(BNC_50_OHM_CONNECTOR, MALE_GENDER)
                           << BNC_50_OHM_CONNECTOR;
    QTest::newRow("BNC75M") << Connector(BNC_75_OHM_CONNECTOR, MALE_GENDER)
                           << BNC_75_OHM_CONNECTOR;
}
void test_Connector::type() {
    QFETCH(Connector, connector);
    QFETCH(ConnectorType, result);
    QCOMPARE(connector.type(), result);
}
void test_Connector::customType_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<QString>("result");

    QTest::newRow("SMA F") << Connector("SMA", FEMALE_GENDER)
                           << QString("SMA");
}
void test_Connector::customType() {
    QFETCH(Connector, connector);
    QFETCH(QString, result);
    QCOMPARE(connector.customType(), result);
}
void test_Connector::gender_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<ConnectorGender>("result");

    QTest::newRow("N50M") << Connector(N_50_OHM_CONNECTOR, MALE_GENDER)
                          << MALE_GENDER;
    QTest::newRow("N75F") << Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER)
                           << FEMALE_GENDER;
    QTest::newRow("7mmN") << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER)
                           << NEUTRAL_GENDER;
}
void test_Connector::gender() {
    QFETCH(Connector, connector);
    QFETCH(ConnectorGender, result);
    QCOMPARE(connector.gender(), result);
}

void test_Connector::getMatingConnector_data() {
    QTest::addColumn<Connector>("connector");
    QTest::addColumn<Connector>("result");

    QTest::newRow("N50M") << Connector(N_50_OHM_CONNECTOR, MALE_GENDER)
                          << Connector(N_50_OHM_CONNECTOR, FEMALE_GENDER);
    QTest::newRow("N75F") << Connector(N_75_OHM_CONNECTOR, FEMALE_GENDER)
                          << Connector(N_75_OHM_CONNECTOR, MALE_GENDER);
    QTest::newRow("7mmN") << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER)
                          << Connector(mm_7_CONNECTOR, NEUTRAL_GENDER);
}
void test_Connector::getMatingConnector() {
    QFETCH(Connector, connector);
    QFETCH(Connector, result);
    QCOMPARE(connector.getMatingConnector(), result);
}

void test_Connector::setType() {
    Connector connector(N_50_OHM_CONNECTOR, MALE_GENDER);
    connector.setType(BNC_75_OHM_CONNECTOR);
    QCOMPARE(connector.type(), BNC_75_OHM_CONNECTOR);
    Connector newType(TYPE_F_75_OHM_CONNECTOR, FEMALE_GENDER);
    connector.setType(newType);
    QCOMPARE(connector.type(), TYPE_F_75_OHM_CONNECTOR);
}
void test_Connector::setCustomType() {
    Connector connector(N_50_OHM_CONNECTOR, MALE_GENDER);
    connector.setCustomType("SMA");
    QCOMPARE(connector.customType(), QString("SMA"));
}
void test_Connector::setGender() {
    Connector connector("SMA", FEMALE_GENDER);
    connector.setGender(MALE_GENDER);
    QCOMPARE(connector.gender(), MALE_GENDER);
}

QTEST_APPLESS_MAIN(test_Connector)
#include "test_Connector.moc"
