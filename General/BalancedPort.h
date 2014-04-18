#ifndef BALANCED_PORT_H
#define BALANCED_PORT_H


// Rsa
#include "Definitions.h"

// Qt
#include <QObject>
#include <QMetaType>


namespace RsaToolbox {
enum BalancedPortType {
    SINGLE_ENDED,
    DIFFERENTIAL_MODE,
    COMMON_MODE};
QString toVnaScpi(BalancedPortType type);

class BalancedPort {
public:

    BalancedPort();
    BalancedPort(uint logicalPort);

    BalancedPortType portType();
    bool isSingleEnded();
    bool isBalanced();
    bool isDifferential();
    bool isCommonMode();

    uint logicalPort();

    void setPortType(BalancedPortType type);
    void setSingleEnded();
    void setDifferential();
    void setCommonMode();

    void setLogicalPort(uint logicalPort);

    operator int();
    operator uint();

private:
    BalancedPortType _portType;
    uint _logicalPort;
};
}
Q_DECLARE_METATYPE(RsaToolbox::BalancedPort)
Q_DECLARE_METATYPE(RsaToolbox::BalancedPortType)


#endif // BALANCED_PORT_H
