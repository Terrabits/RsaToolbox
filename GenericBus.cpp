
// RsaToolbox includes
#include "Definitions.h"
#include "GenericBus.h"

using namespace RsaToolbox;


// Constructor
GenericBus::GenericBus() {
    this->connection_type = NO_CONNECTION;
    this->address = QString();
    this->timeout_ms = 0;
}

GenericBus::GenericBus(ConnectionType connection_type, QString address, short timeout_ms) {
    this->connection_type = connection_type;
    this->address = address;
    this->timeout_ms = timeout_ms;
}
