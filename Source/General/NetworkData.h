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

    bool isSParameter() const;
    bool isYParameter() const;
    bool isZParameter() const;
    bool isHParameter() const;
    bool isGParameter() const;
    NetworkParameter parameter() const;
    void setParameter(NetworkParameter parameter);

    QString comment() const;
    void setComment(const QString &comment);
    QString timestamp() const;
    void setTimestamp(const QDateTime &dateTime = QDateTime::currentDateTime());

    uint ports() const;
    void setPorts(uint ports);
    QString portComment(uint port) const;
    void setPortComment(uint port, const QString &comment);

    double referenceImpedance_Ohms() const;
    void setReferenceImpedance(double Ohms);

    Units xUnits() const;
    SiPrefix xPrefix() const;
    void setXUnits(Units units, SiPrefix prefix = SiPrefix::None);

    uint points() const;
    QRowVector &x();
    ComplexMatrix3D &y();
    ComplexRowVector y(uint outputPort, uint inputPort) const;
    QRowVector y_dB(uint outputPort, uint inputPort) const;
    QRowVector y_magnitude(uint outputPort, uint inputPort) const;
    QRowVector y_phase_deg(uint outputPort, uint inputPort) const;
    QRowVector y_phase_rad(uint outputPort, uint inputPort) const;
    QRowVector y_vswr(uint port) const;
    QRowVector y_real(uint outputPort, uint inputPort) const;
    QRowVector y_imaginary(uint outputPort, uint inputPort) const;

    void clear();
    void resize(uint ports, uint points);
    void setPoints(uint points);
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



