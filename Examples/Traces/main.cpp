

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

    // Set S-Parameter
    // for balanced ports
    // Note: Balanced ports must
    //   be defined in channel.
    //   See channel example.
    // Type options:
    //   SingleEnded
    //   Differential
    //   Common
    // Example: Sdd21
    BalancedPort port1(1, BalancedPort::Type::Differential);
    BalancedPort port2(2, BalancedPort::Type::Differential);
//    trc1.setSParameter(port2, port1);

    // Set impedance trace
    // for single ended ports
    // Example: Z-S11
    trc1.setImpedance(1, 1);

    // Set impedance trace
    // for balanced ports
    // Example: Z-Sdd11
//    trc1.setImpedance(port1, port1);

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
    trc1.setFormat(TraceFormat::DecibelMagnitude);

    // Save data to csv locally.
    // Data is as displayed (e.g. dB)
    QDir src(SOURCE_DIR);
    trc1.saveCsvLocally(src.filePath("formatted_data.csv"));

    // Save complex data to csv locally
    // Data is complex regardless of
    //   the format of the trace.
    // ComplexFormat:
    //   DecibelDegrees
    //   MagnitudeDegrees
    //   RealImaginary
    trc1.saveComplexCsvLocally(src.filePath("complex_data.csv"), ComplexFormat::DecibelDegrees);

    return 0;
}
