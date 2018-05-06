#ifndef VnaSyncGenerator_H
#define VnaSyncGenerator_H


// RsaToolbox
#include "Definitions.h"
#include "vnapulsetype.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaSyncGenerator : QObject
{
private: Q_OBJECT

public:
    explicit VnaSyncGenerator(QObject *parent = 0);
    VnaSyncGenerator(const VnaSyncGenerator &other);
    VnaSyncGenerator(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaSyncGenerator(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaSyncGenerator();

    bool isOn();
    void on(bool isOn = true);
    void off(bool isOff = true);

    VnaPulseType type();
    void setType(VnaPulseType type);

    double delay_s();
    void setDelay(double value, SiPrefix prefix = SiPrefix::None);

    double pulseWidth_s();
    void setPulseWidth(double value, SiPrefix prefix = SiPrefix::None);

    bool isInverted();
    void setInverted(bool isInverted = true);

    bool isChannelSpecific();
    void setChannelSpecific(bool isSpecific = true);

    void operator=(VnaSyncGenerator const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;
};
}

#endif // VnaSyncGenerator_H
