#include <QDebug>


// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QStandardPaths>
#include <QCoreApplication>

// C++ std lib
#include <cmath>


// Enum Conversions
double RsaToolbox::toDouble(SiPrefix prefix) {
    switch(prefix) {
    case SiPrefix::Tera:
        return(1E12);
        break;
    case SiPrefix::Giga:
        return(1E9);
        break;
    case SiPrefix::Mega:
        return(1E6);
        break;
    case SiPrefix::Kilo:
        return(1E3);
        break;
    case SiPrefix::Milli:
        return(1E-3);
        break;
    case SiPrefix::Micro:
        return(1E-6);
        break;
    case SiPrefix::Nano:
        return(1E-9);
        break;
    case SiPrefix::Pico:
        return(1E-12);
        break;
    case SiPrefix::Femto:
        return(1E-15);
        break;
    default:
        // NO_PREFIX
        return(1);
        break;
    }
}

QString RsaToolbox::toString(ComplexFormat format) {
    switch(format) {
    case ComplexFormat::DecibelDegrees:
        return("dB");
        break;
    case ComplexFormat::MagnitudeDegrees:
        return("MA");
        break;
    case ComplexFormat::RealImaginary:
        return("RI");
        break;
    }
    // Default
    return("dB");
}
QString RsaToolbox::toString(NetworkParameter parameter) {
    switch(parameter) {
    case NetworkParameter::S:
        return("S");
        break;
    case NetworkParameter::Y:
        return("Y");
        break;
    case NetworkParameter::Z:
        return("Z");
        break;
    case NetworkParameter::H:
        return("H");
        break;
    case NetworkParameter::G:
        return("G");
        break;
    }
    // Default
    return("S");
}
QString RsaToolbox::toString(NetworkParameter parameter, uint outputPort, uint inputPort) {
    QString output = QVariant(outputPort).toString();
    QString input = QVariant(inputPort).toString();
    int zeros = output.length() - input.length();
    if (zeros > 0)
        input.prepend(QString(zeros, '0'));
    else if (zeros < 0)
        output.prepend(QString(-zeros, '0'));
    return(toString(parameter) + output + input);
}
QString RsaToolbox::toString(WaveQuantity wave) {
    switch (wave) {
    case WaveQuantity::a:
        return "a";
    case WaveQuantity::b:
        return "b";
    default:
        return "a";
    }
}

QString RsaToolbox::toString(SiPrefix prefix) {
    switch(prefix) {
    case SiPrefix::Tera:
        return("T");
    case SiPrefix::Giga:
        return("G");
    case SiPrefix::Mega:
        return("M");
    case SiPrefix::Kilo:
        return("K");
    case SiPrefix::Milli:
        return("m");
    case SiPrefix::Micro:
        return("u");
    case SiPrefix::Nano:
        return("n");
    case SiPrefix::Pico:
        return("p");
    case SiPrefix::Femto:
        return("f");
    default:
        // NO_PREFIX
        return("");
    }
}
QString RsaToolbox::toString(Units units) {
    switch(units) {
    case Units::Seconds:
        return("s");
    case Units::Hertz:
        return("Hz");
    case Units::Radians:
        return("Rad");
    case Units::Degrees:
        return("Deg");
    case Units::Ohms:
        return("Ohm");
    case Units::Siemens:
        return("S");
    case Units::Watts:
        return("W");
    case Units::dB:
        return("dB");
    case Units::dBW:
        return("dBW");
    case Units::dBm:
        return("dBm");
    default:
        // NO_UNITS
        return("");
    }
}
QString RsaToolbox::toString(SiPrefix prefix, Units units) {
    return(toString(prefix) + toString(units));
}

SiPrefix RsaToolbox::toSiPrefix(QString prefix) {
    if (prefix == "T")
        return(SiPrefix::Tera);
    if (prefix == "G")
        return(SiPrefix::Giga);
    if (prefix == "M")
        return(SiPrefix::Mega);
    if (prefix == "K")
        return(SiPrefix::Kilo);
    if (prefix == "m")
        return(SiPrefix::Milli);
    if (prefix == "u")
        return(SiPrefix::Micro);
    if (prefix == "n")
        return(SiPrefix::Nano);
    if (prefix == "p")
        return(SiPrefix::Pico);
    if (prefix == "f")
        return(SiPrefix::Femto);
    // Default
    return(SiPrefix::None);
}
SiPrefix RsaToolbox::getPrefix(double value) {
    int decimal_places = 1;
    const int count = 10;
    SiPrefix prefixes[count] = {
        SiPrefix::Femto,
        SiPrefix::Pico,
        SiPrefix::Nano,
        SiPrefix::Micro,
        SiPrefix::Milli,
        SiPrefix::None,
        SiPrefix::Kilo,
        SiPrefix::Mega,
        SiPrefix::Giga,
        SiPrefix::Tera
    };

    double magnitude = abs(value);
    for (int i = 0; i < count-1; i++) {
        double bound = (1.0 - 0.5 * pow(10.0, double(-3 - decimal_places))) * toDouble(prefixes[i + 1]);
         if (magnitude < bound)
            return(prefixes[i]);
    }

    // else Tera or bigger
    return(prefixes[count-1]);
}


// File system
QString RsaToolbox::AppendPath(QDir path, QString filename) {
    return(path.path() + "/" + filename);
}
QString RsaToolbox::AppendCurrentDirectory(QString filename) {
    return(QCoreApplication::applicationDirPath() + "/" + filename);
}
QString RsaToolbox::GetAppDataPath(QString program_folder) {
    QStringList dataLocations = QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation);
    QString path;
    if (dataLocations.size() > 0)
        path = dataLocations.back()
                + "/" + QString(COMPANY_FOLDER)
                + "/" + program_folder;
    else
        path = QCoreApplication::applicationDirPath();
    return(path);
}
QString RsaToolbox::AppendAppDataPath(QString program_folder, QString filename) {
    QStringList dataLocations = QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation);
    QString path;
    if (dataLocations.size() > 0)
        path = dataLocations.back()
                + "/" + QString(COMPANY_FOLDER)
                + "/" + program_folder;
    else
        path = QCoreApplication::applicationDirPath();
    filename = path + "/" + filename;
    return(filename);
}

