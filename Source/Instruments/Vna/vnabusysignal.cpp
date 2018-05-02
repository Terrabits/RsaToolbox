#include "vnabusysignal.h"
using namespace RsaToolbox;

#include <cassert>


QString toScpi(VnaBusySignal signal) {
    switch (signal) {
    case VnaBusySignal::Auto:
        return "AUTO";
    case VnaBusySignal::Sweep:
        return "SWE";
    case VnaBusySignal::Segment:
        return "SEGM";
    case VnaBusySignal::PartialPoint:
        return "PPO";
    case VnaBusySignal::Point:
        return "POI";
    default:
        assert(false);
        return "AUTO";
    }
}

VnaBusySignal vnaBusySignalFromScpi(QString scpi) {
    scpi = scpi.trimmed().toUpper();
    if (scpi.startsWith("AUTO")) {
        return VnaBusySignal::Auto;
    }
    else if (scpi.startsWith("SWE")) {
        return VnaBusySignal::Sweep;
    }
    else if (scpi.startsWith("SEGM")) {
        return VnaBusySignal::Segment;
    }
    else if (scpi.startsWith("PPO")) {
        return VnaBusySignal::PartialPoint;
    }

    // default
    assert(false);
    return VnaBusySignal::Auto;
}
