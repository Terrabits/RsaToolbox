#include <QDebug>

// Rsa
#include "Definitions.h"
#include "General.h"
#include "NetworkData.h"
#include "Touchstone.h"

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
    sweep_type = LINEAR_FREQUENCY_SWEEP;
    ports = 0;
    points = 0;
    
    // Touchstone defaults
    stimulus_prefix = GIGA_PREFIX;
    network_parameter = S_PARAMETER;
    format = REAL_IMAGINARY_COMPLEX;
    impedance = 50;
    isBalanced = false;
}

// Actions
bool NetworkData::isValid(void) {
    bool isValid = true;
    isValid &= (stimulus.size() == data.size());
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
void NetworkData::GetDb(int output_port, int input_port, RowVector &decibels) {
    decibels.resize(points);
    if (output_port > (int)ports || input_port > (int)ports)
        return;
    
    for (int i = 0; i < (int)points; i++) {
        decibels[i] = ToDb(data[i][output_port - 1][input_port - 1]);
    }
}
RowVector NetworkData::GetDb(int output_port, int input_port) {
    RowVector decibels;
    GetDb(output_port, input_port, decibels);
    return(decibels);
}

void NetworkData::GetMagnitude(int output_port, int input_port, RowVector &magnitude) {
    magnitude.resize(points);
    for (unsigned int frequency = 0; frequency < points; frequency++) {
        magnitude[frequency] = abs(data[frequency][output_port][input_port]);
    }
}
void NetworkData::GetAngle(int output_port, int input_port, RowVector &angle_degrees) {
    angle_degrees.resize(points);
    for (unsigned int frequency = 0; frequency < points; frequency++) {
        angle_degrees[frequency] = arg(data[frequency][output_port][input_port]) * 180 / PI;
    }
}
void NetworkData::GetStimulus(RowVector &stimulus, SiPrefix &stimulus_prefix) {
    stimulus = this->stimulus;
    stimulus_prefix = this->stimulus_prefix;
}

// Operators
NetworkData::operator QString() {
    QString output;
    QTextStream stream(&output);
    
    stream << "Network:" << endl;
    stream << "Sweep:  " << ToString(sweep_type) << endl;
    stream << "Ports:      " << ports << endl;
    stream << "Points:     " << points << endl;
    stream << "Format:     " << ToString(format) << endl;
    stream << "Impedance:  " << impedance << endl;
    stream << "Balanced?   " << QVariant(isBalanced).toString() << endl;
    stream << "Date/Time:  " << date_time.toString() << endl;
    
    // First Point
    stream << "@ " << FormatValue(stimulus[0], 3, HERTZ_UNITS, stimulus_prefix);
    stream << " : S11= " << "(" << QVariant(data[0][1][1].real()).toString();
    stream << ", " << QVariant(data[0][1][1].imag()).toString() << ")" << endl;
    
    // Last Point
    stream << "@ " << FormatValue(stimulus[points-1], 3, HERTZ_UNITS, stimulus_prefix);
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
    isEqual &= (this->stimulus_prefix == other.stimulus_prefix);
    isEqual &= (this->stimulus.size() == other.stimulus.size());
    isEqual &= (this->data.size() == other.data.size());
    
    // Comparing data takes time. Can we return now?
    if (!isEqual) { return(false); }
    
    for (unsigned int i = 0; i < points; i++) {
        isEqual &= (this->stimulus[i] == other.stimulus[i]);
        isEqual &= (this->data[i].size() == other.data[i].size());
        for (unsigned int j = 0; j < ports; j++) {
            isEqual &= (this->data[i][j].size() == other.data[i][j].size());
            for (unsigned int k = 0; k < ports; k++) {
                double error = abs(this->data[i][j][k] - other.data[i][j][k]);
                isEqual &= (error < TOLERANCE); }
        }
    }
    return(isEqual);
}
ComplexMatrix2D& NetworkData::operator[](int index) {
    return(data[index]);
}
QDataStream& operator<<(QDataStream &stream, RsaToolbox::NetworkData &network_data) {
    stream << ToString(network_data.sweep_type);
    stream << network_data.ports;
    stream << network_data.isBalanced;
    stream << network_data.date_time;
    
    QString touchstone_string;
    QTextStream touchstone_stream(&touchstone_string);
    Touchstone::Write(network_data, touchstone_stream);
    touchstone_stream.flush();
    stream << touchstone_string;
    
    return(stream);
}
QDataStream& operator>>(QDataStream &stream, NetworkData &network_data) {
    QString sweep_type;
    stream >> sweep_type;
    network_data.sweep_type = String_To_SweepType(sweep_type);
    stream >> network_data.ports;
    stream >> network_data.isBalanced;
    stream >> network_data.date_time;
    
    QString touchstone_string;
    stream >> touchstone_string;
    QTextStream touchstone_stream(&touchstone_string);
    Touchstone::Read(network_data, touchstone_stream, network_data.ports);
    return(stream);
}



