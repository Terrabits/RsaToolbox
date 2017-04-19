

#include "NameLabel.h"
using namespace RsaToolbox;

#include <QtTest>


class test_NameLabel : public QObject
{
    Q_OBJECT


private Q_SLOTS:
    void setName_data();
    void setName();
    void setLabel_data();
    void setLabel();

    void equalsOperator_data();
    void equalsOperator();

    void equalityOperator_data();
    void equalityOperator();
    void inequalityOperator_data();
    void inequalityOperator();
};

void test_NameLabel::setName_data() {
    QTest::addColumn<NameLabel>("nameLabel");
    QTest::addColumn<QString>("name");

    QTest::newRow("uppercase") << NameLabel() << "NAME";
    QTest::newRow("lowercase") << NameLabel() << "name";
    QTest::newRow("mixedcase") << NameLabel() << "Name";
    QTest::newRow("overwrite") << NameLabel("Name", "Label") << "New name";
}
void test_NameLabel::setName() {
    QFETCH(NameLabel, nameLabel);
    QFETCH(QString, name);
    nameLabel.setName(name);
    QCOMPARE(nameLabel.name(), name);
}
void test_NameLabel::setLabel_data() {
    QTest::addColumn<NameLabel>("nameLabel");
    QTest::addColumn<QString>("label");

    QTest::newRow("uppercase") << NameLabel() << "LABEL";
    QTest::newRow("lowercase") << NameLabel() << "label";
    QTest::newRow("mixedcase") << NameLabel() << "Label";
    QTest::newRow("overwrite") << NameLabel("Name", "Label") << "New label";
}
void test_NameLabel::setLabel() {
    QFETCH(NameLabel, nameLabel);
    QFETCH(QString, label);
    nameLabel.setLabel(label);
    QCOMPARE(nameLabel.label(), label);
}

void test_NameLabel::equalsOperator_data() {
    QTest::addColumn<NameLabel>("right");
    QTest::addColumn<NameLabel>("left");

    QTest::newRow("rightIsBlank") << NameLabel() << NameLabel("Name", "Label");
    QTest::newRow("overwrite") << NameLabel("Name", "Label") << NameLabel("New name", "New label");
}
void test_NameLabel::equalsOperator() {
    QFETCH(NameLabel, right);
    QFETCH(NameLabel, left);
    right = left;
    QCOMPARE(right, left);
}

void test_NameLabel::equalityOperator_data() {
    QTest::addColumn<NameLabel>("rightHand");
    QTest::addColumn<NameLabel>("leftHand");

    QTest::newRow("full") << NameLabel("Name", "Label") << NameLabel("Name", "Label");
    QTest::newRow("empty label") << NameLabel("Name") << NameLabel("Name");
    QTest::newRow("empty name") << NameLabel("", "Label") << NameLabel("", "Label");
    QTest::newRow("empty") << NameLabel("") << NameLabel("");
}
void test_NameLabel::equalityOperator() {
    QFETCH(NameLabel, rightHand);
    QFETCH(NameLabel, leftHand);
    QVERIFY(rightHand == leftHand);
}

void test_NameLabel::inequalityOperator_data() {
    QTest::addColumn<NameLabel>("rightHand");
    QTest::addColumn<NameLabel>("leftHand");

    QTest::newRow("different name") << NameLabel("left-name", "Label") << NameLabel("right-name", "Label");
    QTest::newRow("different label") << NameLabel("Name", "left-label") << NameLabel("Name", "right-label");
    QTest::newRow("case-sensitive name") << NameLabel("Name") << NameLabel("name");
    QTest::newRow("case-sensitive name") << NameLabel("Name", "Label") << NameLabel("Name", "label");
}
void test_NameLabel::inequalityOperator() {
    QFETCH(NameLabel, rightHand);
    QFETCH(NameLabel, leftHand);
    QVERIFY(rightHand != leftHand);
}

QTEST_APPLESS_MAIN(test_NameLabel)
#include "test_NameLabel.moc"
