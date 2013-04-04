#ifndef NETWORK_H
#define NETWORK_H

// RsaToolbox
#include "Definitions.h"


namespace RsaToolbox
{
	class Network {
	public:
        // Properties
        unsigned int ports;
        unsigned int points;
        NetworkParameter type;
        ComplexFormat format;
        double impedance; // Ohms
		bool isBalanced;

        // Data
        SiPrefix frequency_prefix;
        RowVector frequency;
        ComplexMatrix3D data;

		// Constructor
		Network();
		void Initialize(void);

		// Actions
		bool IsValid(void);
        void GetDb(int port1, int port2, RowVector &decibels);
        void GetMagnitude(int port1, int port2, RowVector &magnitude);
        void GetAngle(int port1, int port2, RowVector &angle); // degrees
        void GetFrequency(RowVector &frequency, SiPrefix &units);

		// Operators
		bool operator==(Network &network);
        ComplexMatrix2D& operator[](int index);
	};
}


#endif
