#ifndef GENERAL_H
#define GENERAL_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QDir>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QMap>
#include <QMapIterator>
#include <QTextStream>
#include <QDataStream>

// C++ std lib
#include <cfloat>
#include <complex>
#include <vector>
#include <type_traits>
#include <limits>


namespace RsaToolbox {

QString uniqueAlphanumericString();

// Enum conversions
double toDouble(SiPrefix prefix);
QString toString(NetworkParameter parameter);
QString toString(NetworkParameter parameter, uint outputPort, uint inputPort);
QString toString(WaveQuantity wave);
QString toString(ComplexFormat format);

QString toString(ImageFormat format);
ImageFormat toImageFormat(QString s);


QString toString(SiPrefix prefix);
QString toString(Units units);
QString toString(SiPrefix prefix, Units units);
SiPrefix toSiPrefix(QString prefix);
SiPrefix toSiPrefix(QChar prefix);
SiPrefix toSiPrefix(char prefix);
SiPrefix getPrefix(double value);


// File system
QString GetAppDataPath(QString manufacturerFolder, QString applicationFolder);

// Formatting Functions
void chopTrailingZeros(QString &text);
QString toEngineeringNotation(double value, int decimalPlaces, SiPrefix prefix = SiPrefix::None);
QString formatValue(double value, int decimalPlaces, Units units, SiPrefix prefix = SiPrefix::None);
QString formatDouble(double value, int decimalPlaces);
template <class T>
QStringList toStringList(QVector<T> vector) {
    int size = vector.size();
    QStringList string_list;
    for (int i = 0; i < size; i++)
        string_list << QVariant(vector[i]).toString();
    return(string_list);
}
template <class T>
QString toString(QVector<T> vector, QString separator) {
    int size = vector.size();
    if (size == 0)
        return("");
    // else
    QString list = QVariant(vector[0]).toString();
    for (int i = 1; i < size; i++) {
        list.append(separator);
        list.append(QVariant(vector[i]).toString());
    }
    return(list);
}
QString toString(QStringList list, QString separator);
QString toString(ComplexRowVector vector, QString separator, QString format = "(%1, %2)");
QStringList portLabels(QVector<uint> ports);
QString portString(QVector<uint> ports);
QStringList channelLabels(QVector<uint> channels);

// Parse
QVector<uint> parseUints(QString values, QString separator, QString ignore = "");
QVector<int> parseInts(QString values, QString separator, QString ignore = "");
QRowVector parseDoubles(QString values, QString separator, QString ignore = "");
ComplexRowVector parseComplex(QString values, QString separator, QString ignore = "");
ComplexRowVector parseComplex(QRowVector values);
QRowVector parseQRowVector(QString buffer);
QRowVector parseQRowVector(ComplexRowVector values);
template <class T1, class T2>
QMap<T1, T2> parseMap(QString values, QString separator, QString ignore = "", QString::SplitBehavior splitBehavior = QString::KeepEmptyParts) {
    QMap<T1, T2> map;
    if (!ignore.isEmpty())
        values = values.remove(ignore);
    QStringList results = values.split(separator, splitBehavior);
    int size = results.size();
    if (size % 2 != 0)
        return map;

    for (int i = 0; i < size; i+=2) {
        T1 key = QVariant(results[i]).value<T1>();
        T2 value = QVariant(results[i+1]).value<T2>();
        map.insert(key, value);
    }
    return map;
}

QByteArray toBlockDataFormat(QRowVector values);
QRowVector toQRowVector(QByteArray blockData);
QByteArray toBlockDataFormat(ComplexRowVector values);
ComplexRowVector toComplexRowVector(QByteArray blockData);

// Conversions
double toDb(double magnitude);
QRowVector toDb(QRowVector magnitudes);
double toDb(ComplexDouble complexValue);
QRowVector toDb(ComplexRowVector complexValues);

double toMagnitude(double decibels);
double toMagnitude(ComplexDouble complexValue);
QRowVector toMagnitude(QRowVector values_dB);
QRowVector toMagnitude(ComplexRowVector complexValues);

double degrees(double phase_rad);
QRowVector degrees(QRowVector phases_rad);
double angle_deg(ComplexDouble complexValue);
QRowVector angle_deg(ComplexRowVector complexValues);

double radians(double phase_deg);
QRowVector radians(QRowVector phases_deg);
double angle_rad(ComplexDouble complexValue);
QRowVector angle_rad(ComplexRowVector complexValues);

double toVswr(double magnitude);
QRowVector toVswr(QRowVector magnitudes);
double toVswr(ComplexDouble complexValue);
QRowVector toVswr(ComplexRowVector complexValues);

QRowVector real(ComplexRowVector complexValues);
QRowVector imaginary(ComplexRowVector complexValues);

ComplexDouble fromRealImag(double real, double imag);
ComplexDouble fromMagRadians(double magnitude, double angle_rad);
ComplexDouble fromMagDegrees(double magnitude, double angle_deg);
ComplexDouble fromDbDegrees(double dB, double angle_deg);

QVector<int> range(int start, int stop, int stepSize = 1);
QVector<uint> range(uint start, uint stop, uint stepSize = 1);
QRowVector linearSpacing(double start, double stop, int points);
void linearSpacing(QRowVector &result, double start, double stop, int points);
void linearSpacing(RowVector &result, double start, double stop, int points);
QRowVector logSpacing(double start, double stop, int points);
void logSpacing(QRowVector &result, double start, double stop, int points);

bool isInfinity(double value);
bool isNotInfinity(double value);
bool isNaN(double value);
bool isNotNaN(double value);
double roundInf(double value, double toValue = DBL_MAX);
QRowVector roundInf(QRowVector values, double toValue = DBL_MAX);
double round(double value);
double round(double value, uint decimals);
double floor(double value, double interval);
double ceiling(double value, double interval);
double findClosest(double value, QRowVector values);

void roundAxis(double min, double max, double interval, double &axis_min, double &axis_max);
void roundAxis(QRowVector values, double interval, double &axis_min, double &axis_max);
void roundAxis(RowVector values, double interval, double &axis_min, double &axis_max);
void prettyAxis(double &min, double &max, double &tickStep, int &subTickCount);

double linearInterpolateX(double x1, double y1, double x2, double y2, double y_desired);
double linearInterpolateY(double x1, double y1, double x2, double y2, double x_desired);
QRowVector linearInterpolateY(QRowVector x, QRowVector y, QRowVector xDesired);
ComplexDouble linearInterpolateY(double x1, ComplexDouble y1, double x2, ComplexDouble y2, double x_desired);
ComplexDouble linearInterpolateYMagPhase(double x1, ComplexDouble y1, double x2, ComplexDouble y2, double x_desired);
ComplexMatrix2D linearInterpolateYMagPhase(double x1, ComplexMatrix2D y1, double x2, ComplexMatrix2D y2, double x_desired);
ComplexRowVector linearInterpolateReIm(QRowVector x, ComplexRowVector y, QRowVector xDesired);
ComplexRowVector linearInterpolateMagPhase(QRowVector x, ComplexRowVector y, QRowVector xDesired);

ComplexRowVector exp(ComplexRowVector x);
double sum(QRowVector x);
QRowVector diff(QRowVector x);
QRowVector mod(QRowVector x, double denominator);
QRowVector cumulativeSum(QRowVector x);
QRowVector arg(ComplexRowVector x);
double wrap(double x, double bounds = 2.0*PI);
QRowVector wrap(QRowVector x, double bounds = 2.0*PI);
QRowVector unwrap(QRowVector x, double bounds = 2.0*PI);
double phaseAtDc_rad(QRowVector x, ComplexRowVector y);
double phaseAtDc_deg(QRowVector x, ComplexRowVector y);
ComplexRowVector fixPhaseAtDc(QRowVector x, ComplexRowVector y);
QRowVector addPropagate(QRowVector x, int startIndex, double value);
QRowVector subtractPropagate(QRowVector x, int startIndex, double value);

ComplexRowVector sqrt(ComplexRowVector x);
ComplexRowVector smoothSqrt(ComplexRowVector x);
ComplexRowVector smoothPhase(ComplexRowVector x);
ComplexRowVector conjugate(ComplexRowVector x);

ComplexRowVector multiply(ComplexRowVector vector, double scalar);
ComplexMatrix2D multiply(ComplexMatrix2D matrix, double scalar);
ComplexMatrix3D multiply(ComplexMatrix3D matrix, double scalar);

ComplexRowVector multiply(QRowVector vector, ComplexDouble scalar);
ComplexRowVector multiply(ComplexRowVector vector, ComplexDouble scalar);

RowVector multiply(RowVector vector, double scalar);
Matrix2D multiply(Matrix2D matrix, double scalar);
Matrix3D multiply(Matrix3D matrix, double scalar);
QRowVector multiply(QRowVector vector, double scalar);
QMatrix2D multiply(QMatrix2D matrix, double scalar);
QMatrix3D multiply(QMatrix3D matrix, double scalar);

ComplexRowVector multiplyEach(ComplexRowVector vector1, ComplexRowVector vector2);
RowVector multiplyEach(RowVector vector1, RowVector vector2);
QRowVector multiplyEach(QRowVector vector1, QRowVector vector2);

ComplexRowVector divideEach(ComplexRowVector vector1, ComplexRowVector vector2);
RowVector divideEach(RowVector vector1, RowVector vector2);
QRowVector divideEach(QRowVector vector1, QRowVector vector2);

ComplexRowVector add(ComplexRowVector vector1, ComplexRowVector vector2);
ComplexMatrix2D add(ComplexMatrix2D matrix1, ComplexMatrix2D matrix2);
ComplexMatrix3D add(ComplexMatrix3D matrix1, ComplexMatrix3D matrix2);
RowVector add(RowVector vector1, RowVector vector2);
Matrix2D add(Matrix2D matrix1, Matrix2D matrix2);
Matrix3D add(Matrix3D matrix1, Matrix3D matrix2);
QRowVector add(QRowVector vector1, QRowVector vector2);
QRowVector add(QRowVector vector, double scalar);
QMatrix2D add(QMatrix2D matrix1, QMatrix2D matrix2);
QMatrix3D add(QMatrix3D matrix1, QMatrix3D matrix2);

ComplexRowVector subtract(ComplexRowVector vector1, ComplexRowVector vector2);
ComplexMatrix2D subtract(ComplexMatrix2D matrix1, ComplexMatrix2D matrix2);
ComplexMatrix3D subtract(ComplexMatrix3D matrix1, ComplexMatrix3D matrix2);
RowVector subtract(RowVector vector1, RowVector vector2);
Matrix2D subtract(Matrix2D matrix1, Matrix2D matrix2);
Matrix3D subtract(Matrix3D matrix1, Matrix3D matrix2);
QRowVector subtract(QRowVector vector1, QRowVector vector2);
QRowVector subtract(QRowVector vector, double scalar);
QMatrix2D subtract(QMatrix2D matrix1, QMatrix2D matrix2);
QMatrix3D subtract(QMatrix3D matrix1, QMatrix3D matrix2);

ComplexMatrix2D transpose(ComplexMatrix2D matrix);
QMatrix2D transpose(QMatrix2D matrix);

void resize(ComplexMatrix2D &matrix, uint rows, uint columns);
void resize(ComplexMatrix3D &matrix, uint dimension1, uint dimension2, uint dimension3);
ComplexRowVector serialize(ComplexMatrix2D const &matrix);
ComplexMatrix2D toComplexMatrix2D(ComplexRowVector const &data, uint rows, uint columns);
ComplexMatrix3D toComplexMatrix3D(ComplexRowVector const &data, uint dimension1, uint dimension2, uint dimension3);

ComplexMatrix2D subsection(ComplexMatrix2D matrix, QVector<uint> rows, QVector<uint> columns);
ComplexMatrix2D subsection(ComplexMatrix2D matrix, QVector<uint> indices);
void insert(ComplexMatrix2D &matrix, ComplexMatrix2D data, QVector<uint> toRows, QVector<uint> toColumns);
void insert(ComplexMatrix2D &matrix, ComplexMatrix2D data, QVector<uint> indices);

template <class T, class U, class V>
QMap<T,V> cascade(QMap<T,U> a, QMap<U,V> b) {
    QMap<T,V> result;
    QMapIterator<T,U> i(a);
    while (i.hasNext()) {
        i.next();
        if (b.contains(i.value()))
            result[i.key()] = b.value(i.value());
    }
    return(result);
}

template <class T>
T max(QVector<T> vector) {
    if (vector.size() == 0)
        return(std::numeric_limits<T>::min());

    T _max = vector.first();
    for (int i = 1; i < vector.size(); i++) {
        if (vector[i] > _max)
            _max = vector[i];
    }
    return(_max);
}
template <class T>
void max(QVector<T> vector, T &maximum, int &index) {
    if (vector.size() == 0)
        return;

    maximum = vector.first();
    index = 0;
    for (int i = 1; i < vector.size(); i++) {
        if (vector[i] > maximum) {
            maximum = vector[i];
            index = i;
        }
    }
}

template <class T>
T max(std::vector<T> vector) {
    if (vector.size() == 0)
        return(std::numeric_limits<T>::min());

    T _max = vector[0];
    for (uint i = 1; i < vector.size(); i++) {
        if (vector[i] > _max)
            _max = vector[i];
    }
    return(_max);
}
template <class T>
void max(std::vector<T> vector, T &maximum, int &index) {
    if (vector.size() == 0)
        return;

    maximum = vector[0];
    index = 0;
    for (uint i = 1; i < vector.size(); i++) {
        if (vector[i] > maximum) {
            maximum = vector[i];
            index = i;
        }
    }
}

template <class T>
T min(QVector<T> vector) {
    if (vector.size() == 0)
        return(std::numeric_limits<T>::max());

    T _min = vector.first();
    for (int i = 1; i < vector.size(); i++) {
        if (vector[i] < _min)
            _min = vector[i];
    }
    return(_min);
}
template <class T>
void min(QVector<T> vector, T &minimum, int &index) {
    if (vector.size() == 0)
        return;

    minimum = vector.first();
    index = 0;
    for (int i = 1; i < vector.size(); i++) {
        if (vector[i] < minimum) {
            minimum = vector[i];
            index = i;
        }
    }
}

template <class T>
T min(std::vector<T> vector) {
    if (vector.size() == 0)
        return(std::numeric_limits<T>::max());

    T _min = vector[0];
    for (uint i = 1; i < vector.size(); i++) {
        if (vector[i] < _min)
            _min = vector[i];
    }
    return(_min);
}
template <class T>
T min(std::vector<T> vector, T &minimum, int &index) {
    if (vector.size() == 0)
        return;

    minimum = vector[0];
    index = 0;
    for (uint i = 1; i < vector.size(); i++) {
        if (vector[i] < minimum) {
            minimum = vector[i];
            index = 0;
        }
    }
    return(minimum);
}
}

