
// Rsa
#include "General.h"

// Qt
#include <QStringList>
#include <QStandardPaths>
#include <QTextStream>
#include <QCoreApplication>

// C++ std lib
#include <complex>

using namespace RsaToolbox;

// Enum Conversions
double RsaToolbox::ToDouble(SiPrefix prefix) {
    switch(prefix) {
    case TERA_PREFIX:
        return(1E12);
        break;
    case GIGA_PREFIX:
        return(1E9);
        break;
    case MEGA_PREFIX:
        return(1E6);
        break;
    case KILO_PREFIX:
        return(1E3);
        break;
    case MILLI_PREFIX:
        return(1E-3);
        break;
    case MICRO_PREFIX:
        return(1E-6);
        break;
    case NANO_PREFIX:
        return(1E-9);
        break;
    case PICO_PREFIX:
        return(1E-12);
        break;
    case FEMTO_PREFIX:
        return(1E-15);
        break;
    default:
        // NO_PREFIX
        return(1E0);
        break;
    }
}

QString RsaToolbox::ToString(SiPrefix prefix) {
    switch(prefix) {
    case TERA_PREFIX:
        return("T");
        break;
    case GIGA_PREFIX:
        return("G");
        break;
    case MEGA_PREFIX:
        return("M");
        break;
    case KILO_PREFIX:
        return("K");
        break;
    case MILLI_PREFIX:
        return("m");
        break;
    case MICRO_PREFIX:
        return("u");
        break;
    case NANO_PREFIX:
        return("n");
        break;
    case PICO_PREFIX:
        return("p");
        break;
    case FEMTO_PREFIX:
        return("f");
        break;
    default:
        // NO_PREFIX
        return("");
        break;
    }
}
QString RsaToolbox::ToString(Units units) {
    switch(units) {
    case SECONDS_UNITS:
        return("s");
        break;
    case HERTZ_UNITS:
        return("Hz");
        break;
    case RADIANS_UNITS:
        return("Rad");
        break;
    case DEGREES_UNITS:
        return("Deg");
        break;
    case OHMS_UNITS:
        return("Ω");
        break;
    case SIEMENS_UNITS:
        return("S");
        break;
    case WATTS_UNITS:
        return("W");
        break;
    case DECIBELS_UNITS:
        return("dB");
        break;
    case DECIBEL_WATTS_UNITS:
        return("dBW");
        break;
    case DECIBEL_MILLIWATTS_UNITS:
        return("dBm");
        break;
    default:
        // NO_UNITS
        return("");
        break;
    }
}
QString RsaToolbox::ToString(ComplexFormat format) {
    switch(format) {
    case DB_DEGREES_COMPLEX:
        return("dB");
        break;
    case MAGNITUDE_DEGREES_COMPLEX:
        return("MA");
        break;
    case REAL_IMAGINARY_COMPLEX:
        return("RI");
        break;
    }
    // Default
    return("dB");
}
QString RsaToolbox::ToString(NetworkParameter parameter) {
    switch(parameter) {
    case S_PARAMETER:
        return("S");
        break;
    case Y_PARAMETER:
        return("Y");
        break;
    case Z_PARAMETER:
        return("Z");
        break;
    case H_PARAMETER:
        return("H");
        break;
    case G_PARAMETER:
        return("G");
        break;
    }
    // Default
    return("S");
}
QString RsaToolbox::ToString(VnaModel model) {
    switch(model) {
    case ZVA_MODEL:
        return(QString("ZVA"));
    case ZVB_MODEL:
        return(QString("ZVB"));
    case ZVH_MODEL:
        return(QString("ZVH"));
    case ZVL_MODEL:
        return(QString("ZVL"));
    case ZVT_MODEL:
        return(QString("ZVT"));
    case ZNB_MODEL:
        return(QString("ZNB"));
    case ZNC_MODEL:
        return(QString("ZNC"));
    default:
        // UNKNOWN_MODEL
        return(QString("UNKNOWN"));
    }
}
QString RsaToolbox::ToStateFileExtension(VnaModel model) {
    switch(model) {
    case ZVA_MODEL:
        return(QString(".zvx"));
    case ZVB_MODEL:
        return(QString(".zvx"));
    case ZVH_MODEL:
        return(QString(".zvx"));
    case ZVL_MODEL:
        return(QString(".zvx"));
    case ZVT_MODEL:
        return(QString(".zvx"));
    case ZNB_MODEL:
        return(QString(".znx"));
    case ZNC_MODEL:
        return(QString(".znx"));
    default:
        // UNKNOWN_MODEL
        return(QString(".rsx"));
    }
}

