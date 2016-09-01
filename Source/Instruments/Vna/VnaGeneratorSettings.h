#ifndef VNAGENERATORSETTINGS_H
#define VNAGENERATORSETTINGS_H


// RsaToolbox
#include "VnaArbitraryFrequency.h"

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;

class VnaGeneratorSettings : public QObject
{
    Q_OBJECT
public:
    explicit VnaGeneratorSettings(QObject *parent = 0);
    VnaGeneratorSettings(const VnaGeneratorSettings &other);
    VnaGeneratorSettings(Vna *vna, uint channel, uint index, QObject *parent = 0);
    ~VnaGeneratorSettings();

    bool isPermanentlyOn();
    bool isRfOff();
    void setPermanentlyOn(bool isOn = true);
    void setRfOff(bool isOff = true);

    VnaArbitraryFrequency arbitraryFrequency();
    void setArbitraryFrequency(const VnaArbitraryFrequency &af);

private:
    Vna *_vna;
    uint _channel;
    uint _index;

    QScopedPointer<Vna> _placeholder;

    bool isFullyInitialized() const;
};
} // RsaToolbox

#endif // VNAGENERATORSETTINGS_H
