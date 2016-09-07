#ifndef DEFINITIONS_H
#define DEFINITIONS_H


// Qt
#include <QString>
#include <QMetaType>
#include <QVector>
#include <QMap>

// C++
#include <complex>
#include <vector>
#include <limits>


namespace RsaToolbox {

// Constants
const QString RSATOOLBOX_VERSION = "0.10.0";
const QString COMPANY_FOLDER = "Rohde-Schwarz";
const double PI = 3.14159265358979323846264338327950288419716939937510;
const double  E = 2.71828182845904523536028747135266249775724709369995;
const double DBL_INF = std::numeric_limits<double>::infinity();
const double DBL_NEG_INF = -DBL_INF;
const double DBL_NAN = std::numeric_limits<double>::quiet_NaN();

// Enums
// To be enum class with C++ 11
enum /*class*/ NetworkParameter {
    S = 0,
    Y,
    Z,
    H,
    G
};

enum /*class*/ WaveQuantity {
    a = 0,
    b
};

enum /*class*/ ReferenceLevel {
    Relative,
    Absolute
};

enum /*class*/ TraceFormat {
    DecibelMagnitude,
    Phase,
    SmithChart,
    PolarChart,
    Vswr,
    UnwrappedPhase,
    Magnitude,
    InverseSmithChart,
    Real,
    Imaginary,
    Delay
};

enum /*class*/ ImageFormat {
    Bmp,
    Jpg,
    Png,
    Pdf,
    Svg
};

//enum /*class*/ CsvFormat {
//    DecibelDegrees,
//    DecibelRadians,
//    MagnitudeDegrees,
//    MagnitudeRadians,
//    RealImaginary,
//    DecibelMagnitude,
//    Magnitude,
//    PhaseDegrees,
//    PhaseRadians,
//    Vswr
//};

enum /*class*/ ComplexFormat {
    DecibelDegrees,
    MagnitudeDegrees,
    RealImaginary
};

enum /*class*/ Units {
    NoUnits = 0,
    Seconds,
    Hertz,
    Radians,
    Degrees,
    Ohms,
    Siemens,
    Watts,
    dB,
    dBW,
    dBm
};

enum /*class*/ SiPrefix {
    Tera = 12,
    Giga = 9,
    Mega = 6,
    Kilo = 3,
    None = 0,
    Milli = -3,
    Micro = -6,
    Nano = -9,
    Pico = -12,
    Femto = -15
};

// C++ std data types
typedef std::complex<double> ComplexDouble;
typedef std::vector<ComplexDouble> ComplexRowVector;
typedef std::vector<ComplexRowVector> ComplexMatrix2D;
typedef std::vector<ComplexMatrix2D> ComplexMatrix3D;

typedef std::vector<double> RowVector;
typedef std::vector<RowVector> Matrix2D;
typedef std::vector<Matrix2D> Matrix3D;

// Qt data types
typedef QMap<uint,uint> PortMap;
typedef QVector<uint> Ports;
typedef QVector<double> QRowVector;
typedef QVector<QRowVector> QMatrix2D;
typedef QVector<QMatrix2D> QMatrix3D;
}


Q_DECLARE_METATYPE(RsaToolbox::NetworkParameter)
Q_DECLARE_METATYPE(RsaToolbox::WaveQuantity)
Q_DECLARE_METATYPE(RsaToolbox::ReferenceLevel)
Q_DECLARE_METATYPE(RsaToolbox::TraceFormat)
//Q_DECLARE_METATYPE(RsaToolbox::CsvFormat)
Q_DECLARE_METATYPE(RsaToolbox::ComplexFormat)
Q_DECLARE_METATYPE(RsaToolbox::Units)
Q_DECLARE_METATYPE(RsaToolbox::SiPrefix)

Q_DECLARE_METATYPE(RsaToolbox::ComplexDouble)
Q_DECLARE_METATYPE(RsaToolbox::ComplexRowVector)
Q_DECLARE_METATYPE(RsaToolbox::ComplexMatrix2D)
Q_DECLARE_METATYPE(RsaToolbox::ComplexMatrix3D)

Q_DECLARE_METATYPE(RsaToolbox::PortMap)
Q_DECLARE_METATYPE(RsaToolbox::QRowVector)
Q_DECLARE_METATYPE(RsaToolbox::QMatrix2D)
Q_DECLARE_METATYPE(RsaToolbox::QMatrix3D)


#endif
