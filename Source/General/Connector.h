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
    enum /*class*/ Gender {
        Male      = 0,
        Female    = 1,
        Neutral   = 2
    };
    enum /*class*/ Mode {
        Tem       = 0,
        Waveguide = 1
    };

    Connector();
    Connector(const Connector &other);
    Connector(QString type, Gender gender = Gender::Male);

    bool isUndefined() const;

    bool    isType(const Connector &other) const;
    QString type  ()                       const;
    void setType(const Connector &type);
    void setType(QString          type);

    bool isMale  ()              const;
    bool isFemale()              const;
    bool isGender(Gender gender) const;
    bool isGendered()            const;
    Connector::Gender gender()   const;
    void setGenderNeutral();
    void setMale         ();
    void setFemale       ();
    void setGender(Gender gender);

    Connector getMatingConnector() const;

    double permittivity  () const;
    void   setPermittivity(double permittivity);

    bool isTemMode       () const;
    bool isWaveguideMode () const;
    Mode mode            () const;
    void setTemMode      (double impedance_Ohms = 50.0);
    void setWaveguideMode(double cutoffFrequency_Hz);

    double impedance_Ohms() const;
    void   setImpedance  (double ohms);

    double cutoffFrequency_Hz() const;
    void   setCutoffFrequency(double frequency_Hz);

    QString displayText()   const;
    QString displayGender() const;
    QString genderAbbreviation() const;

    void operator=(const Connector &other);

    static bool        isSameType (QVector<Connector> &connectors);
    static int         maleCount  (QVector<Connector> &connectors);
    static int         femaleCount(QVector<Connector> &connectors);
    static QStringList displayText(QVector<Connector> connectors);

private:
    QString           _type;
    Connector::Gender _gender;
    Mode              _mode;
    double            _permittivity;
    double            _impedance_Ohms;
    double            _cutoffFrequency_Hz;
}; // Connector

bool operator==(const RsaToolbox::Connector &left, const RsaToolbox::Connector &right);
bool operator!=(const RsaToolbox::Connector &left, const RsaToolbox::Connector &right);
QDataStream& operator<<(QDataStream &stream, const RsaToolbox::Connector &connector);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::Connector &connector);
} // RsaToolbox


Q_DECLARE_METATYPE(RsaToolbox::Connector)
Q_DECLARE_METATYPE(RsaToolbox::Connector::Gender)
Q_DECLARE_METATYPE(RsaToolbox::Connector::Mode)


#endif // CONNECTOR_H

