#ifndef %NAME%_H
#define %NAME%_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class %NAME% : QObject
{
private: Q_OBJECT

public:
    explicit %NAME%(QObject *parent = 0);
    %NAME%(const %NAME% &other);
    %NAME%(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    %NAME%(Vna *vna, uint channelIndex, QObject *parent = 0);

    // Methods

    void operator=(%NAME% const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;
    
};
}

#endif // %NAME%_H
