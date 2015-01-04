#ifndef VnaCorrections_H
#define VnaCorrections_H


// RsaToolbox
#include "Definitions.h"
#include "VnaChannel.h"
//#include "VnaCalibrate.h"

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
//class VnaChannel;

class VnaCorrections : public QObject
{
    Q_OBJECT

public:
    explicit VnaCorrections(QObject *parent = 0);
    VnaCorrections(VnaCorrections &other);
    VnaCorrections(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaCorrections(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaCorrections();

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

    // Properties
    VnaCalibrate::CalType calibrationType();
    VnaChannel::SweepType sweepType();
    QVector<uint> testPorts();
    uint points();
    double startFrequency_Hz();
    double stopFrequency_Hz();
    double power_dBm();

    // Physical setup
    bool isVnaPort(uint testPort);
    uint vnaPort(uint testPort);
    PortMap testPortToVnaMap();

    bool areSwitchMatrices();
    uint switchMatrices();
    bool isSwitchMatrixPort(uint testPort);
    uint switchMatrix(uint testPort);
    PortMap switchMatrixToVnaPortMap(uint switchMatrix);
    PortMap testPortToSwitchMatrixMap(uint switchMatrix);

    // Corrections:
    // Vna ports
    ComplexRowVector directivity(uint outputPort, uint inputPort);
    ComplexRowVector sourceMatch(uint outputPort, uint inputPort);
    ComplexRowVector reflectionTracking(uint outputPort, uint inputPort);
    ComplexRowVector loadMatch(uint outputPort, uint inputPort);
    ComplexRowVector transmissionTracking(uint outputPort, uint inputPort);

    void setDirectivity(ComplexRowVector corrections, uint outputPort, uint inputPort);
    void setSourceMatch(ComplexRowVector corrections, uint outputPort, uint inputPort);
    void setReflectionTracking(ComplexRowVector corrections, uint outputPort, uint inputPort);
    void setLoadMatch(ComplexRowVector corrections, uint outputPort, uint inputPort);
    void setTransmissionTracking(ComplexRowVector corrections, uint outputPort, uint inputPort);

    // Corrections:
    // Switch matrix paths
    ComplexRowVector directivity(uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);
    ComplexRowVector sourceMatch(uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);
    ComplexRowVector reflectionTracking(uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);
    ComplexRowVector loadMatch(uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);
    ComplexRowVector transmissionTracking(uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);

    void setDirectivity(ComplexRowVector corrections, uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);
    void setSourceMatch(ComplexRowVector corrections, uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);
    void setReflectionTracking(ComplexRowVector corrections, uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);
    void setLoadMatch(ComplexRowVector corrections, uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);
    void setTransmissionTracking(ComplexRowVector corrections, uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);


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
        NO_CORRECTIONS
    };
    
    bool isFullyInitialized() const;
    CorrectionState correctionState();
    CorrectionState toCorrectionState(QString scpi);
    ComplexRowVector errorValues(QString term, uint outputPort, uint inputPort);
    ComplexRowVector errorValues(QString term, uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);
    void setErrorValues(QString term, ComplexRowVector corrections, uint outputPort, uint inputPort);
    void setErrorValues(QString term, ComplexRowVector corrections, uint outputTestPort, uint vnaGeneratorPort, uint inputTestPort, uint vnaReceiverPort);
    uint bufferSize(uint sfk = 1);
    uint complexBufferSize(uint sfk = 1);
};
} // RsaToolbox


#endif // VnaCorrections_H
