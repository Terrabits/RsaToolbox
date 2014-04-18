#ifndef VnaSettings_H
#define VnaSettings_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;

enum VnaEmulationMode {
    NO_EMULATION,
    PNA_EMULATION,
    HP_8510_EMULATION,
    HP_8720_EMULATION,
    HP_8753_EMULATION,
    HP_8714_EMULATION,
    ZVR_EMULATION,
    HP_8530_EMULATION,
    ENA_EMULATION,
    ZVABT_EMULATION };
enum VnaColorScheme {
    DARK_BACKGROUND,
    LIGHT_BACKGROUND,
    BLACK_WHITE_OUTLINE_BACKGROUND,
    BLACK_WHITE_SOLID_BACKGROUND };

class VnaSettings : public QObject
{
private: Q_OBJECT

public:
    VnaSettings(QObject *parent = 0);
    VnaSettings(VnaSettings &other);
    VnaSettings(Vna *_vna, QObject *parent = 0);

    void setIdString(QString idString);
    void resetIdString();
    void setOptionsString(QString options);
    void resetOptionsString();

    bool isRead32BitBinaryFormat();
    bool isRead64BitBinaryFormat();
    bool isReadAsciiFormat();
    bool isLittleEndian();
    bool isBigEndian();
    void setRead32BitBinaryFormat();
    void setRead64BitBinaryFormat();
    void setReadAsciiFormat();
    void setLittleEndian();
    void setBigEndian();

    bool isEmulationOn();
    bool isEmulationOff();
    bool isEmulationMode(VnaEmulationMode mode);
    VnaEmulationMode emulationMode();
    void setEmulationMode(VnaEmulationMode mode);
    void setEmulationOff();

    bool isDisplayOn();
    bool isDisplayOff();
    void displayOn(bool isOn = true);
    void displayOff(bool isOff = true);
    void manualDisplayMode();
    void updateDisplay();

    bool isErrorDisplayOn();
    bool isErrorDisplayOff();
    void errorDisplayOn(bool isOn = true);
    void errorDisplayOff(bool isOff = true);

    bool isColorScheme(VnaColorScheme scheme);
    VnaColorScheme colorScheme();
    void setColorScheme (VnaColorScheme scheme);
    void setDefaultColorScheme();

    bool isFontSize(uint size_percent);
    uint fontSize_percent();
    void setFontSize(uint size_percent);
    void resetFontSize();

    // presets
    bool isUserPresetOn();
    bool isUserPresetOff();
    void userPresetOn(bool isOn = true);
    void userPresetOff(bool isOff = true);
    QString userPreset();
    void setUserPreset(QString setFilePath);
    bool isUserPresetMappedToRst();
    void mapUserPresetToRst(bool isMapped);

    bool isCalibrationPresetOn();
    bool isCalibrationPresetOff();
    void calibrationPresetOff();
    QString calibrationPreset();
    void setCalibrationPreset(QString calibrationFilePath);

    bool isPortPowerLimitOn(uint physicalPort);
    bool isPortPowerLimitOn();
    bool isPortPowerLimitOff(uint physicalPort);
    bool isPortPowerLimitOff();
    void portPowerLimitOn(uint physicalPort);
    void portPowerLimitsOn(bool isOn = true);
    void portPowerLimitOff(uint physicalPort);
    void portPowerLimitsOff(bool isOff = true);
    double portPowerLimit_dBm(uint physicalPort);
    void portPowerLimits(QVector<uint> &physicalPorts, QVector<double> limits_dBm);
    void setPortPowerLimit(uint physicalPort, double limit_dBm);
    void setPortPowerLimits(double limit_dBm);

    bool isRfOutputPowerOn();
    bool isRfOutputPowerOff();
    void rfOutputPowerOn(bool isOn = true);
    void rfOutputPowerOff(bool isOff = true);

    bool isDynamicIfBandwidthOn();
    bool isDynamicIfBandwidthOff();
    void dynamicIfBandwidthOn(bool isOn = true);
    void dynamicIfBandwidthOff(bool isOff = true);

    bool isLowPowerAutoCalOn();
    bool isLowPowerAutoCalOff();
    void lowPowerAutoCalOn(bool isOn = true);
    void lowPowerAutoCalOff(bool isOff = true);

    void operator=(VnaSettings const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;

    static QString toScpi(VnaEmulationMode mode);
    static VnaEmulationMode toVnaEmulationMode(QString scpi);

    static QString toScpi(VnaColorScheme scheme);
    static VnaColorScheme toColorScheme(QString scpi);
    
};
}
Q_DECLARE_METATYPE(RsaToolbox::VnaEmulationMode)
Q_DECLARE_METATYPE(RsaToolbox::VnaColorScheme)

#endif // VnaSettings_H
