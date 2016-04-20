#ifndef VnaPowerCalibrate_H
#define VnaPowerCalibrate_H


// RsaToolbox
#include "Definitions.h"
#include "NameLabel.h"
#include "Connector.h"

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaChannel;


class VnaPowerCalibrate : QObject
{
    Q_OBJECT

public:
    explicit VnaPowerCalibrate(QObject *parent = 0);
    VnaPowerCalibrate(VnaPowerCalibrate &other);
    VnaPowerCalibrate(Vna *vna, QObject *parent = 0);
    VnaPowerCalibrate(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaPowerCalibrate(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaPowerCalibrate();

    bool isRawDataKept();

    void setConnector(uint port, Connector connector);
    void setConnectors(Connector connector);

    Connector connector(uint port);
    QVector<Connector> connectors();

    void start(QString calibrationName, uint port);
    void keepRawData(bool isKept = true);
    void apply();

    void operator=(VnaPowerCalibrate const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    bool _isChannelSpecific;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;

    void selectChannels();
};
}


#endif // VnaPowerCalibrate_H