// Formatting
QString RsaToolbox::toEngineeringNotation(double value, int decimalPlaces, SiPrefix prefix) {
    QString result;
    QTextStream stream(&result);
    stream.setRealNumberPrecision(decimalPlaces);
    stream.setRealNumberNotation(QTextStream::FixedNotation);

    const int count = 10;
    SiPrefix prefixes[count] = { SiPrefix::Femto,
                                 SiPrefix::Pico,
                                 SiPrefix::Nano,
                                 SiPrefix::Micro,
                                 SiPrefix::Milli,
                                 SiPrefix::None,
                                 SiPrefix::Kilo,
                                 SiPrefix::Mega,
                                 SiPrefix::Giga,
                                 SiPrefix::Tera
                               };

    QStringList eNotation;
    eNotation.append("E-15");
    eNotation.append("E-12");
    eNotation.append("E-9");
    eNotation.append("E-6");
    eNotation.append("E-3");
    eNotation.append("");
    eNotation.append("E3");
    eNotation.append("E6");
    eNotation.append("E9");
    eNotation.append("E12");

    double magnitude = abs(value * toDouble(prefix));
    for (int i = 0; i < count; i++) {
        double bound = (1 - 0.5 * pow(10.0, (double)(-3 - decimalPlaces))) * toDouble(prefixes[i + 1]);
        if (magnitude < bound) {
            stream << (value / toDouble(prefixes[i]));
            stream.flush();
            if (i == 0 && result.toDouble() == 0)
                return result;
            stream << eNotation[i];
            stream.flush();
            return(result);
        }
    }

    // else Tera or bigger
    stream << (value / toDouble(SiPrefix::Tera));
    stream << eNotation.last();
    stream.flush();
    return(result);
}
QString RsaToolbox::formatValue(double value, int decimalPlaces, Units units, SiPrefix prefix) {
    QString result;
    QTextStream stream(&result);
    stream.setRealNumberPrecision(decimalPlaces);
    stream.setRealNumberNotation(QTextStream::FixedNotation);

    const int count = 10;
    SiPrefix prefixes[count] = { SiPrefix::Femto,
                                 SiPrefix::Pico,
                                 SiPrefix::Nano,
                                 SiPrefix::Micro,
                                 SiPrefix::Milli,
                                 SiPrefix::None,
                                 SiPrefix::Kilo,
                                 SiPrefix::Mega,
                                 SiPrefix::Giga,
                                 SiPrefix::Tera
                               };

    double magnitude = abs(value * toDouble(prefix));
    for (int i = 0; i < count; i++) {
        double bound = (1 - 0.5 * pow(10.0, (double)(-3 - decimalPlaces))) * toDouble(prefixes[i + 1]);
        if (magnitude < bound) {
            stream << (value / toDouble(prefixes[i]));
            stream.flush();
            if (i == 0 && result.toDouble() == 0)
                stream << " " << units;
            else
                stream << " " << prefixes[i] << units;
            stream.flush();
            return(result);
        }
    }

    // else Tera or bigger
    stream << (value / toDouble(prefixes[count-1]));
    stream << " " << SiPrefix::Tera << units;
    stream.flush();
    return result;
}
QString RsaToolbox::formatDouble(double value, int decimalPlaces) {
    QString string;
    QTextStream stream(&string);
    stream.setRealNumberPrecision(decimalPlaces);
    stream.setRealNumberNotation(QTextStream::FixedNotation);
    stream << value;
    stream.flush();
    return(string);
}
QString RsaToolbox::toString(QStringList list, QString separator) {
    return(toString(list.toVector(), separator));
}
QString RsaToolbox::toString(ComplexRowVector vector, QString list_separator, QString format) {
    int size = vector.size();
    if (size == 0)
        return("");

    QString list;
    list.clear();
    QString item = format;
    item = item.arg(vector[0].real());
    item = item.arg(vector[0].imag());
    list += item;
    for (int i = 1; i < size; i++) {
        list.append(list_separator);
        item = format;
        item = item.arg(vector[i].real());
        item = item.arg(vector[i].imag());
        list += item;
    }
    return(list);
}
QStringList RsaToolbox::portLabels(QVector<uint> ports) {
    QStringList labels;
    QString label = "Port %1";
    foreach(uint port, ports) {
        labels.append(label.arg(port));
    }
    return(labels);
}
QString RsaToolbox::portString(QVector<uint> ports) {
    qSort(ports);
    int numberOfPorts = ports.size();
    QString result;

    int i = 0;
    int j;
    while (i < numberOfPorts) {
        j = i;
        result += QVariant(ports[i]).toString();
        while (j < numberOfPorts-1 && ports[j+1] == ports[j] + 1) {
            j++;
        }
        if (j == i+1)
            result += QString(", %1").arg(ports[j]);
         else if (j > i+1)
            result += QString("-%1").arg(ports[j]);

        if (j < numberOfPorts-1)
            result += ", ";
        i = j+1;
    }
    return(result);
}
QStringList RsaToolbox::channelLabels(QVector<uint> channels) {
    QStringList labels;
    QString label = "Channel %1";
    foreach(uint channel, channels) {
        labels.append(label.arg(channel));
    }
    return(labels);
}

// Parse
QVector<uint> RsaToolbox::parseUints(QString values, QString separator, QString ignore) {
    if (ignore.isEmpty() == false)
        values.remove(ignore);
    QStringList list = values.split(separator, QString::SkipEmptyParts);
    int numberOfValues = list.size();
    QVector<uint> vector(numberOfValues);
    for (int i = 0; i < numberOfValues; i++) {
        vector[i] = QVariant(list[i]).toUInt();
    }
    return(vector);
}
QVector<int> RsaToolbox::parseInts(QString values, QString separator, QString ignore) {
    if (ignore.isEmpty() == false)
        values.remove(ignore);
    QStringList list = values.split(separator, QString::SkipEmptyParts);
    int numberOfValues = list.size();
    QVector<int> vector(numberOfValues);
    for (int i = 0; i < numberOfValues; i++) {
        vector[i] = QVariant(list[i]).toInt();
    }
    return(vector);
}
QVector<double> RsaToolbox::parseDoubles(QString values, QString separator, QString ignore) {
    if (ignore.isEmpty() == false)
        values.remove(ignore);
    QStringList list = values.split(separator, QString::SkipEmptyParts);
    int numberOfValues = list.size();
    QVector<double> vector(numberOfValues);
    for (int i = 0; i < numberOfValues; i++) {
        vector[i] = QVariant(list[i]).toDouble();
    }
    return(vector);
}

