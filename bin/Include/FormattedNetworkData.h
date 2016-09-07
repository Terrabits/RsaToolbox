#ifndef FORMATTED_NETWORK_DATA_H
#define FORMATTED_NETWORK_DATA_H


// RsaToolbox
#include "Definitions.h"
#include "FormattedComplex.h"

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

class FormattedNetworkData
{
public:
    FormattedNetworkData();
    FormattedNetworkData(const FormattedNetworkData &other);

    bool isSParameter();
    bool isYParameter();
    bool isZParameter();
    bool isHParameter();
    bool isGParameter();
    NetworkParameter parameter();
    void setParameter(NetworkParameter parameter);

    QString comment() const;
    void setComment(QString comment);
    QString timestamp() const;

    ComplexFormat format() const;
    void setFormat(ComplexFormat format);

    uint numberOfPorts() const;
    void setNumberOfPorts(uint ports);
    QString portComment(uint port) const;
    void setPortComment(uint port, QString comment);

    double referenceImpedance_Ohms() const;
    void setReferenceImpedance(double Ohms);

    Units xUnits() const;
    SiPrefix xPrefix() const;
    void setXUnits(Units units, SiPrefix prefix = SiPrefix::None);

    uint points() const;
    QRowVector &x();
    FormattedComplexMatrix3D &y();
    FormattedComplexRowVector y(uint outputPort, uint inputPort) const;
    QRowVector y_dB(uint outputPort, uint inputPort) const;
    QRowVector y_magnitude(uint outputPort, uint inputPort) const;
    QRowVector y_phase_deg(uint outputPort, uint inputPort) const;
    QRowVector y_phase_rad(uint outputPort, uint inputPort) const;
    QRowVector y_vswr(uint port) const;
    QRowVector y_real(uint outputPort, uint inputPort) const;
    QRowVector y_imaginary(uint outputPort, uint inputPort) const;
    void setData(QRowVector const &x, FormattedComplexMatrix3D const &y);

    // Operators
    void operator=(const FormattedNetworkData &other);
    void write(QDataStream &stream) const;
    void read(QDataStream &stream);

private:
    QDateTime _timestamp;
    QString _comment;
    QStringList _portComments;

    NetworkParameter _parameter;
    ComplexFormat _format;
    double _impedance_Ohms;
    uint _ports;
    uint _points;

    QRowVector _x;
    Units _xUnits;
    SiPrefix _xPrefix;

    FormattedComplexMatrix3D _y;
};

}
QDataStream& operator<<(QDataStream &stream, const RsaToolbox::FormattedNetworkData &data);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::FormattedNetworkData &data);
Q_DECLARE_METATYPE(RsaToolbox::FormattedNetworkData)


#endif // FORMATTED_NETWORK_DATA_H



