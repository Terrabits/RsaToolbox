#ifndef CONNECTOR_H
#define CONNECTOR_H


// Rsa
#include "Definitions.h"

// Qt
#include <QString>
#include <QStringList>
#include <QMetaType>
#include <QDataStream>


namespace RsaToolbox {


class Connector {
public:

    enum Gender {
        Male = 0,
        Female = 1,
        Neutral = 2
    };
    enum Type {
        N_50_OHM_CONNECTOR = 0,
        N_75_OHM_CONNECTOR = 1,
        mm_7_CONNECTOR = 2,
        mm_3_5_CONNECTOR = 3,
        mm_2_92_CONNECTOR = 4,
        mm_2_4_CONNECTOR = 5,
        mm_1_85_CONNECTOR = 6,
        in_7_16_CONNECTOR = 7,
        TYPE_F_75_OHM_CONNECTOR = 8,
        BNC_50_OHM_CONNECTOR = 9,
        BNC_75_OHM_CONNECTOR = 10,
        CUSTOM_CONNECTOR = 11,
        UNKNOWN_CONNECTOR = 12
    };

    Connector();
    Connector(const Connector &other);
    Connector(Type type, Gender gender = Gender::Male);
    Connector(QString customType, Gender gender = Gender::Male);

    QString displayText() const;
    QString displayType() const;
    QString displayGender() const;
    QString genderAbbreviation() const;

    bool isType(Connector &other) const;
    bool isNotType(Connector &other) const;
    bool isCustomType() const;
    bool isNotCustomType() const;

    bool isGender(Gender gender) const;
    bool isMale() const;
    bool isNotMale() const;
    bool isFemale() const;
    bool isNotFemale() const;
    bool isGenderNeutral() const;
    bool isGenderSpecific() const;

    Type type() const;
    QString customType() const;
    Connector::Gender gender() const;

    Connector getMatingConnector() const;

    void setType(const Connector &type);
    void setType(Type type);
    void setCustomType(QString type);
    void setGender(Gender gender);

    void operator=(const Connector &other);

    static QStringList displayText(QVector<Connector> connectors);
    static QString displayType(Type type);
    static bool isSingleConnectorType(QVector<Connector> &connectors);
    static int numberOfMaleConnectors(QVector<Connector> &connectors);
    static int numberOfFemaleConnectors(QVector<Connector> &connectors);

private:
    Type _type;
    QString _customType;
    Connector::Gender _gender;
};

bool operator==(const RsaToolbox::Connector &left, const RsaToolbox::Connector &right);
bool operator!=(const RsaToolbox::Connector &left, const RsaToolbox::Connector &right);
QDataStream& operator<<(QDataStream &stream, const RsaToolbox::Connector &connector);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::Connector &connector);

} // RsaToolbox

Q_DECLARE_METATYPE(RsaToolbox::Connector)
Q_DECLARE_METATYPE(RsaToolbox::Connector::Type)
Q_DECLARE_METATYPE(RsaToolbox::Connector::Gender)


#endif // CONNECTOR_H

