#ifndef VNALOGSWEEP_H
#define VNALOGSWEEP_H


// RsaToolbox
#include "Definitions.h"
#include "NetworkData.h"

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaLogSweep : public QObject
{
    Q_OBJECT

public:
    explicit VnaLogSweep(QObject *parent = 0);
    VnaLogSweep(VnaLogSweep &other);
    VnaLogSweep(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaLogSweep(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaLogSweep();

    uint points();
    void setPoints(uint numberOfPoints);
    double start_Hz();
    void setStart(double frequency, SiPrefix prefix = SiPrefix::None);
    double stop_Hz();
    void setStop(double frequency, SiPrefix prefix = SiPrefix::None);
    QVector<double> frequencies_Hz();
    double power_dBm();
    void setPower(double power_dBm);
    double ifBandwidth_Hz();
    void setIfbandwidth(double bandwidth, SiPrefix prefix = SiPrefix::None);

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

    void operator=(VnaLogSweep const &other);

//    void moveToThread(QThread *thread);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;

    bool isFullyInitialized() const;
    static uint frequencyBufferSize(uint points);
};
}

#endif // VnaLogSweep_H
