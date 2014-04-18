
// RSToolbox includes
#include "General.h"
#include "TraceData.h"

// Qt
#include <QTextStream>


using namespace RsaToolbox;

bool TraceData::isComplex() {
    if (format == SMITH_CHART_TRACE
            || format == POLAR_CHART_TRACE
            || format == INVERSE_SMITH_CHART_TRACE)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}
TraceData::operator QString() {
    QString output;
    QTextStream stream(&output);

    stream << "Trace:      "
           << ToString(network_parameter)
           << output_port << input_port << endl;
    stream << "Sweep Type: " << sweep_type << endl;
    stream << "Format:     " << format << endl;
    stream << "Points:     " << complex_data.size() << endl;
    stream << "Date/Time:  " << date_time.toString() << endl;

    // Display first point:
    int current_point = 0;
    stream << "Point " << current_point << " Y=";
    if (isComplex())
        stream << "(" << complex_data[current_point].real()
               << "," << complex_data[current_point].imag()
               << ")";
    else
        stream << FormatValue(data[current_point], 2, data_units);
    if (stimulus_points.size() == points)
        stream << " X=" << FormatValue(stimulus_points[current_point], 2, stimulus_units) << endl;
    else
        stream << endl;

    // Middle Point
    if (points >= 3) {
        current_point = (int)(points/2);
        stream << "Point " << current_point << " Y=";
        if (isComplex())
            stream << "(" << complex_data[current_point].real()
                   << "," << complex_data[current_point].imag()
                   << ")";
        else
            stream << FormatValue(data[current_point], 2, data_units);
        if (stimulus_points.size() == points)
            stream << " X=" << FormatValue(stimulus_points[current_point], 2, stimulus_units) << endl;
        else
            stream << endl;
    }

    // Last Point
    if (points >= 2) {
        // Last point
        current_point = points - 1;
        stream << "Point " << current_point << " Y=";
        if (isComplex())
            stream << "(" << complex_data[current_point].real()
                   << "," << complex_data[current_point].imag()
                   << ")";
        else
            stream << FormatValue(data[current_point], 2, data_units);
        if (stimulus_points.size() == points)
            stream << " X=" << FormatValue(stimulus_points[current_point], 2, stimulus_units) << endl;
        else
            stream << endl;
    }
    stream.flush();
    return(output);
}


