#ifndef VNAUSERCONTROL_H
#define VNAUSERCONTROL_H

#include "vnabusysignal.h"

#include <QObject>
#include <QScopedPointer>

namespace RsaToolbox {
class Vna;
class VnaChannel;

class VnaUserControl : public QObject
{
    Q_OBJECT

public:
    explicit VnaUserControl(QObject *parent=0);
    VnaUserControl(Vna *vna, VnaChannel *channel, QObject *parent=0);
    ~VnaUserControl();

    VnaBusySignal busySignal();
    void setBusySignal(VnaBusySignal signal);

private:
    QScopedPointer<Vna> _placeholder;

    Vna *_vna;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;

    bool isFullyInitialized() const;
};
}


#endif // VNAUSERCONTROL_H
