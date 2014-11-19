#include "VnaScpi.h"


//RsaToolbox
#include "General.h"
using namespace RsaToolbox;


VnaScpi::VnaScpi()
{
}

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
BalancedPort::Type VnaScpi::toBalancedPortType(const QString &scpi) {
    scpi.toUpper();
    if (scpi == "s")
        return BalancedPort::Type::SingleEnded;
    if (scpi == "d")
        return BalancedPort::Type::Differential;
    if (scpi == "c")
        return BalancedPort::Type::Common;

    return BalancedPort::Type::SingleEnded;
}

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
TraceFormat VnaScpi::toTraceFormat(const QString &scpi) {
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


