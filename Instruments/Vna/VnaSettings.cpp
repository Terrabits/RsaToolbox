#include <QDebug>

// RsaToolbox includes
#include "General.h"
#include "VnaSettings.h"
#include "Vna.h"
using namespace RsaToolbox;

/*!
 * \class RsaToolbox::VnaSettings
 * \ingroup VnaGroup
 * \brief The \c %VnaSettings class
 * configures and queries the global
 * settings on a Rohde \& Schwarz VNA.
 */

VnaSettings::VnaSettings(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
}

VnaSettings::VnaSettings(VnaSettings &other)
{
    this->_vna = other._vna;
}

VnaSettings::VnaSettings(Vna *vna, QObject *parent) :
    QObject(parent)
{
    this->_vna = vna;
}
VnaSettings::~VnaSettings() {

}

void VnaSettings::setIdString(QString idString) {
    if (_vna->properties().isZvaFamily()) {
        if (_vna->isLogConnected())
            *_vna->log()
                << "WARNING: setIdString() not available on ZVA-family instrument.\n\n";
        return;
    }

    QString scpi =
            QString(":SYST:IDEN \'%1\'\n").arg(idString);
    _vna->write(scpi);
}
void VnaSettings::resetIdString() {
    if (_vna->properties().isZvaFamily()) {
        if (_vna->isLogConnected())
            *_vna->log()
                << "WARNING: resetIdString() not available on ZVA-family instrument.\n\n";
        return;
    }

    _vna->write(":SYST:IDEN:FACT\n");
}
void VnaSettings::setOptionsString(QString options) {
    if (_vna->properties().isZvaFamily()) {
        if (_vna->isLogConnected())
            *_vna->log()
                << "WARNING: setOptionsString() not available on ZVA-family instrument.\n\n";
        return;
    }

    QString scpi =
            QString(":SYST:OPT \'%1\'\n").arg(options);
    _vna->write(scpi);
}
void VnaSettings::resetOptionsString() {
    if (_vna->properties().isZvaFamily()) {
        if (_vna->isLogConnected())
            *_vna->log()
                << "WARNING: resetOptionsString() not available on ZVA-family instrument.\n\n";
        return;
    }

    _vna->write(":SYST:OPT:FACT\n");
}

ImageFormat VnaSettings::imageFormat() {
    QString scpi = ":HCOP:DEV:LANG?\n";
    QString result = _vna->query(scpi);
    return toImageFormat(result);
}
void VnaSettings::setImageFormat(ImageFormat format) {
    QString scpi = ":HCOP:DEV:LANG %1\n";
    scpi = scpi.arg(toString(format).toUpper());
    _vna->write(scpi);
}

//QString VnaSettings::fileDestination() {
//    QString scpi = ":\n";
//}
void VnaSettings::setFileDestination(const QString &filename) {
    QString scpi = ":MMEM:NAME \'%1\'\n";
    scpi = scpi.arg(filename);
    _vna->write(scpi);
    _vna->write(":HCOP:DEST \'MMEM\'");
}

bool VnaSettings::isRead32BitBinaryFormat() {
    QStringList result
            = _vna->query(":FORM?\n").trimmed().toUpper().split(",");
    if (result.first() == "REAL") {
        uint bit = result.last().toUInt();
        return(bit == uint(32));
    }
    // else
    return(false);
}
void VnaSettings::setRead32BitBinaryFormat() {
    _vna->write(":FORM REAL,32\n");
}
bool VnaSettings::isRead64BitBinaryFormat() {
    QStringList result
            = _vna->query(":FORM?\n").trimmed().toUpper().split(",");
    if (result.first() == "REAL") {
        uint bit = result.last().toUInt();
        return(bit == uint(64));
    }
    // else
    return(false);
}
void VnaSettings::setRead64BitBinaryFormat() {
    _vna->write(":FORM REAL,64\n");
}
bool VnaSettings::isReadAsciiFormat() {
    QStringList result
            = _vna->query(":FORM?\n").trimmed().toUpper().split(",");
    return(result.first() == "ASC");
}
bool VnaSettings::isLittleEndian() {
    return(_vna->query(":FORM:BORD?\n").trimmed().toUpper() == "SWAP");
}
bool VnaSettings::isBigEndian() {
    return(_vna->query(":FORM:BORD?\n").trimmed().toUpper() == "NORM");
}
void VnaSettings::setReadAsciiFormat() {
    _vna->write(":FORM ASC\n");
}
void VnaSettings::setLittleEndian() {
    _vna->write(":FORM:BORD SWAP\n");
}
void VnaSettings::setBigEndian() {
    _vna->write(":FORM:BORD NORM\n");
}

