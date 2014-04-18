

// RsaToolbox
#include "VnaUserDefinedPort.h"
using namespace RsaToolbox;

// Qt
#include <QStringList>

/*!
 * \class RsaToolbox::VnaUserDefinedPort
 * \ingroup VnaGroup
 * \brief The \c %VnaUserDefinedPort class
 * controls the setup of user-defined ports
 */

RsaToolbox::VnaUserDefinedPort::VnaUserDefinedPort()
{
    _sourcePort = 0;

    _referencePort = 0;
    _referenceReceiver = RECEIVER_A;

    _measurePort = 0;
    _measureReceiver = RECEIVER_B;
}

bool VnaUserDefinedPort::isSource(uint port) const {
    return(port == _sourcePort);
}
uint VnaUserDefinedPort::sourcePort() const {
    return(_sourcePort);
}
void VnaUserDefinedPort::setSource(uint port) {
    _sourcePort = port;
}

bool VnaUserDefinedPort::isReference(uint port, VnaReceiver receiver) const {
    return(port == _referencePort && receiver == _referenceReceiver);
}
void VnaUserDefinedPort::reference(uint &port, VnaReceiver &receiver) const {
    port = _referencePort;
    receiver = _referenceReceiver;
}
void VnaUserDefinedPort::setReference(uint port, VnaReceiver receiver) {
    _referencePort = port;
    _referenceReceiver = receiver;
}

bool VnaUserDefinedPort::isMeasure(uint port, VnaReceiver receiver) const {
    return(port == _measurePort && receiver == _measureReceiver);
}
void VnaUserDefinedPort::measure(uint &port, VnaReceiver &receiver) const {
    port = _measurePort;
    receiver = _measureReceiver;
}
void VnaUserDefinedPort::setMeasure(uint port, VnaReceiver receiver) {
    _measurePort = port;
    _measureReceiver = receiver;
}

void VnaUserDefinedPort::operator=(VnaUserDefinedPort const &other) {
    _sourcePort = other._sourcePort;

    _referencePort = other._referencePort;
    _referenceReceiver = other._referenceReceiver;

    _measurePort = other._measurePort;
    _measureReceiver = other._measureReceiver;
}

QString RsaToolbox::toScpi(VnaUserDefinedPort userDefinedPort) {
    QString scpi = "%1:%2%3:%4%5";
    scpi = scpi.arg(userDefinedPort.sourcePort());

    uint port;
    VnaReceiver receiver;
    userDefinedPort.reference(port, receiver);
    scpi = scpi.arg(toScpi(receiver));
    scpi = scpi.arg(port);

    userDefinedPort.measure(port, receiver);
    scpi = scpi.arg(toScpi(receiver));
    scpi = scpi.arg(port);
    return(scpi);
}
VnaUserDefinedPort RsaToolbox::toUserDefinedPort(QString scpi) {
    VnaUserDefinedPort userDefinedPort;
    QStringList list = scpi.trimmed().remove("\'").split(":");
    if (list.size() != 3)
        return(userDefinedPort);

    uint port;
    VnaReceiver receiver;
    port = list[0].toUInt();
    userDefinedPort.setSource(port);

    receiver = toVnaReceiver(list[1].at(0));
    list[1].remove(0,1);
    port = list[1].toUInt();
    userDefinedPort.setReference(port, receiver);

    receiver = toVnaReceiver(list[2].at(0));
    list[2].remove(0,1);
    port = list[2].toUInt();
    userDefinedPort.setMeasure(port, receiver);

    return(userDefinedPort);
}

bool RsaToolbox::operator==(VnaUserDefinedPort const &left, VnaUserDefinedPort const &right) {
    uint leftSourcePort = left.sourcePort();
    uint leftReferencePort, leftMeasurePort;
    VnaReceiver leftReferenceReceiver, leftMeasureReceiver;
    left.reference(leftReferencePort, leftReferenceReceiver);
    left.measure(leftMeasurePort, leftMeasureReceiver);
    return(right.isSource(leftSourcePort)
           && right.isReference(leftReferencePort, leftReferenceReceiver)
           && right.isMeasure(leftMeasurePort, leftMeasureReceiver));
}
bool RsaToolbox::operator!=(VnaUserDefinedPort const &left, VnaUserDefinedPort const &right) {
    return(!(left == right));
}

QString RsaToolbox::toScpi(VnaReceiver receiver) {
    switch(receiver) {
    case RECEIVER_A: return("a");
    case RECEIVER_B: return("b");
    default: return("b");
    }
}
VnaReceiver RsaToolbox::toVnaReceiver(QString scpi) {
    scpi = scpi.trimmed().toLower();
    if (scpi == "a")
        return(RECEIVER_A);
    if (scpi == "b")
        return(RECEIVER_B);
    // else
    return(RECEIVER_B);
}
