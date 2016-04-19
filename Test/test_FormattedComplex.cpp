

#include "FormattedComplex.h"
#include "FormattedNetworkData.h"
#include "FormattedTouchstone.h"
#include "General.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>
#include <QDir>

class test_FormattedComplex : public QObject
{
    Q_OBJECT

public:
    test_FormattedComplex();

private:
    QDir fileDir;

    QString reImFileName;
    QString reImFilePath;

    QString magAngleFileName;
    QString magAngleFilePath;

    QString dBAngleFileName;
    QString dBAngleFilePath;

private Q_SLOTS:
    void init();
    void cleanup();

    void realImag();
    void dbAngle();
    void magAngle();

    void writeReIm();
    void readReIm();

    void writeDbAngle();
    void readDbAngle();

    void writeMagAngle();
    void readMagAngle();
};

test_FormattedComplex::test_FormattedComplex() {
    QDir dir(SOURCE_DIR);
    dir.cd("Files");
    if (!dir.exists("FormattedComplex"))
        dir.mkpath("FormattedComplex");
    dir.cd("FormattedComplex");
    fileDir = dir;

    reImFileName = "reIm.s4p";
    reImFilePath = fileDir.filePath(reImFileName);

    magAngleFileName = "magAngle.s2p";
    magAngleFilePath = fileDir.filePath(magAngleFileName);

    dBAngleFileName = "dBAngle.s2p";
    dBAngleFilePath =  fileDir.filePath(dBAngleFileName);
}

void test_FormattedComplex::init() {

}
void test_FormattedComplex::cleanup() {

}

