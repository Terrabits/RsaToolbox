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

//    bool isOn(uint port);
//    bool isPresent(uint port);
//    bool isInterpolated(uint port);
//    void on(uint port, bool isOn = true);
//    void off(uint port, bool isOff = true);
    QRowVector corrections_dB(QChar wave, uint port);
    void setCorrections(QChar wave, uint port, QRowVector corrections_dB);
//    void clear(); // How?

    QString calGroup();
    void setCalGroup(QString calGroup);
    void saveToCalGroup(QString calGroup);
    void dissolveCalGroupLink();

    void operator=(VnaPowerCorrections const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;
};
}

#endif // VnaPowerCorrections_H
