

// RsaToolbox includes
#include "VnaCalKit.h"
#include "Vna.h"
#include "VnaScpi.h"
using namespace RsaToolbox;

// Qt
#include <QDebug>

/*!
 * \class RsaToolbox::VnaCalKit
 * \ingroup VnaGroup
 * \brief The \c %VnaCalKit class
 * manipulates a calibration
 * kit.
 */

VnaCalKit::VnaCalKit(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _nameLabel = NameLabel();
}

VnaCalKit::VnaCalKit(const VnaCalKit &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _nameLabel = other._nameLabel;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _nameLabel = NameLabel();
    }
}

VnaCalKit::VnaCalKit(Vna *vna, NameLabel nameLabel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _nameLabel = nameLabel;
}
VnaCalKit::~VnaCalKit() {

}

NameLabel VnaCalKit::nameLabel() const {
    return _nameLabel;
}

bool VnaCalKit::isConnectorType(Connector type) {
    return _vna->calKits(type).contains(_nameLabel);
}
bool VnaCalKit::isAgilentModel() {
    QString scpi = ":CORR:CKIT:DMOD? \'%1\',\'%2\',\'%3\'\n";
    scpi = scpi.arg(VnaScpi::toTypeString(connectorType()));
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(_nameLabel.label());
    return _vna->query(scpi).trimmed() == "DEL";
}

bool VnaCalKit::has(VnaCalStandard standard) {
    if (standard.isSinglePort()) {
        if (standard.isPortSpecific())
            return has(standard.type(), standard.port());
        else
            return has(standard.type(), standard.gender());
    }
    else {
        if (standard.isPortSpecific())
            return has(standard.type(), standard.port1(), standard.port2());
        else
            return has(standard.type(), standard.gender1(), standard.gender2());
    }
}
bool VnaCalKit::has(VnaCalStandard::Type type, Connector::Gender gender) {
    if (!VnaCalStandard::isSinglePort(type))
        return false;

    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.type() == type && s.gender() == gender)
            return true;
    }

    return false;
}
bool VnaCalKit::has(VnaCalStandard::Type type, uint port) {
    if (!VnaCalStandard::isSinglePort(type))
        return false;

    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.type() == type && s.port() == port)
            return true;
    }

    return false;
}
bool VnaCalKit::has(VnaCalStandard::Type type, Connector::Gender gender1, Connector::Gender gender2) {
    if (!VnaCalStandard::isTwoPort(type))
        return false;

    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.type() == type) {
            if (s.gender1() == gender1 && s.gender2() == gender2)
                return true;
            if (s.gender1() == gender2 && s.gender2() == gender1)
                return true;
        }
    }

    return false;
}
bool VnaCalKit::has(VnaCalStandard::Type type, uint port1, uint port2) {
    if (!VnaCalStandard::isTwoPort(type))
        return false;

    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.type() == type) {
            if (s.port1() == port1 && s.port2() == port2)
                return true;
            if (s.port() == port2 && s.port2() == port1)
                return true;
        }
    }

    return false;
}

bool VnaCalKit::hasOpen() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isOpen())
            return true;
    }

    return false;
}
bool VnaCalKit::hasOpen(uint port) {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isOpen() && s.port() == port)
            return true;
    }

    return false;
}
bool VnaCalKit::hasMaleOpen() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isMaleOpen())
            return true;
    }

    return false;
}
bool VnaCalKit::hasFemaleOpen() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isFemaleOpen())
            return true;
    }

    return false;
}

bool VnaCalKit::hasShort() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isShort())
            return true;
    }

    return false;
}
bool VnaCalKit::hasShort(uint port) {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isShort() && s.port() == port)
            return true;
    }

    return false;
}
bool VnaCalKit::hasMaleShort() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isMaleShort())
            return true;
    }

    return false;
}
bool VnaCalKit::hasFemaleShort() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isFemaleShort())
            return true;
    }

    return false;
}

bool VnaCalKit::hasOffsetShort1() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isOffsetShort1())
            return true;
    }

    return false;
}
bool VnaCalKit::hasMaleOffsetShort1() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isMaleOffsetShort1())
            return true;
    }

    return false;
}
bool VnaCalKit::hasFemaleOffsetShort1() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isFemaleOffsetShort1())
            return true;
    }

    return false;
}

