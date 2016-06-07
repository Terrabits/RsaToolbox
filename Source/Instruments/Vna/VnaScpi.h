#ifndef VNASCPI_H
#define VNASCPI_H


#include "VnaChannel.h"
#include "VnaTrace.h"
#include "VnaTrigger.h"
#include "BalancedPort.h"
#include "VnaUserDefinedPort.h"
#include "VnaCalStandard.h"
#include "VnaTimeDomain.h"
#include "VnaSwitchMatrix.h"
#include "GenericBus.h"

namespace RsaToolbox {


class VnaScpi
{
public:

    // General
    static QString toString(PortMap map);

    // Channel
    static QString toString(VnaChannel::SweepType type);
    static VnaChannel::SweepType toSweepType(QString scpi);

    // Trace
    static QString toString(VnaTrace::Side side);
    static QString toString(VnaTrace::At at);

    // Trigger
    static QString toString(VnaTrigger::Source source);
    static VnaTrigger::Source toTriggerSource(QString scpi);

    // Balanced Port
    static QString toString(BalancedPort::Type type);
    static BalancedPort::Type toBalancedPortType(QString scpi);

    // User defined port
    static QString toString(VnaUserDefinedPort::Receiver receiver);
    static QString toString(VnaUserDefinedPort port);
    static VnaUserDefinedPort::Receiver toReceiver(QString scpi);
    static VnaUserDefinedPort toUserDefinedPort(QString scpi);

    // Switch Matrix
    static QString toString(VnaSwitchMatrix::ConnectionType type);
    static QString toString(VnaSwitchMatrix::Driver driver);
    static VnaSwitchMatrix::ConnectionType toSwitchMatrixConnectionType(QString scpi);
//    static VnaSwitchMatrix::Driver toSwitchMatrixDriver(QString scpi);

    // Connector
    static QString toString(Connector::Type type);
    static QString toTypeString(Connector connector);
    static Connector::Type toConnectorType(QString scpi);
    static QString toString(Connector::Gender gender);
    static QString toGenderString(Connector connector);
    static Connector::Gender toConnectorGender(QString scpi);
    static QString toString(Connector::Mode mode);
    static Connector::Mode toConnectorMode(QString scpi);


    // Calibration Standards
    static QString toString(const VnaCalStandard &standard);
    static QString toString(VnaCalStandard::Type type);
    static QString toString(VnaCalStandard::Type type, Connector::Gender gender);
    static QString toString(VnaCalStandard::Type type, Connector::Gender gender1, Connector::Gender gender2);
    static VnaCalStandard toCalStandard(QString scpi);

    static bool isThruModel(VnaCalStandard::Type type);
    static bool defaultModelIsOpen(VnaCalStandard::Type type);
    static bool defaultModelIsShort(VnaCalStandard::Type type);
    static bool defaultModelIsMatch(VnaCalStandard::Type type);
    static QString toString(VnaCalStandard::Type type, VnaStandardModel &model);
    static VnaStandardModel toStandardModel(VnaCalStandard::Type type, const QStringList &scpi);

    // Calibration
    static QString toString(VnaCalibrate::CalType calType);
    static VnaCalibrate::CalType toCalType(QString scpi);
    static bool isSMARTerCal(VnaCalibrate::CalType calType);
    static bool isFull12TermErrorCorrection(VnaCalibrate::CalType calType);
    static bool isZvaFamilyCompatible(VnaCalibrate::CalType calType);
    static bool isZnbFamilyCompatible(VnaCalibrate::CalType calType);

    // Trace
    static QString toString(TraceFormat format);
    static TraceFormat toTraceFormat(QString scpi);
    static QString toString(NetworkParameter parameter);
    static QString toString(NetworkParameter parameter, uint outputPort, uint inputPort);
    static QString toString(NetworkParameter parameter, const BalancedPort &output, const BalancedPort &input);
    static QString toString(WaveQuantity wave);
    static QString toString(WaveQuantity wave, uint wavePort, uint sourcePort);
    static QString toPortPair(uint outputPort, uint inputPort);

    // Time Domain
    static QString toString(VnaTimeDomain::Window window);
    static VnaTimeDomain::Window toTimeDomainWindow(QString scpi);

private:
    VnaScpi();

};
} // RsaToolbox

#endif // VNASCPI_H
