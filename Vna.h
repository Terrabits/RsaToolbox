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

        /***********************
        *** ACTIONS ************
        ***********************/

		void Preset(void);
		void ClearStatus(void);

        /***********************
        *** STATUS *************
        ***********************/

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

        /***********************
        *** SELECT *************
        ***********************/

        bool SelectTrace(QString trace_name);

        /***********************
        *** GET ****************
        ***********************/

        // GET:General
        unsigned int GetPorts(void);
        QString GetSelectedTrace(void);
        QString GetSelectedTrace(unsigned int channel);
        double GetSourceAttenuation_dB(unsigned int port);
        double GetSourceAttenuation_dB(unsigned int port, unsigned int channel);
        double GetReceiverAttenuation_dB(unsigned int port);
        double GetReceiverAttenuation_dB(unsigned int port, unsigned int channel);
        ColorScheme GetColorScheme(void);
        unsigned int GetFontSize_percent(void);

        // GET:Channel
        QVector<unsigned int> GetChannels(void);
        QVector<unsigned int> Channel_GetDiagrams(unsigned int channel);
        QStringList Channel_GetTraces(unsigned int channel);
        double GetDelay_s(unsigned int port);
        double GetDelay_s(unsigned int port, unsigned int channel);
        QVector<double> GetDelays_s(void);
        QVector<double> GetDelays_s(unsigned int channel);
        double GetChannelPower_dBm(void);
        double GetChannelPower_dBm(unsigned int channel);
        void GetPortPower_dBm(unsigned int port, ReferenceLevel &power_reference, double &power);
        void GetPortPower_dBm(unsigned int port, unsigned int channel, ReferenceLevel &power_reference, double &power);
        double GetStartFrequency_Hz(void);
        double GetStartFrequency_Hz(unsigned int channel);
        double GetStopFrequency_Hz(void);
        double GetStopFrequency_Hz(unsigned int channel);
        unsigned int GetPoints(void);
        unsigned int GetPoints(unsigned int channel);

        // GET:Diagram
        QVector<unsigned int> GetDiagrams(void);
        QStringList Diagram_GetTraces(unsigned int diagram);
        QVector<unsigned int> Diagram_GetChannels(unsigned int diagram);
        QString GetTitle(unsigned int diagram);

        // GET:Trace
        QStringList GetTraces(void);
        unsigned int Trace_GetChannel(QString trace_name);
        void Trace_GetParameters(QString trace_name, NetworkParameter &parameter, unsigned int &port1, unsigned int &port2);
        TraceFormat Trace_GetFormat(QString trace_name);
        unsigned int Trace_GetDiagram(QString trace_name);



        /***********************
        *** SET ****************
        ***********************/

        bool SetSelectedChannel(unsigned int channel);
        bool SetDelay(unsigned int port, double delay_s);
        bool SetDelay(unsigned int port, unsigned int channel, double delay_s);
        bool Trace_SetChannel(unsigned int channel);
        bool Trace_SetChannel(unsigned int channel, QString trace_name);
        bool Trace_SetDiagram(unsigned int diagram);
        bool Trace_SetDiagram(unsigned int diagram, QString trace_name);
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

        /***********************
        *** ENABLE *************
        ***********************/

        bool EnableUserPreset(bool isEnabled = true);
        bool EnableUserPresetMapToRst(bool isEnabled = true);
        bool EnableSourcePowerLimits(bool isEnabled = true);
        bool EnableRfOutputPower(bool isEnabled = true);
        bool EnableDynamicBandwidth(bool isEnabled = true);
        bool EnableLowPowerAutoCal(bool isEnabled = true);

        /***********************
        *** DISABLE ************
        ***********************/

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

        /***********************
        *** CREATE *************
        ***********************/

        bool CreateChannel(unsigned int channel);
        bool CreateDiagram(unsigned int diagram);

        /***********************
        *** DELETE *************
        ***********************/

        bool DeleteChannel(unsigned int channel);
        bool DeleteUserPreset(void);

        /***********************
        *** MEASURE ************
        ***********************/

        bool MeasureTrace(Trace &trace);
        bool MeasureTrace(Trace &trace, QString name);
        bool MeasureNetwork(Network &network, QVector<unsigned int> ports);
        bool MeasureNetwork(Network &network, QVector<unsigned int> ports, unsigned int channel);

        /***********************
        *** SAVE ***************
        ***********************/
        bool SaveCurrentState(QDir path, QString name);

        /***********************
        *** PRIVATE ************
        ***********************/
    private:

        // readback format: "\'Int1,Name_1,Int2,Name_2,...\'"
        static void ParseIndicesFromRead(QString readback, QVector<unsigned int> &indices);
        static void ParseNamesFromRead(QString readback, QStringList &names);

        // readback format: "Value,Qualifier_String"
        static void ParseValueFromRead(QString readback, unsigned int &value, QString &qualifier);
        static void ParseValueFromRead(QString readback, int &value, QString &qualifier);
        static void ParseValueFromRead(QString readback, double &value, QString &qualifier);

        // Trace format: "\'S12\'" or "\'S1213\'"
        static void ParseTraceParameters(QString readback, NetworkParameter &parameter, unsigned int &port1, unsigned int &port2);
        static QString TraceParameters_to_Scpi(NetworkParameter parameter, unsigned int port1, unsigned int port2);
	};
}


#endif
