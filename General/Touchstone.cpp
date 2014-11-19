

// Rsa
#include "Definitions.h"
#include "General.h"
#include "Touchstone.h"
using namespace RsaToolbox;

// Qt
#include <QRegularExpression>
#include <QDebug>

// C++ std lib
#include <iterator>
#include <cmath>


// Actions
uint Touchstone::ports(QString fileName) {
    QRegularExpression TOUCHSTONE_REGEX(TOUCHSTONE_FILE_REGEX, QRegularExpression::CaseInsensitiveOption);
    if (!TOUCHSTONE_REGEX.match(fileName).hasMatch())
        return 0;

    // Read number of ports
    int dotPosition = fileName.lastIndexOf(".");
    fileName.remove(0, dotPosition + 2);
    fileName.chop(1);
    return(fileName.toUInt());
}
bool Touchstone::Read(NetworkData &network, QString filename) {
    QFile file(filename);
    if (!file.open(QFile::ReadOnly))
        return false;
    QTextStream snpFile(&file);
    network = NetworkData();
    if (!ReadPorts(network, filename)) {
        return false;
    }
    if (!ReadOptions(network, snpFile)) {
        return false;
    }
    if (!ReadData(network, snpFile)) {
        return false;
    }
    // Else
    return true;
}
bool Touchstone::Read(NetworkData &network, QTextStream &touchstone_in, int ports) {
    if (ports < 1)
        return(false);

    network = NetworkData();
    return(ReadOptions(network, touchstone_in)
            && ReadData(network, touchstone_in));
}
bool Touchstone::Write(NetworkData &network, QString filename) {
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
    if (network.numberOfPorts() != 2)
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
bool Touchstone::Write(NetworkData &network, QTextStream &touchstone_out) {
    WriteComments(network, touchstone_out);
    WriteOptions(network, touchstone_out);
    if (network.numberOfPorts() != 2)
        WriteData(network, touchstone_out);
    else {
        NetworkData copyNetwork = network;
        Flip2Ports(copyNetwork);
        WriteData(copyNetwork, touchstone_out);
    }
    touchstone_out.flush();
    return(true);
}

// Private

const QString Touchstone::TOUCHSTONE_FILE_REGEX = "^.*\\.s0*[1-9][0-9]*p$";
const int Touchstone::COLUMNWIDTH = 18;
const int Touchstone::PRECISION = 10;

// Fix 2port touchstone issue
void Touchstone::Flip2Ports(NetworkData &network) {
    if (network.numberOfPorts() == 2) {
        const int PORT1 = 0;
        const int PORT2 = 1;
        for (unsigned int i = 0; i < network.points(); i++) {
            ComplexDouble Port1Port2;
            Port1Port2 = network.y()[i][PORT1][PORT2];
            network.y()[i][PORT1][PORT2] = network.y()[i][PORT2][PORT1];
            network.y()[i][PORT2][PORT1] = Port1Port2;
        }
    }
}

/* READ HELPER FUNCTIONS */

// Read/parse lines
bool Touchstone::ReadLine(QTextStream &snpFile, QStringList &words) {
    if (snpFile.atEnd())
        return false;

    QString line;
    line = snpFile.readLine();
    RemoveComment(line);
    words = line.split(QRegularExpression("\\s+"), QString::SkipEmptyParts);
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

// Read ports, options line
bool Touchstone::ReadPorts(NetworkData &network, QString filename) {
    network.setNumberOfPorts(ports(filename));
    return network.numberOfPorts() != 0;
}
bool Touchstone::ReadOptions(NetworkData &network, QTextStream &snpFile) {
    QStringList words;
    ReadLine(snpFile, words);
    if (words[0] != "#")
        return false;
    if (!ReadFrequencyPrefix(network, words[1])) {
        return false;
    }
    if (!ReadDataType(network, words[2])) {
        return false;
    }
    if (!ReadFormat(words[3])) {
        return false;
    }
    if (words.size() == 6)
         network.setReferenceImpedance(words.last().toDouble());
    // Else
    return true;
}
bool Touchstone::ReadFrequencyPrefix(NetworkData &network, QString units) {
    if (!units.contains("Hz", Qt::CaseInsensitive))
        return false;

    units.chop(2);
    network.setXUnits(Units::Hertz, toSiPrefix(units));
    return(true);
}
bool Touchstone::ReadDataType(NetworkData &network, QString type) {
    QRegularExpression S_REGEX(toString(NetworkParameter::S), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression Y_REGEX(toString(NetworkParameter::Y), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression Z_REGEX(toString(NetworkParameter::Z), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression H_REGEX(toString(NetworkParameter::H), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression G_REGEX(toString(NetworkParameter::G), QRegularExpression::CaseInsensitiveOption);

    if(type.size() == 1)
    {
        if (S_REGEX.match(type).hasMatch()) {
            network.setParameter(NetworkParameter::S);
            return(true);
        }
        if (Y_REGEX.match(type).hasMatch()) {
            network.setParameter(NetworkParameter::Y);
            return(true);
        }
        if (Z_REGEX.match(type).hasMatch()) {
            network.setParameter(NetworkParameter::Z);
            return(true);
        }
        if (H_REGEX.match(type).hasMatch()) {
            network.setParameter(NetworkParameter::H);
            return(true);
        }
        if (G_REGEX.match(type).hasMatch()) {
            network.setParameter(NetworkParameter::G);
            return(true);
        }
    }

    // If all else fails
    return(false);
}
bool Touchstone::ReadFormat(QString format) {
    QRegularExpression RI_REGEX(toString(ComplexFormat::RealImaginary), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression MA_REGEX(toString(ComplexFormat::MagnitudeDegrees), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression DB_REGEX(toString(ComplexFormat::DecibelDegrees), QRegularExpression::CaseInsensitiveOption);

    if(format.length() != 2)
        return false;
    if (RI_REGEX.match(format).hasMatch()) {
        ReadDatum = &ReadRI;
        return(true);
    }
    if (MA_REGEX.match(format).hasMatch()) {
        ReadDatum = &ReadMA;
        return(true);
    }
    if (DB_REGEX.match(format).hasMatch()) {
        ReadDatum = &ReadDB;
        return(true);
    }
    // Else
    return false;
}

// Read data
bool Touchstone::ReadData(NetworkData &network, QTextStream &snpFile) {
    QRowVector freqs;
    ComplexMatrix3D data;
    while (!snpFile.atEnd()) {
        ComplexMatrix2D row;
        double freq;
        if (ReadRow(network, snpFile, row, freq)) {
            freqs << freq;
            data.push_back(row);
        }
    }

    uint ports = network.numberOfPorts();
    network.setData(freqs, data);
    if (network.numberOfPorts() != ports || network.points() == 0)
    return false;
    if (network.numberOfPorts() == 2)
        Flip2Ports(network);
    return(true);
}
bool Touchstone::ReadRow(NetworkData &network, QTextStream &snpFile, ComplexMatrix2D &dataRow, double &frequencyPoint) {
    // Begin to read data values
    double wordsToRead = pow(double(network.numberOfPorts()), 2) * 2 + 1;
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
    dataRow.resize(network.numberOfPorts());
    for (ComplexMatrix2D::iterator rowIndex = dataRow.begin(); rowIndex != dataRow.end(); rowIndex++) {
        (*rowIndex).resize(network.numberOfPorts());
        ComplexRowVector::iterator columnIndex = (*rowIndex).begin();
        for (; columnIndex != (*rowIndex).end(); columnIndex++) {
            *columnIndex = (*ReadDatum)(wordIndex->toDouble(), (wordIndex + 1)->toDouble());
            wordIndex += 2;
        }
    }
    return(true);
}
ComplexDouble (*Touchstone::ReadDatum)(double, double);
ComplexDouble Touchstone::ReadRI(double word1, double word2) {
    return (ComplexDouble(word1, word2));


}
ComplexDouble Touchstone::ReadMA(double word1, double word2) {
    double real = word1 * cos(word2 * PI/180);
    double imag = word1 * sin(word2 * PI/180);
    return(ComplexDouble(real, imag));
}
ComplexDouble Touchstone::ReadDB(double word1, double word2) {
    return(ReadMA(toMagnitude(word1), word2));
}


/* WRITE HELPER FUNCTIONS */

void Touchstone::CreateFile(QFile &file, QString filename, NetworkData &network) {
    QRegularExpression TOUCHSTONE_REGEX(TOUCHSTONE_FILE_REGEX, QRegularExpression::CaseInsensitiveOption);
    if (TOUCHSTONE_REGEX.match(filename).hasMatch()) {
        // Chop off file extension
        int dotPosition = filename.lastIndexOf(".");
        filename.truncate(dotPosition);
    }
    filename = filename + ".s" + QString::number(network.numberOfPorts()) + "p";
    file.setFileName(filename);
    file.open(QFile::WriteOnly);
}
void Touchstone::WriteComments(NetworkData &network, QTextStream &snpFile) {
    snpFile << "! RsaToolbox (C) 2014 Rohde & Schwarz America" << endl;
    snpFile << "! " << endl;
    snpFile << "! Number of points: " << network.points() << endl;
    snpFile << "! Number of ports: " << network.numberOfPorts() << endl;
    snpFile << "! Balanced ports?: " << "No" << endl;
    snpFile << "! " << endl << "! " << endl;
}

// Write Options + helpers
void Touchstone::WriteOptions(NetworkData &network, QTextStream &snpFile) {
    // Write options info
    snpFile << "# ";
    snpFile << WriteUnits(network) << " ";
    snpFile << WriteDataType(network) << " ";
    snpFile << WriteFormat(network) << " ";
    // snpFile << "R " << network.impedance << endl;
    snpFile << "R " << 50 << endl;
}
QString Touchstone::WriteUnits(NetworkData &network) {
    return(toString(network.xPrefix(), network.xUnits()));
}
QString Touchstone::WriteDataType(NetworkData &network) {
    return(toString(network.parameter()));
}
QString Touchstone::WriteFormat(NetworkData &network) {
    Q_UNUSED(network);
    return(toString(ComplexFormat::RealImaginary));
}

// Write data + helpers
void Touchstone::WriteData(NetworkData &network, QTextStream &snpFile) {
    // Choose data format
    GetWriteFormat(network);

    snpFile.setRealNumberPrecision(PRECISION);
    for (uint currentFreq = 0; currentFreq < network.points(); currentFreq++) {
        snpFile.setFieldAlignment(QTextStream::AlignLeft);
        snpFile.setFieldWidth(COLUMNWIDTH);
        snpFile << network.x()[currentFreq];
        ComplexMatrix2D::iterator row_iter = network.y()[currentFreq].begin();
        WriteRow(network, snpFile, *row_iter);
        row_iter++;
        for (; row_iter != network.y()[currentFreq].end(); row_iter++) {
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
        if (columnsWritten == network.numberOfPorts()) {
            snpFile.setFieldWidth(0);
            snpFile << endl;
            snpFile.setFieldWidth(COLUMNWIDTH);
        }
        else if (columnsWritten % COLUMNSPERLINE == 0) {
            snpFile.setFieldWidth(0);
            snpFile << endl;
            snpFile.setFieldAlignment(QTextStream::AlignLeft);
            snpFile.setFieldWidth(COLUMNWIDTH);
            snpFile << " ";
        }
        columnsWritten++;
    }
}
void Touchstone::GetWriteFormat(NetworkData &network) {
    Q_UNUSED(network);
    WriteDatum = &WriteRI;
    //    switch (network.format) {
    //    case REAL_IMAGINARY_COMPLEX:
    //        WriteDatum = &WriteRI;
    //        break;
    //    case MAGNITUDE_DEGREES_COMPLEX:
    //        WriteDatum = &WriteMA;
    //        break;
    //    case DB_DEGREES_COMPLEX:
    //        WriteDatum = &WriteDB;
    //        break;
    //    }
}
void (*Touchstone::WriteDatum)(QTextStream &, ComplexDouble &);
void Touchstone::WriteRI(QTextStream &snpFile, ComplexDouble &datum) {
    snpFile.setFieldAlignment(QTextStream::AlignLeft);
    snpFile.setFieldWidth(COLUMNWIDTH);
    snpFile << datum.real();
    snpFile << datum.imag();
}
void Touchstone::WriteMA(QTextStream &snpFile, ComplexDouble &datum) {
    snpFile.setFieldAlignment(QTextStream::AlignLeft);
    snpFile.setFieldWidth(COLUMNWIDTH);
    snpFile << abs(datum);
    snpFile << arg(datum) * 180 / PI;
}
void Touchstone::WriteDB(QTextStream &snpFile, ComplexDouble &datum) {
    snpFile.setFieldAlignment(QTextStream::AlignLeft);
    snpFile.setFieldWidth(COLUMNWIDTH);
    snpFile << toDb(datum);
    snpFile << arg(datum) * 180 / PI;
}



