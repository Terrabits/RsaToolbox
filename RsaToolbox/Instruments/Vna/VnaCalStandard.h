#ifndef VNACALSTANDARD_H
#define VNACALSTANDARD_H


// Rsa
#include "Definitions.h"
#include "Connector.h"
#include "VnaStandardModel.h"

// Qt
#include <QString>
#include <QStringList>


namespace RsaToolbox {


class VnaCalStandard {
public:

    enum /*class*/  Type {
        Open,
        Short,
        OffsetShort1,
        OffsetShort2,
        OffsetShort3,
        Match,
        SlidingMatch,
        Reflect,
        Thru,
        Line1,
        Line2,
        Line3,
        Attenuation,
        SymmetricNetwork,
        Isolation,
        Unknown
    };

    VnaCalStandard();
    VnaCalStandard(Type type, Connector connector);
    VnaCalStandard(Type type, uint port);
    VnaCalStandard(Type type, Connector connector1, Connector connector2);
    VnaCalStandard(Type type, uint port1, uint port2);
    VnaCalStandard(const VnaCalStandard &other);

    QString displayText() const;
    QString displayType() const;

    bool isType(Type type) const;
    bool isNotType(Type type) const;
    bool isGender(Connector::Gender gender) const;
    bool isGender(Connector::Gender gender1, Connector::Gender gender2) const;

    bool isMale() const;
    bool isFemale() const;

    bool isPortSpecific() const;
    bool isPortSpecific(uint port) const;
    bool isPortSpecific(uint port1, uint port2) const;
    bool isNotPortSpecific() const;

    bool isSinglePort() const;
    static bool isSinglePort(Type type);
    bool isTwoPort() const;
    static bool isTwoPort(Type type);

    bool isSameStandardAs(VnaCalStandard other) const;

    bool isOpen() const;
    bool isOpen(uint port) const;
    bool isMaleOpen() const;
    bool isFemaleOpen() const;

    bool isShort() const;
    bool isShort(uint port) const;
    bool isMaleShort() const;
    bool isFemaleShort() const;

    bool isOffsetShort1() const;
    bool isMaleOffsetShort1() const;
    bool isFemaleOffsetShort1() const;

    bool isOffsetShort2() const;
    bool isMaleOffsetShort2() const;
    bool isFemaleOffsetShort2() const;

    bool isOffsetShort3() const;
    bool isMaleOffsetShort3() const;
    bool isFemaleOffsetShort3() const;

    bool isMatch() const;
    bool isMatch(uint port) const;
    bool isMaleMatch() const;
    bool isFemaleMatch() const;

    bool isThru() const;
    bool isThruMM() const;
    bool isThruMF() const;
    bool isThruFF() const;
    bool isThru(uint port1, uint port2) const;
    bool isThru(Connector::Gender gender1, Connector::Gender gender2) const;

    bool isTouchstone() const;
    bool isModel() const;
    bool isSameModel(const VnaCalStandard &other) const;


    Type type() const;

    double minimumFrequency_Hz() const;
    double maximumFrequency_Hz() const;

    uint port() const;
    uint port1() const;
    uint port2() const;

    Connector& connector();
    Connector& connector1();
    Connector& connector2();

    Connector::Gender gender() const;
    Connector::Gender gender1() const;
    Connector::Gender gender2() const;

    QString label() const;
    QString touchstone() const;


    void setType(Type type);

    void setPort(uint port);
    void setPorts(uint port1, uint port2);

    void setConnector(Connector connector);
    void setConnectors(Connector connector1, Connector connector2);

    void setLabel(QString label);

    void setTouchstoneFile(QString path);

    VnaStandardModel &model();
    VnaStandardModel model() const;
    void setModel(const VnaStandardModel &model);

    void clear();
    void clearPorts();
    void clearConnectors();

    void operator=(const VnaCalStandard &other);

    static QStringList displayText(const QVector<VnaCalStandard> &standards);

private:
    Type _type;
    QString _label;

    uint _port1;
    Connector _connector1;

    uint _port2;
    Connector _connector2;

    bool _isTouchstone;
    QString _touchstone;

    bool _isModel;
    VnaStandardModel _model;

    void setConnector1(Connector connector1);
    void setConnector2(Connector connector2);
    void sort();
};

void sort(Connector &connector1, Connector &connector2);
void sort(Connector::Gender &gender1, Connector::Gender &gender2);
void sort(uint &port1, uint &port2);
bool operator==(const VnaCalStandard &right, const VnaCalStandard &left);
bool operator!=(const VnaCalStandard &right, const VnaCalStandard &left);
}
Q_DECLARE_METATYPE(RsaToolbox::VnaCalStandard)
Q_DECLARE_METATYPE(RsaToolbox::VnaCalStandard::Type)

#endif // VNACALSTANDARD_H

