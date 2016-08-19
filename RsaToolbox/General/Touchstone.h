#ifndef TOUCHSTONE_H
#define TOUCHSTONE_H


// RsaToolbox
#include "Definitions.h"
#include "NetworkData.h"

// Qt
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>

// C++ std lib
#include <complex>
#include <vector>


// ToDo: Rewrite Touchstone/NetworkData to
// not rely on NetworkData::setNumberOfPorts().
// This is bad form: Should be derived from setData();

namespace RsaToolbox
{

class Touchstone {
public:
    // Actions
    static uint ports(QString fileName);
    static bool read(NetworkData &network, QTextStream &stream, int ports);
    static bool read(NetworkData &network, QString filename);
    static bool write(NetworkData &network, QTextStream &stream);
    static bool write(NetworkData &network, QString filename);


private:
    static const QString TOUCHSTONE_FILE_REGEX;
    static const int COLUMNWIDTH;
    static const int PRECISION;

    // Fix 2-port arrangement anomaly
    static void flip2Ports(NetworkData &network);

    /* READ HELPER FUNCTIONS */

    // Read Ports and Options line
    static bool readPorts(NetworkData &network, QString filename);
    static bool readOptions(NetworkData &network, QTextStream &stream);
    static bool readFrequencyPrefix(NetworkData &network, QString units);
    static bool readDataType(NetworkData &network, QString dataType);
    static bool readFormat(QString format);

    // Read data
    static bool readData(NetworkData &network, QTextStream &stream);
    static bool readRow(NetworkData &network, QTextStream &stream, ComplexMatrix2D &dataRow, double &frequencyPoint);
    static ComplexDouble (*readDatum)(double, double);
    static ComplexDouble readRI(double word1, double word2);
    static ComplexDouble readMA(double word1, double word2);
    static ComplexDouble readDB(double word1, double word2);

    // Functions to help read a line, ignore comments and parse line into whitespace-delimited words
    static bool readLine(QTextStream &stream, QStringList &words);
    static void removeComment(QString &line);

    /* WRITE HELPER FUNCTIONS */

    // Create file to be written
    static void createFile(QFile &file, QString filename, NetworkData &network);

    // Write comments and options line
    static void writeComments(NetworkData &network, QTextStream &stream);
    static void writeOptions(NetworkData &network, QTextStream &stream);
    static QString writeUnits(NetworkData &network);
    static QString writeDataType(NetworkData &network);
    static QString writeFormat(NetworkData &network);

    // Write data
    static void writeData(NetworkData &network, QTextStream &stream);
    static void write2PortData(NetworkData &network, QTextStream &stream);
    static void writeRow(QTextStream &stream, ComplexRowVector &row);
    static void getWriteFormat(NetworkData &network);
    static void (*writeDatum)(QTextStream &, ComplexDouble &);
    static void writeRI(QTextStream &stream, ComplexDouble &datum);
    static void writeMA(QTextStream &stream, ComplexDouble &datum);
    static void writeDB(QTextStream &stream, ComplexDouble &datum);
};
}


#endif



