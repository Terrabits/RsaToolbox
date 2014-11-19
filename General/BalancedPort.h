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

    enum class Type {
        SingleEnded = 0,
        Differential,
        Common
    };

    BalancedPort();
    BalancedPort(uint port);

    bool isSingleEnded();
    bool isBalanced();
    bool isDifferential();
    bool isCommonMode();
    Type type();
    void setSingleEnded();
    void setDifferential();
    void setCommonMode();
    void setType(BalancedPort::Type type);


    uint port();
    void setPort(uint logicalPort);

    operator int();
    operator uint();

private:
    Type _type;
    uint _port;
};
}
Q_DECLARE_METATYPE(RsaToolbox::BalancedPort)
Q_DECLARE_METATYPE(RsaToolbox::BalancedPort::Type)


#endif // BALANCED_PORT_H
