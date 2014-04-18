#ifndef CALKIT_H
#define CALKIT_H


// Rsa
#include "Definitions.h"
#include "Connector.h"
#include "CalStandard.h"

// Qt
#include <QString>
#include <QVector>


namespace RsaToolbox {

class CalibrationKit {
public:
    CalibrationKit();
    CalibrationKit(QString name);
    CalibrationKit(QString name, QVector<CalStandard> standards);

    bool hasStandard(CalStandardType type, Connector connector);
    bool hasStandard(CalStandardType type, uint port);
    bool hasStandard(CalStandardType type, Connector connector1, Connector connector2);
    bool hasStandard(CalStandardType type, uint port1, uint port2);

    QString name();
    QString label();

    double minimumFrequency_Hz();
    double maximumFrequency_Hz();

    QVector<CalStandard>& standards();

    CalStandard& standard(CalStandardType type, Connector connector);
    CalStandard& standard(CalStandardType type, uint port);
    CalStandard& standard(CalStandardType type, Connector connector1, Connector connector2);
    CalStandard& standard(CalStandardType type, uint port1, uint port2);

    void AddStandard(CalStandard standard);
    void ClearStandards();

    void operator=(const CalibrationKit &other);


private:
    QString _name;
    QString _label;
    QVector<CalStandard> _standards;
};
}

#endif // CALKIT_H
