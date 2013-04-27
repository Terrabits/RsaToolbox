#ifndef VNA_H
#define VNA_H


// RsaToolbox:
#include "Definitions.h"
#include "GenericBus.h"
#include "Log.h"
#include "Trace.h"
#include "Network.h"

// Qt
#include <QString>
#include <QVector>
#include <QStringList>
#include <QScopedPointer>

// C++ std lib
#include <complex>
#include <vector>


namespace RsaToolbox {
	class Vna {
	public:
        QString id_string;
        VnaModel model;
        QString firmware_version;
        QString serial_no;
        QStringList options;
        unsigned int ports;
        double minimum_frequency_Hz, maximum_frequency_Hz;
        QScopedPointer<Log> log;
        QScopedPointer<GenericBus> bus;

        /***********************
        *** CONNECTION *********
        ***********************/

        Vna();
        Vna(ConnectionType connectionType, QString instrument_address, unsigned int timeout_ms, QString log_path, QString log_filename, QString program_name, QString program_version);
        ~Vna();

        void Reset(ConnectionType connection_type, QString instrument_address, unsigned int timeout_ms, QString log_path, QString log_filename, QString program_name, QString program_version);
        void Reset(void);


    public slots:
        /***********************
        *** ACTIONS ************
        ***********************/

		void Preset(void);
		void ClearStatus(void);
        void PrintInstrumentInfo(void);
        void InitiateSweep(void);
        void InitiateSweep(unsigned int channel);
        void FinishPreviousCommandsFirst(void);
        void PauseUntilCommandQueueIsFinished(void);


    public:
        /***********************
        *** STATUS *************
        ***********************/

        bool isChannelEnabled(unsigned int channel);
        bool isChannelDisabled(unsigned int channel);
        bool isCalibrationEnabled(void);
        bool isCalibrationDisabled(void);
        bool isCalibrationEnabled(unsigned int channel);
        bool isCalibrationDisabled(unsigned int channel);
        bool isContinuousSweepEnabled(void);
        bool isContinuousSweepEnabled(unsigned int channel);
        bool isUserPresetEnabled(void);
        bool isUserPresetDisabled(void);
        bool isUserPresetMappedToRst(void);
        bool isPortPowerLimitEnabled(unsigned int port);
        bool isPortPowerLimitEnabled(void);
        bool isPortPowerLimitDisabled(unsigned int port);
        bool isPortPowerLimitDisabled(void);
        bool isRfOutputPowerEnabled(void);
        bool isRfOutputPowerDisabled(void);
        bool isDynamicIfBandwidthEnabled(void);
        bool isDynamicIfBandwidthDisabled(void);
        bool isLowPowerAutoCalEnabled(void);
        bool isLowPowerAutoCalDisabled(void);


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
        QStringList GetOptions(void);
        unsigned int GetPorts(void);
        double GetMinimumFrequency_Hz(void);
        double GetMaximumFrequency_Hz(void);
        double GetSourceAttenuation_dB(unsigned int port);
        double GetSourceAttenuation_dB(unsigned int port, unsigned int channel);
        double GetReceiverAttenuation_dB(unsigned int port);
        double GetReceiverAttenuation_dB(unsigned int port, unsigned int channel);
        double GetPortPowerLimit(unsigned int port);
        QVector<double> GetPortPowerLimits(void);
        ColorScheme GetColorScheme(void);
        unsigned int GetFontSize_percent(void);
        QString GetUserPreset(void);

        // GET:Channel
        QVector<unsigned int> GetChannels(void);
        QString GetCalGroup(void);
        QString GetCalGroup(unsigned int channel);
        CorrectionState GetCorrectionState(void);
        CorrectionState GetCorrectionState(unsigned int channel);
        SweepType GetSweepType(void);
        SweepType GetSweepType(unsigned int channel);
        void GetStimulusValues(QString trace_name, RowVector &stimulus_data);
        void GetStimulusValues(unsigned int channel, RowVector &stimulus_data);
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
        void SetSourceAttenuations_dB(double attenuation);
        void SetSourceAttenuations_dB(QVector<double> attenuations);
        void SetSourceAttenuations_dB(unsigned int channel, double attenuation);
        void SetSourceAttenuations_dB(unsigned int channel, QVector<double> attenuations);
        void SetReceiverAttenuation_dB(unsigned int port, double attenuation);
        void SetReceiverAttenuation_dB(unsigned int port, unsigned int channel, double attenuation);
        void SetReceiverAttenuations_dB(double attenuation);
        void SetReceiverAttenuations_dB(QVector<double> attenuations);
        void SetReceiverAttenuations_dB(unsigned int channel, double attenuation);
        void SetReceiverAttenuations_dB(unsigned int channel, QVector<double> attenuations);
        void SetPortPowerLimit(unsigned int port, double power_limit);
        void SetPortPowerLimits(QVector<double> power_limits);
        void SetPortPowerLimits(double power_limit);
        void SetColorScheme(ColorScheme scheme);
        void SetFontSize_percent(unsigned int size_percent);
        void SetUserPreset(QString filename);
        void SetUserPreset(QDir path, QString filename);