bool VnaCalKit::hasOffsetShort2() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isOffsetShort2())
            return true;
    }

    return false;
}
bool VnaCalKit::hasMaleOffsetShort2() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isMaleOffsetShort2())
            return true;
    }

    return false;
}
bool VnaCalKit::hasFemaleOffsetShort2() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isFemaleOffsetShort2())
            return true;
    }

    return false;
}

bool VnaCalKit::hasOffsetShort3() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isOffsetShort3())
            return true;
    }

    return false;
}
bool VnaCalKit::hasMaleOffsetShort3() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isMaleOffsetShort3())
            return true;
    }

    return false;
}
bool VnaCalKit::hasFemaleOffsetShort3() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isFemaleOffsetShort3())
            return true;
    }

    return false;
}

bool VnaCalKit::hasMatch() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isMatch())
            return true;
    }

    return false;
}
bool VnaCalKit::hasMatch(uint port) {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isMatch() && s.port() == port)
            return true;
    }

    return false;
}
bool VnaCalKit::hasMaleMatch() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isMaleMatch())
            return true;
    }

    return false;
}
bool VnaCalKit::hasFemaleMatch() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isFemaleMatch())
            return true;
    }

    return false;
}

bool VnaCalKit::hasThru() {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isThru())
            return true;
    }

    return false;
}
bool VnaCalKit::hasThru(uint port1, uint port2) {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isThru(port1, port2))
            return true;
    }

    return false;
}
bool VnaCalKit::hasThru(Connector::Gender gender1, Connector::Gender gender2) {
    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.isThru(gender1, gender2))
            return true;
    }

    return false;
}

void VnaCalKit::useAgilentModel() {
    QString scpi = ":CORR:CKIT:DMOD \'%1\',\'%2\',\'%3\',DEL\n";
    scpi = scpi.arg(VnaScpi::toTypeString(connectorType()));
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(_nameLabel.label());
    _vna->write(scpi);
}
void VnaCalKit::useRohdeModel() {
    QString scpi = ":CORR:CKIT:DMOD \'%1\',\'%2\',\'%3\',ELEN\n";
    scpi = scpi.arg(VnaScpi::toTypeString(connectorType()));
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(_nameLabel.label());
    _vna->write(scpi);
}

Connector VnaCalKit::connectorType() {
    QVector<Connector> connectors = _vna->connectorTypes();
    foreach (Connector connector, connectors) {
        QVector<NameLabel> calkits = _vna->calKits(connector);
        if (calkits.contains(_nameLabel))
            return(connector);
    }

    // Default:
    return(Connector());
}
void VnaCalKit::setConnectorType(const Connector &connector) {
    bool _isAgilentModel = isAgilentModel();
    QVector<VnaCalStandard> _standards = standards();
    for (int i = 0; i < _standards.size(); i++) {
        if (_standards[i].isSinglePort()) {
            _standards[i].connector().setType(connector);
        }
        else {
            _standards[i].connector1().setType(connector);
            _standards[i].connector2().setType(connector);
        }
    }
    _vna->deleteCalKit(_nameLabel);
    for (int i = 0; i < _standards.size(); i++) {
        addStandard(_standards[i]);
    }
    if (_isAgilentModel)
        useAgilentModel();
    else
        useRohdeModel();
}

void VnaCalKit::copy(const NameLabel &newNameLabel) {
    QVector<VnaCalStandard> _standards = standards();
    VnaCalKit newCalKit = _vna->calKit(newNameLabel);
    for (int i = 0; i < _standards.size(); i++) {
        newCalKit.addStandard(_standards[i]);
    }
    if (isAgilentModel())
        newCalKit.useAgilentModel();
    else
        newCalKit.useRohdeModel();
}

QVector<VnaCalStandard> VnaCalKit::standards() {
    Connector type = connectorType();
    QVector<VnaCalStandard> standards = standardsSummary();

    const int size = standards.size();
    for (int i = 0; i < size; i++)
        standardDetails(standards[i], type);
    return standards;
}
void VnaCalKit::addStandard(VnaCalStandard standard) {
    if (standard.type() == VnaCalStandard::Type::Isolation) {
        _vna->print("There is an error in the ZNB firmware for the Isolation standard SCPI command\n\n");
        return;
    }


    if (standard.isTouchstone())
        addStandardByTouchstone(standard);
    else
        addStandardByModel(standard);


}

void VnaCalKit::operator=(const VnaCalKit &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _nameLabel = other._nameLabel;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _nameLabel = NameLabel();
    }
}

// Private
bool VnaCalKit::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}

