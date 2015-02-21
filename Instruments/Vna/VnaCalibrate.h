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

class VnaCalibrate : public QObject
{
    Q_OBJECT

public:

    enum CalType {
        Osm,
        Tosm,
        Uosm
    };

    explicit VnaCalibrate(QObject *parent = 0);
    VnaCalibrate(VnaCalibrate &other);
    VnaCalibrate(Vna *vna, QObject *parent = 0);
    VnaCalibrate(Vna *vna, VnaChannel *channel, QObject *parent = 0);
    VnaCalibrate(Vna *vna, uint channelIndex, QObject *parent = 0);
    ~VnaCalibrate();

    bool isRawDataKept();
    void keepRawData(bool isKept = true);

    Connector connector(uint port);
    QVector<Connector> connectors();
    void setConnector(uint port, Connector connector);
    void setConnectors(Connector connector);

    void selectKit(NameLabel nameLabel);
    void selectKit(QString name, QString label = "");

    NameLabel selectedKit(Connector type);



    void start(QString calibrationName, CalType type, QVector<uint> ports);
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
    uint _timeout_ms;
    
    bool isFullyInitialized() const;
    bool isMissingZvaCommand();

    void selectKit(NameLabel nameLabel, Connector type);
    void selectKit(QString name, QString label, Connector type);
    void selectKit(QString name, QString label, QString customConnector);
    void selectKit(QString name, QString label, Connector::Type type);

    void defineCalibration(QString calibrationName, CalType type, QVector<uint> ports);
    void selectChannels();
};
} // RsaToolbox

Q_DECLARE_METATYPE(RsaToolbox::VnaCalibrate::CalType)


#endif // VnaCalibrate_H
