#ifndef VNALINEARSWEEP_H
#define VNALINEARSWEEP_H


// RsaToolbox
#include "Definitions.h"
#include "NetworkData.h"

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaLinearSweep : public QObject
{
    Q_OBJECT

public:
    explicit VnaLinearSweep(QObject *parent = 0);
    VnaLinearSweep(VnaLinearSweep &other);
    VnaLinearSweep(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaLinearSweep(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaLinearSweep();

    uint points();
    void setPoints(uint numberOfPoints);
    double start_Hz();
    void setStart(double frequency, SiPrefix prefix = SiPrefix::None);
    double stop_Hz();
    void setStop(double frequency, SiPrefix prefix = SiPrefix::None);
    double center_Hz();
    void setCenter(double frequency, SiPrefix prefix = SiPrefix::None);
    double span_Hz();
    void setSpan(double frequencyRange, SiPrefix prefix = SiPrefix::None);
    double spacing_Hz();
    void setSpacing(double frequencySpacing, SiPrefix prefix = SiPrefix::None);
    QRowVector frequencies_Hz();
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

    bool saveSnp(QString filePathName, uint port1, ComplexFormat format = ComplexFormat::RealImaginary);
    bool saveSnp(QString filePathName, uint port1, uint port2, ComplexFormat format = ComplexFormat::RealImaginary);
    bool saveSnp(QString filePathName, uint port1, uint port2, uint port3, ComplexFormat format = ComplexFormat::RealImaginary);
    bool saveSnp(QString filePathName, uint port1, uint port2, uint port3, uint port4, ComplexFormat format = ComplexFormat::RealImaginary);
    bool saveSnp(QString filePathName, QVector<uint> ports, ComplexFormat format = ComplexFormat::RealImaginary);

    void operator=(VnaLinearSweep const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;

    bool isFullyInitialized() const;
    static uint frequencyBufferSize(uint points);
    static uint dataBufferSize(uint ports, uint points);
    QString toScpi(ComplexFormat format);
};
}

#endif // VnaLinearSweep_H
