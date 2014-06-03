#ifndef DEFINITIONS_H
#define DEFINITIONS_H


// C++ std lib
#include <complex>
#include <vector>
#include <limits>
#include <climits>

// Qt
#include <QMetaType>
#include <QVector>


namespace RsaToolbox {

const char RSA_TOOLBOX_VERSION[] = "0.1.0";
const char COMPANY_FOLDER[] = "Rohde-Schwarz";
const double PI = 3.14159265358979323846264338327950288419716939937510;
const double  E = 2.71828182845904523536028747135266249775724709369995;
const double DBL_INF = std::numeric_limits<double>::infinity();
const double DBL_NEG_INF = -DBL_INF;
const double DBL_NAN = std::numeric_limits<double>::quiet_NaN();

enum NetworkParameter {
    S_PARAMETER = 0,
    Y_PARAMETER,
    Z_PARAMETER,
    H_PARAMETER,
    G_PARAMETER };

enum WaveQuantity {
    A_WAVE,
    B_WAVE };

enum ReferenceLevel {
    RELATIVE_REFERENCE_LEVEL,
    ABSOLUTE_REFERENCE_LEVEL };

enum TraceFormat {
    DB_MAGNITUDE_TRACE,
    PHASE_DEG_TRACE,
    SMITH_CHART_TRACE,
    POLAR_CHART_TRACE,
    VSWR_TRACE,
    UNWRAP_PHASE_DEG_TRACE,
    LINEAR_MAGNITUDE_TRACE,
    INVERSE_SMITH_CHART_TRACE,
    REAL_PART_TRACE,
    IMAGINARY_PART_TRACE,
    DELAY_TRACE };

enum CsvFormat {
    COMPLEX_DB_DEGREES_CSV,
    COMPLEX_DB_RADIANS_CSV,
    COMPLEX_MAGNITUDE_DEGREES_CSV,
    COMPLEX_MAGNITUDE_RADIANS_CSV,
    COMPLEX_REAL_IMAGINARY_CSV,
    DECIBEL_MAGNITUDE_CSV,
    MAGNITUDE_CSV,
    PHASE_DEGREES_CSV,
    PHASE_RADIANS_CSV,
    VSWR_CSV };

enum ComplexFormat {
    DB_DEGREES_COMPLEX,
    MAGNITUDE_DEGREES_COMPLEX,
    REAL_IMAGINARY_COMPLEX };

enum Units {
    NO_UNITS = 0,
    SECONDS_UNITS,
    HERTZ_UNITS,
    RADIANS_UNITS,
    DEGREES_UNITS,
    OHMS_UNITS,
    SIEMENS_UNITS,
    WATTS_UNITS,
    DECIBELS_UNITS,
    DECIBEL_WATTS_UNITS,
    DECIBEL_MILLIWATTS_UNITS };

enum SiPrefix {
    TERA_PREFIX = 12,
    GIGA_PREFIX = 9,
    MEGA_PREFIX = 6,
    KILO_PREFIX = 3,
    NO_PREFIX = 0,
    MILLI_PREFIX = -3,
    MICRO_PREFIX = -6,
    NANO_PREFIX = -9,
    PICO_PREFIX = -12,
    FEMTO_PREFIX = -15 };

// C++ std data types
typedef std::complex<double> ComplexDouble;
typedef std::vector<ComplexDouble> ComplexRowVector;
typedef std::vector<ComplexRowVector> ComplexMatrix2D;
typedef std::vector<ComplexMatrix2D> ComplexMatrix3D;

typedef std::vector<double> RowVector;
typedef std::vector<RowVector> Matrix2D;
typedef std::vector<Matrix2D> Matrix3D;

// Qt data types
typedef QVector<double> QRowVector;
typedef QVector<QRowVector> QMatrix2D;
typedef QVector<QMatrix2D> QMatrix3D;
}

Q_DECLARE_METATYPE(RsaToolbox::NetworkParameter)
Q_DECLARE_METATYPE(RsaToolbox::WaveQuantity)
Q_DECLARE_METATYPE(RsaToolbox::ReferenceLevel)
Q_DECLARE_METATYPE(RsaToolbox::TraceFormat)
Q_DECLARE_METATYPE(RsaToolbox::CsvFormat)
Q_DECLARE_METATYPE(RsaToolbox::ComplexFormat)
Q_DECLARE_METATYPE(RsaToolbox::Units)
Q_DECLARE_METATYPE(RsaToolbox::SiPrefix)

Q_DECLARE_METATYPE(RsaToolbox::ComplexDouble)
Q_DECLARE_METATYPE(RsaToolbox::ComplexRowVector)
Q_DECLARE_METATYPE(RsaToolbox::ComplexMatrix2D)
Q_DECLARE_METATYPE(RsaToolbox::ComplexMatrix3D)

Q_DECLARE_METATYPE(RsaToolbox::QRowVector)
Q_DECLARE_METATYPE(RsaToolbox::QMatrix2D)
Q_DECLARE_METATYPE(RsaToolbox::QMatrix3D)



#endif


