#include "vnausercontrol.h"

#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

#include <QString>

VnaUserControl::VnaUserControl(QObject *parent) :
    QObject(parent),
    _placeholder(new Vna()),
    _vna(_placeholder.data()),
    _channel(new VnaChannel()),
    _channelIndex(0)
{
    //
}

VnaUserControl::VnaUserControl(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent),
    _vna(vna),
    _channel(new VnaChannel(*channel)),
    _channelIndex(_channel->index())
{
    //
}

// Busy signal
VnaBusySignal VnaUserControl::busySignal() {
    QString scpi = ":OUTP%1:UPOR:BUSY:LINK?\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = _vna->query(scpi).trimmed();
    return vnaBusySignalFromScpi(scpi);
}
void VnaUserControl::setBusySignal(VnaBusySignal signal) {
    QString scpi = ":OUTP%1:UPOR:BUSY:LINK %2\n";
    scpi         = scpi.arg(_channelIndex);
    scpi         = scpi.arg(toScpi(signal));
    _vna->write(scpi);
}

bool VnaUserControl::isFullyInitialized() const {
    return _vna && _vna != _placeholder.data();
}
