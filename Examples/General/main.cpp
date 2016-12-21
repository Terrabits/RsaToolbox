

// RsaToolbox
#include "Log.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt
#include <QCoreApplication>
#include <QDir>
#include <QVector>


void main()
{
    Vna vna(ConnectionType::VisaTcpConnection, "127.0.0.1");

    // Create log file.
    // Log is useful in case of an
    // error
    QDir src(SOURCE_DIR);
    Log log(src.filePath("filename.txt"),
                    "My Application",
                    "1.0");
    log.printHeader();
    vna.useLog(&log);
    vna.printInfo();

    // Get VNA info
    vna.isRohdeSchwarz();
    vna.properties().model();
    vna.properties().isKnownModel();
    vna.properties().serialNumber();
    vna.properties().firmwareVersion();
    vna.properties().optionsList();

    vna.properties().physicalPorts();
    vna.properties().maximumFrequency_Hz();
    vna.properties().minimumFrequency_Hz();

    // Total number of ports available
    // for measurement (e.g. including
    // switch matrix).
    vna.testPorts();

    // Turn the display on/off
    // in remote control mode
    vna.settings().displayOn();
    vna.settings().displayOff();

    // Preset instrument to
    // factory default state.
    // Wait for preset to finish.
    vna.preset();
    vna.pause();

    // Put instrument into
    // local or remote mode
    vna.local();
    vna.remote();

    // Check for SCPI errors
    // and clear them.
    vna.isError();
    vna.clearStatus();
}
