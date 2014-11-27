#include "VnaScpi.h"


//RsaToolbox
#include "General.h"
using namespace RsaToolbox;


/*!
 * \class RsaToolbox::VnaScpi
 * \ingroup VnaGroup
 * \brief Provides Vna SCPI conversions
 */

/*!
 * \brief Maps \c BalancedPort::Type to
 * SCPI
 * \param type Type of balanced port
 * \return SCPI representation
 */
QString VnaScpi::toString(BalancedPort::Type type) {
    switch(type) {
    case BalancedPort::Type::SingleEnded:
        return "s";
    case BalancedPort::Type::Differential:
        return "d";
    case BalancedPort::Type::Common:
        return "c";
    default:
        return "s";
    }
}

/*!
 * \brief Maps \c scpi to
 * \c BalancedPort::Type
 * \param scpi SCPI representation
 * \return Balanced port type
 */
BalancedPort::Type VnaScpi::toBalancedPortType(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "s")
        return BalancedPort::Type::SingleEnded;
    if (scpi == "d")
        return BalancedPort::Type::Differential;
    if (scpi == "c")
        return BalancedPort::Type::Common;

    return BalancedPort::Type::SingleEnded;
}

// User Defined Ports
QString VnaScpi::toString(VnaUserDefinedPort::Receiver receiver) {
    switch (receiver) {
    case VnaUserDefinedPort::Receiver::A:
        return "a";
    case VnaUserDefinedPort::Receiver::B:
        return "b";
    default:
        return "a";
    }
}
QString VnaScpi::toString(VnaUserDefinedPort port) {
    QString result = "%1:%2%3:%4%5";
    result = result.arg(port.sourcePort());

    uint i;
    VnaUserDefinedPort::Receiver r;
    port.reference(i, r);
    result = result.arg(toString(r));
    result = result.arg(i);

    port.measurement(i, r);
    result = result.arg(toString(r));
    result = result.arg(i);
    return result;
}
VnaUserDefinedPort::Receiver VnaScpi::toReceiver(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "a")
        return VnaUserDefinedPort::Receiver::A;
    if (scpi == "b")
        return VnaUserDefinedPort::Receiver::B;

    return VnaUserDefinedPort::Receiver::A;
}
VnaUserDefinedPort VnaScpi::toUserDefinedPort(QString scpi) {
    VnaUserDefinedPort port;
    QStringList list = scpi.trimmed().remove("\'").split(":");
            if (list.size() != 3)
            return port;

    uint i;
    VnaUserDefinedPort::Receiver r;
    i = list[0].toUInt();
    port.setSource(i);

    r = VnaScpi::toReceiver(list[1].at(0));
    list[1].remove(0,1);
    i = list[1].toUInt();
    port.setReference(i, r);

    r = VnaScpi::toReceiver(list[2].at(0));
    list[2].remove(0,1);
    i = list[2].toUInt();
    port.setMeasurement(i, r);

    return port;
}

// Channel
QString VnaScpi::toString(VnaChannel::SweepType type) {
    switch(type) {
    case VnaChannel::SweepType::Linear:
        return "LIN";
    case VnaChannel::SweepType::Log:
        return "LOG";
    case VnaChannel::SweepType::Segmented:
        return "SEGM";
    case VnaChannel::SweepType::Power:
        return "POW";
    case VnaChannel::SweepType::Cw:
        return "CW";
    case VnaChannel::SweepType::Time:
        return "POIN";
    default:
        return "LIN";
    }
}
VnaChannel::SweepType VnaScpi::toSweepType(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "LIN")
        return VnaChannel::SweepType::Linear;
    if (scpi == "LOG")
        return VnaChannel::SweepType::Log;
    if (scpi == "SEGM")
        return VnaChannel::SweepType::Segmented;
    if (scpi == "POW")
        return VnaChannel::SweepType::Power;
    if (scpi == "CW")
        return VnaChannel::SweepType::Cw;
    if (scpi == "POIN")
        return VnaChannel::SweepType::Time;

    return VnaChannel::SweepType::Linear;
}

// Calibrate
QString VnaScpi::toString(VnaCalibrate::CalType type) {
    switch(type) {
    case VnaCalibrate::CalType::Osm:
        return "FOP";
    case VnaCalibrate::CalType::Tosm:
        return "TOSM";
    case VnaCalibrate::CalType::Uosm:
        return "UOSM";
    default:
        return "UOSM";
    }
}
VnaCalibrate::CalType VnaScpi::toCalType(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "FOP")
        return VnaCalibrate::CalType::Osm;
    if (scpi == "UOSM")
        return VnaCalibrate::CalType::Uosm;
    if (scpi == "TOSM")
        return VnaCalibrate::CalType::Tosm;

    return VnaCalibrate::CalType::Uosm;
}


