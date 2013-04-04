
// Rsa
#include "Definitions.h"
#include "General.h"
#include "Touchstone.h"

// Qt
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

// C++ Standard Library
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <locale>
#include <regex>
#include <algorithm>

using namespace RsaToolbox;

// Actions
bool Touchstone::Read(Network &network, QString filename) {
    QFile file(filename);
    file.open(QFile::ReadOnly);
    if (file.isReadable() == false) {
        if (file.isOpen()) file.close();
        return(false);
    }
    QTextStream snpFile(&file);
	network = Network();
	return(ReadPorts(network, filename)
		&& ReadOptions(network, snpFile)
		&& ReadData(network, snpFile));
}
bool Touchstone::Write(Network &network, QString filename) {
	if (!network.IsValid()) { return(false); }

    QFile file;
    CreateFile(file, filename, network);
    if (file.isWritable() == false) {
        if (file.isOpen()) file.close();
        return(false);
    }
    //else
    QTextStream snpFile(&file);
	WriteComments(network, snpFile);
	WriteOptions(network, snpFile);
    if (network.ports != 2)
		WriteData(network, snpFile);
	else {
		Network copyNetwork = network;
		Flip2Ports(copyNetwork);
		WriteData(copyNetwork, snpFile);
	}
    snpFile.flush();
    file.close();
	return(true);
}

// Fix 2port touchstone issue
void Touchstone::Flip2Ports(Network &network) {
    if (network.ports == 2) {
		const int PORT1 = 0;
		const int PORT2 = 1;
        for (unsigned int i = 0; i < network.points; i++) {
            std::complex<double> Port1Port2;
			Port1Port2 = network[i][PORT1][PORT2];
			network[i][PORT1][PORT2] = network[i][PORT2][PORT1];
			network[i][PORT2][PORT1] = Port1Port2;
		}
	}


}

/* READ HELPER FUNCTIONS */

// Read/parse lines
bool Touchstone::ReadLine(QTextStream &snpFile, QStringList &words) {
    if (snpFile.atEnd())
		return false;

    QString line;
    int first, last;
    line = snpFile.readLine();
	RemoveComment(line);
	while (FoundFirstChar(line, first) && FoundLastChar(line, first, last)) {
        words.append(line.mid(first, last - first + 1));
        line.remove(first, last - first + 1);
    }

    if (words.size() > 0)
        return(true);
    else
        return(ReadLine(snpFile, words));
}
void Touchstone::RemoveComment(QString &line) {
    int commentPosition = line.indexOf("!");
    if (commentPosition != -1)
        line.truncate(commentPosition);
}
bool Touchstone::FoundFirstChar(QString &line, int &first) {
    first = 0;
    while (first < line.length() && !isgraph(line.at(first).toLatin1())) {
		first++; }

    if (first == line.length())
        return(false);
    else
        return(true);
}
bool Touchstone::FoundLastChar(QString &line, int &first, int &last ) {
	last = first + 1;
    while (last < line.length() && isgraph(line.at(last).toLatin1()))
    { last++; }
	
	return(true);
}

