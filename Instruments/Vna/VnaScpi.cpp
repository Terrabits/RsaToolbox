#include "VnaScpi.h"


//RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QDebug>


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

QString VnaScpi::toMatrixString(ConnectionType type) {
    switch(type) {
    case TCPIP_CONNECTION:
        return "LAN";
    case USB_CONNECTION:
        return "USB";
    default:
        return "";
    }
}
ConnectionType VnaScpi::toMatrixConnection(QString scpi) {
    scpi = scpi.trimmed().toUpper();
    if (scpi == "LAN")
        return TCPIP_CONNECTION;
    if (scpi == "USB")
        return USB_CONNECTION;

    // default:
    return NO_CONNECTION;
}

// Connector
QString VnaScpi::toString(Connector::Gender gender) {
    switch(gender) {
    case Connector::Gender::Male:
        return "MALE";
    case Connector::Gender::Female:
        return "FEM";
    default:
        return "MALE";
    }
}
QString VnaScpi::toGenderString(Connector connector) {
    return toString(connector.gender());
}
QString VnaScpi::toString(Connector::Type type) {
    switch(type) {
    case Connector::N_50_OHM_CONNECTOR:
        return "N 50 Ohm";
    case Connector::N_75_OHM_CONNECTOR:
        return "N 75 Ohm";
    case Connector::mm_7_CONNECTOR:
        return "7 mm"; // PC 7
    case Connector::mm_3_5_CONNECTOR:
        return "3.5 mm"; // PC 3.5
    case Connector::mm_2_92_CONNECTOR:
        return "2.92 mm";
    case Connector::mm_2_4_CONNECTOR:
        return "2.4 mm";
    case Connector::mm_1_85_CONNECTOR:
        return "1.85 mm";
    case Connector::in_7_16_CONNECTOR:
        return "7-16";
    case Connector::TYPE_F_75_OHM_CONNECTOR:
        return "Type F (75)"; // !Zva
    case Connector::BNC_50_OHM_CONNECTOR:
        return "BNC 50 Ohm"; // !Zva
    case Connector::BNC_75_OHM_CONNECTOR:
        return "BNC 75 Ohm"; // !Zva
    default:
        return "UNKNOWN_CONNECTOR";
    }
}
QString VnaScpi::toTypeString(Connector connector) {
    if (connector.isCustomType())
        return connector.customType();
    else
        return toString(connector.type());
}
Connector::Gender VnaScpi::toConnectorGender(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "MALE")
        return Connector::Gender::Male;
    if (scpi == "FEM")
        return Connector::Gender::Female;
    // else
        return Connector::Gender::Neutral;
}
Connector::Type VnaScpi::toConnectorType(QString scpi) {
    if (scpi.contains("N 50 Ohm", Qt::CaseInsensitive))
        return Connector::Type::N_50_OHM_CONNECTOR;
    else if (scpi.contains("N 75 Ohm", Qt::CaseInsensitive))
        return Connector::Type::N_75_OHM_CONNECTOR;
    else if (scpi.contains("7 mm", Qt::CaseInsensitive))
        return Connector::Type::mm_7_CONNECTOR;
    else if (scpi.contains("3.5 mm", Qt::CaseInsensitive))
        return Connector::Type::mm_3_5_CONNECTOR;
    else if (scpi.contains("2.92 mm", Qt::CaseInsensitive))
        return Connector::Type::mm_2_92_CONNECTOR;
    else if (scpi.contains("2.4 mm", Qt::CaseInsensitive))
        return Connector::Type::mm_2_4_CONNECTOR;
    else if (scpi.contains("1.85 mm", Qt::CaseInsensitive))
        return Connector::Type::mm_1_85_CONNECTOR;
    else if (scpi.contains("7-16"))
        return Connector::Type::in_7_16_CONNECTOR;
    else if (scpi.contains("Type F (75)", Qt::CaseInsensitive))
        return Connector::Type::TYPE_F_75_OHM_CONNECTOR;
    else if (scpi.contains("BNC 50 Ohm", Qt::CaseInsensitive))
        return Connector::Type::BNC_50_OHM_CONNECTOR;
    else if (scpi.contains("BNC 75 Ohm", Qt::CaseInsensitive))
        return Connector::Type::BNC_75_OHM_CONNECTOR;
    else if (scpi.isEmpty() == false)
        return Connector::Type::CUSTOM_CONNECTOR;
    else
        return Connector::Type::UNKNOWN_CONNECTOR;
}

