#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// C++ std lib
#include <complex>
#include <vector>

namespace RsaToolbox {

    const char TOOLBOX_VERSION[] = "0.0.1";
	const double PI =  3.1415926535897932;

    enum SweepType {
        LINEAR_FREQUENCY,
        LOG_FREQUENCY,
		SEGMENTED_SWEEP,
        POWER_SWEEP,
        CW_MODE,
        TIME_DOMAIN };

    enum NetworkParameter {
		S_PARAMETERS,
		Y_PARAMETERS,
		Z_PARAMETERS,
		H_PARAMETERS,
		G_PARAMETERS };

    enum ComplexFormat {
        DB_DEGREES,
        MAGNITUDE_DEGREES,
        REAL_IMAGINARY };

	enum TraceFormat {
        DB_MAGNITUDE,
        PHASE_DEG,
        SMITH_CHART,
        POLAR_CHART,
        SWR,
        UNWRAP_PHASE_DEG,
        LINEAR_MAGNITUDE,
        INVERSE_SMITH_CHART,
        REAL_PART,
        IMAGINARY_PART,
        DELAY };

    enum Units {
        UNITLESS,
        SECONDS,
        HERTZ,
        RADIANS,
        DEGREES,
        WATTS,
        DECIBELS,
        DECIBEL_WATTS,
        DECIBEL_MILLIWATTS };

    enum SiPrefix {
        TERA = 12,
        GIGA = 9,
        MEGA = 6,
        KILO = 3,
        NO_PREFIX = 0,
        MILLI = -3,
        MICRO = -6,
        NANO = -9,
        PICO = -12,
        FEMTO = -15 };

	enum ConnectionType {
		TCPIP_CONNECTION,
		GPIB_CONNECTION,
		USB_CONNECTION };

    enum VnaModel {
        ZVA,
        ZVB,
        ZVH,
        ZVL,
        ZVT,
        ZNB,
        ZNC,
        UNKNOWN };

    typedef std::vector<std::vector<std::vector<std::complex<double>>>> ComplexMatrix3D;
    typedef std::vector<std::vector<std::complex<double>>> ComplexMatrix2D;
    typedef std::vector<std::complex<double>> ComplexRowVector;
    typedef std::vector<double> RowVector;
}

#endif
