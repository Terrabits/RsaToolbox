#ifndef VNA_H
#define VNA_H


// RsaToolbox:
#include "Definitions.h"
#include "GenericBus.h"
#include "Log.h"
#include "TraceData.h"
#include "NetworkData.h"

// Qt
#include <QObject>
#include <QString>
#include <QDir>
#include <QVector>
#include <QStringList>
#include <QScopedPointer>
#include <QColor>
#include <QPen>

// C++ std lib
#include <complex>
#include <vector>


namespace RsaToolbox {
class Vna : public QObject {
private:
    Q_OBJECT
    
    // Private subclasses (defined below)
    class _Channel;
    class _Trace;
    class _Diagram;
    
    //**********************
    //** Vna ***************
    //*********************/
    
public:
    Vna();
    Vna(ConnectionType connectionType, QString instrument_address, uint timeout_ms);
    ~Vna();
    
    void ConnectLog(Log &log);
    void DisconnectLog();
signals: void Print(QString formatted_text);
public:
    
    // VNA:General
    bool isConnected();
    VnaModel GetModel();
    QString GetSerialNumber();
    QString GetFirmwareVersion();
    
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
    void ClearErrors();
    void InitiateSweeps();
    void WaitForSweep();
    void PauseUntilCommandQueueIsFinished();
    void AutoscaleDiagrams();
    
    // VNA:Directory Handling
    QString Dir();
    QString GetDirectory();
    int GetFreeSpace_B();
    QString GetDefaultDirectory();
    void GetDirectoryContents(QStringList &files, QStringList &directories);
    void GetDirectoryContents(QStringList &files, QVector<int> &file_sizes_B,
                              QStringList &directories);
    QStringList GetFileList();
    void GetFileList(QStringList &files, QVector<int> &file_sizes_B);
    void GetFileList(QStringList &files, QVector<int> &file_sizes_B, int &size_of_files_B);
    QStringList GetDirectoryList();
    QString GetCalGroupDirectory();
    void SetDefaultDirectory();
    void SetDirectory(QString directory);
    void SetDirectory(VnaDirectory directory);
    
    // VNA:Status
    bool isDisplayEnabled();
    bool isDisplayDisabled();
    bool isError();
    bool isErrorDisplayEnabled();
    bool isErrorDisplayDisabled();
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
    double GetMinimumPower_dBm();
    double GetMaximumPower_dBm();
    QVector<double> GetSourceAttenuationStates();
    QVector<double> GetReceiverAttenuationStates();
    QVector<double> GetIfBandwidthStates_Hz();
    void GetIfBandwidthStates(QVector<QStringList> &values, QStringList &units);
    QStringList GetOpenSets();
    double GetPortPowerLimit(uint port);
    QVector<double> GetPortPowerLimits();
    ColorScheme GetColorScheme();
    uint GetFontSize_percent();
    QString GetUserPreset();
    QString GetUserCalPreset();
    QStringList GetCalGroups();
    QVector<uint> GetCalibratedChannels();
    
    QVector<uint> GetChannels();
    QStringList GetTraces();
    QVector<uint> GetDiagrams();
    
    // VNA:Set
    void SetIdentificationString(QString id_string);
    void SetOptionsString(QString options_string);
    void SetPortPowerLimit(uint port, double power_limit);
    void SetPortPowerLimits(QVector<double> power_limits);
    void SetPortPowerLimits(double power_limit);
    void SetColorScheme(ColorScheme scheme);
    void SetFontSize_percent(uint size_percent);
    void SetUserPreset(QString filename);
    void SetUserPreset(QDir path, QString filename);
    void SetUserCalPreset(QString cal_name);
    
    // VNA:Enable
    void EnableDisplay(bool isEnabled = true);
    void EnableErrorDisplay(bool isEnabled = true);
    void EnableUserPreset(bool isEnabled = true);
    void EnableUserPresetMapToRst(bool isEnabled = true);
    void EnablePortPowerLimit(uint port, bool isEnabled = true);
    void EnablePortPowerLimits(bool isEnabled = true);
    void EnableRfOutputPower(bool isEnabled = true);
    void EnableDynamicIfBandwidth(bool isEnabled = true);
    void EnableLowPowerAutoCal(bool isEnabled = true);
    
    // VNA:Disable
    void DisableDisplay(bool isDisabled = true);
    void DisableErrorDisplay(bool isDisabled = true);
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
    uint CreateChannel();

    void CreateTrace(QString trace_name, uint channel, NetworkParameter parameter = S_PARAMETER, uint output_port = 2, uint input_port = 1);

    void CreateDiagram(uint diagram);
    uint CreateDiagram();
    
    // VNA:Delete
    void DeleteSet(QString filename);
    void DeleteUserPreset();
    void DeleteCalGroup(QString cal_group);
    void DeleteSwitchMatrices(void);
    
