#ifndef USERDEFINEDPORT_H
#define USERDEFINEDPORT_H


// RsaToolbox


// Qt
#include <QMetaType>
#include <QString>


namespace RsaToolbox {

enum VnaReceiver {
    RECEIVER_A,
    RECEIVER_B
};
QString toScpi(VnaReceiver receiver);
VnaReceiver toVnaReceiver(QString scpi);

class VnaUserDefinedPort
{
public:
    VnaUserDefinedPort();

    bool isSource(uint port) const;
    uint sourcePort() const;
    void setSource(uint port);

    bool isReference(uint port, VnaReceiver receiver) const;
    void reference(uint &port, VnaReceiver &receiver) const;
    void setReference(uint port, VnaReceiver receiver);

    bool isMeasure(uint port, VnaReceiver receiver) const;
    void measure(uint &port, VnaReceiver &receiver) const;
    void setMeasure(uint port, VnaReceiver receiver);

    void operator=(VnaUserDefinedPort const &other);

private:
    uint _sourcePort;

    uint _referencePort;
    VnaReceiver _referenceReceiver;

    uint _measurePort;
    VnaReceiver _measureReceiver;
};

QString toScpi(VnaUserDefinedPort userDefinedPort);
VnaUserDefinedPort toUserDefinedPort(QString scpi);
bool operator==(VnaUserDefinedPort const &left, VnaUserDefinedPort const &right);
bool operator!=(VnaUserDefinedPort const &left, VnaUserDefinedPort const &right);
}

Q_DECLARE_METATYPE(RsaToolbox::VnaReceiver)
Q_DECLARE_METATYPE(RsaToolbox::VnaUserDefinedPort)

#endif // USERDEFINEDPORT_H
