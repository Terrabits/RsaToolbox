#include "SnpStreamReader.h"


// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

//Qt
#include <QFileInfo>
#include <QRegExp>
#include <QDebug>


//SnpStreamReader::SnpStreamReader() {
//    _isValidFile = false;
//    _stream.setDevice(&_file);
//}
SnpStreamReader::SnpStreamReader(QString filePathName) :
    _file(filePathName),
    _stream(&_file)
{
    _isValidFile = false;
    //_stream.setDevice(&_file);
    setFilename(filePathName);
    //open();
}

void SnpStreamReader::setFilename(QString filePathName) {
    _file.setFileName(filePathName);
}
bool SnpStreamReader::isOpen() {
    return(_file.isOpen());
}
bool SnpStreamReader::open() {
    _file.open(QFile::ReadOnly);
    if (isClosed()) {
        _isValidFile = false;
        return(false);
    }

    _isValidFile = true;
    _parsePorts();
    _stream.setDevice(&_file);
    _readOptions();
    next();
    _point = 0;
    if (_isValidFile) {
        return(true);
    }
    else {
        close();
        return(false);
    }
}
bool SnpStreamReader::isClosed() {
    return(!isOpen());
}
void SnpStreamReader::close() {
    if (isOpen())
        _file.close();
    _isValidFile = false;
}

NetworkParameter SnpStreamReader::parameter() {
    return(_parameter);
}
double SnpStreamReader::impedance_Ohms() {
    return(_impedance_Ohms);
}
uint SnpStreamReader::ports() {
    return(_ports);
}

bool SnpStreamReader::isNotData() {
    return(!_isValidFile);
}
bool SnpStreamReader::isData() {
    return(_isValidFile);
}
uint SnpStreamReader::point() {
    return(_point);
}
bool SnpStreamReader::seekForward(double frequency, SiPrefix prefix) {
    frequency = frequency*toDouble(prefix);
    if (frequency < _frequency_Hz)
        return(false);
    if (frequency == _frequency_Hz)
        return(true);

    // else
    double oldFreq;
    ComplexMatrix2D oldData;
    qint64 oldPos = 0;
    while (_frequency_Hz < frequency && _next(oldFreq, oldData, oldPos));
    if (_frequency_Hz > frequency) {
        _rewind(oldFreq, oldData, oldPos);
        return(true);
    }
    else if (_frequency_Hz == frequency) {
        return(true);
    }
    else {
        return(false);
    }
}
bool SnpStreamReader::peek(double &frequency_Hz, ComplexMatrix2D &data) {
    double oldFreq;
    ComplexMatrix2D oldData;
    qint64 oldPos;
    if (_next(oldFreq, oldData, oldPos)) {
        frequency_Hz = _frequency_Hz;
        data = _data;
        _rewind(oldFreq, oldData, oldPos);
        return(true);
    }
    else {
        _rewind(oldFreq, oldData, oldPos);
        return(false);
    }
}
bool SnpStreamReader::next() {
    if (_isValidFile == false)
        return(false);

    _point++;
    QStringList values = _readValues();
    if (values.size() != _valuesToRead) {
        _frequency_Hz = 0;
        _data.clear();
        _resizeData();
        _isValidFile = false;
        return(false);
    }
    // Else
    _parseFrequency(values.takeFirst());
    _parseData(values);
    (this->*_flip2Port)();
    return(true);
}

double SnpStreamReader::frequency_Hz() {
    return(_frequency_Hz);
}
ComplexMatrix2D SnpStreamReader::data() {
    return(_data);
}
ComplexDouble SnpStreamReader::data(uint outputPort, uint inputPort) {
    return(_data[outputPort-1][inputPort-1]);
}

bool SnpStreamReader::_next(double &oldFreq, ComplexMatrix2D &oldData, qint64 &oldPos) {
    if (_isValidFile == false)
        return(false);

    oldPos = _stream.pos();
    oldFreq = _frequency_Hz;
    oldData = _data;

    _point++;
    QStringList values = _readValues();
    if (values.size() != _valuesToRead) {
        _frequency_Hz = 0;
        _data.clear();
        _resizeData();
        _isValidFile = false;
        return(false);
    }
    // Else
    _parseFrequency(values.takeFirst());
    _parseData(values);
    (this->*_flip2Port)();
    return(true);
}
void SnpStreamReader::_rewind(double const &oldFreq, ComplexMatrix2D const &oldData, qint64 const &oldPos) {
    _point--;
    _frequency_Hz = oldFreq;
    _data = oldData;
    _stream.seek(oldPos);
    _isValidFile = true;
}

