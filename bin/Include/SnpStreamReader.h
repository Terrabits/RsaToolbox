#ifndef SNPSTREAMREADER_H
#define SNPSTREAMREADER_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>


namespace RsaToolbox {

class SnpStreamReader {
public:
//    SnpStreamReader();
    SnpStreamReader(QString filePathName);

    void setFilename(QString filePathName);
    bool isOpen();
    bool open();
    bool isClosed();
    void close();

    NetworkParameter parameter();
    double impedance_Ohms();
    uint ports();

    bool isNotData();
    bool isData();
    uint point();
    bool seekForward(double frequency, SiPrefix prefix = SiPrefix::None);
    bool peek(double &frequency_Hz, ComplexMatrix2D &data);
    bool next();

    double frequency_Hz();
    ComplexMatrix2D data();
    ComplexDouble data(uint outputPort, uint inputPort);

private:
    bool _isValidFile;
    QFile _file;
    QTextStream _stream;

    NetworkParameter _parameter;
    double _impedance_Ohms;
    uint _ports;
    double _frequencyFactor;

    uint _point;
    double _frequency_Hz;
    ComplexMatrix2D _data;

    bool _next(double &oldFreq, ComplexMatrix2D &oldData, qint64 &oldPos);
    void _rewind(double const &oldFreq, ComplexMatrix2D const &oldData, qint64 const &oldPos);

    QStringList _readLine(); // ignore comment
    static QString _removeComment(QString line);

    void _parsePorts();

    void _readOptions();
    void _parseFrequencyPrefix(QString units);
    void _parseNetworkParameter(QString parameter);
    void _parseComplexFormat(QString format);
    void _parseImpedance(QString impedance);

    uint _valuesToRead;
    QStringList _readValues(); // 1 + 2*ports^2
    void _parseFrequency(QString value);
    void _resizeData();
    void _parseData(QStringList data);
    ComplexDouble (*_convert)(double a, double b);

    void _setFlip();
    void (SnpStreamReader::*_flip2Port)();
    void _flip();
    void _noFlip();
};
}


#endif // SNPSTREAMREADER_H
