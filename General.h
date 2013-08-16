#ifndef GENERAL_H
#define GENERAL_H


// Rsa
#include "Definitions.h"

// Qt
#include <QDir>
#include <QString>
#include <QStringList>
#include <QVariant>

// C++ std lib
#include <complex>
#include <vector>

namespace RsaToolbox {

// Enum conversions
double ToDouble(SiPrefix prefix);
QString ToString(SweepType sweep_type);
QString ToString(ComplexFormat format);
QString ToString(NetworkParameter parameter);
QString ToString(SiPrefix prefix);
QString ToString(Units units);
QString ToString(ConnectionType connection_type);
QString ToString(VnaModel model);
QString ToSetFileExtension(VnaModel model);
ConnectionType String_To_ConnectionType(QString string);
SiPrefix String_To_SiPrefix(QString prefix);
SweepType String_To_SweepType(QString sweep_type);

// File system
QString AppendPath(QDir path, QString filename);
QString AppendCurrentDirectory(QString filename);
QString GetAppDataPath(QString program_folder);
QString AppendAppDataPath(QString program_folder, QString filename);

// Formatting Functions
QString FormatValue(double value, int decimal_places, Units units, SiPrefix prefix = NO_PREFIX);
QString FormatDouble(double value, int decimal_places);
template <class T>
QStringList ToStringList(QVector<T> vector) {
    int size = vector.size();
    QStringList string_list;
    for (int i = 0; i < size; i++)
        string_list << QVariant(vector[i]).toString();
    return(string_list);
}
template <class T>
QString ToString(QVector<T> vector, QString separator) {
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
QString ToString(QStringList list, QString separator);
QString ToString(ComplexRowVector vector, QString list_separator, const char *complex_format = "%f,%f");

// Math
double ToDb(double value);
QRowVector ToDb(QRowVector vector);
double ToDb(std::complex<double> value);
double ToMagnitude(double decibels);
QRowVector ToMagnitude(QRowVector vector);
QVector<int> Range(int start, int stop);
void LinearSpacing(QRowVector &result, double start, double stop, int points);
void LinearSpacing(RowVector &result, double start, double stop, int points);
double LinearInterpolateX(double x1, double y1, double x2, double y2, double y_desired);
double LinearInterpolateY(double x1, double y1, double x2, double y2, double x_desired);
RowVector ScalarMultiply(RowVector vector, double scalar);
Matrix2D ScalarMultiply(Matrix2D matrix, double scalar);
Matrix3D ScalarMultiply(Matrix3D matrix, double scalar);
QRowVector ScalarMultiply(QRowVector vector, double scalar);
QMatrix2D ScalarMultiply(QMatrix2D matrix, double scalar);
QMatrix3D ScalarMultiply(QMatrix3D matrix, double scalar);

template <class T>
T Max(QVector<T> vector) {
    if (vector.size() == 0)
        return(NULL);
    
    T max = vector.first();
    for (int i = 1; i < vector.size(); i++) {
        if (vector[i] > max)
            max = vector[i];
    }
    return(max);
}
template <class T>
T Min(QVector<T> vector) {
    if (vector.size() == 0)
        return(NULL);
    
    T min = vector.first();
    for (int i = 1; i < vector.size(); i++) {
        if (vector[i] < min)
            min = vector[i];
    }
    return(min);
}

}


#endif // GENERAL_H

