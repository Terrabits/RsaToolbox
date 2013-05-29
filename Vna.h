#ifndef VNA_H
#define VNA_H


// RsaToolbox:
#include "Definitions.h"
#include "GenericBus.h"
#include "Log.h"
#include "TraceData.h"
#include "NetworkData.h"

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


    //**********************
    //** Vna ***************
    //*********************/

public slots:
    Vna();
    Vna(ConnectionType connectionType, QString instrument_address, uint timeout_ms, QString log_path, QString log_filename, QString program_name, QString program_version);

    // VNA:General
    bool isConnected();
    VnaModel GetModel();
    QString GetSerialNumber();
    QString GetFirmwareVersion();

    void Print(QString formatted_text);
    bool Lock();
    bool Unlock();
    bool Local();
    bool Remote();
    bool Read(char *buffer, unsigned int buffer_size);
    bool Write(QString scpi_command);
    bool Query(QString scpi_command, char *buffer, unsigned int buffer_size);

    // VNA:Actions
    void Preset();
    void ClearStatus();
    void InitiateSweeps();
    void FinishPreviousCommandsFirst();
    void PauseUntilCommandQueueIsFinished();

    // VNA:Status
    bool isChannelEnabled(uint channel);
    bool isChannelDisabled(uint channel);
    bool isUserPresetEnabled();
    bool isUserPresetDisabled();
    bool isUserCalPresetEnabled();
    bool isUserCalPresetDisabled();
    bool isUserPresetMappedToRst();
    bool isPortPowerLimitEnabled();
    bool isPortPowerLimitEnabled(uint port);
    bool isPortPowerLimitDisabled();
    bool isPortPowerLimitDisabled(uint port);
    bool isRfOutputPowerEnabled();
    bool isRfOutputPowerDisabled();
    bool isDynamicIfBandwidthEnabled();
    bool isDynamicIfBandwidthDisabled();
    bool isLowPowerAutoCalEnabled();
    bool isLowPowerAutoCalDisabled();

    // VNA:Select
    void SelectSet(QString set_name);

    // VNA:Get
    QString GetIdentificationString();
    QStringList GetOptions();
    uint GetPorts();
    double GetMinimumFrequency_Hz();
    double GetMaximumFrequency_Hz();
    QString GetDirectory();
    QString GetDefaultDirectory();
    QStringList GetOpenSets();
    double GetPortPowerLimit(uint port);
    QVector<double> GetPortPowerLimits();
    ColorScheme GetColorScheme();
    uint GetFontSize_percent();
    QString GetUserPreset();
    QString GetUserCalPreset();

    QVector<uint> GetChannels();
    QStringList GetTraces();
    QVector<uint> GetDiagrams();

    // VNA:Set
    void SetIdentificationString(QString id_string);
    void SetOptionsString(QString options_string);
    void SetDefaultDirectory();
    void SetDirectory(QString directory);
    void SetPortPowerLimit(uint port, double power_limit);
    void SetPortPowerLimits(QVector<double> power_limits);
    void SetPortPowerLimits(double power_limit);
    void SetColorScheme(ColorScheme scheme);
    void SetFontSize_percent(uint size_percent);
    void SetUserPreset(QString filename);
    void SetUserPreset(QDir path, QString filename);
    void SetUserCalPreset(QString cal_name);

    // VNA:Enable
    void EnableUserPreset(bool isEnabled = true);
    void EnableUserPresetMapToRst(bool isEnabled = true);
    void EnablePortPowerLimit(uint port, bool isEnabled = true);
    void EnablePortPowerLimits(bool isEnabled = true);
    void EnableRfOutputPower(bool isEnabled = true);
    void EnableDynamicIfBandwidth(bool isEnabled = true);
    void EnableLowPowerAutoCal(bool isEnabled = true);

    // VNA:Disable
    void DisableCustomIdString(bool isDisabled = true);
    void DisableCustomOptionsString(bool isDisabled = true);
    void DisableEmulation();
    void DisableUserPreset(bool isDisabled = true);
    void DisableUserPresetMapToRst(bool isDisabled = true);
    void DisablePortPowerLimit(uint port, bool isDisabled = true);
    void DisablePortPowerLimits(bool isDisabled = true);
    void DisableRfOutputPower(bool isDisabled = true);
    void DisableDynamicIfBandwidth(bool isDisabled = true);
    void DisableLowPowerAutoCal(bool isDisabled = true);
    void DisableSwitchMatrices(void);
    void DisableUserCalPreset(void);

    // VNA:Create
    void CreateSet(QString set_name);
    void CreateChannel(uint channel);
    void CreateTrace(QString trace_name, uint channel, NetworkParameter parameter, uint port1, uint port2);
    void CreateDiagram(uint diagram);

    // VNA:Delete
    void DeleteSet(QString filename);
    void DeleteUserPreset();
    void DeleteCalGroup(QString cal_group);
    void DeleteSwitchMatrices(void);

    void DeleteChannel(uint channel);
    void DeleteTrace(QString trace_name);
    void DeleteDiagram(uint diagram);

    // VNA:Open
    void OpenSet(QString filename);

    // VNA:Save
    void SaveSet(QString filename);

    // VNA:Close
    void CloseSet(QString set_name);
    void CloseSets();

