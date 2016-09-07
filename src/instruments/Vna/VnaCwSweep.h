#ifndef VnaCwSweep_H
#define VnaCwSweep_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaCwSweep : public QObject
{
    Q_OBJECT

public:
    explicit VnaCwSweep(QObject *parent = 0);
    VnaCwSweep(VnaCwSweep &other);
    VnaCwSweep(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaCwSweep(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaCwSweep();

    uint points();
    void setPoints(uint numberOfPoints);
    double frequency_Hz();
    void setFrequency(double frequency, SiPrefix prefix = SiPrefix::None);
    double power_dBm();
    void setPower(double power_dBm);
    double ifBandwidth_Hz();
    void setIfBandwidth(double bandwidth, SiPrefix prefix = SiPrefix::None);

    uint sweepTime_ms();

    void operator=(VnaCwSweep const &other);

//    void moveToThread(QThread *thread);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaCwSweep_H
