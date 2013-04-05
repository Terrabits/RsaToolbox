
// Rsa
#include "Definitions.h"
#include "Vna.h"

// Qt
//

using namespace RsaToolbox;


// Constructor, Destructor
Vna::Vna(ConnectionType connectionType, QString instrument_address, QString log_path, QString log_filename, QString program_name, QString program_version) {
    log = Log(log_path, log_filename, program_name, program_version);
    if (connectionType == TCPIP_CONNECTION)
        bus = new RsibBus(connectionType, instrument_address, timeout_ms);
}
Vna::~Vna() {
    delete bus;
}

