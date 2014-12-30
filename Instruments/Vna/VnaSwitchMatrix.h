#ifndef VnaSwitchMatrix_H
#define VnaSwitchMatrix_H


// RsaToolbox
#include "Definitions.h"
#include "GenericBus.h"
#include "VnaScpi.h"

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;

class VnaSwitchMatrix : public QObject
{
    Q_OBJECT

public:
    explicit VnaSwitchMatrix(QObject *parent = 0);
    VnaSwitchMatrix(const VnaSwitchMatrix &other);
    VnaSwitchMatrix(Vna *vna, uint index, QObject *parent = 0);
    ~VnaSwitchMatrix();

    QString driver();
    ConnectionType connectionType();
    QString address();

    bool hasTestPort(uint testPort);
    PortMap matrixToVnaPortMap();
    PortMap testPortToMatrixMap();

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
