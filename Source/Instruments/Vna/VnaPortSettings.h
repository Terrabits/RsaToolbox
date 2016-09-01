#ifndef VNAPORTSETTINGS_H
#define VNAPORTSETTINGS_H


// RsaToolbox
#include "Vna.h"


// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {

class VnaPortSettings
{
    Q_OBJECT

public:
    explicit VnaPortSettings(QObject *parent = 0);
    VnaPortSettings(const VnaPortSettings &other);
    VnaPortSettings(Vna *vna, uint channel, uint port, QObject *parent = 0);
    ~VnaPortSettings();

    // Rf power
    bool isGenerator();
    void setGenerator(bool isGen = true);
    bool isRfOff();
    void rfOff(bool isOff = true);

    // Source frequency
    bool isArbitrarySourceFrequencyOn();
    VnaArbitraryFrequency arbitrarySourceFrequency();
    void setArbitrarySourceFrequency(VnaArbitraryFrequency af);
    void arbitrarySourceFrequencyOff();

private:
    Vna *_vna;
    uint _channel;
    uint _port;

    QScopedPointer<Vna> _placeholder;

    bool isFullyInitialized() const;
};
} // RsaToolbox

#endif // VNAPORTSETTINGS_H
