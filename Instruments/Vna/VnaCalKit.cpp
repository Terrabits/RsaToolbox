

// RsaToolbox includes
#include "VnaCalKit.h"
#include "Vna.h"
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
    _nameLabel = NameLabel("");
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
        _nameLabel = NameLabel("");
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

bool VnaCalKit::isConnectorType(Connector type) {
    Q_UNUSED(type);
    return(false);
}
bool VnaCalKit::has(VnaCalStandard standard) {
    Q_UNUSED(standard);
    return(false);
}
bool VnaCalKit::has(VnaStandardType type, ConnectorGender gender) {
    Q_UNUSED(type);
    Q_UNUSED(gender);
    return(false);
}
bool VnaCalKit::has(VnaStandardType type, uint port) {
    Q_UNUSED(type);
    Q_UNUSED(port);
    return(false);
}
bool VnaCalKit::has(VnaStandardType type, ConnectorGender gender1, ConnectorGender gender2) {
    Q_UNUSED(type);
    Q_UNUSED(gender1);
    Q_UNUSED(gender2);
    return(false);
}
bool VnaCalKit::has(VnaStandardType type, uint port1, uint port2) {
    Q_UNUSED(type);
    Q_UNUSED(port1);
    Q_UNUSED(port2);
    return(false);
}

bool VnaCalKit::hasOpen(uint port) {
    Q_UNUSED(port);
    return(false);
}
bool VnaCalKit::hasMaleOpen() {
    return(false);
}
bool VnaCalKit::hasFemaleOpen() {
    return(false);
}

bool VnaCalKit::hasShort(uint port) {
    Q_UNUSED(port);
    return(false);
}
bool VnaCalKit::hasMaleShort() {
    return(false);
}
bool VnaCalKit::hasFemaleShort() {
    return(false);
}

bool VnaCalKit::hasMatch(uint port) {
    Q_UNUSED(port);
    return(false);
}
bool VnaCalKit::hasMaleMatch() {
    return(false);
}
bool VnaCalKit::hasFemaleMatch() {
    return(false);
}

bool VnaCalKit::hasThru(ConnectorGender gender1, ConnectorGender gender2) {
    Q_UNUSED(gender1);
    Q_UNUSED(gender2);
    return(false);
}
bool VnaCalKit::hasThru(uint port1, uint port2) {
    Q_UNUSED(port1);
    Q_UNUSED(port2);
    return(false);
}

Connector VnaCalKit::connectorType() {
    QVector<Connector> connectors = _vna->connectorTypes();
    foreach (Connector connector, connectors) {
        QVector<NameLabel> calkits = _vna->calKits(connector);
        if (calkits.contains(_nameLabel))
            return(connector);
    }
    // else
    return(Connector());
}
QVector<VnaCalStandard> VnaCalKit::standards() {
    return(QVector<VnaCalStandard>());
}

void VnaCalKit::operator=(VnaCalKit const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _nameLabel = other._nameLabel;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _nameLabel = NameLabel("");
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

void VnaCalKit::standardDetails(VnaCalStandard &std, Connector type) {
    Q_UNUSED(std);
    Q_UNUSED(type);
}
QStringList VnaCalKit::standardsList() {
    return(QStringList());
}
QVector<VnaCalStandard> VnaCalKit::standardsSummary() {
    return(QVector<VnaCalStandard>());
}

void VnaCalKit::addStandardByTouchstone(VnaCalStandard &standard) {
    Q_UNUSED(standard);
}

void VnaCalKit::addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0) {
    Q_UNUSED(type_scpi);
    Q_UNUSED(connector);
    Q_UNUSED(label);
    Q_UNUSED(min_Hz);
    Q_UNUSED(max_Hz);
    Q_UNUSED(length);
    Q_UNUSED(loss);
    Q_UNUSED(Z0);
}
void VnaCalKit::addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3) {
    Q_UNUSED(type_scpi);
    Q_UNUSED(connector);
    Q_UNUSED(label);
    Q_UNUSED(min_Hz);
    Q_UNUSED(max_Hz);
    Q_UNUSED(length);
    Q_UNUSED(loss);
    Q_UNUSED(Z0);
    Q_UNUSED(C0);
    Q_UNUSED(C1);
    Q_UNUSED(C2);
    Q_UNUSED(C3);
    Q_UNUSED(L0);
    Q_UNUSED(L1);
    Q_UNUSED(L2);
    Q_UNUSED(L3);
}
void VnaCalKit::addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, double R) {
    Q_UNUSED(type_scpi);
    Q_UNUSED(connector);
    Q_UNUSED(label);
    Q_UNUSED(min_Hz);
    Q_UNUSED(max_Hz);
    Q_UNUSED(length);
    Q_UNUSED(loss);
    Q_UNUSED(Z0);
    Q_UNUSED(C0);
    Q_UNUSED(C1);
    Q_UNUSED(C2);
    Q_UNUSED(C3);
    Q_UNUSED(L0);
    Q_UNUSED(L1);
    Q_UNUSED(L2);
    Q_UNUSED(L3);
    Q_UNUSED(R);
}

void VnaCalKit::addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, double R, uint port) {
    Q_UNUSED(type_scpi);
    Q_UNUSED(connector);
    Q_UNUSED(label);
    Q_UNUSED(min_Hz);
    Q_UNUSED(max_Hz);
    Q_UNUSED(length);
    Q_UNUSED(loss);
    Q_UNUSED(Z0);
    Q_UNUSED(C0);
    Q_UNUSED(C1);
    Q_UNUSED(C2);
    Q_UNUSED(C3);
    Q_UNUSED(L0);
    Q_UNUSED(L1);
    Q_UNUSED(L2);
    Q_UNUSED(L3);
    Q_UNUSED(R);
    Q_UNUSED(port);
}
void VnaCalKit::addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, uint port1, uint port2) {
    Q_UNUSED(type_scpi);
    Q_UNUSED(connector);
    Q_UNUSED(label);
    Q_UNUSED(min_Hz);
    Q_UNUSED(max_Hz);
    Q_UNUSED(length);
    Q_UNUSED(loss);
    Q_UNUSED(Z0);
    Q_UNUSED(port1);
    Q_UNUSED(port2);
}
void VnaCalKit::addStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, uint port1, uint port2) {
    Q_UNUSED(type_scpi);
    Q_UNUSED(connector);
    Q_UNUSED(label);
    Q_UNUSED(min_Hz);
    Q_UNUSED(max_Hz);
    Q_UNUSED(length);
    Q_UNUSED(loss);
    Q_UNUSED(Z0);
    Q_UNUSED(C0);
    Q_UNUSED(C1);
    Q_UNUSED(C2);
    Q_UNUSED(C3);
    Q_UNUSED(L0);
    Q_UNUSED(L1);
    Q_UNUSED(L2);
    Q_UNUSED(L3);
    Q_UNUSED(port1);
    Q_UNUSED(port2);

}
