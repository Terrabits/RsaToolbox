#ifndef VnaCalUnit_H
#define VnaCalUnit_H


// RsaToolbox
#include "Definitions.h"
#include "Connector.h"

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;

class VnaCalUnit : public QObject
{
private: Q_OBJECT

public:
    explicit VnaCalUnit(QObject *parent = 0);
    VnaCalUnit(const VnaCalUnit &other);
    VnaCalUnit(Vna *vna, QString id, QObject *parent = 0);
    ~VnaCalUnit();

    QString id() const;

    double minimunFrequency_Hz();
    double maximumFrequency_Hz();
    uint ports();

    bool hasConnector(Connector connector);
    bool hasConnector(QString calName, Connector connector);
    QVector<Connector> physicalConnectors();
    QVector<Connector> connectorsFromLatestCal();
    QVector<Connector> connectorsFrom(QString calName);
    QVector<uint> portsOfType(Connector connector);
    QVector<uint> portsOfTypeFromLatestCal(Connector connector);
    QVector<uint> portsOfType(QString calName, Connector connector);

    QStringList calibrations();
    void frequencyRange(QString calName, double &min_Hz, double &max_Hz);
    // QString calDate(QString calName);

    void exportFactoryCal(QString path);
    void exportLatestCal(QString path);
    void exportCalibration(QString calName, QString path);

    bool isWarmedUp();
    void setOpen();
    void setOpen(uint port);
    void setOpen(QVector<uint> ports);
    void setShort();
    void setShort(uint port);
    void setShort(QVector<uint> ports);
    void setMatch();
    void setMatch(uint port);
    void setMatch(QVector<uint> ports);
    void setThru(uint port1, uint port2);

    void operator=(VnaCalUnit const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QString _id;
    bool isFullyInitialized() const;

    void select();
    
};
}

#endif // VnaCalUnit_H
