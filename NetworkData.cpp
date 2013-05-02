

// Rsa
#include "Definitions.h"
#include "General.h"
#include "NetworkData.h"

// Qt
#include <QTextStream>

// C++ std lib
#include <iostream>
#include <sstream>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <algorithm>

using namespace RsaToolbox;
using namespace std;

// Constructor
NetworkData::NetworkData() {
    ports = 0;
    points = 0;

    // Touchstone defaults
    frequency_prefix = GIGA_PREFIX;
    network_parameter = S_PARAMETER;
    format = REAL_IMAGINARY_COMPLEX;
    impedance = 50;
    isBalanced = false;
}

// Actions
bool NetworkData::isValid(void) {
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
void NetworkData::GetDb(int port1, int port2, RowVector &decibels) {
    decibels.resize(points);
    for (unsigned int frequency = 0; frequency < points; frequency++) {
        decibels[frequency] = ToDb(data[frequency][port1][port2]);
    }
}
void NetworkData::GetMagnitude(int port1, int port2, RowVector &magnitude) {
    magnitude.resize(points);
    for (unsigned int frequency = 0; frequency < points; frequency++) {
        magnitude[frequency] = abs(data[frequency][port1][port2]);
    }
}
void NetworkData::GetAngle(int port1, int port2, RowVector &angle_degrees) {
    angle_degrees.resize(points);
    for (unsigned int frequency = 0; frequency < points; frequency++) {
        angle_degrees[frequency] = arg(data[frequency][port1][port2]) * 180 / PI;
    }
}
void NetworkData::GetFrequency(RowVector &frequency, SiPrefix &frequency_prefix) {
    frequency = this->frequency;
    frequency_prefix = this->frequency_prefix;
}

// Operators
NetworkData::operator QString() {
    QString output;
    QTextStream stream(&output);

    stream << "Network:" << endl;
    stream << "Ports:      " << ports << endl;
    stream << "Points:     " << points << endl;
    stream << "Format:     " << ToString(format) << endl;
    stream << "Impedance:  " << impedance << endl;
    stream << "Balanced?   " << QVariant(isBalanced).toString() << endl;
    stream << "Date/Time:  " << date_time.toString() << endl;

    // First Point
    stream << "@ " << FormatValue(frequency[0], 3, HERTZ_UNITS, frequency_prefix);
    stream << " : S11= " << "(" << QVariant(data[0][1][1].real()).toString();
    stream << ", " << QVariant(data[0][1][1].imag()).toString() << ")" << endl;

    // Last Point
    stream << "@ " << FormatValue(frequency[points-1], 3, HERTZ_UNITS, frequency_prefix);
    stream << " : S11= " << "(" << QVariant(data[points-1][1][1].real()).toString();
    stream << ", " << QVariant(data[points-1][1][1].imag()).toString() << ")" << endl;

    stream.flush();
    return(output);
}
bool NetworkData::operator==(NetworkData &other) {
    const double TOLERANCE = 0.0001;

    bool isEqual = true;
    isEqual &= (this->points == other.points);
    isEqual &= (this->ports == other.ports);
    isEqual &= (this->impedance == other.impedance);
    isEqual &= (this->format == other.format);
    isEqual &= (this->network_parameter == other.network_parameter);
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
                isEqual &= (error < TOLERANCE); }
        }
    }
    return(isEqual);
}
ComplexMatrix2D& NetworkData::operator[](int index) {
    return(data[index]);
}
