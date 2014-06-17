

// RsaToolbox
#include "General.h"
#include "Vna.h"
#include "VnaProperties.h"
using namespace RsaToolbox;

/*!
 * \class RsaToolbox::VnaProperties
 * \ingroup VnaGroup
 * \brief The \c %VnaProperties class
 * provides the immutable properties of the
 * Rohde \& Schwarz VNA.
 */

VnaProperties::VnaProperties(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
}

VnaProperties::VnaProperties(VnaProperties &other)
{
    this->_vna = other._vna;
}

VnaProperties::VnaProperties(Vna *vna, QObject *parent) :
    QObject(parent)
{
    this->_vna = vna;
}

VnaModel VnaProperties::model() {
    QStringList idList = _vna->idString().split(',');
    if (idList.size() < 2)
        return(UNKNOWN_MODEL);

    QString _model = idList[1].toUpper();
    if (_model.contains("ZVA"))
        return(ZVA_MODEL);
    if (_model.contains("ZVB"))
        return(ZVB_MODEL);
    if (_model.contains("ZVH"))
        return(ZVH_MODEL);
    if (_model.contains("ZVL"))
        return(ZVL_MODEL);
    if (_model.contains("ZVT"))
        return(ZVT_MODEL);
    if (_model.contains("ZNBT"))
        return(ZNBT_MODEL);
    if (_model.contains("ZNB"))
        return(ZNB_MODEL);
    if (_model.contains("ZNC"))
        return(ZNC_MODEL);
    if (_model.contains("ZNP"))
        return(ZNP_MODEL);
    // else
    return(UNKNOWN_MODEL);
}
QString VnaProperties::serialNumber() {
    QStringList idList = _vna->idString().split(',');
    if (idList.size() < 3)
        return("");
    else
        return(idList[2].trimmed());
}
QString VnaProperties::firmwareVersion() {
    QStringList idList = _vna->idString().split(',');
    if (idList.size() < 4)
        return("");
    else
        return(idList[3].trimmed());
}
QStringList VnaProperties::optionsList() {
    return(_vna->optionsString().split(',', QString::SkipEmptyParts));
}

bool VnaProperties::isZvaFamily() {
    switch(model()) {
    case ZVA_MODEL:
    case ZVB_MODEL:
    case ZVH_MODEL:
    case ZVL_MODEL:
    case ZVT_MODEL:
        return(true);
    default:
        return(false);
    }
}
bool VnaProperties::isNotZvaFamily() {
    return(!isZvaFamily());
}
bool VnaProperties::isZnbFamily() {
    switch(model()) {
    case ZNB_MODEL:
    case ZNBT_MODEL:
    case ZNC_MODEL:
    case ZNP_MODEL:
        return(true);
    default:
        return(false);
    }
}
bool VnaProperties::isNotZnbFamily() {
    return(!isZnbFamily());
}
bool VnaProperties::isKnownModel() {
    return(!isUnknownModel());
}
bool VnaProperties::isUnknownModel() {
    return(model() == UNKNOWN_MODEL);
}
uint VnaProperties::physicalPorts() {
    return(_vna->query(":INST:PORT:COUN?\n").toUInt());
}

double VnaProperties::minimumFrequency_Hz() {
    return(_vna->query(":SYST:FREQ? MIN\n").toDouble());
}
double VnaProperties::maximumFrequency_Hz() {
    return(_vna->query(":SYST:FREQ? MAX\n").toDouble());
}

QVector<double> VnaProperties::ifBandwidthMantissa_Hz() {
    QVector<double> mantissaValues;
    if (isZnbFamily()) {
        mantissaValues << 1
                       << 2
                       << 5
                       << 10
                       << 20
                       << 50
                       << 100
                       << 200
                       << 500;
    }
    else if (isZvaFamily()) {
        mantissaValues << 1
                       << 2
                       << 3
                       << 4
                       << 5
                       << 7
                       << 10
                       << 15
                       << 20
                       << 30
                       << 50
                       << 70
                       << 100
                       << 150
                       << 200
                       << 300
                       << 500
                       << 700;
    }
    return(mantissaValues);
}
QVector<double> VnaProperties::ifBandwidthMantissa_KHz() {
    QVector<double> mantissaValues;
    if (isZnbFamily()) {
        mantissaValues << 1
                       << 2
                       << 5
                       << 10
                       << 20
                       << 50
                       << 100
                       << 200
                       << 500;
    }
    else if (isZvaFamily()) {
        mantissaValues << 1
                       << 1.5
                       << 2
                       << 3
                       << 5
                       << 7
                       << 10
                       << 15
                       << 20
                       << 30
                       << 50
                       << 70
                       << 100
                       << 150
                       << 200
                       << 300
                       << 500
                       << 700;
    }
    return(mantissaValues);
}
QVector<double> VnaProperties::ifBandwidthMantissa_MHz() {
    QVector<double> mantissaValues;
    if (isZnbFamily()) {

        mantissaValues << 1
                       << 2
                       << 5
                       << 10
                       << 20
                       << 30;
    }
    else if (isZvaFamily()) {
        mantissaValues << 1
                       << 1.5
                       << 2
                       << 3
                       << 5
                       << 7
                       << 10;
    }
    return(mantissaValues);
}

