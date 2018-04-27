#include "vnapulsetype.h"

QString toScpi(VnaPulseType type) {
    switch (type) {
    case VnaPulseType::Single:
        return "SING";
    case VnaPulseType::Train:
        return "TRA";
    case VnaPulseType::ConstantHigh:
        return "CHIG";
    case VnaPulseType::ConstantLow:
        return "CLOW";
    default:
        return QString();
    }
}
VnaPulseType vnaPulseTypeFromScpi(QString scpi) {
    scpi = scpi.trimmed().toUpper();
    if (scpi.startsWith("SING")) {
        return VnaPulseType::Single;
    }
    if (scpi.startsWith("TRA")) {
        return VnaPulseType::Train;
    }
    if (scpi.startsWith("CHIG")) {
        return VnaPulseType::ConstantHigh;
    }
    if (scpi.startsWith("CLOW")) {
        return VnaPulseType::ConstantLow;
    }
    // Default?
    return VnaPulseType::Single;
}