private:
    // VNA:Private
    QString id_string;
    VnaModel model;
    QString firmware_version;
    QString serial_no;
    QStringList options;
    uint ports;
    double minimum_frequency_Hz, maximum_frequency_Hz;
    QDir default_directory;
    QScopedPointer<Log> log;
    QScopedPointer<GenericBus> bus;

    // VNA:Private:General
    void Reset();
    void Reset(ConnectionType connection_type, QString instrument_address, uint timeout_ms, QString log_path, QString log_filename, QString program_name, QString program_version);

    bool isRohdeSchwarz(QString identification);
    void GetInstrumentInfo(QString id);
    VnaModel ParseModel(QString id_part_2);
    static const char* ToScpi(ColorScheme scheme);
    static ColorScheme Scpi_To_ColorScheme(QString scpi);
    void PrintInstrumentInfo();

    // VNA:Private:Readback
    // format: "\'Int1,Name_1,Int2,Name_2,...\'"
    static void ParseIndicesFromRead(QString readback, QVector<uint> &indices);
    static void ParseNamesFromRead(QString readback, QStringList &names);

    // format: "Value,Qualifier_String"
    static void ParseValueFromRead(QString readback, uint &value, QString &qualifier);
    static void ParseValueFromRead(QString readback, int &value, QString &qualifier);
    static void ParseValueFromRead(QString readback, double &value, QString &qualifier);
    static QString ValueQualifier_to_Scpi(uint value, QString qualifier);
    static QString ValueQualifier_to_Scpi(int value, QString qualifier);
    static QString ValueQualifier_to_Scpi(double value, QString qualifier);

    //**********************
    //** CHANNEL ***********
    //*********************/

