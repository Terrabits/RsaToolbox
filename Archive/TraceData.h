#ifndef TRACE_DATA_H
#define TRACE_DATA_H


// Rsa
#include "Definitions.h"

// Qt
#include <QString>
#include <QDateTime>

// C++ std lib
#include <complex>
#include <vector>


namespace RsaToolbox {
class TraceData  {
public:
    NetworkParameter network_parameter;
    unsigned int output_port;
    unsigned int input_port;
    unsigned int points;
    VnaSweepType sweep_type;
    TraceFormat format;
    QDateTime date_time;

    ComplexRowVector complex_data;
    RowVector data, stimulus_points;
    Units data_units, stimulus_units;

    bool isComplex(void);

    // Search functions


    operator QString();
};
}


#endif