double VnaProperties::minimumPower_dBm() {
    if (isZvaFamily())
        return(-150);
    else if (isZnbFamily())
        return(-40);
    // Default:
    return(-40);
}
double VnaProperties::maximumPower_dBm() {
    if (isZvaFamily())
        return(100);
    else if (isZnbFamily())
        return(10);
    // Default:
    return(10);
}

bool VnaProperties::hasSourceAttenuators() {
//    const uint port1 = 1;
//    uint channel = _vna->createChannel();
//    _vna->clearStatus();
//     _vna->settings().errorDisplayOff();
//     _vna->settings().rfOff(); // turn back on?

     bool isSourceAttenuation = false;
//    _vna->channel(channel).setSourceAttenuation(port1, 0);
//    if (_vna->isError())
//        isSourceAttenuation = false;
//    else
//        isSourceAttenuation = true;

//    _vna->clearStatus();
//    _vna->deleteChannel(channel);
//    _vna->settings().errorDisplayOn();
//    _vna->settings().rfOn(); // should I?
    return(isSourceAttenuation);
}
QVector<uint> VnaProperties::sourceAttenuations_dB() {
    const uint port1 = 1; Q_UNUSED(port1);
    QVector<uint> attenuations;
//    attenuations << 0;
//    uint channel = _vna->createChannel();

//    _vna->clearStatus();
//     _vna->settings().errorDisplayOff();
//     _vna->settings().rfOff(); // turn back on?
//    _vna->channel(channel).setSourceAttenuation(port1, 0);
//    if (_vna->isError()) {
//        _vna->clearStatus();
//    }
//    else {
//        for (double i = 1; i <= 100; i++) {
//            _vna->channel(channel).setSourceAttenuation(port1, i);
//            double attenuation = _vna->channel(channel).sourceAttenuation_dB(port1);
//            if (attenuation == i)
//                attenuations << attenuation;
//        }
//    }

//    _vna->settings().errorDisplayOn();
//    _vna->deleteChannel(channel);
    return(attenuations);
}

bool VnaProperties::hasReceiverAttenuators() {
    //    const uint port1 = 1;
    //    uint channel = _vna->createChannel();
    //    _vna->clearStatus();
    //     _vna->settings().errorDisplayOff();
    //     _vna->settings().rfOff(); // turn back on?

         bool isReceiverAttenuation = false;
    //    _vna->channel(channel).setReceiverAttenuation(port1, 0);
    //    if (_vna->isError())
    //        isReceiverAttenuation = false;
    //    else
    //        isReceiverAttenuation = true;

    //    _vna->clearStatus();
    //    _vna->deleteChannel(channel);
    //    _vna->settings().errorDisplayOn();
    //    _vna->settings().rfOn(); // should I?
        return(isReceiverAttenuation);
}
QVector<uint> VnaProperties::receiverAttenuations_dB() {
    const uint port1 = 1;
    QVector<uint> attenuations;
//    attenuations << 0;
//    uint channel = _vna->createChannel();

//    _vna->clearStatus();
//     _vna->settings().errorDisplayOff();
//     _vna->settings().rfOff(); // turn back on?
//    _vna->channel(channel).setReceiverAttenuation(port1, 0);
//    if (_vna->isError()) {
//        _vna->clearStatus();
//    }
//    else {
//        for (double i = 1; i <= 100; i++) {
//            _vna->channel(channel).setReceiverAttenuation(port1, i);
//            double attenuation = _vna->channel(channel).receiverAttenuation_dB(port1);
//            if (attenuation == i)
//                attenuations << attenuation;
//        }
//    }

//    _vna->settings().errorDisplayOn();
//    _vna->deleteChannel(channel);
    return(attenuations);
}
uint VnaProperties::maximumPoints() {
    if (isZnbFamily())
        return(100001);
    if (isZvaFamily())
        return(60001);
    // else
    return(60001);
}

void VnaProperties::operator=(VnaProperties const &other) {
    this->_vna = other._vna;
}

QString RsaToolbox::toString(VnaModel model) {
    switch(model) {
    case ZVA_MODEL:
        return(QString("ZVA"));
    case ZVB_MODEL:
        return(QString("ZVB"));
    case ZVH_MODEL:
        return(QString("ZVH"));
    case ZVL_MODEL:
        return(QString("ZVL"));
    case ZVT_MODEL:
        return(QString("ZVT"));
    case ZNB_MODEL:
        return(QString("ZNB"));
    case ZNBT_MODEL:
        return(QString("ZNBT"));
    case ZNC_MODEL:
        return(QString("ZNC"));
    case ZNP_MODEL:
        return(QString("ZNP"));
    default:
        // UNKNOWN_MODEL
        return(QString("UNKNOWN"));
    }
}
QString RsaToolbox::toSetFileExtension(VnaModel model) {
    switch(model) {
    case ZVA_MODEL:
    case ZVB_MODEL:
    case ZVH_MODEL:
    case ZVL_MODEL:
    case ZVT_MODEL:
        return(QString(".zvx"));
    case ZNB_MODEL:
    case ZNBT_MODEL:
    case ZNC_MODEL:
    case ZNP_MODEL:
        return(QString(".znx"));
    default:
        // UNKNOWN_MODEL
        return(QString(".rsx"));
    }
}