    void DeleteChannel(uint channel);
    void DeleteChannels(QVector<uint> channels);
    void DeleteChannels();
    void DeleteTrace(QString trace_name);
    void DeleteTraces(QStringList traces);
    void DeleteTraces();
    void DeleteDiagram(uint diagram);
    void DeleteDiagrams(QVector<uint> diagrams);
    void DeleteDiagrams();
    
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
    Log *log;
    QScopedPointer<GenericBus> bus;
    
    // VNA:Private:General
    void Reset();
    void Reset(ConnectionType connection_type, QString instrument_address, uint timeout_ms);
    
    bool isRohdeSchwarz(QString identification);
    void GetInstrumentInfo(QString id);
    VnaModel ParseModel(QString id_part_2);
    static const char* ToScpi(ColorScheme scheme);
    static ColorScheme Scpi_To_ColorScheme(QString scpi);
    void PrintInstrumentInfo();
    
    // VNA:Private:Readback
    //     format: "\'Int1,Name_1,Int2,Name_2,...\'"
    static void ParseIndicesFromRead(QString readback, QVector<uint> &indices);
    static void ParseNamesFromRead(QString readback, QStringList &names);
    
    //     format: "Value,Qualifier_String"
    static void ParseValueFromRead(QString readback, uint &value, QString &qualifier);
    static void ParseValueFromRead(QString readback, int &value, QString &qualifier);
    static void ParseValueFromRead(QString readback, double &value, QString &qualifier);
    static QString ValueQualifier_to_Scpi(uint value, QString qualifier);
    static QString ValueQualifier_to_Scpi(int value, QString qualifier);
    static QString ValueQualifier_to_Scpi(double value, QString qualifier);
    
    // VNA:Private:Directory Readback
    static void ParseDir(QString readback,
                         int &size_of_files_B,
                         int &free_space_B,
                         QStringList &files,
                         QVector<int> &file_sizes_B,
                         QStringList &directories);
    
    //**********************
    //** CHANNEL ***********
    //*********************/
    
    class _Channel {
    public:
        _Channel() {}
        _Channel(Vna *vna, uint channel);
        friend class Vna;
        friend class _Trace;
        friend class _Diagram;
        
        // CHANNEL:Actions
        void InitiateSweep();
        
        // CHANNEL:Status
        bool isEnabled();
        bool isSweepDisabled();
        bool isCalibrationEnabled();
        bool isCalibrationDisabled();
        bool isCalibrationPresent();
        
        bool isReceiverPowerCalEnabled_aWave(uint port);
        bool isReceiverPowerCalEnabled_aWave();
        bool isReceiverPowerCalDisabled_aWave(uint port);
        bool isReceiverPowerCalDisabled_aWave();
        bool isReceiverPowerCalEnabled_bWave(uint port);
        bool isReceiverPowerCalEnabled_bWave();
        bool isReceiverPowerCalDisabled_bWave(uint port);
        bool isReceiverPowerCalDisabled_bWave();
        bool isSourcePowerCalEnabled(uint port);
        bool isSourcePowerCalEnabled();
        bool isSourcePowerCalDisabled(uint port);
        bool isSourcePowerCalDisabled();
        bool isPowerCalEnabled();
        bool isPowerCalDisabled();
        bool isPowerCalPresent();
        bool isUserDefinedSParameterEnabled(uint port);
        bool isUserDefinedSParameterDisabled(uint port);
        bool isContinuousSweepEnabled();
        bool isSingleSweepEnabled();
        bool isCompressionCalculated();
        bool isLinearFrequencySweep();
        bool isLogFrequencySweep();
        bool isSegmentedSweep();
        bool isPowerSweep();
        bool isCwMode();
        bool isTimeSweep();
        
        // CHANNEL:Get
        double GetSourceAttenuation_dB(uint port);
        QVector<double> GetSourceAttenuations_dB();
        double GetReceiverAttenuation_dB(uint port);
        QVector<double> GetReceiverAttenuations_dB();
        void GetUserDefinedPort(uint physical_port,
                                uint &source_port,
                                QChar &numerator_wave, uint &numerator_port,
                                QChar &denominator_wave, uint &denominator_port);
        QString GetCalGroup();
        CorrectionState GetCorrectionState();
        SweepType GetSweepType();
        void GetStimulusValues(RowVector &stimulus_data);
        void GetStimulusValues(QRowVector &stimulus_data);
        QVector<uint> GetDiagrams();
        QStringList GetTraces();
        QString GetSelectedTrace();
        double GetDelay_s(uint port);
        QVector<double> GetDelays_s();
        double GetChannelPower_dBm();
        void GetPortPower_dBm(uint port, ReferenceLevel &power_reference, double &power);
        double GetStartFrequency_Hz();
        double GetStopFrequency_Hz();
        double GetFrequencyStepSize_Hz();
        double GetCwFrequency_Hz();
        double GetStartPower_dBm();
        double GetStopPower_dBm();
        double GetIfBandwidth();
        uint GetPoints();
        QVector<uint> GetSweepSegments();
        uint GetNumberOfSweepSegments();
        double GetCompressionLevel_dBm();
        void GetCompressionPoints(double &input_dBm, double &output_dBm);
        QVector<uint> GetSParameterGroupPorts();
        void GetSParameterGroupData(NetworkData &network_data);
        
