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


namespace RsaToolbox
{

class Touchstone {
public:
    // Actions
    static uint ports(QString fileName);
    static bool Read(NetworkData &network, QTextStream &touchstone_in, int ports);
    static bool Read(NetworkData &network, QString filename);
    static bool Write(NetworkData &network, QTextStream &touchstone_out);
    static bool Write(NetworkData &network, QString filename);


private:
    static const QString TOUCHSTONE_FILE_REGEX;
    static const int COLUMNWIDTH;
    static const int PRECISION;

    // Fix 2-port arrangement anomaly
    static void Flip2Ports(NetworkData &network);

    /* READ HELPER FUNCTIONS */

    // Read Ports and Options line
    static bool ReadPorts(NetworkData &network, QString filename);
    static bool ReadOptions(NetworkData &network, QTextStream &snpFile);
    static bool ReadFrequencyPrefix(NetworkData &network, QString units);
    static bool ReadDataType(NetworkData &network, QString dataType);
    static bool ReadFormat(NetworkData &network, QString format);

    // Read data
    static bool ReadData(NetworkData &network, QTextStream &snpFile);
    static bool ReadRow(NetworkData &network, QTextStream &snpFile, ComplexMatrix2D &dataRow, double &frequencyPoint);
    static std::complex<double> (*ReadDatum)(double, double);
    static std::complex<double> ReadRI(double word1, double word2);
    static std::complex<double> ReadMA(double word1, double word2);
    static std::complex<double> ReadDB(double word1, double word2);

    // Functions to help read a line, ignore comments and parse line into whitespace-delimited words
    static bool ReadLine(QTextStream &snpFile, QStringList &words);
    static void RemoveComment(QString &line);

    /* WRITE HELPER FUNCTIONS */

    // Create file to be written
    static void CreateFile(QFile &file, QString filename, NetworkData &network);

    // Write comments and options line
    static void WriteComments(NetworkData &network, QTextStream &snpFile);
    static void WriteOptions(NetworkData &network, QTextStream &snpFile);
    static QString WriteUnits(NetworkData &network);
    static QString WriteDataType(NetworkData &network);
    static QString WriteFormat(NetworkData &network);

    // Write data
    static void WriteData(NetworkData &network, QTextStream &snpFile);
    static void WriteRow(NetworkData &network, QTextStream &snpFile, ComplexRowVector &row);
    static void GetWriteFormat(NetworkData &network);
    static void (*WriteDatum)(QTextStream &, std::complex<double> &);
    static void WriteRI(QTextStream &snpFile, std::complex<double> &datum);
    static void WriteMA(QTextStream &snpFile, std::complex<double> &datum);
    static void WriteDB(QTextStream &snpFile, std::complex<double> &datum);
};
}


#endif



