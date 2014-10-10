#ifndef GENERAL_H
#define GENERAL_H


// Rsa
#include "Definitions.h"

// Qt
#include <QDir>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QMap>
#include <QMapIterator>

// C++ std lib
#include <complex>
#include <vector>

namespace RsaToolbox {

// Enum conversions
double toDouble(SiPrefix prefix);
QString toString(ComplexFormat format);
QString toString(NetworkParameter parameter);
QString toString(NetworkParameter parameter, uint outputPort, uint inputPort);
QString toString(SiPrefix prefix);
QString toString(Units units);
QString toString(SiPrefix prefix, Units units);
SiPrefix toSiPrefix(QString prefix);
SiPrefix getPrefix(double value);


// File system
QString AppendPath(QDir path, QString filename);
QString AppendCurrentDirectory(QString filename);
QString GetAppDataPath(QString program_folder);
QString AppendAppDataPath(QString program_folder, QString filename);

// Formatting Functions
QString toScientificNotation(double value, int decimal_places, SiPrefix prefix = NO_PREFIX);
QString formatValue(double value, int decimal_places, Units units, SiPrefix prefix = NO_PREFIX);
QString formatDouble(double value, int decimal_places);
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
QString toString(ComplexRowVector vector, QString list_separator, QString format = "(%1, %2)");
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
ComplexDouble fromMagDegrees(double magnitude, double angle_deg);
ComplexDouble fromDbDegrees(double dB, double angle_deg);

QVector<int> range(int start, int stop, int stepSize = 1);
QVector<uint> range(uint start, uint stop, uint stepSize = 1);
QRowVector linearSpacing(double start, double stop, int points);
void linearSpacing(QRowVector &result, double start, double stop, int points);
void linearSpacing(RowVector &result, double start, double stop, int points);
void logSpacing(QRowVector &result, double start, double stop, int points);

bool isInfinity(double value);
bool isNotInfinity(double value);
bool isNaN(double value);
bool isNotNaN(double value);
double roundInf(double value, double toValue = DBL_MAX);
QRowVector roundInf(QRowVector values, double toValue = DBL_MAX);
double round(double value);
double round(double value, uint decimal_places);
double floor(double value, double interval);
double ceiling(double value, double interval);

void roundAxis(double min, double max, double interval, double &axis_min, double &axis_max);
void roundAxis(QRowVector values, double interval, double &axis_min, double &axis_max);
void roundAxis(RowVector values, double interval, double &axis_min, double &axis_max);

double linearInterpolateX(double x1, double y1, double x2, double y2, double y_desired);
double linearInterpolateY(double x1, double y1, double x2, double y2, double x_desired);
ComplexDouble linearInterpolateY(double x1, ComplexDouble y1, double x2, ComplexDouble y2, double x_desired);
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
        return(NULL);

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
        return(NULL);

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
        return(NULL);

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
        return(NULL);

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

QDataStream& operator<<(QDataStream &stream, RsaToolbox::ComplexDouble value);
QDataStream& operator<<(QDataStream &stream, RsaToolbox::ComplexRowVector vector);
QDataStream& operator<<(QDataStream &stream, RsaToolbox::ComplexMatrix2D matrix);
QDataStream& operator<<(QDataStream &stream, RsaToolbox::ComplexMatrix3D matrix);

QDataStream& operator>>(QDataStream &stream, RsaToolbox::ComplexDouble &value);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::ComplexRowVector &vector);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::ComplexMatrix2D &matrix);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::ComplexMatrix3D &matrix);


#endif // GENERAL_H