bool VnaSettings::isEmulationOn() {
    return(emulationMode() != EmulationMode::Off);
}
bool VnaSettings::isEmulationMode(EmulationMode mode) {
    return(emulationMode() == mode);
}
bool VnaSettings::isEmulationOff() {
    return(emulationMode() == EmulationMode::Off);
}
VnaSettings::EmulationMode VnaSettings::emulationMode() {
    return(toVnaEmulationMode(
               _vna->query(":SYST:LANG?\n").trimmed().remove("\'")));
}
void VnaSettings::setEmulationMode(EmulationMode mode) {
    _vna->write(
          QString(":SYST:LANG \'%1\'\n").arg(toScpi(mode)));
}
void VnaSettings::setEmulationOff() {
    setEmulationMode(EmulationMode::Off);
}

bool VnaSettings::isDisplayOn() {
    return(_vna->query(":SYST:DISP:UPD?\n").trimmed()
           == "1");
}
bool VnaSettings::isDisplayOff() {
    return(!isDisplayOn());
}

void VnaSettings::displayOn(bool isOn) {
    // Bug in ZNB firmware:
    // SYST:DISP:UPD 1 is interepreted the
    // same as
    // SYST:DISP:UPD ONCE
    // Oooooops!

    if (isOn)
        _vna->write(":SYST:DISP:UPD ON\n");
    else
        _vna->write(":SYST:DISP:UPD OFF\n");
}
void VnaSettings::displayOff(bool isOff) {
    displayOn(!isOff);
}
void VnaSettings::manualDisplayMode() {
    displayOff();
}
void VnaSettings::updateDisplay() {
    _vna->write(":SYST:DISP:UPD ONCE\n");
}

bool VnaSettings::isErrorDisplayOn() {
    return(_vna->query(":SYST:ERR:DISP?\n").trimmed()
           == "1");
}
bool VnaSettings::isErrorDisplayOff() {
    return(!isErrorDisplayOn());
}
void VnaSettings::errorDisplayOn(bool isOn) {
    if (isOn)
            _vna->write(":SYST:ERR:DISP 1\n");
        else
            _vna->write(":SYST:ERR:DISP 0\n");
}
void VnaSettings::errorDisplayOff(bool isOff) {
    errorDisplayOn(!isOff);
}

bool VnaSettings::isColorScheme(ColorScheme scheme) {
    return(colorScheme() == scheme);
}
VnaSettings::ColorScheme VnaSettings::colorScheme() {
    QString scpi = _vna->query(":SYST:DISP:COL?\n").trimmed();
    return(toColorScheme(scpi));
}
void VnaSettings::setColorScheme(ColorScheme scheme) {
    QString scpi
            = QString(":SYST:DISP:COL %1\n").arg(
                toScpi(scheme));
    _vna->write(scpi);
}
void VnaSettings::setDefaultColorScheme() {
    setColorScheme(ColorScheme::Dark);
}

bool VnaSettings::isFontSize(uint size_percent) {
    return(fontSize_percent() == size_percent);
}
uint VnaSettings::fontSize_percent() {
    return(QString(_vna->query(":DISP:RFS?\n")).trimmed().toInt());
}
void VnaSettings::setFontSize(uint size_percent) {
    QString scpi = QString(":DISP:RFS %1\n").arg(size_percent);
    _vna->write(scpi);
}
void VnaSettings::resetFontSize() {
    setFontSize(100);
}

