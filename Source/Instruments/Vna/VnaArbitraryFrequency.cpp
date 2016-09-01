#include "VnaArbitraryFrequency.h"


// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QDebug>


VnaArbitraryFrequency::VnaArbitraryFrequency() :
    _numerator  (1    ),
    _denominator(1    ),
    _offset_Hz  (0    )
{

}
VnaArbitraryFrequency::VnaArbitraryFrequency(double numerator, double denominator, double offset_Hz) :
    _numerator  (numerator  ),
    _denominator(denominator),
    _offset_Hz  (offset_Hz  )
{

}

VnaArbitraryFrequency::~VnaArbitraryFrequency()
{

}

bool VnaArbitraryFrequency::isOn() const {
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
    _numerator       = 1.0  ;
    _denominator     = 1.0  ;
    _offset_Hz       = 0.0  ;
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

void VnaArbitraryFrequency::setNumerator  (double numerator  ) {
    _numerator = numerator;
}
void VnaArbitraryFrequency::setDenominator(double denominator) {
    _denominator = denominator;
}
void VnaArbitraryFrequency::setOffset     (double offset, RsaToolbox::SiPrefix prefix) {
    _offset_Hz = offset * toDouble(prefix);
}

bool operator==(const VnaArbitraryFrequency &l, const VnaArbitraryFrequency &r) {
    if (l.numerator()       != r.numerator())
        return false;
    if (l.denominator()     != r.denominator())
        return false;
    if (l.offset_Hz()       != r.offset_Hz())
        return false;

    // Else
    return true;
}
bool operator!=(const VnaArbitraryFrequency &l, const VnaArbitraryFrequency &r) {
    return !(l == r);
}
