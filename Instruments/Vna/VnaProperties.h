#ifndef VNAPROPERTIES_H
#define VNAPROPERTIES_H

#include "Definitions.h"

#include <QObject>
#include <QVector>
#include <QString>
#include <QScopedPointer>

namespace RsaToolbox {
class Vna;

enum VnaModel {
    ZVA_MODEL,
    ZVB_MODEL,
    ZVH_MODEL,
    ZVL_MODEL,
    ZVT_MODEL,
    ZNB_MODEL,
    ZNBT_MODEL,
    ZNC_MODEL,
    ZNP_MODEL,
    UNKNOWN_MODEL };

class VnaProperties : public QObject
{
private: Q_OBJECT

public:
    explicit VnaProperties(QObject *parent = 0);
    VnaProperties(VnaProperties &other);
    VnaProperties(Vna *vna, QObject *parent = 0);

    VnaModel model();
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

QString toString(VnaModel model);
QString toSetFileExtension(VnaModel model);
}
Q_DECLARE_METATYPE(RsaToolbox::VnaModel)


#endif // VNAPROPERTIES_H