        // SET:Channel
        void SetSweepType(SweepType sweep_type);
        void SetSweepType(unsigned int channel, SweepType sweep_type);
        void Channel_SetSelectedTrace(QString trace_name);
        void SetDelay(unsigned int port, double delay, SiPrefix prefix = NO_PREFIX);
        void SetDelay(unsigned int port, unsigned int channel, double delay, SiPrefix prefix = NO_PREFIX);
        void SetDelays(QVector<double> delays, SiPrefix prefix = NO_PREFIX);
        void SetDelays(unsigned int channel, QVector<double> delays, SiPrefix prefix = NO_PREFIX);
        void SetChannelPower_dBm(double power_dBm);
        void SetChannelPower_dBm(unsigned int channel, double power_dBm);
        void SetPortPower(unsigned int port, double power_dBm, ReferenceLevel power_reference = ABSOLUTE_REFERENCE_LEVEL);
        void SetPortPower(unsigned int port, unsigned int channel, double power_dBm, ReferenceLevel power_reference = ABSOLUTE_REFERENCE_LEVEL);
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

        void EnableCorrection(bool isEnabled = true);
        void EnableCorrection(int channel, bool isEnabled = true);
        void EnableCorrection(unsigned int channel, bool isEnabled = true);
        void EnableContinuousSweep(bool isEnabled = true);
        void EnableContinuousSweep(int channel, bool isEnabled = true);
        void EnableContinuousSweep(unsigned int channel, bool isEnabled = true);
        void EnableContinuousSweep(double channel, bool isEnabled = true);
        void EnableUserPreset(bool isEnabled = true);
        void EnableUserPresetMapToRst(bool isEnabled = true);
        void EnablePortPowerLimit(unsigned int port, bool isEnabled = true);
        void EnablePortPowerLimits(bool isEnabled = true);
        void EnableRfOutputPower(bool isEnabled = true);
        void EnableDynamicIfBandwidth(bool isEnabled = true);
        void EnableLowPowerAutoCal(bool isEnabled = true);


    public slots:
        /***********************
        *** DISABLE ************
        ***********************/

        void DisableCustomIdString(bool isDisabled = true);
        void DisableCustomOptionsString(bool isDisabled = true);
        void DisableEmulation(void);
        void DisableCorrection(bool isDisabled = true);
        void DisableCorrection(int channel, bool isDisabled = true);
        void DisableCorrection(unsigned int channel, bool isDisabled = true);
        void DisableCalGroup(void);
        void DisableCalGroup(unsigned int channel);
        void DisableContinuousSweep(bool isDisabled = true);
        void DisableContinuousSweep(int channel, bool isDisabled = true);
        void DisableContinuousSweep(unsigned int channel, bool isDisabled = true);
        void DisableContinuousSweep(double channel, bool isDisabled = true);
        void DisableDelay(unsigned int port);
        void DisableDelay(unsigned int port, unsigned int channel);
        void DisableDelays(void);
        void DisableDelays(unsigned int channel);
        void DisableUserPreset(bool isDisabled = true);
        void DisableUserPresetMapToRst(bool isDisabled = true);
        void DisablePortPowerLimit(unsigned int port, bool isDisabled = true);
        void DisablePortPowerLimits(bool isDisabled = true);
        void DisableRfOutputPower(bool isDisabled = true);
        void DisableDynamicIfBandwidth(bool isDisabled = true);
        void DisableLowPowerAutoCal(bool isDisabled = true);


    public slots:
        /***********************
        *** CREATE *************
        ***********************/

        void CreateChannel(unsigned int channel);
        void CreateSParameterGroup(unsigned int channel, QVector<unsigned int> ports);
        void CreateDiagram(unsigned int diagram);
        void CreateTrace(QString trace_name, unsigned int channel, NetworkParameter parameter, unsigned int port1, unsigned int port2);


    public slots:
        /***********************
        *** DELETE *************
        ***********************/

        void DeleteChannel(unsigned int channel);
        void DeleteCorrectionData(void);
        void DeleteCorrectionData(unsigned int channel);
        void DeleteCalGroup(QString cal_group);
        void DeleteSParameterGroup(unsigned int channel);
        void DeleteDiagram(unsigned int diagram);
        void DeleteTrace(QString trace_name);
        void DeleteUserPreset(void);


    public slots:
        /***********************
        *** MEASURE ************
        ***********************/

        void MeasureTrace(QString trace_name, Trace &trace);
        void MeasureNetwork(Network &network, unsigned int channel, QVector<unsigned int> ports);


    public slots:
        /***********************
        *** SAVE ***************
        ***********************/

        void SaveCalGroup(QString cal_file);
        void SaveCalGroup(unsigned int channel, QString cal_file);
        void SaveState(QString filename);
        void SaveState(QDir path, QString filename);


    public slots:
        /***********************
        *** LOAD ***************
        ***********************/

        void LoadCalGroup(QString cal_file);
        void LoadCalGroup(unsigned int channel, QString cal_file);
        void LoadState(QString state_file);
        void LoadState(QDir path, QString state_file);


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
        static QString ValueQualifier_to_Scpi(unsigned int value, QString qualifier);
        static QString ValueQualifier_to_Scpi(int value, QString qualifier);
        static QString ValueQualifier_to_Scpi(double value, QString qualifier);

        // Trace format: "\'S12\'" or "\'S1213\'"
        static void ParseTraceParameters(QString readback, NetworkParameter &parameter, unsigned int &port1, unsigned int &port2);
        static QString TraceParameters_to_Scpi(NetworkParameter parameter, unsigned int port1, unsigned int port2);

        // Read Trace
        static unsigned int TraceBufferSize(TraceFormat format, unsigned int points);
        static unsigned int StimulusBufferSize(unsigned int points);
        static void ParseTraceData(Trace &trace, QString data);
        static void ParseTraceStimulus(RowVector &stimulus_data, QString readback);
        static void GetTraceUnits(Trace &trace);

        // Read Network
        static unsigned int NetworkBufferSize(unsigned int points, unsigned int ports);
        static void Vna::ParseNetworkData(Network &network, QString readback);
	};
}


#endif
