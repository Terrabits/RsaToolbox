#include "VnaGeneratorSettings.h"


// RsaToolbox
#include "Vna.h"
using namespace RsaToolbox;


VnaGeneratorSettings::VnaGeneratorSettings(QObject *parent) :
    QObject(parent)
{
    _placeholder.reset(new Vna());
    _vna = _placeholder.data();
    _channel = 0;
    _index    = 0;
}
VnaGeneratorSettings::VnaGeneratorSettings(const VnaGeneratorSettings &other)
{
    if (other.isFullyInitialized()) {
        _vna     = other._vna;
        _channel = other._channel;
        _index    = other._index;
    }
    else {
        _placeholder.reset(new Vna);
        _vna     = _placeholder.data();
        _channel = 0;
        _index    = 0;
    }
}
VnaGeneratorSettings::VnaGeneratorSettings(Vna *vna, uint channel, uint index, QObject *parent) :
    QObject(parent),
    _vna(vna),
    _channel(channel),
    _index(index)
{

}
VnaGeneratorSettings::~VnaGeneratorSettings()
{

}

bool VnaGeneratorSettings::isPermanentlyOn() {
    QString scpi = ":SOUR%1:POW:GEN%2:PERM?\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(_index);
    return _vna->query(scpi).trimmed() == "1";
}
bool VnaGeneratorSettings::isRfOff() {
    QString scpi = ":SOUR%1:POW:GEN%2:STAT?\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(_index);
    return _vna->query(scpi).trimmed() == "0";
}
void VnaGeneratorSettings::setPermanentlyOn(bool isOn) {
    QString scpi = ":SOUR%1:POW:GEN%2:PERM %3\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(_index);
    scpi = scpi.arg(isOn ? 1 : 0);
    _vna->write(scpi);
}
void VnaGeneratorSettings::rfOff(bool isOff) {
    QString scpi = ":SOUR%1:POW:GEN%2:STAT %3\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(_index);
    scpi = scpi.arg(isOff ? 0 : 1);
    _vna->write(scpi);
}

VnaArbitraryFrequency VnaGeneratorSettings::arbitraryFrequency() {
    QString scpi = ":SOUR%1:FREQ:CONV:ARB:EFR%2?\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(_index);
    QStringList results = _vna->query(scpi).trimmed().split(",");
    if (results.size() != 4) {
        // Error
        return VnaArbitraryFrequency();
    }

    VnaArbitraryFrequency af;
    //                results[0] -> RF Off
    af.setNumerator  (results[1].toDouble());
    af.setDenominator(results[2].toDouble());
    af.setOffset     (results[3].toDouble());
    //                results[4] -> formula type (SWE)
    return af;
}
void VnaGeneratorSettings::setArbitraryFrequency(const VnaArbitraryFrequency &af) {
    QString scpi = ":SOUR%1:FREQ:CONV:ARB:EFR%2 %3,%4,%5,%6?\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(_index);
    scpi = scpi.arg(!isRfOff());
    scpi = scpi.arg(af.numerator());
    scpi = scpi.arg(af.denominator());
    scpi = scpi.arg(af.offset_Hz());
    _vna->write(scpi);
}
void VnaGeneratorSettings::arbitraryFrequencyOff() {
    VnaArbitraryFrequency af;
    af.clear();
    setArbitraryFrequency(af);
}


// private
bool VnaGeneratorSettings::isFullyInitialized() const {
    if (_vna     == NULL)
        return false;
    if (_vna     == _placeholder.data())
        return false;
    if (_channel == 0)
        return false;
    if (_index   == 0)
        return false;

    return true;
}
