

// RsaToolbox
#include "Vna.h"
#include "VnaTrace.h"
using namespace RsaToolbox;

// Qt
#include <QCoreApplication>


int main(int argc, char *argv[])
{
    Vna vna(ConnectionType::VisaTcpConnection, "127.0.0.1");

    // Start from instrument preset
    vna.preset();
    vna.pause();

    // Get Trc1 interface
    VnaTrace trc1 = vna.trace("Trc1");

    // Set Parameter
    // for single-ended ports.
    // Example: S21
    trc1.setSParameter(2, 1);

    // Set Parameter
    // for balanced ports
    // Type options:
    //   SingleEnded
    //   Differential
    //   Common
    // Example: Sdd21
    BalancedPort port1(1, BalancedPort::Type::Differential);
    BalancedPort port2(2, BalancedPort::Type::Differential);
    trc1.setSParameter(port2, port1);

    // Set impedance trace
    // for single ended ports
    // Example: Z-S11
    trc1.setImpedance(1, 1);

    // Set impedance trace
    // for balanced ports
    // Example: Z-S11
    port1.setSingleEnded();
    trc1.setImpedance(port1, port1);

    // Set display format
    // Options:
    //   DecibelMagnitude,
    //   Phase,
    //   SmithChart,
    //   PolarChart,
    //   Vswr,
    //   UnwrappedPhase,
    //   Magnitude,
    //   InverseSmithChart,
    //   Real,
    //   Imaginary,
    //   Delay
    trc1.setFormat(TraceFormat::dB);

    // Set Parameter

    return 0;
}
