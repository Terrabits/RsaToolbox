#ifndef FORMATTED_TOUCHSTONE_H
#define FORMATTED_TOUCHSTONE_H


// RsaToolbox
#include "Definitions.h"
#include "FormattedComplex.h"
#include "FormattedNetworkData.h"

// Qt
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>

// C++ std lib
#include <complex>
#include <vector>


// ToDo: Rewrite FormattedTouchstone/FormattedNetworkData to
// not rely on FormattedNetworkData::setNumberOfPorts().
// This is bad form: Should be derived from setData();

namespace RsaToolbox
{

class FormattedTouchstone {
public:
    // Actions
    static uint ports(QString fileName);
    static bool Read(FormattedNetworkData &network, QTextStream &FormattedTouchstone_in, int ports);
    static bool Read(FormattedNetworkData &network, QString filename);
    static bool Write(FormattedNetworkData &network, QTextStream &FormattedTouchstone_out);
    static bool Write(FormattedNetworkData &network, QString filename);

private:
    static const QString FormattedTouchstone_FILE_REGEX;
    static const int COLUMNWIDTH;
    static const int PRECISION;

    // Fix 2-port arrangement anomaly
    static void Flip2Ports(FormattedNetworkData &network);

    /* READ HELPER FUNCTIONS */

    // Read Ports and Options line
    static bool ReadPorts(FormattedNetworkData &network, QString filename);
    static bool ReadOptions(FormattedNetworkData &network, QTextStream &snpFile);
    static bool ReadFrequencyPrefix(FormattedNetworkData &network, QString units);
    static bool ReadDataType(FormattedNetworkData &network, QString dataType);
    static bool ReadFormat(FormattedNetworkData &network, QString format);

    // Read data
    static bool ReadData(FormattedNetworkData &network, QTextStream &snpFile);
    static bool ReadRow(FormattedNetworkData &network, QTextStream &snpFile, FormattedComplexMatrix2D &dataRow, double &frequencyPoint);
    static FormattedComplex (*ReadDatum)(double, double);
    static FormattedComplex ReadRI(double word1, double word2);
    static FormattedComplex ReadMA(double word1, double word2);
    static FormattedComplex ReadDB(double word1, double word2);

    // Functions to help read a line, ignore comments and parse line into whitespace-delimited words
    static bool ReadLine(QTextStream &snpFile, QStringList &words);
    static void RemoveComment(QString &line);

    /* WRITE HELPER FUNCTIONS */

    // Create file to be written
    static void CreateFile(QFile &file, QString filename, FormattedNetworkData &network);

    // Write comments and options line
    static void WriteComments(FormattedNetworkData &network, QTextStream &snpFile);
    static void WriteOptions(FormattedNetworkData &network, QTextStream &snpFile);
    static QString WriteUnits(FormattedNetworkData &network);
    static QString WriteDataType(FormattedNetworkData &network);
    static QString WriteFormat(FormattedNetworkData &network);

    // Write data
    static void WriteData(FormattedNetworkData &network, QTextStream &snpFile);
    static void WriteRow(FormattedNetworkData &network, QTextStream &snpFile, FormattedComplexRowVector &row);
    static void GetWriteFormat(FormattedNetworkData &network);
    static void (*WriteDatum)(QTextStream &, FormattedComplex &);
    static void WriteRI(QTextStream &snpFile, FormattedComplex &datum);
    static void WriteMA(QTextStream &snpFile, FormattedComplex &datum);
    static void WriteDB(QTextStream &snpFile, FormattedComplex &datum);
};
}


#endif // FORMATTED_TOUCHSTONE_H



