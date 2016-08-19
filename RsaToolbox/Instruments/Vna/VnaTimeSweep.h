#ifndef VnaTimeSweep_H
#define VnaTimeSweep_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaTimeSweep : public QObject
{
    Q_OBJECT

public:
    explicit VnaTimeSweep(QObject *parent = 0);
    VnaTimeSweep(VnaTimeSweep &other);
    VnaTimeSweep(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaTimeSweep(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaTimeSweep();

    uint points();
    void setPoints(uint numberOfPoints);
    double frequency_Hz();
    void setFrequency(double frequency, SiPrefix prefix = SiPrefix::None);
    double power_dBm();
    void setPower(double power_dBm);
    double ifBandwidth_Hz();
    void setIfBandwidth(double bandwidth, SiPrefix prefix = SiPrefix::None);
    double time_s();
    void setTime(double time, SiPrefix prefix = SiPrefix::None);

    void operator=(VnaTimeSweep const &other);

//    void moveToThread(QThread *thread);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaTimeSweep_H