// Enum serialization
//QDataStream &operator<<(QDataStream &stream, const RsaToolbox::Units &units);
//QDataStream &operator<<(QDataStream &stream, const RsaToolbox::SiPrefix &prefix);

//QDataStream &operator>>(QDataStream &stream, RsaToolbox::Units &units);
//QDataStream &operator>>(QDataStream &stream, RsaToolbox::SiPrefix &prefix);

//// Enum text stream operators
//QTextStream &operator<<(QTextStream &stream, const RsaToolbox::Units &units);
//QTextStream &operator<<(QTextStream &stream, const RsaToolbox::SiPrefix &prefix);


// Using templates:
template <class T>
QDataStream& operator<<(QDataStream &stream, const T &t) {
    static_assert(std::is_enum<T>::value, "Template type is not enum.");
    stream << qint32(t);
    return stream;
}
template <class T>
QDataStream& operator>>(QDataStream &stream, T &t) {
    static_assert(std::is_enum<T>::value, "Template type is not enum.");
    qint32 value;
    stream >> value;
    t = T(value);
    return stream;
}

template <class T>
QTextStream& operator<<(QTextStream &stream, const T &t) {
    static_assert(std::is_enum<T>::value, "Template type is not enum.");
    stream << toString(t);
    return stream;
}


// Data type stream operators
QDataStream& operator<<(QDataStream &stream, RsaToolbox::ComplexDouble value);
QDataStream& operator<<(QDataStream &stream, RsaToolbox::ComplexRowVector vector);
QDataStream& operator<<(QDataStream &stream, RsaToolbox::ComplexMatrix2D matrix);
QDataStream& operator<<(QDataStream &stream, RsaToolbox::ComplexMatrix3D matrix);

QDataStream& operator>>(QDataStream &stream, RsaToolbox::ComplexDouble &value);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::ComplexRowVector &vector);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::ComplexMatrix2D &matrix);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::ComplexMatrix3D &matrix);


#endif // GENERAL_H
