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


enum VnaStandardType {
    OPEN_STANDARD_TYPE,
    SHORT_STANDARD_TYPE,
    OFFSET_SHORT1_STANDARD_TYPE,
    OFFSET_SHORT2_STANDARD_TYPE,
    OFFSET_SHORT3_STANDARD_TYPE,
    MATCH_STANDARD_TYPE,
    SLIDING_MATCH_STANDARD_TYPE,
    REFLECT_STANDARD_TYPE,
    THRU_STANDARD_TYPE,
    LINE_STANDARD_TYPE,
    LINE2_STANDARD_TYPE,
    LINE3_STANDARD_TYPE,
    ATTENUATION_STANDARD_TYPE,
    SYMMETRIC_NETWORK_STANDARD_TYPE,
    ISOLATION_STANDARD_TYPE,
    UNKNOWN_STANDARD_TYPE
};

class VnaCalStandard {
public:
    VnaCalStandard();
    VnaCalStandard(VnaStandardType type, Connector connector);
    VnaCalStandard(VnaStandardType type, uint port);
    VnaCalStandard(VnaStandardType type, Connector connector1, Connector connector2);
    VnaCalStandard(VnaStandardType type, uint port1, uint port2);

    QString displayText() const;
    QString displayType() const;

    bool isType(VnaStandardType type) const;
    bool isNotType(VnaStandardType type) const;
    bool isGender(Connector::Gender gender) const;
    bool isGender(Connector::Gender gender1, Connector::Gender gender2) const;

    bool isMale() const;
    bool isFemale() const;

    bool isPortSpecific() const;
    bool isPortSpecific(uint port) const;
    bool isPortSpecific(uint port1, uint port2) const;
    bool isNotPortSpecific() const;

    bool isSinglePort() const;
    static bool isSinglePort(VnaStandardType type);
    bool isTwoPort() const;
    static bool isTwoPort(VnaStandardType type);

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


    VnaStandardType type() const;

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


    void setType(VnaStandardType type);

    void setMinimumFrequency(double frequency_Hz);
    void setMaximumFrequency(double frequency_Hz);

    void setPort(uint port);
    void setPorts(uint port1, uint port2);

    void setConnector(Connector connector);
    void setConnectors(Connector connector1, Connector connector2);

    void setLabel(QString label);

    void setTouchstoneFile(QString path);

    VnaStandardModel model() const;
    void setModel(VnaStandardModel model);
    void setModel(double eLength_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3, double R_Ohms);

    void setOpenModel(VnaStandardModel model);
    void setOpenModel(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3);
    void setOpenModel(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3, double R_Ohms);

    void setShortModel(VnaStandardModel model);
    void setShortModel(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3);
    void setShortModel(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3, double R_Ohms);

    void setMatchModel(VnaStandardModel model);
    void setMatchModel(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms);
    void setMatchModel(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3, double R_Ohms);

    void setReflectModel(VnaStandardModel model);
    void setReflectModel(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3, double R_Ohms);

    void setThruModel(VnaStandardModel model);
    void setThruModel(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms);

    void setLineModel(VnaStandardModel model);
    void setLineModel(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms);
    void setLine2Model(VnaStandardModel model);
    void setLine2Model(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms);
    void setLine3Model(VnaStandardModel model);
    void setLine3Model(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms);

    void setSymmetricNetworkModel(VnaStandardModel model);
    void setSymmetricNetworkModel(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms);
    void setSymmetricNetworkModel(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3);

    void setDirectConnection(double Z0_Ohms);

    void clear();
    void clearPorts();
    void clearConnectors();

    void operator=(const VnaCalStandard &other);

    static QStringList displayText(const QVector<VnaCalStandard> &standards);

private:
    VnaStandardType _type;
    QString _label;

    double _min_freq_Hz;
    double _max_freq_Hz;

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
Q_DECLARE_METATYPE(RsaToolbox::VnaStandardType)

#endif // VNACALSTANDARD_H

