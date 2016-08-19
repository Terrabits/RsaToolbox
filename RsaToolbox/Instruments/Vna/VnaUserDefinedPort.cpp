#include "VnaUserDefinedPort.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QStringList>


/*!
 * \class RsaToolbox::VnaUserDefinedPort
 * \ingroup VnaGroup
 * \brief The \c %VnaUserDefinedPort class
 * controls the setup of user-defined ports
 */

VnaUserDefinedPort::VnaUserDefinedPort()
{
    _sourcePort = 0;

    _referencePort = 0;
    _referenceReceiver = Receiver::A;

    _measurementPort = 0;
    _measurementReceiver = Receiver::B;
}
VnaUserDefinedPort::VnaUserDefinedPort(const VnaUserDefinedPort &other) {
    this->operator =(other);
}


bool VnaUserDefinedPort::isSourceSet(uint port) const {
    return(port == _sourcePort);
}
uint VnaUserDefinedPort::sourcePort() const {
    return(_sourcePort);
}
void VnaUserDefinedPort::setSource(uint port) {
    _sourcePort = port;
}

bool VnaUserDefinedPort::isReferenceSet(uint port, VnaUserDefinedPort::Receiver receiver) const {
    return(port == _referencePort && receiver == _referenceReceiver);
}
void VnaUserDefinedPort::reference(uint &port, VnaUserDefinedPort::Receiver &receiver) const {
    port = _referencePort;
    receiver = _referenceReceiver;
}
void VnaUserDefinedPort::setReference(uint port, VnaUserDefinedPort::Receiver receiver) {
    _referencePort = port;
    _referenceReceiver = receiver;
}

bool VnaUserDefinedPort::isMeasurementSet(uint port, VnaUserDefinedPort::Receiver receiver) const {
    return(port == _measurementPort && receiver == _measurementReceiver);
}
void VnaUserDefinedPort::measurement(uint &port, VnaUserDefinedPort::Receiver &receiver) const {
    port = _measurementPort;
    receiver = _measurementReceiver;
}
void VnaUserDefinedPort::setMeasurement(uint port, VnaUserDefinedPort::Receiver receiver) {
    _measurementPort = port;
    _measurementReceiver = receiver;
}

void VnaUserDefinedPort::operator=(VnaUserDefinedPort const &other) {
    _sourcePort = other._sourcePort;

    _referencePort = other._referencePort;
    _referenceReceiver = other._referenceReceiver;

    _measurementPort = other._measurementPort;
    _measurementReceiver = other._measurementReceiver;
}

bool operator==(const VnaUserDefinedPort &left, const VnaUserDefinedPort &right) {
    uint leftSourcePort = left.sourcePort();
    uint leftReferencePort, leftMeasurePort;
    VnaUserDefinedPort::Receiver leftReferenceReceiver, leftMeasureReceiver;
    left.reference(leftReferencePort, leftReferenceReceiver);
    left.measurement(leftMeasurePort, leftMeasureReceiver);
    return(right.isSourceSet(leftSourcePort)
           && right.isReferenceSet(leftReferencePort, leftReferenceReceiver)
           && right.isMeasurementSet(leftMeasurePort, leftMeasureReceiver));
}
bool operator!=(const VnaUserDefinedPort &left, const VnaUserDefinedPort &right) {
    return(!(left == right));
}
