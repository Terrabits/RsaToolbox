#include "vnatriggersource.h"
using namespace RsaToolbox;

#include <cassert>

QString toScpi(VnaTriggerSource source) {
    switch (source) {
    case VnaTriggerSource::FreeRun:
        return "IMM";
    case VnaTriggerSource::External:
        return "EXT";
    case VnaTriggerSource::Manual:
        return "MAN";
    case VnaTriggerSource::Multiple:
        return "MULT";
    case VnaTriggerSource::Timed:
        return "TIM";
    case VnaTriggerSource::PulseGenerator:
        return "PGEN";
    default:
        // FreeRun
        assert(false);
        return "IMM";
    }
}

VnaTriggerSource vnaTriggerSourceFromScpi(QString scpi) {
    scpi = scpi.trimmed().toUpper();
    if (scpi.startsWith("IMM")) {
        return VnaTriggerSource::FreeRun;
    }
    if (scpi.startsWith("EXT")) {
        return VnaTriggerSource::External;
    }
    if (scpi.startsWith("MAN")) {
        return VnaTriggerSource::Manual;
    }
    if (scpi.startsWith("MULT")) {
        return VnaTriggerSource::Multiple;
    }
    if (scpi.startsWith("TIM")) {
        return VnaTriggerSource::Timed;
    }
    if (scpi.startsWith("PGEN")) {
        return VnaTriggerSource::PulseGenerator;
    }
    // default:
    assert(false);
    return VnaTriggerSource::FreeRun;
}
