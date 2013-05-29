

// Rsa
#include "General.h"
#include "Touchstone.h"

// Qt
#include <QRegularExpression>

// C++ std lib
#include <iterator>
#include <cmath>

using namespace RsaToolbox;


// Actions
bool Touchstone::Read(NetworkData &network, QString filename) {
    QFile file(filename);
    file.open(QFile::ReadOnly);
    if (file.isReadable() == false) {
        if (file.isOpen()) file.close();
        return(false);
    }
    QTextStream snpFile(&file);
    network = NetworkData();
    return(ReadPorts(network, filename)
           && ReadOptions(network, snpFile)
           && ReadData(network, snpFile));
}
bool Touchstone::Write(NetworkData &network, QString filename) {
    if (!network.isValid()) { return(false); }

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
        NetworkData copyNetwork = network;
        Flip2Ports(copyNetwork);
        WriteData(copyNetwork, snpFile);
    }
    snpFile.flush();
    file.close();
    return(true);
}


// Private

const QString Touchstone::TOUCHSTONE_FILE_REGEX = "^.*\\.s[0-9][0-9]*p$";
const int Touchstone::COLUMNWIDTH = 18;
const int Touchstone::PRECISION = 10;

// Fix 2port touchstone issue
void Touchstone::Flip2Ports(NetworkData &network) {
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
bool Touchstone::ReadPorts(NetworkData &network, QString filename) {
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
bool Touchstone::ReadOptions(NetworkData &network, QTextStream &snpFile) {
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
bool Touchstone::ReadFrequencyPrefix(NetworkData &network, QString units) {
    QRegularExpression THZ_REGEX(ToString(TERA_PREFIX) + ToString(HERTZ_UNITS), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression GHZ_REGEX(ToString(GIGA_PREFIX) + ToString(HERTZ_UNITS), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression MHZ_REGEX(ToString(MEGA_PREFIX) + ToString(HERTZ_UNITS), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression KHZ_REGEX(ToString(KILO_PREFIX) + ToString(HERTZ_UNITS), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression HZ_REGEX(ToString(HERTZ_UNITS), QRegularExpression::CaseInsensitiveOption);

    if (units.length() == 2 && HZ_REGEX.match(units).hasMatch()) {
        network.frequency_prefix = NO_PREFIX; return(true);
    }

    if(units.size() == 3)
    {
        if (THZ_REGEX.match(units).hasMatch()) {
            network.frequency_prefix = TERA_PREFIX; return(true);
        }
        if (GHZ_REGEX.match(units).hasMatch()) {
            network.frequency_prefix = GIGA_PREFIX; return(true);
        }
        if (MHZ_REGEX.match(units).hasMatch()) {
            network.frequency_prefix = MEGA_PREFIX; return(true);
        }
        if (KHZ_REGEX.match(units).hasMatch()) {
            network.frequency_prefix = KILO_PREFIX; return(true);
        }
    }

    // If all else fails
    return(false);
}
bool Touchstone::ReadDataType(NetworkData &network, QString type) {
    QRegularExpression S_REGEX(ToString(S_PARAMETER), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression Y_REGEX(ToString(Y_PARAMETER), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression Z_REGEX(ToString(Z_PARAMETER), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression H_REGEX(ToString(H_PARAMETER), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression G_REGEX(ToString(G_PARAMETER), QRegularExpression::CaseInsensitiveOption);

    if(type.size() == 1)
    {
        if (S_REGEX.match(type).hasMatch()) {
            network.network_parameter = S_PARAMETER; return(true);
        }
        if (Y_REGEX.match(type).hasMatch()) {
            network.network_parameter = Y_PARAMETER; return(true);
        }
        if (Z_REGEX.match(type).hasMatch()) {
            network.network_parameter = Z_PARAMETER; return(true);
        }
        if (H_REGEX.match(type).hasMatch()) {
            network.network_parameter = H_PARAMETER; return(true);
        }
        if (G_REGEX.match(type).hasMatch()) {
            network.network_parameter = G_PARAMETER; return(true);
        }
    }

    // If all else fails
    return(false);
}
bool Touchstone::ReadFormat(NetworkData &network, QString format) {
    QRegularExpression RI_REGEX(ToString(REAL_IMAGINARY_COMPLEX), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression MA_REGEX(ToString(MAGNITUDE_DEGREES_COMPLEX), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression DB_REGEX(ToString(DB_DEGREES_COMPLEX), QRegularExpression::CaseInsensitiveOption);

    if(format.length() == 2)
    {
        if (RI_REGEX.match(format).hasMatch()) {
            network.format = REAL_IMAGINARY_COMPLEX;
            ReadDatum = &ReadRI;
            return(true);
        }
        if (MA_REGEX.match(format).hasMatch()) {
            network.format = MAGNITUDE_DEGREES_COMPLEX;
            ReadDatum = &ReadMA;
            return(true); }
        if (DB_REGEX.match(format).hasMatch()) {
            network.format = DB_DEGREES_COMPLEX;
            ReadDatum = &ReadDB;
            return(true); }
    }

    // If all else fails
    return(false);
}

// Read data
bool Touchstone::ReadData(NetworkData &network, QTextStream &snpFile) {
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
bool Touchstone::ReadRow(NetworkData &network, QTextStream &snpFile, ComplexMatrix2D &dataRow, double &frequencyPoint) {
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

void Touchstone::CreateFile(QFile &file, QString filename, NetworkData &network) {
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
void Touchstone::WriteComments(NetworkData &network, QTextStream &snpFile) {
    snpFile << "! RsaToolbox (C) 2013 Rohde & Schwarz America" << endl;
    snpFile << "! " << endl;
    snpFile << "! Number of points: " << network.points << endl;
    snpFile << "! Number of ports: " << network.ports << endl;
    snpFile << "! Balanced ports?: " << network.isBalanced << endl;
    snpFile << "! " << endl << "! " << endl;


}

// Write Options + helpers
void Touchstone::WriteOptions(NetworkData &network, QTextStream &snpFile) {
    // Write options info
    snpFile << "# ";
    snpFile << WriteUnits(network) << " ";
    snpFile << WriteDataType(network) << " ";
    snpFile << WriteFormat(network) << " ";
    snpFile << "R " << network.impedance << endl;
}
QString Touchstone::WriteUnits(NetworkData &network) {
    switch (network.frequency_prefix) {
    case TERA_PREFIX:
        return(ToString(TERA_PREFIX) + ToString(HERTZ_UNITS));
        break;
    case GIGA_PREFIX:
        return(ToString(GIGA_PREFIX) + ToString(HERTZ_UNITS));
        break;
    case MEGA_PREFIX:
        return(ToString(MEGA_PREFIX) + ToString(HERTZ_UNITS));
        break;
    case KILO_PREFIX:
        return(ToString(KILO_PREFIX) + ToString(HERTZ_UNITS));
        break;
    default:
        return(ToString(NO_PREFIX) + ToString(HERTZ_UNITS));
        break;
    }
}
QString Touchstone::WriteDataType(NetworkData &network) {
    switch (network.network_parameter) {
    case Y_PARAMETER:
        return(ToString(Y_PARAMETER));
        break;
    case Z_PARAMETER:
        return(ToString(Z_PARAMETER));
        break;
    case H_PARAMETER:
        return(ToString(H_PARAMETER));
        break;
    case G_PARAMETER:
        return(ToString(G_PARAMETER));
        break;
    default:
        return(ToString(S_PARAMETER));
        break;
    }
}
QString Touchstone::WriteFormat(NetworkData &network) {
    switch (network.format) {
    case DB_DEGREES_COMPLEX:
        return(ToString(DB_DEGREES_COMPLEX));
        break;
    case MAGNITUDE_DEGREES_COMPLEX:
        return(ToString(MAGNITUDE_DEGREES_COMPLEX));
        break;
    default:
        return(ToString(REAL_IMAGINARY_COMPLEX));
        break;
    }
}

// Write data + helpers
void Touchstone::WriteData(NetworkData &network, QTextStream &snpFile) {
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
void Touchstone::WriteRow(NetworkData &network, QTextStream &snpFile, ComplexRowVector &row) {
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
void Touchstone::GetWriteFormat(NetworkData &network) {
    switch (network.format) {
    case REAL_IMAGINARY_COMPLEX:
        WriteDatum = &WriteRI;
        break;
    case MAGNITUDE_DEGREES_COMPLEX:
        WriteDatum = &WriteMA;
        break;
    case DB_DEGREES_COMPLEX:
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
