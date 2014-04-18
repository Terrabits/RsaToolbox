#include "SnpStreamWriter.h"
#include <QDebug>


// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QFileInfo>


SnpStreamWriter::SnpStreamWriter() {
    _stream.setDevice(&_file);
    _initialize();
}
SnpStreamWriter::SnpStreamWriter(QString filePathName) {
    _stream.setDevice(&_file);
    _initialize();
    setFileName(filePathName);
}
SnpStreamWriter::SnpStreamWriter(QString filePathName, uint ports) {
    _stream.setDevice(&_file);
    _initialize();
    setFileName(filePathName, ports);
}

bool SnpStreamWriter::setFileName(QString filePathName) {
    if (isOpen())
        close();

    _initialize();
    if (_parsePorts(filePathName)) {
        _file.setFileName(filePathName);
        return(true);
    }
    else {
        return(false);
    }
}
bool SnpStreamWriter::setFileName(QString filePathName, uint ports) {
    if (ports == 0 || filePathName.size() == 0)
        return(false);

    QString fileName = QFileInfo(filePathName).fileName();
    QRegExp snp("\\.s\\d+p", Qt::CaseInsensitive);
    int i = snp.lastIndexIn(fileName);
    if (i != -1)
        filePathName.chop(fileName.size() - i);
    filePathName += QString(".s%1p").arg(ports);
    return(setFileName(filePathName));
}
bool SnpStreamWriter::rename(QString fileName) {
    if (isClosed() || fileName.size() == 0)
        return(false);

    fileName = QFileInfo(fileName).fileName();
    QRegExp snp("\\.s\\d+p", Qt::CaseInsensitive);
    int i = snp.lastIndexIn(fileName);
    if (i != -1)
        fileName.chop(fileName.size() - i);
    fileName += QString(".s%1p").arg(_ports);
    return(_file.rename(fileName));
}
bool SnpStreamWriter::isValidFilename() {
    return(_ports > 0);
}

bool SnpStreamWriter::isOpen() {
    return(_file.isOpen());
}
bool SnpStreamWriter::isClosed() {
    return(!isOpen());
}
bool SnpStreamWriter::open() {
    if (isOpen())
        close();

    // _initialize();
    if (isValidFilename()) {
        return(_file.open(QFile::WriteOnly));
    }
    else
        return(false);
}
void SnpStreamWriter::close() {
    _stream.flush();
    _file.close();
    _initialize();
}

void SnpStreamWriter::writeCommentLine(QString comment) {
    _stream.reset();
    _stream << "!" << comment << endl;
    _setDataFormat();
}
bool SnpStreamWriter::writeOptions(NetworkParameter parameter, SiPrefix frequencyPrefix, ComplexFormat format, double impedance_Ohms) {
    if (isOpen() && _isOptionsLineMissing) {
        _parameter = parameter;
        _impedance_Ohms = impedance_Ohms;
        _frequencyFactor = toDouble(frequencyPrefix);

        if (format == DB_DEGREES_COMPLEX)
            _writeValue = &SnpStreamWriter::_writeMagnitudeAngle;
        else if (format == MAGNITUDE_DEGREES_COMPLEX)
            _writeValue = &SnpStreamWriter::_writeDecibelAngle;
        else
            _writeValue = &SnpStreamWriter::_writeRealImaginary;

        _stream.reset();
        QString options = "#  %1   %2   %3   R     %4\n";
        options = options.arg(toString(frequencyPrefix, HERTZ_UNITS));
        options = options.arg(toString(parameter));
        options = options.arg(toString(format));
        options = options.arg(formatDouble(impedance_Ohms, 2));
        _stream << options;
        _setDataFormat();
        _isOptionsLineMissing = false;
        return(true);
    }
    else {
        return(false);
    }
}
bool SnpStreamWriter::writePoint(const double &frequency, const ComplexMatrix2D &matrix) {
    if (_isOptionsLineMissing) {
        return(false);
    }
    if (_isInvalidFrequency(frequency)) {
        return(false);
    }
    if (_isInvalidMatrix(matrix)) {
        return(false);
    }

    _writeFrequency(frequency);
    _writeMatrix(matrix);
    _previousFrequency = *_frequency;
    return(true);
}

