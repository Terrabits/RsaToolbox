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

class VnaSettings : public QObject
{
    Q_OBJECT

public:
    enum /*class*/ EmulationMode {
        Pna    = 1,
        Ena    = 2,
        Hp8510 = 3,
        Hp8530 = 4,
        Hp8720 = 5,
        Hp8753 = 6,
        Hp8714 = 7,
        Zvr    = 8,
        Zvabt  = 9,
        Off    = 0,
    };
    enum /*class*/ ColorScheme {
        Dark              = 0,
        Light             = 1,
        BlackWhiteOutline = 2,
        BlackWhiteSolid   = 3
    };

    explicit VnaSettings(QObject *parent = 0);
    VnaSettings(VnaSettings &other);
    VnaSettings(Vna *_vna, QObject *parent = 0);
    ~VnaSettings();

    void setIdString(QString idString);
    void resetIdString();
    void setOptionsString(QString options);
    void resetOptionsString();

    ImageFormat imageFormat();
    void setImageFormat(ImageFormat format);

//    QString fileDestination();
    void setFileDestination(const QString &filename);

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
    bool isEmulationMode(EmulationMode mode);
    EmulationMode emulationMode();
    void setEmulationMode(EmulationMode mode);
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

    bool isColorScheme(ColorScheme scheme);
    ColorScheme colorScheme();
    void setColorScheme (ColorScheme scheme);
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

    bool isPowerReductionBetweenSweepsOn();
    void powerReductionBetweenSweepsOn(bool isOn = true);
    void powerReductionBetweenSweepsOff(bool isOff = true);


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

    bool isRemoteLogOn();
    bool isRemoteLogOff();
    void remoteLogOn(bool isOn = true);
    void remoteLogOff(bool isOff = true);

    void servicePassword(const QString &password);
    void serviceFunction(const QString &function);
    void serviceFunction(const QString &function, const QString &password);

    void operator=(VnaSettings const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;

    static QString toScpi(EmulationMode mode);
    static EmulationMode toVnaEmulationMode(QString scpi);

    static QString toScpi(ColorScheme scheme);
    static ColorScheme toColorScheme(QString scpi);
    
};
}
Q_DECLARE_METATYPE(RsaToolbox::VnaSettings::EmulationMode)
Q_DECLARE_METATYPE(RsaToolbox::VnaSettings::ColorScheme)

#endif // VnaSettings_H
