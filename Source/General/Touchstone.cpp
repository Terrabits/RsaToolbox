

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
    return fileName.toUInt();
}
bool Touchstone::read(NetworkData &network, QString filename) {
    QFile file(filename);
    if (!file.open(QFile::ReadOnly))
        return false;
    QTextStream stream(&file);
    network = NetworkData();
    if (!readPorts(network, filename)) {
        return false;
    }
    if (!readOptions(network, stream)) {
        return false;
    }
    if (!readData(network, stream)) {
        return false;
    }
    // Else
    return true;
}
bool Touchstone::read(NetworkData &network, QTextStream &stream, int ports) {
    if (ports < 1)
        return false;

    network = NetworkData();
    return readOptions(network, stream) && readData(network, stream);
}
bool Touchstone::write(NetworkData &network, QString filename) {
    QFile file;
    createFile(file, filename, network);
    if (!file.isWritable()) {
        if (file.isOpen())
            file.close();
        return false;
    }
    //else
    QTextStream stream(&file);
    if (write(network, stream)) {
        stream.flush();
        file.close();
        return true;
    }
    else {
        file.close();
        QFileInfo info(filename);
        if (info.exists()) {
            info.dir().remove(info.fileName());
        }
        return false;
    }
}
bool Touchstone::write(NetworkData &network, QTextStream &stream) {
    writeComments(network, stream);
    writeOptions(network, stream);
    if (network.ports() == 2) {
        NetworkData copyNetwork = network;
        flip2Ports(copyNetwork);
        write2PortData(copyNetwork, stream);
    }
    else {
        writeData(network, stream);
    }

    return true;
}

// Private

const QString Touchstone::TOUCHSTONE_FILE_REGEX = "^.*\\.s0*[1-9][0-9]*p$";
const int Touchstone::COLUMNWIDTH = 18;
const int Touchstone::PRECISION = 10;

// Fix 2port touchstone issue
void Touchstone::flip2Ports(NetworkData &network) {
    if (network.ports() != 2)
        return;

    const int PORT1 = 0;
    const int PORT2 = 1;
    for (unsigned int i = 0; i < network.points(); i++) {
        ComplexDouble Port1Port2;
        Port1Port2 = network.y()[i][PORT1][PORT2];
        network.y()[i][PORT1][PORT2] = network.y()[i][PORT2][PORT1];
        network.y()[i][PORT2][PORT1] = Port1Port2;
    }
}

/* READ HELPER FUNCTIONS */

// Read/parse lines
bool Touchstone::readLine(QTextStream &stream, QStringList &words) {
    if (stream.atEnd())
        return false;

    QString line;
    line = stream.readLine();
    removeComment(line);
    words = line.split(QRegularExpression("\\s+"), QString::SkipEmptyParts);
    if (words.size() > 0)
        return true;
    else
        return readLine(stream, words);
}
void Touchstone::removeComment(QString &line) {
    int commentPosition = line.indexOf("!");
    if (commentPosition != -1)
        line.truncate(commentPosition);
}

