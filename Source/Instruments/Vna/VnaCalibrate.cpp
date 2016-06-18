#include "VnaCalibrate.h"


// RsaToolbox includes
#include "General.h"
#include "Vna.h"
#include "VnaChannel.h"
#include "VnaScpi.h"
using namespace RsaToolbox;

// Qt includes
#include <QDebug>
#include <QElapsedTimer>


/*!
 * \class RsaToolbox::VnaCalibrate
 * \ingroup VnaGroup
 * \brief The \c %VnaCalibrate class
 * is used to perform calibration.
 */

// Static init:
uint VnaCalibrate::_timeout_ms = 10 * 60 * 1000; // 10 min

VnaCalibrate::VnaCalibrate(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _isChannelSpecific = false;
    _channelIndex = 0;
}
VnaCalibrate::VnaCalibrate(const VnaCalibrate &other)
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
    _timeout_ms = 10 * 60 * 1000; // 10 mins
}
VnaCalibrate::~VnaCalibrate() {

}

bool VnaCalibrate::isRawDataKept() {
    if (isMissingZvaCommand())
        return false;

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
    if (isMissingZvaCommand())
            return;

    selectChannels();

    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SCON%2 \'%3\',%4\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:SCON%2 \'%3\',%4\n";
    }
    scpi = scpi.arg(port);
    scpi = scpi.arg(VnaScpi::toTypeString(connector));
    scpi = scpi.arg(VnaScpi::toGenderString(connector));
    _vna->write(scpi);
}
void VnaCalibrate:: setConnectors(Connector connector) {
    QVector<int> ports = range(1, int(_vna->properties().physicalPorts()));
    foreach(int port, ports)
        setConnector(uint(port), connector);
}

Connector VnaCalibrate:: connector(uint port) {
    if (isMissingZvaCommand())
                return Connector();

    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SCON%2?\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:SCON%2?\n";
    }
    scpi = scpi.arg(port);

    QStringList results
            = _vna->query(scpi).trimmed().remove("\'").split(",");

    if (results.size() != 2)
        return Connector();
    Connector::Type type
            = VnaScpi::toConnectorType(results.first());
    Connector::Gender gender
            = VnaScpi::toConnectorGender(results.last());

    if (type == Connector::CUSTOM_CONNECTOR)
        return Connector(results.first(), gender);
    else
        return Connector(type, gender);
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
    // This is not channel specific. Period.
    // But it might get updated...

    if (isMissingZvaCommand())
        return NameLabel();

    // ...This currently does not work per channel,
    // but I'm adding it anyway...
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:CKIT:LSEL? \'%2\'\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:CKIT:LSEL? \'%2\'\n";
    }
    scpi = scpi.arg(VnaScpi::toTypeString(type));

    QString result = _vna->query(scpi).trimmed();
    QVector<NameLabel> results
            = NameLabel::parse(result, ",", "\'");
    if (results.isEmpty())
        return(NameLabel(""));
    else
        return(results.first());
}

