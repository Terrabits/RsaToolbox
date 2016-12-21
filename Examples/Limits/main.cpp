

// RsaToolbox
#include "Vna.h"
using namespace RsaToolbox;

// Qt
#include <QCoreApplication>
#include <QDir>
#include <QVector>


void main()
{
    Vna vna(ConnectionType::VisaTcpConnection, "127.0.0.1");
    VnaTrace trc1 = vna.trace("Trc1");

    // Check trace for limit line
    trc1.limits().isOn();

    // Turn on limits
    trc1.limits().on();

    // is trace pass, fail?
    trc1.limits().isPass();
    trc1.limits().isFail();

    // Are all limits passing?
    // failing?
    vna.isGlobalLimitsPass();
    vna.isGlobalLimitsFail();
}
