#ifndef VnaCorrections_H
#define VnaCorrections_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;
enum VnaSweepType;
enum VnaCalType;

class VnaCorrections : public QObject
{
private: Q_OBJECT

public:
    explicit VnaCorrections(QObject *parent = 0);
    VnaCorrections(VnaCorrections &other);
    VnaCorrections(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaCorrections(Vna *vna, uint channelIndex, QObject *parent = 0);

    bool isOn();
    bool isOff();
    bool isPresent();
    bool isNotPresent();
    bool isInterpolated();
    bool isNotInterpolated();
    void on(bool isOn = true);
    void off(bool isOff = true);
    QString calGroup();
    void setCalGroup(QString calGroup);
    void saveToCalGroup(QString calGroup);
    void dissolveCalGroupLink();
    void clear(); //?

    // Correction values
    VnaCalType calibrationType();
    VnaSweepType sweepType();
    QVector<uint> ports();
    uint points();
    double startFrequency_Hz();
    double stopFrequency_Hz();
    double power_dBm();

    ComplexRowVector directivity(uint outputPort, uint inputPort);
    void setDirectivity(ComplexRowVector corrections, uint outputPort, uint inputPort);
    ComplexRowVector sourceMatch(uint outputPort, uint inputPort);
    void setSourceMatch(ComplexRowVector corrections, uint outputPort, uint inputPort);
    ComplexRowVector reflectionTracking(uint outputPort, uint inputPort);
    void setReflectionTracking(ComplexRowVector corrections, uint outputPort, uint inputPort);
    ComplexRowVector loadMatch(uint outputPort, uint inputPort);
    void setLoadMatch(ComplexRowVector corrections, uint outputPort, uint inputPort);
    ComplexRowVector transmissionTracking(uint outputPort, uint inputPort);
    void setTransmissionTracking(ComplexRowVector corrections, uint outputPort, uint inputPort);

    void operator=(VnaCorrections const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;

    enum CorrectionState {
        APPLIED_CORRECTIONS,
        INTERPOLATED_CORRECTIONS,
        DISABLED_CORRECTIONS,
        NO_CORRECTIONS };
    
    bool isFullyInitialized() const;
    CorrectionState correctionState();
    CorrectionState toCorrectionState(QString scpi);
    ComplexRowVector errorValues(QString term, uint outputPort, uint inputPort);
    void setErrorValues(QString term, ComplexRowVector corrections, uint outputPort, uint inputPort);
    uint bufferSize(uint sfk = 1);
    uint complexBufferSize(uint sfk = 1);
};
}

#endif // VnaCorrections_H
