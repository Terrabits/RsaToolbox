#ifndef VnaPulseGenerator_H
#define VnaPulseGenerator_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaPulseGenerator : QObject
{
private: Q_OBJECT

public:
    explicit VnaPulseGenerator(QObject *parent = 0);
    VnaPulseGenerator(const VnaPulseGenerator &other);
    VnaPulseGenerator(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaPulseGenerator(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaPulseGenerator();

    bool isOn();
    void on(bool isOn = true);
    void off(bool isOff = true);

    double delay_s();
    void setDelay(double value, SiPrefix prefix = SiPrefix::None);

    double pulseWidth_s();
    void setPulseWidth(double value, SiPrefix prefix = SiPrefix::None);

    double period_s();
    void setPeriod(double value, SiPrefix prefix = SiPrefix::None);

    void operator=(VnaPulseGenerator const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaPulseGenerator_H
