#ifndef TRACE_H
#define TRACE_H


// Rsa
#include "Definitions.h"

// Qt
#include <QString>
#include <QStringList>

// C++ std lib
#include <vector>

namespace RsaToolbox {
    class Trace  {
	public:
        unsigned int port1;
        unsigned int port2;
        SweepType sweep_type;
        NetworkParameter network_parameter;
        TraceFormat format;

        RowVector data();
        RowVector x_axis();
	};
}


#endif
