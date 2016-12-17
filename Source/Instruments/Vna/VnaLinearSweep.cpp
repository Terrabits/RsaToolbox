#include <QDebug>

// RsaToolbox includes
#include "General.h"
#include "VnaLinearSweep.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaLinearSweep
 * \ingroup VnaGroup
 * \brief The \c %VnaLinearSweep class
 * configures and controls a
 * frequency sweep with linearly-spaced
 * measurement points.
 */

VnaLinearSweep::VnaLinearSweep(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaLinearSweep::VnaLinearSweep(VnaLinearSweep &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _channel.reset(new VnaChannel(*other._channel.data()));
        _channelIndex = other._channelIndex;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
    }
}
VnaLinearSweep::VnaLinearSweep(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}
VnaLinearSweep::VnaLinearSweep(Vna *vna, uint index, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, index));
    _channelIndex = index;
}
VnaLinearSweep::~VnaLinearSweep() {

}


uint VnaLinearSweep::points() {
    QString scpi = ":SENS%1:SWE:POIN?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toUInt());
}
void VnaLinearSweep::setPoints(uint numberOfPoints) {
    QString scpi = ":SENS%1:SWE:POIN %2\n";
    scpi = scpi.arg(_channelIndex).arg(numberOfPoints);
    _vna->write(scpi);
}
double VnaLinearSweep::start_Hz() {
    QString scpi = ":SENS%1:FREQ:STAR?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaLinearSweep::setStart(double frequency, SiPrefix prefix) {
    QString scpi = ":SENS%1:FREQ:STAR %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(formatDouble(frequency, 12));
    scpi = scpi.arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}
double VnaLinearSweep::stop_Hz() {
    QString scpi = ":SENS%1:FREQ:STOP?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaLinearSweep::setStop(double frequency, SiPrefix prefix) {
    QString scpi = ":SENS%1:FREQ:STOP %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(formatDouble(frequency, 12));
    scpi = scpi.arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}
double VnaLinearSweep::center_Hz() {
    QString scpi = ":SENS%1:FREQ:CENT?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaLinearSweep::setCenter(double frequency, SiPrefix prefix) {
    QString scpi = ":SENS%1:FREQ:CENT %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(formatDouble(frequency, 12));
    scpi = scpi.arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}
double VnaLinearSweep::span_Hz() {
    QString scpi = ":SENS%1:FREQ:SPAN?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaLinearSweep::setSpan(double frequencyRange, SiPrefix prefix) {
    QString scpi = ":SENS%1:FREQ:SPAN %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(formatDouble(frequencyRange, 12));
    scpi = scpi.arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}
double VnaLinearSweep::spacing_Hz() {
    QString scpi = ":SENS%1:SWE:STEP?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaLinearSweep::setSpacing(double frequencySpacing, SiPrefix prefix) {
    QString scpi = ":SENS%1:SWE:STEP %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(formatDouble(frequencySpacing, 12));
    scpi = scpi.arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}
