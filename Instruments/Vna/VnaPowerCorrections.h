#ifndef VnaPowerCorrections_H
#define VnaPowerCorrections_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaPowerCorrections : QObject
{
    Q_OBJECT

public:
    explicit VnaPowerCorrections(QObject *parent = 0);
    VnaPowerCorrections(VnaPowerCorrections &other);
    VnaPowerCorrections(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaPowerCorrections(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaPowerCorrections();

    bool isOn(uint port);
    bool isOff(uint port);
    bool isPresent(uint port);
    bool isNotPresent(uint port);
    bool isInterpolated(uint port);
    bool isNotInterpolated(uint port);
    void on(uint port, bool isOn = true);
    void off(uint port, bool isOff = true);
    QString calGroup();
    void setCalGroup(QString calGroup);
    void saveToCalGroup(QString calGroup);
    void dissolveCalGroupLink();
    void clear(); //?

    void operator=(VnaPowerCorrections const &other);

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
    CorrectionState correctionState(uint port);
    CorrectionState toCorrectionState(QString scpi);
};
}

#endif // VnaPowerCorrections_H
