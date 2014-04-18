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
private: Q_OBJECT

public:
    explicit VnaLinearSweep(QObject *parent = 0);
    VnaLinearSweep(VnaLinearSweep &other);
    VnaLinearSweep(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaLinearSweep(Vna *vna, uint channelIndex, QObject *parent = 0);

    uint points();
    void setPoints(uint numberOfPoints);
    double start_Hz();
    void setStart(double frequency, SiPrefix prefix = NO_PREFIX);
    double stop_Hz();
    void setStop(double frequency, SiPrefix prefix = NO_PREFIX);
    double center_Hz();
    void setCenter(double frequency, SiPrefix prefix = NO_PREFIX);
    double span_Hz();
    void setSpan(double frequencyRange, SiPrefix prefix = NO_PREFIX);
    double spacing_Hz();
    void setSpacing(double frequencySpacing, SiPrefix prefix = NO_PREFIX);
    QRowVector frequencies_Hz();
    double power_dBm();
    void setPower(double power_dBm);
    double ifBandwidth_Hz();
    void setIfbandwidth(double bandwidth, SiPrefix prefix = NO_PREFIX);

    QVector<uint> sParameterGroup();
    void setSParameterGroup(QVector<uint> ports);
    void clearSParameterGroup();
    ComplexMatrix3D readSParameterGroup();

    double estimatedSweepTime_s();
    void setSweepTime(double time_s);
    NetworkData measure(uint port1);
    NetworkData measure(uint port1, uint port2);
    NetworkData measure(uint port1, uint port2, uint port3);
    NetworkData measure(uint port1, uint port2, uint port3, uint port4);
    NetworkData measure(QVector<uint> ports);

    bool saveSnp(QString filePathName, uint port1, ComplexFormat format = REAL_IMAGINARY_COMPLEX);
    bool saveSnp(QString filePathName, uint port1, uint port2, ComplexFormat format = REAL_IMAGINARY_COMPLEX);
    bool saveSnp(QString filePathName, uint port1, uint port2, uint port3, ComplexFormat format = REAL_IMAGINARY_COMPLEX);
    bool saveSnp(QString filePathName, uint port1, uint port2, uint port3, uint port4, ComplexFormat format = REAL_IMAGINARY_COMPLEX);
    bool saveSnp(QString filePathName, QVector<uint> ports, ComplexFormat format = REAL_IMAGINARY_COMPLEX);

    void operator=(VnaLinearSweep const &other);

//    void moveToThread(QThread *thread);

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