QRowVector VnaLinearSweep::frequencies_Hz() {
    QString scpi = ":CALC%1:DATA:STIM?\n";
    scpi = scpi.arg(_channelIndex);
    uint bufferSize = frequencyBufferSize(points());
    return(_vna->queryVector(scpi, bufferSize));
}
double VnaLinearSweep::power_dBm() {
    QString scpi = ":SOUR%1:POW?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaLinearSweep::setPower(double power_dBm) {
    QString scpi = ":SOUR%1:POW %2\n";
    scpi = scpi.arg(_channelIndex).arg(power_dBm);
    _vna->write(scpi);
}
double VnaLinearSweep::ifBandwidth_Hz() {
    QString scpi = QString("SENS%1:BAND?\n").arg(_channelIndex);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaLinearSweep::setIfbandwidth(double bandwidth, SiPrefix prefix) {
    QString scpi = "SENS%1:BAND %2%3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(bandwidth);
    scpi = scpi.arg(toString(prefix, Units::Hertz));
    _vna->write(scpi);
}

void VnaLinearSweep::createHarmonicGrid(double stopFrequency_Hz, double spacing_Hz) {
    setStart(_vna->properties().minimumFrequency_Hz());
    setStop(stopFrequency_Hz);
    setSpacing(spacing_Hz);

    QString scpi = ":CALC%1:TRAN:TIME:LPAS KSD\n";
    scpi = scpi.arg(_channelIndex);
    _vna->write(scpi);
}
void VnaLinearSweep::createHarmonicGrid(double stopFrequency_Hz, uint points) {
    setStart(_vna->properties().minimumFrequency_Hz());
    setStop(stopFrequency_Hz);
    setPoints(points);

    QString scpi = ":CALC%1:TRAN:TIME:KFST KFST\n";
    scpi = scpi.arg(_channelIndex);
    _vna->write(scpi);
}

QVector<uint> VnaLinearSweep::sParameterGroup() {
    QString scpi = ":CALC%1:PAR:DEF:SGR?\n";
    scpi = scpi.arg(_channelIndex);
    QString result = _vna->query(scpi).trimmed();
    if (result == "NONE")
        return(QVector<uint>());
    else
        return(parseUints(result, ","));
}
void VnaLinearSweep::setSParameterGroup(QVector<uint> ports) {
    if (ports.size() <= 0)
        return;

    qSort(ports);
    QString group = toString(ports, ",");
    QString scpi = ":CALC%1:PAR:DEF:SGR %2\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(group);
    _vna->write(scpi);
}
void VnaLinearSweep::clearSParameterGroup() {
    QString scpi = ":CALC%1:PAR:DEL:SGR\n";
    scpi = scpi.arg(_channelIndex);
    _vna->write(scpi);
}
ComplexMatrix3D VnaLinearSweep::readSParameterGroup() {
    QString scpi = ":CALC%1:DATA:SGR? SDAT\n";
    scpi = scpi.arg(_channelIndex);

    ComplexMatrix3D sParameters;
    uint ports = sParameterGroup().size();
    uint points = this->points();
    if (ports <= 0)
        return(sParameters);
    uint bufferSize = dataBufferSize(ports, points);

    ComplexRowVector data = _vna->queryComplexVector(scpi, bufferSize);
    return(toComplexMatrix3D(data, points, ports, ports));
}

bool VnaLinearSweep::isAutoSweepTimeOn() {
    QString scpi = ":SENS%1:SWE:TIME:AUTO?\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed() == "1");
}
bool VnaLinearSweep::isAutoSweepTimeOff() {
    return !isAutoSweepTimeOn();
}
void VnaLinearSweep::autoSweepTimeOn(bool isOn) {
    QString scpi = ":SENS%1:SWE:TIME:AUTO %2\n";
    scpi = scpi.arg(_channelIndex);
    if (isOn)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
void VnaLinearSweep::autoSweepTimeOff(bool isOff) {
    autoSweepTimeOn(!isOff);
}

uint VnaLinearSweep::sweepTime_ms() {
    QString scpi = ":SENS%1:SWE:TIME?\n";
    scpi = scpi.arg(_channelIndex);
    double time = _vna->query(scpi).trimmed().toDouble();

    // Znb 20, 40 may report incorrect
    // sweep times. These instruments are
    // slower than the Znb 8!
    if (_vna->properties().isZnbFamily()
            && _vna->properties().maximumFrequency_Hz() >= 20.0E9)
    {
        time *= 2.0;
    }

    return uint(time * 1000.0);
}
void VnaLinearSweep::setSweepTime(uint time_ms) {
    QString scpi = ":SENS%1:SWE:TIME %2 ms\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(time_ms);

    autoSweepTimeOff();
    _vna->write(scpi);
}

NetworkData VnaLinearSweep::measure(uint port1) {
    QVector<uint> ports;
    ports << port1;
    return(measure(ports));
}
NetworkData VnaLinearSweep::measure(uint port1, uint port2) {
    QVector<uint> ports;
    ports << port1 << port2;
    return(measure(ports));
}
NetworkData VnaLinearSweep::measure(uint port1, uint port2, uint port3) {
    QVector<uint> ports;
    ports << port1 << port2 << port3;
    return(measure(ports));
}
NetworkData VnaLinearSweep::measure(uint port1, uint port2, uint port3, uint port4) {
    QVector<uint> ports;
    ports << port1 << port2 << port3 << port4;
    return(measure(ports));
}
NetworkData VnaLinearSweep::measure(QVector<uint> ports) {
    NetworkData network;

    if (ports.size() <= 0)
        return(network);
    if (_channel->isCwSweep() || _channel->isTimeSweep())
        return(network);

    setSParameterGroup(ports);
    network.setParameter(NetworkParameter::S);
    network.setReferenceImpedance(50);
    network.setXUnits(Units::Hertz);

    // Sweep
    bool isContinuousSweep = _channel->isContinuousSweep();
    if (isContinuousSweep)
        _channel->manualSweepOn();
    const uint timeout_ms = sweepTime_ms() * _channel->sweepCount();
    _channel->startSweep();
    _vna->pause(timeout_ms);

    // Get data
    network.setData(frequencies_Hz(), readSParameterGroup());

    // Return
    if (isContinuousSweep)
        _channel->continuousSweepOn();
    return(network);
}

bool VnaLinearSweep::saveSnp(QString filePathName, uint port1, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    return(saveSnp(filePathName, ports, format));
}
bool VnaLinearSweep::saveSnp(QString filePathName, uint port1, uint port2, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    ports << port2;
    return(saveSnp(filePathName, ports, format));
}
bool VnaLinearSweep::saveSnp(QString filePathName, uint port1, uint port2, uint port3, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    ports << port2;
    ports << port3;
    return(saveSnp(filePathName, ports, format));
}
bool VnaLinearSweep::saveSnp(QString filePathName, uint port1, uint port2, uint port3, uint port4, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    ports << port2;
    ports << port3;
    ports << port4;
    return(saveSnp(filePathName, ports, format));
}
bool VnaLinearSweep::saveSnp(QString filePathName, QVector<uint> ports, ComplexFormat format) {
    QString extension = ".s%1p";
    extension = extension.arg(ports.size());
    if (filePathName.endsWith(extension, Qt::CaseInsensitive) == false)
        filePathName += extension;

    QString scpi = ":MMEM:STOR:TRAC:PORT %1,\'%2\',%3,%4\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(filePathName);
    scpi = scpi.arg(toScpi(format));
    scpi = scpi.arg(toString(ports, ","));

    _vna->write(scpi);
    _vna->pause();
    return(_vna->fileSystem().isFile(filePathName));
}

// measureToSnp
bool VnaLinearSweep::measureToSnp(QString filePathName, uint port1, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    return(measureToSnp(filePathName, ports, format));
}
bool VnaLinearSweep::measureToSnp(QString filePathName, uint port1, uint port2, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    ports << port2;
    return(measureToSnp(filePathName, ports, format));
}
bool VnaLinearSweep::measureToSnp(QString filePathName, uint port1, uint port2, uint port3, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    ports << port2;
    ports << port3;
    return(measureToSnp(filePathName, ports, format));
}
bool VnaLinearSweep::measureToSnp(QString filePathName, uint port1, uint port2, uint port3, uint port4, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    ports << port2;
    ports << port3;
    ports << port4;
    return(measureToSnp(filePathName, ports, format));
}
bool VnaLinearSweep::measureToSnp(QString filePathName, QVector<uint> ports, ComplexFormat format) {
    if (ports.size() <= 0)
        return false;
    if (_channel->isCwSweep() || _channel->isTimeSweep())
        return false;

    // Sweep
    bool isContinuousSweep = _channel->isContinuousSweep();
    if (isContinuousSweep)
        _channel->manualSweepOn();
    const uint timeout_ms = sweepTime_ms() * _channel->sweepCount();
    setSParameterGroup(ports);
    _channel->startSweep();
    _vna->pause(timeout_ms);

    // File extention
    QString extension = ".s%1p";
    extension = extension.arg(ports.size());
    if (filePathName.endsWith(extension, Qt::CaseInsensitive) == false)
        filePathName += extension;

    // Save
    QString scpi = ":MMEM:STOR:TRAC:PORT %1,\'%2\',%3,%4\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(filePathName);
    scpi = scpi.arg(toScpi(format));
    scpi = scpi.arg(toString(ports, ","));
    _vna->write(scpi);
    _vna->pause(5000);

    // Return
    if (isContinuousSweep)
        _channel->continuousSweepOn();
    return(_vna->fileSystem().isFile(filePathName));
}

// measureToSnpLocally
bool VnaLinearSweep::measureToSnpLocally(QString filePathName, uint port1, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    return(measureToSnpLocally(filePathName, ports, format));
}
bool VnaLinearSweep::measureToSnpLocally(QString filePathName, uint port1, uint port2, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    ports << port2;
    return(measureToSnpLocally(filePathName, ports, format));
}
bool VnaLinearSweep::measureToSnpLocally(QString filePathName, uint port1, uint port2, uint port3, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    ports << port2;
    ports << port3;
    return(measureToSnpLocally(filePathName, ports, format));
}
bool VnaLinearSweep::measureToSnpLocally(QString filePathName, uint port1, uint port2, uint port3, uint port4, ComplexFormat format) {
    QVector<uint> ports;
    ports << port1;
    ports << port2;
    ports << port3;
    ports << port4;
    return(measureToSnpLocally(filePathName, ports, format));
}
bool VnaLinearSweep::measureToSnpLocally(QString filePathName, QVector<uint> ports, ComplexFormat format) {
    // Check file extention
    QString extension = ".s%1p";
    extension = extension.arg(ports.size());
    if (filePathName.endsWith(extension, Qt::CaseInsensitive) == false)
        filePathName += extension;

    // Measure, save temp.snp to VNA
    QString temp = uniqueAlphanumericString() + extension;
    if (!measureToSnp(temp, ports, format))
        return false;

    // Transfer file
    _vna->fileSystem().downloadFile(temp, filePathName);
    _vna->fileSystem().deleteFile(temp);
    _vna->pause();
    return true;
}

void VnaLinearSweep::operator=(VnaLinearSweep const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _channel.reset(new VnaChannel(*other._channel.data()));
        _channelIndex = _channel->index();
    }
    else {
        _vna = placeholder.data();
        _channel.reset(new VnaChannel());
        _channelIndex = 0;
    }
}

//void VnaLinearSweep::moveToThread(QThread *thread) {
//    QObject::moveToThread(thread);
//    if (_channel.isNull() == false)
//        _channel->moveToThread(thread);
//}

// Private
bool VnaLinearSweep::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
uint VnaLinearSweep::frequencyBufferSize(uint points) {
    const uint HEADER_MAX_SIZE = 11;
    const uint SIZE_PER_POINT = 8;
    const uint INSURANCE = 20;
    return(HEADER_MAX_SIZE + SIZE_PER_POINT * points + INSURANCE);
}
uint VnaLinearSweep::dataBufferSize(uint ports, uint points) {
    const uint HEADER_MAX_SIZE = 11;
    const uint SIZE_PER_POINT = 16;
    const uint INSURANCE = 20;
    return(HEADER_MAX_SIZE + SIZE_PER_POINT*points*pow(double(ports), 2.0) + INSURANCE);
}
QString VnaLinearSweep::toScpi(ComplexFormat format) {
    switch(format) {
    case ComplexFormat::RealImaginary: return("COMP");
    case ComplexFormat::MagnitudeDegrees: return("LINP");
    case ComplexFormat::DecibelDegrees: return("LOGP");
    default: return("COMP");
    }
}
