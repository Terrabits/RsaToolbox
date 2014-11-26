

#include "VnaTrace.h"

// RsaToolbox
#include "General.h"
#include "Vna.h"
#include "VnaScpi.h"
using namespace RsaToolbox;

// Qt
#include <Qt>
#include <QtGui/QColor>
#include <QtGui/QPen>
#include <QDebug>

/*!
 * \class RsaToolbox::VnaTrace
 * \ingroup VnaGroup
 * \brief The \c %VnaTrace class provides an object-oriented
 * method for manipulating a trace.
 */

VnaTrace::VnaTrace(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _name = "";
}
VnaTrace::VnaTrace(const VnaTrace &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _name = other._name;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _name = "";
    }
}
VnaTrace::VnaTrace(Vna *vna, QString name, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _name = name;
}
VnaTrace::~VnaTrace() {

}

bool VnaTrace::isVisible() {
    QString scpi = ":DISP:TRAC:SHOW? \'%1\'\n";
    scpi = scpi.arg(_name);
    return(_vna->query(scpi).trimmed() == "1");
}
bool VnaTrace::isHidden() {
    return(!isVisible() || (diagram() == 0));
}

void VnaTrace::select() {
    QString scpi = ":CALC%1:PAR:SEL \'%2\'\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(name());
    _vna->write(scpi);
}
void VnaTrace::autoscale() {
    QString scpi = ":DISP:TRAC:Y:AUTO ONCE, \'%1\'\n";
    scpi = scpi.arg(_name);
    _vna->write(scpi);
}
void VnaTrace::show(bool isVisible) {
    QString scpi = ":DISP:TRAC:SHOW \'%1\',%2";
    scpi = scpi.arg(_name);
    if (isVisible)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
void VnaTrace::hide(bool isInvisible) {
    show(!isInvisible);
}

QString VnaTrace::name() {
    return(_name);
}
uint VnaTrace::channel() {
    QString scpi = ":CONF:TRAC:CHAN:NAME:ID? \'%1\'\n";
    scpi = scpi.arg(_name);
    return(_vna->query(scpi).trimmed().toUInt());
}
uint VnaTrace::diagram() {
    if (!_vna->properties().isZvaFamily()) {
        QString scpi = ":CONF:TRAC:WIND? \'%1\'\n";
        scpi = scpi.arg(_name);
        uint result = _vna->query(scpi).trimmed().toUInt();
        return(result);
    }
    else { // ZVA lacks this command
        QVector<uint> diagrams = _vna->diagrams();
        foreach (uint i, diagrams) {
            if (_vna->diagram(i).traces().contains(_name))
                return i;
        }
        return 0;
    }
}
void VnaTrace::setDiagram(uint index) {
    QString scpi = ":DISP:WIND%1:TRAC:EFE \'%2\'\n";
    scpi = scpi.arg(index);
    scpi = scpi.arg(_name);
    _vna->write(scpi);
}

bool VnaTrace::isNetworkParameter() {
    QString result = measurementString();
    result = result.toUpper();
    switch(result.at(0).toLatin1()) {
    case 'S': return(true);
    case 'Y':
    case 'Z':
        if (result.contains("-"))
            return(false);
        else
            return(true);
    default: return(false);
    }
}
void VnaTrace::networkParameter(NetworkParameter &parameter, uint &outputPort, uint &inputPort) {
    Q_UNUSED(parameter);
    Q_UNUSED(outputPort);
    Q_UNUSED(inputPort);
}
void VnaTrace::networkParameter(NetworkParameter &parameter, BalancedPort &outputPort, BalancedPort &inputPort) {
    Q_UNUSED(parameter);
    Q_UNUSED(outputPort);
    Q_UNUSED(inputPort);
}
void VnaTrace::setNetworkParameter(NetworkParameter parameter, uint outputPort, uint inputPort) {
    QString scpi;
    if (_vna->properties().isZvaFamily())
        scpi = ":CALC%1:PAR:MEAS \'%2\',\'%3\'\n";
    else
        scpi = ":CALC%1:PAR:MEAS:SEND \'%2\',\'%3\'\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(_name);
    scpi = scpi.arg(VnaScpi::toString(parameter, outputPort, inputPort));
    _vna->write(scpi);
}
void VnaTrace::setNetworkParameter(NetworkParameter parameter, BalancedPort outputPort, BalancedPort inputPort) {
    QString scpi = ":CALC%1:PAR:MEAS \'%2\',\'%3\'\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(_name);
    scpi = scpi.arg(VnaScpi::toString(parameter, outputPort, inputPort));
    _vna->write(scpi);
}
void VnaTrace::measure(NetworkTraceData &data) {
    NetworkParameter parameter;
    BalancedPort outputPort, inputPort;
    networkParameter(parameter, outputPort, inputPort);
    data.setParameter(parameter);
    data.setOutputPort(outputPort);
    data.setInputPort(inputPort);
    ComplexRowVector yValues;
    y(yValues);
    data.setData(x(), yValues);
}

bool VnaTrace::isWaveQuantity() {
    QString result = measurementString();
    result = result.toUpper();
    switch(result.at(0).toLatin1()) {
    case 'A':
    case 'B':
        if (result.contains("/"))
            return(false);
        else
            return(true);
    default: return(false);
    }
}
void VnaTrace::waveQuantity(WaveQuantity &wave, uint &port) {
    Q_UNUSED(wave);
    Q_UNUSED(port);
}
void VnaTrace::setWaveQuantity(WaveQuantity wave, uint port) {
    QString scpi = ":CALC%1:PAR:MEAS \'%2\',\'%3\'\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(_name);
    scpi = scpi.arg(VnaScpi::toString(wave, port));
    _vna->write(scpi);
}

bool VnaTrace::isWaveRatio() {
    QString result = measurementString();
    result = result.toUpper();
    switch(result.at(0).toLatin1()) {
    case 'A':
    case 'B':
        if (result.contains("/"))
            return(true);
        else
            return(false);
    default: return(false);
    }
}
void VnaTrace::waveRatio(WaveQuantity &outputWave, uint &outputPort, WaveQuantity &inputWave, uint &inputPort) {
    Q_UNUSED(outputWave);
    Q_UNUSED(outputPort);
    Q_UNUSED(inputWave);
    Q_UNUSED(inputPort);
}
void VnaTrace::setWaveRatio(WaveQuantity numeratorWave, uint numeratorPort, WaveQuantity denominatorWave, uint denominatorPort) {
    QString scpi = ":CALC%1:PAR:MEAS \'%2\',\'%3/%4\'\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(_name);
    scpi = scpi.arg(VnaScpi::toString(numeratorWave, numeratorPort));
    scpi = scpi.arg(VnaScpi::toString(denominatorWave, denominatorPort));
    _vna->write(scpi);
}

bool VnaTrace::isImpedance() {
    QString result = measurementString();
    result = result.toUpper();
    if (result.at(0) == 'Z' && result.contains("-"))
        return(true);
    else
        return(false);
}
void VnaTrace::impedance(uint &outputPort, uint &inputPort) {
    Q_UNUSED(outputPort);
    Q_UNUSED(inputPort);
}
void VnaTrace::impedance(BalancedPort &outputPort, BalancedPort &inputPort) {
    Q_UNUSED(outputPort);
    Q_UNUSED(inputPort);
}
void VnaTrace::setImpedance(uint outputPort, uint inputPort) {
    QString scpi = ":CALC%1:PAR:MEAS \'%2\',\'Z-S%3\'\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(_name);
    scpi = scpi.arg(VnaScpi::toPortPair(outputPort, inputPort));
    _vna->write(scpi);
}
void VnaTrace::setImpedance(BalancedPort outputPort, BalancedPort inputPort) {
    QString scpi = ":CALC%1:PAR:MEAS \'%2\',\'Z-%3\'\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(_name);
    scpi = scpi.arg(VnaScpi::toString(NetworkParameter::S, outputPort, inputPort));
    _vna->write(scpi);
}

bool VnaTrace::isAdmittance() {
    QString result = measurementString();
    result = result.toUpper();
    if (result.at(0) == 'Y' && result.contains("-"))
        return(true);
    else
        return(false);
}
void VnaTrace::admittance(uint &outputPort, uint &inputPort) {
    Q_UNUSED(outputPort);
    Q_UNUSED(inputPort);
}
void VnaTrace::admittance(BalancedPort &outputPort, BalancedPort &inputPort) {
    Q_UNUSED(outputPort);
    Q_UNUSED(inputPort);
}
void VnaTrace::setAdmittance(uint outputPort, uint inputPort) {
    QString scpi = ":CALC%1:PAR:MEAS \'%2\',\'Y-S%3\'\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(_name);
    scpi = scpi.arg(VnaScpi::toPortPair(outputPort, inputPort));
    _vna->write(scpi);
}
void VnaTrace::setAdmittance(BalancedPort outputPort, BalancedPort inputPort) {
    QString scpi = ":CALC%1:PAR:MEAS \'%2\',\'Y-%3\'\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(_name);
    scpi = scpi.arg(VnaScpi::toString(NetworkParameter::S, outputPort, inputPort));
    _vna->write(scpi);
}

TraceFormat VnaTrace::format() {
    select();
    QString scpi = ":CALC%1:FORM?\n";
    scpi = scpi.arg(channel());
    QString result = _vna->query(scpi).trimmed();
    return(VnaScpi::toTraceFormat(result));
}
void VnaTrace::setFormat(TraceFormat format) {
    QString scpi = ":CALC%1:FORM %2\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(VnaScpi::toString(format));
    _vna->write(scpi);
}

void VnaTrace::setDisplayProperties(int red, int green, int blue, Qt::PenStyle style, int width) {
    Q_UNUSED(red);
    Q_UNUSED(green);
    Q_UNUSED(blue);
    Q_UNUSED(style);
    Q_UNUSED(width);
}
void VnaTrace::setDisplayProperties(QColor color, Qt::PenStyle style, int width) {
    Q_UNUSED(color);
    Q_UNUSED(style);
    Q_UNUSED(width);
}
void VnaTrace::setDisplayProperties(QPen pen) {
    Q_UNUSED(pen);
}

void VnaTrace::setYAxisMinimum(double min) {
    QString scpi = ":DISP:TRAC:Y:BOTT %1, \'%2\'\n";
    scpi = scpi.arg(min);
    scpi = scpi.arg(_name);
    _vna->write(scpi);
}
void VnaTrace::setYAxisMaximum(double max) {
    QString scpi = ":DISP:TRAC:Y:TOP %1, \'%2\'\n";
    scpi = scpi.arg(max);
    scpi = scpi.arg(_name);
    _vna->write(scpi);
}
void VnaTrace::setYAxis(double min, double max) {
    Q_UNUSED(min);
    Q_UNUSED(max);
}

uint VnaTrace::points() {
    return(_vna->channel(channel()).linearSweep().points());
}
QRowVector VnaTrace::x() {
    select();

    QString scpi = ":CALC%1:DATA:STIM?\n";
    scpi = scpi.arg(channel());
    return(_vna->queryVector(scpi, bufferSize()));
}
void VnaTrace::y(QRowVector &y) {
    uint channel = this->channel();

    QString scpi;
    if (_vna->properties().isZvaFamily()) {
        select();
        scpi = ":CALC%1:DATA? FDAT\n";
        scpi = scpi.arg(channel);
    }
    else {
        scpi = ":CALC:DATA:TRAC? \'%1\', FDAT\n";
        scpi = scpi.arg(_name);
    }

    QRowVector result;
    if (_vna->channel(channel).isContinuousSweep()) {
        _vna->channel(channel).manualSweepOn();
        _vna->channel(channel).startSweep();
        _vna->wait();
        result = _vna->queryVector(scpi, bufferSize());
        _vna->channel(channel).continuousSweepOn();
    }
    else {
        result = _vna->queryVector(scpi, bufferSize());
    }
    y = result;
}
void VnaTrace::y(ComplexRowVector &y) {
    uint channel = this->channel();

    QString scpi;
    if (_vna->properties().isZvaFamily()) {
        select();
        scpi = ":CALC%1:DATA? SDAT\n";
        scpi = scpi.arg(channel);
    }
    else {
        scpi = ":CALC:DATA:TRAC? \'%1\', SDAT\n";
        scpi = scpi.arg(_name);
    }

    ComplexRowVector result;
    if (_vna->channel(channel).isContinuousSweep()) {
        _vna->channel(channel).manualSweepOn();
        _vna->channel(channel).startSweep();
        _vna->wait();
        result = _vna->queryComplexVector(scpi, complexBufferSize());
        _vna->channel(channel).continuousSweepOn();
    }
    else {
        result = _vna->queryComplexVector(scpi, complexBufferSize());
    }
    y = result;
}

void VnaTrace::toMemory(QString name) {
    QString scpi = ":TRAC:COPY \'%1\',\'%2\'\n";
    scpi = scpi.arg(name);
    scpi = scpi.arg(this->name());
    _vna->write(scpi);
}
void VnaTrace::write(QRowVector data) {
    // FOR SOME REASON YOU JUST CANNOT
    // WRITE FORMATTED (REAL) DATA TO
    // A MEMORY TRACE.
    // "FUNCTION NOT AVAILABLE"!
    QString scpi = ":CALC%1:DATA FDAT,";
    scpi = scpi.arg(channel());

    _vna->settings().setRead64BitBinaryFormat();
    _vna->settings().setLittleEndian();
    select();
    _vna->binaryWrite(scpi.toUtf8()
                      + toBlockDataFormat(data) + "\n");
    _vna->wait();
}
void VnaTrace::write(QRowVector frequencies_Hz, QRowVector data) {
    uint i = channel();
    _vna->channel(i).setFrequencies(frequencies_Hz);
    write(data);
}
void VnaTrace::write(ComplexRowVector data) {
    QString scpi = ":CALC%1:DATA SDAT, ";
    scpi = scpi.arg(channel());

    if (_vna->properties().isZvaFamily())
        _vna->settings().displayOn();
    select();
    _vna->settings().setRead64BitBinaryFormat();
    _vna->settings().setLittleEndian();
    _vna->binaryWrite(scpi.toUtf8()
                      + toBlockDataFormat(data) + "\n");
    _vna->wait();
}
void VnaTrace::write(QRowVector frequencies_Hz, ComplexRowVector data) {
    uint i = channel();
    _vna->channel(i).setFrequencies(frequencies_Hz);
    write(data);
}

// Marker
bool VnaTrace::isMarker(uint index) {
    select();

    QString scpi = ":CALC%1:MARK%2?\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(index);
    return(_vna->query(scpi).trimmed() == "1");
}
bool VnaTrace::isNotMarker(uint index) {
    return(!isMarker(index));
}
bool VnaTrace::isMarkers() {
    return(markers().isEmpty() == false);
}
bool VnaTrace::isNotMarkers() {
    return(!isMarkers());
}
QVector<uint> VnaTrace::markers() {
    QVector<uint> markers;

    for (int i = 1; i <= 10; i++) {
        if (isMarker(i) == true)
            markers.append(i);
    }
    return(markers);
}
void VnaTrace::createMarker(uint index) {
//    if (index <= 0 || index > 10) {
//            _vna->print("ERROR: Cannot create marker "
//                        + QVariant(index).toString() + "\n"
//                        + "Marker indexes must be 1-10\n\n");
//            return;
//        }

        select();

        QString scpi = ":CALC%1:MARK%2 1\n";
        scpi = scpi.arg(channel());
        scpi = scpi.arg(index);
        _vna->write(scpi);
}
uint VnaTrace::createMarker() {
    for (int i = 1; i <= 10; i++) {
        if (isMarker(i) == false) {
            createMarker(i);
            return(i);
        }
    }

    // Else: all markers are used
    _vna->print(QString()
                + "ERROR: Cannot create new marker.\n"
                + "The maximum of 10 markers has been reached\n\n");
    return(0);
}
void VnaTrace::deleteMarker(uint index) {
//    if (index <= 0 || index > 10) {
//            vna->log->print(QString()
//                            + "ERROR: Cannot delete marker "
//                            + QVariant(index).toString() + "\n"
//                            + "Marker indexes must be 1-10\n\n");
//            return;
//        }

    select();

    QString scpi = ":CALC%1:MARK%2 0\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(index);
    _vna->write(scpi);
}
void VnaTrace::deleteMarkers() {
    for (int i = 1; i <= 10; i++) {
        deleteMarker(i);
    }
}
VnaMarker &VnaTrace::marker(uint index) {
    _marker.reset(new VnaMarker(_vna, this, index));
    return(*_marker.data());
}

// Reference Marker
VnaReferenceMarker &VnaTrace::referenceMarker() {
    _referenceMarker.reset(new VnaReferenceMarker(_vna, this));
    return(*_referenceMarker.data());
}

// Limit Lines
VnaLimits &VnaTrace::limits() {
    _limits.reset(new VnaLimits(_vna, this));
    return *_limits.data();
}

// Trace math
VnaMath &VnaTrace::math() {
    _math.reset(new VnaMath(_vna, this));
    return *_math.data();
}

// Time Domain
bool VnaTrace::isTimeDomain() {
    return(timeDomain().isOn());
}
bool VnaTrace::isNotTimeDomain() {
    return(timeDomain().isOff());
}

VnaTimeDomain &VnaTrace::timeDomain() {
    _timeDomain.reset(new VnaTimeDomain(_vna, this));
    return(*_timeDomain.data());
}


void VnaTrace::operator=(VnaTrace const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _name = other._name;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _name = "";
    }
}

//void VnaTrace::moveToThread(QThread *thread) {
//    QObject::moveToThread(thread);
//    if (_marker.isNull() == false)
//        _marker->moveToThread(thread);
//    if (_referenceMarker.isNull() == false)
//        _referenceMarker->moveToThread(thread);
//    if (_timeDomain.isNull() == false)
//        _timeDomain->moveToThread(thread);
//}

// Private
bool VnaTrace::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}

QString VnaTrace::measurementString() {
    QString scpi = ":CALC%1:PAR:MEAS? \'%2\'\n";
    scpi = scpi.arg(channel());
    scpi = scpi.arg(_name);
    return(_vna->query(scpi).trimmed().remove("\'"));
}
uint VnaTrace::bufferSize() {
    const uint SIZE_PER_POINT = 8;
    return(SIZE_PER_POINT * points() + 11);
}
uint VnaTrace::complexBufferSize() {
    return(2 * bufferSize() - 11);
}