ComplexRowVector RsaToolbox::parseComplex(QString values, QString separator, QString ignore) {
    QRowVector list = parseDoubles(values, separator, ignore);
    return(parseComplex(list));
}
ComplexRowVector RsaToolbox::parseComplex(QRowVector values) {
    int size = values.size();
    int resize = int(size/2);
    ComplexRowVector result;
    result.resize(resize);

    int n = 0;
    for (int i = 0; i < resize; i++) {
        double real = values[n];
        double imaginary = values[n+1];
        ComplexDouble value(real, imaginary);
        result[i] = value;
        n += 2;
    }
    return(result);
}

QRowVector RsaToolbox::parseQRowVector(QString buffer) {
    QStringList bufferList = buffer.split(",");
    int numberOfPoints = bufferList.size();
    QRowVector data(numberOfPoints);
    for(int i = 0; i < numberOfPoints; i++) {
        data[i] = bufferList[i].trimmed().toDouble();
    }
    return(data);
}
QRowVector RsaToolbox::parseQRowVector(ComplexRowVector values) {
    int size = values.size();
    QRowVector result(size * 2);
    for (int i = 0; i < size; i++) {
        result[2*i] = values[i].real();
        result[2*i+1] = values[i].imag();
    }
    return(result);
}

QByteArray RsaToolbox::toBlockDataFormat(QRowVector values) {
    quint64 bytes = values.size() * 8;
    QString bytesString = QVariant(bytes).toString();
    QString numberOfNumbers = QVariant(bytesString.size()).toString();
    quint64 headerSize = quint64(2) + quint64(bytesString.size());
    quint64 totalSize = headerSize + bytes;
    QByteArray result;
    result.resize(totalSize);
    QByteArray header = "#" + numberOfNumbers.toUtf8() + bytesString.toUtf8();
    result.replace(0, headerSize, header);
    int index = 0;
    for (quint64 i = headerSize; i < totalSize; i += 8) {
        char *value = (char *)&(values[index]);
        result.replace(i, 8, value, 8);
        index++;
    }
    return(result);
}
QRowVector RsaToolbox::toQRowVector(QByteArray blockData) {
    quint64 numberOfNumbers = blockData.mid(1,1).toInt();
    quint64 bytes = blockData.mid(2, numberOfNumbers).toUInt();
    blockData.remove(0, 2 + numberOfNumbers);
    quint64 numberOfDoubles = bytes/8.0;

    QRowVector values(numberOfDoubles);
    for (quint64 i = 0; i < numberOfDoubles; i++) {
        values[i] = *((double *)blockData.mid(8*i, 8).data());
    }
    return(values);
}
QByteArray RsaToolbox::toBlockDataFormat(ComplexRowVector values) {
    QRowVector result = parseQRowVector(values);
    return(toBlockDataFormat(result));
}
ComplexRowVector RsaToolbox::toComplexRowVector(QByteArray blockData) {
    QRowVector values = toQRowVector(blockData);
    return(parseComplex(values));
}

// Conversions
double RsaToolbox::toDb(double magnitude) {
    return(20.0 * log10(magnitude));
}
QRowVector RsaToolbox::toDb(QRowVector magnitudes) {
    int size = magnitudes.size();
    QRowVector dB(size);
    for (int i = 0; i < size; i++)
        dB[i] = toDb(magnitudes[i]);
    return(dB);
}
double RsaToolbox::toDb(ComplexDouble complexValue) {
    return(toDb(std::abs(complexValue)));
}
QRowVector RsaToolbox::toDb(ComplexRowVector complexValues) {
    int points = int(complexValues.size());
    QRowVector result(points);
    for (int i = 0; i < points; i++) {
        result[i] = toDb(complexValues[i]);
    }
    return(result);
}

double RsaToolbox::toMagnitude(double decibels) {
    return(pow(10.0, decibels / 20.0));
}
QRowVector RsaToolbox::toMagnitude(QRowVector values_dB) {
    int size = values_dB.size();
    QRowVector magnitude(size);
    for (int i = 0; i < size; i++)
        magnitude[i] = toMagnitude(values_dB[i]);
    return(magnitude);
}
double RsaToolbox::toMagnitude(ComplexDouble complexValue) {
    return(std::abs(complexValue));
}
QRowVector RsaToolbox::toMagnitude(ComplexRowVector complexValues) {
    int points = int(complexValues.size());
    QRowVector result(points);
    for (int i = 0; i < points; i++) {
        result[i] = toMagnitude(complexValues[i]);
    }
    return(result);
}

double RsaToolbox::degrees(double phase_rad) {
    return(phase_rad * 180.0 / PI);
}
QRowVector RsaToolbox::degrees(QRowVector phases_rad) {
    int size = phases_rad.size();
    QRowVector result(size);
    for (int i = 0; i < size; i++)
        result[i] = degrees(phases_rad[i]);
    return(result);
}
double RsaToolbox::angle_deg(ComplexDouble complexValue) {
    return(degrees(angle_rad(complexValue)));
}
QRowVector RsaToolbox::angle_deg(ComplexRowVector complexValues) {
    return(degrees(angle_rad(complexValues)));
}

double RsaToolbox::radians(double phase_deg) {
    return(phase_deg * PI / 180.0);
}
QRowVector RsaToolbox::radians(QRowVector phases_deg) {
    int size = phases_deg.size();
    QRowVector result(size);
    for (int i = 0; i < size; i++)
        result[i] = radians(phases_deg[i]);
    return(result);
}
double RsaToolbox::angle_rad(ComplexDouble complexValue) {
    return(std::arg(complexValue));
}
QRowVector RsaToolbox::angle_rad(ComplexRowVector complexValues) {
    int points = int(complexValues.size());
    QRowVector result(points);
    for (int i = 0; i < points; i++) {
        result[i] = angle_rad(complexValues[i]);
    }
    return(result);
}

double RsaToolbox::toVswr(double magnitude) {
    return((1.0 + magnitude)/(1.0 - magnitude));
}
QRowVector RsaToolbox::toVswr(QRowVector magnitudes) {
    int size = magnitudes.size();
    QRowVector result(size);
    for (int i = 0; i < size; i++)
        result[i] = toVswr(magnitudes[i]);
    return(result);
}
double RsaToolbox::toVswr(ComplexDouble complexValue) {
    return(toVswr(toMagnitude(complexValue)));
}
QRowVector RsaToolbox::toVswr(ComplexRowVector complexValues) {
    return(toVswr(toMagnitude(complexValues)));
}

