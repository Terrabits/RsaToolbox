#ifndef VnaSweepSegment_H
#define VnaSweepSegment_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;
class VnaSegmentedSweep;

class VnaSweepSegment : public QObject
{
    Q_OBJECT

public:
    explicit VnaSweepSegment(QObject *parent = 0);
    VnaSweepSegment(VnaSweepSegment &other);
    VnaSweepSegment(Vna *vna, VnaChannel *channel, uint index, QObject *parent = 0);
    VnaSweepSegment(Vna *vna, uint channelIndex, uint segmentIndex, QObject *parent = 0);
    ~VnaSweepSegment();

    bool isOn();
    bool isOff();
    void on();
    void off();

    uint points();
    void setPoints(uint numberOfPoints);

    double start_Hz();
    void setStart(double frequency, SiPrefix prefix = SiPrefix::None);
    double stop_Hz();
    void setStop(double frequency, SiPrefix prefix = SiPrefix::None);
    void setSingleFrequency(double frequency, SiPrefix prefix = SiPrefix::None);

    double power_dBm();
    void setPower(double power_dBm);

    void operator=(VnaSweepSegment const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    uint _segmentIndex;


    bool isFullyInitialized() const;
};
}

#endif // VnaSweepSegment_H
