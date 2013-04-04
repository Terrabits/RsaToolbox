#ifndef TOUCHSTONE_H
#define TOUCHSTONE_H

// Rsa
#include "Network.h"

// Qt
#include <QString>
#include <QFile>
#include <QTextStream>

// C++ std lib
#include <string>
#include <complex>
#include <vector>
#include <iterator>


namespace RsaToolbox
{
    QString const TOUCHSTONE_FILE_REGEX = "^.*\\.s[0-9][0-9]*p$";
	int const COLUMNWIDTH = 18;
	int const PRECISION = 10;

	class Touchstone {
	public:
		// Actions
        static bool Read(Network &network, QString filename);
        static bool Write(Network &network, QString filename);
        static QString WriteUnits(Network &network);
        static QString WriteDataType(Network &network);
        static QString WriteFormat(Network &network);

	private:
		// Fix 2-port arrangement anomaly
		static void Flip2Ports(Network &network);

		/* READ HELPER FUNCTIONS */

		// Read Ports and Options line
        static bool ReadPorts(Network &network, QString filename);
        static bool ReadOptions(Network &network, QTextStream &snpFile);
        static bool ReadFrequencyPrefix(Network &network, QString units);
        static bool ReadDataType(Network &network, QString dataType);
        static bool ReadFormat(Network &network, QString format);

		// Read data
        static bool ReadData(Network &network, QTextStream &snpFile);
        static bool ReadRow(Network &network, QTextStream &snpFile, ComplexMatrix2D &dataRow, double &frequencyPoint);
		static std::complex<double> (*ReadDatum)(double, double);
		static std::complex<double> ReadRI(double word1, double word2);
		static std::complex<double> ReadMA(double word1, double word2);
		static std::complex<double> ReadDB(double word1, double word2);

		// Functions to help read a line, ignore comments and parse line into whitespace-delimited words
        static bool ReadLine(QTextStream &snpFile, QStringList &words);
        static bool FoundFirstChar(QString &line, int &first);
        static bool FoundLastChar(QString &line, int &first, int &last);
        static void RemoveComment(QString &line);

		/* WRITE HELPER FUNCTIONS */

		// Create file to be written
        static void CreateFile(QFile &file, QString filename, Network &network);

		// Write comments and options line
        static void WriteComments(Network &network, QTextStream &snpFile);
        static void WriteOptions(Network &network, QTextStream &snpFile);

		// Write data
        static void WriteData(Network &network, QTextStream &snpFile);
        static void WriteRow(Network &network, QTextStream &snpFile, ComplexRowVector &row);
		static void GetWriteFormat(Network &network);
        static void (*WriteDatum)(QTextStream &, std::complex<double> &);
        static void WriteRI(QTextStream &snpFile, std::complex<double> &datum);
        static void WriteMA(QTextStream &snpFile, std::complex<double> &datum);
        static void WriteDB(QTextStream &snpFile, std::complex<double> &datum);
	};
}


#endif
