
// Rsa
#include "Definitions.h"
#include "RsibBus.h"
#include "Vna.h"

// Qt
#include <QByteArray>
#include <QtAlgorithms>

// C++
#include <cstdio>

using namespace RsaToolbox;


// Constructor, Destructor
Vna::Vna(ConnectionType connectionType, QString instrument_address, unsigned int timeout_ms, QString log_path, QString log_filename, QString program_name, QString program_version) {
    log = new Log(log_path, log_filename, program_name, program_version);
    if (connectionType == TCPIP_CONNECTION)
        bus = new RsibBus(connectionType, instrument_address, timeout_ms);
    if (bus->isOpen()) {
        QString id = GetIdentificationString();
        if (!isRohdeSchwarz(id))
            throw("RsaToolbox Error: Not a Rohde & Schwarz Analyzer");
        ports = GetPorts();
        minimum_frequency_Hz = GetMinimumFrequency_Hz();
        maximum_frequency_Hz = GetMaximumFrequency_Hz();
        GetInstrumentInfo(id);
        options = GetOptions();
    }
    else {
        model = UNKNOWN;
        throw("RsaToolbox Error: No instrument found");
    }

    // Signals and slots
    QObject::connect(bus, &GenericBus::Print, log, &Log::Print);
}
Vna::~Vna() {
    delete bus;
    delete log;
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
    if (model != UNKNOWN) {
        stream << "Make:             Rohde & Schwarz" << endl;
        stream << "Model:            " << ToString(model) << endl;
        stream << "Serial No:        " << serial_no << endl;
        stream << "Firmware Version: " << firmware_version << endl;
        stream << "Min Frequency:    " << FormatValue(minimum_frequency_Hz, 1, HERTZ) << endl;
        stream << "Max Frequency:    " << FormatValue(maximum_frequency_Hz, 1, HERTZ) << endl;
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
    for (int i = 1; i <= ports; i++)
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
    if (model != ZVA)
        return(0);
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:ATT?\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetSourceAttenuation_dB(unsigned int port, unsigned int channel) {
    if (model != ZVA)
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
    for (int i = 1; i <= ports; i++)
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
    QByteArray c_string = id_string.toLocal8Bit();
    const unsigned int BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:IDEN \'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetOptionsString(QString options_string)  {
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
    for (int i = 1; i <= ports; i++)
        SetSourceAttenuation_dB(i, attenuation);
}
void Vna::SetSourceAttenuations_dB(QVector<double> attenuations) {
    if (attenuations.size() != ports)
        return;
    for (int i = 1; i <= ports; i++)
        SetSourceAttenuation_dB(i, attenuations[i-1]);
}
void Vna::SetSourceAttenuations_dB(unsigned int channel, double attenuation) {
    for (int i = 1; i <= ports; i++)
        SetSourceAttenuation_dB(i, channel, attenuation);
}
void Vna::SetSourceAttenuations_dB(unsigned int channel, QVector<double> attenuations) {
    if (attenuations.size() != ports)
        return;
    for (int i = 1; i <= ports; i++)
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
    for (int i = 1; i <= ports; i++)
        SetReceiverAttenuation_dB(i, attenuation);
}
void Vna::SetReceiverAttenuations_dB(QVector<double> attenuations) {
    if (attenuations.size() != ports)
        return;
    for (int i = 1; i <= ports; i++)
        SetReceiverAttenuation_dB(i, attenuations[i-1]);
}
void Vna::SetReceiverAttenuations_dB(unsigned int channel, double attenuation) {
    for (int i = 1; i <= ports; i++)
        SetReceiverAttenuation_dB(i, channel, attenuation);
}
void Vna::SetReceiverAttenuations_dB(unsigned int channel, QVector<double> attenuations) {
    if (attenuations.size() != ports)
        return;
    for (int i = 1; i <= ports; i++)
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
    for (int i = 1; i <= ports; i++)
        SetPortPowerLimit(i, power_limits[i-1]);
}
void Vna::SetPortPowerLimits(double power_limit) {
    for (int i = 1; i <= ports; i++)
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
    if (!filename.contains(ToStateFileExtension(model)))
        filename = filename + ToStateFileExtension(model);
    filename = AppendPath(path, filename);
    QByteArray c_string = filename.toLocal8Bit();
    const unsigned int BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:PRES:USER:NAME \'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}

// SET:Channel
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
    QByteArray c_string = (ToString(prefix) + ToString(SECONDS)).toLocal8Bit();
    sprintf(buffer, ":CORR:EDEL%d:TIME %f%s\n", port, delay, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetDelay(unsigned int port, unsigned int channel, double delay, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = (ToString(prefix) + ToString(SECONDS)).toLocal8Bit();
    sprintf(buffer, ":SENS%d:CORR:EDEL%d:TIME %f%s\n", channel, port, delay, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetDelays(QVector<double> delays, SiPrefix prefix)  {
    if (delays.size() != ports)
        return;
    for (int i = 1; i <= ports; i++)
        SetDelay(i, delays[i-1], prefix);
}
void Vna::SetDelays(unsigned int channel, QVector<double> delays, SiPrefix prefix)  {
    if (delays.size() != ports)
        return;
    for (int i = 1; i <= ports; i++)
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
    QString units_string = ToString(prefix) + ToString(HERTZ);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":FREQ:STAR %f%s\n", start_frequency, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetStartFrequency(unsigned int channel, double start_frequency, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":SENS%d:FREQ:STAR %f%s\n", channel, start_frequency, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetStopFrequency(double stop_frequency, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":FREQ:STOP %f%s\n", stop_frequency, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetStopFrequency(unsigned int channel, double stop_frequency, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":SENS%d:FREQ:STOP %f%s\n", channel, stop_frequency, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetIfBandwidth(double if_bandwidth, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":BAND %f%s\n", if_bandwidth, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetIfBandwidth(unsigned int channel, double if_bandwidth, SiPrefix prefix)  {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ);
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
    for (int i = 1; i <= ports; i++)
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
    if (isDisabled)
        bus->Write(":SYST:IDEN:FACT\n");
}
void Vna::DisableCustomOptionsString(bool isDisabled) {
    if (isDisabled)
        bus->Write(":SYST:OPT:FACT\n");
}
void Vna::DisableEmulation() {
    bus->Write(":SYST:LANG \'SCPI\'\n");
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

void Vna::CreateChannel(unsigned int channel) {}
void Vna::CreateDiagram(unsigned int diagram) {}
void Vna::CreateTrace(QString trace_name) {}


/***********************
*** DELETE *************
***********************/

void Vna::DeleteChannel(unsigned int channel) {}
void Vna::DeleteDiagram(unsigned int diagram) {}
void Vna::DeleteTrace(QString trace_name) {}
void Vna::DeleteUserPreset(void) {
    SetUserPreset("");
}


/***********************
*** MEASURE ************
***********************/

void Vna::MeasureTrace(Trace &trace) {}
void Vna::MeasureTrace(Trace &trace, QString name) {}
void Vna::MeasureNetwork(Network &network, QVector<unsigned int> ports) {}
void Vna::MeasureNetwork(Network &network, QVector<unsigned int> ports, unsigned int channel) {}


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
        return(ZVA);
    if (id_part_2.contains("ZVB", Qt::CaseInsensitive))
        return(ZVB);
    if (id_part_2.contains("ZVH", Qt::CaseInsensitive))
        return(ZVH);
    if (id_part_2.contains("ZVL", Qt::CaseInsensitive))
        return(ZVL);
    if (id_part_2.contains("ZVT", Qt::CaseInsensitive))
        return(ZVT);
    if (id_part_2.contains("ZNB", Qt::CaseInsensitive))
        return(ZNB);
    if (id_part_2.contains("ZNC", Qt::CaseInsensitive))
        return(ZNC);
    else return(UNKNOWN);
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