QRowVector RsaToolbox::real(ComplexRowVector complexValues) {
    int points = int(complexValues.size());
    QRowVector result(points);
    for (int i = 0; i < points; i++) {
        result[i] = complexValues[i].real();
    }
    return(result);
}
QRowVector RsaToolbox::imaginary(ComplexRowVector complexValues) {
    int points = int(complexValues.size());
    QRowVector result(points);
    for (int i = 0; i < points; i++) {
        result[i] = complexValues[i].imag();
    }
    return(result);
}

ComplexDouble RsaToolbox::fromRealImag(double real, double imag) {
    return(ComplexDouble(real, imag));
}
ComplexDouble RsaToolbox::fromMagDegrees(double magnitude, double angle_deg) {
    double real = magnitude * std::cos(radians(angle_deg));
    double imag = magnitude * std::sin(radians(angle_deg));
    return(ComplexDouble(real, imag));
}
ComplexDouble RsaToolbox::fromDbDegrees(double dB, double angle_deg) {
    double mag = toMagnitude(dB);
    return(fromMagDegrees(mag, angle_deg));
}


// Math
QVector<int> RsaToolbox::range(int start, int stop, int stepSize) {
    QVector<int> range;
    if (start == stop) {
        range.append(start);
        return(range);
    }

    if (start < stop) {
        for (int i = start; i <= stop; i += stepSize)
            range.append(i);

        return(range);
    }

    if (start > stop) {
        for (int i = start; i >= stop; i -= stepSize)
            range.append(i);

        return(range);
    }

    // This will never happen
    return(range);
}
QVector<uint> RsaToolbox::range(uint start, uint stop, uint stepSize) {
    QVector<uint> range;
    if (start == stop) {
        range.append(start);
        return(range);
    }

    if (start < stop) {
        for (uint i = start; i <= stop; i += stepSize)
            range.append(i);

        return(range);
    }

    if (start > stop) {
        for (uint i = start; i >= stop; i -= stepSize)
            range.append(i);

        return(range);
    }

    // This will never happen
    return(range);
}
QRowVector RsaToolbox::linearSpacing(double start, double stop, int points) {
    QRowVector result;
    linearSpacing(result, start, stop, points);
    return(result);
}
void RsaToolbox::linearSpacing(QRowVector &result, double start, double stop, int points) {
    RowVector std_result;
    linearSpacing(std_result, start, stop, points);
    result = QRowVector::fromStdVector(std_result);
}
void RsaToolbox::linearSpacing(RowVector &result, double start, double stop, int points) {
    result.clear();
    result.resize(points);
    double spacing = (stop - start)/(-1.0 + points);
    for (int i = 0; i < points; i++) {
        result[i] = start + spacing * i;
    }
}
void RsaToolbox::logSpacing(QRowVector &result, double start, double stop, int points) {
    double geoStart = log10(start);
    double geoStop = log10(stop);
    QVector<double> geoPowers;
    linearSpacing(geoPowers, geoStart, geoStop, points);
    result.resize(points);
    for(int i = 0; i < points; i++) {
        result[i] = pow(double(10), geoPowers[i]);
    }
}

bool RsaToolbox::isInfinity(double value) {
    return(value == DBL_INF || value == DBL_NEG_INF);
}
bool RsaToolbox::isNotInfinity(double value) {
    return(!isInfinity(value));
}
bool RsaToolbox::isNaN(double value) {
    return(value != value);
}
bool RsaToolbox::isNotNaN(double value) {
    return(!isNaN(value));
}
double RsaToolbox::roundInf(double value, double toValue) {
    if (toValue < 0)
        toValue = -toValue;

    if (isNaN(value) || isNotInfinity(value))
        return(value);

    if (value == DBL_INF)
        value = toValue;
    else if (value == DBL_NEG_INF)
        value = -toValue;
    return(value);
}
QRowVector RsaToolbox::roundInf(QRowVector values, double toValue) {
    if (toValue < 0)
        toValue = -toValue;

    QRowVector result(values.size());
    int size = values.size();
    for (int i = 0; i < size; i++)
        result[i] = roundInf(values[i], toValue);
    return(result);
}
double RsaToolbox::round(double value) {
    if (value >= 0)
        return(std::floor(value + 0.5));
    else
        return(ceil(value - 0.5));
}
double RsaToolbox::round(double value, uint decimal_places) {
    value *= pow(10.0, (int)decimal_places);
    value = round(value);
    return(value * pow(10.0, -1 * (int)decimal_places));
}
double RsaToolbox::floor(double value, double interval) {
    return(std::floor(value/interval)*interval);
}
double RsaToolbox::ceiling(double value, double interval) {
    return(std::ceil(value/interval)*interval);
}
void RsaToolbox::roundAxis(double min, double max, double interval, double &axis_min, double &axis_max) {
    axis_min = floor(min, interval);
    axis_max = ceiling(max, interval);
}
void RsaToolbox::roundAxis(QRowVector values, double interval, double &axis_min, double &axis_max) {
    roundAxis(min(values), max(values), interval, axis_min, axis_max);
}
void RsaToolbox::roundAxis(RowVector values, double interval, double &axis_min, double &axis_max) {
    roundAxis(min(values), max(values), interval, axis_min, axis_max);
}
double RsaToolbox::linearInterpolateX(double x1, double y1, double x2, double y2, double y_desired) {
    double invSlope = (x2 - x1)/(y2 - y1);
    return(x1 + invSlope*(y_desired - y1));
}
double RsaToolbox::linearInterpolateY(double x1, double y1, double x2, double y2, double x_desired) {
    double slope = (y2 - y1)/(x2 - x1);
    return(y1 + slope*(x_desired - x1));
}
ComplexDouble RsaToolbox::linearInterpolateY(double x1, ComplexDouble y1, double x2, ComplexDouble y2, double x_desired) {
    ComplexDouble slope = (y2 - y1)/(x2 - x1);
    return(y1 + slope*(x_desired - x1));
}
ComplexRowVector RsaToolbox::linearInterpolateReIm(QRowVector x, ComplexRowVector y, QRowVector xDesired) {
    int newPoints = xDesired.size();
    ComplexRowVector result(newPoints);

    int i = 0;
    int oldPoints = x.size();
    for (int j = 1; j < oldPoints; j++) {
        double x1 = x[j-1];
        double x2 = x[j];
        ComplexDouble y1 = y[j-1];
        ComplexDouble y2 = y[j];
        while (i < newPoints && xDesired[i] <= x2) {
            result[i] = linearInterpolateY(x1, y1, x2, y2, xDesired[i]);
            i++;
        }
        if (i >= newPoints)
            break;
    }
    return result;
}
ComplexRowVector RsaToolbox::linearInterpolateMagPhase(QRowVector x, ComplexRowVector y, QRowVector xDesired) {
    int newPoints = xDesired.size();
    ComplexRowVector result(newPoints);

    int i = 0;
    int oldPoints = x.size();
    for (int j = 1; j < oldPoints; j++) {
        double x1 = x[j-1];
        double x2 = x[j];
        double mag1 = abs(y[j-1]);
        double phase1 = angle_rad(y[j-1]);
        double mag2 = abs(y[j]);
        double phase2 = angle_rad(y[j]);

        // Assume no aliasing
        // Take shortest path between points
        if (phase2 - phase1 > PI)
            phase1 += 2*PI;
        else if (phase1 - phase2 > PI)
            phase2 += 2*PI;

        while (i < newPoints && xDesired[i] <= x2) {
            double mag = linearInterpolateY(x1, mag1, x2, mag2, xDesired[i]);
            double phase = linearInterpolateY(x1, phase1, x2, phase2, xDesired[i]);
            result[i] = std::polar(mag, phase);
            i++;
        }
        if (i >= newPoints)
            break;
    }
    return result;
}

