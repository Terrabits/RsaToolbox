#ifndef NETWORK_DATA_H
#define NETWORK_DATA_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QMetaType>
#include <QDateTime>
#include <QFile>
#include <QDataStream>

// Std lib
//

namespace RsaToolbox {

class NetworkData
{
public:
    NetworkData();
    NetworkData(const NetworkData &other);

    bool isSParameter();
    bool isYParameter();
    bool isZParameter();
    bool isHParameter();
    bool isGParameter();
    NetworkParameter parameter();
    void setParameter(NetworkParameter parameter);

    QString comment();
    void setComment(QString comment);
    QString timestamp();

    uint numberOfPorts();
    void setNumberOfPorts(uint ports);
    QString portComment(uint port);
    void setPortComment(uint port, QString comment);

    double referenceImpedance_Ohms();
    void setReferenceImpedance(double Ohms);

    Units xUnits();
    SiPrefix xPrefix();
    void setXUnits(Units units, SiPrefix prefix = SiPrefix::None);

    uint points();
    QRowVector &x();
    ComplexMatrix3D &y();
    ComplexRowVector y(uint outputPort, uint inputPort);
    QRowVector y_dB(uint outputPort, uint inputPort);
    QRowVector y_magnitude(uint outputPort, uint inputPort);
    QRowVector y_phase_deg(uint outputPort, uint inputPort);
    QRowVector y_phase_rad(uint outputPort, uint inputPort);
    QRowVector y_vswr(uint port);
    QRowVector y_real(uint outputPort, uint inputPort);
    QRowVector y_imaginary(uint outputPort, uint inputPort);
    void setData(QRowVector const &x, ComplexMatrix3D const &y);

    // Operators
    void operator=(const NetworkData &other);
    void write(QDataStream &stream) const;
    void read(QDataStream &stream);

private:
    QDateTime _timestamp;
    QString _comment;
    QStringList _portComments;

    NetworkParameter _parameter;
    double _impedance_Ohms;
    uint _ports;
    uint _points;

    QRowVector _x;
    Units _xUnits;
    SiPrefix _xPrefix;

    ComplexMatrix3D _y;
};

}
QDataStream& operator<<(QDataStream &stream, const RsaToolbox::NetworkData &data);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::NetworkData &data);
Q_DECLARE_METATYPE(RsaToolbox::NetworkData)


#endif // NETWORK_DATA_H