void SnpStreamWriter::_setDataFormat() {
    _stream << left
            << qSetFieldWidth(23)
            << scientific
            << qSetRealNumberPrecision(15);
}
void SnpStreamWriter::_writeFrequency(double frequency) {
    _frequency = &frequency;
    _stream.reset();
    _stream << " ";
    _setDataFormat();
    _stream << frequency;
}
void SnpStreamWriter::_writeBlankColumn() {
    _stream.reset();
    _stream << QString(24, ' ');
    _setDataFormat();
}
void SnpStreamWriter::_writeMatrix(const ComplexMatrix2D &matrix) {
    _matrix = matrix;
    (this->*_flip2Port)();
    uint position = 0;
    _writeFirstLine(position);
    while (_writeNextLine(position));
}
ComplexDouble SnpStreamWriter::_serialize(uint index) {
    uint row = index/_ports;
    uint column = index % _ports;
    return(_matrix[row][column]);
}
void SnpStreamWriter::_writeFirstLine(uint &position) {
    if (_numberOfValues < 4) {
        _writeLine(0, _numberOfValues);
        position = _numberOfValues;
    }
    else {
        _writeLine(0, 4);
        position = 4;
    }
}
bool SnpStreamWriter::_writeNextLine(uint &position) {
    if (position >= _numberOfValues)
        return(false);

    _writeBlankColumn();
    if (position+4 <= _numberOfValues) {
        _writeLine(position, position+4);
        position += 4;
    }
    else {
        _writeLine(position, _numberOfValues-position);
        position = _numberOfValues;
    }
    return(true);
}
void SnpStreamWriter::_writeLine(uint begin, uint end) {
    for (uint i = begin; i < end; i++) {
        (this->*_writeValue)(_serialize(i));
    }
    _stream.reset();
    _stream << endl;
    _setDataFormat();
}
void SnpStreamWriter::_writeRealImaginary(const ComplexDouble &value) {
    _stream.reset();
    _stream << " ";
    _setDataFormat();
    _stream << value.real();
    _stream.reset();
    _stream << " ";
    _setDataFormat();
    _stream << value.imag();
}
void SnpStreamWriter::_writeMagnitudeAngle(const ComplexDouble &value) {
    _stream.reset();
    _stream << " ";
    _setDataFormat();
    _stream << abs(value);
    _stream.reset();
    _stream << " ";
    _setDataFormat();
    _stream << angle_deg(value);
}
void SnpStreamWriter::_writeDecibelAngle(const ComplexDouble &value) {
    _stream.reset();
    _stream << " ";
    _setDataFormat();
    _stream << toDb(value);
    _stream.reset();
    _stream << " ";
    _setDataFormat();
    _stream << angle_deg(value);
}

// Private
void SnpStreamWriter::_initialize() {
    _ports = 0;
    _isOptionsLineMissing = true;
    _previousFrequency = -1.0*DBL_MIN;
    _setDataFormat();
}
bool SnpStreamWriter::_isNotPorts() {
    return(_ports == 0);
}

bool SnpStreamWriter::_parsePorts(QString filePathName) {
    QString fileName = QFileInfo(filePathName).fileName();
    QRegExp snp("\\.s\\d+p", Qt::CaseInsensitive);
    int i = snp.lastIndexIn(fileName);
    if (i == -1) {
        return(false);
    }
    else {
        int size = fileName.size() - 1 - (i+2);
        _ports = fileName.mid(i+2, size).toUInt();
        _numberOfValues = pow(double(_ports), 2.0);
        if (_ports > 0) {
            _setFlip();
            return(true);
        }
        else {
            return(false);
        }
    }
}
void SnpStreamWriter::_writeColumnHeaders() {

}
bool SnpStreamWriter::_isInvalidFrequency(double frequency) {
    return(frequency <= _previousFrequency);
}
bool SnpStreamWriter::_isInvalidMatrix(const ComplexMatrix2D &matrix) {
    if (matrix.size() != _ports)
        return(true);
    for (uint i = 0; i < _ports; i++) {
        if (matrix[i].size() != _ports)
            return(true);
    }
    return(false);
}

void SnpStreamWriter::_setFlip() {
    if (_ports == 2)
        _flip2Port = &SnpStreamWriter::_flip;
    else
        _flip2Port = &SnpStreamWriter::_noFlip;
}
void SnpStreamWriter::_flip() {
    _matrix = transpose(_matrix);
}
void SnpStreamWriter::_noFlip() {
    // Do nothing!
    return;
}