ComplexRowVector RsaToolbox::exp(ComplexRowVector x) {
    uint size = x.size();
    for (uint i = 0; i < size; i++)
        x[i] = exp(x[i]);
    return(x);
}
double RsaToolbox::sum(QRowVector x) {
    double sum = 0;
    foreach(double i, x)
        sum += i;
    return(sum);
}
QRowVector RsaToolbox::diff(QRowVector x) {
    uint size = x.size();
    QRowVector result(size-1);
    for (uint i = 1; i < size; i++) {
        result[i-1] = x[i] - x[i-1];
    }
    return(result);
}
QRowVector RsaToolbox::mod(QRowVector x, double denominator) {
    uint size = x.size();
    for (uint i = 0; i < size; i++) {
        x[i]  = x[i] - std::floor(x[i]/denominator) * denominator;
    }
    return(x);
}
QRowVector RsaToolbox::cumulativeSum(QRowVector x) {
    uint size = x.size();
    for (uint i = 1; i < size; i++)
        x[i] = x[i-1] + x[i];
    return(x);
}

QRowVector RsaToolbox::arg(ComplexRowVector x) {
    uint size = x.size();
    QRowVector result(size);
    for (uint i = 0; i < size; i++)
        result[i] = arg(x[i]);
    return(result);
}
QRowVector RsaToolbox::unwrap(QRowVector x, double bounds) {
    uint size = x.size();
    QRowVector difference = diff(x);
    QRowVector diffMod = add(difference,PI);
    diffMod = mod(diffMod, 2.0*PI);
    diffMod = subtract(diffMod, PI);
    for (uint i = 0; i < size-1; i++)
        if (diffMod[i] == -1.0 * PI && difference[i] > 0)
            diffMod[i] = PI;
    QRowVector phaseCorrect = subtract(diffMod, difference);
    for (uint i = 0; i < size-1; i++)
        if (abs(difference[i]) < bounds/2.0)
            phaseCorrect[i] = 0;
    phaseCorrect = cumulativeSum(phaseCorrect);
    for (uint i = 1; i < size; i++)
        x[i] = x[i] + phaseCorrect[i-1];
    return(x);

//    uint size = x.size();
//    double cutoff = bounds/2;
//    for (uint i = 1; i < size; i++) {
//        double difference = x[i] - x[i-1];
//        if (difference > cutoff)
//            x = subtractPropagate(x, i, bounds);
//        else if (difference < -cutoff)
//            x = addPropagate(x, i, bounds);
//    }
//    return(x);
}
QRowVector RsaToolbox::addPropagate(QRowVector x, int startIndex, double value) {
    uint size = x.size();
    for (uint i = startIndex; i < size; i++) {
        x[i] += value;
    }
    return(x);
}
QRowVector RsaToolbox::subtractPropagate(QRowVector x, int startIndex, double value) {
    return(addPropagate(x, startIndex, -1*value));
}

ComplexRowVector RsaToolbox::sqrt(ComplexRowVector x) {
    uint size = x.size();
    ComplexRowVector result(size);
    for (uint i = 0; i < size; i++)
        result[i] = std::sqrt(x[i]);
    return(result);
}

// Helpers
namespace RsaToolbox {
double bValue(double x1, double y1, double x2, double y2) {
    double m = (y2 - y1)/(x2 - x1);
    return(y2 - m*x2);
}
QRowVector bValues(QRowVector x, QRowVector y) {
    int size = std::min(x.size(), y.size());
    QRowVector result(size-1);
    for (int i = 1; i < size; i++)
        result[i-1] = bValue(x[i-1], y[i-1], x[i], y[i]);
    return(result);
}
double weightedAverage(QRowVector values, QRowVector weights) {
    QRowVector result = multiplyEach(values, weights);
    double total = sum(result);
    double weight = sum(weights);
    return(total/weight);
}
}

double RsaToolbox::wrap(double x, double bounds) {
    return(bounds*((x/bounds) - round(x/bounds)));
}
QRowVector RsaToolbox::wrap(QRowVector x, double bounds) {
    uint size = x.size();
    QRowVector result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = wrap(x[i], bounds);
    }
    return(result);
}

