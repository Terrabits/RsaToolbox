#ifndef VNASCPI_H
#define VNASCPI_H


#include "VnaChannel.h"
#include "BalancedPort.h"
#include "VnaUserDefinedPort.h"
#include "VnaTimeDomain.h"

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
