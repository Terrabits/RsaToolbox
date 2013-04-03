#ifndef NETWORK_H
#define NETWORK_H


#include "Frequency.h"
#include <visa.h>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <fstream>
#include <ostream>
#include <regex>


namespace RSToolbox
{
	// Probably a better way/place to define pi, but wtf:
	// double precision pi
	double const PI = 3.14159265358979323846;

	// Enumerators
	enum data_type { S, Y, Z, H, G };
	enum data_format { DB, MA, RI };

	class Network {
	public:
		// Public properties
		int numberOfPorts;
		double portImpedance; // Ohms
		bool isBalanced;
		data_type dataType;
		int numberOfFreqPoints;
		Frequency frequency;
		data_format format;
		std::vector<std::vector<std::vector<std::complex<double>>>> data;

		// Constructor
		Network();
		void Initialize(void);

		// Actions
		void Display(std::vector<std::array<int, 3>> &points);
		bool IsValid(void);
		void GetDb(int port1, int port2, std::vector<double> &decibels);
		void GetMagnitude(int port1, int port2, std::vector<double> &magnitude);
		void GetAngle(int port1, int port2, std::vector<double> &angle); // degrees
		void GetFrequency(std::vector<double> &frequency, std::string &units);
		std::string GetFormattedValue(double value, int decimalPlaces, std::string unitAbbreviation);

		// Operators
		bool operator==(Network &network);
		std::vector<std::vector<std::complex<double>>>& operator[](int index);
	};
}


#endif