double RsaToolbox::phaseAtDc_rad(QRowVector x, ComplexRowVector y) {
    uint size = std::min(uint(x.size()), uint(y.size()));

    // Calculate y-intercept (b of y = mx + b)
    QRowVector phase = arg(y);
    phase = unwrap(phase);
    QRowVector b = bValues(x, phase);

    // Calculate weighted y-intercept
    // (low-x points weight heavier)
    QRowVector weights;
    linearSpacing(weights, 1, 0, size-1);
    double average = weightedAverage(b, weights);
    average = wrap(average);
    return(average);
}
double RsaToolbox::phaseAtDc_deg(QRowVector x, ComplexRowVector y) {
    return(phaseAtDc_rad(x, y) * 180.0/PI);
}
ComplexRowVector RsaToolbox::fixPhaseAtDc(QRowVector x, ComplexRowVector y) {
    double bAvg = phaseAtDc_rad(x, y);
    if (bAvg > PI/2.0) {
        ComplexDouble j(0, 1.0);
        y = multiply(y, exp(-1.0*j*PI));
    }
    else if (bAvg < -1*PI/2.0) {
        ComplexDouble j(0, 1.0);
        y = multiply(y, exp(j*PI));
    }
    return(y);
}
ComplexRowVector RsaToolbox::smoothSqrt(ComplexRowVector x) {
    uint size = x.size();
    ComplexRowVector result = sqrt(x);

    // Smooth
    for (uint i = 1; i < size; i++) {
        ComplexDouble current = result[i];
        ComplexDouble previous = result[i-1];
        double difference = arg(current*conj(previous));
        if (abs(difference) > PI/2)
            result[i] = -1.0*current;
    }
    return(result);
}
ComplexRowVector RsaToolbox::smoothPhase(ComplexRowVector x) {
    uint size = x.size();
    for (uint i = 1; i < size; i++) {
        ComplexDouble current = x[i];
        ComplexDouble previous = x[i-1];
        double difference = arg(current*conj(previous));
        if (abs(difference) > PI/2)
            x[i] = -1.0*current;
    }
    return(x);
}

ComplexRowVector RsaToolbox::conjugate(ComplexRowVector x) {
    uint size = x.size();
    ComplexRowVector result(size);
    for (uint i = 0; i < size; i++)
        result[i] = std::conj(x[i]);
    return(result);
}

ComplexRowVector RsaToolbox::multiply(ComplexRowVector vector, double scalar) {
    uint size = vector.size();
    ComplexRowVector result(size);
    for (uint i = 0; i < size; i++)
        result[i] = vector[i] * scalar;
    return(result);
}
ComplexMatrix2D RsaToolbox::multiply(ComplexMatrix2D matrix, double scalar) {
    int size = matrix.size();
    for (int i = 0; i < size; i++)
        matrix[i] = multiply(matrix[i], scalar);
    return(matrix);
}
ComplexMatrix3D RsaToolbox::multiply(ComplexMatrix3D matrix, double scalar) {
    int size = matrix.size();
    for (int i = 0; i < size; i++)
        matrix[i] = multiply(matrix[i], scalar);
    return(matrix);
}

ComplexRowVector RsaToolbox::multiply(QRowVector vector, ComplexDouble scalar) {
    uint size = vector.size();
    ComplexRowVector x(size);
    for (uint i = 0; i < size; i++)
        x[i] = vector[i];
    return(multiply(x, scalar));
}
ComplexRowVector RsaToolbox::multiply(ComplexRowVector vector, ComplexDouble scalar) {
    uint size = vector.size();
    for (uint i = 0; i < size; i++)
        vector[i] = vector[i] * scalar;
    return(vector);
}

RowVector RsaToolbox::multiply(RowVector vector, double scalar) {
    const int size = vector.size();
    for (int i = 0; i < size; i++)
        vector[i] = vector[i] * scalar;
    return(vector);
}
Matrix2D RsaToolbox::multiply(Matrix2D matrix, double scalar) {
    const int size = matrix.size();
    for (int i = 0; i < size; i++)
        multiply(matrix[i], scalar);
    return(matrix);
}
Matrix3D RsaToolbox::multiply(Matrix3D matrix, double scalar) {
    const int size = matrix.size();
    for (int i = 0; i < size; i++)
        multiply(matrix[i], scalar);
    return(matrix);
}
QRowVector RsaToolbox::multiply(QRowVector vector, double scalar) {
    const int size = vector.size();
    for (int i = 0; i < size; i++)
        vector[i] = vector[i] * scalar;
    return(vector);
}
QMatrix2D RsaToolbox::multiply(QMatrix2D matrix, double scalar) {
    const int size = matrix.size();
    for (int i = 0; i < size; i++)
        multiply(matrix[i], scalar);
    return(matrix);
}
QMatrix3D RsaToolbox::multiply(QMatrix3D matrix, double scalar) {
    const int size = matrix.size();
    for (int i = 0; i < size; i++)
        multiply(matrix[i], scalar);
    return(matrix);
}

ComplexRowVector RsaToolbox::multiplyEach(ComplexRowVector vector1, ComplexRowVector vector2) {
    ComplexRowVector::size_type size = vector1.size();
    if (vector2.size() != size)
        return(ComplexRowVector());

    ComplexRowVector result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = vector1[i] * vector2[i];
    }
    return(result);
}
RowVector RsaToolbox::multiplyEach(RowVector vector1, RowVector vector2) {
    RowVector::size_type size = vector1.size();
    if (vector2.size() != size)
        return(RowVector());

    RowVector result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = vector1[i] * vector2[i];
    }
    return(result);
}
QRowVector RsaToolbox::multiplyEach(QRowVector vector1, QRowVector vector2) {
    int size = vector1.size();
    if (vector2.size() != size)
        return(QRowVector());

    QRowVector result(size);
    for (int i = 0; i < size; i++) {
        result[i] = vector1[i] * vector2[i];
    }
    return(result);
}

ComplexRowVector RsaToolbox::divideEach(ComplexRowVector vector1, ComplexRowVector vector2) {
    ComplexRowVector::size_type size = vector1.size();
    if (vector2.size() != size)
        return(ComplexRowVector());

    ComplexRowVector result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = vector1[i] / vector2[i];
    }
    return(result);
}
RowVector RsaToolbox::divideEach(RowVector vector1, RowVector vector2) {
    RowVector::size_type size = vector1.size();
    if (vector2.size() != size)
        return(RowVector());

    RowVector result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = vector1[i] / vector2[i];
    }
    return(result);
}
QRowVector RsaToolbox::divideEach(QRowVector vector1, QRowVector vector2) {
    int size = vector1.size();
    if (vector2.size() != size)
        return(QRowVector());

    QRowVector result(size);
    for (int i = 0; i < size; i++) {
        result[i] = vector1[i] / vector2[i];
    }
    return(result);
}