// Trace

QString VnaScpi::toString(TraceFormat format) {
    switch(format) {
    case TraceFormat::DecibelMagnitude:
        return "MLOG";
    case TraceFormat::Phase:
        return "PHAS";
    case TraceFormat::SmithChart:
        return "SMIT";
    case TraceFormat::PolarChart:
        return "POL";
    case TraceFormat::Vswr:
        return "SWR";
    case TraceFormat::UnwrappedPhase:
        return "UPH";
    case TraceFormat::Magnitude:
        return "MLIN";
    case TraceFormat::InverseSmithChart:
        return "ISM";
    case TraceFormat::Real:
        return "REAL";
    case TraceFormat::Imaginary:
        return "IMAG";
    case TraceFormat::Delay:
        return "GDEL";
    default:
        return "MLOG";
    }
}
TraceFormat VnaScpi::toTraceFormat(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "MLOG")
        return TraceFormat::DecibelMagnitude;
    if (scpi == "PHAS")
        return TraceFormat::Phase;
    if (scpi == "SMIT")
        return TraceFormat::SmithChart;
    if (scpi == "POL")
        return TraceFormat::PolarChart;
    if (scpi == "SWR")
        return TraceFormat::Vswr;
    if (scpi == "UPH")
        return TraceFormat::UnwrappedPhase;
    if (scpi == "MLIN")
        return TraceFormat::Magnitude;
    if (scpi == "ISM")
        return TraceFormat::InverseSmithChart;
    if (scpi == "REAL")
        return TraceFormat::Real;
    if (scpi == "IMAG")
        return TraceFormat::Imaginary;
    if (scpi == "GDEL")
        return TraceFormat::Delay;

    return TraceFormat::DecibelMagnitude;
}
QString VnaScpi::toString(NetworkParameter parameter) {
    return RsaToolbox::toString(parameter);
}
QString VnaScpi::toString(NetworkParameter parameter,
                          uint outputPort, uint inputPort) {
    return toString(parameter)
            + toPortPair(outputPort, inputPort);
}
QString VnaScpi::toString(NetworkParameter parameter,
                          const BalancedPort &output,
                          const BalancedPort &input)
{
    QString result = toString(parameter);
    result += toString(output.type());
    result += toString(input.type());
    result += toPortPair(output.port(), input.port());
    return result;
}
QString VnaScpi::toString(WaveQuantity wave) {
    switch(wave) {
    case WaveQuantity::a:
        return "a";
    case WaveQuantity::b:
        return "b";
    default:
        return "a";
    }
}
QString VnaScpi::toString(WaveQuantity wave, uint port) {
    return toString(wave) + QVariant(port).toString();
}
QString VnaScpi::toPortPair(uint outputPort, uint inputPort) {
    QString out = QVariant(outputPort).toString();
    QString in = QVariant(inputPort).toString();

    int diff = out.size() - in.size();
    if (diff > 0) {
        in.prepend(QString('0', diff));
    }
    else if (diff < 0) {
        out.prepend(QString('0', -diff));
    }
    return out + in;
}

// Time Domain
QString VnaScpi::toString(VnaTimeDomain::Window window) {
    switch(window) {
    case VnaTimeDomain::Window::Regular:
        return("RECT");
    case VnaTimeDomain::Window::Hamming:
        return("HAMM");
    case VnaTimeDomain::Window::Hann:
        return("HANN");
    case VnaTimeDomain::Window::Bohman:
        return("BOHM");
    case VnaTimeDomain::Window::DolphChebychev:
        return("DCH");
    default:
        return("RECT");
    }
}
VnaTimeDomain::Window VnaScpi::toTimeDomainWindow(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "RECT")
        return VnaTimeDomain::Window::Regular;
    if (scpi == "HAMM")
        return VnaTimeDomain::Window::Hamming;
    if (scpi == "HANN")
        return VnaTimeDomain::Window::Hann;
    if (scpi ==  "BOHM")
        return VnaTimeDomain::Window::Bohman;
    if (scpi == "DCH")
        return VnaTimeDomain::Window::DolphChebychev;

    return VnaTimeDomain::Window::Regular;
}

// Private
VnaScpi::VnaScpi()
{
}
