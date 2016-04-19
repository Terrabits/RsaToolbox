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
    Q_OBJECT

public:
    explicit VnaSegmentedSweep(QObject *parent = 0);
    VnaSegmentedSweep(VnaSegmentedSweep &other);
    VnaSegmentedSweep(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaSegmentedSweep(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaSegmentedSweep();

    uint points();
    double start_Hz();
    double stop_Hz();
    QVector<double> frequencies_Hz();
    double power_dBm();
    void setPower(double power_dBm);
    double ifBandwidth_Hz();
    void setIfbandwidth(double bandwidth, SiPrefix prefix = SiPrefix::None);

    uint segments();
    void addSegment(uint index);
    uint addSegment();
    void deleteSegment(uint index);
    void deleteSegments();
    VnaSweepSegment &segment(uint index);

    QVector<uint> sParameterGroup();
    void setSParameterGroup(QVector<uint> ports);
    void clearSParameterGroup();
    ComplexMatrix3D readSParameterGroup();

    uint sweepTime_ms();

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
    static uint dataBufferSize(uint ports, uint points);
};
}

#endif // VnaSegmentedSweep_H
