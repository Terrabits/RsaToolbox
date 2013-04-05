#ifndef VNA_H
#define VNA_H


// RsaToolbox:
#include "Definitions.h"
#include "General.h"
#include "GenericBus.h"
#include "RsibBus.h"
#include "Log.h"
#include "Trace.h"
#include "Network.h"

// Qt
#include <QString>
#include <QVector>
#include <QStringList>

// C++ std lib
#include <complex>
#include <vector>


namespace RsaToolbox {
	class Vna {
	public:
        VnaModel model;
        QString firmware;
        QString options;
        unsigned int ports;
        Log log;
        GenericBus *bus;

		// Constructor / Destructor
        Vna(ConnectionType connectionType, QString instrument_address, QString log_path, QString log_filename, QString program_name, QString program_version);
		~Vna();

    public slots:

		// Actions
		void Preset(void);
		void ClearStatus(void);

        // Get
        unsigned int GetSelectedChannel(void);
        QVector<unsigned int> GetChannels(void);
        QVector<double> GetDelays_s(unsigned int channel);
        int GetChannel(QString trace);
        QVector<unsigned int> GetDiagrams(void);
        QStringList GetTraces(unsigned int diagram);
        QVector<double> GetSourceAttenuation_dB(void);
        double GetSourceAttenuation_dB(unsigned int port);
        QString GetColorScheme(void);
        unsigned int GetFontSize_percent(void);
        double GetSourcePowerLevel_dBm(void);
        double GetStartFrequency_Hz(void);
        double GetStartFrequency_Hz(unsigned int channel);
        double GetStopFrequency_Hz(void);
        double GetStopFrequency_Hz(unsigned int channel);
        unsigned int GetPoints(void);
        unsigned int GetPoints(unsigned int channel);

        // Set
        bool SetSelectedChannel(unsigned int channel);
        bool SetDelay(unsigned int channel, double delay_s);
        bool SetUserPreset(QString filename);
        bool SetSourceAttenuation(double attenuation_dB);
        bool SetSourceAttenuation(unsigned int port, double attenuation_dB);
        bool SetColorScheme(QString color_scheme);
        bool SetFontSize(unsigned int font_size_percent);
        bool SetSourcePowerLevel(double power_level_dBm);
        bool SetStartFrequency(double frequency, SiPrefix prefix = NO_PREFIX);
        bool SetStopFrequency(double frequency, SiPrefix prefix = NO_PREFIX);
        bool SetPoints(unsigned int points);
        bool SetPoints(unsigned int points, unsigned int channel);
        bool SetIfBandwidth(unsigned int if_bandwidth, SiPrefix prefix = NO_PREFIX);
        bool SetIfBandwidth(unsigned int if_bandwidth, SiPrefix prefix, unsigned int channel);

        // Enable
        bool EnableUserPreset(bool isEnabled = true);
        bool EnableMapUserPresetToRst(bool isEnabled = true);
        bool EnableSourcePowerLimits(bool isEnabled = true);
        bool EnableRfOutputPower(bool isEnabled = true);
        bool EnableDynamicBandwidth(bool isEnabled = true);
        bool EnableLowPowerAutoCal(bool isEnabled = true);

        // Disable
        bool DisableUserPreset(bool isDisabled = true);
        bool DisableMapUserPresetToRst(bool isDisabled = true);
        bool DisableSourcePowerLimits(bool isDisabled = true);
        bool DisableRfOutputPower(bool isDisabled = true);
        bool DisableDynamicBandwidth(bool isDisabled = true);
        bool DisableLowPowerAutoCal(bool isDisabled = true);

        // Delete
        //

        // Measure
        bool MeasureTrace(Trace &trace);
        bool MeasureTrace(Trace &trace, QString name);
        bool MeasureNetwork(Network &network, QVector<unsigned int> ports);
        bool MeasureNetwork(Network &network, QVector<unsigned int> ports, unsigned int channel);

        // Save
        bool SaveCurrentState(QDir path, QString name);
	};
}


#endif
