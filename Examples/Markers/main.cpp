

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

    VnaTrace trc1 = vna.trace("Trc1");

    // Get current markers
    // => QVector<uint>
    // Marker indices are from 1-10
    trc1.markers();

    // Create a marker
    uint i = trc1.createMarker();

    // Get interface to marker
    VnaMarker m1 = trc1.marker(i);

    // Give the marker a name
    m1.setName("my_marker");

    // Set x position
    m1.setX(1, SiPrefix::Giga);

    // Get x position
    double x1 = m1.x();

    // Read formatted y value
    double y1 = m1.y();

    // Read both x and y
    m1.coordinates(x1, y1);

    // Move marker to a particular
    // y value, if it exists
    m1.searchFor(-10.0);

    // Move marker left, to
    // next instance of y
    m1.searchLeftFor(-10.0);

    // Or move right
    m1.searchRightFor(-10.0);

    // Find max
    m1.searchForMax();

    // Find min
    m1.searchForMin();

    // Search left for max
    m1.searchLeftForPeak();

    // Search right for max
    m1.searchRightForPeak();

    // Create reference marker
    // Note: all markers share
    // reference within trace
    trc1.referenceMarker().on();

    VnaReferenceMarker ref = trc1.referenceMarker();

    // Reference markers have
    // similar functions to
    // regular markers
    ref.setX(1, SiPrefix::Giga);
    double y_ref = ref.y();

    // Reference markers can be
    // moved to another marker.
    // Now m1 and ref overlap:
    ref.setToMarker(i);

    // Markers can display
    // delta values with reference
    m1.deltaOn();
}
