#ifndef VNAPULSETYPE_H
#define VNAPULSETYPE_H

#include <QString>
namespace RsaToolbox {
    enum /*class*/ VnaPulseType {
        Single,
        Train,
        ConstantHigh,
        ConstantLow
    };
}

RsaToolbox::VnaPulseType vnaPulseTypeFromScpi(QString scpi);
QString toScpi(RsaToolbox::VnaPulseType type);

#endif // VNAPULSETYPE_H
