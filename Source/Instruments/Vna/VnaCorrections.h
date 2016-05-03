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

    // Clear corrections
    // (How?)
    // void clear();

    // Properties
    VnaCalibrate::CalType calibrationType();
    bool isFull12TermErrorCorrection();
    bool isSMARTerCal();
    VnaChannel::SweepType sweepType();
    QVector<uint> ports();
    uint points();
    double startFrequency_Hz();
    double stopFrequency_Hz();
    QRowVector frequencies_Hz();
    double power_dBm();

    // Physical setup
    // Place under VnaCalHardware interface?
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
    void loadDefaultCorrections();

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
    ComplexRowVector directivity(uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);
    ComplexRowVector sourceMatch(uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);
    ComplexRowVector reflectionTracking(uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);
    ComplexRowVector loadMatch(uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);
    ComplexRowVector transmissionTracking(uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);

    void setDirectivity(ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);
    void setSourceMatch(ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);
    void setReflectionTracking(ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);
    void setLoadMatch(ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);
    void setTransmissionTracking(ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);


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
    ComplexRowVector errorValues(QString term, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);
    void setErrorValues(QString term, ComplexRowVector corrections, uint outputPort, uint inputPort);
    void setErrorValues(QString term, ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort);
    uint bufferSize();
    uint complexBufferSize();
};
} // RsaToolbox


#endif // VnaCorrections_H