bool VnaSettings::isUserPresetOn() {
    return(_vna->query(":SYST:PRES:USER?\n").trimmed() == "1");
}
bool VnaSettings::isUserPresetOff() {
    return(!isUserPresetOn());
}
void VnaSettings::userPresetOn(bool isOn) {
    if (isOn)
        _vna->write(":SYST:PRES:USER 1\n");
    else
        _vna->write(":SYST:PRES:USER 0\n");
}
void VnaSettings::userPresetOff(bool isOff) {
    userPresetOn(!isOff);
}
QString VnaSettings::userPreset() {
    ;
    return(_vna->query(":SYST:PRES:USER:NAME?\n").trimmed().remove("\'"));
}
void VnaSettings::setUserPreset(QString setFilePath) {
    QString scpi = ":SYST:PRES:USER:NAME \'%1\'\n";
    scpi = scpi.arg(setFilePath);
    _vna->write(scpi);
}
bool VnaSettings::isUserPresetMappedToRst() {
    return(_vna->query(":SYST:PRES:REM?\n").trimmed() == "1");
}
void VnaSettings::mapUserPresetToRst(bool isMapped) {
    if (isMapped)
        _vna->write(":SYST:PRES:REM 1\n");
    else
        _vna->write(":SYST:PRES:REM 0\n");
}

bool VnaSettings::isCalibrationPresetOn() {
    if (_vna->properties().isZvaFamily()) {
        *_vna->log()
                << "WARNING: setCalibrationPreset() not available on ZVA-family instrument.\n\n";
        return(false);
    }

    return(calibrationPreset().isEmpty() == false);
}
bool VnaSettings::isCalibrationPresetOff() {
    return(!isCalibrationPresetOn());
}
void VnaSettings::calibrationPresetOff() {
    setCalibrationPreset("");
}
QString VnaSettings::calibrationPreset() {
    if (_vna->properties().isZvaFamily()) {
        *_vna->log()
                << "WARNING: setCalibrationPreset() not available on ZVA-family instrument.\n\n";
        return(QString());
    }

    return(_vna->query(":SYST:PRES:USER:CAL?\n").trimmed().remove("\'"));
}
void VnaSettings::setCalibrationPreset(QString calibrationFilePath) {
    if (_vna->properties().isZvaFamily()) {
        *_vna->log()
                << "WARNING: setCalibrationPreset() not available on ZVA-family instrument.\n\n";
        return;
    }

    QString scpi = ":SYST:PRES:USER:CAL \'%1\'\n";
    scpi = scpi.arg(calibrationFilePath);
    _vna->write(scpi);
}

