#ifndef VnaSwitchMatrix_H
#define VnaSwitchMatrix_H


// RsaToolbox
#include "Definitions.h"
#include "GenericBus.h"

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;

class VnaSwitchMatrix : public QObject
{
    Q_OBJECT

public:

    enum /*class*/ ConnectionType {
        Usb,
        Lan,
        DirectControl
    };
    enum /*class*/ Driver {
        ZN_Z84_02,
        ZN_Z84_22,
        ZN_Z84_24,
        ZN_Z84_32,
        ZN_Z84_34,
        ZN_Z84_42,
        ZN_Z84_44,
        ZN_Z85_02,
        ZN_Z85_24,
        ZN_Z81_05,
        ZN_Z81_09,
        ZN_Z81_29,
        ZN_Z81_66,
        ZN_Z82_10,
        ZN_Z82_16,
        ZN_Z82_30
    };

    explicit VnaSwitchMatrix(QObject *parent = 0);
    VnaSwitchMatrix(const VnaSwitchMatrix &other);
    VnaSwitchMatrix(Vna *vna, uint index, QObject *parent = 0);
    ~VnaSwitchMatrix();

    QString driver();
    VnaSwitchMatrix::ConnectionType connectionType();
    QString address();

    bool hasTestPort(uint testPort);
    PortMap switchMatrixToVnaPortMap();
    PortMap testPortToMatrixMap();

    void setConnectionsToVna(PortMap matrixToVnaPortMap);
    void setTestPorts(PortMap matrixToTestPortMap);

    void operator=(VnaSwitchMatrix const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    uint _index;
    
    bool isFullyInitialized() const;
    QStringList defineQuery();
    
};
}

#endif // VnaSwitchMatrix_H