const char* RsaToolbox::ToScpi(SweepType sweep_type) {
    switch(sweep_type) {
    case LINEAR_FREQUENCY_SWEEP:
        return("LIN");
    case LOG_FREQUENCY_SWEEP:
        return("LOG");
    case SEGMENTED_SWEEP:
        return("SEGM");
    case POWER_SWEEP:
        return("POW");
    case CW_MODE_SWEEP:
        return("CW");
    case TIME_SWEEP:
        return("POIN");
    }
    // Default
    return("LIN");
}
const char* RsaToolbox::ToScpi(ReferenceLevel reference_level) {
    if (reference_level == RELATIVE_REFERENCE_LEVEL)
        return("CPAD");
    if (reference_level == ABSOLUTE_REFERENCE_LEVEL)
        return("ONLY");
    //Default
    return("ONLY");
}
const char* RsaToolbox::ToScpi(ColorScheme scheme) {
    switch(scheme) {
    case DARK_BACKGROUND:
        return("DBAC");
        break;
    case LIGHT_BACKGROUND:
        return("LBAC");
        break;
    case BLACK_WHITE_OUTLINE_BACKGROUND:
        return("BWLS");
        break;
    case BLACK_WHITE_SOLID_BACKGROUND:
        return("BWS");
        break;
    }
    // Default
    return("DBAC");
}
const char* RsaToolbox::ToScpi(TraceFormat format) {
    switch(format) {
    case DB_MAGNITUDE_TRACE:
        return("MLOG");
        break;
    case PHASE_DEG_TRACE:
        return("PHAS");
        break;
    case SMITH_CHART_TRACE:
        return("SMIT");
        break;
    case POLAR_CHART_TRACE:
        return("POL");
        break;
    case VSWR_TRACE:
        return("SWR");
        break;
    case UNWRAP_PHASE_DEG_TRACE:
        return("UPH");
        break;
    case LINEAR_MAGNITUDE_TRACE:
        return("MLIN");
        break;
    case INVERSE_SMITH_CHART_TRACE:
        return("ISM");
        break;
    case REAL_PART_TRACE:
        return("REAL");
        break;
    case IMAGINARY_PART_TRACE:
        return("IMAG");
        break;
    case DELAY_TRACE:
        return("GDE");
        break;
    }
    // Default
    return("MLOG");
}

SiPrefix RsaToolbox::String_To_SiPrefix(QString prefix) {
    if (prefix.length() == 0)
        return(NO_PREFIX);
    if (prefix == "T")
        return(TERA_PREFIX);
    if (prefix == "G")
        return(GIGA_PREFIX);
    if (prefix == "M")
        return(MEGA_PREFIX);
    if (prefix == "K")
        return(KILO_PREFIX);
    if (prefix == "m")
        return(MILLI_PREFIX);
    if (prefix == "u")
        return(MICRO_PREFIX);
    if (prefix == "n")
        return(NANO_PREFIX);
    if (prefix == "p")
        return(PICO_PREFIX);
    if (prefix == "f")
        return(FEMTO_PREFIX);
    // Default
    return(NO_PREFIX);
}

