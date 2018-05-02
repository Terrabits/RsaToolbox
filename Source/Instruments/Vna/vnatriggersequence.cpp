#include "VnaTrigger.h"
using namespace RsaToolbox;

#include <cassert>

QString toScpi(VnaTrigger::Sequence sequence) {
    switch (sequence) {
    case VnaTrigger::Sequence::Sweep:
        return "SWEEP";
    case VnaTrigger::Sequence::Segment:
        return "SEGMENT";
    case VnaTrigger::Sequence::Point:
        return "POINT";
    case VnaTrigger::Sequence::PartialPoint:
        return "PPOINT";
    default:
        assert(false);
        return "SWEEP";
    }
}

VnaTrigger::Sequence vnaTriggerSequenceFromScpi(QString scpi) {
    scpi = scpi.trimmed().remove("\'").toUpper();
    if (scpi.startsWith("SWE")) {
        return VnaTrigger::Sequence::Sweep;
    }
    if (scpi.startsWith("SEGM")) {
        return VnaTrigger::Sequence::Segment;
    }
    if (scpi.startsWith("POIN")) {
        return VnaTrigger::Sequence::Point;
    }
    if (scpi.startsWith("PPO")) {
        return VnaTrigger::Sequence::PartialPoint;
    }
    // default
    assert(false);
    return VnaTrigger::Sequence::Sweep;
}