// Calibration Standards
QString VnaScpi::toString(const VnaCalStandard &standard) {
    if (standard.isSinglePort()) {
        if (standard.isNotPortSpecific())
            return(toString(standard.type(), standard.gender()));
        else
            return(toString(standard.type(), standard.gender(), standard.port()));
    }
    else {
        if (standard.isNotPortSpecific())
            return(toString(standard.type(), standard.gender1(), standard.gender2()));
        else
            return(toString(standard.type(), standard.gender1(), standard.port1(), standard.gender2(), standard.port2()));
    }
}
QString VnaScpi::toString(VnaStandardType type) {
    switch(type) {
    case OPEN_STANDARD_TYPE:
        return "OP";
    case SHORT_STANDARD_TYPE:
        return "SH";
    case OFFSET_SHORT1_STANDARD_TYPE:
        return "OSH";
    case OFFSET_SHORT2_STANDARD_TYPE:
        return "OSHORT2";
    case OFFSET_SHORT3_STANDARD_TYPE:
        return "OSHORT3";
    case MATCH_STANDARD_TYPE:
        return "MTC";
    case SLIDING_MATCH_STANDARD_TYPE:
        return "SM";
    case REFLECT_STANDARD_TYPE:
        return "REF";
    case THRU_STANDARD_TYPE:
        return "TH";
    case LINE_STANDARD_TYPE:
        return "LINE1";
    case LINE2_STANDARD_TYPE:
        return "LINE2";
    case LINE3_STANDARD_TYPE:
        return "LINE3";
    case ATTENUATION_STANDARD_TYPE:
        return "AT";
    case SYMMETRIC_NETWORK_STANDARD_TYPE:
        return "SN";
    case ISOLATION_STANDARD_TYPE:
        return "????";
    default:
        return "UNKNOWN_STANDARD";
    }
}
QString VnaScpi::toString(VnaStandardType type, Connector::Gender gender) {
    if (!VnaCalStandard::isSinglePort(type))
        return "";

    QString scpi = "%1%2";
    if (gender == Connector::Gender::Female)
        scpi = scpi.arg("F");
    else
        scpi = scpi.arg("M");
    return scpi.arg(toString(type));
}
QString VnaScpi::toString(VnaStandardType type, Connector::Gender gender, uint port) {
    if (!VnaCalStandard::isSinglePort(type))
        return "";

    QString scpi = "%1%2(P%3)";
    if (gender == Connector::Gender::Female)
        scpi = scpi.arg("F");
    else
        scpi = scpi.arg("M");
    scpi = scpi.arg(toString(type));
    return scpi.arg(port);
}
QString VnaScpi::toString(VnaStandardType type, Connector::Gender gender1, Connector::Gender gender2) {
    if (!VnaCalStandard::isTwoPort(type))
        return "";

//    sort(gender1, gender2);
    QString scpi = "%1%2%3";
    if (gender1 == Connector::Gender::Female)
        scpi = scpi.arg("F");
    else
        scpi = scpi.arg("M");
    if (gender2 == Connector::Gender::Female)
        scpi = scpi.arg("F");
    else
        scpi = scpi.arg("M");
    return scpi.arg(toString(type));
}
QString VnaScpi::toString(VnaStandardType type, Connector::Gender gender1, uint port1, Connector::Gender gender2, uint port2) {
    if (!VnaCalStandard::isTwoPort(type))
        return "";

//    sort(gender1, gender2);
//    sort(port1, port2);
    QString scpi = "%1%2%3(P%4P%5)";
    if (gender1 == Connector::Gender::Female)
        scpi = scpi.arg("F");
    else
        scpi = scpi.arg("M");
    if (gender2 == Connector::Gender::Female)
        scpi = scpi.arg("F");
    else
        scpi = scpi.arg("M");
    scpi = scpi.arg(toString(type));
    scpi = scpi.arg(port1);
    return scpi.arg(port2);
}

