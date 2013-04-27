#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// C++ std lib
#include <complex>
#include <vector>


namespace RsaToolbox {

    const char RSA_TOOLBOX_VERSION[] = "0.0.1";
    const char COMPANY_FOLDER[] = "Rohde-Schwarz";
	const double PI =  3.1415926535897932;

    enum SweepType {
        LINEAR_FREQUENCY_SWEEP,
        LOG_FREQUENCY_SWEEP,
        SEGMENTED_SWEEP,
        POWER_SWEEP,
        CW_MODE_SWEEP,
        TIME_SWEEP };

    enum NetworkParameter {
        S_PARAMETER,
        Y_PARAMETER,
        Z_PARAMETER,
        H_PARAMETER,
        G_PARAMETER };

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

    enum CorrectionState {
        APPLIED_CORRECTION,
        INTERPOLATED_CORRECTION,
        DISABLED_CORRECTION,
        NO_CORRECTION };

    enum ColorScheme {
        DARK_BACKGROUND,
        LIGHT_BACKGROUND,
        BLACK_WHITE_OUTLINE_BACKGROUND,
        BLACK_WHITE_SOLID_BACKGROUND };

    enum ComplexFormat {
        DB_DEGREES_COMPLEX,
        MAGNITUDE_DEGREES_COMPLEX,
        REAL_IMAGINARY_COMPLEX };

    enum Units {
        NO_UNITS,
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

	enum ConnectionType {
		TCPIP_CONNECTION,
		GPIB_CONNECTION,
        // USB_CONNECTION,
        NO_CONNECTION };

    enum VnaModel {
        ZVA_MODEL,
        ZVB_MODEL,
        ZVH_MODEL,
        ZVL_MODEL,
        ZVT_MODEL,
        ZNB_MODEL,
        ZNC_MODEL,
        UNKNOWN_MODEL };

    // Data types
    typedef std::vector<std::vector<std::vector<std::complex<double>>>> ComplexMatrix3D;
    typedef std::vector<std::vector<std::complex<double>>> ComplexMatrix2D;
    typedef std::vector<std::complex<double>> ComplexRowVector;
    typedef std::vector<double> RowVector;
}

#endif
