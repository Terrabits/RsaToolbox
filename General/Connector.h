#ifndef CONNECTOR_H
#define CONNECTOR_H


// Rsa
#include "Definitions.h"

// Qt
#include <QString>
#include <QStringList>
#include <QMetaType>


namespace RsaToolbox {

enum ConnectorType {
    N_50_OHM_CONNECTOR,
    N_75_OHM_CONNECTOR,
    mm_7_CONNECTOR,
    mm_3_5_CONNECTOR,
    mm_2_92_CONNECTOR,
    mm_2_4_CONNECTOR,
    mm_1_85_CONNECTOR,
    in_7_16_CONNECTOR,
    TYPE_F_75_OHM_CONNECTOR,
    BNC_50_OHM_CONNECTOR,
    BNC_75_OHM_CONNECTOR,
    CUSTOM_CONNECTOR,
    UNKNOWN_CONNECTOR };

enum ConnectorGender {
    MALE_GENDER,
    FEMALE_GENDER,
    NEUTRAL_GENDER };

class Connector {
public:
    Connector();
    Connector(const Connector &other);
    Connector(ConnectorType type, ConnectorGender gender = MALE_GENDER);
    Connector(QString customType, ConnectorGender gender = MALE_GENDER);

    QString displayText() const;
    QString displayType() const;
    QString displayGender() const;
    QString genderAbbreviation() const;

    bool isType(Connector &other) const;
    bool isNotType(Connector &other) const;
    bool isCustomType() const;
    bool isNotCustomType() const;

    bool isGender(ConnectorGender gender) const;
    bool isMale() const;
    bool isNotMale() const;
    bool isFemale() const;
    bool isNotFemale() const;
    bool isGenderNeutral() const;
    bool isGenderSpecific() const;

    ConnectorType type() const;
    QString customType() const;
    ConnectorGender gender() const;

    Connector getMatingConnector() const;

    void setType(const Connector type);
    void setType(ConnectorType type);
    void setCustomType(QString type);
    void setGender(ConnectorGender gender);

    void operator=(const Connector &other);

    static QStringList displayText(QVector<Connector> connectors);
    static QString displayType(ConnectorType type);
    static bool isSingleConnectorType(QVector<Connector> &connectors);
    static int numberOfMaleConnectors(QVector<Connector> &connectors);
    static int numberOfFemaleConnectors(QVector<Connector> &connectors);

private:
    ConnectorType _type;
    QString _customType;
    ConnectorGender _gender;
};

ConnectorType toConnectorType(QString vnaScpi);
ConnectorGender toConnectorGender(QString vnaScpi);
QString toVnaScpi(ConnectorType type);
QString toVnaScpi(ConnectorGender gender);
QString toConnectorTypeVnaScpi(Connector connector);
QString toConnectorGenderVnaScpi(Connector connector);
bool operator==(const Connector &left, const Connector &right);
bool operator!=(const Connector &left, const Connector &right);
}
Q_DECLARE_METATYPE(RsaToolbox::Connector)
Q_DECLARE_METATYPE(RsaToolbox::ConnectorType)
Q_DECLARE_METATYPE(RsaToolbox::ConnectorGender)

#endif // CONNECTOR_H