VnaCalStandard VnaScpi::toCalStandard(QString scpi) {
    VnaCalStandard std;
    if (scpi.contains('(')) {
        // Port specific (PxPy)
        QStringList parts = scpi.remove(')').split('(');
        scpi = parts.first();
        QStringList ports = parts.last().remove(0,1).split('P');
        if (ports.size() == 2) {
            std.setPorts(ports.first().toUInt(),
                         ports.last().toUInt());
        }
        else {
            std.setPort(ports.first().toUInt());
        }
    }

    if (scpi.endsWith("OP", Qt::CaseInsensitive)) {
        std.setType(OPEN_STANDARD_TYPE);
        scpi.chop(2);
    }
    else if (scpi.endsWith("OSH", Qt::CaseInsensitive)) {
        std.setType(OFFSET_SHORT1_STANDARD_TYPE);
        scpi.chop(3);
    }
    else if (scpi.endsWith("OSHORT1", Qt::CaseInsensitive)) {
        std.setType(OFFSET_SHORT1_STANDARD_TYPE);
        scpi.chop(7);
    }
    else if (scpi.endsWith("OSHORT2", Qt::CaseInsensitive)) {
        std.setType(OFFSET_SHORT2_STANDARD_TYPE);
        scpi.chop(7);
    }
    else if (scpi.endsWith("OSHORT3", Qt::CaseInsensitive)) {
        std.setType(OFFSET_SHORT3_STANDARD_TYPE);
        scpi.chop(7);
    }
    else if (scpi.endsWith("SH", Qt::CaseInsensitive)) {
        std.setType(SHORT_STANDARD_TYPE);
        scpi.chop(2);
    }
    else if (scpi.endsWith("MMT", Qt::CaseInsensitive)) {
        std.setType(MATCH_STANDARD_TYPE);
        scpi.chop(3);
    }
    else if (scpi.endsWith("SM", Qt::CaseInsensitive)) {
        std.setType(SLIDING_MATCH_STANDARD_TYPE);
        scpi.chop(2);
    }
    else if (scpi.endsWith("REF", Qt::CaseInsensitive)) {
        std.setType(REFLECT_STANDARD_TYPE);
        scpi.chop(3);
    }
    else if (scpi.endsWith("TH", Qt::CaseInsensitive)) {
        std.setType(THRU_STANDARD_TYPE);
        scpi.chop(2);
    }
    else if (scpi.endsWith("L", Qt::CaseInsensitive)) {
        std.setType(LINE_STANDARD_TYPE);
        scpi.chop(1);
    }
    else if (scpi.endsWith("LINE1", Qt::CaseInsensitive)) {
        std.setType(LINE_STANDARD_TYPE);
        scpi.chop(5);
    }
    else if (scpi.endsWith("LINE2", Qt::CaseInsensitive)) {
        std.setType(LINE2_STANDARD_TYPE);
        scpi.chop(5);
    }
    else if (scpi.endsWith("LINE3", Qt::CaseInsensitive)) {
        std.setType(LINE3_STANDARD_TYPE);
        scpi.chop(5);
    }
    else if (scpi.endsWith("AT", Qt::CaseInsensitive)) {
        std.setType(ATTENUATION_STANDARD_TYPE);
        scpi.chop(2);
    }
    else if (scpi.endsWith("SN", Qt::CaseInsensitive)) {
        std.setType(SYMMETRIC_NETWORK_STANDARD_TYPE);
        scpi.chop(2);
    }
    else if (scpi.endsWith("????")) {
        std.setType(ISOLATION_STANDARD_TYPE);
        scpi.chop(4);
    }
    else {
        std.setType(UNKNOWN_STANDARD_TYPE);
        return std;
    }

    if (std.isSinglePort() && scpi.size() >= 1) {
        switch(scpi[0].toUpper().toLatin1()) {
        case 'M':
            std.connector().setGender(Connector::Gender::Male);
            break;
        case 'F':
            std.connector().setGender(Connector::Gender::Female);
            break;
        default:
            std.connector().setGender(Connector::Gender::Neutral);
        }
    }
    else if (std.isTwoPort() && scpi.size() >= 2) {
        char port1 = scpi[0].toUpper().toLatin1();
        switch(port1) {
        case 'M':
            std.connector1().setGender(Connector::Gender::Male);
            break;
        case 'F':
            std.connector1().setGender(Connector::Gender::Female);
            break;
        default:
            std.connector1().setGender(Connector::Gender::Neutral);
        }

        char port2 = scpi[1].toUpper().toLatin1();
        switch(port2) {
        case 'M':
            std.connector2().setGender(Connector::Gender::Male);
            break;
        case 'F':
            std.connector2().setGender(Connector::Gender::Female);
            break;
        default:
            std.connector2().setGender(Connector::Gender::Neutral);
        }
    }

    return(std);
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
