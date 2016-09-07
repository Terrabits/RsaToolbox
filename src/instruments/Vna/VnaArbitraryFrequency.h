#ifndef VNAARBITRARYFREQUENCY_H
#define VNAARBITRARYFREQUENCY_H


// RsaToolbox
#include "Definitions.h"

namespace RsaToolbox {

struct VnaArbitraryFrequency
{
public:
    VnaArbitraryFrequency();
    VnaArbitraryFrequency(double numerator, double denominator, double offset_Hz);
    ~VnaArbitraryFrequency();

    // isOn : Non default settings?
    // clear: default settings (off)
    bool   isOn() const;
    void   clear();

    double numerator  () const;
    double denominator() const;
    double offset_Hz  () const;
    void   setNumerator    (double numerator  );
    void   setDenominator  (double denominator);
    void   setOffset       (double offset, RsaToolbox::SiPrefix prefix = RsaToolbox::SiPrefix::None);

private:
    double _numerator  ;
    double _denominator;
    double _offset_Hz  ;
};

} // RsaToolbox

bool operator==(const RsaToolbox::VnaArbitraryFrequency &left, const RsaToolbox::VnaArbitraryFrequency &right);
bool operator!=(const RsaToolbox::VnaArbitraryFrequency &left, const RsaToolbox::VnaArbitraryFrequency &right);


#endif // VNAARBITRARYFREQUENCY_H
