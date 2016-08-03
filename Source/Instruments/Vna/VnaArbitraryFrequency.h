#ifndef VNAARBITRARYFREQUENCY_H
#define VNAARBITRARYFREQUENCY_H


// RsaToolbox
#include "Definitions.h"

namespace RsaToolbox {

struct VnaArbitraryFrequency
{
public:
    VnaArbitraryFrequency();
    VnaArbitraryFrequency(double numerator, double denominator, double offset_Hz, bool isGeneratorPort = false, bool isRfOff = false);
    ~VnaArbitraryFrequency();

    // isOn : Non default settings?
    // clear: default settings (off)
    bool   isOn() const;
    void   clear();

    bool   isGeneratorPort() const;
    bool   isRfOff    () const;
    double numerator  () const;
    double denominator() const;
    double offset_Hz  () const;
    void   setGeneratorPort(bool isGenerator  );
    void   rfOn            (bool isOn  = true );
    void   rfOff           (bool isOff = true );
    void   setNumerator    (double numerator  );
    void   setDenominator  (double denominator);
    void   setOffset       (double offset, RsaToolbox::SiPrefix prefix = RsaToolbox::SiPrefix::None);

private:
    bool   _isGeneratorPort;
    bool   _isRfOff    ;
    double _numerator  ;
    double _denominator;
    double _offset_Hz  ;
};
} // RsaToolbox


#endif // VNAARBITRARYFREQUENCY_H
