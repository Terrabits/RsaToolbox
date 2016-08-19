#ifndef USERDEFINEDPORT_H
#define USERDEFINEDPORT_H


// Qt
#include <QMetaType>
#include <QString>


namespace RsaToolbox {


class VnaUserDefinedPort
{
public:

    enum /*class*/ Receiver {
        A,
        B
    };

    VnaUserDefinedPort();
    VnaUserDefinedPort(const VnaUserDefinedPort &other);

    bool isSourceSet(uint port) const;
    uint sourcePort() const;
    void setSource(uint port);

    bool isReferenceSet(uint port, Receiver receiver) const;
    void reference(uint &port, Receiver &receiver) const;
    void setReference(uint port, Receiver receiver);

    bool isMeasurementSet(uint port, Receiver receiver) const;
    void measurement(uint &port, Receiver &receiver) const;
    void setMeasurement(uint port, Receiver receiver);

    void operator=(const VnaUserDefinedPort &other);

private:
    uint _sourcePort;

    uint _referencePort;
    Receiver _referenceReceiver;

    uint _measurementPort;
    Receiver _measurementReceiver;
};
} // RsaToolbox

bool operator==(const RsaToolbox::VnaUserDefinedPort &left, const RsaToolbox::VnaUserDefinedPort &right);
bool operator!=(const RsaToolbox::VnaUserDefinedPort &left, const RsaToolbox::VnaUserDefinedPort &right);

Q_DECLARE_METATYPE(RsaToolbox::VnaUserDefinedPort::Receiver)
Q_DECLARE_METATYPE(RsaToolbox::VnaUserDefinedPort)

#endif // USERDEFINEDPORT_H
