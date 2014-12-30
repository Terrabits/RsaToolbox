#ifndef VNASCPI_H
#define VNASCPI_H


#include "VnaChannel.h"
#include "BalancedPort.h"
#include "VnaUserDefinedPort.h"
#include "VnaCalStandard.h"
#include "VnaTimeDomain.h"
#include "GenericBus.h"

namespace RsaToolbox {


class VnaScpi
{
public:

    // Channel
    static QString toString(VnaChannel::SweepType type);
    static VnaChannel::SweepType toSweepType(QString scpi);

    // Balanced Port
    static QString toString(BalancedPort::Type type);
    static BalancedPort::Type toBalancedPortType(QString scpi);

    // User defined port
    static QString toString(VnaUserDefinedPort::Receiver receiver);
    static QString toString(VnaUserDefinedPort port);
    static VnaUserDefinedPort::Receiver toReceiver(QString scpi);
    static VnaUserDefinedPort toUserDefinedPort(QString scpi);

    // Switch Matrix
    static QString toMatrixString(ConnectionType type);
    static ConnectionType toMatrixConnection(QString scpi);

    // Connector
    static QString toString(Connector::Gender gender);
    static QString toGenderString(Connector connector);
    static QString toString(Connector::Type type);
    static QString toTypeString(Connector connector);
    static Connector::Gender toConnectorGender(QString scpi);
    static Connector::Type toConnectorType(QString scpi);

    // Calibration Standards
    static QString toString(const VnaCalStandard &standard);
    static QString toString(VnaStandardType type);
    static QString toString(VnaStandardType type, Connector::Gender gender);
    static QString toString(VnaStandardType type, Connector::Gender gender, uint port);
    static QString toString(VnaStandardType type, Connector::Gender gender1, Connector::Gender gender2);
    static QString toString(VnaStandardType type, Connector::Gender gender1, uint port1, Connector::Gender gender2, uint port2);
    static VnaCalStandard toCalStandard(QString scpi);

    // Calibration
    static QString toString(VnaCalibrate::CalType type);
    static VnaCalibrate::CalType toCalType(QString scpi);

    // Trace
    static QString toString(TraceFormat format);
    static TraceFormat toTraceFormat(QString scpi);
    static QString toString(NetworkParameter parameter);
    static QString toString(NetworkParameter parameter, uint outputPort, uint inputPort);
    static QString toString(NetworkParameter parameter, const BalancedPort &output, const BalancedPort &input);
    static QString toString(WaveQuantity wave);
    static QString toString(WaveQuantity wave, uint port);
    static QString toPortPair(uint outputPort, uint inputPort);

    // Time Domain
    static QString toString(VnaTimeDomain::Window window);
    static VnaTimeDomain::Window toTimeDomainWindow(QString scpi);

private:
    VnaScpi();

};
} // RsaToolbox

#endif // VNASCPI_H
