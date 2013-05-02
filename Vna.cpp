
// Rsa
#include "General.h"
#include "RsibBus.h"
#include "VisaBus.h"
#include "TraceData.h"
#include "Vna.h"

// Qt
#include <QByteArray>
#include <QtAlgorithms>
#include <QVariant>
#include <QDateTime>
#include <QScopedArrayPointer>

// C++
#include <cstdio>
#include <complex>
#include <vector>

using namespace RsaToolbox;


/***********************
*** Vna ****************
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
Vna::Vna(ConnectionType connection_type, QString instrument_address, uint timeout_ms, QString log_path, QString log_filename, QString program_name, QString program_version) {
    Reset(connection_type, instrument_address, timeout_ms, log_path, log_filename, program_name, program_version);
    log->PrintProgramHeader();
    if (this->bus->connection_type != NO_CONNECTION) {
        PrintInstrumentInfo();
    }
    else {
        QString message;
        QTextStream stream(&message);
        stream << "Instrument not found" << endl;
        stream << "Connection:       " << ToString(connection_type) << endl;
        stream << "Address:          " << instrument_address << endl << endl << endl;
        stream.flush();
        log->Print(message);
    }
}

// VNA:General
bool Vna::isConnected() {
    return(bus->isOpen());
}
VnaModel Vna::GetModel() {
    return(model);
}
QString Vna::GetSerialNumber() {
    return(serial_no);
}
QString Vna::GetFirmwareVersion() {
    return(firmware_version);
}

void Vna::Print(QString formatted_text) {
    log->Print(formatted_text);
}
void Vna::Read(char *buffer, unsigned int buffer_size) {
    bus->Read(buffer, buffer_size);
}
void Vna::Write(QString scpi_command) {
    bus->Write(scpi_command);
}
void Vna::Query(QString scpi_command, char *buffer, unsigned int buffer_size) {
    bus->Query(scpi_command, buffer, buffer_size);
}

// VNA:Actions
void Vna::Preset() {
    bus->Write("*RST\n");
}
void Vna::ClearStatus() {
    bus->Write("*CLS\n");
}
void Vna::InitiateSweeps() {
    bus->Write(":INIT:ALL\n");
}
void Vna::FinishPreviousCommandsFirst() {
    bus->Write("*WAI\n");
}
void Vna::PauseUntilCommandQueueIsFinished() {
    const uint BUFFER_SIZE = 5;
    char buffer[BUFFER_SIZE];
    bus->Query("*OPC?\n", buffer, BUFFER_SIZE);
}

// VNA:Status
bool Vna::isUserPresetEnabled() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:PRES:USER?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isUserPresetDisabled() {
    return(!isUserPresetEnabled());
}
bool Vna::isUserPresetMappedToRst() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query("SYST:PRES:REM?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isPortPowerLimitEnabled() {
    for (uint i = 1; i <= ports; i++)
        if (isPortPowerLimitEnabled(i))
            return(true);
    return(false);
}
bool Vna::isPortPowerLimitEnabled(uint port) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:LLIM?\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isPortPowerLimitDisabled() {
    return(!isPortPowerLimitEnabled());
}
bool Vna::isPortPowerLimitDisabled(uint port) {
    return(!isPortPowerLimitEnabled(port));
}
bool Vna::isRfOutputPowerEnabled() {
    const uint BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":OUTP?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isRfOutputPowerDisabled() {
    return(!isRfOutputPowerEnabled());
}
bool Vna::isDynamicIfBandwidthEnabled() {
    const uint BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":BAND:DRED?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isDynamicIfBandwidthDisabled() {
    return(!isDynamicIfBandwidthEnabled());
}
bool Vna::isLowPowerAutoCalEnabled() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:COMM:RDEV:AKAL:PRED?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isLowPowerAutoCalDisabled() {
    return(!isLowPowerAutoCalEnabled());
}

// VNA:Get
QString Vna::GetIdentificationString() {
    const uint BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    bus->Query("*IDN?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).trimmed());
}
QStringList Vna::GetOptions() {
    const uint BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    bus->Query("*OPT?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).trimmed().split(','));
}
uint Vna::GetPorts() {
    const uint BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":INST:PORT:COUN?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}
double Vna::GetMinimumFrequency_Hz() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:FREQ? MIN\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetMaximumFrequency_Hz() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:FREQ? MAX\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetPortPowerLimit(uint port) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:LLIM:VAL?\n", port);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
QVector<double> Vna::GetPortPowerLimits() {
    QVector<double> power_limits;
    for (uint i = 1; i <= ports; i++)
        power_limits.append(GetPortPowerLimit(i));
    return(power_limits);
}
ColorScheme Vna::GetColorScheme() {
    const uint BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:DISP:COL?\n", buffer, BUFFER_SIZE);
    return(Scpi_To_ColorScheme(buffer));
}
uint Vna::GetFontSize_percent() {
    const uint BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->Query(":DISP:RFS?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}
QString Vna::GetUserPreset() {
    const uint BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    bus->Query(":SYST:PRES:USER:NAME?\n", buffer, BUFFER_SIZE);
    QString user_preset = QString(buffer);
    user_preset.remove(0,1); // remove 1st char: "\'"
    user_preset.chop(1); // remove last char: "\'"
    return(user_preset);
}

QVector<uint> Vna::GetChannels() {
    const uint BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    bus->Query(":CONF:CHAN:CAT?\n", buffer, BUFFER_SIZE);
    QVector<uint> channels;
    ParseIndicesFromRead(buffer, channels);
    return(channels);
}
QStringList Vna::GetTraces() {
    const uint BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    bus->Query(":CONF:TRAC:CAT?\n", buffer, BUFFER_SIZE);
    QStringList traces;
    ParseNamesFromRead(buffer, traces);
    return(traces);
}
QVector<uint> Vna::GetDiagrams() {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    bus->Query(":DISP:CAT?\n", buffer, BUFFER_SIZE);
    QVector<uint> diagrams;
    ParseIndicesFromRead(buffer, diagrams);
    return(diagrams);
}

// VNA:Set
void Vna::SetIdentificationString(QString id_string)  {
    if (!(model == ZNB_MODEL || model == ZNC_MODEL))
        return;
    QByteArray c_string = id_string.toLocal8Bit();
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:IDEN \'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetOptionsString(QString options_string)  {
    if (!(model == ZNB_MODEL || model == ZNC_MODEL))
        return;
    QByteArray c_string = options_string.toLocal8Bit();
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:OPT \'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetPortPowerLimit(uint port, double power_limit) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:LLIM:VAL %f\n", port, power_limit);
    bus->Write(QString(buffer));
}
void Vna::SetPortPowerLimits(QVector<double> power_limits) {
    if (power_limits.size() != ports)
        return;
    for (uint i = 1; i <= ports; i++)
        SetPortPowerLimit(i, power_limits[i-1]);
}
void Vna::SetPortPowerLimits(double power_limit) {
    for (uint i = 1; i <= ports; i++)
        SetPortPowerLimit(i, power_limit);
}
void Vna::SetColorScheme(ColorScheme scheme)  {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:DISP:COL %s\n", ToScpi(scheme));
    bus->Write(QString(buffer));
}
void Vna::SetFontSize_percent(uint size_percent)  {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:RFS %d\n", size_percent);
    bus->Write(QString(buffer));
}
void Vna::SetUserPreset(QString filename)  {
    if (!filename.contains(ToStateFileExtension(model)))
        filename = filename + ToStateFileExtension(model);
    QByteArray c_string = filename.toLocal8Bit();
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:PRES:USER:NAME \'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::SetUserPreset(QDir path, QString filename)  {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    if (!filename.contains(ToStateFileExtension(model)))
        filename = filename + ToStateFileExtension(model);
    filename = AppendPath(path, filename);
    filename = QDir::toNativeSeparators(filename);
    QByteArray c_string = filename.toLocal8Bit();
    sprintf(buffer, ":SYST:PRES:USER:NAME \'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}

// VNA:Enable
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
void Vna::EnablePortPowerLimit(uint port, bool isEnabled) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":SOUR:POW%d:LLIM 1\n", port);
    else
        sprintf(buffer, ":SOUR:POW%d:LLIM 0\n", port);
    bus->Write(QString(buffer));
}
void Vna::EnablePortPowerLimits(bool isEnabled) {
    for (uint i = 1; i <= ports; i++)
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

// VNA:Disable
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
void Vna::DisableUserPreset(bool isDisabled) {
    EnableUserPreset(!isDisabled);
}
void Vna::DisableUserPresetMapToRst(bool isDisabled) {
    EnableUserPresetMapToRst(!isDisabled);
}
void Vna::DisablePortPowerLimit(uint port, bool isDisabled) {
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

// VNA:Create
void Vna::CreateChannel(uint channel) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d:MEAS 1\n", channel);
    bus->Write(QString(buffer));
}
void Vna::CreateTrace(QString trace_name, uint channel, NetworkParameter parameter, uint port1, uint port2) {
    const uint BUFFER_SIZE = 150;
    char buffer[BUFFER_SIZE];
    QByteArray c_name = trace_name.toLocal8Bit();
    QByteArray c_parameters = _Trace::Parameters_to_Scpi(parameter, port1, port2).toLocal8Bit();
    sprintf(buffer, ":CALC%d:PAR:SDEF \'%s\', \'%s\'\n", channel, c_name.constData(), c_parameters.constData());
    bus->Write(QString(buffer));
}
void Vna::CreateDiagram(uint diagram) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:STAT 1\n", diagram);
    bus->Write(QString(buffer));
}

// VNA:Delete
void Vna::DeleteUserPreset() {
    bus->Write(QString(":SYST:PRES:USER:NAME \'\'\n"));
}
void Vna::DeleteCalGroup(QString cal_group) {
    const unsigned int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = cal_group.toLocal8Bit();
    sprintf(buffer, ":MMEM:DEL:CORR \'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}

void Vna::DeleteChannel(uint channel) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d 0\n", channel);
    bus->Write(QString(buffer));
}
void Vna::DeleteTrace(QString trace_name) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    uint channel = _Trace(this, trace_name).GetChannel();
    QByteArray c_string = trace_name.toLocal8Bit();
    sprintf(buffer, ":CALC%d:PAR:DEL \'%s\'\n", channel, c_string.constData());
    bus->Write(QString(buffer));
}
void Vna::DeleteDiagram(uint diagram) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:STAT 0\n", diagram);
    bus->Write(QString(buffer));
}

// VNA:Save
void Vna::SaveState(QString filename) {
    const uint BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    // Fix save directory issue with firmware
    filename = "./RecallSets/" + filename;
    if (!filename.contains(ToStateFileExtension(model)))
        filename = filename + ToStateFileExtension(model);
    QByteArray c_string = filename.toLocal8Bit();
    sprintf(buffer, ":MMEM:STOR:STAT 1,\'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}

// VNA:Load
void Vna::LoadState(QString state_file) {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    if (!state_file.contains(ToStateFileExtension(model)))
        state_file = state_file + ToStateFileExtension(model);
    QByteArray c_string = state_file.toLocal8Bit();
    sprintf(buffer, ":MMEM:LOAD:STAT 1,\'%s\'\n", c_string.constData());
    bus->Write(QString(buffer));
}

// VNA:Private:General
void Vna::Reset() {
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
void Vna::Reset(ConnectionType connection_type, QString instrument_address, uint timeout_ms, QString log_path, QString log_filename, QString program_name, QString program_version) {
    log.reset(new Log(log_path, log_filename, program_name, program_version));
    if (connection_type == TCPIP_CONNECTION) {
        bus.reset(new RsibBus(connection_type, instrument_address, timeout_ms));
        // bus.reset(new VisaBus(connection_type, instrument_address, timeout_ms));
    }
    else if (connection_type == GPIB_CONNECTION) {
        bus.reset(new VisaBus(connection_type, instrument_address, timeout_ms));
    }

    if (bus->isOpen()) {
        id_string = GetIdentificationString();
        if (isRohdeSchwarz(id_string)) {
            ports = GetPorts();
            minimum_frequency_Hz = GetMinimumFrequency_Hz();
            maximum_frequency_Hz = GetMaximumFrequency_Hz();
            GetInstrumentInfo(id_string);
            options = GetOptions();
        }
        else
            model = UNKNOWN_MODEL;
    }
    else { // bus is not open
        QScopedPointer<Log> keep_log;
        keep_log.reset(log.take());
        Reset();
        log.reset(keep_log.take());
    }

    // Signals and slots
    QObject::connect(bus.data(), &GenericBus::Print, log.data(), &Log::Print);
}

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
const char* Vna::ToScpi(ColorScheme scheme) {
    switch(scheme) {
    case DARK_BACKGROUND:
        return("DBAC");
        break;
    case LIGHT_BACKGROUND:
        return("LBAC");
        break;
    case BLACK_WHITE_OUTLINE_BACKGROUND:
        return("BWLS");
        break;
    case BLACK_WHITE_SOLID_BACKGROUND:
        return("BWS");
        break;
    }
    // Default
    return("DBAC");
}
ColorScheme Vna::Scpi_To_ColorScheme(QString scpi) {
    if(scpi == "DBAC")
        return(DARK_BACKGROUND);
    if(scpi == "LBAC")
        return(LIGHT_BACKGROUND);
    if(scpi == "BWLS")
        return(BLACK_WHITE_OUTLINE_BACKGROUND);
    if(scpi == "BWS")
        return(BLACK_WHITE_SOLID_BACKGROUND);
    // Default
    return(DARK_BACKGROUND);
}
void Vna::PrintInstrumentInfo() {
    QString info;
    QTextStream stream(&info);
    stream << "INSTRUMENT INFO" << endl;
    if (model != UNKNOWN_MODEL) {
        stream << "Connection:       " << ToString(bus->connection_type) << endl;
        stream << "Address:          " << bus->address << endl;
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
        stream << endl << endl << endl;
    }
    else if (bus->connection_type != NO_CONNECTION) {
        stream << "Make: Unknown" << endl;
        stream << "*IDN?\n  " << id_string << endl << endl << endl;
    }

    stream.flush();
    log->Print(info);
}

// VNA:Private:Readback
// format: "\'Int1,Name_1,Int2,Name_2,...\'"
void Vna::ParseIndicesFromRead(QString readback, QVector<uint> &indices) {
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

// VNA:Private:Readback
// format: "Value,Qualifier_String"
void Vna::ParseValueFromRead(QString readback, uint &value, QString &qualifier) {
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
QString Vna::ValueQualifier_to_Scpi(uint value, QString qualifier) {
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



/***********************
*** CHANNEL ************
***********************/