void VnaCalibrate::start(QString calibrationName,
                          CalType type,
                          QVector<uint> ports)
{
    if (_vna->properties().isZvaFamily() && !VnaScpi::isZvaFamilyCompatible(type)) {
        QString msg = "Error: Calibration type \'%1\' not available on ZVA-family instrument\n\n";
        msg = msg.arg(VnaScpi::toString(type));
        _vna->print(msg);
        // return; // ?
    }
    else if (_vna->properties().isZnbFamily() && !VnaScpi::isZnbFamilyCompatible(type)) {
        QString msg = "Error: Calibration type \'%1\' not available on ZNB-family instrument\n\n";
        msg = msg.arg(VnaScpi::toString(type));
        _vna->print(msg);
        // return; // ?
    }

    // Note: Cannot ask for sweep type (and therefore sweep time)
    // during calibration!
    if (_isChannelSpecific)
        _timeout_ms = _channel->totalSweepTime_ms();
    else
        _timeout_ms = _vna->calibrationSweepTime_ms();

    selectChannels();
    defineCalibration(calibrationName, type, ports);
}
void VnaCalibrate:: keepRawData(bool isKept) {
    if (isMissingZvaCommand())
        return;

    selectChannels();

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
    if (isMissingZvaCommand())
        return;

//    uint timeout_ms;
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SEL OPEN,%2\n";
        scpi = scpi.arg(_channelIndex);
//        timeout_ms = _channel->calibrationSweepTime_ms();
    }
    else {
        scpi = ":CORR:COLL:SEL OPEN,%2\n";
//        timeout_ms = _vna->calibrationSweepTime_ms();
    }
    scpi = scpi.arg(port);
    _vna->write(scpi);

    // Note: Cannot ask for sweep type (and therefore sweep time)
    // during calibration!
    _vna->pause(_timeout_ms * 2 + 5000 /*timeout_ms * 2 + 5000*/);
}
void VnaCalibrate:: measureShort(uint port) {
    if (isMissingZvaCommand())
        return;

//    uint timeout_ms;
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SEL SHOR,%2\n";
        scpi = scpi.arg(_channelIndex);
//        timeout_ms = _channel->calibrationSweepTime_ms();
    }
    else {
        scpi = ":CORR:COLL:SEL SHOR,%2\n";
//        timeout_ms = _vna->calibrationSweepTime_ms();
    }
    scpi = scpi.arg(port);
    _vna->write(scpi);

    // Note: Cannot ask for sweep type (and therefore sweep time)
    // during calibration!
    _vna->pause(_timeout_ms * 2 + 5000 /*timeout_ms * 2 + 5000*/);
}
void VnaCalibrate:: measureMatch(uint port) {
    if (isMissingZvaCommand())
        return;

//    uint timeout_ms;
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SEL MATC,%2\n";
        scpi = scpi.arg(_channelIndex);
//        timeout_ms = _channel->calibrationSweepTime_ms();
    }
    else {
        scpi = ":CORR:COLL:SEL MATC,%2\n";
//        timeout_ms = _vna->calibrationSweepTime_ms();
    }
    scpi = scpi.arg(port);
    _vna->write(scpi);

    // Note: Cannot ask for sweep type (and therefore sweep time)
    // during calibration!
    _vna->pause(_timeout_ms * 2 + 5000 /*timeout_ms * 2 + 5000*/);
}

void VnaCalibrate::measureOffsetShort1(uint port) {
    if (isMissingZvaCommand())
        return;

//    uint timeout_ms;
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SEL OSHORT1,%2\n";
        scpi = scpi.arg(_channelIndex);
//        timeout_ms = _channel->calibrationSweepTime_ms();
    }
    else {
        scpi = ":CORR:COLL:SEL OSHORT1,%2\n";
//        timeout_ms = _vna->calibrationSweepTime_ms();
    }
    scpi = scpi.arg(port);
    _vna->write(scpi);

    // Note: Cannot ask for sweep type (and therefore sweep time)
    // during calibration!
    _vna->pause(_timeout_ms * 2 + 5000 /*timeout_ms * 2 + 5000*/);
}
void VnaCalibrate::measureOffsetShort2(uint port) {
    if (isMissingZvaCommand())
        return;

//    uint timeout_ms;
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SEL OSHORT2,%2\n";
        scpi = scpi.arg(_channelIndex);
//        timeout_ms = _channel->calibrationSweepTime_ms();
    }
    else {
        scpi = ":CORR:COLL:SEL OSHORT2,%2\n";
//        timeout_ms = _vna->calibrationSweepTime_ms();
    }
    scpi = scpi.arg(port);
    _vna->write(scpi);

    // Note: Cannot ask for sweep type (and therefore sweep time)
    // during calibration!
    _vna->pause(_timeout_ms * 2 + 5000 /*timeout_ms * 2 + 5000*/);
}
void VnaCalibrate::measureOffsetShort3(uint port) {
    if (isMissingZvaCommand())
        return;

//    uint timeout_ms;
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SEL OSHORT3,%2\n";
        scpi = scpi.arg(_channelIndex);
//        timeout_ms = _channel->calibrationSweepTime_ms();
    }
    else {
        scpi = ":CORR:COLL:SEL OSHORT3,%2\n";
//        timeout_ms = _vna->calibrationSweepTime_ms();
    }
    scpi = scpi.arg(port);
    _vna->write(scpi);

    // Note: Cannot ask for sweep type (and therefore sweep time)
    // during calibration!
    _vna->pause(_timeout_ms * 2 + 5000 /*timeout_ms * 2 + 5000*/);
}