private:
    class _Channel {
    public:
        _Channel() {}
        _Channel(Vna *vna, uint channel);
        friend class Vna;

        // CHANNEL:Actions
        void InitiateSweep();

        // CHANNEL:Status
        bool isEnabled();
        bool isDisabled();
        bool isCalibrationEnabled();
        bool isCalibrationDisabled();
        bool isContinuousSweepEnabled();
        bool isSingleSweepEnabled();

        // CHANNEL:Get
        double GetSourceAttenuation_dB(uint port);
        double GetReceiverAttenuation_dB(uint port);
        QString GetCalGroup();
        CorrectionState GetCorrectionState();
        SweepType GetSweepType();
        void GetStimulusValues(RowVector &stimulus_data);
        QVector<uint> GetDiagrams();
        QStringList GetTraces();
        QString GetSelectedTrace();
        double GetDelay_s(uint port);
        QVector<double> GetDelays_s();
        double GetChannelPower_dBm();
        void GetPortPower_dBm(uint port, ReferenceLevel &power_reference, double &power);
        double GetStartFrequency_Hz();
        double GetStopFrequency_Hz();
        double GetIfBandwidth();
        uint GetPoints();

        // CHANNEL:Set
        void SetCalGroup(QString cal_file);
        void SetSourceAttenuation_dB(uint port, double attenuation_dB);
        void SetSourceAttenuations_dB(double attenuation_dB);
        void SetSourceAttenuations_dB(QVector<double> attenuations_dB);
        void SetReceiverAttenuation_dB(uint port, double attenuation_dB);
        void SetReceiverAttenuations_dB(double attenuation_dB);
        void SetReceiverAttenuations_dB(QVector<double> attenuations_dB);
        void SetSweepType(SweepType sweep_type);
        void SetDelay(uint port, double delay_s, SiPrefix prefix = NO_PREFIX);
        void SetDelays(double delay_s, SiPrefix prefix = NO_PREFIX);
        void SetDelays(QVector<double> delays_s, SiPrefix prefix = NO_PREFIX);
        void SetChannelPower_dBm(double power_dBm);
        void SetPortPower(uint port, double power_dBm, ReferenceLevel power_reference = ABSOLUTE_REFERENCE_LEVEL);
        void SetPortPowers(double power_dBm, ReferenceLevel power_reference = ABSOLUTE_REFERENCE_LEVEL);
        void SetPortPowers(QVector<double> powers_dBm, ReferenceLevel power_reference = ABSOLUTE_REFERENCE_LEVEL);
        void SetStartFrequency(double start_frequency_Hz, SiPrefix prefix = NO_PREFIX);
        void SetStopFrequency(double stop_frequency_Hz, SiPrefix prefix = NO_PREFIX);
        void SetIfBandwidth(double if_bandwidth_Hz, SiPrefix prefix = NO_PREFIX);
        void SetPoints(uint points);

        // CHANNEL:Enable
        void EnableCorrection(bool isEnabled = true);
        void EnableContinuousSweep(bool isEnabled = true);

        // CHANNEL:Disable
        void DisableCorrection(bool isDisabled = true);
        void DisableCalGroup();
        void DisableContinuousSweep(bool isDisabled = true);
        void DisableDelay(uint port);
        void DisableDelays();

        // CHANNEL:Create
        void CreateSParameterGroup(QVector<uint> ports);

        // CHANNEL:Delete
        void DeleteCorrectionData();
        void DeleteSParameterGroup();

        // CHANNEL:Measure
        void MeasureNetwork(NetworkData &network, QVector<uint> ports);

        // CHANNEL:Save
        void SaveCalGroup(QString cal_file);

        //CHANNEL:Private
    private:
        Vna *vna;
        uint channel;

        // CHANNEL:Private:General
        static const char* ToScpi(ReferenceLevel reference_level);
        static const char* ToScpi(SweepType sweep_type);
        static ReferenceLevel Scpi_To_ReferenceLevel(QString scpi);
        static SweepType Scpi_To_SweepType(QString scpi);
        static CorrectionState Scpi_To_CorrectionState(QString scpi);

        // CHANNEL:Private:Read network
        static uint NetworkBufferSize(uint points, uint ports);
        static uint StimulusBufferSize(uint points);
        static void ParseStimulus(RowVector &stimulus_data, QString readback);
        static void ParseNetworkData(NetworkData &network, QString readback);

    };

private:
    _Channel _channel;
public:
    _Channel& Channel(uint channel = 1);


    //**********************
    //** TRACE *************
    //*********************/

private:
    class _Trace {
    public:
        _Trace() {}
        _Trace(Vna *vna, QString trace_name);
        friend class Vna;

        // TRACE:Select
        void Select();

        // TRACE:Get
        void GetStimulusValues(RowVector &stimulus_data);
        uint GetChannel();
        void GetParameters(NetworkParameter &parameter, uint &port1, uint &port2);
        TraceFormat GetFormat();
        uint GetDiagram();

        // TRACE:Set
        void SetParameters(NetworkParameter parameter, uint port1, uint port2);
        void SetFormat(TraceFormat format);

        // TRACE:Measure
        void MeasureTrace(TraceData &trace);

        // TRACE:Private
    private:
        Vna *vna;
        QString trace_name;

        // TRACE:Private:General
        static const char* ToScpi(TraceFormat format);
        static TraceFormat Scpi_To_TraceFormat(QString scpi);
        static NetworkParameter Scpi_To_NetworkParameter(QString scpi);
        static void ParseParameters(QString readback, NetworkParameter &parameter, uint &port1, uint &port2);
        static QString Parameters_to_Scpi(NetworkParameter parameter, uint port1, uint port2);

        // TRACE:Private:Read Trace
        static uint TraceBufferSize(TraceFormat format, uint points);
        static uint StimulusBufferSize(uint points);
        static void ParseData(TraceData &trace, QString data);
        static void ParseStimulus(RowVector &stimulus_data, QString readback);
        static void GetUnits(TraceData &trace);
    };

private:
    _Trace _trace;
public:
    _Trace& Trace(QString trace_name = "Trc1");


    //**********************
    //** DIAGRAM ***********
    //*********************/

private:
    class _Diagram {
    public:
        _Diagram() {}
        _Diagram (Vna *vna, uint diagram);
        friend class Vna;

        // DIAGRAM:Get
        QStringList GetTraces();
        QVector<uint> GetChannels();
        QString GetTitle();

        // DIAGRAM:Set
        void SetTitle(QString title);

        // DIAGRAM:Private
    private:
        Vna *vna;
        uint diagram;
    };

private:
    _Diagram _diagram;
public:
    _Diagram& Diagram(uint diagram = 1);

};
}


#endif
