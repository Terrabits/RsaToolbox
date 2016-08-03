#include "VnaArbitraryFrequency.h"


// RsaToolbox
#include "General.h"
using namespace RsaToolbox;


VnaArbitraryFrequency::VnaArbitraryFrequency() :
    _isGeneratorPort(false),
    _isRfOff    (false),
    _numerator  (1    ),
    _denominator(1    ),
    _offset_Hz  (0    )
{

}
VnaArbitraryFrequency::VnaArbitraryFrequency(double numerator, double denominator, double offset_Hz, bool isGenerator, bool isRfOff) :
    _isGeneratorPort(isGenerator),
    _isRfOff    (isRfOff    ),
    _numerator  (numerator  ),
    _denominator(denominator),
    _offset_Hz  (offset_Hz  )
{

}

VnaArbitraryFrequency::~VnaArbitraryFrequency()
{

}

bool VnaArbitraryFrequency::isOn() const {
    if (_isGeneratorPort)
        return true;
    if (_isRfOff    )
        return true;
    if (_numerator   != 1.0)
        return true;
    if (_denominator != 1.0)
        return true;
    if (_offset_Hz   != 0.0)
        return true;

    // Else
    return false;
}
void VnaArbitraryFrequency::clear() {
    _isGeneratorPort = false;
    _isRfOff         = false;
    _numerator       = 1.0  ;
    _denominator     = 1.0  ;
    _offset_Hz       = 0.0  ;
}

bool VnaArbitraryFrequency::isGeneratorPort  () const {
    return _isGeneratorPort;
}
bool VnaArbitraryFrequency::isRfOff      () const {
    return _isRfOff;
}
double VnaArbitraryFrequency::numerator  () const {
    return _numerator;
}
double VnaArbitraryFrequency::denominator() const {
    return _denominator;
}
double VnaArbitraryFrequency::offset_Hz  () const {
    return _offset_Hz;
}

void VnaArbitraryFrequency::setGeneratorPort  (bool isGenerator  ) {
    _isGeneratorPort = isGenerator;
}
void VnaArbitraryFrequency::rfOn          (bool isOn         ) {
    _isRfOff = !isOn;
}
void VnaArbitraryFrequency::rfOff         (bool isOff        ) {
    _isRfOff = isOff;
}
void VnaArbitraryFrequency::setNumerator  (double numerator  ) {
    _numerator = numerator;
}
void VnaArbitraryFrequency::setDenominator(double denominator) {
    _denominator = denominator;
}
void VnaArbitraryFrequency::setOffset     (double offset, RsaToolbox::SiPrefix prefix) {
    _offset_Hz = offset * toDouble(prefix);
}
