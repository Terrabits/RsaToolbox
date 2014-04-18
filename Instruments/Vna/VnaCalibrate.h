#ifndef VnaCalibrate_H
#define VnaCalibrate_H


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

enum VnaCalType {
    OSM_CAL_TYPE,
    TOSM_CAL_TYPE,
    UOSM_CAL_TYPE };

class VnaCalibrate : public QObject
{
private: Q_OBJECT

public:
    explicit VnaCalibrate(QObject *parent = 0);
    VnaCalibrate(VnaCalibrate &other);
    VnaCalibrate(Vna *vna, QObject *parent = 0);
    VnaCalibrate(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaCalibrate(Vna *vna, uint channelIndex, QObject *parent = 0);

    bool isRawDataKept();

    void setConnector(uint port, Connector connector);
    void setConnectors(Connector connector);

    Connector connector(uint port);
    QVector<Connector> connectors();

    void selectKit(NameLabel nameLabel);
    void selectKit(QString name, QString label = "");

    NameLabel selectedKit(Connector type);

    void start(QString calibrationName, VnaCalType type, QVector<uint> ports);
    void keepRawData(bool isKept = true);
    void measureOpen(uint port);
    void measureShort(uint port);
    void measureMatch(uint port);
    void measureThru(uint port1, uint port2);
    void apply();

    void operator=(VnaCalibrate const &other);

//    void moveToThread(QThread *thread);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    bool _isChannelSpecific;
    QScopedPointer<VnaChannel> _channel;
    uint _channelIndex;
    
    bool isFullyInitialized() const;

    void selectKit(NameLabel nameLabel, Connector type);
    void selectKit(QString name, QString label, Connector type);
    void selectKit(QString name, QString label, QString customConnector);
    void selectKit(QString name, QString label, ConnectorType type);

    void defineCalibration(QString calibrationName, VnaCalType type, QVector<uint> ports);
    void selectChannels();
};

QString toScpi(VnaCalType type);
VnaCalType toVnaCalType(QString scpi);
}
Q_DECLARE_METATYPE(RsaToolbox::VnaCalType)


#endif // VnaCalibrate_H