void test_FormattedComplex::realImag() {
    FormattedComplex reIm = FormattedComplex::realImaginary(1.0/sqrt(2.0), -1.0/sqrt(2.0));
    QCOMPARE(reIm.format(), REAL_IMAGINARY_COMPLEX);
    QVERIFY(reIm.isRealImaginary());
    QVERIFY(!reIm.isDbDegrees());
    QVERIFY(!reIm.isMagnitudeDegrees());
    QCOMPARE(reIm.value(), ComplexDouble(1.0/sqrt(2.0), -1.0/sqrt(2.0)));
    QCOMPARE(reIm.real(), 1.0/sqrt(2.0));
    QCOMPARE(reIm.imaginary(), -1.0/sqrt(2.0));
    QCOMPARE(reIm.magnitude(), 1.0);
    QCOMPARE(reIm.dB(), 0.0);
    QCOMPARE(reIm.angle_deg(), -45.0);
    QCOMPARE(reIm.angle_rad(), -1.0*PI/4.0);
}
void test_FormattedComplex::dbAngle() {
    FormattedComplex dbA = FormattedComplex::dBAngle(0.0, -45.0);
    QCOMPARE(dbA.format(), DB_DEGREES_COMPLEX);
    QVERIFY(!dbA.isRealImaginary());
    QVERIFY(dbA.isDbDegrees());
    QVERIFY(!dbA.isMagnitudeDegrees());
    QCOMPARE(dbA.value().real(), ComplexDouble(1.0/sqrt(2.0), -1.0/sqrt(2.0)).real());
    QCOMPARE(dbA.value().imag(), ComplexDouble(1.0/sqrt(2.0), -1.0/sqrt(2.0)).imag());
    QCOMPARE(dbA.real(), 1.0/sqrt(2.0));
    QCOMPARE(dbA.imaginary(), -1.0/sqrt(2.0));
    QCOMPARE(dbA.magnitude(), 1.0);
    QCOMPARE(dbA.dB(), 0.0);
    QCOMPARE(dbA.angle_deg(), -45.0);
    QCOMPARE(dbA.angle_rad(), -1.0*PI/4.0);
}
void test_FormattedComplex::magAngle() {
    FormattedComplex dbA = FormattedComplex::magnitudeAngle(1.0, -45.0);
    QCOMPARE(dbA.format(), MAGNITUDE_DEGREES_COMPLEX);
    QVERIFY(!dbA.isRealImaginary());
    QVERIFY(!dbA.isDbDegrees());
    QVERIFY(dbA.isMagnitudeDegrees());
    QCOMPARE(dbA.value().real(), ComplexDouble(1.0/sqrt(2.0), -1.0/sqrt(2.0)).real());
    QCOMPARE(dbA.value().imag(), ComplexDouble(1.0/sqrt(2.0), -1.0/sqrt(2.0)).imag());
    QCOMPARE(dbA.real(), 1.0/sqrt(2.0));
    QCOMPARE(dbA.imaginary(), -1.0/sqrt(2.0));
    QCOMPARE(dbA.magnitude(), 1.0);
    QCOMPARE(dbA.dB(), 0.0);
    QCOMPARE(dbA.angle_deg(), -45.0);
    QCOMPARE(dbA.angle_rad(), -1.0*PI/4.0);
}
void test_FormattedComplex::writeReIm() {
    int points = 101;
    int ports = 4;

    int val = 0;
    FormattedComplexMatrix3D data;
    data.resize(points);
    for (int f = 0; f < points; f++) {
        data[f].resize(ports);
        for (int i = 0; i < ports; i++) {
            data[f][i].resize(ports);
            for (int j = 0; j < ports; j++) {
                double a = val++;
                double b = val++;
                data[f][i][j] = FormattedComplex::realImaginary(a, b);
            }
        }
    }
    QRowVector freq = linearSpacing(1.0, 2.0, points);

    FormattedNetworkData network;
    network.setParameter(S_PARAMETER);
    network.setReferenceImpedance(50);
    network.setFormat(REAL_IMAGINARY_COMPLEX);
    network.setXUnits(HERTZ_UNITS, GIGA_PREFIX);
    network.setNumberOfPorts(ports);
    network.setData(freq, data);

    QVERIFY(fileDir.exists());
    if (fileDir.exists(reImFileName))
        QVERIFY(fileDir.remove(reImFileName));

    QVERIFY(FormattedTouchstone::Write(network, reImFilePath));
    QVERIFY(fileDir.exists(reImFileName));
    QVERIFY(QFileInfo(reImFilePath).size() > 0);
}
void test_FormattedComplex::readReIm() {
    FormattedNetworkData network;
    QVERIFY(FormattedTouchstone::Read(network, reImFilePath));

    int ports = 4;
    int points = 101;
    QCOMPARE(network.numberOfPorts(), uint(ports));
    QCOMPARE(network.points(), uint(points));
    QCOMPARE(network.format(), REAL_IMAGINARY_COMPLEX);
    QCOMPARE(network.xUnits(), HERTZ_UNITS);
    QCOMPARE(network.xPrefix(), GIGA_PREFIX);
    QCOMPARE(network.referenceImpedance_Ohms(), 50.0);

    int val = 0;
    for (int f = 0; f < points; f++) {
        for (int i = 0; i < ports; i++) {
            for (int j = 0; j < ports; j++) {
                double a = val++;
                double b = val++;
                QVERIFY(network.y()[f][i][j] == FormattedComplex::realImaginary(a, b));
            }
        }
    }
}
void test_FormattedComplex::writeDbAngle() {
    int ports = 2;
    int points = 201;

    int val = 0;
    FormattedComplexMatrix3D data;
    data.resize(points);
    for (int f = 0; f < points; f++) {
        data[f].resize(ports);
        for (int i = 0; i < ports; i++) {
            data[f][i].resize(ports);
            for (int j = 0; j < ports; j++) {
                double a = val++;
                double b = val++;
                data[f][i][j] = FormattedComplex::dBAngle(a, b);
            }
        }
    }
    QRowVector freq = linearSpacing(1.0, 2.0, points);

    FormattedNetworkData network;
    network.setParameter(S_PARAMETER);
    network.setReferenceImpedance(50);
    network.setFormat(DB_DEGREES_COMPLEX);
    network.setXUnits(HERTZ_UNITS, GIGA_PREFIX);
    network.setNumberOfPorts(ports);
    network.setData(freq, data);

    QVERIFY(fileDir.exists());
    if (fileDir.exists(dBAngleFileName))
        QVERIFY(fileDir.remove(dBAngleFileName));

    QCOMPARE(network.format(), DB_DEGREES_COMPLEX);
    QVERIFY(FormattedTouchstone::Write(network, dBAngleFilePath));
    QVERIFY(fileDir.exists(dBAngleFileName));
    QVERIFY(QFileInfo(dBAngleFilePath).size() > 0);
}
void test_FormattedComplex::readDbAngle() {
    FormattedNetworkData network;
    QVERIFY(FormattedTouchstone::Read(network, dBAngleFilePath));

    int ports = 2;
    int points = 201;
    QCOMPARE(network.numberOfPorts(), uint(ports));
    QCOMPARE(network.points(), uint(points));
    QCOMPARE(network.format(), DB_DEGREES_COMPLEX);
    QCOMPARE(network.xUnits(), HERTZ_UNITS);
    QCOMPARE(network.xPrefix(), GIGA_PREFIX);
    QCOMPARE(network.referenceImpedance_Ohms(), 50.0);

    int val = 0;
    for (int f = 0; f < points; f++) {
        for (int i = 0; i < ports; i++) {
            for (int j = 0; j < ports; j++) {
                double a = val++;
                double b = val++;
                QVERIFY(network.y()[f][i][j] == FormattedComplex::dBAngle(a, b));
            }
        }
    }
}
void test_FormattedComplex::writeMagAngle() {
    int ports = 2;
    int points = 201;

    int val = 0;
    FormattedComplexMatrix3D data;
    data.resize(points);
    for (int f = 0; f < points; f++) {
        data[f].resize(ports);
        for (int i = 0; i < ports; i++) {
            data[f][i].resize(ports);
            for (int j = 0; j < ports; j++) {
                double a = val++;
                double b = val++;
                data[f][i][j] = FormattedComplex::magnitudeAngle(a, b);
            }
        }
    }
    QRowVector freq = linearSpacing(1.0, 2.0, points);

    FormattedNetworkData network;
    network.setParameter(S_PARAMETER);
    network.setReferenceImpedance(50);
    network.setFormat(MAGNITUDE_DEGREES_COMPLEX);
    network.setXUnits(HERTZ_UNITS, GIGA_PREFIX);
    network.setNumberOfPorts(ports);
    network.setData(freq, data);

    QVERIFY(fileDir.exists());
    if (fileDir.exists(magAngleFileName))
        QVERIFY(fileDir.remove(magAngleFileName));

    QCOMPARE(network.format(), MAGNITUDE_DEGREES_COMPLEX);
    QVERIFY(FormattedTouchstone::Write(network, magAngleFilePath));
    QVERIFY(fileDir.exists(magAngleFileName));
    QVERIFY(QFileInfo(magAngleFilePath).size() > 0);
}
void test_FormattedComplex::readMagAngle() {
    FormattedNetworkData network;
    QVERIFY(FormattedTouchstone::Read(network, magAngleFilePath));

    int ports = 2;
    int points = 201;
    QCOMPARE(network.numberOfPorts(), uint(ports));
    QCOMPARE(network.points(), uint(points));
    QCOMPARE(network.format(), MAGNITUDE_DEGREES_COMPLEX);
    QCOMPARE(network.xUnits(), HERTZ_UNITS);
    QCOMPARE(network.xPrefix(), GIGA_PREFIX);
    QCOMPARE(network.referenceImpedance_Ohms(), 50.0);

    int val = 0;
    for (int f = 0; f < points; f++) {
        for (int i = 0; i < ports; i++) {
            for (int j = 0; j < ports; j++) {
                double a = val++;
                double b = val++;
                QVERIFY(network.y()[f][i][j] == FormattedComplex::magnitudeAngle(a, b));
            }
        }
    }
}

QTEST_APPLESS_MAIN(test_FormattedComplex)
#include "test_FormattedComplex.moc"


