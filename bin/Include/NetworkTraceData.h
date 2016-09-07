#ifndef NETWORKTRACEDATA_H
#define NETWORKTRACEDATA_H


// RsaToolbox
#include "Definitions.h"
#include "BalancedPort.h"

// Qt
#include <QString>
#include <QDateTime>
#include <QMetaType>
#include <QFile>
#include <QTextStream>
#include <QDataStream>

// Std lib
//

namespace RsaToolbox {

class NetworkTraceData
{
public:
    NetworkTraceData();
    NetworkTraceData(const NetworkTraceData &other);

    bool isSParameter();
    bool isYParameter();
    bool isZParameter();
    bool isHParameter();
    bool isGParameter();
    void setParameter(NetworkParameter parameter);

    QString comment();
    void setComment(QString comment);
    QString timestamp();

    uint outputPort();
    void setOutputPort(uint logicalPort);
    void outputPort(BalancedPort &port);
    void setOutputPort(BalancedPort port);
    QString outputPortComment();
    void setOutputPortComment(QString comment);

    uint inputPort();
    void setInputPort(uint logicalPort);
    void inputPort(BalancedPort &port);
    void setInputPort(BalancedPort port);
    QString inputPortComment();
    void setInputPortComment(QString comment);

    Units xUnits();
    SiPrefix xPrefix();
    void setXUnits(Units units, SiPrefix prefix = SiPrefix::None);

    uint points();
    QRowVector x();
    ComplexRowVector y();
    QRowVector y_dB();
    QRowVector y_magnitude();
    QRowVector y_phase_deg();
    QRowVector y_phase_rad();
    QRowVector y_vswr();
    QRowVector y_real();
    QRowVector y_imaginary();
    void setData(QRowVector const &x, ComplexRowVector const &y);

    void operator=(const NetworkTraceData &other);
    // void toCsvFile(QFile &file, CsvFormat format);

private:
    QDateTime _timestamp;
    QString _comment;
    QString _outputPortComment;
    QString _inputPortComment;

    NetworkParameter _parameter;
    double _impedance_Ohms;
    uint _points;

    BalancedPort _outputPort;
    BalancedPort _inputPort;

    QRowVector _x;
    Units _xUnits;
    SiPrefix _xPrefix;

    ComplexRowVector _y;
};

}
Q_DECLARE_METATYPE(RsaToolbox::NetworkTraceData)

// QDataStream& operator<<(QDataStream &stream, RsaToolbox::NetworkTraceData &trace);
// QDataStream& operator>>(QDataStream &stream, RsaToolbox::NetworkTraceData &trace);

#endif // NETWORKTRACEDATA_H