QStringList SnpStreamReader::_readLine() {
    QStringList result;
    if (_stream.atEnd())
        return(result);

    QString line = _stream.readLine();
    line = _removeComment(line);
    line = line.simplified();
    result = line.split(" ", QString::SkipEmptyParts);
    if (result.isEmpty())
        return(_readLine());
    else
        return(result);
}
QString SnpStreamReader::_removeComment(QString line) {
    if (line.contains("!")) {
        uint pos = line.indexOf("!");
        line.truncate(pos);
    }
    return(line);
}

void SnpStreamReader::_parsePorts() {
    if (_isValidFile == false)
        return;

    QString filename = _file.fileName();
    QRegExp snpFileRegex("^.*\\.s0*[1-9][0-9]*p$", Qt::CaseInsensitive);
    if (filename.contains(snpFileRegex)) {
        // Read number of ports
        int dot = filename.lastIndexOf(".");
        filename.remove(0, dot + 2);
        filename.chop(1);
        _ports = filename.toUInt();
        _setFlip();
    }
    else {
        _isValidFile = false;
    }
}
void SnpStreamReader::_readOptions() {
    if (_isValidFile == false)
        return;

    QStringList options = _readLine();
    if (options.isEmpty() == false
            && options.first() == "#"
            && options.size() >= 4)
    {
        _parseFrequencyPrefix(options[1]);
        _parseNetworkParameter(options[2]);
        _parseComplexFormat(options[3]);
        if (options.size() == 6)
            _parseImpedance(options.last());
        else
            _impedance_Ohms = 50;
        if (_isValidFile)
            _valuesToRead = 1 + 2*pow(int(_ports), 2.0);
    }
    else {
        _isValidFile = false;
    }
}

void SnpStreamReader::_parseFrequencyPrefix(QString units) {
    if (units.contains("Hz", Qt::CaseInsensitive)) {
        units.chop(2);
        _frequencyFactor = toDouble(toSiPrefix(units));
    }
    else {
        _isValidFile = false;
    }
}
void SnpStreamReader::_parseNetworkParameter(QString parameter) {
    if (parameter.size() > 1) {
        _isValidFile = false;
        return;
    }

    char p = parameter.at(0).toUpper().toLatin1();
    switch(p) {
    case 'S':
        _parameter = S_PARAMETER;
        break;
    case 'Y':
        _parameter = Y_PARAMETER;
        break;
    case 'Z':
        _parameter = Z_PARAMETER;
        break;
    default:
        _isValidFile = false;
    }
}
void SnpStreamReader::_parseComplexFormat(QString format) {
    if (format.size() != 2) {
        _isValidFile = false;
        return;
    }

    format = format.toUpper();
    if (format == "DB")
        _convert = fromDbDegrees;
    else if (format == "MA")
        _convert = fromMagDegrees;
    else if (format == "RI")
        _convert = fromRealImag;
    else
        _isValidFile = false;
}
void SnpStreamReader::_parseImpedance(QString impedance) {
    _impedance_Ohms = impedance.toDouble();
    if (_impedance_Ohms <= 0)
        _isValidFile = false;
}

QStringList SnpStreamReader::_readValues() {
    QStringList values;
    uint valuesRead = 0;
    while (_stream.atEnd() == false
           && valuesRead < _valuesToRead)
    {
        values += _readLine();
        valuesRead = values.size();
    }
    return(values);
}
void SnpStreamReader::_parseFrequency(QString value) {
    _frequency_Hz = _frequencyFactor * value.toDouble();
}
void SnpStreamReader::_resizeData() {
    _data.resize(_ports);
    for (uint i = 0; i < _ports; i++)
        _data[i].resize(_ports);
}
void SnpStreamReader::_parseData(QStringList data) {
    resize(_data, _ports, _ports);
    int pos = 0;
    for (uint i = 0; i < _ports; i++) {
        for (uint j = 0; j < _ports; j++) {
            _data[i][j] =
                    _convert(data[pos].toDouble(),
                             data[pos+1].toDouble());
            pos += 2;
        }
    }
}

void SnpStreamReader::_setFlip() {
    if (_ports == 2)
        _flip2Port = &SnpStreamReader::_flip;
    else
        _flip2Port = &SnpStreamReader::_noFlip;
}
void SnpStreamReader::_flip() {
    _data = transpose(_data);
}
void SnpStreamReader::_noFlip() {
    // Do nothing!
    return;
}


