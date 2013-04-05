
// RsaToolbox includes
#include "Definitions.h"
#include "GenericBus.h"

using namespace RsaToolbox;


// Constructor
GenericBus::GenericBus(ConnectionType connectionType, QString address, short timeout_ms) {
    this->connectionType = connectionType;
    this->address = address;
    this->timeout_ms = timeout_ms;
}