TraceFormat RsaToolbox::Scpi_To_TraceFormat(QString scpi) {
    if (scpi == "MLOG")
        return(DB_MAGNITUDE_TRACE);
    if (scpi == "PHAS")
        return(PHASE_DEG_TRACE);
    if (scpi == "SMIT")
        return(SMITH_CHART_TRACE);
    if (scpi == "POL")
        return(POLAR_CHART_TRACE);
    if (scpi == "SWR")
        return(VSWR_TRACE);
    if (scpi == "UPH")
        return(UNWRAP_PHASE_DEG_TRACE);
    if (scpi == "MLIN")
        return(LINEAR_MAGNITUDE_TRACE);
    if (scpi == "ISM")
        return(INVERSE_SMITH_CHART_TRACE);
    if (scpi == "REAL")
        return(REAL_PART_TRACE);
    if (scpi == "IMAG")
        return(IMAGINARY_PART_TRACE);
    if (scpi == "GDE")
        return(DELAY_TRACE);
    // Default
    return(DB_MAGNITUDE_TRACE);
}
ColorScheme RsaToolbox::Scpi_To_ColorScheme(QString scpi) {
    if(scpi == "DBAC")
        return(DARK_BACKGROUND);
    if(scpi == "LBAC")
        return(LIGHT_BACKGROUND);
    if(scpi == "BWLS")
        return(BLACK_WHITE_OUTLINE_BACKGROUND);
    if(scpi == "BWS")
        return(BLACK_WHITE_SOLID_BACKGROUND);
    // Default
    return(DARK_BACKGROUND);
}
NetworkParameter RsaToolbox::Scpi_To_NetworkParameter(QString scpi) {
    if (scpi == "S")
        return(S_PARAMETER);
    if (scpi == "Y")
        return(Y_PARAMETER);
    if (scpi == "Z")
        return(Z_PARAMETER);
    if (scpi == "H")
        return(H_PARAMETER);
    if (scpi == "G")
        return(G_PARAMETER);
    // Default
    return(S_PARAMETER);
}
ReferenceLevel RsaToolbox::Scpi_To_ReferenceLevel(QString scpi) {
    if (scpi == "CPAD")
        return(RELATIVE_REFERENCE_LEVEL);
    if (scpi == "ONLY")
        return(ABSOLUTE_REFERENCE_LEVEL);
    // Default
    return(ABSOLUTE_REFERENCE_LEVEL);
}
SweepType RsaToolbox::Scpi_To_SweepType(QString scpi) {
    if (scpi == "LIN")
        return(LINEAR_FREQUENCY_SWEEP);
    if (scpi == "LOG")
        return(LOG_FREQUENCY_SWEEP);
    if (scpi == "SEGM")
        return(SEGMENTED_SWEEP);
    if (scpi == "POW")
        return(POWER_SWEEP);
    if (scpi == "CW")
        return(CW_MODE_SWEEP);
    if (scpi == "POIN")
        return(TIME_SWEEP);
    // Default
    return(LINEAR_FREQUENCY_SWEEP);
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
QString RsaToolbox::FormatValue(double value, int decimalPlaces, Units units, SiPrefix prefix) {
    QString formatted_value;
    QTextStream text_stream(&formatted_value);
    text_stream.setRealNumberPrecision(decimalPlaces);
    text_stream.setRealNumberNotation(QTextStream::FixedNotation);

    const int count = 10;
    SiPrefix prefixes[count] =
    { FEMTO_PREFIX,
      PICO_PREFIX,
      NANO_PREFIX,
      MICRO_PREFIX,
      MILLI_PREFIX,
      NO_PREFIX,
      KILO_PREFIX,
      MEGA_PREFIX,
      GIGA_PREFIX,
      TERA_PREFIX };

    double magnitude = abs(value * ToDouble(prefix));
    for (int i = 0; i < count; i++) {
        double bound = (1 - 0.5 * pow(10.0, (double)(-3 - decimalPlaces))) * ToDouble(prefixes[i + 1]);
        if (magnitude < bound) {
            text_stream << (value / ToDouble(prefixes[i])) << " ";
            text_stream << ToString(prefixes[i]) << ToString(units);
            text_stream.flush();
            return(formatted_value);
        }
    }

    // else Tera or bigger
    text_stream << (value / (double)prefixes[count]);
    text_stream << (QString)prefixes[count] << (QString)units;
    text_stream.flush();
    return(formatted_value);
}

// Math
double RsaToolbox::ToDb(double value) {
    return(20 * log10(value));
}
double RsaToolbox::ToDb(std::complex<double> value) {
    return(ToDb(abs(value)));
}
double RsaToolbox::ToMagnitude(double decibels) {
    return(pow(10.0, decibels / 20.0));
}
