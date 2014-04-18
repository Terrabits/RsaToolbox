#ifndef VnaTimeDomain_H
#define VnaTimeDomain_H


// RsaToolbox
#include "Definitions.h"


// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaTrace;

enum VnaWindowFunction {
    REGULAR_WINDOW_FUNCTION,
    HAMMING_WINDOW_FUNCTION,
    HANN_WINDOW_FUNCTION,
    BOHMAN_WINDOW_FUNCTION,
    DOLPH_CHEBYCHEV_WINDOW_FUNCTION };

enum RiseTimeDefinition {
    RISETIME_20_TO_80,
    RISETIME_10_TO_90 };

class VnaTimeDomain : public QObject
{
private: Q_OBJECT

public:
    explicit VnaTimeDomain(QObject *parent = 0);
    VnaTimeDomain(const VnaTimeDomain &other);
    VnaTimeDomain(Vna *vna, VnaTrace *trace, QObject *parent = 0);
    VnaTimeDomain(Vna *vna, QString traceName, QObject *parent = 0);

    bool isOn();
    bool isOff();
    void on(bool isOn = true);
    void off(bool isOff = true);

    bool isBandpassImpulseResponse();
    void setBandpassImpulseResponse();
    bool isLowpassImpulseResponse();
    void setLowpassImpulseResponse();
    bool isLowpassStepResponse();
    void setLowpassStepResponse();

    bool isAutomaticDcExtrapolation();
    bool isManualDcExtrapolation();
    void automaticDcExtrapolationOn(bool isOn = true);
    void manualDcExtrapolationOn(bool isOn = true);
    double extrapolatedDcValue();
    void setExtrapolatedDcValue(double dcValue);

    bool isResolutionEnhancementOn();
    bool isResolutionEnhancementOff();
    double resolutionEnhancementFactor();
    void resolutionEnhancementOff();
    void setResolutionEnhancement(double factor);

    bool isWindow(VnaWindowFunction window);
    VnaWindowFunction window();
    void setWindow(VnaWindowFunction window);

    double slowestRiseTime_s(RiseTimeDefinition definition = RISETIME_10_TO_90);
    double fastestRiseTime_s(RiseTimeDefinition definition = RISETIME_10_TO_90);
    double longestRange_s();
    double longestRange_s(double riseTime_s, RiseTimeDefinition definition = RISETIME_10_TO_90);
    double shortestRange_s();
    double shortestRange_s(double riseTime_s, RiseTimeDefinition definition = RISETIME_10_TO_90);

    double unambiguousRange_s();
    double riseTime_s(RiseTimeDefinition definition);

    void setupChannel(double riseTime_s, RiseTimeDefinition definition, double unambiguousRange_s);
    void setupTrace();

    // Harmonic grid
    // Note: all adjustments effect the start frequency
    //       and other channel settings
    // Spacing effects unambiguous range
    // Stop frequency effects rise/fall time
    void adjustChannelFrequencySpacing();
    void adjustChannelStopFrequency();
    void adjustChannelPoints();

    bool isTimeAxis();
    bool isDistanceAxis();

    double startValue();
    void setStart(double value, SiPrefix prefix = NO_PREFIX);
    double stopValue();
    void setStop(double value, SiPrefix prefix = NO_PREFIX);

    void operator=(VnaTimeDomain const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaTrace> _trace;
    QString _traceName;
    
    bool isFullyInitialized() const;

    void setHarmonicGrid(double stopFrequency_Hz, double spacing_Hz);

    // Scpi
    QString filterTypeScpi();
    QString responseTypeScpi();
    QString toScpi(VnaWindowFunction window);
    VnaWindowFunction toWindow(QString scpi);
};
}
Q_DECLARE_METATYPE(RsaToolbox::VnaWindowFunction)
Q_DECLARE_METATYPE(RsaToolbox::RiseTimeDefinition)

#endif // VnaTimeDomain_H