        // CHANNEL:Set
        void SetCalGroup(QString cal_file);
        void SetSourceAttenuation(uint port, double attenuation_dB);
        void SetSourceAttenuations(double attenuation_dB);
        void SetSourceAttenuations(QVector<double> attenuations_dB);
        void SetReceiverAttenuation(uint port, double attenuation_dB);
        void SetReceiverAttenuations(double attenuation_dB);
        void SetReceiverAttenuations(QVector<double> attenuations_dB);
        void SetUserDefinedSParameter(uint physical_port,
                                      uint source_port,
                                      QChar numerator_wave, uint numerator_port,
                                      QChar denominator_wave, uint denominator_port);
        void SetSweepType(SweepType sweep_type);
        void SetDelay(uint port, double delay_s, SiPrefix prefix = NO_PREFIX);
        void SetDelays(double delay_s, SiPrefix prefix = NO_PREFIX);
        void SetDelays(QVector<double> delays_s, SiPrefix prefix = NO_PREFIX);
        void SetChannelPower_dBm(double power_dBm);
        void SetPortPower(uint port, double power_dBm, ReferenceLevel power_reference = ABSOLUTE_REFERENCE_LEVEL);
        void SetPortPowers(double power_dBm, ReferenceLevel power_reference = ABSOLUTE_REFERENCE_LEVEL);
        void SetPortPowers(QVector<double> powers_dBm, ReferenceLevel power_reference = ABSOLUTE_REFERENCE_LEVEL);
        void SetStartFrequency(double start_frequency, SiPrefix prefix = NO_PREFIX);
        void SetStopFrequency(double stop_frequency, SiPrefix prefix = NO_PREFIX);
        void SetFrequencyStepSize(double step_size, SiPrefix prefix = NO_PREFIX);
        void SetCwFrequency(double cw_frequency, SiPrefix prefix = NO_PREFIX);
        void SetCustomFrequencySweep(QRowVector frequencies, SiPrefix prefix = NO_PREFIX);
        void SetStartPower(double power_dBm);
        void SetStopPower(double power_dBm);
        void SetIfBandwidth(double if_bandwidth_Hz, SiPrefix prefix = NO_PREFIX);
        void SetPoints(uint points);
        void SetCompressionLevel(double level_dBm);
        
        // CHANNEL:Enable
        void EnableCorrection(bool isEnabled = true);
        void EnableUserDefinedSParameter(uint port, bool isEnabled = true);
        void EnableSweep(bool isEnabled = true);
        void EnableContinuousSweep(bool isEnabled = true);
        void EnableCompressionCalc(bool isEnabled = true);
        
        // CHANNEL:Disable
        void DisableCorrection(bool isSweepDisabled = true);
        void DisableCalGroup();
        void DisableUserDefinedSParameter(uint port, bool isDisabled = true);
        void DisableSweep(bool isDisabled = true);
        void DisableContinuousSweep(bool isSweepDisabled = true);
        void DisableDelay(uint port);
        void DisableDelays();
        void DisableCompressionCalc(bool isSweepDisabled = true);
        
        // CHANNEL:Create
        void CreateSParameterGroup(QVector<uint> ports);
        uint CreateSweepSegment();
        
        // CHANNEL:Delete
        void DeleteCorrectionData();
        void DeleteSParameterGroup();
        void DeleteSweepSegment(uint segment);
        void DeleteSweepSegments();
        
        // CHANNEL:Measure
        void MeasureNetwork(NetworkData &network, QVector<uint> ports);
        
        // CHANNEL:Save
        void SaveCalGroup(QString cal_file);
        
        
        // CHANNEL:Private
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
        
        // channel:SWEEP_SEGMENT
        class _SweepSegment {
        public:
            _SweepSegment() {}
            _SweepSegment(Vna *vna, _Channel *channel, uint segment);
            
            // Status
            bool isPoint();
            bool isEnabled();
            bool isDisabled();
            
            // Get
            uint GetPoints();
            double GetStartFrequency_Hz();
            double GetStopFrequency_Hz();
            
