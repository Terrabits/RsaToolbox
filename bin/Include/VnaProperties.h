#ifndef VNAPROPERTIES_H
#define VNAPROPERTIES_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QObject>
#include <QVector>
#include <QString>
#include <QScopedPointer>


namespace RsaToolbox {

class Vna;

class VnaProperties : public QObject
{
    Q_OBJECT

public:

    enum /*class*/ Model {
        Zva = 0,
        Zvb = 1,
        Zvh = 2,
        Zvl = 3,
        Zvt = 4,
        Znb = 10,
        Znbt = 11,
        Znc = 12,
        Znd = 13,
        Znp = 14,
        Unknown = 1000
    };


    explicit VnaProperties(QObject *parent = 0);
    VnaProperties(const VnaProperties &other);
    VnaProperties(Vna *vna, QObject *parent = 0);
    ~VnaProperties();

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

    QRowVector ifBandwidthMantissa_Hz();
    QRowVector ifBandwidthMantissa_KHz();
    QRowVector ifBandwidthMantissa_MHz();
    QRowVector ifBandwidthValues_Hz();

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
    QScopedPointer<Vna> _placeholder;

};


QString toString(VnaProperties::Model model);
QString toSetFileExtension(VnaProperties::Model model);


} // RsaToolbox

Q_DECLARE_METATYPE(RsaToolbox::VnaProperties::Model)


#endif // VNAPROPERTIES_H