ComplexRowVector RsaToolbox::add(ComplexRowVector vector1, ComplexRowVector vector2) {
    ComplexRowVector::size_type size = vector1.size();
    if (vector2.size() != size)
        return(ComplexRowVector());

    ComplexRowVector result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = vector1[i] + vector2[i];
    }
    return(result);
}
ComplexMatrix2D RsaToolbox::add(ComplexMatrix2D matrix1, ComplexMatrix2D matrix2) {
    ComplexRowVector::size_type size = matrix1.size();
    if (matrix2.size() != size)
        return(ComplexMatrix2D());

    ComplexMatrix2D result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = add(matrix1[i], matrix2[i]);
    }
    return(result);
}
ComplexMatrix3D RsaToolbox::add(ComplexMatrix3D matrix1, ComplexMatrix3D matrix2) {
    ComplexRowVector::size_type size = matrix1.size();
    if (matrix2.size() != size)
        return(ComplexMatrix3D());

    ComplexMatrix3D result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = add(matrix1[i], matrix2[i]);
    }
    return(result);
}
RowVector RsaToolbox::add(RowVector vector1, RowVector vector2) {
    RowVector::size_type size = vector1.size();
    if (vector2.size() != size)
        return(RowVector());

    RowVector result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = vector1[i] + vector2[i];
    }
    return(result);
}
Matrix2D RsaToolbox::add(Matrix2D matrix1, Matrix2D matrix2) {
    RowVector::size_type size = matrix1.size();
    if (matrix2.size() != size)
        return(Matrix2D());

    Matrix2D result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = add(matrix1[i], matrix2[i]);
    }
    return(result);
}
Matrix3D RsaToolbox::add(Matrix3D matrix1, Matrix3D matrix2) {
    RowVector::size_type size = matrix1.size();
    if (matrix2.size() != size)
        return(Matrix3D());

    Matrix3D result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = add(matrix1[i], matrix2[i]);
    }
    return(result);
}
QRowVector RsaToolbox::add(QRowVector vector1, QRowVector vector2) {
    int size = vector1.size();
    if (vector2.size() != size)
        return(QRowVector());

    QRowVector result(size);
    for (int i = 0; i < size; i++) {
        result[i] = vector1[i] + vector2[i];
    }
    return(result);
}
QRowVector RsaToolbox::add(QRowVector vector, double scalar) {
    return(add(vector, QRowVector(vector.size(), scalar)));
}

QMatrix2D RsaToolbox::add(QMatrix2D matrix1, QMatrix2D matrix2) {
    int size = matrix1.size();
    if (matrix2.size() != size)
        return(QMatrix2D());

    QMatrix2D result(size);
    for (int i = 0; i < size; i++) {
        result[i] = add(matrix1[i], matrix2[i]);
    }
    return(result);
}
QMatrix3D RsaToolbox::add(QMatrix3D matrix1, QMatrix3D matrix2) {
    int size = matrix1.size();
    if (matrix2.size() != size)
        return(QMatrix3D());

    QMatrix3D result(size);
    for (int i = 0; i < size; i++) {
        result[i] = add(matrix1[i], matrix2[i]);
    }
    return(result);
}

ComplexRowVector RsaToolbox::subtract(ComplexRowVector vector1, ComplexRowVector vector2) {
    std::vector<double>::size_type size = vector1.size();
    if (vector2.size() != size)
        return(ComplexRowVector());

    ComplexRowVector result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = vector1[i] - vector2[i];
    }
    return(result);
}
ComplexMatrix2D RsaToolbox::subtract(ComplexMatrix2D matrix1, ComplexMatrix2D matrix2) {
    std::vector<double>::size_type size = matrix1.size();
    if (matrix2.size() != size)
        return(ComplexMatrix2D());

    ComplexMatrix2D result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = subtract(matrix1[i], matrix2[i]);
    }
    return(result);
}
ComplexMatrix3D RsaToolbox::subtract(ComplexMatrix3D matrix1, ComplexMatrix3D matrix2) {
    std::vector<double>::size_type size = matrix1.size();
    if (matrix2.size() != size)
        return(ComplexMatrix3D());

    ComplexMatrix3D result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = subtract(matrix1[i], matrix2[i]);
    }
    return(result);
}
RowVector RsaToolbox::subtract(RowVector vector1, RowVector vector2) {
    std::vector<double>::size_type size = vector1.size();
    if (vector2.size() != size)
        return(RowVector());

    RowVector result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = vector1[i] - vector2[i];
    }
    return(result);
}
Matrix2D RsaToolbox::subtract(Matrix2D matrix1, Matrix2D matrix2) {
    std::vector<double>::size_type size = matrix1.size();
    if (matrix2.size() != size)
        return(Matrix2D());

    Matrix2D result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = subtract(matrix1[i], matrix2[i]);
    }
    return(result);
}
Matrix3D RsaToolbox::subtract(Matrix3D matrix1, Matrix3D matrix2) {
    std::vector<double>::size_type size = matrix1.size();
    if (matrix2.size() != size)
        return(Matrix3D());

    Matrix3D result(size);
    for (uint i = 0; i < size; i++) {
        result[i] = subtract(matrix1[i], matrix2[i]);
    }
    return(result);
}
QRowVector RsaToolbox::subtract(QRowVector vector1, QRowVector vector2) {
    int size = vector1.size();
    if (vector2.size() != size)
        return(QRowVector());

    QRowVector result(size);
    for (int i = 0; i < size; i++) {
        result[i] = vector1[i] - vector2[i];
    }
    return(result);
}
QRowVector RsaToolbox::subtract(QRowVector vector, double scalar) {
    return(subtract(vector, QRowVector(vector.size(), scalar)));
}
QMatrix2D RsaToolbox::subtract(QMatrix2D matrix1, QMatrix2D matrix2) {
    int size = matrix1.size();
    if (matrix2.size() != size)
        return(QMatrix2D());

    QMatrix2D result(size);
    for (int i = 0; i < size; i++) {
        result[i] = subtract(matrix1[i], matrix2[i]);
    }
    return(result);
}
QMatrix3D RsaToolbox::subtract(QMatrix3D matrix1, QMatrix3D matrix2) {
    int size = matrix1.size();
    if (matrix2.size() != size)
        return(QMatrix3D());

    QMatrix3D result(size);
    for (int i = 0; i < size; i++) {
        result[i] = subtract(matrix1[i], matrix2[i]);
    }
    return(result);
}
ComplexMatrix2D RsaToolbox::transpose(ComplexMatrix2D matrix) {
    uint rows = matrix.size();
    if (rows == 0)
        return(ComplexMatrix2D());

    uint columns = matrix[0].size();
    if (columns == 0)
        return(ComplexMatrix2D());

    ComplexMatrix2D result = matrix;
    for (uint i = 0; i < rows; i++) {
        if (matrix[i].size() != columns)
            return(ComplexMatrix2D());
        for (uint j = 0; j < columns; j++) {
            result[i][j] = matrix[j][i];
            result[j][i] = matrix[i][j];
        }
    }
    return(result);
}
QMatrix2D RsaToolbox::transpose(QMatrix2D matrix) {
    int rows = matrix.size();
    if (rows == 0)
        return(QMatrix2D());

    int columns = matrix[0].size();
    if (columns == 0)
        return(QMatrix2D());

    QMatrix2D result = matrix;
    for (int i = 0; i < rows; i++) {
        if (matrix[i].size() != columns)
            return(QMatrix2D());
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix[j][i];
            result[j][i] = matrix[i][j];
        }
    }
    return(result);
}

