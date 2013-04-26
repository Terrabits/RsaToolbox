
// Rsa
#include "General.h"
#include "RsibBus.h"
#include "VisaBus.h"
#include "Trace.h"
#include "Vna.h"

// Qt
#include <QByteArray>
#include <QtAlgorithms>
#include <QVariant>
#include <QDateTime>
#include <QDebug>

// C++
#include <cstdio>
#include <complex>
#include <vector>

using namespace RsaToolbox;


/***********************
*** MANAGE *************
***********************/

Vna::Vna() {
    log.reset(new Log());
    bus.reset(new RsibBus());
    model = UNKNOWN_MODEL;
    serial_no = "";
    firmware_version = "";
    ports = 0;
    minimum_frequency_Hz = 0;
    maximum_frequency_Hz = 0;
    options = QStringList();
}
Vna::Vna(ConnectionType connection_type, QString instrument_address, unsigned int timeout_ms, QString log_path, QString log_filename, QString program_name, QString program_version) {
    Reset(connection_type, instrument_address, timeout_ms, log_path, log_filename, program_name, program_version);
}
Vna::~Vna() {
    // QScopedPointers solved this problem!
}

void Vna::Reset(void) {
    log.reset(new Log());
    bus.reset(new RsibBus());
    model = UNKNOWN_MODEL;
    serial_no = "";
    firmware_version = "";
    ports = 0;
    minimum_frequency_Hz = 0;
    maximum_frequency_Hz = 0;
    options = QStringList();
}
void Vna::Reset(ConnectionType connection_type, QString instrument_address, unsigned int timeout_ms, QString log_path, QString log_filename, QString program_name, QString program_version) {
    log.reset(new Log(log_path, log_filename, program_name, program_version));
    if (connection_type == TCPIP_CONNECTION)
        bus.reset(new RsibBus(connection_type, instrument_address, timeout_ms));
    else if (connection_type == GPIB_CONNECTION)
        bus.reset(new VisaBus(connection_type, instrument_address, timeout_ms));
    if (bus->isOpen()) {
        QString id = GetIdentificationString();
        if (isRohdeSchwarz(id)) {
            ports = GetPorts();
            minimum_frequency_Hz = GetMinimumFrequency_Hz();
            maximum_frequency_Hz = GetMaximumFrequency_Hz();
            GetInstrumentInfo(id);
            options = GetOptions();
        }
        else {
            model = UNKNOWN_MODEL;
            serial_no = "";
            firmware_version = "";
            ports = 0;
            minimum_frequency_Hz = 0;
            maximum_frequency_Hz = 0;
            options = QStringList();
        }
    }
    else {
        model = UNKNOWN_MODEL;
        serial_no = "";
        firmware_version = "";
        ports = 0;
        minimum_frequency_Hz = 0;
        maximum_frequency_Hz = 0;
        options = QStringList();
    }

    // Signals and slots
    QObject::connect(bus.data(), &GenericBus::Print, log.data(), &Log::Print);
}

/***********************
*** ACTIONS ************
***********************/

void Vna::Preset(void) {
    bus->Write("*RST\n");
}
void Vna::ClearStatus(void) {
    bus->Write("*CLS\n");
}
void Vna::PrintInstrumentInfo(void) {
    QString info;
    QTextStream stream(&info);
    stream << "INSTRUMENT INFO" << endl;
    if (model != UNKNOWN_MODEL) {
        stream << "Make:             Rohde & Schwarz" << endl;
        stream << "Model:            " << ToString(model) << endl;
        stream << "Serial No:        " << serial_no << endl;
        stream << "Firmware Version: " << firmware_version << endl;
        stream << "Min Frequency:    " << FormatValue(minimum_frequency_Hz, 1, HERTZ_UNITS) << endl;
        stream << "Max Frequency:    " << FormatValue(maximum_frequency_Hz, 1, HERTZ_UNITS) << endl;
        stream << "Number of Ports:  " << ports << endl;
        stream << "Options:          ";
        for (int i = 0; i < options.size(); i++) {
            stream << options[i] << endl << "                  ";
        }
        stream << endl << endl;
    }
    else
        stream << "Make: Unknown" << endl << endl << endl;

    stream.flush();
    log->Print(info);
}
void Vna::InitiateSweep(void) {
    bus->Write(":INIT\n");
}
void Vna::InitiateSweep(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 15;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":INIT%d\n", channel);
    bus->Write(QString(buffer));
}
void Vna::FinishPreviousCommandsFirst(void) {
    bus->Write("*WAI\n");
}
void Vna::PauseUntilCommandQueueIsFinished(void) {
    const unsigned int BUFFER_SIZE = 5;
    char buffer[BUFFER_SIZE];
    bus->Query("*OPC?\n", buffer, BUFFER_SIZE);
}


/***********************
*** STATUS *************
***********************/