Vna::_Channel& Vna::Channel(uint channel) {
    _channel = _Channel(this, channel);
    return(_channel);
}

Vna::_Channel::_Channel(Vna *vna, uint channel) {
    this->vna = vna;
    this->channel = channel;
}

// CHANNEL:Action
void Vna::_Channel::InitiateSweep() {
    const uint BUFFER_SIZE = 15;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":INIT%d\n", channel);
    vna->bus->Write(QString(buffer));
}

// CHANNEL:Status
bool Vna::_Channel::isEnabled() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d:STAT?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Channel::isDisabled() {
    return(!isEnabled());
}
bool Vna::_Channel::isCalibrationEnabled() {
    const uint BUFFER_SIZE = 5;
    char buffer[BUFFER_SIZE];
    vna->bus->Query(":CORR?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Channel::isCalibrationDisabled() {
    return(!isCalibrationEnabled());
}
bool Vna::_Channel::isContinuousSweepEnabled() {
    const uint BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":INIT%d:CONT?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Channel::isSingleSweepEnabled() {
    return(!isContinuousSweepEnabled());
}

// CHANNEL:Get
double Vna::_Channel::GetSourceAttenuation_dB(uint port) {
    if (vna->model != ZVA_MODEL)
        return(0);
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW%d:ATT?\n", channel, port);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Channel::GetReceiverAttenuation_dB(uint port) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:POW:ATT? %d\n", channel, port);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
QString Vna::_Channel::GetCalGroup() {
    const uint BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":MMEM:LOAD:CORR? %d\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    // Remove quotes
    QString cal_file = QString(buffer).remove(0,1);
    cal_file.chop(1);
    return(cal_file);
}
CorrectionState Vna::_Channel::GetCorrectionState() {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:CORR:SST?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    // Remove quotes
    QString state_scpi = QString(buffer).remove(0,1);
    state_scpi.chop(1);
    return(Scpi_To_CorrectionState(state_scpi));
}
SweepType Vna::_Channel::GetSweepType() {
    const uint BUFFER_SIZE = 25;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:TYPE?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(Scpi_To_SweepType(QString(buffer)));
}
void Vna::_Channel::GetStimulusValues(RowVector &stimulus_data) {
    uint points = GetPoints();
    uint buffer_size = StimulusBufferSize(points);
    QScopedPointer<char> buffer(new char[buffer_size]);
    sprintf(buffer.data(), ":CALC%d:DATA:STIM?\n", channel);
    vna->bus->Query(QString(buffer.data()), buffer.data(), buffer_size);
    ParseStimulus(stimulus_data, buffer.data());
}
QVector<uint> Vna::_Channel::GetDiagrams() {
    QStringList traces = GetTraces();
    QVector<uint> diagrams;
    for (int i = 0; i < traces.length(); i++) {
        uint currentDiagram = vna->Trace(traces[i]).GetDiagram();
        if (!diagrams.contains(currentDiagram))
            diagrams.append(currentDiagram);
    }
    qSort(diagrams);
    return(diagrams);
}
QStringList Vna::_Channel::GetTraces() {
    const uint BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d:TRAC:CAT?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QStringList traces;
    Vna::ParseNamesFromRead(buffer, traces);
    return(traces);
}
QString Vna::_Channel::GetSelectedTrace() {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:SEL?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QString selected_trace = QString(buffer);
    selected_trace.remove(0,1); // remove first char
    selected_trace.chop(1); // remove last char
    return(selected_trace);
}
double Vna::_Channel::GetDelay_s(uint port) {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:CORR:EDEL%d:TIME?\n", channel, port);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
QVector<double> Vna::_Channel::GetDelays_s() {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QVector<double> delays;
    for (uint port = 1; port <= vna->ports; port++) {
        sprintf(buffer, "SENS%d:CORR:EDEL%d:TIME?\n", channel, port);
        vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
        delays.append(QString(buffer).toDouble());
    }
    return(delays);
}
double Vna::_Channel::GetChannelPower_dBm() {
    const uint BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
void Vna::_Channel::GetPortPower_dBm(uint port, ReferenceLevel &power_reference, double &power) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW%d:OFFS?\n", channel, port);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QString reference_string;
    Vna::ParseValueFromRead(QString(buffer), power, reference_string);
    power_reference = Scpi_To_ReferenceLevel(reference_string);
}
double Vna::_Channel::GetStartFrequency_Hz() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:FREQ:STAR?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Channel::GetStopFrequency_Hz() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "SENS%d:FREQ:STOP?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Channel::GetIfBandwidth() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:BAND?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
uint Vna::_Channel::GetPoints() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:POIN?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}

// CHANNEL:Set
void Vna::_Channel::SetCalGroup(QString cal_file) {
    const uint BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    if (!cal_file.contains(".cal", Qt::CaseInsensitive))
        cal_file = cal_file + QString(".cal");
    QByteArray c_string = cal_file.toLocal8Bit();
    sprintf(buffer, ":MMEM:LOAD:CORR %d,\'%s\'\n", channel, c_string.constData());
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::SetSourceAttenuation_dB(uint port, double attenuation_dB) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW%d:ATT %f\n", channel, port, attenuation_dB);
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::SetSourceAttenuations_dB(double attenuation_dB) {
    for (uint i = 1; i <= vna->ports; i++)
        SetSourceAttenuation_dB(i, attenuation_dB);
}
void Vna::_Channel::SetSourceAttenuations_dB(QVector<double> attenuations_dB) {
    if (attenuations_dB.size() != vna->ports)
        return;
    for (uint i = 1; i <= vna->ports; i++)
        SetSourceAttenuation_dB(i, attenuations_dB[i-1]);
}
void Vna::_Channel::SetReceiverAttenuation_dB(uint port, double attenuation_dB) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:POW:ATT %d, %f\n", channel, port, attenuation_dB);
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::SetReceiverAttenuations_dB(double attenuation_dB) {
    for (uint i = 1; i <= vna->ports; i++)
        SetReceiverAttenuation_dB(i, attenuation_dB);
}
void Vna::_Channel::SetReceiverAttenuations_dB(QVector<double> attenuations_dB) {
    if (attenuations_dB.size() != vna->ports)
        return;
    for (uint i = 1; i <= vna->ports; i++)
        SetReceiverAttenuation_dB(i, attenuations_dB[i-1]);
}
void Vna::_Channel::SetSweepType(SweepType sweep_type) {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:TYPE %s\n", channel, ToScpi(sweep_type));
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::SetDelay(uint port, double delay_s, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = (ToString(prefix) + ToString(SECONDS_UNITS)).toLocal8Bit();
    sprintf(buffer, ":SENS%d:CORR:EDEL%d:TIME %f%s\n", channel, port, delay_s, c_string.constData());
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::SetDelays(double delay_s, SiPrefix prefix) {
    for (uint i = 1; i <= vna->ports; i++)
        SetDelay(i, delay_s, prefix);
}
void Vna::_Channel::SetDelays(QVector<double> delays_s, SiPrefix prefix) {
    if (delays_s.size() != vna->ports)
        return;
    for (uint i = 1; i <= vna->ports; i++)
        SetDelay(i, delays_s[i-1], prefix);
}
void Vna::_Channel::SetChannelPower_dBm(double power_dBm) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW %f\n", channel, power_dBm);
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::SetPortPower(uint port, double power_dBm, ReferenceLevel power_reference) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString power_scpi = ValueQualifier_to_Scpi(power_dBm, ToScpi(power_reference));
    QByteArray c_string = power_scpi.toLocal8Bit();
    sprintf(buffer, ":SOUR%d:POW%d:OFFS %s\n", channel, port, c_string.constData());
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::SetPortPowers(double power_dBm, ReferenceLevel power_reference) {
    for (uint i = 1; i <= vna->ports; i++)
        SetPortPower(i, power_dBm, power_reference);
}
void Vna::_Channel::SetPortPowers(QVector<double> powers_dBm, ReferenceLevel power_reference) {
    if (powers_dBm.size() != vna->ports)
        return;
    for (uint i = 1; i <= vna->ports; i++)
        SetPortPower(i, powers_dBm[i], power_reference);
}
void Vna::_Channel::SetStartFrequency(double start_frequency_Hz, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":SENS%d:FREQ:STAR %f%s\n", channel, start_frequency_Hz, c_string.constData());
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::SetStopFrequency(double stop_frequency_Hz, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, ":SENS%d:FREQ:STOP %f%s\n", channel, stop_frequency_Hz, c_string.constData());
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::SetIfBandwidth(double if_bandwidth_Hz, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toLocal8Bit();
    sprintf(buffer, "SENS%d:BAND %f%s\n", channel, if_bandwidth_Hz, c_string.constData());
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::SetPoints(uint points) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:POIN %d\n", channel, points);
    vna->bus->Write(QString(buffer));
}

// CHANNEL:Enable
void Vna::_Channel::EnableCorrection(bool isEnabled) {
    const uint BUFFER_SIZE = 25;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":SENS%d:CORR 1\n", channel);
    else
        sprintf(buffer, ":SENS%d:CORR 0\n", channel);
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::EnableContinuousSweep(bool isEnabled) {
    const uint BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    if (isEnabled) {
        sprintf(buffer, ":INIT%d:CONT 1\n", channel);
        vna->bus->Write(QString(buffer));
    }
    else {
        sprintf(buffer, ":INIT%d:CONT 0\n", channel);
        vna->bus->Write(QString(buffer));
    }
}

// CHANNEL:Disable
void Vna::_Channel::DisableCorrection(bool isDisabled) {
    EnableCorrection(!isDisabled);
}
void Vna::_Channel::DisableCalGroup() {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":MMEM:LOAD:CORR:RES %d\n", channel);
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::DisableContinuousSweep(bool isDisabled) {
    EnableContinuousSweep(!isDisabled);
}
void Vna::_Channel::DisableDelay(uint port) {
    SetDelay(port, 0);
}
void Vna::_Channel::DisableDelays() {
    QVector<double> zero_delays(vna->ports, 0);
    SetDelays(zero_delays);
}

// CHANNEL:Create
void Vna::_Channel::CreateSParameterGroup(QVector<uint> ports) {
    uint number_of_ports = ports.size();
    if (number_of_ports <= 0)
        return;
    const uint BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    QString ports_list = QVariant(ports[0]).toString();
    for (uint i = 1; i < number_of_ports; i++) {
        ports_list = ports_list + "," + QVariant(ports[i]).toString();
    }
    QByteArray c_ports_list = ports_list.toLocal8Bit();
    sprintf(buffer, ":CALC%d:PAR:DEF:SGR %s\n", channel, c_ports_list.constData());
    vna->bus->Write(QString(buffer));
}

// CHANNEL:Delete
void Vna::_Channel::DeleteCorrectionData() {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:CORR:COLL:DEL ALL\n", channel);
    vna->bus->Write(QString(buffer));
}
void Vna::_Channel::DeleteSParameterGroup() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:DEL:SGR\n", channel);
    vna->bus->Write(QString(buffer));
}

// CHANNEL:Measure
void Vna::_Channel::MeasureNetwork(NetworkData &network, QVector<uint> ports) {
    // (Temporary?) Sanity check
    SweepType sweep_type = GetSweepType();
    if (sweep_type == POWER_SWEEP || sweep_type == CW_MODE_SWEEP || sweep_type == TIME_SWEEP)
        return;

    // info, buffer
    CreateSParameterGroup(ports);
    network.date_time = QDateTime::currentDateTime();
    network.ports = ports.size();
    network.points = GetPoints();
    uint buffer_size = NetworkBufferSize(network.points, network.ports);
    QScopedArrayPointer<char> buffer(new char[buffer_size]);
    sprintf(buffer.data(), ":CALC%d:DATA:SGR? MDAT\n", channel);

    // Measure
    if (isContinuousSweepEnabled()) {
        DisableContinuousSweep();
        InitiateSweep();
        vna->FinishPreviousCommandsFirst();
        vna->bus->Query(QString(buffer.data()), buffer.data(), buffer_size);
        EnableContinuousSweep();
    }
    else {
        InitiateSweep();
        vna->FinishPreviousCommandsFirst();
        vna->bus->Query(QString(buffer.data()), buffer.data(), buffer_size);
    }

    // Parse
    ParseNetworkData(network, buffer.data());
    network.frequency_prefix = NO_PREFIX;
    GetStimulusValues(network.frequency);

    // Clean up
    DeleteSParameterGroup();
}

// CHANNEL:Save
void Vna::_Channel::SaveCalGroup(QString cal_file) {
    const uint BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    if (!cal_file.contains(".cal", Qt::CaseInsensitive))
        cal_file = cal_file + QString(".cal");
    QByteArray c_string = cal_file.toLocal8Bit();
    sprintf(buffer, ":MMEM:STOR:CORR %d,\'%s\'\n", channel, c_string.constData());
    vna->bus->Write(QString(buffer));
}

// CHANNEL:Private:General
const char* Vna::_Channel::ToScpi(ReferenceLevel reference_level) {
    if (reference_level == RELATIVE_REFERENCE_LEVEL)
        return("CPAD");
    if (reference_level == ABSOLUTE_REFERENCE_LEVEL)
        return("ONLY");
    //Default
    return("ONLY");
}
const char* Vna::_Channel::ToScpi(SweepType sweep_type) {
    switch(sweep_type) {
    case LINEAR_FREQUENCY_SWEEP:
        return("LIN");
    case LOG_FREQUENCY_SWEEP:
        return("LOG");
    case SEGMENTED_SWEEP:
        return("SEGM");
    case POWER_SWEEP:
        return("POW");
    case CW_MODE_SWEEP:
        return("CW");
    case TIME_SWEEP:
        return("POIN");
    }
    // Default
    return("LIN");
}
ReferenceLevel Vna::_Channel::Scpi_To_ReferenceLevel(QString scpi) {
    if (scpi == "CPAD")
        return(RELATIVE_REFERENCE_LEVEL);
    if (scpi == "ONLY")
        return(ABSOLUTE_REFERENCE_LEVEL);
    // Default
    return(ABSOLUTE_REFERENCE_LEVEL);
}
SweepType Vna::_Channel::Scpi_To_SweepType(QString scpi) {
    if (scpi == "LIN")
        return(LINEAR_FREQUENCY_SWEEP);
    if (scpi == "LOG")
        return(LOG_FREQUENCY_SWEEP);
    if (scpi == "SEGM")
        return(SEGMENTED_SWEEP);
    if (scpi == "POW")
        return(POWER_SWEEP);
    if (scpi == "CW")
        return(CW_MODE_SWEEP);
    if (scpi == "POIN")
        return(TIME_SWEEP);
    // Default
    return(LINEAR_FREQUENCY_SWEEP);
}
CorrectionState Vna::_Channel::Scpi_To_CorrectionState(QString scpi) {
    if (scpi == "CAL")
        return(APPLIED_CORRECTION);
    if (scpi == "CAI")
        return(INTERPOLATED_CORRECTION);
    if (scpi == "CAL OFF")
        return(DISABLED_CORRECTION);
    if (scpi.isEmpty())
        return(NO_CORRECTION);
    // Default
    return(NO_CORRECTION);
}

// CHANNEL:PRIVATE:Read network
uint Vna::_Channel::NetworkBufferSize(uint points, uint ports) {
    const uint SIZE_PER_POINT = 20;
    return((uint) 2 * ports*ports * points*SIZE_PER_POINT);
}
uint Vna::_Channel::StimulusBufferSize(uint points) {
    const uint SIZE_PER_POINT = 16;
    return((uint)SIZE_PER_POINT * points);
}
void Vna::_Channel::ParseStimulus(RowVector &stimulus_data, QString readback) {
    QStringList stim_list = readback.split(',');
    uint points = stim_list.length();
    stimulus_data.resize(points);
    for (uint i=0; i < points; i++) {
        stimulus_data[i] = stim_list[i].toDouble();
    }
}
void Vna::_Channel::ParseNetworkData(NetworkData &network, QString readback) {
    QStringList data_list = readback.split(',');
    network.data.resize(network.points);
    for (uint freq = 0; freq < network.points; freq++) {
        network.data[freq].resize(network.points);
        for (uint row = 0; row < network.ports; row++) {
            network.data[freq][row].resize(network.ports);
            for (uint column = 0; column < network.ports; column++) {
                int index = (network.ports * row + column) * 2 * network.points + 2 * freq;
                network.data[freq][row][column] =
                        std::complex<double>(data_list[index].toDouble(), data_list[index+1].toDouble());
            }
        }
    }
}


/***********************
*** TRACE **************
***********************/

Vna::_Trace& Vna::Trace(QString trace_name) {
    _trace = _Trace(this, trace_name);
    return(_trace);
}

Vna::_Trace::_Trace(Vna *vna, QString trace_name) {
    this->vna = vna;
    this->trace_name = trace_name;
}

// TRACE:Select
void Vna::_Trace::Select() {
    QByteArray c_string = trace_name.toLocal8Bit();
    const uint BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    uint channel = GetChannel();
    sprintf(buffer, ":CALC%d:PAR:SEL \'%s\'\n", channel, c_string.constData());
    vna->bus->Write(QString(buffer));
}

// TRACE:Get
void Vna::_Trace::GetStimulusValues(RowVector &stimulus_data) {
    uint channel = GetChannel();
    uint points = vna->Channel(channel).GetPoints();
    uint buffer_size = StimulusBufferSize(points);
    QScopedPointer<char> buffer(new char[buffer_size]);
    sprintf(buffer.data(), ":CALC%d:DATA:STIM?\n", channel);
    vna->bus->Query(QString(buffer.data()), buffer.data(), buffer_size);
    ParseStimulus(stimulus_data, buffer.data());
}
uint Vna::_Trace::GetChannel() {
    QByteArray c_string = trace_name.toLocal8Bit();
    const uint BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:TRAC:CHAN:NAME:ID? \'%s\'\n", c_string.constData());
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}
void Vna::_Trace::GetParameters(NetworkParameter &parameter, uint &port1, uint &port2) {
    QByteArray trace_byte_array = trace_name.toLocal8Bit();
    char * trace_name_c = trace_byte_array.data();
    uint channel = GetChannel();
    const uint BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:MEAS? \'%s\'\n", channel, trace_name_c);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    ParseParameters(QString(buffer), parameter, port1, port2);
}
TraceFormat Vna::_Trace::GetFormat() {
    uint channel = GetChannel();
    QString selected_trace = vna->Channel(channel).GetSelectedTrace();
    Select();
    const uint BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:FORM?\n", channel);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    if (trace_name != selected_trace)
        Vna::_Trace(vna, selected_trace).Select();
    return(Scpi_To_TraceFormat(QString(buffer)));
}
uint Vna::_Trace::GetDiagram() {
    const uint BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    QByteArray byte_array = trace_name.toLocal8Bit();
    char *trace_c_string = byte_array.data();
    sprintf(buffer, ":CONF:TRAC:WIND:TRAC? \'%s\'\n", trace_c_string);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}

// TRACE:Set
void Vna::_Trace::SetParameters(NetworkParameter parameter, uint port1, uint port2) {
    QByteArray c_name = trace_name.toLocal8Bit();
    QByteArray c_parameters = Parameters_to_Scpi(parameter, port1, port2).toLocal8Bit();
    uint channel = GetChannel();
    const uint BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:MEAS \'%s\', \'%s\'\n", channel, c_name.constData(), c_parameters.constData());
    vna->bus->Write(QString(buffer));
}
void Vna::_Trace::SetFormat(TraceFormat format) {
    uint channel = GetChannel();
    QString selected_trace = vna->Channel(channel).GetSelectedTrace();
    Select();
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:FORM %s\n", channel, ToScpi(format));
    vna->bus->Write(QString(buffer));
    if (trace_name != selected_trace)
        vna->Trace(selected_trace).Select();
}

// TRACE:Measure
void Vna::_Trace::MeasureTrace(TraceData &trace) {
    // Info, buffer
    uint channel_index = GetChannel();
    Vna::_Channel channel(vna, channel_index);
    uint points = channel.GetPoints();
    TraceFormat format = GetFormat();
    uint buffer_size = TraceBufferSize(format, points);
    QScopedArrayPointer<char> buffer(new char[buffer_size]);
    QByteArray c_trace_name = trace_name.toLocal8Bit();

    // Handle analyzer discrepancy
    if (vna->model == ZNB_MODEL || vna->model == ZNC_MODEL) {
        sprintf(buffer.data(), ":CALC:DATA:TRAC? \'%s\', FDAT\n", c_trace_name.constData());
    }
    else {
        // ZVA doesn't have "CALC:DATA:TRAC?" command. Use a different method.
        Select();
        sprintf(buffer.data(), ":CALC%d:DATA? FDAT", channel_index);
    }

    // Read data
    if (channel.isContinuousSweepEnabled()) {
        channel.DisableContinuousSweep();
        channel.InitiateSweep();
        vna->FinishPreviousCommandsFirst();
        vna->bus->Query(QString(buffer.data()), buffer.data(), buffer_size);
        channel.EnableContinuousSweep();
    }
    else {
        channel.InitiateSweep();
        vna->FinishPreviousCommandsFirst();
        vna->bus->Query(QString(buffer.data()), buffer.data(), buffer_size);
    }

    // Parse data
    GetParameters(trace.network_parameter, trace.port1, trace.port2);
    trace.points = points;
    trace.sweep_type = channel.GetSweepType();
    trace.format = format;
    trace.date_time = QDateTime::currentDateTime();
    GetUnits(trace);
    ParseData(trace, buffer.data());
    GetStimulusValues(trace.stimulus_points);
}

// TRACE:Private:General
const char* Vna::_Trace::ToScpi(TraceFormat format) {
    switch(format) {
    case DB_MAGNITUDE_TRACE:
        return("MLOG");
        break;
    case PHASE_DEG_TRACE:
        return("PHAS");
        break;
    case SMITH_CHART_TRACE:
        return("SMIT");
        break;
    case POLAR_CHART_TRACE:
        return("POL");
        break;
    case VSWR_TRACE:
        return("SWR");
        break;
    case UNWRAP_PHASE_DEG_TRACE:
        return("UPH");
        break;
    case LINEAR_MAGNITUDE_TRACE:
        return("MLIN");
        break;
    case INVERSE_SMITH_CHART_TRACE:
        return("ISM");
        break;
    case REAL_PART_TRACE:
        return("REAL");
        break;
    case IMAGINARY_PART_TRACE:
        return("IMAG");
        break;
    case DELAY_TRACE:
        return("GDE");
        break;
    }
    // Default
    return("MLOG");
}
TraceFormat Vna::_Trace::Scpi_To_TraceFormat(QString scpi) {
    if (scpi == "MLOG")
        return(DB_MAGNITUDE_TRACE);
    if (scpi == "PHAS")
        return(PHASE_DEG_TRACE);
    if (scpi == "SMIT")
        return(SMITH_CHART_TRACE);
    if (scpi == "POL")
        return(POLAR_CHART_TRACE);
    if (scpi == "SWR")
        return(VSWR_TRACE);
    if (scpi == "UPH")
        return(UNWRAP_PHASE_DEG_TRACE);
    if (scpi == "MLIN")
        return(LINEAR_MAGNITUDE_TRACE);
    if (scpi == "ISM")
        return(INVERSE_SMITH_CHART_TRACE);
    if (scpi == "REAL")
        return(REAL_PART_TRACE);
    if (scpi == "IMAG")
        return(IMAGINARY_PART_TRACE);
    if (scpi == "GDE")
        return(DELAY_TRACE);
    // Default
    return(DB_MAGNITUDE_TRACE);
}
NetworkParameter Vna::_Trace::Scpi_To_NetworkParameter(QString scpi) {
    if (scpi == "S")
        return(S_PARAMETER);
    if (scpi == "Y")
        return(Y_PARAMETER);
    if (scpi == "Z")
        return(Z_PARAMETER);
    if (scpi == "H")
        return(H_PARAMETER);
    if (scpi == "G")
        return(G_PARAMETER);
    // Default
    return(S_PARAMETER);
}
void Vna::_Trace::ParseParameters(QString readback, NetworkParameter &parameter, uint &port1, uint &port2) {
    readback.remove(0,1);
    readback.chop(1);
    parameter = Scpi_To_NetworkParameter(readback.mid(0, 1));
    if (readback.length() == 3) {
        // "%c%1d%1d" format
        port1 = readback.mid(1,1).toUInt();
        port2 = readback.mid(2,1).toUInt();
    }
    else if (readback.length() == 5) {
        // "%c%2d%2d" format
        port1 = readback.mid(1,2).toUInt();
        port2 = readback.mid(3,2).toUInt();
    }
    else {  //readback.length() is 7?!!
        // "%c%3d%3d" format
        port1 = readback.mid(1,3).toUInt();
        port2 = readback.mid(4,3).toUInt();
    }
}
QString Vna::_Trace::Parameters_to_Scpi(NetworkParameter parameter, uint port1, uint port2) {
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

// TRACE:Private:Read Trace
uint Vna::_Trace::TraceBufferSize(TraceFormat format, uint points) {
    const uint SIZE_PER_POINT = 16;
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
uint Vna::_Trace::StimulusBufferSize(uint points) {
    const uint SIZE_PER_POINT = 16;
    return((uint)SIZE_PER_POINT * points);
}
void Vna::_Trace::ParseData(TraceData &trace, QString data) {
    // Assumes Trace has enough data for isComplex() to return
    QStringList data_list = data.split(',');
    if (trace.isComplex()) {
        trace.complex_data.resize(trace.points);
        for (uint i=0; i < trace.points; i++) {
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
void Vna::_Trace::ParseStimulus(RowVector &stimulus_data, QString readback) {
    QStringList stim_list = readback.split(',');
    uint points = stim_list.length();
    stimulus_data.resize(points);
    for (uint i=0; i < points; i++) {
        stimulus_data[i] = stim_list[i].toDouble();
    }
}
void Vna::_Trace::GetUnits(TraceData &trace) {
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


/***********************
*** DIAGRAM ************
***********************/

Vna::_Diagram& Vna::Diagram(uint diagram) {
    _diagram = _Diagram(this, diagram);
    return(_diagram);
}

Vna::_Diagram::_Diagram(Vna *vna, uint diagram) {
    this->vna = vna;
    this->diagram = diagram;
}

// DIAGRAM:Get
QStringList Vna::_Diagram::GetTraces() {
    const uint BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    QStringList traces;
    sprintf(buffer, ":DISP:WIND%d:TRAC:CAT?\n", diagram);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    Vna::ParseNamesFromRead(buffer, traces);
    qSort(traces);
    return(traces);
}
QVector<uint> Vna::_Diagram::GetChannels() {
    QStringList traces = GetTraces();
    QVector<uint> channels;
    for (int i = 0; i < traces.length(); i++) {
        uint current_channel = Vna::_Trace(vna, traces[i]).GetChannel();
        if (!channels.contains(current_channel))
            channels.append(current_channel);
    }
    qSort(channels);
    return(channels);
}
QString Vna::_Diagram::GetTitle() {
    const uint BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:TITL:DATA?\n", diagram);
    vna->bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    QString title(buffer);
    title.remove(0,1);
    title.chop(1);
    return(title);
}

// DIAGRAM:Set
void Vna::_Diagram::SetTitle(QString title) {
    const uint BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = title.toLocal8Bit();
    sprintf(buffer, ":DISP:WIND%d:TITL:DATA \'%s\'\n", diagram, c_string.constData());
    vna->bus->Write(QString(buffer));
}