            // Set
            void SetPoints(uint points);
            void SetStartFrequency(double frequency, SiPrefix prefix = NO_PREFIX);
            void SetStopFrequency(double frequency, SiPrefix prefix = NO_PREFIX);
            
            // Enable
            void Enable(bool isEnabled = true);
            
            // Disable
            void Disable(bool isDisabled = true);
            
        private:
            Vna *vna;
            _Channel *channel;
            uint segment;
        };
        
    public:
        _SweepSegment& SweepSegment(uint segment);
        
    private:
        _SweepSegment sweep_segment;
        
        
    };
    
public:
    _Channel& Channel(uint channel = 1);
    
private:
    _Channel _channel;
    
    
    //**********************
    //** TRACE *************
    //*********************/
    
private:
    class _Trace {
        // To be defined later...
        class _TimeDomain;

    public:
        _Trace() {}
        _Trace(Vna *vna, QString trace_name);
        friend class Vna;
        friend class _TimeDomain;
        friend class _Channel;
        friend class _Diagram;
        
        // TRACE:Actions
        void Select();
        void Autoscale();
        
        // TRACE:Status
        bool isShown();
        bool isHidden();
        
        // TRACE:Get
        void GetStimulusValues(RowVector &stimulus_data);
        void GetStimulusValues(QRowVector &stimulus_data);
        uint GetChannel();
        void GetParameters(NetworkParameter &parameter, uint &output_port, uint &input_port);
        TraceFormat GetFormat();
        uint GetDiagram();
        
        // TRACE:Set
        void SetParameters(NetworkParameter parameter, uint output_port, uint input_port);
        void SetWaveQuantity(WaveQuantity wave, uint port);
        void SetFormat(TraceFormat format);
        void SetDiagram(uint diagram);
        void SetDisplayProperties(int red, int green, int blue, Qt::PenStyle style = Qt::SolidLine, int width = 1);
        void SetDisplayProperties(QColor color, Qt::PenStyle style = Qt::SolidLine, int width = 1);
        void SetDisplayProperties(QPen pen);

        // TRACE:Show
        void Show(bool isShown = true);
        
        //Trace:Hide
        void Hide(bool isHidden = true);
        
        // TRACE:Copy
        void CopyToMemory(QString memory_trace_name);
        
        // TRACE:Measure
        void MeasureTrace(TraceData &trace);
        
        // TRACE:Write
        void WriteData(QRowVector &data);

        // trace:TIME DOMAIN
    private:
        class _TimeDomain {
        public:
            _TimeDomain() {}
            _TimeDomain(Vna *vna, _Trace *trace);

            // Status
            bool isEnabled();
            bool isDisabled();
            bool isBandPassImpulseResponse();
            bool isLowPassImpulseResponse();
            bool isLowPassStepResponse();
            bool isTimeAxis();
            bool isDistanceAxis();


            // Get
            double GetExtrapolatedDCValue();
            WindowFunction GetWindowFunction();

            // Set
            void SetBandPassImpulseResponse();
            void SetLowPassImpulseResponse();
            void SetLowPassStepResponse();
            void SetExtrapolatedDCValue(double dc_value);
            void SetHarmonicGrid_KeepStopFrequencyAndPoints();
            void SetHarmonicGrid_KeepFrequencySpacingAndPoints();
            void SetHarmonicGrid_KeepStopFrequencyAndSpacing();
            void SetWindowFunction(WindowFunction window);
            void SetStartValue(double start_value, SiPrefix prefix = NO_PREFIX);
            void SetStopValue(double stop_value, SiPrefix prefix = NO_PREFIX);


            // Enable
            void Enable(bool isEnabled = true);
            void EnableContinuousDCExtrapolation(bool isEnabled = true);

            // Disable
            void Disable(bool isDisabled = true);
            void DisableContinuousDCExtrapolation(bool isDisabled = true);

        private:
            Vna *vna;
            _Trace *trace;
        };

    public:
        _TimeDomain TimeDomain;
        
        // TRACE:Private
    private:
        Vna *vna;
        QString trace_name;
        
        // TRACE:Private:General
        static const char* ToScpi(TraceFormat format);
        static TraceFormat Scpi_To_TraceFormat(QString scpi);
        static NetworkParameter Scpi_To_NetworkParameter(QString scpi);
        static void ParseParameters(QString readback, NetworkParameter &parameter, uint &output_port, uint &input_port);
        static QString Parameters_to_Scpi(NetworkParameter parameter, uint output_port, uint input_port);
        
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
        friend class _Channel;
        friend class _Trace;
        
        // DIAGRAM:Actions
        void Autoscale();
        
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
        
        // DIAGRAM:Private:Trace Info
        QVector<uint> GetTraceNumbers();
    };
    
private:
    _Diagram _diagram;
public:
    _Diagram& Diagram(uint diagram = 1);
    
};
}


#endif

