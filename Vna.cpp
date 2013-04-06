
// Rsa
#include "Definitions.h"
#include "Vna.h"

// Qt
#include <QByteArray>

// C++
#include <cstdio>

using namespace RsaToolbox;


// Constructor, Destructor
Vna::Vna(ConnectionType connectionType, QString instrument_address, QString log_path, QString log_filename, QString program_name, QString program_version) {
    log = Log(log_path, log_filename, program_name, program_version);
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
}

// Actions
void Vna::Preset(void) {
    bus->Write("*RST\n");
}
void Vna::ClearStatus(void) {
    bus->Write("*CLS\n");
}

// Get
unsigned int Vna::GetPorts(void) {
    const unsigned int BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":INST:PORT:COUN?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).ToInt());
}
unsigned int GetSelectedChannel(void);
QVector<unsigned int> Vna::GetChannels(void) {
    const unsigned int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    bus->Query(":CONF:CHAN:CAT?\n", buffer, BUFFER_SIZE);
    QVector<unsigned int> channels();
    ParseIndicesFromRead(readback, channels);
    return(channels);
}
double Vna::GetDelay_s(unsigned int port) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QVector<double> delays();
    sprintf(buffer, ":CORR:EDEL%d:TIME?\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).ToDouble());
}
double Vna::GetDelay_s(unsigned int port, unsigned int channel) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QVector<double> delays();
    sprintf(buffer, ":SENS%d:CORR:EDEL%d:TIME?\n", channel, port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).ToDouble());
}

QVector<double> Vna::GetDelays_s(void) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QVector<double> delays();
    for (int port = 0; port < ports; port++) {
            sprintf(buffer, ":CORR:EDEL%d:TIME?\n", port);
            bus->Query(QString(buffer), buffer, BUFFER_SIZE);
            delays.append(QString(buffer).ToDouble());
    }
    return(delays);
}
QVector<double> Vna::GetDelays_s(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QVector<double> delays();
    for (int port = 0; port < ports; port++) {
            sprintf(buffer, "SENS%d:CORR:EDEL%d:TIME?\n", channel, port);
            bus->Query(QString(buffer), buffer, BUFFER_SIZE);
            delays.append(QString(buffer).ToDouble());
    }
    return(delays);
}
int Vna::Trace_GetChannel(QString trace) {
    QByteArray c_string = trace.toLocal8Bit();
    const unsigned int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:TRAC:CHAN:NAME:ID? \'%s\'\n", c_string.constData());
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}

QVector<unsigned int> Vna::GetDiagrams(void) {
    const unsigned int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    bus->Query(":DISP:CAT?\n", buffer, BUFFER_SIZE);
    QVector<unsigned int> diagrams;
    ParseIndicesFromRead(buffer, diagrams);
    return(diagrams);
}
QString Vna::GetTitle(unsigned int diagram) {
    const unsigned int BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:TITL:DATA?\n", diagram);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(buffer);
}
QVector<unsigned int> Channel_GetDiagrams(unsigned int channel);
QStringList Vna::Channel_GetTraces(unsigned int channel) {
    const unsigned int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d:TRAC:CAT?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QStringList traces;
    ParseNamesFromRead(buffer, traces);
    return(diagrams);
}

QVector<unsigned int> Trace_GetDiagrams(QString trace);
QStringList Vna::GetTraces(void) {
    const unsigned int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    bus->Query(":CONF:TRAC:CAT?\n", buffer, BUFFER_SIZE);
    QStringList traces;
    ParseNamesFromRead(buffer, traces);
    return(traces);
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
QVector<double> GetSourceAttenuation_dB(void);
double GetSourceAttenuation_dB(unsigned int port);
QString Vna::GetColorScheme(void) {
    const unsigned int BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:DISP:COL?\n", buffer, BUFFER_SIZE);
    return(QString(buffer));
}

unsigned int Vna::GetFontSize_percent(void) {
    const unsigned int BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":DISP:RFS?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}

double GetSourcePowerLevel_dBm(void);
double GetStartFrequency_Hz(void);
double GetStartFrequency_Hz(unsigned int channel);
double GetStopFrequency_Hz(void);
double GetStopFrequency_Hz(unsigned int channel);
unsigned int GetPoints(void) {
    //":SWE:POIN?\n"
}

unsigned int Vna::GetPoints(unsigned int channel) {
    unsigned int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(":SENS%d:SWE:​POIN?\n", channel);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}

// Help
void Vna::ParseIndicesFromRead(QString readback, QVector<unsigned int> &indices) {
    // Assumes readback format: '1,Name_1,2,Name_2,...'
    indices.clear();
    readback.remove(0, 1);
    readback.chop(1);
    QStringList words = readback.split(',');
    for (int i = 0; i < words.length(); i += 2) {
        indices.append(words[i].ToInt());
    }
}
void Vna::ParseNamesFromRead(QString readback, QStringList &names) {
    // Assumes readback format: '1,Name_1,2,Name_2...'
    names.clear();
    readback.remove(0, 1);
    readback.chop(1);
    names = readback.split(',');
    if (names.length() % 2 == 1) return;
    for (int i = names.length() - 2; i <= 0; i -= 2) {
        names.removeAt(i);
    }
}
