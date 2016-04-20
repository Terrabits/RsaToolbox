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



class VnaTimeDomain : public QObject
{
    Q_OBJECT

public:

    enum /*class*/ Window {
        Regular,
        Hamming,
        Hann,
        Bohman,
        DolphChebychev
    };
    enum /*class*/ RiseTime {
        TwentyToEighty,
        TenToNinety
    };

    explicit VnaTimeDomain(QObject *parent = 0);
    VnaTimeDomain(const VnaTimeDomain &other);
    VnaTimeDomain(Vna *vna, VnaTrace *trace, QObject *parent = 0);
    VnaTimeDomain(Vna *vna, QString traceName, QObject *parent = 0);
    ~VnaTimeDomain();

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

    bool isWindow(Window window);
    Window window();
    void setWindow(Window window);

    double slowestRiseTime_s(VnaTimeDomain::RiseTime definition = VnaTimeDomain::RiseTime::TenToNinety);
    double fastestRiseTime_s(VnaTimeDomain::RiseTime definition = VnaTimeDomain::RiseTime::TenToNinety);
    double longestRange_s();
    double longestRange_s(double riseTime_s, VnaTimeDomain::RiseTime definition = VnaTimeDomain::RiseTime::TenToNinety);
    double shortestRange_s();
    double shortestRange_s(double riseTime_s, VnaTimeDomain::RiseTime definition = VnaTimeDomain::RiseTime::TenToNinety);

    double unambiguousRange_s();
    double riseTime_s(VnaTimeDomain::RiseTime definition);

    void setupChannel(double riseTime_s, VnaTimeDomain::RiseTime definition, double unambiguousRange_s);
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
    void setStart(double value, SiPrefix prefix = SiPrefix::None);
    double stopValue();
    void setStop(double value, SiPrefix prefix = SiPrefix::None);

    void operator=(VnaTimeDomain const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaTrace> _trace;
    QString _traceName;
    
    bool isFullyInitialized() const;

    void setHarmonicGrid(double stopFrequency_Hz, double spacing_Hz);

    // Queries
    QString filterTypeScpi();
    QString responseTypeScpi();
};
} // RsaToolbox


Q_DECLARE_METATYPE(RsaToolbox::VnaTimeDomain::Window)
Q_DECLARE_METATYPE(RsaToolbox::VnaTimeDomain::RiseTime)

#endif // VnaTimeDomain_H
