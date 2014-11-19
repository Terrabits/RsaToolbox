#ifndef VNASCPI_H
#define VNASCPI_H


#include "BalancedPort.h"

namespace RsaToolbox {


class VnaScpi
{
public:

    // Balanced Port
    static QString toString(BalancedPort::Type type);
    static BalancedPort::Type toBalancedPortType(const QString &scpi);

    // Trace
    static QString toString(TraceFormat format);
    static TraceFormat toTraceFormat(const QString &scpi);

    static QString toString(NetworkParameter parameter);
    static QString toString(NetworkParameter parameter, uint outputPort, uint inputPort);
    static QString toString(NetworkParameter parameter, const BalancedPort &output, const BalancedPort &input);
    static QString toString(WaveQuantity wave, uint port);
    static QString toPortPair(uint outputPort, uint inputPort);

private:
    VnaScpi();


};
} // RsaToolbox

#endif // VNASCPI_H
