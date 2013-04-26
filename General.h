#ifndef GENERAL_H
#define GENERAL_H

// Rsa
#include "Definitions.h"

// Qt
#include <QDir>
#include <QString>

// C++ std lib
#include <complex>
#include <vector>

namespace RsaToolbox {

// Enum conversions
double ToDouble(SiPrefix prefix);

QString ToString(SiPrefix prefix);
QString ToString(Units units);
QString ToString(ComplexFormat format);
QString ToString(NetworkParameter parameter);
QString ToString(VnaModel model);
QString ToStateFileExtension(VnaModel model);

const char* ToScpi(ReferenceLevel reference_level);
const char* ToScpi(ColorScheme scheme);
const char* ToScpi(TraceFormat format);
const char* ToScpi(SweepType sweep_type);

SiPrefix String_To_SiPrefix(QString prefix);

TraceFormat Scpi_To_TraceFormat(QString scpi);
ColorScheme Scpi_To_ColorScheme(QString scpi);
NetworkParameter Scpi_To_NetworkParameter(QString scpi);
ReferenceLevel Scpi_To_ReferenceLevel(QString scpi);
SweepType Scpi_To_SweepType(QString scpi);

// File system
QString AppendPath(QDir path, QString filename);
QString AppendCurrentDirectory(QString filename);
QString GetAppDataPath(QString program_folder);
QString AppendAppDataPath(QString program_folder, QString filename);

// Formatting Functions
QString FormatValue(double value, int decimalPlaces, Units units, SiPrefix prefix = NO_PREFIX);

// Math
double ToDb(double value);
double ToDb(std::complex<double> value);
double ToMagnitude(double decibels);

}
#endif // GENERAL_H
