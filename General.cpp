
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
QString RsaToolbox::ToString(ConnectionType connection_type) {
    if (connection_type == TCPIP_CONNECTION)
        return("TCPIP");
    if (connection_type == GPIB_CONNECTION)
        return("GPIB");
    // Else
    return("No Connection");
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
