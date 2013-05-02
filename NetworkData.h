#ifndef NETWORK_DATA_H
#define NETWORK_DATA_H

// Rsa
#include "Definitions.h"

// Qt
#include <QString>
#include <QDateTime>

// C++ std lib
#include <complex>
#include <vector>


namespace RsaToolbox
{
    class NetworkData {
	public:
        NetworkParameter network_parameter;
        unsigned int ports;
        unsigned int points;
        ComplexFormat format;
        double impedance; // Ohms
		bool isBalanced;
        QDateTime date_time;

        // Data
        SiPrefix frequency_prefix;
        RowVector frequency;
        ComplexMatrix3D data;

		// Constructor
        NetworkData();

		// Actions
        bool isValid(void);
        void GetDb(int port1, int port2, RowVector &decibels);
        void GetMagnitude(int port1, int port2, RowVector &magnitude);
        void GetAngle(int port1, int port2, RowVector &angle_degrees);
        void GetFrequency(RowVector &frequency, SiPrefix &frequency_prefix);

		// Operators
        operator QString();
        bool operator==(NetworkData &network);
        ComplexMatrix2D& operator[](int index);
	};
}


#endif