bool VnaSettings::isPortPowerLimitOn(uint physicalPort) {
    QString scpi = ":SOUR:POW%1:LLIM?\n";
    scpi = scpi.arg(physicalPort);
    return(_vna->query(scpi).trimmed() == "1");
}
bool VnaSettings::isPortPowerLimitOn() {
    QVector<uint> ports
            = range(uint(1), _vna->properties().physicalPorts());
    foreach (uint port, ports) {
        if (_vna->settings().isPortPowerLimitOn(port))
            return(true);
    }
    // else
    return(false);
}
bool VnaSettings::isPortPowerLimitOff() {
    return(!isPortPowerLimitOn());
}
bool VnaSettings::isPortPowerLimitOff(uint physicalPort) {
    return(!isPortPowerLimitOn(physicalPort));
}
void VnaSettings::portPowerLimitOn(uint physicalPort) {
    QString scpi = ":SOUR:POW%1:LLIM 1\n";
    scpi = scpi.arg(physicalPort);
    _vna->write(scpi);
}
void VnaSettings::portPowerLimitsOn(bool isOn) {
    QString scpi;
    if (isOn)
        scpi = ":SOUR:POW%1:LLIM 1\n";
    else
        scpi = ":SOUR:POW%1:LLIM 0\n";

    QVector<uint> ports
            = range(uint(1), _vna->properties().physicalPorts());
    foreach (uint port, ports)
        _vna->write(scpi.arg(port));
}
void VnaSettings::portPowerLimitOff(uint physicalPort) {
    QString scpi = ":SOUR:POW%1:LLIM 0\n";
    scpi = scpi.arg(physicalPort);
    _vna->write(scpi);
}
void VnaSettings::portPowerLimitsOff(bool isOff) {
    portPowerLimitsOn(!isOff);
}
double VnaSettings::portPowerLimit_dBm(uint physicalPort) {
    QString scpi = ":SOUR:POW%1:LLIM:VAL?\n";
    scpi = scpi.arg(physicalPort);
    return(_vna->query(scpi).trimmed().toDouble());
}
void VnaSettings::portPowerLimits(QVector<uint> &physicalPorts, QVector<double> limits_dBm) {
    Q_UNUSED(physicalPorts);
    Q_UNUSED(limits_dBm);
}
void VnaSettings::setPortPowerLimit(uint physicalPort, double limit_dBm) {
    QString scpi = ":SOUR:POW%1:LLIM:VAL %2\n";
    scpi = scpi.arg(physicalPort).arg(limit_dBm);
    _vna->write(scpi);
}
void VnaSettings::setPortPowerLimits(double limit_dBm) {
    QString scpi = QString(":SOUR:POW%2:LLIM:VAL %1\n");
    scpi = scpi.arg(limit_dBm);
    QVector<uint> ports = range(uint(1), _vna->properties().physicalPorts());
    foreach (uint port, ports)
        _vna->write(scpi.arg(port));
}

bool VnaSettings::isPowerReductionBetweenSweepsOn() {
    const QString scpi = ":SOUR:POW:RED?\n";
    return _vna->query(scpi).trimmed() == "1";
}
void VnaSettings::powerReductionBetweenSweepsOn(bool isOn) {
    QString scpi;
    if (isOn)
        scpi = ":SOUR:POW:RED 1\n";
    else
        scpi = ":SOUR:POW:RED 0\n";
    _vna->write(scpi);
}
void VnaSettings::powerReductionBetweenSweepsOff(bool isOff) {
    powerReductionBetweenSweepsOn(!isOff);
}

bool VnaSettings::isRfOutputPowerOn() {
    return(_vna->query(":OUTP?\n").trimmed()
           == "1");
}
bool VnaSettings::isRfOutputPowerOff() {
    return(!isRfOutputPowerOn());
}
void VnaSettings::rfOutputPowerOn(bool isOn) {
    if (isOn)
        _vna->write(":OUTP 1\n");
    else
        _vna->write(":OUTP 0\n");
}
void VnaSettings::rfOutputPowerOff(bool isOff) {
    rfOutputPowerOn(!isOff);
}

bool VnaSettings::isDynamicIfBandwidthOn() {
    if (_vna->properties().isZnbFamily()) {
        *_vna->log()
                << "WARNING: isDynamicIfBandwidthOn() not available on ZNB-family instrument.\n\n";
        return(false);
    }

    return(_vna->query(":BAND:DRED?\n").trimmed() == "1");
}
bool VnaSettings::isDynamicIfBandwidthOff() {
    return(!isDynamicIfBandwidthOn());
}
void VnaSettings::dynamicIfBandwidthOn(bool isOn) {
    if (_vna->properties().isZnbFamily()) {
        *_vna->log() << "WARNING: dynamicIfBandwidthOn() not available on ZNB-family instrument.\n\n";
        return;
    }

    if (isOn)
        _vna->write(":BAND:DRED 1\n");
    else
        _vna->write(":BAND:DRED 0\n");
}
void VnaSettings::dynamicIfBandwidthOff(bool isOff) {
    dynamicIfBandwidthOn(!isOff);
}

