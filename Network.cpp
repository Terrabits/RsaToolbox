/* To do:
1. Handle different data formats (just MA right now)
									*/

// Includes in header, plus a few extra
#include "Network.h"
#include "Touchstone.h"

#include <iostream>
#include <sstream>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <locale>



namespace RSToolbox
{
	using namespace std;
	using namespace std::regex_constants;

	// Constructor
	Network::Network() {
		Initialize();


	}
	void Network::Initialize(void) {
		// Prepare object to hold data
		data = vector<vector<vector<complex<double>>>>();
		frequency = Frequency();
		numberOfFreqPoints = 0;
		numberOfPorts = 0;

		// Initialize the rest of the parameters to (Touchstone) defaults
		isBalanced = false;
		dataType = S;
		portImpedance = 50; // Ohms
		format = RI;


	}

	// Actions
	bool Network::IsValid(void) {
		bool isValid = true;
		isValid &= (frequency.frequency.size() == data.size());
		if (isValid) { numberOfFreqPoints = data.size(); };
		isValid &= (numberOfFreqPoints > 0);
		isValid &= (frequency.units == THZ ||
			frequency.units == GHZ ||
			frequency.units == MHZ ||
			frequency.units == KHZ ||
			frequency.units == HZ);
		isValid &= (numberOfPorts > 0);
		isValid &= (portImpedance > 0);
		isValid &= (format == RI || format == DB || format == MA);
		isValid &= (dataType == S || dataType == Y || dataType == Z || dataType == H || dataType == G);

		// Checking each freq point, row and column takes time.
		// Can we return now?
		if (isValid == false) return(false);

		// Check each frequency point, row and column for data
		vector<vector<vector<complex<double>>>>::iterator freqIterator = data.begin();
		for (; freqIterator != data.end(); freqIterator++) {
			isValid &= ((*freqIterator).size() == numberOfPorts);
			vector<vector<complex<double>>>::iterator rowIterator = (*freqIterator).begin();
			for (; rowIterator != (*freqIterator).end(); rowIterator++) {
				isValid &= ((*rowIterator).size() == numberOfPorts);
			}
		}

		return(isValid);


	}
	void Network::Display(vector<array<int, 3>> &points) {
		cout << endl << "*** NETWORK ***" << endl;
		if (!IsValid()) { cout << "ERROR: This instance is bad" << endl << endl; return; }

		cout << setw(14) << "Network type: " << Touchstone::WriteDataType(*this) << endl;
		cout << setw(14) << "Number of Points: " << numberOfFreqPoints << endl;
		cout << setw(14) << "Frequency Units: " << Touchstone::WriteUnits(*this) << endl;
		cout << setw(14) << "Number of Ports: " << numberOfPorts << endl;
		cout << setw(14) << "Port Impedance: " << portImpedance << endl;
		cout << setw(14) << "Data Format: " << Touchstone::WriteFormat(*this) << endl;

		if (points.size() <= 0) { return; }

		vector<array<int, 3>>::iterator point_iter = points.begin();
		for (; point_iter != points.end(); point_iter++) {
			int freq = (*point_iter)[0];
			int row = (*point_iter)[1];
			int col = (*point_iter)[2];
			if (freq < numberOfFreqPoints && row < numberOfPorts && col < numberOfPorts) {
				cout << setw(8) << setprecision(4) << frequency[freq] << " " << setw(4);
				cout << "(" << setw(8) << setprecision(4) << data[freq][row][col].real() << ", " << setw(8) << setprecision(4) << data[freq][row][col].imag() << ")" << endl; }
		}
		cout << endl;


	}
	void Network::GetDb(int port1, int port2, std::vector<double> &decibels) {
		decibels.resize(numberOfFreqPoints);
		for (int frequency = 0; frequency < numberOfFreqPoints; frequency++) {
			decibels[frequency] = 20 * log10(abs(data[frequency][port1][port2]));
		}

	
	}
	void Network::GetMagnitude(int port1, int port2, std::vector<double> &magnitude) {
		magnitude.resize(numberOfFreqPoints);
		for (int frequency = 0; frequency < numberOfFreqPoints; frequency++) {
			magnitude[frequency] = abs(data[frequency][port1][port2]);
		}


	}
	void Network::GetAngle(int port1, int port2, std::vector<double> &angle) {
		angle.resize(numberOfFreqPoints);
		for (int frequency = 0; frequency < numberOfFreqPoints; frequency++) {
			angle[frequency] = arg(data[frequency][port1][port2]) * 180 / PI;
		}
	
	
	} // degrees
	void Network::GetFrequency(std::vector<double> &frequency, std::string &units) {
		frequency = this->frequency.frequency;
		units = "Hz";


	}
	string Network::GetFormattedValue(double value, int decimalPlaces, string unitAbbreviation) {
		ostringstream formattedValue;
		formattedValue.precision(decimalPlaces);
		formattedValue << fixed;

		const int count = 10;
		int prefixMagnitudes[count] = { -15, -12, -9, -6, -3, 0, 3, 6, 9, 12 };
		vector<string> prefixStrings(count);
		prefixStrings[0] = "f";
		prefixStrings[1] = "p";
		prefixStrings[2] = "n";
		prefixStrings[3] = "u";
		prefixStrings[4] = "m";
		prefixStrings[5] = "";
		prefixStrings[6] = "K";
		prefixStrings[7] = "M";
		prefixStrings[8] = "G";
		prefixStrings[9] = "T";

		double magnitude = abs(value);
		int i;
		for (i = 0; i < count - 1; i++) {
			double bound = (1 - 0.5 * pow(10.0, (double)(-3 - decimalPlaces))) * pow(10.0, (double)prefixMagnitudes[i + 1]);
			if (magnitude < bound) {
				formattedValue << (value * pow(10.0, (double) (-1 * prefixMagnitudes[i]))) << " ";
				formattedValue << prefixStrings[i] << unitAbbreviation;
				return(formattedValue.str());
			}
		}
		// else Terra or bigger
		formattedValue << (value * pow(10.0, (double) (-1 * prefixMagnitudes[i])));
		formattedValue << prefixStrings[i] << unitAbbreviation;
		return(formattedValue.str());


	}


	// Operators
	bool Network::operator==(Network &other) {
		bool isEqual = true;
		double PRECISION = 0.0001;
		isEqual &= (this->numberOfFreqPoints == other.numberOfFreqPoints);
		isEqual &= (this->numberOfPorts == other.numberOfPorts);
		isEqual &= (this->portImpedance == other.portImpedance);
		isEqual &= (this->format == other.format);
		isEqual &= (this->dataType == other.dataType);
		isEqual &= (this->frequency.units == other.frequency.units);
		isEqual &= (this->frequency.frequency.size() == other.frequency.frequency.size());
		isEqual &= (this->data.size() == other.data.size());


		// Comparing data takes time. Can we return now?
		if (!isEqual) { return(false); }

		for (int freq = 0; freq < numberOfFreqPoints; freq++) {
			isEqual &= (this->frequency[freq] == other.frequency[freq]);
			isEqual &= (this->data[freq].size() == other.data[freq].size());
			for (int row = 0; row < numberOfPorts; row++) {
				isEqual &= (this->data[freq][row].size() == other.data[freq][row].size());
				for (int column = 0; column < numberOfPorts; column++) {
					double error = abs(this->data[freq][row][column] - other.data[freq][row][column]);
					isEqual &= error < PRECISION; }
			}
		}
		return(isEqual);


	}
	std::vector<std::vector<std::complex<double>>>& Network::operator[](int index) {
		return(data[index]);


	}

}