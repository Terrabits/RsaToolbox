

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
bool VnaCalKit::has(VnaStandardType type, Connector::Gender gender) {
    if (!VnaCalStandard::isSinglePort(type))
        return false;

    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.type() == type && s.gender() == gender)
            return true;
    }

    return false;
}
bool VnaCalKit::has(VnaStandardType type, uint port) {
    if (!VnaCalStandard::isSinglePort(type))
        return false;

    QVector<VnaCalStandard> standards = this->standards();
    foreach(VnaCalStandard s, standards) {
        if (s.type() == type && s.port() == port)
            return true;
    }

    return false;
}
bool VnaCalKit::has(VnaStandardType type, Connector::Gender gender1, Connector::Gender gender2) {
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
bool VnaCalKit::has(VnaStandardType type, uint port1, uint port2) {
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
    if (standard.isTouchstone()) {
        addStandardByTouchstone(standard);
        return;
    }

    // Values
    QString type;
    QString connector = VnaScpi::toTypeString(standard.connector());
    QString label = standard.label();
    double min = standard.minimumFrequency_Hz();
    double max = standard.maximumFrequency_Hz();
    double e_length = standard.model().eLength_m;
    double loss = standard.model().loss_dB_per_sqrt_Hz;
    double Z0 = standard.model().Z0_Ohms;
    double C0 = standard.model().C0_fF;
    double C1 = standard.model().C1_fF_per_GHz;
    double C2 = standard.model().C2_fF_per_GHz2;
    double C3 = standard.model().C3_fF_per_GHz3;
    double L0 = standard.model().L0_pH;
    double L1 = standard.model().L1_pH_per_GHz;
    double L2 = standard.model().L2_pH_per_GHz2;
    double L3 = standard.model().L3_pH_per_GHz3;
    double R = standard.model().R_Ohms;

    if (standard.isSinglePort()) {
        if (standard.isPortSpecific()) {
            type = VnaScpi::toString(standard.type(), standard.gender());
            addStandardByModel(type, connector, label, min, max, e_length,loss, Z0, C0, C1, C2, C3, L0, L1, L2, L3, R, standard.port());
        }
        else { // Not port specific
            type = VnaScpi::toString(standard.type(), standard.gender());
            if (R == 0)
                addStandardByModel(type, connector, label, min, max, e_length,loss, Z0, C0, C1, C2, C3, L0, L1, L2, L3);
            else
                addStandardByModel(type, connector, label, min, max, e_length,loss, Z0, C0, C1, C2, C3, L0, L1, L2, L3, R);
        }
    }
    else { // Two port
        if (standard.isPortSpecific()) {
            type = VnaScpi::toString(standard.type(), standard.gender1(), standard.gender2());
            if (standard.type() != SYMMETRIC_NETWORK_STANDARD_TYPE) {
                addStandardByModel(type, connector, label, min, max, e_length, loss, Z0, standard.port1(), standard.port2());
            }
            else { // Symm. Network
                addStandardByModel(type, connector, label, min, max, e_length,loss, Z0, C0, C1, C2, C3, L0, L1, L2, L3, standard.port1(), standard.port2());
            }
        }
        else { // Not port specific
            type = VnaScpi::toString(standard.type(), standard.gender1(), standard.gender2());
            if (standard.type() != SYMMETRIC_NETWORK_STANDARD_TYPE) {
                addStandardByModel(type, connector, label, min, max, e_length, loss, Z0);
            }
            else { // SYMM. Network
                addStandardByModel(type, connector, label, min, max, e_length,loss, Z0, C0, C1, C2, C3, L0, L1, L2, L3);
            }
        }
    }
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
    if (standard.type() == ISOLATION_STANDARD_TYPE)
        return;

    // Don't query unknown standards
    if (standard.type() == UNKNOWN_STANDARD_TYPE)
        return;

    QString scpi;
    if (!standard.isPortSpecific()) {
        scpi = ":CORR:CKIT:%1:WLAB? \'%2\',\'%3\',\'%4\'\n";
        scpi = scpi.arg(VnaScpi::toString(standard)); // Standard
        scpi = scpi.arg(VnaScpi::toTypeString(type)); // Connector type
        scpi = scpi.arg(_nameLabel.name()); // name
        scpi = scpi.arg(_nameLabel.label()); // label
    }
    else {
        // Port specific standard
        if (standard.isSinglePort()) {
            scpi = ":CORR:CKIT:%1:WLAB? \'%2\',\'%3\',\'%4\',%5\n";
            scpi = scpi.arg(VnaScpi::toString(standard)); // Standard
            scpi = scpi.arg(VnaScpi::toTypeString(type)); // Connector type
            scpi = scpi.arg(_nameLabel.name()); // name
            scpi = scpi.arg(_nameLabel.label()); // label
            scpi = scpi.arg(standard.port()); // Port
        }
        else {
            scpi = ":CORR:CKIT:%1:WLAB? \'%2\',\'%3\',\'%4\',%5,%6\n";
            scpi = scpi.arg(VnaScpi::toString(standard)); // Standard
            scpi = scpi.arg(VnaScpi::toTypeString(type)); // Connector type
            scpi = scpi.arg(_nameLabel.name()); // name
            scpi = scpi.arg(_nameLabel.label()); // label
            scpi = scpi.arg(standard.port1()); // Port 1
            scpi = scpi.arg(standard.port2()); // Port 2
        }
    }
    parse(standard, _vna->query(scpi, 1000));
}
void VnaCalKit::parse(VnaCalStandard &standard, QString scpi) {
    QStringList results = scpi.remove('\'').split(',', QString::KeepEmptyParts);
    int length = results.size();

    if (length < 6)
        return;

    standard.setLabel(results[3]);
    standard.setMinimumFrequency(results[4].toDouble());
    standard.setMaximumFrequency(results[5].toDouble());

    if (length < 9)
        return;

    double e_length = results[6].toDouble();
    double loss = results[7].toDouble();
    double Z0 = results[8].toDouble();

    if (length == 9) {
        standard.setModel(e_length, loss, Z0,
                          0,0,0,0, // C
                          0,0,0,0, // L
                          0); // R
        return;
    }

    if (length < 11)
        return;

    if (length == 11) {
        // thru, port-specific
        standard.setPorts(results[9].toDouble(),
                results[10].toDouble());
        standard.setModel(e_length, loss, Z0,
                          0,0,0,0, // C
                          0,0,0,0, // L
                          0); // R
        return;
    }

    if (length < 17)
        return;

    double C0, C1, C2, C3;
    double L0, L1, L2, L3;

    C0 = results[9].toDouble();
    C1 = results[10].toDouble();
    C2 = results[11].toDouble();
    C3 = results[12].toDouble();

    L0 = results[13].toDouble();
    L1 = results[14].toDouble();
    L2 = results[15].toDouble();
    L3 = results[16].toDouble();

    if (length == 17) {
        standard.setModel(e_length, loss, Z0,
                          C0,C1,C2,C3,
                          L0,L1,L2,L3,
                          0); // R
        return;
    }

    double R = results[17].toDouble();

    if (length == 18) {
        standard.setModel(e_length, loss, Z0,
                          C0,C1,C2,C3,
                          L0,L1,L2,L3,
                          R);
        return;
    }

    if (length == 19) {
        standard.setPort(results[18].toDouble());
        standard.setModel(e_length, loss, Z0,
                          C0,C1,C2,C3,
                          L0,L1,L2,L3,
                          R);
        return;
    }

    if (length == 20) {
        standard.setPorts(results[18].toDouble(),
                          results[19].toDouble());
        standard.setModel(e_length, loss, Z0,
                          C0,C1,C2,C3,
                          L0,L1,L2,L3,
                          R);
        return;
    }
}



void VnaCalKit::addStandardByTouchstone(VnaCalStandard &standard) {
    QString scpi;
    if (standard.isTwoPort()) {
        if (standard.isPortSpecific()) {
            scpi = ":MMEM:LOAD:CKIT:SDAT \'%1\',\'%2\',%3,\'%4\',\'%5\',%6,%7\n";
            scpi = scpi.arg(VnaScpi::toTypeString(standard.connector()));
            scpi = scpi.arg(_nameLabel.name());
            scpi = scpi.arg(VnaScpi::toString(standard));
            scpi = scpi.arg(_nameLabel.label());
            scpi = scpi.arg(standard.touchstone());
            scpi = scpi.arg(standard.port1());
            scpi = scpi.arg(standard.port2());
        }
        else {
            scpi = ":MMEM:LOAD:CKIT:SDAT \'%1\',\'%2\',%3,\'%4\',\'%5\'\n";
            scpi = scpi.arg(VnaScpi::toTypeString(standard.connector()));
            scpi = scpi.arg(_nameLabel.name());
            scpi = scpi.arg(VnaScpi::toString(standard));
            scpi = scpi.arg(_nameLabel.label());
            scpi = scpi.arg(standard.touchstone());
        }
    }
    else {
        if (standard.isPortSpecific()) {
            scpi = ":MMEM:LOAD:CKIT:SDAT \'%1\',\'%2\',%3,\'%4\',\'%5\',%6\n";
            scpi = scpi.arg(VnaScpi::toTypeString(standard.connector()));
            scpi = scpi.arg(_nameLabel.name());
            scpi = scpi.arg(VnaScpi::toString(standard));
            scpi = scpi.arg(_nameLabel.label());
            scpi = scpi.arg(standard.touchstone());
            scpi = scpi.arg(standard.port1());
        }
        else {
            scpi = ":MMEM:LOAD:CKIT:SDAT \'%1\',\'%2\',%3,\'%4\',\'%5\'\n";
            scpi = scpi.arg(VnaScpi::toTypeString(standard.connector()));
            scpi = scpi.arg(_nameLabel.name());
            scpi = scpi.arg(VnaScpi::toString(standard));
            scpi = scpi.arg(_nameLabel.label());
            scpi = scpi.arg(standard.touchstone());
        }
    }
    _vna->write(scpi);
}
void VnaCalKit::addStandardByModel(QString type, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0) {
    QString scpi = ":CORR:CKIT:%1:WLAB \'%2\',\'%3\',\'%4\',\'%5\',%6,%7,%8,%9,%10\n";
    scpi = scpi.arg(type);
    scpi = scpi.arg(connector);
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(_nameLabel.label());
    scpi = scpi.arg(label);
    scpi = scpi.arg(min_Hz);
    scpi = scpi.arg(max_Hz);
    scpi = scpi.arg(length);
    scpi = scpi.arg(loss);
    scpi = scpi.arg(Z0);
    _vna->write(scpi);
}
void VnaCalKit::addStandardByModel(QString type, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3) {
    QString scpi = ":CORR:CKIT:%1:WLAB \'%2\',\'%3\',\'%4\',\'%5\',%6,%7,%8,%9,%10,%11,%12,%13,%14,%15,%16,%17,%18\n";
    scpi = scpi.arg(type);
    scpi = scpi.arg(connector);
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(_nameLabel.label());
    scpi = scpi.arg(label);
    scpi = scpi.arg(min_Hz);
    scpi = scpi.arg(max_Hz);
    scpi = scpi.arg(length);
    scpi = scpi.arg(loss);
    scpi = scpi.arg(Z0);
    scpi = scpi.arg(C0);
    scpi = scpi.arg(C1);
    scpi = scpi.arg(C2);
    scpi = scpi.arg(C3);
    scpi = scpi.arg(L0);
    scpi = scpi.arg(L1);
    scpi = scpi.arg(L2);
    scpi = scpi.arg(L3);
    _vna->write(scpi);
}
void VnaCalKit::addStandardByModel(QString type, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, double R) {
    QString scpi = ":CORR:CKIT:%1:WLAB \'%2\',\'%3\',\'%4\',\'%5\',%6,%7,%8,%9,%10,%11,%12,%13,%14,%15,%16,%17,%18,%19\n";
    scpi = scpi.arg(type);
    scpi = scpi.arg(connector);
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(_nameLabel.label());
    scpi = scpi.arg(label);
    scpi = scpi.arg(min_Hz);
    scpi = scpi.arg(max_Hz);
    scpi = scpi.arg(length);
    scpi = scpi.arg(loss);
    scpi = scpi.arg(Z0);
    scpi = scpi.arg(C0);
    scpi = scpi.arg(C1);
    scpi = scpi.arg(C2);
    scpi = scpi.arg(C3);
    scpi = scpi.arg(L0);
    scpi = scpi.arg(L1);
    scpi = scpi.arg(L2);
    scpi = scpi.arg(L3);
    scpi = scpi.arg(R);
    _vna->write(scpi);
}
void VnaCalKit::addStandardByModel(QString type, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, double R, uint port) {
    QString scpi = ":CORR:CKIT:%1:WLAB \'%2\',\'%3\',\'%4\',\'%5\',%6,%7,%8,%9,%10,%11,%12,%13,%14,%15,%16,%17,%18,%19,%20\n";
    scpi = scpi.arg(type);
    scpi = scpi.arg(connector);
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(_nameLabel.label());
    scpi = scpi.arg(label);
    scpi = scpi.arg(min_Hz);
    scpi = scpi.arg(max_Hz);
    scpi = scpi.arg(length);
    scpi = scpi.arg(loss);
    scpi = scpi.arg(Z0);
    scpi = scpi.arg(C0);
    scpi = scpi.arg(C1);
    scpi = scpi.arg(C2);
    scpi = scpi.arg(C3);
    scpi = scpi.arg(L0);
    scpi = scpi.arg(L1);
    scpi = scpi.arg(L2);
    scpi = scpi.arg(L3);
    scpi = scpi.arg(R);
    scpi = scpi.arg(port);
    _vna->write(scpi);
}
void VnaCalKit::addStandardByModel(QString type, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, uint port1, uint port2) {
    QString scpi = ":CORR:CKIT:%1:WLAB \'%2\',\'%3\',\'%4\',\'%5\',%6,%7,%8,%9,%10,%11,%12\n";
    scpi = scpi.arg(type);
    scpi = scpi.arg(connector);
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(_nameLabel.label());
    scpi = scpi.arg(label);
    scpi = scpi.arg(min_Hz);
    scpi = scpi.arg(max_Hz);
    scpi = scpi.arg(length);
    scpi = scpi.arg(loss);
    scpi = scpi.arg(Z0);
    scpi = scpi.arg(port1);
    scpi = scpi.arg(port2);
    _vna->write(scpi);
}
void VnaCalKit::addStandardByModel(QString type, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, uint port1, uint port2) {
    QString scpi = ":CORR:CKIT:%1:WLAB \'%2\',\'%3\',\'%4\',\'%5\',%6,%7,%8,%9,%10,%11,%12,%13,%14,%15,%16,%17,%18,%19,%20\n";
    scpi = scpi.arg(type);
    scpi = scpi.arg(connector);
    scpi = scpi.arg(_nameLabel.name());
    scpi = scpi.arg(_nameLabel.label());
    scpi = scpi.arg(label);
    scpi = scpi.arg(min_Hz);
    scpi = scpi.arg(max_Hz);
    scpi = scpi.arg(length);
    scpi = scpi.arg(loss);
    scpi = scpi.arg(Z0);
    scpi = scpi.arg(C0);
    scpi = scpi.arg(C1);
    scpi = scpi.arg(C2);
    scpi = scpi.arg(C3);
    scpi = scpi.arg(L0);
    scpi = scpi.arg(L1);
    scpi = scpi.arg(L2);
    scpi = scpi.arg(L3);
    scpi = scpi.arg(port1);
    scpi = scpi.arg(port2);
    _vna->write(scpi);

}
