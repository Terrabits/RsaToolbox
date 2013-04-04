#ifndef GENERAL_H
#define GENERAL_H

// Rsa
#include "Definitions.h"

// Qt
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

// Formatting Functions
QString FormatValue(double value, int decimalPlaces, Units units, SiPrefix prefix = NO_PREFIX);

// Math
double ToDb(double value);
double ToDb(std::complex<double> value);
double ToMagnitude(double decibels);

}

#endif // GENERAL_H
