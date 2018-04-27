#ifndef VNAPULSETYPE_H
#define VNAPULSETYPE_H

#include <QString>

enum /*class*/ VnaPulseType {
    Single,
    Train,
    ConstantHigh,
    ConstantLow
};

VnaPulseType vnaPulseTypeFromScpi(QString scpi);
QString toScpi(VnaPulseType type);

#endif // VNAPULSETYPE_H
