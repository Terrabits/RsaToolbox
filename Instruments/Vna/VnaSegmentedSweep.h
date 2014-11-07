#ifndef VnaSegmentedSweep_H
#define VnaSegmentedSweep_H


// RsaToolbox
#include "Definitions.h"
#include "NetworkData.h"
#include "VnaSweepSegment.h"

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaSegmentedSweep : public QObject
{
private: Q_OBJECT

public:
    explicit VnaSegmentedSweep(QObject *parent = 0);
    VnaSegmentedSweep(VnaSegmentedSweep &other);
    VnaSegmentedSweep(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaSegmentedSweep(Vna *vna, uint channelIndex, QObject *parent = 0);

    uint points();
    double start_Hz();
    double stop_Hz();
    QVector<double> frequencies_Hz();
    double power_dBm();
    void setPower(double power_dBm);
    double ifBandwidth_Hz();
    void setIfbandwidth(double bandwidth, SiPrefix prefix = NO_PREFIX);

    uint segments();
    uint addSegment();
    void deleteSegment(uint index);
    void deleteSegments();
    VnaSweepSegment &segment(uint index);

    QVector<uint> sParameterGroup();
    void setSParameterGroup(QVector<uint> ports);
    void clearSParameterGroup();
    ComplexMatrix3D readSParameterGroup();

    bool isAutoSweepTimeOn();
    bool isAutoSweepTimeOff();
    void autoSweepTimeOn(bool isOn = true);
    void autoSweepTimeOff(bool isOff = true);
    uint sweepTime_ms();
    void setSweepTime(uint time_ms);

    NetworkData measure(uint port1);
    NetworkData measure(uint port1, uint port2);
    NetworkData measure(uint port1, uint port2, uint port3);
    NetworkData measure(uint port1, uint port2, uint port3, uint port4);
    NetworkData measure(QVector<uint> ports);

    void operator=(VnaSegmentedSweep const &other);

//    void moveToThread(QThread *thread);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    QScopedPointer<VnaSweepSegment> _segment;

    bool isFullyInitialized() const;
    static uint frequencyBufferSize(uint points);
};
}

#endif // VnaSegmentedSweep_H
