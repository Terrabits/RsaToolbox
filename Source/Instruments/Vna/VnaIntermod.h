#ifndef VnaIntermod_H
#define VnaIntermod_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <Qt> // uint
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaIntermod : QObject
{
private: Q_OBJECT

public:

    class ToneSource {
    public:
        ToneSource();
        ~ToneSource();

        enum /*class*/ Type {
            Port,
            Generator,
            None
        };

        bool isUndefined() const;
        Type type() const;

        bool isPort() const;
        uint port() const;
        void setPort(uint port);

        bool isGenerator() const;
        uint generator() const;
        void setGenerator(uint index);

        void clear();

    private:
        Type _type;
        uint _port;
        uint _generator;
    };

    explicit VnaIntermod(QObject *parent = 0);
    VnaIntermod(const VnaIntermod &other);
    VnaIntermod(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaIntermod(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaIntermod();

    // Methods
    double toneDistance_Hz();
    void setToneDistance(double distance_Hz, SiPrefix prefix = SiPrefix::None);

    uint lowerTonePort();
    void setLowerTonePort(uint port);

    ToneSource upperToneSource();
    void setUpperToneSource(ToneSource source);

    uint receivingPort();
    void setReceivingPort(uint port);

    void order3On(bool on = true);
    void order5On(bool on = true);
    void order7On(bool on = true);
    void order9On(bool on = true);
    void orderOn(uint n, bool on = true);

    void operator=(VnaIntermod const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;
    
};
}

bool operator!=(const RsaToolbox::VnaIntermod::ToneSource &lsrc, const RsaToolbox::VnaIntermod::ToneSource &rsrc);
bool operator==(const RsaToolbox::VnaIntermod::ToneSource &lsrc, const RsaToolbox::VnaIntermod::ToneSource &rsrc);

#endif // VnaIntermod_H
