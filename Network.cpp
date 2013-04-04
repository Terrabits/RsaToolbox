

// Rsa
#include "Definitions.h"
#include "General.h"
#include "Network.h"

#include <iostream>
#include <sstream>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <locale>

using namespace RsaToolbox;
using namespace std;

// Constructor
Network::Network() {
    Initialize();
}

void Network::Initialize(void) {
    // Prepare object to hold data
    data = ComplexMatrix3D();
    frequency_prefix = NO_PREFIX;
    frequency = RowVector();
    ports = 0;
    points = 0;

    // Initialize rest to (Touchstone) defaults
    type = S_PARAMETERS;
    format = REAL_IMAGINARY;
    impedance = 50;
    isBalanced = false;
}

// Actions
bool Network::IsValid(void) {
    bool isValid = true;
    isValid &= (frequency.size() == data.size());
    if (isValid) { points = data.size(); };
    isValid &= (points > 0);
    isValid &= (ports > 0);
    isValid &= (impedance > 0);

    // Can we save time and return now?
    if (isValid == false) return(false);

    // Check data structure
    ComplexMatrix3D::iterator freqIterator = data.begin();
    for (; freqIterator != data.end(); freqIterator++) {
        isValid &= ((*freqIterator).size() == ports);
        ComplexMatrix2D::iterator rowIterator = (*freqIterator).begin();
        for (; rowIterator != (*freqIterator).end(); rowIterator++) {
            isValid &= ((*rowIterator).size() == ports);
        }
    }
    return(isValid);
}

void Network::GetDb(int port1, int port2, RowVector &decibels) {
    decibels.resize(points);
    for (unsigned int frequency = 0; frequency < points; frequency++) {
        decibels[frequency] = ToDb(data[frequency][port1][port2]);
    }
}


void Network::GetMagnitude(int port1, int port2, RowVector &magnitude) {
    magnitude.resize(points);
    for (unsigned int frequency = 0; frequency < points; frequency++) {
        magnitude[frequency] = abs(data[frequency][port1][port2]);
    }
}

void Network::GetAngle(int port1, int port2, RowVector &angle) {
    angle.resize(points);
    for (unsigned int frequency = 0; frequency < points; frequency++) {
        angle[frequency] = arg(data[frequency][port1][port2]) * 180 / PI;
    }
}

void Network::GetFrequency(RowVector &frequency, SiPrefix &prefix) {
    frequency = this->frequency;
    prefix = this->frequency_prefix;
}

// Operators
bool Network::operator==(Network &other) {
    bool isEqual = true;
    const double PRECISION = 0.0001;
    isEqual &= (this->points == other.points);
    isEqual &= (this->ports == other.ports);
    isEqual &= (this->impedance == other.impedance);
    isEqual &= (this->format == other.format);
    isEqual &= (this->type == other.type);
    isEqual &= (this->frequency_prefix == other.frequency_prefix);
    isEqual &= (this->frequency.size() == other.frequency.size());
    isEqual &= (this->data.size() == other.data.size());


    // Comparing data takes time. Can we return now?
    if (!isEqual) { return(false); }

    for (unsigned int freq = 0; freq < points; freq++) {
        isEqual &= (this->frequency[freq] == other.frequency[freq]);
        isEqual &= (this->data[freq].size() == other.data[freq].size());
        for (unsigned int row = 0; row < ports; row++) {
            isEqual &= (this->data[freq][row].size() == other.data[freq][row].size());
            for (unsigned int column = 0; column < ports; column++) {
                double error = abs(this->data[freq][row][column] - other.data[freq][row][column]);
                isEqual &= (error < PRECISION); }
        }
    }
    return(isEqual);
}


ComplexMatrix2D& Network::operator[](int index) {
    return(data[index]);
}
