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
        unsigned int port1;
        unsigned int port2;
        unsigned int points;
        SweepType sweep_type;
        TraceFormat format;
        QDateTime date_time;

        ComplexRowVector complex_data;
        RowVector data, stimulus_points;
        Units data_units, stimulus_units;

        bool isComplex(void);
        operator QString();
	};
}


#endif
