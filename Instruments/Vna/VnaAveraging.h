#ifndef VnaAveraging_H
#define VnaAveraging_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaAveraging : QObject
{
    Q_OBJECT

public:
    explicit VnaAveraging(QObject *parent = 0);
    VnaAveraging(const VnaAveraging &other);
    VnaAveraging(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaAveraging(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaAveraging();

    // Methods
    bool isOn();
    bool isOff();
    void on(bool isOn = true);
    void off(bool isOff = true);
    void reset();
    void setNumber(uint numberOfAverages);
    uint number();



    void operator=(VnaAveraging const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaAveraging_H
