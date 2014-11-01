

// RsaToolbox includes
#include "General.h"
#include "VnaCalibrate.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaCalibrate
 * \ingroup VnaGroup
 * \brief The \c %VnaCalibrate class
 * is used to perform calibration.
 */

VnaCalibrate::VnaCalibrate(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _isChannelSpecific = false;
    _channelIndex = 0;
}
VnaCalibrate::VnaCalibrate(VnaCalibrate &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _isChannelSpecific = other._isChannelSpecific;
        if (_isChannelSpecific) {
            _channel.reset(new VnaChannel(*other._channel.data()));
            _channelIndex = other._channelIndex;
        }
        else {
            _channelIndex = 0;
        }
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _isChannelSpecific = false;
        _channelIndex = 0;
    }
}
VnaCalibrate::VnaCalibrate(Vna *vna, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _isChannelSpecific = false;
    _channelIndex = 0;
}
VnaCalibrate::VnaCalibrate(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _isChannelSpecific = true;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}
VnaCalibrate::VnaCalibrate(Vna *vna, uint channelIndex, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _isChannelSpecific = true;
    _channel.reset(new VnaChannel(vna, channelIndex));
    _channelIndex = channelIndex;
}

bool VnaCalibrate::isRawDataKept() {
    QString scpi;
    if (_isChannelSpecific) {
       scpi = ":SENS%1:CORR:COLL:RSAV?\n";
       scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:RSAV?\n";
    }

    return(_vna->query(scpi).trimmed() == "1");
}
void VnaCalibrate::setConnector(uint port, Connector connector) {
    QString scpi = ":CORR:COLL:SCON%1 \'%2\',%3\n"; // port, type, gender
    scpi = scpi.arg(port);
    scpi = scpi.arg(toConnectorTypeVnaScpi(connector));
    scpi = scpi.arg(toConnectorGenderVnaScpi(connector));
    _vna->write(scpi);
}
void VnaCalibrate:: setConnectors(Connector connector) {
    QVector<int> ports = range(1, int(_vna->properties().physicalPorts()));
    foreach(int port, ports)
        setConnector(uint(port), connector);
}

Connector VnaCalibrate:: connector(uint port) {
    QString scpi = ":CORR:COLL:SCON%1?\n";
    scpi = scpi.arg(port);

    QStringList results
            = _vna->query(scpi).trimmed().remove("\'").split(",");
    Connector::Type type
            = toConnectorType(results.first());
    ConnectorGender gender
            = toConnectorGender(results.last());

    if (type == Connector::CUSTOM_CONNECTOR)
        return(Connector(results.first(), gender));
    else
        return(Connector(type, gender));
}
QVector<Connector> VnaCalibrate:: connectors() {
    QVector<Connector> result;
    QVector<int> ports
            = range(1, int(_vna->properties().physicalPorts()));
    foreach(int port, ports)
        result << connector(uint(port));
    return(result);
}

void VnaCalibrate:: selectKit(NameLabel nameLabel) {
    Connector type = _vna->calKit(nameLabel).connectorType();
    selectKit(nameLabel, type);
}
void VnaCalibrate:: selectKit(QString name, QString label) {
    selectKit(NameLabel(name, label));
}

NameLabel VnaCalibrate:: selectedKit(Connector type) {
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:CKIT:LSEL? \'%2\'\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:CKIT:LSEL? \'%2\'\n";
    }
    scpi = scpi.arg(toConnectorTypeVnaScpi(type));

    QString result = _vna->query(scpi).trimmed();
    QVector<NameLabel> results
            = NameLabel::parse(result, ",", "\'");
    if (results.isEmpty())
        return(NameLabel(""));
    else
        return(results.first());
}

