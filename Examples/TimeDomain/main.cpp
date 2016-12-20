

// RsaToolbox
#include "Vna.h"
using namespace RsaToolbox;

// Qt
#include <QCoreApplication>
#include <QDir>


void main()
{
    Vna vna(ConnectionType::VisaTcpConnection, "127.0.0.1");

    // Start from instrument preset
    vna.preset();
    vna.pause();

    // Channel must have harmonically-
    // spaced frequency points to be
    // properly converted to time domain
    VnaChannel ch1 = vna.channel(1);
    ch1.setSweepType(VnaChannel::SweepType::Linear);

    const double stopFreq_Hz = 20e9;
    const uint   points      = 2000;
    VnaLinearSweep sweep1    = ch1.linearSweep();
    sweep1.createHarmonicGrid(stopFreq_Hz, points);

    // Result:
    //   Start Freq: 10 MHz
    //   Stop Freq:  20 GHz
    //   Spacing:    10 MHz
    //   Points:   2000

    // Setup time domain trace
    VnaTrace trc1 = vna.trace("Trc1");
    trc1.timeDomain().on();

    // Set response type
    // Options:
    //   Bandpass impulse
    //   Lowpass impulse
    //   Lowpass step
    // This is usually lowpass step
    trc1.timeDomain().setLowpassStepResponse();

    // An estimated DC value is necessary
    // for the time domain transform.
    // You can either use automatic extrapolation
    trc1.timeDomain().automaticDcExtrapolationOn();

    // ... or set a DC value manually
    trc1.timeDomain().manualDcExtrapolationOn();
    trc1.timeDomain().setExtrapolatedDcValue(0); // 0 Ohms

    // Optionally, you can
    // set a transform window
    // Options:
    //   Regular
    //   Hamming
    //   Hann (default)
    //   Bohman
    //   DolphChebychev
    trc1.timeDomain().setWindow(VnaTimeDomain::Window::Hann);

    // For time domain traces,
    // the x-axis (range) can be set.
    // Each time domain trace x-axis must be
    // set separately, regardless of what
    // diagram it is in.
    // Setting them all to the same range
    // is preferred for readability.
    trc1.timeDomain().setStart(-20, SiPrefix::Nano);
    trc1.timeDomain().setStop ( 20, SiPrefix::Nano);

    // As with any trace, you
    // can save formatted data
    QDir src(SOURCE_DIR);
    trc1.saveCsvLocally(src.filePath("formatted_data.csv"));

    // ...and save complex data
    trc1.saveComplexCsvLocally(src.filePath("complex_data.csv"));
}