bool Vna::isChannelEnabled(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d:STAT?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isChannelDisabled(unsigned int channel) {
    return(!isChannelEnabled(channel));
}
bool Vna::isContinuousSweepEnabled(void) {
    const unsigned int BUFFER_SIZE = 5;
    char buffer[BUFFER_SIZE];
    bus->Query(":INIT:CONT?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isContinuousSweepEnabled(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":INIT%d:CONT?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isUserPresetEnabled(void) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:PRES:USER?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isUserPresetDisabled(void) {
    return(!isUserPresetEnabled());
}
bool Vna::isUserPresetMappedToRst(void) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query("SYST:PRES:REM?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isPortPowerLimitEnabled(unsigned int port) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:LLIM?\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isPortPowerLimitEnabled(void) {
    for (unsigned int i = 1; i <= ports; i++)
        if (isPortPowerLimitEnabled(i))
            return(true);
    return(false);
}
bool Vna::isPortPowerLimitDisabled(unsigned int port) {
    return(!isPortPowerLimitEnabled(port));
}
bool Vna::isPortPowerLimitDisabled(void) {
    return(!isPortPowerLimitEnabled());
}
bool Vna::isRfOutputPowerEnabled(void) {
    const unsigned int BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":OUTP?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isRfOutputPowerDisabled(void) {
    return(!isRfOutputPowerEnabled());
}
bool Vna::isDynamicIfBandwidthEnabled(void) {
    const unsigned int BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":BAND:DRED?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isDynamicIfBandwidthDisabled(void) {
    return(!isDynamicIfBandwidthEnabled());
}
bool Vna::isLowPowerAutoCalEnabled(void) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:COMM:RDEV:AKAL:PRED?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isLowPowerAutoCalDisabled(void) {
    return(!isLowPowerAutoCalEnabled());
}

/***********************
*** SELECT *************
***********************/

void Vna::SelectTrace(QString trace_name) {
    unsigned int channel = Trace_GetChannel(trace_name);
    QByteArray trace_byte_array = trace_name.toLocal8Bit();
    char *trace_c_string = trace_byte_array.data();
    const unsigned int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:SEL \'%s\'\n", channel, trace_c_string);
    bus->Write(QString(buffer));
}


/***********************
*** GET ****************
***********************/

// GET:General
QString Vna::GetIdentificationString(void) {
    const unsigned int BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    bus->Query("*IDN?\n", buffer, BUFFER_SIZE);
    return(QString(buffer));
}
QStringList Vna::GetOptions(void) {
    const unsigned int BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    bus->Query("*OPT?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).split(','));
}
unsigned int Vna::GetPorts(void) {
    const unsigned int BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":INST:PORT:COUN?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}
double Vna::GetMinimumFrequency_Hz(void) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:FREQ? MIN\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetMaximumFrequency_Hz(void) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:FREQ? MAX\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetSourceAttenuation_dB(unsigned int port) {
    if (model != ZVA_MODEL)
        return(0);
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:ATT?\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetSourceAttenuation_dB(unsigned int port, unsigned int channel) {
    if (model != ZVA_MODEL)
        return(0);
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW%d:ATT?\n", channel, port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetReceiverAttenuation_dB(unsigned int port) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":POW:ATT? %d\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetReceiverAttenuation_dB(unsigned int port, unsigned int channel) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:POW:ATT? %d\n", channel, port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetPortPowerLimit(unsigned int port) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:LLIM:VAL?\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
QVector<double> Vna::GetPortPowerLimits(void) {
    QVector<double> power_limits;
    for (unsigned int i = 1; i <= ports; i++)
        power_limits.append(GetPortPowerLimit(i));
    return(power_limits);
}
ColorScheme Vna::GetColorScheme(void) {
    const unsigned int BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:DISP:COL?\n", buffer, BUFFER_SIZE);
    return(Scpi_To_ColorScheme(buffer));
}
unsigned int Vna::GetFontSize_percent(void) {
    const unsigned int BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":DISP:RFS?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}
QString Vna::GetUserPreset(void) {
    const unsigned int BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:PRES:USER:NAME?\n", buffer, BUFFER_SIZE);
    QString user_preset = QString(buffer);
    user_preset.remove(0,1); // remove 1st char: "\'"
    user_preset.chop(1); // remove last char: "\'"
    return(user_preset);
}

// GET:Channel
QVector<unsigned int> Vna::GetChannels(void) {
    const unsigned int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    bus->Query(":CONF:CHAN:CAT?\n", buffer, BUFFER_SIZE);
    QVector<unsigned int> channels;
    ParseIndicesFromRead(buffer, channels);
    return(channels);
}
SweepType Vna::GetSweepType(void) {
    const unsigned int BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    bus->Query(":SWE:TYPE?\n", buffer, BUFFER_SIZE);
    return(Scpi_To_SweepType(QString(buffer)));
}
SweepType Vna::GetSweepType(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 25;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:TYPE?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(Scpi_To_SweepType(QString(buffer)));
}
void Vna::GetStimulusValues(QString trace_name, RowVector &stimulus_data) {
    unsigned int channel = Trace_GetChannel(trace_name);
    GetStimulusValues(channel, stimulus_data);
}
void Vna::GetStimulusValues(unsigned int channel, RowVector &stimulus_data) {
    unsigned int points = GetPoints(channel);
    unsigned int buffer_size = StimulusBufferSize(points);
    QScopedPointer<char> buffer(new char[buffer_size]);
    sprintf(buffer.data(), ":CALC%d:DATA:STIM?\n", channel);
    bus->Query(QString(buffer.data()), buffer.data(), buffer_size);
    ParseTraceStimulus(stimulus_data, buffer.data());
}
QVector<unsigned int> Vna::Channel_GetDiagrams(unsigned int channel) {
    QStringList traces = Channel_GetTraces(channel);
    QVector<unsigned int> diagrams;
    for (int i = 0; i < traces.length(); i++) {
        unsigned int currentDiagram = Trace_GetDiagram(traces[i]);
        if (!diagrams.contains(currentDiagram))
            diagrams.append(currentDiagram);
    }
    qSort(diagrams);
    return(diagrams);
}
QStringList Vna::Channel_GetTraces(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d:TRAC:CAT?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QStringList traces;
    ParseNamesFromRead(buffer, traces);
    return(traces);
}
QString Vna::Channel_GetSelectedTrace(void) {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    bus->Query(":CALC:PAR:SEL?\n", buffer, BUFFER_SIZE);
    QString selected_trace = QString(buffer);
    selected_trace.remove(0,1); // remove 1st char
    selected_trace.chop(1); // remove last char
    return(selected_trace);
}
QString Vna::Channel_GetSelectedTrace(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:SEL?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QString selected_trace = QString(buffer);
    selected_trace.remove(0,1); // remove first char
    selected_trace.chop(1); // remove last char
    return(selected_trace);
}
double Vna::GetDelay_s(unsigned int port) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CORR:EDEL%d:TIME?\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetDelay_s(unsigned int port, unsigned int channel) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:CORR:EDEL%d:TIME?\n", channel, port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
QVector<double> Vna::GetDelays_s(void) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QVector<double> delays;
    for (unsigned int port = 1; port <= ports; port++) {
        sprintf(buffer, ":CORR:EDEL%d:TIME?\n", port);
        bus->Query(QString(buffer), buffer, BUFFER_SIZE);
        delays.append(QString(buffer).toDouble());
    }
    return(delays);
}
QVector<double> Vna::GetDelays_s(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QVector<double> delays;
    for (unsigned int port = 1; port <= ports; port++) {
        sprintf(buffer, "SENS%d:CORR:EDEL%d:TIME?\n", channel, port);
        bus->Query(QString(buffer), buffer, BUFFER_SIZE);
        delays.append(QString(buffer).toDouble());
    }
    return(delays);
}
double Vna::GetChannelPower_dBm(void) {
    const unsigned int BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    bus->Query(":SOUR:POW?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetChannelPower_dBm(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
void Vna::GetPortPower_dBm(unsigned int port, ReferenceLevel &power_reference, double &power) {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:OFFS?\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QString reference_string;
    ParseValueFromRead(QString(buffer), power, reference_string);
    power_reference = Scpi_To_ReferenceLevel(reference_string);
}
void Vna::GetPortPower_dBm(unsigned int port, unsigned int channel, ReferenceLevel &power_reference, double &power) {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW%d:OFFS?\n", channel, port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QString reference_string;
    ParseValueFromRead(QString(buffer), power, reference_string);
    power_reference = Scpi_To_ReferenceLevel(reference_string);
}
double Vna::GetStartFrequency_Hz(void) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":FREQ:STAR?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetStartFrequency_Hz(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:FREQ:STAR?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetStopFrequency_Hz(void) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":FREQ:STOP?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetStopFrequency_Hz(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "SENS%d:FREQ:STOP?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetIfBandwidth(void) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":BAND?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetIfBandwidth(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:BAND?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
unsigned int Vna::GetPoints(void) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":SWE:POIN?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}
unsigned int Vna::GetPoints(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:POIN?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}

// GET:Diagram
QVector<unsigned int> Vna::GetDiagrams(void) {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    bus->Query(":DISP:CAT?\n", buffer, BUFFER_SIZE);
    QVector<unsigned int> diagrams;
    ParseIndicesFromRead(buffer, diagrams);
    return(diagrams);
}
QStringList Vna::Diagram_GetTraces(unsigned int diagram) {
    const unsigned int BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    QStringList traces;
    sprintf(buffer, ":DISP:WIND%d:TRAC:CAT?\n", diagram);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    ParseNamesFromRead(buffer, traces);
    qSort(traces);
    return(traces);
}
QVector<unsigned int> Vna::Diagram_GetChannels(unsigned int diagram) {
    QStringList traces = Diagram_GetTraces(diagram);
    QVector<unsigned int> channels;
    for (int i = 0; i < traces.length(); i++) {
        unsigned int current_channel = Trace_GetChannel(traces[i]);
        if (!channels.contains(current_channel))
            channels.append(current_channel);
    }
    qSort(channels);
    return(channels);
}
QString Vna::GetTitle(unsigned int diagram) {
    const unsigned int BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:TITL:DATA?\n", diagram);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QString title(buffer);
    title.remove(0,1);
    title.chop(1);
    return(title);
}

// GET:Trace
QStringList Vna::GetTraces(void) {
    const unsigned int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    bus->Query(":CONF:TRAC:CAT?\n", buffer, BUFFER_SIZE);
    QStringList traces;
    ParseNamesFromRead(buffer, traces);
    return(traces);
}
unsigned int Vna::Trace_GetChannel(QString trace_name) {
    QByteArray c_string = trace_name.toLocal8Bit();
    const unsigned int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:TRAC:CHAN:NAME:ID? \'%s\'\n", c_string.constData());
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}
void Vna::Trace_GetParameters(QString trace_name, NetworkParameter &parameter, unsigned int &port1, unsigned int &port2) {
    QByteArray trace_byte_array = trace_name.toLocal8Bit();
    char * trace_name_c = trace_byte_array.data();
    unsigned int channel = Trace_GetChannel(trace_name);
    const unsigned int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:MEAS? \'%s\'\n", channel, trace_name_c);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    ParseTraceParameters(QString(buffer), parameter, port1, port2);
}
TraceFormat Vna::Trace_GetFormat(QString trace_name) {
    QString selected_trace = Channel_GetSelectedTrace();
    SelectTrace(trace_name);
    unsigned int channel = Trace_GetChannel(trace_name);
    const unsigned int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:FORM?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    if (trace_name != selected_trace)
        SelectTrace(selected_trace);
    return(Scpi_To_TraceFormat(QString(buffer)));
}
unsigned int Vna::Trace_GetDiagram(QString trace_name) {
    const unsigned int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    QByteArray byte_array = trace_name.toLocal8Bit();
    char *trace_c_string = byte_array.data();
    sprintf(buffer, ":CONF:TRAC:WIND:TRAC? \'%s\'\n", trace_c_string);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}


/***********************
*** SET ****************
***********************/

// SET:General
void Vna::SetIdentificationString(QString id_string)  {
    if (!(model == ZNB_MODEL || model == ZNC_MODEL))
        return;
    QByteArray c_string = id_string.toLocal8Bit();
    const unsigned int BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:IDEN \'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetOptionsString(QString options_string)  {
    if (!(model == ZNB_MODEL || model == ZNC_MODEL))
        return;
    QByteArray c_string = options_string.toLocal8Bit();
    const unsigned int BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:OPT \'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetSourceAttenuation_dB(unsigned int port, double attenuation)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:ATT %f\n", port, attenuation);
    bus->Write(QString(buffer));
}
void Vna::SetSourceAttenuation_dB(unsigned int port, unsigned int channel, double attenuation)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW%d:ATT %f\n", channel, port, attenuation);
    bus->Write(QString(buffer));
}
void Vna::SetSourceAttenuations_dB(double attenuation) {
    for (unsigned int i = 1; i <= ports; i++)
        SetSourceAttenuation_dB(i, attenuation);
}
void Vna::SetSourceAttenuations_dB(QVector<double> attenuations) {
    if (attenuations.size() != ports)
        return;
    for (unsigned int i = 1; i <= ports; i++)
        SetSourceAttenuation_dB(i, attenuations[i-1]);
}
void Vna::SetSourceAttenuations_dB(unsigned int channel, double attenuation) {
    for (unsigned int i = 1; i <= ports; i++)
        SetSourceAttenuation_dB(i, channel, attenuation);
}
void Vna::SetSourceAttenuations_dB(unsigned int channel, QVector<double> attenuations) {
    if (attenuations.size() != ports)
        return;
    for (unsigned int i = 1; i <= ports; i++)
        SetSourceAttenuation_dB(i, channel, attenuations[i-1]);
}
void Vna::SetReceiverAttenuation_dB(unsigned int port, double attenuation)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":POW:ATT %d, %f\n", port, attenuation);
    bus->Write(QString(buffer));
}
void Vna::SetReceiverAttenuation_dB(unsigned int port, unsigned int channel, double attenuation)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:POW:ATT %d, %f\n", channel, port, attenuation);
    bus->Write(QString(buffer));
}
void Vna::SetReceiverAttenuations_dB(double attenuation) {
    for (unsigned int i = 1; i <= ports; i++)
        SetReceiverAttenuation_dB(i, attenuation);
}
void Vna::SetReceiverAttenuations_dB(QVector<double> attenuations) {
    if (attenuations.size() != ports)
        return;
    for (unsigned int i = 1; i <= ports; i++)
        SetReceiverAttenuation_dB(i, attenuations[i-1]);
}
void Vna::SetReceiverAttenuations_dB(unsigned int channel, double attenuation) {
    for (unsigned int i = 1; i <= ports; i++)
        SetReceiverAttenuation_dB(i, channel, attenuation);
}
void Vna::SetReceiverAttenuations_dB(unsigned int channel, QVector<double> attenuations) {
    if (attenuations.size() != ports)
        return;
    for (unsigned int i = 1; i <= ports; i++)
        SetReceiverAttenuation_dB(i, channel, attenuations[i-1]);
}
void Vna::SetPortPowerLimit(unsigned int port, double power_limit) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:LLIM:VAL %f\n", port, power_limit);
    bus->Write(QString(buffer));
}
void Vna::SetPortPowerLimits(QVector<double> power_limits) {
    if (power_limits.size() != ports)
        return;
    for (unsigned int i = 1; i <= ports; i++)
        SetPortPowerLimit(i, power_limits[i-1]);
}
void Vna::SetPortPowerLimits(double power_limit) {
    for (unsigned int i = 1; i <= ports; i++)
        SetPortPowerLimit(i, power_limit);
}
void Vna::SetColorScheme(ColorScheme scheme)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:DISP:COL %s\n", ToScpi(scheme));
    bus->Write(QString(buffer));
}
void Vna::SetFontSize_percent(unsigned int size_percent)  {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:RFS %d\n", size_percent);
    bus->Write(QString(buffer));
}
void Vna::SetUserPreset(QString filename)  {
    if (!filename.contains(ToStateFileExtension(model)))
        filename = filename + ToStateFileExtension(model);
    QByteArray c_string = filename.toLocal8Bit();
    const unsigned int BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:PRES:USER:NAME \'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetUserPreset(QDir path, QString filename)  {
    const unsigned int BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    if (!filename.contains(ToStateFileExtension(model)))
        filename = filename + ToStateFileExtension(model);
    filename = AppendPath(path, filename);
    filename = QDir::toNativeSeparators(filename);
    QByteArray c_string = filename.toLocal8Bit();
    sprintf(buffer, ":SYST:PRES:USER:NAME \'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}

// SET:Channel
void Vna::SetSweepType(SweepType sweep_type) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SWE:TYPE %s\n", ToScpi(sweep_type));
    bus->Write(QString(buffer));
}
void Vna::SetSweepType(unsigned int channel, SweepType sweep_type) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:TYPE %s\n", channel, ToScpi(sweep_type));
    bus->Write(QString(buffer));
}
void Vna::Channel_SetSelectedTrace(QString trace_name)  {
    QByteArray c_string = trace_name.toLocal8Bit();
    const unsigned int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    unsigned int channel = Trace_GetChannel(trace_name);
    sprintf(buffer, ":CALC%d:PAR:SEL \'%s\'\n", channel, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetDelay(unsigned int port, double delay, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = (ToString(prefix) + ToString(SECONDS_UNITS)).toLocal8Bit();
    sprintf(buffer, ":CORR:EDEL%d:TIME %f%s\n", port, delay, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetDelay(unsigned int port, unsigned int channel, double delay, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = (ToString(prefix) + ToString(SECONDS_UNITS)).toLocal8Bit();
    sprintf(buffer, ":SENS%d:CORR:EDEL%d:TIME %f%s\n", channel, port, delay, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetDelays(QVector<double> delays, SiPrefix prefix)  {
    if (delays.size() != ports)
        return;
    for (unsigned int i = 1; i <= ports; i++)
        SetDelay(i, delays[i-1], prefix);
}
void Vna::SetDelays(unsigned int channel, QVector<double> delays, SiPrefix prefix)  {
    if (delays.size() != ports)
        return;
    for (unsigned int i = 1; i <= ports; i++)
        SetDelay(i, channel, delays[i-1], prefix);
}
void Vna::SetChannelPower_dBm(double power_dBm)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW %f\n", power_dBm);
    bus->Write(QString(buffer));
}
void Vna::SetChannelPower_dBm(unsigned int channel, double power_dBm)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW %f\n", channel, power_dBm);
    bus->Write(QString(buffer));
}
void Vna::SetPortPower(unsigned int port, double power_dBm, ReferenceLevel power_reference)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString power_scpi = ValueQualifier_to_Scpi(power_dBm, ToScpi(power_reference));
    QByteArray c_string = power_scpi.toLocal8Bit();
    sprintf(buffer, ":SOUR:POW%d:OFFS %s\n", port, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetPortPower(unsigned int port, unsigned int channel, double power_dBm, ReferenceLevel power_reference)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString power_scpi = ValueQualifier_to_Scpi(power_dBm, ToScpi(power_reference));
    QByteArray c_string = power_scpi.toLocal8Bit();
    sprintf(buffer, ":SOUR%d:POW%d:OFFS %s\n", channel, port, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetStartFrequency(double start_frequency, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":FREQ:STAR %f%s\n", start_frequency, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetStartFrequency(unsigned int channel, double start_frequency, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":SENS%d:FREQ:STAR %f%s\n", channel, start_frequency, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetStopFrequency(double stop_frequency, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":FREQ:STOP %f%s\n", stop_frequency, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetStopFrequency(unsigned int channel, double stop_frequency, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":SENS%d:FREQ:STOP %f%s\n", channel, stop_frequency, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetIfBandwidth(double if_bandwidth, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":BAND %f%s\n", if_bandwidth, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetIfBandwidth(unsigned int channel, double if_bandwidth, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, "SENS%d:BAND %f%s\n", channel, if_bandwidth, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetPoints(unsigned int points)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SWE:POIN %d\n", points);
    bus->Write(QString(buffer));
}
void Vna::SetPoints(unsigned int channel, unsigned int points)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:POIN %d\n", channel, points);
    bus->Write(QString(buffer));
}

// SET:Diagram
void Vna::SetTitle(unsigned int diagram, QString title)  {
    const unsigned int BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = title.toLocal8Bit();
    sprintf(buffer, ":DISP:WIND%d:TITL:DATA \'%s\'\n", diagram, c_string.constData());
    bus->Write(QString(buffer));
}

// SET:Trace
//void Vna::Trace_SetChannel(QString trace_name, unsigned int channel)  {}
void Vna::Trace_SetParameters(QString trace_name, NetworkParameter parameter, unsigned int port1, unsigned int port2)  {
    QByteArray c_name = trace_name.toLocal8Bit();
    QByteArray c_parameters = TraceParameters_to_Scpi(parameter, port1, port2).toLocal8Bit();
    unsigned int channel = Trace_GetChannel(trace_name);
    const unsigned int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:MEAS \'%s\', \'%s\'\n", channel, c_name.constData(), c_parameters.constData());
    bus->Write(QString(buffer));
}
void Vna::Trace_SetFormat(QString trace_name, TraceFormat format)  {
    QString selected_trace = Channel_GetSelectedTrace();
    SelectTrace(trace_name);
    unsigned int channel = Trace_GetChannel(trace_name);
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:FORM %s\n", channel, ToScpi(format));
    bus->Write(QString(buffer));
}
//void Vna::Trace_SetDiagram(QString trace_name, unsigned int diagram)  {}


/***********************
*** ENABLE *************
***********************/

void Vna::EnableContinuousSweep(bool isEnabled) {
    if (isEnabled)
        bus->Write(":INIT:CONT 1\n");
    else
        bus->Write(":INIT:CONT 0\n");
}
void Vna::EnableContinuousSweep(int channel, bool isEnabled) {
    EnableContinuousSweep((unsigned int)channel, isEnabled);
}
void Vna::EnableContinuousSweep(unsigned int channel, bool isEnabled) {
    const unsigned int BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    if (isEnabled) {
        sprintf(buffer, ":INIT%d:CONT 1\n", channel);
        bus->Write(QString(buffer));
    }
    else {
        sprintf(buffer, ":INIT%d:CONT 0\n", channel);
        bus->Write(QString(buffer));
    }
}
void Vna::EnableContinuousSweep(double channel, bool isEnabled) {
    EnableContinuousSweep((unsigned int)channel, isEnabled);
}
void Vna::EnableUserPreset(bool isEnabled) {
    if (isEnabled)
        bus->Write(":SYST:PRES:USER 1\n");
    else
        bus->Write(":SYST:PRES:USER 0\n");
}
void Vna::EnableUserPresetMapToRst(bool isEnabled) {
    if (isEnabled)
        bus->Write(":SYST:PRES:REM 1\n");
    else
        bus->Write(":SYST:PRES:REM 0\n");
}
void Vna::EnablePortPowerLimit(unsigned int port, bool isEnabled) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":SOUR:POW%d:LLIM 1\n", port);
    else
        sprintf(buffer, ":SOUR:POW%d:LLIM 0\n", port);
    bus->Write(QString(buffer));
}
void Vna::EnablePortPowerLimits(bool isEnabled) {
    for (unsigned int i = 1; i <= ports; i++)
        EnablePortPowerLimit(i, isEnabled);
}
void Vna::EnableRfOutputPower(bool isEnabled) {
    if (isEnabled)
        bus->Write(":OUTP 1\n");
    else
        bus->Write(":OUTP 0\n");
}
void Vna::EnableDynamicIfBandwidth(bool isEnabled) {
    if (isEnabled)
        bus->Write(":BAND:DRED 1\n");
    else
        bus->Write(":BAND:DRED 0\n");
}
void Vna::EnableLowPowerAutoCal(bool isEnabled) {
    if (isEnabled)
        bus->Write(":SYST:COMM:RDEV:AKAL:PRED 1\n");
    else
        bus->Write(":SYST:COMM:RDEV:AKAL:PRED 0\n");
}


/***********************
*** DISABLE ************
***********************/

void Vna::DisableCustomIdString(bool isDisabled) {
    if (isDisabled) {
        if (model == ZNB_MODEL || model == ZNC_MODEL)
            bus->Write(":SYST:IDEN:FACT\n");
    }
}
void Vna::DisableCustomOptionsString(bool isDisabled) {
    if (isDisabled) {
        if (model == ZNB_MODEL || model == ZNC_MODEL)
        bus->Write(":SYST:OPT:FACT\n");
    }
}
void Vna::DisableEmulation() {
    bus->Write(":SYST:LANG \'SCPI\'\n");
}
void Vna::DisableContinuousSweep(bool isDisabled) {
    EnableContinuousSweep(!isDisabled);
}
void Vna::DisableContinuousSweep(int channel, bool isDisabled) {
    EnableContinuousSweep((unsigned int)channel, !isDisabled);
}
void Vna::DisableContinuousSweep(unsigned int channel, bool isDisabled) {
    EnableContinuousSweep(channel, !isDisabled);
}
void Vna::DisableContinuousSweep(double channel, bool isDisabled) {
    EnableContinuousSweep((unsigned int)channel, !isDisabled);
}
void Vna::DisableDelay(unsigned int port) {
    SetDelay(port, 0);
}
void Vna::DisableDelay(unsigned int port, unsigned int channel) {
    SetDelay(port, channel, 0);
}
void Vna::DisableDelays(void) {
    QVector<double> zero_delays(ports, 0);
    SetDelays(zero_delays);
}
void Vna::DisableDelays(unsigned int channel) {
    QVector<double> zero_delays(ports, 0);
    SetDelays(channel, zero_delays);
}
void Vna::DisableUserPreset(bool isDisabled) {
    EnableUserPreset(!isDisabled);
}
void Vna::DisableUserPresetMapToRst(bool isDisabled) {
    EnableUserPresetMapToRst(!isDisabled);
}
void Vna::DisablePortPowerLimit(unsigned int port, bool isDisabled) {
    EnablePortPowerLimit(port, !isDisabled);
}
void Vna::DisablePortPowerLimits(bool isDisabled) {
    EnablePortPowerLimits(!isDisabled);
}
void Vna::DisableRfOutputPower(bool isDisabled) {
    EnableRfOutputPower(!isDisabled);
}
void Vna::DisableDynamicIfBandwidth(bool isDisabled) {
    EnableDynamicIfBandwidth(!isDisabled);
}
void Vna::DisableLowPowerAutoCal(bool isDisabled) {
    EnableLowPowerAutoCal(!isDisabled);
}


/***********************
*** CREATE *************
***********************/

void Vna::CreateChannel(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d:MEAS 1\n", channel);
    bus->Write(QString(buffer));
}
void Vna::CreateSParameterGroup(unsigned int channel, QVector<unsigned int> ports) {
    unsigned int number_of_ports = ports.size();
    if (number_of_ports <= 0)
        return;
    const unsigned int BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    QString ports_list = QVariant(ports[0]).toString();
    for (unsigned int i = 1; i < number_of_ports; i++) {
        ports_list = ports_list + "," + QVariant(ports[i]).toString();
    }
    QByteArray c_ports_list = ports_list.toLocal8Bit();
    sprintf(buffer, ":CALC%d:PAR:DEF:SGR %s\n", channel, c_ports_list.constData());
    bus->Write(QString(buffer));
}
void Vna::CreateDiagram(unsigned int diagram) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:STAT 1\n", diagram);
    bus->Write(QString(buffer));
}
void Vna::CreateTrace(QString trace_name, unsigned int channel, NetworkParameter parameter, unsigned int port1, unsigned int port2) {
    const unsigned int BUFFER_SIZE = 150;
    char buffer[BUFFER_SIZE];
    QByteArray c_name = trace_name.toLocal8Bit();
    QByteArray c_parameters = TraceParameters_to_Scpi(parameter, port1, port2).toLocal8Bit();
    sprintf(buffer, ":CALC%d:PAR:SDEF \'%s\', \'%s\'\n", channel, c_name.constData(), c_parameters.constData());
    bus->Write(QString(buffer));
}


/***********************
*** DELETE *************
***********************/

void Vna::DeleteChannel(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d 0\n", channel);
    bus->Write(QString(buffer));
}
void Vna::DeleteSParameterGroup(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:DEL:SGR\n", channel);
    bus->Write(QString(buffer));
}
void Vna::DeleteDiagram(unsigned int diagram) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:STAT 0\n", diagram);
    bus->Write(QString(buffer));
}
void Vna::DeleteTrace(QString trace_name) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    unsigned int channel = Trace_GetChannel(trace_name);
    QByteArray c_string = trace_name.toLocal8Bit();
    sprintf(buffer, ":CALC%d:PAR:DEL \'%s\'\n", channel, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::DeleteUserPreset(void) {
    bus->Write(QString(":SYST:PRES:USER:NAME \'\'\n"));
}


/***********************
*** MEASURE ************
***********************/

void Vna::MeasureTrace(QString trace_name, Trace &trace) {
    // Info, buffer
    unsigned int channel = Trace_GetChannel(trace_name);
    unsigned int points = GetPoints(channel);
    TraceFormat format = Trace_GetFormat(trace_name);
    unsigned int buffer_size = TraceBufferSize(format, points);
    QScopedPointer<char> buffer(new char[buffer_size]);
    QByteArray c_trace_name = trace_name.toLocal8Bit();

    // Handle analyzer discrepancy
    if (model == ZNB_MODEL || model == ZNC_MODEL) {
        sprintf(buffer.data(), ":CALC:DATA:TRAC? \'%s\', FDAT\n", c_trace_name.constData());
    }
    else {
        // ZVA doesn't have "CALC:DATA:TRAC?" command. Use a different method.
        SelectTrace(trace_name);
        sprintf(buffer.data(), ":CALC%d:DATA? FDAT", channel);
    }

    // Read data
    if (isContinuousSweepEnabled()) {
        DisableContinuousSweep(channel);
        InitiateSweep(channel);
        FinishPreviousCommandsFirst();
        bus->Query(QString(buffer.data()), buffer.data(), buffer_size);
        EnableContinuousSweep();
    }
    else {
        InitiateSweep(channel);
        FinishPreviousCommandsFirst();
        bus->Query(QString(buffer.data()), buffer.data(), buffer_size);
    }

    // Parse data
    Trace_GetParameters(trace_name, trace.network_parameter, trace.port1, trace.port2);
    trace.points = points;
    trace.sweep_type = GetSweepType(channel);
    trace.format = format;
    trace.date_time = QDateTime::currentDateTime();
    GetTraceUnits(trace);
    ParseTraceData(trace, buffer.data());
    GetStimulusValues(channel, trace.stimulus_points);
}
void Vna::MeasureNetwork(Network &network, unsigned int channel, QVector<unsigned int> ports) {
    // (Temporary?) Sanity check
    SweepType sweep_type = GetSweepType(channel);
    if (sweep_type == POWER_SWEEP || sweep_type == CW_MODE_SWEEP || sweep_type == TIME_SWEEP)
        return;

    // info, buffer
    CreateSParameterGroup(channel, ports);
    network.date_time = QDateTime::currentDateTime();
    network.ports = ports.size();
    network.points = GetPoints(channel);
    unsigned int buffer_size = NetworkBufferSize(network.points, network.ports);
    QScopedPointer<char> buffer(new char[buffer_size]);
    sprintf(buffer.data(), ":CALC%d:DATA:SGR? MDAT\n", channel);

    // Measure
    if (isContinuousSweepEnabled()) {
        DisableContinuousSweep(channel);
        InitiateSweep(channel);
        FinishPreviousCommandsFirst();
        bus->Query(QString(buffer.data()), buffer.data(), buffer_size);
        EnableContinuousSweep();
    }
    else {
        InitiateSweep(channel);
        FinishPreviousCommandsFirst();
        bus->Query(QString(buffer.data()), buffer.data(), buffer_size);
    }

    // Parse
    ParseNetworkData(network, buffer.data());
    network.frequency_prefix = NO_PREFIX;
    GetStimulusValues(channel, network.frequency);

    // Clean up
    DeleteSParameterGroup(channel);
}


/***********************
*** SAVE ***************
***********************/

void Vna::SaveCurrentState(QString name) {
    const unsigned int BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    // Fix save directory issue with firmware
    name = "./RecallSets/" + name;
    if (!name.contains(ToStateFileExtension(model)))
        name = name + ToStateFileExtension(model);
    QByteArray c_string = name.toLocal8Bit();
    sprintf(buffer, ":MMEM:STOR:STAT 1,\'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SaveCurrentState(QDir path, QString name) {
    const unsigned int BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    name = AppendPath(path, name);
    name = QDir::toNativeSeparators(name);
    if (!name.contains(ToStateFileExtension(model)))
        name = name + ToStateFileExtension(model);
    QByteArray c_string = name.toLocal8Bit();
    sprintf(buffer, ":MMEM:STOR:STAT 1,\'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}

/***********************
*** PRIVATE ************
***********************/

bool Vna::isRohdeSchwarz(QString id) {
    return(
                id.contains("Rohde", Qt::CaseInsensitive)
                && id.contains("Schwarz", Qt::CaseInsensitive));
}
void Vna::GetInstrumentInfo(QString id) {
    QStringList id_list = id.split(',');
    model = ParseModel(id_list[1]);
    serial_no = id_list[2];
    firmware_version = id_list[3];
}
VnaModel Vna::ParseModel(QString id_part_2) {
    if (id_part_2.contains("ZVA", Qt::CaseInsensitive))
        return(ZVA_MODEL);
    if (id_part_2.contains("ZVB", Qt::CaseInsensitive))
        return(ZVB_MODEL);
    if (id_part_2.contains("ZVH", Qt::CaseInsensitive))
        return(ZVH_MODEL);
    if (id_part_2.contains("ZVL", Qt::CaseInsensitive))
        return(ZVL_MODEL);
    if (id_part_2.contains("ZVT", Qt::CaseInsensitive))
        return(ZVT_MODEL);
    if (id_part_2.contains("ZNB", Qt::CaseInsensitive))
        return(ZNB_MODEL);
    if (id_part_2.contains("ZNC", Qt::CaseInsensitive))
        return(ZNC_MODEL);
    else return(UNKNOWN_MODEL);
}

// readback format: "\'Int1,Name_1,Int2,Name_2,...\'"
void Vna::ParseIndicesFromRead(QString readback, QVector<unsigned int> &indices) {
    // Assumes readback format: '1,Name_1,2,Name_2,...'
    indices.clear();
    readback.remove(0, 1);
    readback.chop(1);
    QStringList words = readback.split(',');
    for (int i = 0; i < words.length(); i += 2) {
        indices.append(words[i].toUInt());
    }
}
void Vna::ParseNamesFromRead(QString readback, QStringList &names) {
    // Assumes readback format: '1,Name_1,2,Name_2...'
    names.clear();
    readback.remove(0,1);
    readback.chop(1);
    names = readback.split(',');
    if (names.length() % 2 == 1) return;
    for (int i = names.length() - 2; i >= 0; i -= 2) {
        names.removeAt(i);
    }
}

// readback format: "Value,Qualifier_String"
void Vna::ParseValueFromRead(QString readback, unsigned int &value, QString &qualifier) {
    QStringList list = readback.split(',');
    value = list[0].toUInt();
    qualifier = list[1];
}
void Vna::ParseValueFromRead(QString readback, int &value, QString &qualifier) {
    QStringList list = readback.split(',');
    value = list[0].toInt();
    qualifier = list[1];
}
void Vna::ParseValueFromRead(QString readback, double &value, QString &qualifier) {
    QStringList list = readback.split(',');
    value = list[0].toDouble();
    qualifier = list[1];
}
QString Vna::ValueQualifier_to_Scpi(unsigned int value, QString qualifier) {
    QVariant value_variant(value);
    return(value_variant.toString() + "," + qualifier);
}
QString Vna::ValueQualifier_to_Scpi(int value, QString qualifier) {
    QVariant value_variant(value);
    return(value_variant.toString() + "," + qualifier);
}
QString Vna::ValueQualifier_to_Scpi(double value, QString qualifier) {
    QVariant value_variant(value);
    return(value_variant.toString() + "," + qualifier);
}

// Trace format: "\'S12\'" or "\'S1213\'"
void Vna::ParseTraceParameters(QString readback, NetworkParameter &parameter, unsigned int &port1, unsigned int &port2) {
    readback.remove(0,1);
    readback.chop(1);
    parameter = Scpi_To_NetworkParameter(readback.mid(0, 1));
    if (readback.length() == 3) {
        // "%c%1d%1d" format
        port1 = readback.mid(1,1).toUInt();
        port2 = readback.mid(2,1).toUInt();
    }
    else {
        // "%c%2d%2d" format
        port1 = readback.mid(1,2).toUInt();
        port2 = readback.mid(3,2).toUInt();
    }
}
QString Vna::TraceParameters_to_Scpi(NetworkParameter parameter, unsigned int port1, unsigned int port2) {
    QString port1_string = QVariant(port1).toString();
    QString port2_string = QVariant(port2).toString();
    if (port1_string.length() == port2_string.length())
        return(ToString(parameter) + port1_string + port2_string);

    // Fix length mismatch
    if (port1_string.length() < port2_string.length())
        port1_string =  "0" + port1_string;
    else
        port2_string = "0" + port2_string;
    return(ToString(parameter) + port1_string + port2_string);
}

// Read Trace
unsigned int Vna::TraceBufferSize(TraceFormat format, unsigned int points) {
    const unsigned int SIZE_PER_POINT = 16;
    if (format == SMITH_CHART_TRACE || format == POLAR_CHART_TRACE
            ||format == INVERSE_SMITH_CHART_TRACE)
    {
        // (Re, Im) pairs:
        return(2 * SIZE_PER_POINT * points);
    }
    else {
        return(SIZE_PER_POINT * points);
    }
}
unsigned int Vna::StimulusBufferSize(unsigned int points) {
    const unsigned int SIZE_PER_POINT = 16;
    return((unsigned int)SIZE_PER_POINT * points);
}
void Vna::ParseTraceData(Trace &trace, QString data) {
    // Assumes Trace has enough data for isComplex() to return
    QStringList data_list = data.split(',');
    if (trace.isComplex()) {
        trace.complex_data.resize(trace.points);
        for (unsigned int i=0; i < trace.points; i++) {
            trace.complex_data[i]
                    = std::complex<double>(data_list[2*i].toDouble(), data_list[2*i+1].toDouble());
        }
    }
    else {
        trace.data.resize(trace.points);
        for (int i=0; i < data_list.length(); i++) {
            trace.data[i] = data_list[i].toDouble();
        }
    }
}
void Vna::ParseTraceStimulus(RowVector &stimulus_data, QString readback) {
    QStringList stim_list = readback.split(',');
    unsigned int points = stim_list.length();
    stimulus_data.resize(points);
    for (unsigned int i=0; i < points; i++) {
        stimulus_data[i] = stim_list[i].toDouble();
    }
}
void Vna::GetTraceUnits(Trace &trace) {
    // Assumes Trace contains:
    //  network_parameter, port1, port2, sweep_type and format

    // Sweep units
    if (trace.sweep_type == LINEAR_FREQUENCY_SWEEP
            || trace.sweep_type == LOG_FREQUENCY_SWEEP
            || trace.sweep_type == SEGMENTED_SWEEP)
        trace.stimulus_units = HERTZ_UNITS;
    else if (trace.sweep_type == POWER_SWEEP)
        trace.stimulus_units = DECIBEL_MILLIWATTS_UNITS;
    else
        trace.stimulus_units = SECONDS_UNITS;

    // Data units
    if (trace.network_parameter == S_PARAMETER)
        trace.data_units = DECIBELS_UNITS;
    else if (trace.network_parameter == Y_PARAMETER)
        trace.data_units = SIEMENS_UNITS;
    else if (trace.network_parameter == Z_PARAMETER)
        trace.data_units = OHMS_UNITS;
    else
        trace.data_units = NO_UNITS;
}

// Read Network
unsigned int Vna::NetworkBufferSize(unsigned int points, unsigned int ports) {
    const unsigned int SIZE_PER_POINT = 20;
    return((unsigned int) 2 * ports*ports * points*SIZE_PER_POINT);
}
void Vna::ParseNetworkData(Network &network, QString readback) {
    QStringList data_list = readback.split(',');
    network.data.resize(network.points);
    for (unsigned int freq = 0; freq < network.points; freq++) {
        network.data[freq].resize(network.points);
        for (unsigned int row = 0; row < network.ports; row++) {
            network.data[freq][row].resize(network.ports);
            for (unsigned int column = 0; column < network.ports; column++) {
                int index = (network.ports * row + column) * 2 * network.points + 2 * freq;
                network.data[freq][row][column] =
                        std::complex<double>(data_list[index].toDouble(), data_list[index+1].toDouble());
            }
        }
    }
}
