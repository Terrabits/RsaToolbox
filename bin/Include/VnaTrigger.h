#ifndef VnaTrigger_H
#define VnaTrigger_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaTrigger : QObject
{
private: Q_OBJECT

public:

    enum /*class*/ Source {
        FreeRun,
        External,
        Manual,
        Multiple
    };

    explicit VnaTrigger(QObject *parent = 0);
    VnaTrigger(const VnaTrigger &other);
    VnaTrigger(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaTrigger(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaTrigger();

    Source source();
    void setSource(Source source);

    void sendManualTrigger();

    double delay_s();
    void setDelay(double time_s);

    void operator=(VnaTrigger const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaTrigger_H
