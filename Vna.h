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
        QString firmware_version;
        QString serial_no;
        QString options;
        unsigned int ports;
        double minimum_frequency_Hz, maximum_frequency_Hz;
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

    public:
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
        bool isUserPresetDisabled(void);
        bool isUserPresetMappedToRst();
        bool isSourcePowerLimitEnabled();
        bool isSourcePowerLimitDisabled();
        bool isRfOutputPowerEnabled();
        bool isRfOutputPowerDisabled();
        bool isDynamicBandwidthEnabled();
        bool isDynamicBandwidthDisabled();
        bool isLowPowerAutoCalEnabled();
        bool isLowPowerAutoCalDisabled();

    public slots:
        /***********************
        *** SELECT *************
        ***********************/

        void SelectTrace(QString trace_name);

    public:
        /***********************
        *** GET ****************
        ***********************/

        // GET:General
        QString GetIdentificationString(void);
        QString GetOptionsString(void);
        unsigned int GetPorts(void);
        double GetMinimumFrequency_Hz(void);
        double GetMaximumFrequency_Hz(void);
        double GetSourceAttenuation_dB(unsigned int port);
        double GetSourceAttenuation_dB(unsigned int port, unsigned int channel);
        double GetReceiverAttenuation_dB(unsigned int port);
        double GetReceiverAttenuation_dB(unsigned int port, unsigned int channel);
        ColorScheme GetColorScheme(void);
        unsigned int GetFontSize_percent(void);
        QString GetUserPreset(void);

        // GET:Channel
        QVector<unsigned int> GetChannels(void);
        QVector<unsigned int> Channel_GetDiagrams(unsigned int channel);
        QStringList Channel_GetTraces(unsigned int channel);
        QString Channel_GetSelectedTrace(void);
        QString Channel_GetSelectedTrace(unsigned int channel);
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
        double GetIfBandwidth(void);
        double GetIfBandwidth(unsigned int channel);
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


    public slots:
        /***********************
        *** SET ****************
        ***********************/

        // SET:General
        void SetIdentificationString(QString id_string);
        void SetOptionsString(QString options_string);
        void SetSourceAttenuation_dB(unsigned int port, double attenuation);
        void SetSourceAttenuation_dB(unsigned int port, unsigned int channel, double attenuation);
        void SetReceiverAttenuation_dB(unsigned int port, double attenuation);
        void SetReceiverAttenuation_dB(unsigned int port, unsigned int channel, double attenuation);
        void SetColorScheme(ColorScheme scheme);
        void SetFontSize_percent(unsigned int size_percent);
        void SetUserPreset(QString filename);
        void SetUserPreset(QString filename, QDir path);

        // SET:Channel
        void Channel_SetSelectedTrace(QString trace_name);
        void SetDelay(unsigned int port, double delay, SiPrefix prefix = NO_PREFIX);
        void SetDelay(unsigned int port, unsigned int channel, double delay, SiPrefix prefix = NO_PREFIX);
        void SetDelays(QVector<double> delays, SiPrefix prefix = NO_PREFIX);
        void SetDelays(unsigned int channel, QVector<double> delays, SiPrefix prefix = NO_PREFIX);
        void SetChannelPower_dBm(double power_dBm);
        void SetChannelPower_dBm(unsigned int channel, double power_dBm);
        void SetPortPower(unsigned int port, double power_dBm, ReferenceLevel power_reference = ABSOLUTE);
        void SetPortPower(unsigned int port, unsigned int channel, double power_dBm, ReferenceLevel power_reference = ABSOLUTE);
        void SetStartFrequency(double start_frequency, SiPrefix prefix = NO_PREFIX);
        void SetStartFrequency(unsigned int channel, double start_frequency, SiPrefix prefix = NO_PREFIX);
        void SetStopFrequency(double stop_frequency, SiPrefix prefix = NO_PREFIX);
        void SetStopFrequency(unsigned int channel, double stop_frequency, SiPrefix prefix = NO_PREFIX);
        void SetIfBandwidth(double if_bandwidth, SiPrefix prefix = NO_PREFIX);
        void SetIfBandwidth(unsigned int channel, double if_bandwidth, SiPrefix prefix = NO_PREFIX);
        void SetPoints(unsigned int points);
        void SetPoints(unsigned int channel, unsigned int points);

        // SET:Diagram
        void SetTitle(unsigned int diagram, QString title);

        // SET:Trace
        // void Trace_SetChannel(QString trace_name, unsigned int channel);
        void Trace_SetParameters(QString trace_name, NetworkParameter parameter, unsigned int port1, unsigned int port2);
        void Trace_SetFormat(QString trace_name, TraceFormat format);
        // void Trace_SetDiagram(QString trace_name, unsigned int diagram);

    public slots:
        /***********************
        *** ENABLE *************
        ***********************/

        void EnableUserPreset(bool isEnabled = true);
        void EnableUserPresetMapToRst(bool isEnabled = true);
        void EnableSourcePowerLimits(bool isEnabled = true);
        void EnableRfOutputPower(bool isEnabled = true);
        void EnableDynamicBandwidth(bool isEnabled = true);
        void EnableLowPowerAutoCal(bool isEnabled = true);

    public slots:
        /***********************
        *** DISABLE ************
        ***********************/

        void DisableCustomIdString(bool isDisabled = true);
        void DisableCustomOptionsString(bool isDisabled = true);
        void DisableDelay(unsigned int port, bool isDisabled = true);
        void DisableDelay(unsigned int port, unsigned int channel, bool isDisabled = true);
        void DisableDelays(bool isDisabled = true);
        void DisableDelays(unsigned int channel, bool isDisabled = true);
        void DisableUserPreset(bool isDisabled = true);
        void DisableUserPresetMapToRst(bool isDisabled = true);
        void DisableSourcePowerLimits(bool isDisabled = true);
        void DisableRfOutputPower(bool isDisabled = true);
        void DisableDynamicBandwidth(bool isDisabled = true);
        void DisableLowPowerAutoCal(bool isDisabled = true);

    public slots:
        /***********************
        *** CREATE *************
        ***********************/

        bool CreateChannel(unsigned int channel);
        bool CreateDiagram(unsigned int diagram);

    public slots:
        /***********************
        *** DELETE *************
        ***********************/

        bool DeleteChannel(unsigned int channel);
        bool DeleteUserPreset(void);

    public slots:
        /***********************
        *** MEASURE ************
        ***********************/


        bool MeasureTrace(Trace &trace);
        bool MeasureTrace(Trace &trace, QString name);
        bool MeasureNetwork(Network &network, QVector<unsigned int> ports);
        bool MeasureNetwork(Network &network, QVector<unsigned int> ports, unsigned int channel);

    public slots:
        /***********************
        *** SAVE ***************
        ***********************/
        bool SaveCurrentState(QDir path, QString name);


    private:
        /***********************
        *** PRIVATE ************
        ***********************/

        bool isRohdeSchwarz(QString identification);
        void GetInstrumentInfo(QString id);
        VnaModel ParseModel(QString id_part_2);

        // readback format: "\'Int1,Name_1,Int2,Name_2,...\'"
        static void ParseIndicesFromRead(QString readback, QVector<unsigned int> &indices);
        static void ParseNamesFromRead(QString readback, QStringList &names);

        // readback format: "Value,Qualifier_String"
        static void ParseValueFromRead(QString readback, unsigned int &value, QString &qualifier);
        static void ParseValueFromRead(QString readback, int &value, QString &qualifier);
        static void ParseValueFromRead(QString readback, double &value, QString &qualifier);
        QString ValueQualifier_to_Scpi(unsigned int value, QString qualifier);
        QString ValueQualifier_to_Scpi(int value, QString qualifier);
        QString ValueQualifier_to_Scpi(double value, QString qualifier);

        // Trace format: "\'S12\'" or "\'S1213\'"
        static void ParseTraceParameters(QString readback, NetworkParameter &parameter, unsigned int &port1, unsigned int &port2);
        static QString TraceParameters_to_Scpi(NetworkParameter parameter, unsigned int port1, unsigned int port2);
	};
}


#endif