QStringList VnaCalKit::standardsList() {
    QString scpi = ":CORR:CKIT:STAN:LCAT? \'%1\',\'%2\'\n";
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(_nameLabel.label());
    return _vna->query(scpi, 2000).trimmed().remove("\'").split(",", QString::SkipEmptyParts);
}
QVector<VnaCalStandard> VnaCalKit::standardsSummary() {
    Connector type = connectorType();
    QStringList list = standardsList();

    QVector<VnaCalStandard> standards;
    foreach (QString i, list) {
        VnaCalStandard std = VnaScpi::toCalStandard(i);
        if (std.isSinglePort()) {
            std.connector().setType(type);
        }
        else {
            std.connector1().setType(type);
            std.connector2().setType(type);
        }
        standards << std;
    }
    return standards;
}
void VnaCalKit::standardDetails(VnaCalStandard &standard, Connector type) {
    // Firmware error handling
    // Isolation standards
    // (toString(standard) undefined)
    if (standard.type() == VnaCalStandard::Type::Isolation)
        return;

    // Don't query unknown standards
    if (standard.type() == VnaCalStandard::Type::Unknown)
        return;

    QString scpi = ":CORR:CKIT:%1:WLAB? \'%2\',\'%3\',\'%4\'";;
    scpi = scpi.arg(VnaScpi::toString(standard)); // Standard
    scpi = scpi.arg(VnaScpi::toTypeString(type)); // Connector type
    scpi = scpi.arg(_nameLabel.name()); // name
    scpi = scpi.arg(_nameLabel.label()); // label
    if (standard.isPortSpecific()) {
        QString ports;
        if (standard.isSinglePort()) {
            ports = ",%1";
            ports = ports.arg(standard.port());
        }
        else {
            ports = ",%1,%2";
            ports = ports.arg(standard.port1());
            ports = ports.arg(standard.port2());
        }
        scpi = scpi + ports;
    }
    scpi = scpi + "\n";
    parse(standard, _vna->query(scpi, 1000));
}
void VnaCalKit::parse(VnaCalStandard &standard, QString scpi) {
    QStringList list = scpi.remove('\'').trimmed().split(',');
    if (list.size() < 4)
        return;

    // Redundant fields
    list.removeFirst(); // Connector
    list.removeFirst(); // Cal kit name
    list.removeFirst(); // Cal kit label

    // 4th parameter: label
    standard.setLabel(list.takeFirst());

    // Redundant fields
    if (standard.isPortSpecific()) {
        if (!list.isEmpty())
            list.removeLast();
        if (standard.isTwoPort() && !list.isEmpty())
            list.removeLast();
    }

    standard.setModel(VnaScpi::toStandardModel(standard.type(), list));
}


void VnaCalKit::addStandardByTouchstone(VnaCalStandard &standard) {
    QString scpi = ":MMEM:LOAD:CKIT:SDAT \'%1\',\'%2\',%3,\'%4\',\'%5\'";;
    scpi = scpi.arg(VnaScpi::toTypeString(standard.connector()));
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(VnaScpi::toString(standard));
    scpi = scpi.arg(_nameLabel.label());
    scpi = scpi.arg(standard.touchstone());
    if (standard.isPortSpecific()) {
        QString ports;
        if (standard.isSinglePort()) {
            ports = ",%1";
            ports = ports.arg(standard.port());
        }
        else {
            ports = ",%1,%2";
            ports = ports.arg(standard.port1());
            ports = ports.arg(standard.port2());
        }
        scpi = scpi + ports;
    }
    scpi.append("\n");
    _vna->write(scpi);
}
void VnaCalKit::addStandardByModel(VnaCalStandard &standard) {
    QString scpi = ":CORR:CKIT:%1:WLAB \'%2\',\'%3\',\'%4\',\'%5\'";
    scpi = scpi.arg(VnaScpi::toString(standard));
    scpi = scpi.arg(VnaScpi::toTypeString(standard.connector()));
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(_nameLabel.label());
    scpi = scpi.arg(standard.label());
    scpi += ",";
    scpi += VnaScpi::toString(standard.type(), standard.model());
    if (standard.isPortSpecific()) {
        QString ports;
        if (standard.isSinglePort()) {
            ports = ",%1";
            ports = ports.arg(standard.port());
        }
        else {
            ports = ",%1,%2";
            ports = ports.arg(standard.port1());
            ports = ports.arg(standard.port2());
        }
        scpi += ports;
    }
    scpi.append("\n");
    _vna->write(scpi);
}
