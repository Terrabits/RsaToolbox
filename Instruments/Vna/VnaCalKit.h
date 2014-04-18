#ifndef VnaCalKit_H
#define VnaCalKit_H


// RsaToolbox
#include "Definitions.h"
#include "NameLabel.h"
#include "Connector.h"
#include "VnaCalStandard.h"

// Qt
#include <QObject>
#include <QStringList>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;

class VnaCalKit : public QObject
{
private: Q_OBJECT

public:
    explicit VnaCalKit(QObject *parent = 0);
    VnaCalKit(const VnaCalKit &other);
    VnaCalKit(Vna *vna, NameLabel nameLabel, QObject *parent = 0);

    bool isConnectorType(Connector type);
    bool has(VnaCalStandard standard);
    bool has(VnaStandardType type, ConnectorGender gender);
    bool has(VnaStandardType type, uint port);
    bool has(VnaStandardType type, ConnectorGender gender1, ConnectorGender gender2);
    bool has(VnaStandardType type, uint port1, uint port2);

    bool hasOpen(uint port);
    bool hasMaleOpen();
    bool hasFemaleOpen();

    bool hasShort(uint port);
    bool hasMaleShort();
    bool hasFemaleShort();

    bool hasMatch(uint port);
    bool hasMaleMatch();
    bool hasFemaleMatch();

    bool hasThru(ConnectorGender gender1, ConnectorGender gender2);
    bool hasThru(uint port1, uint port2);

    Connector connectorType();
    QVector<VnaCalStandard> standards();

    void addStandard(VnaCalStandard standard);

    void operator=(VnaCalKit const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    NameLabel _nameLabel;
    
    bool isFullyInitialized() const;

    void standardDetails(VnaCalStandard &std, Connector type);
    QStringList standardsList();
    QVector<VnaCalStandard> standardsSummary();

    void addStandardByTouchstone(VnaCalStandard &standard);

    void addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3);
    void addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, double R); // OSM, SymmN
    void addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, double R, uint port);

    void addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0);
    void addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, uint port1, uint port2);
    void addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, uint port1, uint port2); // Symm Network
};
}

#endif // VnaCalKit_H
