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
    Q_OBJECT

public:
    explicit VnaCalKit(QObject *parent = 0);
    VnaCalKit(const VnaCalKit &other);
    VnaCalKit(Vna *vna, NameLabel nameLabel, QObject *parent = 0);
    ~VnaCalKit();

    NameLabel nameLabel() const;

    bool isConnectorType(Connector type);
    bool isAgilentModel();

    bool has(VnaCalStandard standard);
    bool has(VnaCalStandard::Type type, Connector::Gender gender);
    bool has(VnaCalStandard::Type type, uint port);
    bool has(VnaCalStandard::Type type, Connector::Gender gender1, Connector::Gender gender2);
    bool has(VnaCalStandard::Type type, uint port1, uint port2);

    bool hasOpen();
    bool hasOpen(uint port);
    bool hasMaleOpen();
    bool hasFemaleOpen();

    bool hasShort();
    bool hasShort(uint port);
    bool hasMaleShort();
    bool hasFemaleShort();

    bool hasOffsetShort1();
    bool hasMaleOffsetShort1();
    bool hasFemaleOffsetShort1();

    bool hasOffsetShort2();
    bool hasMaleOffsetShort2();
    bool hasFemaleOffsetShort2();

    bool hasOffsetShort3();
    bool hasMaleOffsetShort3();
    bool hasFemaleOffsetShort3();

    bool hasMatch();
    bool hasMatch(uint port);
    bool hasMaleMatch();
    bool hasFemaleMatch();

    bool hasThru();
    bool hasThru(uint port1, uint port2);
    bool hasThru(Connector::Gender gender1, Connector::Gender gender2);

    void useAgilentModel();
    void useRohdeModel();

    QVector<VnaCalStandard> standards();
    void addStandard(VnaCalStandard standard);

    Connector connectorType();
    void setConnectorType(const Connector &connector);

    void copy(const NameLabel &newNameLabel);

    void operator=(const VnaCalKit &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    NameLabel _nameLabel;
    
    bool isFullyInitialized() const;

    QStringList standardsList();
    QVector<VnaCalStandard> standardsSummary();
    void standardDetails(VnaCalStandard &standard, Connector type);
    void parse(VnaCalStandard &standard, QString scpi);

    void addStandardByTouchstone(VnaCalStandard &standard);
    void addStandardByModel(VnaCalStandard &standard);
};
}

#endif // VnaCalKit_H
