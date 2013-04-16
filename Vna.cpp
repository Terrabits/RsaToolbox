
// Rsa
#include "Definitions.h"
#include "RsibBus.h"
#include "Vna.h"

// Qt
#include <QByteArray>

// C++
#include <cstdio>

using namespace RsaToolbox;


// Constructor, Destructor
Vna::Vna(ConnectionType connectionType, QString instrument_address, unsigned int timeout_ms, QString log_path, QString log_filename, QString program_name, QString program_version) {
    log = new Log(log_path, log_filename, program_name, program_version);
    if (connectionType == TCPIP_CONNECTION)
        bus = new RsibBus(connectionType, instrument_address, timeout_ms);
    if (bus->isOpen()) {
        // Get instrument info:
        // - Make/Model
        ports = GetPorts();
        // - Serial No.
        // - Firmware
    }
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


/***********************
*** SELECT *************
***********************/

bool Vna::SelectTrace(QString trace_name) {
    unsigned int channel = Trace_GetChannel(trace_name);
    QByteArray trace_byte_array = trace_name.toLocal8Bit();
    char *trace_c_string = trace_byte_array.data();
    const unsigned int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:SEL \'%s\'\n", channel, trace_c_string);
    return(bus->Write(QString(buffer)));
}


/***********************
*** GET ****************
***********************/

// GET:General
unsigned int Vna::GetPorts(void) {
    const unsigned int BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":INST:PORT:COUN?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}
QString Vna::GetSelectedTrace(void) {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    bus->Query(":CALC:PAR:SEL?\n", buffer, BUFFER_SIZE);
    QString selected_trace = QString(buffer);
    selected_trace.remove(0,1); // remove 1st char
    selected_trace.chop(1); // remove last char
    return(selected_trace);
}
QString Vna::GetSelectedTrace(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:SEL?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QString selected_trace = QString(buffer);
    selected_trace.remove(0,1); // remove first char
    selected_trace.chop(1); // remove last char
    return(selected_trace);
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

// GET:Channel
QVector<unsigned int> Vna::GetChannels(void) {
    const unsigned int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    bus->Query(":CONF:CHAN:CAT?\n", buffer, BUFFER_SIZE);
    QVector<unsigned int> channels;
    ParseIndicesFromRead(buffer, channels);
    return(channels);
}
QVector<unsigned int> Vna::Channel_GetDiagrams(unsigned int channel) {}
QStringList Vna::Channel_GetTraces(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d:TRAC:CAT?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QStringList traces;
    ParseNamesFromRead(buffer, traces);
    return(traces);
}
double Vna::GetDelay_s(unsigned int port) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QVector<double> delays();
    sprintf(buffer, ":CORR:EDEL%d:TIME?\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetDelay_s(unsigned int port, unsigned int channel) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QVector<double> delays();
    sprintf(buffer, ":SENS%d:CORR:EDEL%d:TIME?\n", channel, port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
QVector<double> Vna::GetDelays_s(void) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QVector<double> delays;
    for (unsigned int port = 0; port < ports; port++) {
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
    for (unsigned int port = 0; port < ports; port++) {
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
    return(QString(buffer).toInt());
}
double Vna::GetChannelPower_dBm(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}
void Vna::GetPortPower_dBm(unsigned int port, ReferenceLevel &power_reference, double &power) {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:OFFS?\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QString reference_string;
    ParseValueFromRead(QString(buffer), power, reference_string);
    if (reference_string == "ONLY")
        power_reference = ABSOLUTE;
    else
        power_reference = RELATIVE;
}
void Vna::GetPortPower_dBm(unsigned int port, unsigned int channel, ReferenceLevel &power_reference, double &power) {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW%d:OFFS?\n", channel, port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QString reference_string;
    ParseValueFromRead(QString(buffer), power, reference_string);
    if (reference_string == "ONLY")
        power_reference = ABSOLUTE;
    else
        power_reference = RELATIVE;
}
double Vna::GetStartFrequency_Hz(void) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":FREQ:STAR?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}
double Vna::GetStartFrequency_Hz(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "SENS%d:FREQ:​STAR?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}
double Vna::GetStopFrequency_Hz(void) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":FREQ:STOP?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}
double Vna::GetStopFrequency_Hz(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "SENS%d:FREQ:​STOP?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
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
    sprintf(buffer, ":SENS%d:SWE:​POIN\n", channel);
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
    return(traces);
}
QVector<unsigned int> Vna::Diagram_GetChannels(unsigned int diagram) {
    QStringList traces = Diagram_GetTraces(diagram);
    QVector<unsigned int> channels;
    for (unsigned int i = 0; i < traces.length(); i++) {
        channels.append(Trace_GetChannel(traces[i]));
    }
    return(channels);
}
QString Vna::GetTitle(unsigned int diagram) {
    const unsigned int BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:TITL:DATA?\n", diagram);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(buffer);
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
    QString selected_trace = GetSelectedTrace();
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
*** PRIVATE ************
***********************/

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
    for (int i = names.length() - 2; i <= 0; i -= 2) {
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

// Trace format: "\'S12\'" or "\'S1213\'"
void Vna::ParseTraceParameters(QString readback, NetworkParameter &parameter, unsigned int &port1, unsigned int &port2) {
    readback.remove(0, 1);
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
