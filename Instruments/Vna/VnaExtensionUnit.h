#ifndef VnaExtensionUnit_H
#define VnaExtensionUnit_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaExtensionUnit : QObject
{
private: Q_OBJECT

public:
    explicit VnaExtensionUnit(QObject *parent = 0);
    VnaExtensionUnit(const VnaExtensionUnit &other);
    VnaExtensionUnit(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaExtensionUnit(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaExtensionUnit();

    // Methods

    void operator=(VnaExtensionUnit const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaExtensionUnit_H