void VnaCalibrate:: measureThru(uint port1, uint port2) {
    if (isMissingZvaCommand())
        return;

//    uint timeout_ms;
    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SEL THR,%2,%3\n";
        scpi = scpi.arg(_channelIndex);
//        timeout_ms = _channel->calibrationSweepTime_ms();
    }
    else {
        scpi = ":CORR:COLL:SEL THR,%2,%3\n";
//        timeout_ms = _vna->calibrationSweepTime_ms();
    }
    scpi = scpi.arg(port1);
    scpi = scpi.arg(port2);
    _vna->write(scpi);

    // Note: Cannot ask for sweep type (and therefore sweep time)
    // during calibration!
    _vna->pause(_timeout_ms * 2 + 5000 /*timeout_ms * 2 + 5000*/);
}
void VnaCalibrate:: apply() {
    if (isMissingZvaCommand())
        return;

    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:SAVE:SEL\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:SAVE:SEL\n";
    }
    _vna->write(scpi);
    _vna->pause(6000);
}

void VnaCalibrate::operator=(const VnaCalibrate &other) {
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


// Private
bool VnaCalibrate::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
bool VnaCalibrate::isMissingZvaCommand() {
    if (_vna->properties().isZvaFamily() && !_isChannelSpecific) {
        _vna->print("ZVA firmware does not support calibrating all channels at once.\n\n");
        return true;
    }

    return false;
}

void VnaCalibrate::selectKit(NameLabel nameLabel, Connector type) {
    selectKit(nameLabel.name(), nameLabel.label(), VnaScpi::toTypeString(type));
}
void VnaCalibrate::selectKit(QString name, QString label, Connector type) {
    selectKit(name, label, VnaScpi::toTypeString(type));
}
void VnaCalibrate::selectKit(QString name, QString label, QString customConnector) {
    if (isMissingZvaCommand())
        return;

    selectChannels();

    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:CKIT:LSEL \'%2\',\'%3\',\'%4\'\n";
        scpi = scpi.arg(_channelIndex);
        scpi = scpi.arg(customConnector);
        scpi = scpi.arg(name);
        scpi = scpi.arg(label);
    }
    else {
        scpi = ":CORR:CKIT:LSEL \'%2\',\'%3\',\'%4\'\n";
        scpi = scpi.arg(customConnector);
        scpi = scpi.arg(name);
        scpi = scpi.arg(label);
    }
    _vna->write(scpi);
}
void VnaCalibrate::selectKit(QString name, QString label, Connector::Type type) {
    selectKit(name, label, VnaScpi::toString(type));
}
void VnaCalibrate::defineCalibration(QString calibrationName, CalType type, QVector<uint> ports) {
    if (isMissingZvaCommand())
        return;

    QString scpi;
    if (_isChannelSpecific) {
        scpi = ":SENS%1:CORR:COLL:METH:DEF \'%2\',%3,%4\n";
        scpi = scpi.arg(_channelIndex);
    }
    else {
        scpi = ":CORR:COLL:METH:DEF \'%2\',%3,%4\n";
    }
    scpi = scpi.arg(calibrationName);
    scpi = scpi.arg(VnaScpi::toString(type));
    scpi = scpi.arg(toString(ports, ","));
    _vna->write(scpi);
}
void VnaCalibrate::selectChannels() {
    // ZVA does not have this capability
    if (_vna->properties().isZvaFamily())
        return;

    if (_isChannelSpecific)
        _vna->write(":CORR:COLL:CHAN:ALL 0\n");
    else
        _vna->write(":CORR:COLL:CHAN:ALL 1\n");
}
