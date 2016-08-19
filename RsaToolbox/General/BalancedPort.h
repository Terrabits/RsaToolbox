#ifndef BALANCED_PORT_H
#define BALANCED_PORT_H


// Rsa
#include "Definitions.h"

// Qt
#include <QObject>
#include <QMetaType>


namespace RsaToolbox {


class BalancedPort {
public:

    enum /*class*/ Type {
        SingleEnded = 0,
        Differential,
        Common
    };

    BalancedPort();
    BalancedPort(uint port);

    bool isSingleEnded() const;
    bool isBalanced() const;
    bool isDifferential() const;
    bool isCommonMode() const;
    Type type() const;
    void setSingleEnded();
    void setDifferential();
    void setCommonMode();
    void setType(BalancedPort::Type type);

    uint port() const;
    void setPort(uint logicalPort);

    operator int() const;
    operator uint() const;

private:
    Type _type;
    uint _port;
};
}
Q_DECLARE_METATYPE(RsaToolbox::BalancedPort)
Q_DECLARE_METATYPE(RsaToolbox::BalancedPort::Type)


#endif // BALANCED_PORT_H