void RsaToolbox::resize(ComplexMatrix2D &matrix, uint rows, uint columns) {
    if (rows <= 0 || columns <= 0)
        return;

    matrix.resize(rows);
    for (uint i = 0; i < rows; i++)
        matrix[i].resize(columns);
}
void RsaToolbox::resize(ComplexMatrix3D &matrix, uint dimension1, uint dimension2, uint dimension3) {
    if (dimension1 <= 0 || dimension2 <= 0 || dimension3 <= 0)
        return;
    matrix.resize(dimension1);
    for (uint i = 0; i < dimension1; i++)
        resize(matrix[i], dimension2, dimension3);
}

ComplexRowVector RsaToolbox::serialize(const ComplexMatrix2D &matrix) {
    ComplexRowVector result;
    uint rows = matrix.size();
    uint columns;
    for (uint i = 0; i < rows; i++) {
        columns = matrix[i].size();
        for (uint j = 0; j < columns; j++) {
            result.push_back(matrix[i][j]);
        }
    }
    return(result);
}
ComplexMatrix2D RsaToolbox::toComplexMatrix2D(const ComplexRowVector &data, uint rows, uint columns) {
    ComplexMatrix2D matrix;
    if (rows <= 0 || columns <= 0 || data.size() != rows*columns)
        return(matrix);

    resize(matrix, rows, columns);
    uint n = 0;
    for (uint i = 0; i < rows; i++)
        for (uint j = 0; j < columns; j++)
            matrix[i][j] = data[n++];
    return(matrix);
}
ComplexMatrix3D RsaToolbox::toComplexMatrix3D(const ComplexRowVector &data, uint dimension1, uint dimension2, uint dimension3) {
    ComplexMatrix3D matrix;
    if (dimension1 <= 0 || dimension2 <= 0 || dimension3 <= 0
            || data.size() != dimension1*dimension2*dimension3)
        return(matrix);

    resize(matrix, dimension1, dimension2, dimension3);
    uint n = 0;

    for (uint j = 0; j < dimension2; j++)
        for (uint k = 0; k < dimension3; k++)
            for (uint i = 0; i < dimension1; i++)
                matrix[i][j][k] = data[n++];
    return(matrix);
}

ComplexMatrix2D RsaToolbox::subsection(ComplexMatrix2D matrix, QVector<uint> rows, QVector<uint> columns) {
    ComplexMatrix2D result;

    uint numberOfRows = rows.size();
    uint numberOfColumns = columns.size();

    result.resize(numberOfRows);
    for (uint i = 0; i < numberOfRows; i++) {
        result[i].resize(numberOfColumns);
        for (uint j = 0; j < numberOfColumns; j++) {
            uint row = rows[i];
            uint col = columns[j];
            result[i][j] = matrix[row][col];
        }
    }
    return(result);
}
ComplexMatrix2D RsaToolbox::subsection(ComplexMatrix2D matrix, QVector<uint> indices) {
    return(subsection(matrix, indices, indices));
}
void RsaToolbox::insert(ComplexMatrix2D &matrix, ComplexMatrix2D data, QVector<uint> toRows, QVector<uint> toColumns) {
    uint numberOfRows = toRows.size();
    uint numberOfColumns = toColumns.size();
    for (uint i = 0; i < numberOfRows; i++) {
        for (uint j = 0; j < numberOfColumns; j++) {
            uint row = toRows[i];
            uint col = toColumns[i];
            matrix[row][col] = data[i][j];
        }
    }
}
void RsaToolbox::insert(ComplexMatrix2D &matrix, ComplexMatrix2D data, QVector<uint> indices) {
    insert(matrix, data, indices, indices);
}


// Data type stream operators
QDataStream& operator<<(QDataStream &stream, ComplexDouble value) {
    stream << value.real();
    stream << value.imag();
    return(stream);
}
QDataStream& operator<<(QDataStream &stream, RsaToolbox::ComplexRowVector vector) {
    quint64 size = vector.size();
    stream << size;
    for (ComplexRowVector::size_type i = 0; i < size; i++)
        stream << vector[i];
    return(stream);
}
QDataStream& operator<<(QDataStream &stream, RsaToolbox::ComplexMatrix2D matrix) {
    quint64 size = matrix.size();
    stream << size;
    for (ComplexMatrix2D::size_type i = 0; i < size; i++)
        stream << matrix[i];
    return(stream);
}
QDataStream& operator<<(QDataStream &stream, RsaToolbox::ComplexMatrix3D matrix) {
    quint64 size = matrix.size();
    stream << size;
    for (ComplexMatrix3D::size_type i = 0; i < size; i++)
        stream << matrix[i];
    return(stream);
}

QDataStream& operator>>(QDataStream &stream, ComplexDouble &value) {
    double real, imag;
    stream >> real;
    stream >> imag;
    value = ComplexDouble(real, imag);
    return(stream);
}
QDataStream& operator>>(QDataStream &stream, RsaToolbox::ComplexRowVector &vector) {
    quint64 size;
    stream >> size;
    vector.resize(size);
    for (ComplexRowVector::size_type i = 0; i < size; i++)
        stream >> vector[i];
    return(stream);
}
QDataStream& operator>>(QDataStream &stream, RsaToolbox::ComplexMatrix2D &matrix) {
    quint64 size;
    stream >> size;
    matrix.resize(size);
    for (ComplexMatrix2D::size_type i = 0; i < size; i++)
        stream >> matrix[i];
    return(stream);
}
QDataStream& operator>>(QDataStream &stream, RsaToolbox::ComplexMatrix3D &matrix) {
    quint64 size;
    stream >> size;
    matrix.resize(size);
    for (ComplexMatrix3D::size_type i = 0; i < size; i++)
        stream >> matrix[i];
    return(stream);
}
