#ifndef VNAPROPERTIES_H
#define VNAPROPERTIES_H

#include "Definitions.h"

#include <QObject>
#include <QVector>
#include <QString>
#include <QScopedPointer>

namespace RsaToolbox {
class Vna;

class VnaProperties : public QObject
{
private: Q_OBJECT

public:

    enum Model {
        ZVA_MODEL,
        ZVB_MODEL,
        ZVH_MODEL,
        ZVL_MODEL,
        ZVT_MODEL,
        ZNB_MODEL,
        ZNBT_MODEL,
        ZNC_MODEL,
        ZNP_MODEL,
        UNKNOWN_MODEL
    };

    explicit VnaProperties(QObject *parent = 0);
    VnaProperties(VnaProperties &other);
    VnaProperties(Vna *vna, QObject *parent = 0);

    Model model();
    QString serialNumber();
    QString firmwareVersion();
    QStringList optionsList();

    bool isZvaFamily();
    bool isNotZvaFamily();
    bool isZnbFamily();
    bool isNotZnbFamily();
    bool isKnownModel();
    bool isUnknownModel();

    uint physicalPorts();

    double minimumFrequency_Hz();
    double maximumFrequency_Hz();

    QVector<double> ifBandwidthMantissa_Hz();
    QVector<double> ifBandwidthMantissa_KHz();
    QVector<double> ifBandwidthMantissa_MHz();

    double minimumPower_dBm();
    double maximumPower_dBm();

    bool hasSourceAttenuators();
    QVector<uint> sourceAttenuations_dB();

    bool hasReceiverAttenuators();
    QVector<uint> receiverAttenuations_dB();

    uint maximumPoints();


    void operator=(VnaProperties const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;

};

QString toString(VnaProperties::Model model);
QString toSetFileExtension(VnaProperties::Model model);
}

Q_DECLARE_METATYPE(RsaToolbox::VnaProperties::Model)


#endif // VNAPROPERTIES_H
