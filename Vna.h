#ifndef VNA_H
#define VNA_H


// RsaToolbox:
#include "Definitions.h"
#include "General.h"
#include "GenericBus.h"
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
        Log *log;
        GenericBus *bus;

		// Constructor / Destructor
        Vna(ConnectionType connectionType, QString instrument_address, unsigned int timeout_ms, QString log_path, QString log_filename, QString program_name, QString program_version);
		~Vna();

    public slots:

		// Actions
		void Preset(void);
		void ClearStatus(void);

        // Get
        unsigned int GetPorts(void);
        unsigned int GetSelectedChannel(void);
        QVector<unsigned int> GetChannels(void);
        double GetDelay_s(unsigned int port);
        double GetDelay_s(unsigned int port, unsigned int channel);
        QVector<double> GetDelays_s(void);
        QVector<double> GetDelays_s(unsigned int channel);
        int Trace_GetChannel(QString trace);
        QVector<unsigned int> GetDiagrams(void);
        QString GetTitle(unsigned int diagram);
        QVector<unsigned int> Channel_GetDiagrams(unsigned int channel);
        QStringList Channel_GetTraces(unsigned int channel);
        QVector<unsigned int> Trace_GetDiagrams(QString trace);
        QStringList GetTraces(void);
        QStringList Diagram_GetTraces(unsigned int diagram);
        QVector<double> GetSourceAttenuation_dB(void);
        double GetSourceAttenuation_dB(unsigned int port);
        QString GetColorScheme(void);
        unsigned int GetFontSize_percent(void);
        double GetChannelPower_dBm(void);
        double GetChannelPower_dBm(unsigned int channel);
        double GetPortPower_dBm(unsigned int port, ReferenceLevel &power_reference, double &power);
        double GetPortPower_dBm(unsigned int port, unsigned int channel, ReferenceLevel &power_reference, double &power);
        double GetStartFrequency_Hz(void);
        double GetStartFrequency_Hz(unsigned int channel);
        double GetStopFrequency_Hz(void);
        double GetStopFrequency_Hz(unsigned int channel);
        unsigned int GetPoints(void);
        unsigned int GetPoints(unsigned int channel);

        // Set
        bool SetSelectedChannel(unsigned int channel);
        bool SetDelay(unsigned int port, double delay_s);
        bool SetDleay(unsigned int port, unsigned int channel, double delay_s);
        bool SetTitle(QString title);
        bool SetTitle(QString title, unsigned int diagram);
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
        bool EnableChannel(unsigned int channel, bool isEnabled = true);
        bool EnableUserPreset(bool isEnabled = true);
        bool EnableUserPresetMapToRst(bool isEnabled = true);
        bool EnableSourcePowerLimits(bool isEnabled = true);
        bool EnableRfOutputPower(bool isEnabled = true);
        bool EnableDynamicBandwidth(bool isEnabled = true);
        bool EnableLowPowerAutoCal(bool isEnabled = true);

        // Disable
        bool DisableChannel(unsigned int channel, bool isDisabled = true);
        bool DisableDelay(unsigned int port);
        bool DisableDelay(unsigned int port, unsigned int channel);
        bool DisableDelays(void);
        bool DisableDelays(unsigned int channel);
        bool DisableUserPreset(bool isDisabled = true);
        bool DisableUserPresetMapToRst(bool isDisabled = true);
        bool DisableSourcePowerLimits(bool isDisabled = true);
        bool DisableRfOutputPower(bool isDisabled = true);
        bool DisableDynamicBandwidth(bool isDisabled = true);
        bool DisableLowPowerAutoCal(bool isDisabled = true);

        // Status
        bool isChannelEnabled(unsigned int channel);
        bool isChannelDisabled(unsigned int channel);
        bool isPortPowerOffsetEnabled(unsigned int port);
        bool isPortPowerOffsetDisabled(unsigned int port);
        bool isPortPowerOffsetEnabled(unsigned int port, unsigned int channel);
        bool isPortPowerOffsetDisabled(unsigned int port, unsigned int channel);
        bool isUserPresetEnabled(void);
        bool isUserPresetMappedToRst();
        bool isSourcePowerLimitEnabled();
        bool isRfOutputPowerEnabled();
        bool isDynamicBandwidthEnabled();
        bool isLowPowerAutoCalEnabled();


        // Create
        bool CreateDiagram(unsigned int diagram);

        // Delete/Clear
        bool ClearUserPreset(void);

        // Measure
        bool MeasureTrace(Trace &trace);
        bool MeasureTrace(Trace &trace, QString name);
        bool MeasureNetwork(Network &network, QVector<unsigned int> ports);
        bool MeasureNetwork(Network &network, QVector<unsigned int> ports, unsigned int channel);

        // Save
        bool SaveCurrentState(QDir path, QString name);

    private:
        // For 'Int1,Name_1,Int2,Name_2...' Query formats
        static void ParseIndicesFromRead(QString readback, QVector<unsigned int> &indices);
        static void ParseNamesFromRead(QString readback, QStringList &names);

        // For 'Value,Qualifier_String'
        static void ParseValueFromRead(QString readback, unsigned int &value, QString &qualifier);
        static void ParseValueFromRead(QString readback, int &value, QString &qualifier);
        static void ParseValueFromRead(QString readback, double &value, QString &qualifier);
	};
}


#endif
