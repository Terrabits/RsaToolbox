

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


}
