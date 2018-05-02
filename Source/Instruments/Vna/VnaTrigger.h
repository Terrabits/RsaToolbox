#ifndef VnaTrigger_H
#define VnaTrigger_H


// RsaToolbox
#include "Definitions.h"
#include "vnatriggersource.h"

// Qt
#include <QMetaObject>
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaTrigger : QObject
{
    Q_OBJECT
public:

    enum /*class*/ Sequence {
        Sweep,
        Segment,
        Point,
        PartialPoint
    };

    explicit VnaTrigger(QObject *parent = 0);
    VnaTrigger(const VnaTrigger &other);
    VnaTrigger(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaTrigger(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaTrigger();

    VnaTriggerSource source();
    void setSource(VnaTriggerSource source);

    void manualTrigger();

    bool isOnPositiveEdge();
    void setOnPositiveEdge(bool positive = true);

    Sequence sequence();
    void setSequence(Sequence sequence);

    double delay_s();
    void setDelay(double time, SiPrefix prefix=SiPrefix::None);

    void operator=(VnaTrigger const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;
    
};
}

#include "vnatriggersequence.h"

#endif // VnaTrigger_H
