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
QString VnaScpi::toString(Connector::Mode mode) {
    if (mode == Connector::Mode::Tem)
        return "TEM";
    if (mode == Connector::Mode::Waveguide)
        return "WGU";

    // Default:
    return "";
}
Connector::Mode VnaScpi::toConnectorMode(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "TEM")
        return Connector::Mode::Tem;
    if (scpi.startsWith("WGU"))
        return Connector::Mode::Waveguide;

    // Default:
    return Connector::Mode::Tem;
}

// Calibration Standards
QString VnaScpi::toString(const VnaCalStandard &standard) {
    if (standard.isSinglePort()) {
        return(toString(standard.type(), standard.gender()));
    }
    else {
        return(toString(standard.type(), standard.gender1(), standard.gender2()));
    }
}
QString VnaScpi::toString(VnaCalStandard::Type type) {
    switch(type) {
    case VnaCalStandard::Type::Open:
        return "OP";
    case VnaCalStandard::Type::Short:
        return "SH";
    case VnaCalStandard::Type::OffsetShort1:
        return "OSHORT1";
    case VnaCalStandard::Type::OffsetShort2:
        return "OSHORT2";
    case VnaCalStandard::Type::OffsetShort3:
        return "OSHORT3";
    case VnaCalStandard::Type::Match:
        return "MTC";
    case VnaCalStandard::Type::SlidingMatch:
        return "SM";
    case VnaCalStandard::Type::Reflect:
        return "REF";
    case VnaCalStandard::Type::Thru:
        return "TH";
    case VnaCalStandard::Type::Line1:
        return "LINE1";
    case VnaCalStandard::Type::Line2:
        return "LINE2";
    case VnaCalStandard::Type::Line3:
        return "LINE3";
    case VnaCalStandard::Type::Attenuation:
        return "AT";
    case VnaCalStandard::Type::SymmetricNetwork:
        return "SN";
    case VnaCalStandard::Type::Isolation:
        return "????";
    default:
        return "UNKNOWN_STANDARD";
    }
}
QString VnaScpi::toString(VnaCalStandard::Type type, Connector::Gender gender) {
    if (!VnaCalStandard::isSinglePort(type))
        return "";

    QString scpi = "%1%2";
    if (gender == Connector::Gender::Female)
        scpi = scpi.arg("F");
    else
        scpi = scpi.arg("M");
    return scpi.arg(toString(type));
}
QString VnaScpi::toString(VnaCalStandard::Type type, Connector::Gender gender1, Connector::Gender gender2) {
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
        std.setType(VnaCalStandard::Type::Open);
        scpi.chop(2);
    }
    else if (scpi.endsWith("OSH", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::OffsetShort1);
        scpi.chop(3);
    }
    else if (scpi.endsWith("OSHORT1", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::OffsetShort1);
        scpi.chop(7);
    }
    else if (scpi.endsWith("OSHORT2", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::OffsetShort2);
        scpi.chop(7);
    }
    else if (scpi.endsWith("OSHORT3", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::OffsetShort3);
        scpi.chop(7);
    }
    else if (scpi.endsWith("SH", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::Short);
        scpi.chop(2);
    }
    else if (scpi.endsWith("MMT", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::Match);
        scpi.chop(3);
    }
    else if (scpi.endsWith("SM", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::SlidingMatch);
        scpi.chop(2);
    }
    else if (scpi.endsWith("REF", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::Reflect);
        scpi.chop(3);
    }
    else if (scpi.endsWith("TH", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::Thru);
        scpi.chop(2);
    }
    else if (scpi.endsWith("L", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::Line1);
        scpi.chop(1);
    }
    else if (scpi.endsWith("LINE1", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::Line1);
        scpi.chop(5);
    }
    else if (scpi.endsWith("LINE2", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::Line2);
        scpi.chop(5);
    }
    else if (scpi.endsWith("LINE3", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::Line3);
        scpi.chop(5);
    }
    else if (scpi.endsWith("AT", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::Attenuation);
        scpi.chop(2);
    }
    else if (scpi.endsWith("SN", Qt::CaseInsensitive)) {
        std.setType(VnaCalStandard::Type::SymmetricNetwork);
        scpi.chop(2);
    }
    else if (scpi.endsWith("????")) {
        std.setType(VnaCalStandard::Type::Isolation);
        scpi.chop(4);
    }
    else {
        std.setType(VnaCalStandard::Type::Unknown);
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

bool VnaScpi::isThruModel(VnaCalStandard::Type type) {
    if (type == VnaCalStandard::Type::Thru)
        return true;
    if (type == VnaCalStandard::Type::Line1)
        return true;
    if (type == VnaCalStandard::Type::Line2)
        return true;
    if (type == VnaCalStandard::Type::Line3)
        return true;
    if (type == VnaCalStandard::Type::Attenuation)
        return true;
    if (type == VnaCalStandard::Type::Isolation)
        return true;

    return false;
}
bool VnaScpi::defaultModelIsOpen(VnaCalStandard::Type type) {
    if (type == VnaCalStandard::Type::Open)
        return true;
    if (type == VnaCalStandard::Type::Reflect)
        return true;
    if (type == VnaCalStandard::Type::SymmetricNetwork)
        return true;

    return false;
}
bool VnaScpi::defaultModelIsShort(VnaCalStandard::Type type) {
    if (type == VnaCalStandard::Type::Short)
        return true;
    if (type == VnaCalStandard::Type::OffsetShort1)
        return true;
    if (type == VnaCalStandard::Type::OffsetShort2)
        return true;
    if (type == VnaCalStandard::Type::OffsetShort3)
        return true;

    return false;
}
bool VnaScpi::defaultModelIsMatch(VnaCalStandard::Type type) {
    if (type == VnaCalStandard::Type::Match)
        return true;

    return false;
}
QString VnaScpi::toString(VnaCalStandard::Type type, VnaStandardModel &model) {
    QString frequency = "%1,%2";
    frequency = frequency.arg(model.minimumFrequency_Hz);
    frequency = frequency.arg(model.maximumFrequency_Hz);

    if (type == VnaCalStandard::Type::SlidingMatch)
        return frequency;
    if (type == VnaCalStandard::Type::Attenuation)
        return frequency;

    QString transmission = ",%1,%2,%3";
    transmission = transmission.arg(model.eLength_m);
    transmission = transmission.arg(model.loss_dB_per_sqrt_Hz);
    transmission = transmission.arg(model.Z0_Ohms);

    if (isThruModel(type))
        return frequency + transmission;

    QString capacitance = ",%1,%2,%3,%4";
    if (model.hasCapacitanceValues()) {
        capacitance = capacitance.arg(model.C0_fF);
        capacitance = capacitance.arg(model.C1_fF_per_GHz);
        capacitance = capacitance.arg(model.C2_fF_per_GHz2);
        capacitance = capacitance.arg(model.C3_fF_per_GHz3);
    }
    else {
        capacitance = capacitance.arg(0);
        capacitance = capacitance.arg(0);
        capacitance = capacitance.arg(0);
        capacitance = capacitance.arg(0);
    }

    QString inductance = ",%1,%2,%3,%4";
    if (model.hasInductanceValues()) {
        inductance = inductance.arg(model.L0_pH);
        inductance = inductance.arg(model.L1_pH_per_GHz);
        inductance = inductance.arg(model.L2_pH_per_GHz2);
        inductance = inductance.arg(model.L3_pH_per_GHz3);
    }
    else {
        inductance = inductance.arg(0);
        inductance = inductance.arg(0);
        inductance = inductance.arg(0);
        inductance = inductance.arg(0);
    }

    QString scpi = frequency + transmission + capacitance + inductance;

    QString r = ",%1";
    r = r.arg(model.R_Ohms);
    if (model.hasRValue()) {
        return scpi + r;
    }

    QString typeString = ",%1";
    if (model.type == VnaStandardModel::Type::Open)
        typeString = typeString.arg("OPEN");
    if (model.type == VnaStandardModel::Type::Short)
        typeString = typeString.arg("SHORT");
    if (model.type == VnaStandardModel::Type::Match)
        typeString = typeString.arg("MATCH");
    return scpi + typeString;
}
VnaStandardModel VnaScpi::toStandardModel(VnaCalStandard::Type type, const QStringList &scpi) {
    // Index:
    const int MINIMUM_FREQUENCY = 0;
    const int MAXIMUM_FREQUENCY = 1;
    const int ELECTRICAL_LENGTH = 2;
    const int LOSS = 3;
    const int IMPEDANCE = 4;
    const int C0 = 5;
    const int C1 = 6;
    const int C2 = 7;
    const int C3 = 8;
    const int L0 = 9;
    const int L1 = 10;
    const int L2 = 11;
    const int L3 = 12;
    const int R = 13;

    VnaStandardModel model;
    if (type == VnaCalStandard::Type::SlidingMatch)
        return model;

    if (scpi.size() < 2) {
        // Not enough parameters
        return model;
    }
    model.minimumFrequency_Hz = scpi[MINIMUM_FREQUENCY].toDouble();
    model.maximumFrequency_Hz = scpi[MAXIMUM_FREQUENCY].toDouble();
    if (type == VnaCalStandard::Type::SlidingMatch)
        return model;
    if (type == VnaCalStandard::Type::Attenuation)
        return model;

    if (scpi.size() < 5) {
        // Not enough parameters
        return model;
    }
    model.eLength_m = scpi[ELECTRICAL_LENGTH].toDouble();
    model.loss_dB_per_sqrt_Hz = scpi[LOSS].toDouble();
    model.Z0_Ohms = scpi[IMPEDANCE].toDouble();
    if (isThruModel(type)) {
        model.type = VnaStandardModel::Type::Thru;
        return model;
    }

    if (scpi.size() < 13) {
        // Not enough parameters for
        // remaining models
        return model;
    }

    // Default models
    if (defaultModelIsOpen(type))
        model.type = VnaStandardModel::Type::Open;
    if (defaultModelIsShort(type))
        model.type = VnaStandardModel::Type::Short;
    if (defaultModelIsMatch(type))
        model.type = VnaStandardModel::Type::Match;

    // Check for specific model
    // (Overrides default)
    if (scpi.last() == "OPEN")
        model.type = VnaStandardModel::Type::Open;
    else if (scpi.last() == "SHORT")
        model.type = VnaStandardModel::Type::Short;
    else if (scpi.last() == "MATCH")
        model.type = VnaStandardModel::Type::Match;
    else if (scpi.size() == 14) {
        model.type = VnaStandardModel::Type::R;
    }

    model.C0_fF = scpi[C0].toDouble();
    model.C1_fF_per_GHz = scpi[C1].toDouble();
    model.C2_fF_per_GHz2 = scpi[C2].toDouble();
    model.C3_fF_per_GHz3 = scpi[C3].toDouble();
    model.L0_pH = scpi[L0].toDouble();
    model.L1_pH_per_GHz = scpi[L1].toDouble();
    model.L2_pH_per_GHz2 = scpi[L2].toDouble();
    model.L3_pH_per_GHz3 = scpi[L3].toDouble();
    if (model.hasRValue())
        model.R_Ohms = scpi[R].toDouble();

    return model;
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

// Trigger
QString VnaScpi::toString(VnaTrigger::Source source) {
    switch(source) {
    case VnaTrigger::Source::FreeRun:
        return "IMM";
    case VnaTrigger::Source::External:
        return "EXT";
    case VnaTrigger::Source::Manual:
        return "MAN";
    case VnaTrigger::Source::Multiple:
        return "MULT";
    default:
        return "IMM";
    }
}
VnaTrigger::Source VnaScpi::toTriggerSource(QString scpi) {
    scpi = scpi.trimmed().toUpper();
    if (scpi == "IMM")
        return VnaTrigger::Source::FreeRun;
    if (scpi == "EXT")
        return VnaTrigger::Source::External;
    if (scpi == "MAN")
        return VnaTrigger::Source::Manual;
    if (scpi == "MULT")
        return VnaTrigger::Source::Multiple;

    // Else
    return VnaTrigger::Source::FreeRun;
}

// Calibrate
QString VnaScpi::toString(VnaCalibrate::CalType calType) {
    switch(calType) {

    // Standard calibrations:
    case VnaCalibrate::CalType::AdapterRemoval:
        return "ART";
    case VnaCalibrate::CalType::ReflectionNormOpen:
        return "REFL";
    case VnaCalibrate::CalType::ReflectionNormShort:
        return "RSH";
    case VnaCalibrate::CalType::Osm:
        return "FOP";
    case VnaCalibrate::CalType::TransmitNormForward:
        return "FTR";
    case VnaCalibrate::CalType::TransmitNormReverse:
        return "RTR";
    case VnaCalibrate::CalType::TransmitNormBothDirections:
        return "FRTR";
    case VnaCalibrate::CalType::OnePathTwoPorts:
        return "OPTP";
    case VnaCalibrate::CalType::Tosm:
        return "TOSM";
    case VnaCalibrate::CalType::Uosm:
        return "UOSM";
    case VnaCalibrate::CalType::Trl:
        return "TRL";
    case VnaCalibrate::CalType::NistTrl:
        return "NMTR";
    case VnaCalibrate::CalType::Tom:
        return "TOM";
    case VnaCalibrate::CalType::Tsm:
        return "TSM";
    case VnaCalibrate::CalType::Trm:
        return "TRM";
    case VnaCalibrate::CalType::Tna:
        return "TNA";

    // SMARTerCal (+ Power):
    case VnaCalibrate::CalType::AdapterRemoval_SMARTerCal:
        return "ARPT";
    case VnaCalibrate::CalType::Tosm_SMARTerCal:
        return "PTOS";
    case VnaCalibrate::CalType::Uosm_SMARTerCal:
        return "PUOS";
    case VnaCalibrate::CalType::Trl_SMARTerCal:
        return "PTRL";
    case VnaCalibrate::CalType::Tom_SMARTerCal:
        return "PTOM";
    case VnaCalibrate::CalType::Tsm_SMARTerCal:
        return "PTSM";
    case VnaCalibrate::CalType::Trm_SMARTerCal:
        return "PTRM";
    case VnaCalibrate::CalType::Tna_SMARTerCal:
        return "PTNA";

    default:
        return "UOSM";
    }
}
VnaCalibrate::CalType VnaScpi::toCalType(QString scpi) {
    scpi = scpi.trimmed().toUpper();

    // Standard calibrations:
    if (scpi == "ART")
        return VnaCalibrate::CalType::AdapterRemoval;
    if (scpi == "REFL")
        return VnaCalibrate::CalType::ReflectionNormOpen;
    if (scpi == "RSH")
        return VnaCalibrate::CalType::ReflectionNormShort;
    if (scpi == "FOP")
        return VnaCalibrate::CalType::Osm;
    if (scpi == "FTR")
        return VnaCalibrate::CalType::TransmitNormForward;
    if (scpi == "RTR")
        return VnaCalibrate::CalType::TransmitNormReverse;
    if (scpi == "FRTR")
        return VnaCalibrate::CalType::TransmitNormBothDirections;
    if (scpi == "OPTP")
        return VnaCalibrate::CalType::OnePathTwoPorts;
    if (scpi == "TOSM")
        return VnaCalibrate::CalType::Tosm;
    if (scpi == "UOSM")
        return VnaCalibrate::CalType::Uosm;
    if (scpi == "TRL")
        return VnaCalibrate::CalType::Trl;
    if (scpi == "NMTR")
        return VnaCalibrate::CalType::NistTrl;
    if (scpi == "TOM")
        return VnaCalibrate::CalType::Tom;
    if (scpi == "TSM")
        return VnaCalibrate::CalType::Tsm;
    if (scpi == "TRM")
        return VnaCalibrate::CalType::Trm;
    if (scpi == "TNA")
        return VnaCalibrate::CalType::Tna;

    // SMARTer cals (+power):
    if (scpi == "ARPT")
        return VnaCalibrate::CalType::AdapterRemoval_SMARTerCal;
    if (scpi == "PTOS")
        return VnaCalibrate::CalType::Tosm_SMARTerCal;
    if (scpi == "PUOS")
        return VnaCalibrate::CalType::Uosm_SMARTerCal;
    if (scpi == "PTRL")
        return VnaCalibrate::CalType::Trl_SMARTerCal;
    if (scpi == "PTOM")
        return VnaCalibrate::CalType::Tom_SMARTerCal;
    if (scpi == "PTSM")
        return VnaCalibrate::CalType::Tsm_SMARTerCal;
    if (scpi == "PTRM")
        return VnaCalibrate::CalType::Trm_SMARTerCal;
    if (scpi == "PTNA")
        return VnaCalibrate::CalType::Tna_SMARTerCal;

    // Default:
    return VnaCalibrate::CalType::Uosm;
}
bool VnaScpi::isSMARTerCal(VnaCalibrate::CalType calType) {
    switch(calType) {
    case VnaCalibrate::CalType::AdapterRemoval_SMARTerCal:
    case VnaCalibrate::CalType::Uosm_SMARTerCal:
    case VnaCalibrate::CalType::Tosm_SMARTerCal:
    case VnaCalibrate::CalType::Trl_SMARTerCal:
    case VnaCalibrate::CalType::Tom_SMARTerCal:
    case VnaCalibrate::CalType::Tsm_SMARTerCal:
    case VnaCalibrate::CalType::Trm_SMARTerCal:
    case VnaCalibrate::CalType::Tna_SMARTerCal:
        return true;
    default:
        return false;
    }
}
bool VnaScpi::isFull12TermErrorCorrection(VnaCalibrate::CalType calType) {
    switch(calType) {
    case VnaCalibrate::CalType::AdapterRemoval:
    case VnaCalibrate::CalType::Osm:
    case VnaCalibrate::CalType::Uosm:
    case VnaCalibrate::CalType::Tosm:
    case VnaCalibrate::CalType::Trl:
    case VnaCalibrate::CalType::NistTrl:
    case VnaCalibrate::CalType::Tom:
    case VnaCalibrate::CalType::Tsm:
    case VnaCalibrate::CalType::Trm:
    case VnaCalibrate::CalType::Tna:
    case VnaCalibrate::CalType::AdapterRemoval_SMARTerCal:
    case VnaCalibrate::CalType::Uosm_SMARTerCal:
    case VnaCalibrate::CalType::Tosm_SMARTerCal:
    case VnaCalibrate::CalType::Trl_SMARTerCal:
    case VnaCalibrate::CalType::Tom_SMARTerCal:
    case VnaCalibrate::CalType::Tsm_SMARTerCal:
    case VnaCalibrate::CalType::Trm_SMARTerCal:
    case VnaCalibrate::CalType::Tna_SMARTerCal:
        return true;
    default:
        return false;
    }
}
bool VnaScpi::isZvaFamilyCompatible(VnaCalibrate::CalType calType) {
    if (isSMARTerCal(calType))
        return false;
    else
        return true;
}
bool VnaScpi::isZnbFamilyCompatible(VnaCalibrate::CalType calType) {
    if (calType == VnaCalibrate::CalType::NistTrl)
        return false;
    else
        return true;
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