void VnaCalibrate:: start(QString calibrationName,
                          VnaCalType type,
                          QVector<uint> ports) {
    defineCalibration(calibrationName, type, ports);
    selectChannels();
}
void VnaCalibrate:: keepRawData(bool isKept) {
    QString scpi;
    if (_isChannelSpecific) {
       scpi = ":SENS%1:CORR:COLL:RSAV %2\n";
       scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:RSAV %2\n";
    }

    if (isKept)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);

    _vna->write(scpi);
}
void VnaCalibrate:: measureOpen(uint port) {
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SEL OPEN,%2\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:SEL OPEN,%2\n";
    }
    scpi = scpi.arg(port);
    _vna->write(scpi);
}
void VnaCalibrate:: measureShort(uint port) {
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SEL SHOR,%2\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:SEL SHOR,%2\n";
    }
    scpi = scpi.arg(port);
    _vna->write(scpi);
}
void VnaCalibrate:: measureMatch(uint port) {
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SEL MATC,%2\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:SEL MATC,%2\n";
    }
    scpi = scpi.arg(port);
    _vna->write(scpi);
}
void VnaCalibrate:: measureThru(uint port1, uint port2) {
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SEL THR,%2,%3\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:SEL THR,%2,%3\n";
    }
    scpi = scpi.arg(port1);
    scpi = scpi.arg(port2);
    _vna->write(scpi);
}
void VnaCalibrate:: apply() {
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SAVE:SEL\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:SAVE:SEL\n";
    }
    _vna->write(scpi);
}

void VnaCalibrate::operator=(VnaCalibrate const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _isChannelSpecific = other._isChannelSpecific;
        _channel.reset(new VnaChannel(*other._channel.data()));
        _channelIndex = other._channelIndex;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _isChannelSpecific = false;
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
    }
}

//void VnaCalibrate::moveToThread(QThread *thread) {
//    QObject::moveToThread(thread);
//    if (_channel.isNull() == false)
//        _channel->moveToThread(thread);
//}

// Private
bool VnaCalibrate::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}

void VnaCalibrate::selectKit(NameLabel nameLabel, Connector type) {
    selectKit(nameLabel.name(), nameLabel.label(), toConnectorTypeVnaScpi(type));
}
void VnaCalibrate::selectKit(QString name, QString label, Connector type) {
    selectKit(name, label, toConnectorTypeVnaScpi(type));
}
void VnaCalibrate::selectKit(QString name, QString label, QString customConnector) {
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:CKIT:LSEL \'%2\',\'%3\',\'%4\'\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:CKIT:LSEL \'%2\',\'%3\',\'%4\'\n";
    }
    scpi = scpi.arg(customConnector);
    scpi = scpi.arg(name);
    scpi = scpi.arg(label);
    _vna->write(scpi);
}
void VnaCalibrate::selectKit(QString name, QString label, Connector::Type type) {
    selectKit(name, label, toVnaScpi(type));
}
void VnaCalibrate::defineCalibration(QString calibrationName, VnaCalType type, QVector<uint> ports) {
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:METH:DEF \'%2\',%3,%4\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:METH:DEF \'%2\',%3,%4\n";
    }
    scpi = scpi.arg(calibrationName);
    scpi = scpi.arg(toScpi(type));
    scpi = scpi.arg(toString(ports, ","));
    _vna->write(scpi);
}
void VnaCalibrate::selectChannels() {
    // Zva firmware does not have this feature.
    if (_vna->properties().isZvaFamily() && _isChannelSpecific == false) {
        _vna->print("ZVA firmware can\'t calibrate multiple channels at once.\n\n");
        return;
    }

    if (_isChannelSpecific)
            _vna->write(":CORR:COLL:CHAN:ALL 0\n");
        else
            _vna->write(":CORR:COLL:CHAN:ALL 1\n");
}

QString RsaToolbox::toScpi(VnaCalType type) {
    switch(type) {
        case OSM_CAL_TYPE:  return("FOP");
        case TOSM_CAL_TYPE: return("TOSM");
        case UOSM_CAL_TYPE: return("UOSM");
        default: return("UNKNOWN_VNA_CAL_TYPE");
        }
}
VnaCalType RsaToolbox::toVnaCalType(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "FOP")
        return(OSM_CAL_TYPE);
    if (scpi == "UOSM")
        return(UOSM_CAL_TYPE);
    if (scpi == "TOSM")
        return(TOSM_CAL_TYPE);
    // else (default)
    return(TOSM_CAL_TYPE);
}