// Read ports, options line
bool Touchstone::readPorts(NetworkData &network, QString filename) {
    network.setPorts(ports(filename));
    return network.ports() != 0;
}
bool Touchstone::readOptions(NetworkData &network, QTextStream &stream) {
    QStringList words;
    readLine(stream, words);
    if (words[0] != "#")
        return false;
    if (!readFrequencyPrefix(network, words[1])) {
        return false;
    }
    if (!readDataType(network, words[2])) {
        return false;
    }
    if (!readFormat(words[3])) {
        return false;
    }
    if (words.size() == 6)
         network.setReferenceImpedance(words.last().toDouble());
    // Else
    return true;
}
bool Touchstone::readFrequencyPrefix(NetworkData &network, QString units) {
    if (!units.contains("Hz", Qt::CaseInsensitive))
        return false;

    units.chop(2);
    network.setXUnits(Units::Hertz, toSiPrefix(units));
    return true;
}
bool Touchstone::readDataType(NetworkData &network, QString type) {
    QRegularExpression S_REGEX(toString(NetworkParameter::S), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression Y_REGEX(toString(NetworkParameter::Y), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression Z_REGEX(toString(NetworkParameter::Z), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression H_REGEX(toString(NetworkParameter::H), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression G_REGEX(toString(NetworkParameter::G), QRegularExpression::CaseInsensitiveOption);

    if(type.size() == 1)
    {
        if (S_REGEX.match(type).hasMatch()) {
            network.setParameter(NetworkParameter::S);
            return true;
        }
        if (Y_REGEX.match(type).hasMatch()) {
            network.setParameter(NetworkParameter::Y);
            return true;
        }
        if (Z_REGEX.match(type).hasMatch()) {
            network.setParameter(NetworkParameter::Z);
            return true;
        }
        if (H_REGEX.match(type).hasMatch()) {
            network.setParameter(NetworkParameter::H);
            return true;
        }
        if (G_REGEX.match(type).hasMatch()) {
            network.setParameter(NetworkParameter::G);
            return true;
        }
    }

    // If all else fails
    return false;
}
bool Touchstone::readFormat(QString format) {
    QRegularExpression RI_REGEX(toString(ComplexFormat::RealImaginary), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression MA_REGEX(toString(ComplexFormat::MagnitudeDegrees), QRegularExpression::CaseInsensitiveOption);
    QRegularExpression DB_REGEX(toString(ComplexFormat::DecibelDegrees), QRegularExpression::CaseInsensitiveOption);

    if(format.length() != 2)
        return false;
    if (RI_REGEX.match(format).hasMatch()) {
        readDatum = &readRI;
        return true;
    }
    if (MA_REGEX.match(format).hasMatch()) {
        readDatum = &readMA;
        return true;
    }
    if (DB_REGEX.match(format).hasMatch()) {
        readDatum = &readDB;
        return true;
    }
    // Else
    return false;
}

// Read data
bool Touchstone::readData(NetworkData &network, QTextStream &stream) {
    QRowVector freqs;
    ComplexMatrix3D data;
    while (!stream.atEnd()) {
        ComplexMatrix2D row;
        double freq;
        if (readRow(network, stream, row, freq)) {
            freqs << freq;
            data.push_back(row);
        }
    }

    uint ports = network.ports();
    network.setData(freqs, data);
    if (network.ports() != ports || network.points() == 0)
    return false;
    if (network.ports() == 2)
        flip2Ports(network);
    return true;
}
bool Touchstone::readRow(NetworkData &network, QTextStream &stream, ComplexMatrix2D &dataRow, double &frequencyPoint) {
    // Begin to read data values
    double wordsToRead = pow(double(network.ports()), 2) * 2 + 1;
    QStringList allWords;
    while (wordsToRead > 0 && !stream.atEnd()) {
        QStringList words;
        readLine(stream, words);
        wordsToRead -= words.size();
        allWords.append(words);
    }

    // Check to see if all data was read
    if (wordsToRead != 0)
        return false;

    // Process data
    frequencyPoint = allWords[0].toDouble();
    QStringList::iterator wordIndex = allWords.begin() + 1;
    dataRow.resize(network.ports());
    for (ComplexMatrix2D::iterator rowIndex = dataRow.begin(); rowIndex != dataRow.end(); rowIndex++) {
        (*rowIndex).resize(network.ports());
        ComplexRowVector::iterator columnIndex = (*rowIndex).begin();
        for (; columnIndex != (*rowIndex).end(); columnIndex++) {
            *columnIndex = (*readDatum)(wordIndex->toDouble(), (wordIndex + 1)->toDouble());
            wordIndex += 2;
        }
    }
    return true;
}
ComplexDouble (*Touchstone::readDatum)(double, double);
ComplexDouble Touchstone::readRI(double word1, double word2) {
    return (ComplexDouble(word1, word2));


}
ComplexDouble Touchstone::readMA(double word1, double word2) {
    double real = word1 * cos(word2 * PI/180);
    double imag = word1 * sin(word2 * PI/180);
    return ComplexDouble(real, imag);
}
ComplexDouble Touchstone::readDB(double word1, double word2) {
    return readMA(toMagnitude(word1), word2);
}


/* WRITE HELPER FUNCTIONS */

void Touchstone::createFile(QFile &file, QString filename, NetworkData &network) {
    QRegularExpression TOUCHSTONE_REGEX(TOUCHSTONE_FILE_REGEX, QRegularExpression::CaseInsensitiveOption);
    if (TOUCHSTONE_REGEX.match(filename).hasMatch()) {
        // Chop off file extension
        int dotPosition = filename.lastIndexOf(".");
        filename.truncate(dotPosition);
    }
    filename = filename + ".s" + QString::number(network.ports()) + "p";
    file.setFileName(filename);
    file.open(QFile::WriteOnly);
}
void Touchstone::writeComments(NetworkData &network, QTextStream &stream) {
    stream << "! RsaToolbox (C) 2015 Rohde & Schwarz America" << endl;
    stream << "! " << endl;
    stream << "! Number of points: " << network.points() << endl;
    stream << "! Number of ports: " << network.ports() << endl;
    stream << "! Balanced ports?: " << "No" << endl;
    stream << "! " << endl << "! " << endl;
}

// Write Options + helpers
void Touchstone::writeOptions(NetworkData &network, QTextStream &stream) {
    // Write options info
    stream << "# ";
    stream << writeUnits(network) << " ";
    stream << writeDataType(network) << " ";
    stream << writeFormat(network) << " ";
    // stream << "R " << network.impedance << endl;
    stream << "R " << 50 << endl;
}
QString Touchstone::writeUnits(NetworkData &network) {
    return toString(network.xPrefix(), network.xUnits());
}
QString Touchstone::writeDataType(NetworkData &network) {
    return toString(network.parameter());
}
QString Touchstone::writeFormat(NetworkData &network) {
    Q_UNUSED(network);
    return toString(ComplexFormat::RealImaginary);
}

// Write data + helpers
void Touchstone::writeData(NetworkData &network, QTextStream &stream) {
    // Choose data format
    getWriteFormat(network);

    stream.setRealNumberPrecision(PRECISION);
    for (uint currentFreq = 0; currentFreq < network.points(); currentFreq++) {
        stream.setFieldAlignment(QTextStream::AlignLeft);
        stream.setFieldWidth(COLUMNWIDTH);
        stream << network.x()[currentFreq];
        ComplexMatrix2D::iterator row_iter = network.y()[currentFreq].begin();
        writeRow(stream, *row_iter);
        row_iter++;
        for (; row_iter != network.y()[currentFreq].end(); row_iter++) {
            stream.setFieldAlignment(QTextStream::AlignLeft);
            stream.setFieldWidth(COLUMNWIDTH);
            stream << " "; // tab past frequency column for subsequent rows
            writeRow(stream, *row_iter);
        }
    }
}
void Touchstone::write2PortData(NetworkData &network, QTextStream &stream) {
    getWriteFormat(network);

    stream.setRealNumberPrecision(PRECISION);
    for (uint currentFreq = 0; currentFreq < network.points(); currentFreq++) {
        stream.setFieldAlignment(QTextStream::AlignLeft);
        stream.setFieldWidth(COLUMNWIDTH);
        stream << network.x()[currentFreq];

        ComplexRowVector row;
        row.reserve(4);
        row.insert(row.end(), network.y()[currentFreq][0].begin(), network.y()[currentFreq][0].end());
        row.insert(row.end(), network.y()[currentFreq][1].begin(), network.y()[currentFreq][1].end());
        writeRow(stream, row);
    }
}
void Touchstone::writeRow(QTextStream &stream, ComplexRowVector &row) {
    uint columnsWritten = 1;
    int const COLUMNSPERLINE = 4;
    ComplexRowVector::iterator column_iter = row.begin();
    for (; column_iter != row.end(); column_iter++) {
        (*writeDatum)(stream, *column_iter);
        if (columnsWritten % COLUMNSPERLINE == 0
                && column_iter != row.end()-1)
        {
            stream.setFieldWidth(0);
            stream << endl;
            stream.setFieldAlignment(QTextStream::AlignLeft);
            stream.setFieldWidth(COLUMNWIDTH);
            stream << " ";
        }
        columnsWritten++;
    }

    // Newline to separate frequency points:
    stream.setFieldWidth(0);
    stream << endl;
    stream.setFieldAlignment(QTextStream::AlignLeft);
    stream.setFieldWidth(COLUMNWIDTH);
}
void Touchstone::getWriteFormat(NetworkData &network) {
    Q_UNUSED(network);
    writeDatum = &writeRI;
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
void (*Touchstone::writeDatum)(QTextStream &, ComplexDouble &);
void Touchstone::writeRI(QTextStream &stream, ComplexDouble &datum) {
    stream.setFieldAlignment(QTextStream::AlignLeft);
    stream.setFieldWidth(COLUMNWIDTH);
    stream << datum.real();
    stream << datum.imag();
}
void Touchstone::writeMA(QTextStream &stream, ComplexDouble &datum) {
    stream.setFieldAlignment(QTextStream::AlignLeft);
    stream.setFieldWidth(COLUMNWIDTH);
    stream << abs(datum);
    stream << arg(datum) * 180 / PI;
}
void Touchstone::writeDB(QTextStream &stream, ComplexDouble &datum) {
    stream.setFieldAlignment(QTextStream::AlignLeft);
    stream.setFieldWidth(COLUMNWIDTH);
    stream << toDb(datum);
    stream << arg(datum) * 180 / PI;
}