bool VnaSettings::isLowPowerAutoCalOn() {
    QString response
            = _vna->query(":SYST:COMM:RDEV:AKAL:PRED?\n");
    return(response.trimmed() == "1");
}
bool VnaSettings::isLowPowerAutoCalOff() {
    return(!isLowPowerAutoCalOn());
}
void VnaSettings::lowPowerAutoCalOn(bool isOn) {
    if (isOn)
        _vna->write(":SYST:COMM:RDEV:AKAL:PRED 1\n");
    else
        _vna->write(":SYST:COMM:RDEV:AKAL:PRED 0\n");
}
void VnaSettings::lowPowerAutoCalOff(bool isOff) {
    lowPowerAutoCalOn(!isOff);
}

bool VnaSettings::isRemoteLogOn() {
    return(_vna->query(":SYST:LOGG:REM?\n").trimmed() == "1");
}
bool VnaSettings::isRemoteLogOff() {
    return(!isRemoteLogOn());
}
void VnaSettings::remoteLogOn(bool isOn) {
    if (isOn)
        _vna->write(":SYST:LOGG:REM 1\n");
    else
        _vna->write(":SYST:LOGG:REM 0\n");
}
void VnaSettings::remoteLogOff(bool isOff) {
    remoteLogOn(!isOff);
}

void VnaSettings::servicePassword(const QString &password) {
    QString scpi = ":SYST:PASS \'%1\'\n";
    scpi = scpi.arg(password);
    _vna->write(scpi);
}
void VnaSettings::serviceFunction(const QString &function) {
    QString scpi = ":DIAG:SERV:SFUN \'%1\'\n";
    scpi = scpi.arg(function);
    _vna->write(scpi);
}
void VnaSettings::serviceFunction(const QString &function, const QString &password) {
    servicePassword(password);
    serviceFunction(function);
}

// Private
QString VnaSettings::toScpi(EmulationMode mode) {
    switch(mode) {
    case EmulationMode::Off:
        return("SCPI");
    case EmulationMode::Pna:
        return("PNA");
    case EmulationMode::Hp8510:
        return("HP8510");
    case EmulationMode::Hp8720:
        return("HP8720");
    case EmulationMode::Hp8753:
        return("HP8753");
    case EmulationMode::Hp8714:
        return("HP8714");
    case EmulationMode::Zvr:
        return("ZVR");
    case EmulationMode::Hp8530:
        return("HP8530");
    case EmulationMode::Ena:
        return("ENA");
    case EmulationMode::Zvabt:
        return("ZVABT");
    default:
        return("SCPI");
    }
}
VnaSettings::EmulationMode VnaSettings::toVnaEmulationMode(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "SCPI")
        return(EmulationMode::Off);
    if (scpi == "PNA")
        return(EmulationMode::Pna);
    if (scpi == "HP8510")
        return(EmulationMode::Hp8510);
    if (scpi == "HP8720")
        return(EmulationMode::Hp8720);
    if (scpi == "HP8753")
        return(EmulationMode::Hp8753);
    if (scpi == "HP8714")
        return(EmulationMode::Hp8714);
    if (scpi == "ZVR")
        return(EmulationMode::Zvr);
    if (scpi == "ZVABT")
        return(EmulationMode::Zvabt);
    // default
    return(EmulationMode::Off);
}

QString VnaSettings::toScpi(ColorScheme scheme) {
    switch(scheme) {
    case ColorScheme::Dark:
        return("DBAC");
    case ColorScheme::Light:
        return("LBAC");
    case ColorScheme::BlackWhiteOutline:
        return("BWLS");
    case ColorScheme::BlackWhiteSolid:
        return("BWS");
    default:
        return("DBAC");
    }
}
VnaSettings::ColorScheme VnaSettings::toColorScheme(QString scpi) {
    scpi = scpi.toUpper();
    if(scpi == "DBAC")
        return(ColorScheme::Dark);
    if(scpi == "LBAC")
        return(ColorScheme::Light);
    if(scpi == "BWLS")
        return(ColorScheme::BlackWhiteOutline);
    if(scpi == "BWS")
        return(ColorScheme::BlackWhiteSolid);
    // Default
    return(ColorScheme::Dark);
}
