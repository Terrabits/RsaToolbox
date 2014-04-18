#ifndef NETWORK_DATA_H
#define NETWORK_DATA_H

// Rsa
#include "Definitions.h"

// Qt
#include <QString>
#include <QDateTime>
#include <QDataStream>

// C++ std lib
#include <complex>
#include <vector>


namespace RsaToolbox
{
class NetworkData {
public:
    SweepType sweep_type;
    NetworkParameter network_parameter;
    unsigned int ports;
    unsigned int points;
    ComplexFormat format;
    double impedance; // Ohms
    bool isBalanced;
    QDateTime date_time;

    // Data
    SiPrefix stimulus_prefix;
    RowVector stimulus;
    ComplexMatrix3D data;

    // Constructor
    NetworkData();

    // Actions
    bool isValid(void);
    void GetDb(int output_port, int input_port, RowVector &decibels);
    RowVector GetDb(int output_port, int input_port);
    void GetMagnitude(int output_port, int input_port, RowVector &magnitude);
    void GetAngle(int output_port, int input_port, RowVector &angle_degrees);
    void GetStimulus(RowVector &stimulus, SiPrefix &stimulus_prefix);

    // Operators
    operator QString();
    bool operator==(NetworkData &network);
    ComplexMatrix2D& operator[](int index);
};
}

QDataStream& operator<<(QDataStream &stream, RsaToolbox::NetworkData &network_data);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::NetworkData &network_data);

#endif



