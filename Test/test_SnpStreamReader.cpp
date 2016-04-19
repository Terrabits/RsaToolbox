

#include "SnpStreamReader.h"
using namespace RsaToolbox;

#include <QDebug>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QScopedPointer>

class test_SnpStreamReader : public QObject
{
    Q_OBJECT

public:
    test_SnpStreamReader();

private:
    QString snpFile;
    QScopedPointer<SnpStreamReader> reader;


private Q_SLOTS:
    void init();
    void cleanup();

    void open();
};

test_SnpStreamReader::test_SnpStreamReader() {
    snpFile = "../RsaToolboxTest/Files/SnpStreamReader/50 MHz to 8.5 GHz - 170 points.s24p";
}

void test_SnpStreamReader::init() {
    QVERIFY(reader->open());
}
void test_SnpStreamReader::cleanup() {
    reader->close();
    reader.reset(new SnpStreamReader(snpFile));
}

void test_SnpStreamReader::open() {
    
    // Tests here
    
}
void test_SnpStreamReader::openSuccess() {

    // Tests here



}


QTEST_APPLESS_MAIN(test_SnpStreamReader)
#include "test_SnpStreamReader.moc"


