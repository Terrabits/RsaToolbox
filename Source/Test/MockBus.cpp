#include "MockBus.h"


// RsaToolbox
using namespace RsaToolbox;


MockBus::MockBus(QObject *parent) :
    GenericBus(parent)
{

}
MockBus::MockBus(ConnectionType connectionType, QString address, uint bufferSize_B, uint timeout_ms, QObject *parent) :
    GenericBus(connectionType, address, parent)
{

}