// Read ports, options line
bool Touchstone::ReadPorts(Network &network, QString filename) {
    QRegularExpression TOUCHSTONE_REGEX(TOUCHSTONE_FILE_REGEX, QRegularExpression::CaseInsensitiveOption);
    if (TOUCHSTONE_REGEX.match(filename).hasMatch()) {
		// Read number of ports
        int dotPosition = filename.indexOf(".");
        filename.remove(0, dotPosition + 2);
        filename.chop(1);
        network.ports = filename.toInt();
        return(true);
    }
	else
		return(false);
}
bool Touchstone::ReadOptions(Network &network, QTextStream &snpFile) {
    QStringList words;
	bool isUnits, isDataType, isFormat, isImpedance;
	ReadLine(snpFile, words);
	if (words[0][0] == '#') {
        isUnits = ReadFrequencyPrefix(network, words[1]);
		isDataType = ReadDataType(network, words[2]);
		isFormat = ReadFormat(network, words[3]);
		if (words.size() == 6) { 
            network.impedance = words[5].toDouble();
			isImpedance = true; }
		else {
			isImpedance = false; }
        return (isUnits && isDataType && isFormat && isImpedance);
	}
	else { return(false); }
}
bool Touchstone::ReadFrequencyPrefix(Network &network, QString units) {
    QRegularExpression THZ_REGEX(ToString(TERA) + ToString(HERTZ), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression GHZ_REGEX(ToString(GIGA) + ToString(HERTZ), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression MHZ_REGEX(ToString(MEGA) + ToString(HERTZ), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression KHZ_REGEX(ToString(KILO) + ToString(HERTZ), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression HZ_REGEX(ToString(HERTZ), QRegularExpression::CaseInsensitiveOption);

    if (units.length() == 2 && HZ_REGEX.match(units).hasMatch()) {
        network.frequency_prefix = NO_PREFIX; return(true);
    }

	if(units.size() == 3)
	{
        if (THZ_REGEX.match(units).hasMatch()) {
            network.frequency_prefix = TERA; return(true);
        }
        if (GHZ_REGEX.match(units).hasMatch()) {
            network.frequency_prefix = GIGA; return(true);
        }
        if (MHZ_REGEX.match(units).hasMatch()) {
            network.frequency_prefix = MEGA; return(true);
        }
        if (KHZ_REGEX.match(units).hasMatch()) {
            network.frequency_prefix = KILO; return(true);
        }
	}

	// If all else fails
    return(false);
}
bool Touchstone::ReadDataType(Network &network, QString type) {
    QRegularExpression S_REGEX(ToString(S_PARAMETERS), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression Y_REGEX(ToString(Y_PARAMETERS), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression Z_REGEX(ToString(Z_PARAMETERS), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression H_REGEX(ToString(H_PARAMETERS), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression G_REGEX(ToString(G_PARAMETERS), QRegularExpression::CaseInsensitiveOption);

    if(type.size() == 1)
	{
        if (S_REGEX.match(type).hasMatch()) {
            network.type = S_PARAMETERS; return(true);
        }
        if (Y_REGEX.match(type).hasMatch()) {
            network.type = Y_PARAMETERS; return(true);
        }
        if (Z_REGEX.match(type).hasMatch()) {
            network.type = Z_PARAMETERS; return(true);
        }
        if (H_REGEX.match(type).hasMatch()) {
            network.type = H_PARAMETERS; return(true);
        }
        if (G_REGEX.match(type).hasMatch()) {
            network.type = G_PARAMETERS; return(true);
        }
    }

	// If all else fails
	return(false);
}
bool Touchstone::ReadFormat(Network &network, QString format) {
    QRegularExpression RI_REGEX(ToString(REAL_IMAGINARY), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression MA_REGEX(ToString(MAGNITUDE_DEGREES), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression DB_REGEX(ToString(DB_DEGREES), QRegularExpression::CaseInsensitiveOption);

    if(format.length() == 2)
	{
        if (RI_REGEX.match(format).hasMatch()) {
            network.format = REAL_IMAGINARY;
			ReadDatum = &ReadRI;
            return(true);
        }
        if (MA_REGEX.match(format).hasMatch()) {
            network.format = MAGNITUDE_DEGREES;
			ReadDatum = &ReadMA;
			return(true); }
        if (DB_REGEX.match(format).hasMatch()) {
            network.format = DB_DEGREES;
			ReadDatum = &ReadDB;
			return(true); }
	}

	// If all else fails
	return(false);
}

// Read data
bool Touchstone::ReadData(Network &network, QTextStream &snpFile) {
    while (!snpFile.atEnd()) {
        ComplexMatrix2D dataRow;
		double frequencyPoint;
		if (ReadRow(network, snpFile, dataRow, frequencyPoint)) {
            network.frequency.push_back(frequencyPoint);
            network.data.push_back(dataRow);
		}
	}

    if (network.data.size() > 0 && network.data.size() == network.frequency.size()) {
        network.points = network.data.size();
        if (network.ports == 2)
			Flip2Ports(network);
		return(true);
	}
	else
		return(false);
}
bool Touchstone::ReadRow(Network &network, QTextStream &snpFile, ComplexMatrix2D &dataRow, double &frequencyPoint) {
	// Begin to read data values
    double wordsToRead = pow((double)network.ports, 2) * 2 + 1;
    QStringList allWords;
    while (wordsToRead > 0 && !snpFile.atEnd()) {
        QStringList words;
		ReadLine(snpFile, words);
        wordsToRead -= words.size();
        allWords.append(words);
	}

	// Check to see if all data was read
	if (wordsToRead != 0) { return(false); }

	// Process data
    frequencyPoint = allWords[0].toDouble();
    QStringList::iterator wordIndex = allWords.begin() + 1;
    dataRow.resize(network.ports);
    for (ComplexMatrix2D::iterator rowIndex = dataRow.begin(); rowIndex != dataRow.end(); rowIndex++) {
        (*rowIndex).resize(network.ports);
        ComplexRowVector::iterator columnIndex = (*rowIndex).begin();
		for (; columnIndex != (*rowIndex).end(); columnIndex++) {
            *columnIndex = (*ReadDatum)(wordIndex->toDouble(), (wordIndex + 1)->toDouble());
			wordIndex += 2; }
	}
	return(true);
}
std::complex<double> (*Touchstone::ReadDatum)(double, double);
std::complex<double> Touchstone::ReadRI(double word1, double word2) {
    return (std::complex<double>(word1, word2));


}
std::complex<double> Touchstone::ReadMA(double word1, double word2) {
	double real = word1 * cos(word2 * PI/180);
	double imag = word1 * sin(word2 * PI/180);
    return(std::complex<double>(real, imag));
}
std::complex<double> Touchstone::ReadDB(double word1, double word2) {
    return(ReadMA(ToMagnitude(word1), word2));
}


/* WRITE HELPER FUNCTIONS */

void Touchstone::CreateFile(QFile &file, QString filename, Network &network) {
    QRegularExpression TOUCHSTONE_REGEX(TOUCHSTONE_FILE_REGEX, QRegularExpression::CaseInsensitiveOption);
    if (TOUCHSTONE_REGEX.match(filename).hasMatch()) {
        // Chop off file extension
        int dotPosition = filename.indexOf(".");
        filename.chop(filename.length() - dotPosition);
    }
    filename = filename + ".s" + QString::number(network.ports) + "p";
    file.setFileName(filename);
    file.open(QFile::WriteOnly);
}
void Touchstone::WriteComments(Network &network, QTextStream &snpFile) {
    snpFile << "! RsaToolbox (C) 2013 Rohde & Schwarz America" << endl;
	snpFile << "! " << endl;
    snpFile << "! Number of points: " << network.points << endl;
    snpFile << "! Number of ports: " << network.ports << endl;
	snpFile << "! Balanced ports?: " << network.isBalanced << endl;
	snpFile << "! " << endl << "! " << endl;


}

// Write Options + helpers
void Touchstone::WriteOptions(Network &network, QTextStream &snpFile) {
	// Write options info
	snpFile << "# ";
	snpFile << WriteUnits(network) << " ";
	snpFile << WriteDataType(network) << " ";
	snpFile << WriteFormat(network) << " ";
    snpFile << "R " << network.impedance << endl;
}
QString Touchstone::WriteUnits(Network &network) {
    switch (network.frequency_prefix) {
    case TERA:
        return(ToString(TERA) + ToString(HERTZ));
		break;
    case GIGA:
        return(ToString(GIGA) + ToString(HERTZ));
		break;
    case MEGA:
        return(ToString(MEGA) + ToString(HERTZ));
		break;
    case KILO:
        return(ToString(KILO) + ToString(HERTZ));
		break;
	default:
        return(ToString(NO_PREFIX) + ToString(HERTZ));
		break;
	}
}
QString Touchstone::WriteDataType(Network &network) {
    switch (network.type) {
    case Y_PARAMETERS:
        return(ToString(Y_PARAMETERS));
		break;
    case Z_PARAMETERS:
        return(ToString(Z_PARAMETERS));
		break;
    case H_PARAMETERS:
        return(ToString(H_PARAMETERS));
		break;
    case G_PARAMETERS:
        return(ToString(G_PARAMETERS));
		break;
	default:
        return(ToString(S_PARAMETERS));
		break;
	}
}
QString Touchstone::WriteFormat(Network &network) {
	switch (network.format) {
    case DB_DEGREES:
        return(ToString(DB_DEGREES));
		break;
    case MAGNITUDE_DEGREES:
        return(ToString(MAGNITUDE_DEGREES));
		break;
	default:
        return(ToString(REAL_IMAGINARY));
		break;
	}
}

// Write data + helpers
void Touchstone::WriteData(Network &network, QTextStream &snpFile) {
	// Choose data format
	GetWriteFormat(network);

    snpFile.setRealNumberPrecision(PRECISION);
    for (unsigned int currentFreq = 0; currentFreq < network.points; currentFreq++) {
        snpFile.setFieldAlignment(QTextStream::AlignLeft);
        snpFile.setFieldWidth(COLUMNWIDTH);
        snpFile << network.frequency[currentFreq];
        ComplexMatrix2D::iterator row_iter = network.data[currentFreq].begin();
		WriteRow(network, snpFile, *row_iter);
		row_iter++;
		for (; row_iter != network.data[currentFreq].end(); row_iter++) {
            snpFile.setFieldAlignment(QTextStream::AlignLeft);
            snpFile.setFieldWidth(COLUMNWIDTH);
            snpFile << " "; // tab past frequency column for subsequent rows
			WriteRow(network, snpFile, *row_iter);
		}
	}
}
void Touchstone::WriteRow(Network &network, QTextStream &snpFile, ComplexRowVector &row) {
	int columnsWritten = 1;
	int const COLUMNSPERLINE = 4;
    ComplexRowVector::iterator column_iter = row.begin();
	for (; column_iter != row.end(); column_iter++) {
		(*WriteDatum)(snpFile, *column_iter);
		// add delimiter
        if (columnsWritten == network.ports)
            snpFile << endl;
        else if (columnsWritten % COLUMNSPERLINE == 0) {
            snpFile << endl;
            snpFile.setFieldAlignment(QTextStream::AlignLeft);
            snpFile.setFieldWidth(COLUMNWIDTH);
            snpFile << " ";
        }
		columnsWritten++;
	}
}
void Touchstone::GetWriteFormat(Network &network) {
	switch (network.format) {
    case REAL_IMAGINARY:
		WriteDatum = &WriteRI;
		break;
    case MAGNITUDE_DEGREES:
		WriteDatum = &WriteMA;
		break;
    case DB_DEGREES:
		WriteDatum = &WriteDB;
		break;
	}
}
void (*Touchstone::WriteDatum)(QTextStream &, std::complex<double> &);
void Touchstone::WriteRI(QTextStream &snpFile, std::complex<double> &datum) {
    snpFile.setFieldAlignment(QTextStream::AlignLeft);
    snpFile.setFieldWidth(COLUMNWIDTH);
    snpFile << datum.real();
    snpFile << datum.imag();
}
void Touchstone::WriteMA(QTextStream &snpFile, std::complex<double> &datum) {
    snpFile.setFieldAlignment(QTextStream::AlignLeft);
    snpFile.setFieldWidth(COLUMNWIDTH);
    snpFile << abs(datum);
    snpFile << arg(datum) * 180 / PI;
}
void Touchstone::WriteDB(QTextStream &snpFile, std::complex<double> &datum) {
    snpFile.setFieldAlignment(QTextStream::AlignLeft);
    snpFile.setFieldWidth(COLUMNWIDTH);
    snpFile << ToDb(datum);
    snpFile << arg(datum) * 180 / PI;
}
