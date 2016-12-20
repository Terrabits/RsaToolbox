

// RsaToolbox
#include "Vna.h"
#include "VnaChannel.h"
#include "VnaLinearSweep.h"
using namespace RsaToolbox;

// Qt
#include <QCoreApplication>
#include <QDir>
#include <QVector>


int main(int argc, char *argv[])
{
    Vna vna(ConnectionType::VisaTcpConnection, "127.0.0.1");

    // Start from instrument preset
    vna.preset();
    vna.pause();

    // Channel 1 interface
    //   Optional. Could also use
    //   vna.channel(index).<method>(..)
    VnaChannel ch1 = vna.channel(1);

    // Configure balanced ports
    // Logical Port 1: Physical ports (1, 3);
    // Logical Port 2: Physical ports (2, 4);
    ch1.createBalancedPort(1, 1, 3);
    ch1.createBalancedPort(2, 2, 4);

    // Set sweep type
    ch1.setSweepType(VnaChannel::SweepType::Linear);

    // Set sweep settings manually
    VnaLinearSweep ch1Sweep = ch1.linearSweep();
    ch1Sweep.setStart(10, SiPrefix::Mega);      // 10 MHz
    ch1Sweep.setStop (20, SiPrefix::Giga);      // 20 GHz
    ch1Sweep.setPoints(2000);
    ch1Sweep.setIfbandwidth(1, SiPrefix::Kilo); //  1 KHz
    ch1Sweep.setPower(0);                       //  0 dBm

    // ...Alternatively:
    // Set harmonic sweep settings.
    // Time domain traces require
    // harmonic frequency settings.
    //
    // For this example,
    // Result:
    //   Start:   10 MHz
    //   Stop:    20 GHz
    //   Points:  2000
    //   Spacing: 10 MHz
    //   Each frequency point is a harmonic of 10 MHz
    const double stop_Hz = 20e9;
    const uint   points  = 2000;
    ch1Sweep.createHarmonicGrid(stop_Hz, points);

    // Create a new channel
    // with next index
    uint nextIndex = vna.createChannel();

    // Create a new channel
    // with a specifix index
    vna.createChannel(3);

    // Copy a channel
    // Note: when creating a
    //   channel, new channel has
    //   same settings as last
    //   active channel.
    ch1.select();                    // Now active
    vna.createChannel(4); // Copy of 1

    // Save measurement to
    // snp file on host computer
    // Formats:
    //   DecibelDegrees
    //   MagnitudeDegrees
    //   RealImaginary
    QDir src(SOURCE_DIR);
    QVector<uint> ports;
    ports << 1 << 2 << 3 << 4;
    ch1Sweep.measureToSnpLocally(src.filePath("filename.s4p"), ports, ComplexFormat::RealImaginary);

    return 0;
}
