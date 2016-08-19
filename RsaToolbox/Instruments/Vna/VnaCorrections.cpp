

// RsaToolbox includes
#include "General.h"
#include "Vna.h"
#include "VnaChannel.h"
#include "VnaCorrections.h"
#include "VnaScpi.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaCorrections
 * \ingroup VnaGroup
 * \brief The \c %VnaCorrections class
 * controls and queries the measurement
 * corrections applied to a channel.
 */

VnaCorrections::VnaCorrections(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _channel.reset(new VnaChannel());
    _channelIndex = 0;
}

VnaCorrections::VnaCorrections(VnaCorrections &other)
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
VnaCorrections::VnaCorrections(Vna *vna, VnaChannel *channel, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(*channel));
    _channelIndex = channel->index();
}

VnaCorrections::VnaCorrections(Vna *vna, uint channelIndex, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _channel.reset(new VnaChannel(vna, channelIndex, this));
    _channelIndex = channelIndex;
}
VnaCorrections::~VnaCorrections() {

}

// Use corrections
bool VnaCorrections::isOn() {
    CorrectionState state = correctionState();
    if (state == APPLIED_CORRECTIONS)
        return(true);
    if (state == INTERPOLATED_CORRECTIONS)
        return(true);
    // else
    return(false);
}
bool VnaCorrections::isOff() {
    return(!isOn());
}
bool VnaCorrections::isPresent() {
    return(correctionState() != NO_CORRECTIONS);
}
bool VnaCorrections::isNotPresent() {
    return(!isPresent());
}
bool VnaCorrections::isInterpolated() {
    return(correctionState() == INTERPOLATED_CORRECTIONS);
}
bool VnaCorrections::isNotInterpolated() {
    return(!isInterpolated());
}
void VnaCorrections::on(bool isOn) {
    QString scpi = ":SENS%1:CORR %2\n";
    scpi = scpi.arg(_channelIndex);
    if (isOn)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
void VnaCorrections::off(bool isOff) {
    on(!isOff);
}
QString VnaCorrections::calGroup() {
    QString scpi = ":MMEM:LOAD:CORR? %1\n";
    scpi = scpi.arg(_channelIndex);
    return(_vna->query(scpi).trimmed().remove("\'"));
}
void VnaCorrections::setCalGroup(QString calGroup) {
    if (calGroup.contains(".cal", Qt::CaseInsensitive) == false)
        calGroup = calGroup + ".cal";
    QString scpi = ":MMEM:LOAD:CORR %1,\'%2\'\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(calGroup);
    _vna->write(scpi);
}
void VnaCorrections::saveToCalGroup(QString calGroup) {
    if (calGroup.contains(".cal", Qt::CaseInsensitive) == false)
        calGroup = calGroup + ".cal";
    QString scpi = ":MMEM:STOR:CORR %1,\'%2\'\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(calGroup);
    _vna->write(scpi);
}
void VnaCorrections::dissolveCalGroupLink() {
    QString scpi = ":MMEM:LOAD:CORR:RES %1\n";
    scpi = scpi.arg(_channelIndex);
    _vna->write(scpi);
}
void VnaCorrections::clear() {
//    _vna->fileSystem().uploadFile();
//    _vna->importCalGroup("DELETE");
//    setCalGroup("DELETE");
//    dissolveCalGroupLink();
//    _vna->deleteCalGroup("DELETE");
} //?


// Properties
VnaCalibrate::CalType VnaCorrections::calibrationType() {
    QString scpi = ":SENS%1:CORR:DATA:PAR? %3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg("TYPE");
    QString result = _vna->query(scpi).trimmed();
    return(VnaScpi::toCalType(result));

}
bool VnaCorrections::isFull12TermErrorCorrection() {
    return VnaScpi::isFull12TermErrorCorrection(calibrationType());
}
bool VnaCorrections::isSMARTerCal() {
    return VnaScpi::isSMARTerCal(calibrationType());
}
VnaChannel::SweepType VnaCorrections::sweepType() {
    QString scpi = ":SENS%1:CORR:DATA:PAR? %3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg("STYP");
    QString result = _vna->query(scpi).trimmed();
    return(VnaScpi::toSweepType(result));
}
QVector<uint> VnaCorrections::ports() {
    QString scpi = ":SENS%1:CORR:DATA:PAR? %3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg("PORT");
    QString result = _vna->query(scpi).trimmed();
    return(parseUints(result, ","));
}
uint VnaCorrections::points() {
    QString scpi = ":SENS%1:CORR:DATA:PAR? %3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg("POIN");
    return(_vna->query(scpi).trimmed().toUInt());
}
double VnaCorrections::startFrequency_Hz() {
    QString scpi = ":SENS%1:CORR:DATA:PAR? %3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg("STAR");
    return(_vna->query(scpi).trimmed().toDouble());
}
double VnaCorrections::stopFrequency_Hz() {
    QString scpi = ":SENS%1:CORR:DATA:PAR? %3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg("STOP");
    return(_vna->query(scpi).trimmed().toDouble());
}
QRowVector VnaCorrections::frequencies_Hz() {
    QString scpi = ":SENS%1:CORR:STIM?\n";
    scpi = scpi.arg(_channelIndex);
    return _vna->queryVector(scpi, bufferSize());
}
double VnaCorrections::power_dBm() {
    QString scpi = ":SENS%1:CORR:DATA:PAR? %3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg("SPOW");
    return(_vna->query(scpi).trimmed().toDouble());
}

// Physical setup
bool VnaCorrections::isVnaPort(uint testPort) {
    return testPortToVnaMap().contains(testPort);
}
uint VnaCorrections::vnaPort(uint testPort) {
    return testPortToVnaMap().value(testPort, 0);
}
PortMap VnaCorrections::testPortToVnaMap() {
    // For Zva, test port == physical Vna port?
    if (_vna->properties().isZvaFamily()) {
        return _vna->testPortToVnaMap();
    }


    QString scpi = ":SENS%1:CORR:DATA:PAR? %3\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg("TVNA");
    QString result = _vna->query(scpi).trimmed();
    return RsaToolbox::parseMap<uint,uint>(result, ",");
}

bool VnaCorrections::areSwitchMatrices() {
    if (_vna->properties().isZvaFamily())
        return false;

    _vna->isError();
    _vna->clearStatus();
    bool displayError = _vna->settings().isErrorDisplayOn();
    _vna->settings().errorDisplayOff();

    const PortMap map = switchMatrixToVnaPortMap(1);
    if (!map.isEmpty() && !_vna->isError()) {
        _vna->clearStatus();
        _vna->settings().errorDisplayOn(displayError);
        return true;
    }
    else {
        _vna->settings().errorDisplayOn(displayError);
        return false;
    }
}
uint VnaCorrections::switchMatrices() {
    if (_vna->properties().isZvaFamily())
        return 0;

    _vna->isError();
    _vna->clearStatus();
    bool displayError = _vna->settings().isErrorDisplayOn();
    _vna->settings().errorDisplayOff();

    uint i = 0;
    PortMap map = switchMatrixToVnaPortMap(i+1);
    while (!_vna->isError() && !map.isEmpty()) {
        i++;
        map = switchMatrixToVnaPortMap(i+1);
    }

    _vna->clearStatus();
    _vna->settings().errorDisplayOn(displayError);
    return i;
}
bool VnaCorrections::isSwitchMatrixPort(uint testPort) {
    uint matrices = switchMatrices();
    for (uint i = 1; i <= matrices; i++) {
        if (testPortToSwitchMatrixMap(i).contains(testPort))
            return true;
    }

    // Else
    return false;
}
uint VnaCorrections::switchMatrix(uint testPort) {
    uint matrices = switchMatrices();
    for (uint i = 1; i <= matrices; i++) {
        if (testPortToSwitchMatrixMap(i).contains(testPort))
            return i;
    }

    // Else
    return 0;
}
PortMap VnaCorrections::switchMatrixToVnaPortMap(uint switchMatrix) {
    if (_vna->properties().isZvaFamily())
        return PortMap();

    QString scpi = ":SENS%1:CORR:DATA:PAR? %3,%4\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg("MVNA");
    scpi = scpi.arg(switchMatrix);
    QString result = _vna->query(scpi).trimmed();
    return RsaToolbox::parseMap<uint,uint>(result, ",");
}
PortMap VnaCorrections::testPortToSwitchMatrixMap(uint switchMatrix) {
    if (_vna->properties().isZvaFamily())
        return PortMap();

    QString scpi = ":SENS%1:CORR:DATA:PAR? %3,%4\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg("MTES");
    scpi = scpi.arg(switchMatrix);
    QString result = _vna->query(scpi).trimmed();
    return RsaToolbox::parseMap<uint,uint>(result, ",");
}

void VnaCorrections::loadDefaultCorrections() {
    QString scpi = ":SENS%1:CORR:COLL:SAVE:SEL:DEF\n";
    scpi = scpi.arg(_channelIndex);
    _vna->write(scpi);
}

ComplexRowVector VnaCorrections::directivity(uint outputPort, uint inputPort) {
    return(errorValues("DIRECTIVITY", outputPort, inputPort));
}
void VnaCorrections::setDirectivity(ComplexRowVector corrections, uint outputPort, uint inputPort) {
    setErrorValues("DIRECTIVITY", corrections, outputPort, inputPort);
}
ComplexRowVector VnaCorrections::sourceMatch(uint outputPort, uint inputPort) {
    return(errorValues("SRCMATCH", outputPort, inputPort));
}
void VnaCorrections::setSourceMatch(ComplexRowVector corrections, uint outputPort, uint inputPort) {
    setErrorValues("SRCMATCH", corrections, outputPort, inputPort);
}
ComplexRowVector VnaCorrections::reflectionTracking(uint outputPort, uint inputPort) {
    return(errorValues("REFLTRACK", outputPort, inputPort));
}
void VnaCorrections::setReflectionTracking(ComplexRowVector corrections, uint outputPort, uint inputPort) {
    setErrorValues("REFLTRACK", corrections, outputPort, inputPort);
}
ComplexRowVector VnaCorrections::loadMatch(uint outputPort, uint inputPort) {
    return(errorValues("LOADMATCH", outputPort, inputPort));
}
void VnaCorrections::setLoadMatch(ComplexRowVector corrections, uint outputPort, uint inputPort) {
    setErrorValues("LOADMATCH", corrections, outputPort, inputPort);
}
ComplexRowVector VnaCorrections::transmissionTracking(uint outputPort, uint inputPort) {
    return(errorValues("TRANSTRACK", outputPort, inputPort));
}
void VnaCorrections::setTransmissionTracking(ComplexRowVector corrections, uint outputPort, uint inputPort) {
    setErrorValues("TRANSTRACK", corrections, outputPort, inputPort);
}

// With switch matrix paths
ComplexRowVector VnaCorrections::directivity(uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    return errorValues("DIRECTIVITY", outputTestPort, vnaLoadPort, inputTestPort, vnaGeneratorPort);
}
ComplexRowVector VnaCorrections::sourceMatch(uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    return errorValues("SRCMATCH", outputTestPort, vnaLoadPort, inputTestPort, vnaGeneratorPort);
}
ComplexRowVector VnaCorrections::reflectionTracking(uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    return errorValues("REFLTRACK", outputTestPort, vnaLoadPort, inputTestPort, vnaGeneratorPort);
}
ComplexRowVector VnaCorrections::loadMatch(uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    return errorValues("LOADMATCH", outputTestPort, vnaLoadPort, inputTestPort, vnaGeneratorPort);
}
ComplexRowVector VnaCorrections::transmissionTracking(uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    return errorValues("TRANSTRACK", outputTestPort, vnaLoadPort, inputTestPort, vnaGeneratorPort);
}

void VnaCorrections::setDirectivity(ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    setErrorValues("DIRECTIVITY", corrections, outputTestPort, vnaLoadPort, inputTestPort, vnaGeneratorPort);
}
void VnaCorrections::setSourceMatch(ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    setErrorValues("SRCMATCH", corrections, outputTestPort, vnaLoadPort, inputTestPort, vnaGeneratorPort);
}
void VnaCorrections::setReflectionTracking(ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    setErrorValues("REFLTRACK", corrections, outputTestPort, vnaLoadPort, inputTestPort, vnaGeneratorPort);
}
void VnaCorrections::setLoadMatch(ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    setErrorValues("LOADMATCH", corrections, outputTestPort, vnaLoadPort, inputTestPort, vnaGeneratorPort);
}
void VnaCorrections::setTransmissionTracking(ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    setErrorValues("TRANSTRACK", corrections, outputTestPort, vnaLoadPort, inputTestPort, vnaGeneratorPort);
}

void VnaCorrections::operator=(VnaCorrections const &other) {
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

// Private
bool VnaCorrections::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
VnaCorrections::CorrectionState VnaCorrections::correctionState() {
    QString scpi = ":SENS%1:CORR:SST?\n";
    scpi = scpi.arg(_channelIndex);

    QString result = _vna->query(scpi).trimmed().remove("\'");
    return(toCorrectionState(result));
}
VnaCorrections::CorrectionState VnaCorrections::toCorrectionState(QString scpi) {
    if (scpi == "CAL")
        return(APPLIED_CORRECTIONS);
    if (scpi == "CAI")
        return(INTERPOLATED_CORRECTIONS);
    if (scpi == "CAL OFF")
        return(DISABLED_CORRECTIONS);
    if (scpi.isEmpty())
        return(NO_CORRECTIONS);
    // Default
    return(NO_CORRECTIONS);
}
ComplexRowVector VnaCorrections::errorValues(QString term, uint outputPort, uint inputPort) {
    QString scpi = ":SENS%1:CORR:CDAT? \'%2\',%3,%4\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(term);
    scpi = scpi.arg(inputPort);
    scpi = scpi.arg(outputPort);
    return(_vna->queryComplexVector(scpi, complexBufferSize()));
}
ComplexRowVector VnaCorrections::errorValues(QString term, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    QString scpi = ":SENS%1:CORR:SMAT:CDAT? \'%2\',%3,%4,%5,%6\n";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(term);
    scpi = scpi.arg(inputTestPort);
    scpi = scpi.arg(outputTestPort);
    scpi = scpi.arg(vnaGeneratorPort);
    scpi = scpi.arg(vnaLoadPort);
    return _vna->queryComplexVector(scpi, complexBufferSize());
}

void VnaCorrections::setErrorValues(QString term, ComplexRowVector corrections, uint outputPort, uint inputPort) {
    QString scpi = ":SENS%1:CORR:CDAT \'%2\',%3,%4, ";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(term);
    scpi = scpi.arg(inputPort);
    scpi = scpi.arg(outputPort);

    bool isReadAscii = _vna->settings().isReadAsciiFormat();
    bool isRead32Bit = _vna->settings().isRead32BitBinaryFormat();

    _vna->settings().setRead64BitBinaryFormat();
    _vna->binaryWrite(scpi.toUtf8() + toBlockDataFormat(corrections) + "\n");

    if (isReadAscii)
        _vna->settings().setReadAsciiFormat();
    if (isRead32Bit)
        _vna->settings().setRead32BitBinaryFormat();
}
void VnaCorrections::setErrorValues(QString term, ComplexRowVector corrections, uint outputTestPort, uint vnaLoadPort, uint inputTestPort, uint vnaGeneratorPort) {
    QString scpi = ":SENS%1:CORR:SMAT:CDAT \'%2\',%3,%4,%5,%6, ";
    scpi = scpi.arg(_channelIndex);
    scpi = scpi.arg(term);
    scpi = scpi.arg(inputTestPort);
    scpi = scpi.arg(outputTestPort);
    scpi = scpi.arg(vnaGeneratorPort);
    scpi = scpi.arg(vnaLoadPort);

    bool isReadAscii = _vna->settings().isReadAsciiFormat();
    bool isRead32Bit = _vna->settings().isRead32BitBinaryFormat();

    _vna->settings().setRead64BitBinaryFormat();
    _vna->binaryWrite(scpi.toUtf8() + toBlockDataFormat(corrections) + "\n");

    if (isReadAscii)
        _vna->settings().setReadAsciiFormat();
    if (isRead32Bit)
        _vna->settings().setRead32BitBinaryFormat();
}

uint VnaCorrections::bufferSize() {
    const uint HEADER_MAX_SIZE = 11;
    const uint SIZE_PER_POINT = 8;
    const uint INSURANCE = 20;
    return(HEADER_MAX_SIZE + SIZE_PER_POINT * points() + INSURANCE);
}
uint VnaCorrections::complexBufferSize() {
    const uint HEADER_MAX_SIZE = 11;
    const uint SIZE_PER_POINT = 16;
    const uint INSURANCE = 20;
    return(HEADER_MAX_SIZE + SIZE_PER_POINT * points() + INSURANCE);
}
