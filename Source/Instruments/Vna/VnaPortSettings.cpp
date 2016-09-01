#include "VnaPortSettings.h"


// RsaToolbox
using namespace RsaToolbox;


VnaPortSettings::VnaPortSettings(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel = 0;
    _port    = 0;
}
VnaPortSettings::VnaPortSettings(const VnaPortSettings &other)
{
    if (other.isFullyInitialized()) {
        _vna     = other._vna;
        _channel = other._channel;
        _port    = other._port;
    }
    else {
        _placeholder.reset(new Vna);
        _vna     = _placeholder.data();
        _channel = 0;
        _port    = 0;
    }
}
VnaPortSettings::VnaPortSettings(Vna *vna, uint channel, uint port, QObject *parent) :
    QObject(parent),
    _vna(vna),
    _channel(channel),
    _port(port)
{
    //
}
VnaPortSettings::~VnaPortSettings()
{

}

// Rf power
bool VnaPortSettings::isGenerator() {
    QString scpi = ":SOUR%1:POW%2:PERM?\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(_port);
    return _vna->query(scpi).trimmed() == "1";
}
void VnaPortSettings::setGenerator(bool isGen) {
    QString scpi = ":SOUR%1:POW%2:PERM %3\n";
    scpi = scpi.arg(_channel      );
    scpi = scpi.arg(_port);
    if (isGen) {
        scpi = scpi.arg(1);
    }
    else {
        scpi = scpi.arg(0);
    }
    _vna->write(scpi);
}
bool VnaPortSettings::isRfOff() {
    QString scpi = ":SOUR%1:POW%2:STAT?\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(_port);
    return _vna->query(scpi).trimmed() == "0";
}
void VnaPortSettings::rfOff(bool isOff) {
    QString scpi = ":SOUR%1:POW%2:STAT %3\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(_port);
    if (isOff) {
        scpi = scpi.arg(0);
    }
    else {
        scpi = scpi.arg(1);
    }
    _vna->write(scpi);
}

// Source frequency
bool VnaPortSettings::isArbitrarySourceFrequencyOn() {
    return arbitrarySourceFrequency().isOn();
}
VnaArbitraryFrequency VnaPortSettings::arbitrarySourceFrequency() {
    VnaArbitraryFrequency af;
    af.setGeneratorPort(isGenerator());
    af.rfOff           (isRfOff());

    QString scpi = ":SOUR%1:FREQ%2:CONV:ARB:IFR?\n";
    scpi = scpi.arg(_channel);
    scpi = scpi.arg(_port);
    QStringList results = _vna->query(scpi).trimmed().split(",");
    if (results.size() != 4) {
        // Error
        return af;
    }

    af.setNumerator  (results[0].toDouble());
    af.setDenominator(results[1].toDouble());
    af.setOffset     (results[2].toDouble());
    //                results[3] -> formula type (SWE)
    return af;
}
void VnaPortSettings::setArbitrarySourceFrequency(VnaArbitraryFrequency af) {
    setGenerator(af.isGeneratorPort());
    rfOff       (af.isRfOff        ());

    QString scpi = ":SOUR%1:FREQ%2:CONV:ARB:IFR %3,%4,%5,%6\n";
    scpi = scpi.arg(_channel          );
    scpi = scpi.arg(_port    );
    scpi = scpi.arg(af.numerator  ());
    scpi = scpi.arg(af.denominator());
    scpi = scpi.arg(af.offset_Hz  ());
    scpi = scpi.arg("SWE"); // apply formula
    _vna->write(scpi);
}
void VnaPortSettings::arbitrarySourceFrequencyOff() {
    VnaArbitraryFrequency af;
    af.setGeneratorPort(false);
    af.rfOn            (true );
    af.setNumerator    ( 1.0 );
    af.setDenominator  ( 1.0 );
    af.setOffset       ( 0.0 );
    setSourceArbitraryFreq(af);
}

// private
bool VnaPortSettings::isFullyInitialized() const {
    if (_vna     == NULL)
        return false;
    if (_vna     == _placeholder.data())
        return false;
    if (_channel == 0)
        return false;
    if (_port    == 0)
        return false;

    return true;
}
