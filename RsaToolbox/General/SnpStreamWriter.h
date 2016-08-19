#ifndef SNPSTREAMWRITER_H
#define SNPSTREAMWRITER_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>


namespace RsaToolbox {

class SnpStreamWriter
{
public:
//    SnpStreamWriter();
    SnpStreamWriter(QString filePathName);
    SnpStreamWriter(QString filePathName, uint ports);
    bool setFileName(QString filePathName);
    bool setFileName(QString filePathName, uint ports);
    bool rename(QString filePathName);
    bool isValidFilename();
    bool isOpen();
    bool isClosed();
    bool open();
    void close();

    void writeCommentLine(QString comment);
    bool writeOptions(NetworkParameter parameter = NetworkParameter::S, SiPrefix frequencyPrefix = SiPrefix::None, ComplexFormat format = ComplexFormat::RealImaginary, double impedance_Ohms = 50);
    bool writePoint(double const &frequency, ComplexMatrix2D const &matrix);

private:
    QFile _file;
    QTextStream _stream;
    void _initialize();
    bool _isNotPorts();
    bool _parsePorts(QString filePathName);

    bool _isOptionsLineMissing;
    NetworkParameter _parameter;
    double _impedance_Ohms;
    uint _ports;
    double _frequencyFactor;
    void _writeColumnHeaders();
    // comment: " <freq[%1]>" +(1<=n<=4)x"  <%2>  <%3>"

    double _previousFrequency;
    double const *_frequency;
    uint _numberOfValues;
    ComplexMatrix2D _matrix;
    bool _isInvalidFrequency(double frequency);
    bool _isInvalidMatrix(ComplexMatrix2D const &matrix);

    void _setDataFormat();
    void _writeFrequency(double frequency);
    void _writeBlankColumn();
    void _writeMatrix(ComplexMatrix2D const &matrix);
    ComplexDouble _serialize(uint index);
    void _writeFirstLine(uint &position);
    bool _writeNextLine(uint &position);
    void _writeLine(uint begin, uint end);
    void (SnpStreamWriter::*_writeValue)(const ComplexDouble &value);
    void _writeRealImaginary(const ComplexDouble &value);
    void _writeMagnitudeAngle(const ComplexDouble &value);
    void _writeDecibelAngle(const ComplexDouble &value);

    void _setFlip();
    void (SnpStreamWriter::*_flip2Port)();
    void _flip();
    void _noFlip();

};
}


#endif // SNPSTREAMWRITER_H
