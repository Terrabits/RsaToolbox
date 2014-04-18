#include <QDebug>

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
#include <QFileInfo>
#include <QDateTime>
#include <QScopedArrayPointer>

// C++
#include <cstdio>
#include <complex>
#include <vector>

using namespace RsaToolbox;



//**********************
//** Vna ***************
//*********************/

Vna::Vna()
    : QObject()
{
    bus.reset(new RsibBus());
    model = UNKNOWN_MODEL;
    serial_no = "";
    firmware_version = "";
    ports = 0;
    minimum_frequency_Hz = 0;
    maximum_frequency_Hz = 0;
    options = QStringList();
}
Vna::Vna(ConnectionType connection_type, QString instrument_address, uint timeout_ms)
    : QObject()
{
    Reset(connection_type, instrument_address, timeout_ms);
}
Vna::~Vna() {
    bus->disconnect();
}

void Vna::ConnectLog(Log &log) {
    this->log = &log;

    // Connect log
    QObject::connect(bus.data(), SIGNAL(print(QString)),
                     &log, SLOT(print(QString)));
    QObject::connect(this, SIGNAL(Print(QString)),
                     &log, SLOT(print(QString)));

    PrintInstrumentInfo();
}
void Vna::DisconnectLog() {
    // Disconnect Log
    QObject::disconnect(bus.data(), SIGNAL(Print(QString)),
                        log, SLOT(Print));
    QObject::disconnect(this, SIGNAL(Print(QString)),
                        log, SLOT(Print(QString)));
}

// VNA:General
bool Vna::isConnected() {
    return(bus->isOpen());
}
bool Vna::isNotConnected() {
    return(!isConnected());
}
bool Vna::isCalUnitConnected() {
    return(!isNoCalUnitConnected());
}
bool Vna::isNoCalUnitConnected() {
    return(GetCalUnits().isEmpty());
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

bool Vna::Lock() {
    return(bus->lock());
}
bool Vna::Unlock() {
    return(bus->unlock());
}
bool Vna::Local() {
    return(bus->local());
}
bool Vna::Remote() {
    return(bus->remote());
}
bool Vna::Read(char *buffer, unsigned int buffer_size) {
    return(bus->read(buffer, buffer_size));
}
bool Vna::Write(QString scpi_command) {
    return(bus->write(scpi_command));
}
bool Vna::Query(QString scpi_command, char *buffer, unsigned int buffer_size) {
    return(bus->query(scpi_command, buffer, buffer_size));
}

// VNA:Actions
void Vna::ServiceFunction(QString password, QString command) {
    password = QString(":SYST:PASS \'%1\'\n").arg(password);
    command = QString(":DIAG:SERV:SFUN \'%1\'\n").arg(command);

    bus->write(password);
    bus->write(command);
}
void Vna::Preset() {
    bus->write("*RST\n");
}
void Vna::ClearStatus() {
    bus->write("*CLS\n");
}
void Vna::ClearErrors() {
    isError();
}
void Vna::InitiateSweeps() {
    bus->write(":INIT:SCOP ALL\n");
    bus->write(":INIT\n");
}
void Vna::WaitForSweeps() {
    bus->write("*WAI\n");
}
void Vna::PauseUntilCommandQueueIsFinished() {
    const uint BUFFER_SIZE = 5;
    char buffer[BUFFER_SIZE];
    bus->query("*OPC?\n", buffer, BUFFER_SIZE);
}
void Vna::AutoscaleDiagrams() {
    QVector<uint> diagrams = GetDiagrams();
    uint number_of_diagrams = diagrams.size();
    for (uint i = 0; i < number_of_diagrams; i++) {
        Diagram(diagrams[i]).Autoscale();
    }
}

// VNA::Directory Handling
bool Vna::isFilePresent(QString file) {
    QFileInfo file_info(file);
    QString name = file_info.fileName();
    QString parent = QDir::toNativeSeparators(file_info.dir().absolutePath());

    QString current = GetDirectory();
    if (parent.isEmpty() == false) {
        SetDirectory(parent);
        bool isPresent = GetFileList().contains(name, Qt::CaseInsensitive);
        SetDirectory(current);
        return(isPresent);
    }
    else {
        return(GetFileList().contains(name, Qt::CaseInsensitive));
    }
}
bool Vna::isDirectoryPresent(QString directory) {
    if (directory.endsWith('\\') || directory.endsWith('/'))
        directory.chop(1);

    QFileInfo dir_info(directory);
    QString name = dir_info.fileName();
    QString parent = QDir::toNativeSeparators(dir_info.dir().absolutePath());

    QString current = GetDirectory();
    if (parent.isEmpty() == false) {
        SetDirectory(parent);
        bool isPresent = GetDirectoryList().contains(name, Qt::CaseInsensitive);
        SetDirectory(current);
        return(isPresent);
    }
    else {
        return(GetDirectoryList().contains(name, Qt::CaseInsensitive));
    }
}
void Vna::ClearDirectory(QString directory) {
    if (isDirectoryPresent(directory) == false)
        return;

    QString current = GetDirectory();
    SetDirectory(directory);
    QStringList files = GetFileList();
    DeleteFiles(files);
    SetDirectory(current);
}

QString Vna::Dir() {
    const unsigned int BUFFER_SIZE = 4000;
    char buffer[BUFFER_SIZE];
    bus->query(":MMEM:CAT?\n", buffer, BUFFER_SIZE);
    return(QString(buffer));
}
QString Vna::GetDirectory() {
    const unsigned int BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    bus->query(":MMEM:CDIR?\n", buffer, BUFFER_SIZE);
    QString directory(buffer);
    directory.remove('\'');
    return(directory);
}
QString Vna::GetDirectory(VnaDirectory directory) {
    QString dir = GetDefaultDirectory();
    switch(directory) {
    case CAL_KIT_DIRECTORY:
        return(dir + "\\Calibration\\Kits\\");
    case CAL_GROUP_DIRECTORY:
        return(dir + "\\Calibration\\Data\\");
    case RECALL_SETS_DIRECTORY:
        return(dir + "\\RecallSets\\");
    case TRACES_DIRECTORY:
        return(dir + "\\Traces\\");
    default:
        return(dir);
    }
}
int Vna::GetFreeSpace_B() {
    QString readback = Dir();
    int size_of_files_B, free_space_B;
    QStringList files, directories;
    QVector<int> file_sizes_B;
    ParseDir(readback,
             size_of_files_B, free_space_B,
             files, file_sizes_B,
             directories);
    return(free_space_B);
}
QString Vna::GetDefaultDirectory() {
    QString current_dir = GetDirectory();
    SetDefaultDirectory();
    QString default_dir = GetDirectory();
    SetDirectory(current_dir);
    return(default_dir);
}
void Vna::GetDirectoryContents(QStringList &files, QStringList &directories) {
    QString readback = Dir();
    int size_of_files_B, free_space_B;
    QVector<int> file_sizes_B;
    ParseDir(readback,
             size_of_files_B, free_space_B,
             files, file_sizes_B,
             directories);
}
void Vna::GetDirectoryContents(QStringList &files, QVector<int> &file_sizes_B,
                               QStringList &directories) {
    QString readback = Dir();
    int size_of_files_B, free_space_B;
    ParseDir(readback,
             size_of_files_B, free_space_B,
             files, file_sizes_B,
             directories);
}
QStringList Vna::GetFileList() {
    QString readback = Dir();
    int size_of_files_B, free_space_B;
    QStringList files, directories;
    QVector<int> file_sizes_B;
    ParseDir(readback,
             size_of_files_B, free_space_B,
             files, file_sizes_B,
             directories);
    return(files);
}
void Vna::GetFileList(QStringList &files, QVector<int> &file_sizes_B) {
    QString readback = Dir();
    int size_of_files_B, free_space_B;
    QStringList directories;
    ParseDir(readback,
             size_of_files_B, free_space_B,
             files, file_sizes_B,
             directories);
}
void Vna::GetFileList(QStringList &files, QVector<int> &file_sizes_B, int &size_of_files_B) {
    QString readback = Dir();
    int free_space_B;
    QStringList directories;
    ParseDir(readback,
             size_of_files_B, free_space_B,
             files, file_sizes_B,
             directories);
}
int Vna::GetFileSize_B(QString path) {
    QString current_directory = GetDirectory();

    QFileInfo file_info(path);
    QString name = file_info.fileName();
    int size_B = 0;

    QString directory = file_info.path();
    if (directory.isEmpty() == false) {
        directory = QDir::toNativeSeparators(directory);
        SetDirectory(directory);
    }

    QStringList files;
    QVector<int> sizes_B;
    int total_size_B;
    GetFileList(files, sizes_B, total_size_B);

    // Case insensitive compare
    // (Firmware runs on standard windows FS)
    for (int i = 0; i < files.size(); i++) {
        if (files[i].compare(name, Qt::CaseInsensitive) == 0)
            size_B = sizes_B[i];
    }

    if (directory.isEmpty() == false)
        SetDirectory(current_directory);
    return(size_B);
}
QStringList Vna::GetDirectoryList() {
    QString readback = Dir();
    int size_of_files_B, free_space_B;
    QStringList files, directories;
    QVector<int> file_sizes_B;
    ParseDir(readback,
             size_of_files_B, free_space_B,
             files, file_sizes_B,
             directories);
    return(directories);
}
QString Vna::GetCalGroupDirectory() {
    return(GetDefaultDirectory() + "\\Calibration\\Data\\");
}
void Vna::SetDefaultDirectory() {
    bus->write(":MMEM:CDIR DEF\n");
}
void Vna::SetDirectory(QString directory) {
    QByteArray c_string = directory.toUtf8();
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":MMEM:CDIR \'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}
void Vna::SetDirectory(VnaDirectory directory) {
    switch(directory) {
    case DEFAULT_DIRECTORY:
        SetDefaultDirectory();
        break;
    case CAL_GROUP_DIRECTORY:
        SetDirectory(GetCalGroupDirectory());
        break;
    default:
        break;
    }
}

void Vna::MoveFile(QString source, QString destination) {
    QString scpi;
    scpi = ":MMEM:MOVE \'" + source + "\',\'" + destination + "\'\n";
    bus->write(scpi);
}
void Vna::CreateDirectory(QString directory) {
    QString scpi;
    scpi = ":MMEM:MDIR \'" + directory + "\'\n";
    bus->write(scpi);
}
void Vna::CopyFile(QString source, QString destination) {
    QString scpi;
    scpi = ":MMEM:COPY \'" + source + "\',\'" + destination + "\'\n";
    bus->write(scpi);
}
void Vna::DeleteFile(QString filename) {
    QString scpi;
    scpi = ":MMEM:DEL \'" + filename + "\',FORC\n";
    bus->write(scpi);
}
void Vna::DeleteFiles(QStringList filenames) {
    foreach(const QString file, filenames)
        DeleteFile(file);
}
void Vna::DeleteDirectory(QString directory) {
    QString scpi;
    scpi = ":MMEM:RDIR \'" + directory + "\'\n";
    bus->write(scpi);
}

// VNA:Status
bool Vna::isZvaFamily() {
    VnaModel model = GetModel();
    switch(model) {
    case ZVA_MODEL:
    case ZVB_MODEL:
    case ZVH_MODEL:
    case ZVL_MODEL:
    case ZVT_MODEL:
        return(true);
    default:
        return(false);
    }
}
bool Vna::isZnbFamily() {
    VnaModel model = GetModel();
    switch(model) {
    case ZNB_MODEL:
    case ZNC_MODEL:
    case ZNP_MODEL:
        return(true);
    default:
        return(false);
    }
}
bool Vna::isUnknownModel() {
    return(GetModel() == UNKNOWN_MODEL);
}

bool Vna::isDisplayEnabled() {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    bus->query(":SYST:DISP:UPD?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toInt() != 1);
}
bool Vna::isDisplayDisabled() {
    return(!isDisplayEnabled());
}
bool Vna::isError() {
    const uint BUFFER_SIZE = 2000;
    char buffer[BUFFER_SIZE];
    bus->query(":SYST:ERR:ALL?\n", buffer, BUFFER_SIZE);

    QString first_result = QString(buffer).split(",").first();
    if (first_result.toInt() != 0) {
        Print("    Errors:\n");
        Print("    ");
        Print(ToString(QString(buffer).split(","), "\n    "));
        Print("\n\n");
        return(true);
    }
    else {
        return(false);
    }
}
bool Vna::isErrorDisplayEnabled() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->query(":SYST:ERR:DISP?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isErrorDisplayDisabled() {
    return(!isErrorDisplayEnabled());
}

bool Vna::isChannelEnabled(uint channel) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d?\n", channel);
    bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isChannelEnabled(QString name) {
    QByteArray c_name = name.toUtf8();

    const uint BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN:NAME:ID? \'%s\'\n", c_name.constData());

    ClearStatus();
    bus->query(QString(buffer), buffer, BUFFER_SIZE);
    if (QString(buffer).isEmpty() || isError()) {
        ClearStatus();
        return(false);
    }
    else {
        return(true);
    }
}
bool Vna::isChannelDisabled(uint channel) {
    return(!isChannelEnabled(channel));
}
bool Vna::isChannelDisabled(QString name) {
    return(!isChannelEnabled(name));
}

bool Vna::isConnectorTypeDefined(Connector type) {
    if (type.isNotCustomType())
        return(true);

    // else
    return(isConnectorTypeDefined(type.customType()));
}
bool Vna::isConnectorTypeDefined(QString custom_type) {
    if (custom_type.isEmpty())
        return(false);

    QVector<Connector> types = GetConnectorTypes();
    foreach (Connector type, types) {
        if (type.isCustomType()
                && custom_type == type.customType())
            return(true);
    }

    // else
    return(false);
}
bool Vna::isCalKitPresent(QString name, QString label) {
    return(GetCalKits().contains(NameLabel(name, label)));
}

bool Vna::isUserPresetEnabled() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->query(":SYST:PRES:USER?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isUserPresetDisabled() {
    return(!isUserPresetEnabled());
}
bool Vna::isUserCalPresetEnabled() {
    if (model == ZNB_MODEL || model == ZNC_MODEL)
        return(GetUserCalPreset().isEmpty() == true);
    else
        return(false);
}
bool Vna::isUserCalPresetDisabled() {
    return(!isUserCalPresetEnabled());
}
bool Vna::isUserPresetMappedToRst() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->query("SYST:PRES:REM?\n", buffer, BUFFER_SIZE);
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
    bus->query(QString(buffer), buffer, BUFFER_SIZE);
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
    bus->query(":OUTP?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isRfOutputPowerDisabled() {
    return(!isRfOutputPowerEnabled());
}
bool Vna::isDynamicIfBandwidthEnabled() {
    const uint BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->query(":BAND:DRED?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isDynamicIfBandwidthDisabled() {
    return(!isDynamicIfBandwidthEnabled());
}
bool Vna::isLowPowerAutoCalEnabled() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->query(":SYST:COMM:RDEV:AKAL:PRED?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::isLowPowerAutoCalDisabled() {
    return(!isLowPowerAutoCalEnabled());
}

// VNA:Select
void Vna::SelectSet(QString set_name) {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = set_name.toUtf8();
    sprintf(buffer, ":MEM:SEL \'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}

// VNA:Get
QString Vna::GetIdentificationString() {
    const uint BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    bus->query("*IDN?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).trimmed());
}
QStringList Vna::GetOptions() {
    const uint BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    bus->query("*OPT?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).trimmed().split(','));
}
uint Vna::GetPorts() {
    const uint BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->query(":INST:PORT:COUN?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}
uint Vna::GetTestPorts() {
    // ZVA does not have this command
    if (isZvaFamily())
        return(GetPorts());

    const uint BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->query(":INST:TPORT:COUN?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}
double Vna::GetMinimumFrequency_Hz() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->query(":SYST:FREQ? MIN\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetMaximumFrequency_Hz() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    bus->query(":SYST:FREQ? MAX\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::GetMinimumPower_dBm() {
    VnaModel model = GetModel();
    switch(model) {
    case ZVA_MODEL:
    case ZVT_MODEL:
    case ZVH_MODEL:
    case ZVL_MODEL:
        return(-150);
    case ZNB_MODEL:
    case ZNC_MODEL:
    case ZNP_MODEL:
        return(-40);
    default:
        return(-40);
    }
}
double Vna::GetMaximumPower_dBm() {
    VnaModel model = GetModel();
    switch(model) {
    case ZVA_MODEL:
    case ZVT_MODEL:
    case ZVH_MODEL:
    case ZVL_MODEL:
        return(100);
    case ZNB_MODEL:
    case ZNC_MODEL:
    case ZNP_MODEL:
        return(10);
    default:
        return(10);
    }
}
QVector<double> Vna::GetSourceAttenuationStates() {
    const uint port1 = 1;
    QVector<double> attenuations;
    attenuations << 0;
    QVector<uint> channels = GetChannels();
    uint new_channel = Max(channels) + 1;
    CreateChannel(new_channel);

    ClearStatus();
    DisableErrorDisplay();
    Channel(new_channel).SetSourceAttenuation(port1, 0);
    if (isError()) {
        ClearStatus();
    }
    else {
        for (double i = 1; i <= 100; i++) {
            Channel(new_channel).SetSourceAttenuation(port1, i);
            double attenuation = Channel(new_channel).GetSourceAttenuation_dB(port1);
            if (attenuation == i)
                attenuations << attenuation;
        }
    }

    EnableErrorDisplay();
    DeleteChannel(new_channel);
    return(attenuations);
}
QVector<double> Vna::GetReceiverAttenuationStates() {
    const uint port1 = 1;
    QVector<double> attenuations;
    attenuations << 0;
    QVector<uint> channels = GetChannels();
    uint new_channel = Max(channels) + 1;
    CreateChannel(new_channel);


    ClearStatus();
    DisableErrorDisplay();
    Channel(new_channel).SetReceiverAttenuation(port1, 0);
    if (isError()) {
        ClearStatus();
    }
    else {
        for (double i = 1; i <= 100; i++) {
            Channel(new_channel).SetReceiverAttenuation(port1, i);
            double attenuation = Channel(new_channel).GetReceiverAttenuation_dB(port1);
            if (attenuation == i)
                attenuations << attenuation;
        }
    }

    EnableErrorDisplay();
    DeleteChannel(new_channel);
    return(attenuations);
}
QVector<double> Vna::GetIfBandwidthStates_Hz() {
    QVector<double> states;
    if (model == ZNB_MODEL || ZNC_MODEL || ZNP_MODEL) {
        // Hz
        states << 1
               << 2
               << 5
               << 10
               << 20
               << 50
               << 100
               << 200
               << 500;
        // KHz
        states << 1E3
               << 2E3
               << 5E3
               << 10E3
               << 20E3
               << 50E3
               << 100E3
               << 200E3
               << 500E3;
        // MHz
        states << 1E6
               << 2E6
               << 5E6
               << 10E6
               << 20E6
               << 30E6;
    }
    else {
        // Hz
        states << 1
               << 2
               << 3
               << 4
               << 5
               << 7
               << 10
               << 15
               << 20
               << 30
               << 50
               << 70
               << 100
               << 150
               << 200
               << 300
               << 500
               << 700;
        // KHz
        states << 1E3
               << 1.5E3
               << 2E3
               << 3E3
               << 5E3
               << 7E3
               << 10E3
               << 15E3
               << 20E3
               << 30E3
               << 50E3
               << 70E3
               << 100E3
               << 150E3
               << 200E3
               << 300E3
               << 500E3
               << 700E3;
        // MHz
        states << 1E6
               << 1.5E6
               << 2E6
               << 3E6
               << 5E6
               << 7E6
               << 10E6;
    }
    return(states);
}
void Vna::GetIfBandwidthStates(QVector<QStringList> &values, QStringList &units) {
    values.clear();
    units.clear();
    if (model == ZNB_MODEL || ZNC_MODEL || ZNP_MODEL) {
        QStringList if_mantissa_Hz;
        if_mantissa_Hz << "1"
                       << "2"
                       << "5"
                       << "10"
                       << "20"
                       << "50"
                       << "100"
                       << "200"
                       << "500";
        QStringList if_mantissa_KHz;
        if_mantissa_KHz << "1"
                        << "2"
                        << "5"
                        << "10"
                        << "20"
                        << "50"
                        << "100"
                        << "200"
                        << "500";
        QStringList if_mantissa_MHz;
        if_mantissa_MHz << "1"
                        << "2"
                        << "5"
                        << "10"
                        << "20"
                        << "30";
        values << if_mantissa_Hz
               << if_mantissa_KHz
               << if_mantissa_MHz;
        units  << "Hz"
               << "KHz"
               << "MHz";
    }
    else if (model != UNKNOWN_MODEL){
        QStringList if_mantissa_Hz;
        if_mantissa_Hz << "1"
                       << "2"
                       << "3"
                       << "4"
                       << "5"
                       << "7"
                       << "10"
                       << "15"
                       << "20"
                       << "30"
                       << "50"
                       << "70"
                       << "100"
                       << "150"
                       << "200"
                       << "300"
                       << "500"
                       << "700";
        QStringList if_mantissa_KHz;
        if_mantissa_KHz << "1"
                        << "1.5"
                        << "2"
                        << "3"
                        << "5"
                        << "7"
                        << "10"
                        << "15"
                        << "20"
                        << "30"
                        << "50"
                        << "70"
                        << "100"
                        << "150"
                        << "200"
                        << "300"
                        << "500"
                        << "700";
        QStringList if_mantissa_MHz;
        if_mantissa_MHz << "1"
                        << "1.5"
                        << "2"
                        << "3"
                        << "5"
                        << "7"
                        << "10";
        values << if_mantissa_Hz
               << if_mantissa_KHz
               << if_mantissa_MHz;
        units  << "Hz"
               << "KHz"
               << "MHz";
    }
}
QStringList Vna::GetOpenSets() {
    const unsigned int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    bus->query(":MEM:CAT?\n", buffer, BUFFER_SIZE);
    QString readback(buffer);
    readback.remove('\'');
    return(readback.split(','));
}
double Vna::GetPortPowerLimit(uint port) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:LLIM:VAL?\n", port);
    bus->query(QString(buffer), buffer, BUFFER_SIZE);
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
    bus->query(":SYST:DISP:COL?\n", buffer, BUFFER_SIZE);
    return(Scpi_To_ColorScheme(buffer));
}
uint Vna::GetFontSize_percent() {
    const uint BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    bus->query(":DISP:RFS?\n", buffer, BUFFER_SIZE);
    return(QString(buffer).toInt());
}
QString Vna::GetUserPreset() {
    const uint BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    bus->query(":SYST:PRES:USER:NAME?\n", buffer, BUFFER_SIZE);
    QString user_preset = QString(buffer);
    user_preset.remove('\'');
    return(user_preset);
}
QString Vna::GetUserCalPreset() {
    if (model == ZNB_MODEL || model == ZNC_MODEL) {
        const unsigned int BUFFER_SIZE = 500;
        char buffer[BUFFER_SIZE];
        bus->query(":SYST:PRES:USER:CAL?\n", buffer, BUFFER_SIZE);
        return(QString(buffer).remove('\''));
    }
    else
        return("");
}

QVector<Connector> Vna::GetConnectorTypes() {
    const int BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    bus->query(":CORR:CONN:CAT?\n", buffer, BUFFER_SIZE);
    QStringList list = QString(buffer).remove('\'').split(',');
    QVector<Connector> types;
    foreach (QString item, list) {
        ConnectorType type = Scpi_To_ConnectorType(item);
        Connector new_type;
        if (type == CUSTOM_CONNECTOR) {
            new_type.setCustomType(item);
            types.append(new_type);
        }
        else {
            new_type.setType(type);
            types.append(new_type);
        }
    }
    return(types);
}
QVector<NameLabel> Vna::GetCalKits() {
    QVector<Connector> types = GetConnectorTypes();
    QVector<NameLabel> kits;
    foreach (Connector type, types) {
        kits += GetCalKits(type);
    }

    return(kits);
}
QVector<NameLabel> Vna::GetCalKits(Connector type) {
    if (type.isCustomType())
        return(GetCalKits(type.customType()));
    else
        return(GetCalKits(type.type()));
}
QVector<NameLabel> Vna::GetCalKits(ConnectorType type) {
    const int BUFFER_SIZE = 2000;
    char buffer[BUFFER_SIZE];
    QString scpi = ":CORR:CKIT:LCAT? \'" + QString(ToScpi(type)) + "\'\n";
    bus->query(scpi, buffer, BUFFER_SIZE);
    QStringList result = QString(buffer).remove('\'').split(',', QString::KeepEmptyParts);
    return(NameLabel::parseNameLabelList(result));
}
QVector<NameLabel> Vna::GetCalKits(QString custom_connector_type) {
    const int BUFFER_SIZE = 2000;
    char buffer[BUFFER_SIZE];
    QString scpi = ":CORR:CKIT:LCAT? \'" + custom_connector_type + "\'\n";
    bus->query(scpi, buffer, BUFFER_SIZE);
    QStringList result = QString(buffer).remove('\'').split(',', QString::KeepEmptyParts);
    return(NameLabel::parseNameLabelList(result));
}
QStringList Vna::GetCalGroups() {
    QString directory = GetDirectory();
    SetDirectory(CAL_GROUP_DIRECTORY);
    QStringList files = GetFileList();
    SetDirectory(directory);

    int number_of_files = files.size();
    for (int i = 0; i < number_of_files; i++) {
        if (files[i].contains(".cal", Qt::CaseInsensitive) == false) {
            files.removeAt(i);
            number_of_files--;
        }
    }
    return(files);
}
QVector<uint> Vna::GetCalibratedChannels() {
    // NEED TO FINISH THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    QVector<uint> channels = GetChannels();
    int number_of_channels = channels.size();
    for (int i = 0; i < number_of_channels; i++) {
        if (Channel(i).isCalibrationPresent() == false
                && Channel(i).isPowerCalPresent() == false)
            channels.remove(i);
    }
    return(channels);
}

QStringList Vna::GetCalUnits() {
    const uint BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    bus->query(":SYST:COMM:RDEV:AKAL:ADDR:ALL?\n", buffer, BUFFER_SIZE);

    if (QString(buffer).remove('\'').isEmpty())
        return(QStringList());

    QStringList units = QString(buffer).remove('\'').split(',');
    return(units);
}
uint Vna::GetChannelId(QString name) {
    QByteArray c_name = name.toUtf8();

    const uint BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN:NAME:ID? \'%s\'\n", c_name.constData());
    bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}
QVector<uint> Vna::GetChannels() {
    const uint BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    bus->query(":CONF:CHAN:CAT?\n", buffer, BUFFER_SIZE);
    QVector<uint> channels;
    ParseIndicesFromRead(buffer, channels);
    return(channels);
}
QStringList Vna::GetTraces() {
    const uint BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    bus->query(":CONF:TRAC:CAT?\n", buffer, BUFFER_SIZE);
    QStringList traces;
    ParseNamesFromRead(buffer, traces);
    return(traces);
}
QVector<uint> Vna::GetDiagrams() {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    bus->query(":DISP:CAT?\n", buffer, BUFFER_SIZE);
    QVector<uint> diagrams;
    ParseIndicesFromRead(buffer, diagrams);
    return(diagrams);
}

// VNA:Set
void Vna::SetIdentificationString(QString id_string)  {
    if (!(model == ZNB_MODEL || model == ZNC_MODEL))
        return;
    QByteArray c_string = id_string.toUtf8();
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:IDEN \'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}
void Vna::SetOptionsString(QString options_string)  {
    if (!(model == ZNB_MODEL || model == ZNC_MODEL))
        return;
    QByteArray c_string = options_string.toUtf8();
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:OPT \'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}
void Vna::SetPortPowerLimit(uint port, double power_limit) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR:POW%d:LLIM:VAL %f\n", port, power_limit);
    bus->write(QString(buffer));
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
    bus->write(QString(buffer));
}
void Vna::SetFontSize_percent(uint size_percent)  {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:RFS %d\n", size_percent);
    bus->write(QString(buffer));
}
void Vna::SetUserPreset(QString filename)  {
    if (!filename.contains(ToSetFileExtension(model)))
        filename = filename + ToSetFileExtension(model);
    QByteArray c_string = filename.toUtf8();
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:PRES:USER:NAME \'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}
void Vna::SetUserPreset(QDir path, QString filename)  {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    if (!filename.contains(ToSetFileExtension(model)))
        filename = filename + ToSetFileExtension(model);
    filename = AppendPath(path, filename);
    filename = QDir::toNativeSeparators(filename);
    QByteArray c_string = filename.toUtf8();
    sprintf(buffer, ":SYST:PRES:USER:NAME \'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}
void Vna::SetUserCalPreset(QString cal_name) {
    if (model == ZNB_MODEL || model == ZNC_MODEL) {
        const unsigned int BUFFER_SIZE = 500;
        char buffer[BUFFER_SIZE];
        QByteArray c_string = cal_name.toUtf8();
        sprintf(buffer, ":SYST:PRES:USER:CAL \'%s\'\n", c_string.constData());
        bus->write(QString(buffer));
    }
    else
        return;
}

// VNA:Enable
void Vna::EnableDisplay(bool isEnabled) {
    if (isEnabled)
        bus->write(":SYST:DISP:UPD 1\n");
    else
        bus->write(":SYST:DISP:UPD 0\n");
}
void Vna::EnableErrorDisplay(bool isEnabled) {
    if (isEnabled)
        bus->write(":SYST:ERR:DISP 1\n");
    else
        bus->write(":SYST:ERR:DISP 0\n");
}
void Vna::EnableUserPreset(bool isEnabled) {
    if (isEnabled)
        bus->write(":SYST:PRES:USER 1\n");
    else
        bus->write(":SYST:PRES:USER 0\n");
}
void Vna::EnableUserPresetMapToRst(bool isEnabled) {
    if (isEnabled)
        bus->write(":SYST:PRES:REM 1\n");
    else
        bus->write(":SYST:PRES:REM 0\n");
}
void Vna::EnablePortPowerLimit(uint port, bool isEnabled) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":SOUR:POW%d:LLIM 1\n", port);
    else
        sprintf(buffer, ":SOUR:POW%d:LLIM 0\n", port);
    bus->write(QString(buffer));
}
void Vna::EnablePortPowerLimits(bool isEnabled) {
    for (uint i = 1; i <= ports; i++)
        EnablePortPowerLimit(i, isEnabled);
}
void Vna::EnableRfOutputPower(bool isEnabled) {
    if (isEnabled)
        bus->write(":OUTP 1\n");
    else
        bus->write(":OUTP 0\n");
}
void Vna::EnableDynamicIfBandwidth(bool isEnabled) {
    if (isEnabled)
        bus->write(":BAND:DRED 1\n");
    else
        bus->write(":BAND:DRED 0\n");
}
void Vna::EnableLowPowerAutoCal(bool isEnabled) {
    if (isEnabled)
        bus->write(":SYST:COMM:RDEV:AKAL:PRED 1\n");
    else
        bus->write(":SYST:COMM:RDEV:AKAL:PRED 0\n");
}

// VNA:Disable
void Vna::DisableDisplay(bool isDisabled) {
    EnableDisplay(!isDisabled);
}
void Vna::DisableErrorDisplay(bool isDisabled) {
    EnableErrorDisplay(!isDisabled);
}
void Vna::DisableCustomIdString(bool isDisabled) {
    if (isDisabled) {
        if (model == ZNB_MODEL || model == ZNC_MODEL)
            bus->write(":SYST:IDEN:FACT\n");
    }
}
void Vna::DisableCustomOptionsString(bool isDisabled) {
    if (isDisabled) {
        if (model == ZNB_MODEL || model == ZNC_MODEL)
            bus->write(":SYST:OPT:FACT\n");
    }
}
void Vna::DisableEmulation() {
    bus->write(":SYST:LANG \'SCPI\'\n");
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
void Vna::DisableSwitchMatrices(void) {
    bus->write(":INST:SMAT 0\n");
}
void Vna::DisableUserCalPreset(void) {
    if (model == ZNB_MODEL || model == ZNC_MODEL)
        SetUserCalPreset("");
    else
        return;
}

// VNA:Create
void Vna::ExportCalKit(QString kit_name, QString filename) {
    // MMEM:STOR:CKIT 'name','filename'
    QFileInfo file_info(filename);
    if (file_info.path().isEmpty())
        filename = ".\\Calibration\\kit\\"; // + file_info.baseName() + ".calkit";
    else
        filename = file_info.path();
    filename += file_info.baseName() + ".calkit";

    QString scpi = ":MMEM:STOR:CKIT \'" + kit_name + "\' ";
    scpi += "\'" + filename + "\'\n";
    Write(scpi);
}
void Vna::CreateSet(QString set_name) {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = set_name.toUtf8();
    sprintf(buffer, ":MEM:DEF \'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}

void Vna::CreateChannel(uint channel) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d 1\n", channel);
    bus->write(QString(buffer));
}
uint Vna::CreateChannel() {
    QVector<uint> channels = GetChannels();
    if (channels.isEmpty()) {
        CreateChannel(1);
        return(1);
    }
    else {
        uint new_channel = Max(channels) + 1;
        CreateChannel(new_channel);
        return(new_channel);
    }
}

void Vna::CreateTrace(QString trace_name, uint channel, NetworkParameter parameter, uint output_port, uint input_port) {
    const uint BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    QByteArray c_name = trace_name.toUtf8();
    QByteArray c_parameters = _Trace::Parameters_to_Scpi(parameter, output_port, input_port).toUtf8();
    sprintf(buffer, ":CALC%d:PAR:SDEF \'%s\', \'%s\'\n", channel, c_name.constData(), c_parameters.constData());
    bus->write(QString(buffer));
}
void Vna::CreateTrace(QString trace_name, uint channel, NetworkParameter parameter, PortDefinition &output_port, PortDefinition &input_port) {
    const uint BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    QByteArray c_name = trace_name.toUtf8();
    QByteArray c_parameters = _Trace::Parameters_to_Scpi(parameter, output_port, input_port).toUtf8();
    sprintf(buffer, ":CALC%d:PAR:SDEF \'%s\', \'%s\'\n", channel, c_name.constData(), c_parameters.constData());
    bus->write(QString(buffer));
}

void Vna::CreateDiagram(uint diagram) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:STAT 1\n", diagram);
    bus->write(QString(buffer));
}
uint Vna::CreateDiagram() {
    QVector<uint> diagrams = GetDiagrams();
    if (diagrams.isEmpty()) {
        CreateDiagram(1);
        return(1);
    }
    else {
        uint new_diagram = Max(diagrams) + 1;
        CreateDiagram(new_diagram);
        return(new_diagram);
    }
}

// VNA:Delete
void Vna::DeleteCalKit(QString kit_name) {
    bus->write(":CORR:CKIT:DEL \'" + kit_name + "\'\n");
}
void Vna::DeleteSet(QString filename) {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    // Fix save directory issue with firmware
    QFileInfo file_info(filename);
    if (file_info.path() == QString(".")) {
        filename = default_directory.path()
                + "/RecallSets/"
                + filename;
        file_info.setFile(filename);
    }
    if (file_info.suffix().isEmpty())
        filename = filename + ToSetFileExtension(model);
    QByteArray c_string = QDir::toNativeSeparators(filename).toUtf8();
    sprintf(buffer, ":MMEM:DEL \'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}
void Vna::DeleteUserPreset() {
    bus->write(QString(":SYST:PRES:USER:NAME \'\'\n"));
}
void Vna::DeleteCalGroup(QString cal_group) {
    const unsigned int BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = cal_group.toUtf8();
    sprintf(buffer, ":MMEM:DEL:CORR \'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}
void Vna::DeleteSwitchMatrices(void) {
    bus->write(":SYST:COMM:RDEV:SMAT:DEL\n");
}

void Vna::DeleteChannel(uint channel) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d 0\n", channel);
    bus->write(QString(buffer));
}
void Vna::DeleteChannels(QVector<uint> channels) {
    foreach(const uint channel, channels) {
        DeleteChannel(channel);
    }
}
void Vna::DeleteChannels() {
    DeleteChannels(GetChannels());
}

void Vna::DeleteTrace(QString trace_name) {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    uint channel = _Trace(this, trace_name).GetChannel();
    QByteArray c_string = trace_name.toUtf8();
    sprintf(buffer, ":CALC%d:PAR:DEL \'%s\'\n", channel, c_string.constData());
    bus->write(QString(buffer));
}
void Vna::DeleteTraces(QStringList traces) {
    if (traces.size() == 0)
        return;

    foreach(const QString trace, traces) {
        DeleteTrace(trace);
    }
}
void Vna::DeleteTraces() {
    QStringList traces = GetTraces();
    if (traces.size() == 0)
        return;

    DeleteTraces(GetTraces());
}

void Vna::DeleteDiagram(uint diagram) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:STAT 0\n", diagram);
    bus->write(QString(buffer));
}
void Vna::DeleteDiagrams(QVector<uint> diagrams) {
    if (diagrams.size() == 0)
        return;

    foreach(const uint diagram, diagrams) {
        DeleteDiagram(diagram);
    }
}
void Vna::DeleteDiagrams() {
    QVector<uint> diagrams = GetDiagrams();
    if (diagrams.size() == 0)
        return;

    qSort(diagrams.begin(), diagrams.end(), qGreater<uint>());
    uint temp_diagram = CreateDiagram();
    DeleteDiagrams(diagrams);
    CreateDiagram(1);
    DeleteDiagram(temp_diagram);
}

// VNA:Open
void Vna::ImportCalKit(QString filename) {
    QFileInfo file_info(filename);
    if (file_info.path().isEmpty())
        filename = ".\\Calibration\\kit\\"; // + file_info.baseName() + ".calkit";
    else
        filename = file_info.path();
    filename += file_info.baseName() + ".calkit";

    QString scpi = ":MMEM:LOAD:CKIT \'" + filename + "\'\n";
    Write(scpi);
}
void Vna::OpenSet(QString filename) {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    QFileInfo file_info(filename);
    if (file_info.path() == QString(".")) {
        filename = default_directory.path()
                + "/RecallSets/"
                + filename;
        file_info.setFile(filename);
    }
    if (file_info.suffix() != ToSetFileExtension(model).remove('.'))
        filename = filename + ToSetFileExtension(model);
    QByteArray c_string = QDir::toNativeSeparators(filename).toUtf8();
    sprintf(buffer, ":MMEM:LOAD:STAT 1,\'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}

// VNA:Save
void Vna::SaveSet(QString filename) {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    // Fix save directory issue with firmware
    QFileInfo file_info(filename);
    if (file_info.path() == QString(".")) {
        filename = default_directory.path()
                + "/RecallSets/"
                + filename;
        file_info.setFile(filename);
    }
    if (file_info.suffix() != ToSetFileExtension(model).remove('.'))
        filename = filename + ToSetFileExtension(model);
    QByteArray c_string = QDir::toNativeSeparators(filename).toUtf8();
    sprintf(buffer, ":MMEM:STOR:STAT 1,\'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}

// VNA:Close
void Vna::CloseSet(QString set_name) {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = set_name.toUtf8();
    sprintf(buffer, ":MEM:DEL \'%s\'\n", c_string.constData());
    bus->write(QString(buffer));
}
void Vna::CloseSets() {
    bus->write(":MEM:DEL:ALL\n");
}


// VNA:Private:General
void Vna::Reset() {
    bus.reset(new RsibBus());
    model = UNKNOWN_MODEL;
    serial_no = "";
    firmware_version = "";
    ports = 0;
    minimum_frequency_Hz = 0;
    maximum_frequency_Hz = 0;
    options = QStringList();
    default_directory.setPath("");
}
void Vna::Reset(ConnectionType connection_type, QString instrument_address, uint timeout_ms) {
    if (connection_type == NO_CONNECTION) {
        bus.reset(new RsibBus());
    }
    else if (connection_type == TCPIP_CONNECTION) {
        bus.reset(new RsibBus(connection_type, instrument_address, timeout_ms));
    }
    else {
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
            default_directory.setPath(GetDefaultDirectory());
        }
        else
            model = UNKNOWN_MODEL;
    }
    else { // bus is not open
        Reset();
    }
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
    if (id_part_2.contains("ZNP", Qt::CaseInsensitive))
        return(ZNP_MODEL);
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
    QString info_text;
    QTextStream stream(&info_text);
    stream << "VNA INSTRUMENT INFO" << endl;
    if (isConnected()) {
        if (model != UNKNOWN_MODEL) {
            stream << "Connection:       " << ToString(bus->connectionType()) << endl;
            stream << "Address:          " << bus->address() << endl;
            stream << "Make:             Rohde & Schwarz" << endl;
            stream << "Model:            " << ToString(model) << endl;
            stream << "Serial No:        " << serial_no << endl;
            stream << "Firmware Version: " << firmware_version << endl;
            stream << "Min Frequency:    " << FormatValue(minimum_frequency_Hz, 1, HERTZ_UNITS) << endl;
            stream << "Max Frequency:    " << FormatValue(maximum_frequency_Hz, 1, HERTZ_UNITS) << endl;
            stream << "Number of Ports:  " << ports << endl;
            if (options.size() > 0) {
                stream << "Options:          ";
                stream << ToString(options, "\n                  ");
                stream << endl;
            }
        }
        else if (bus->connectionType() != NO_CONNECTION) {
            stream << "Make: Unknown" << endl;
            stream << "*IDN?\n  " << id_string << endl << endl << endl;
        }
    }
    else {
        QString info_text;
        QTextStream stream(&info_text);
        stream << "Instrument not found" << endl;
        stream << "Connection:       " << ToString(bus->connectionType()) << endl;
        stream << "Address:          " << bus->address() << endl << endl << endl;
    }
    stream << endl << endl;
    stream.flush();
    emit Print(info_text);
}


// VNA:Private:Readback
//     format: "\'Int1,Name_1,Int2,Name_2,...\'"
void Vna::ParseIndicesFromRead(QString readback, QVector<uint> &indices) {
    // Assumes readback format: '1,Name_1,2,Name_2,...'
    indices.clear();
    readback.remove('\'');
    QStringList words = readback.split(',', QString::SkipEmptyParts);
    for (int i = 0; i < words.length(); i += 2) {
        indices.append(words[i].toUInt());
    }
}
void Vna::ParseNamesFromRead(QString readback, QStringList &names) {
    // Assumes readback format: '1,Name_1,2,Name_2...'
    names.clear();
    readback.remove('\'');
    names = readback.split(',', QString::SkipEmptyParts);
    if (names.length() % 2 == 1)
        return;
    for (int i = names.length() - 2; i >= 0; i -= 2) {
        names.removeAt(i);
    }
}

//     format: "Value,Qualifier_String"
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

// VNA:Private:Directory Readback
void Vna::ParseDir(QString readback,
                   int &size_of_files_B,
                   int &free_space_B,
                   QStringList &files,
                   QVector<int> &file_sizes_B,
                   QStringList &directories) {
    QStringList list = readback.split(",");
    if (list.size() < 2)
        return;

    files.clear();
    file_sizes_B.clear();
    directories.clear();

    size_of_files_B = list.takeFirst().toInt();
    free_space_B = list.takeFirst().toInt();
    int list_size = list.size();

    bool isError = false;

    for (int i = 0; i+2 < list_size; i += 3) {
        if (list[i+1].contains("<Dir>", Qt::CaseInsensitive)) {
            directories << list[i].trimmed();
        }
        else if (list[i+1] == " ") {
            files << list[i].trimmed();
            file_sizes_B << list[i+2].trimmed().toInt();
        }
        else {
            // possible mis-read;
            isError = true;
        }
    }

    if (isError) {
        emit Print(QString()
                   + "This MMEM:DIR? call may have failed because one of the files\n"
                   + "in the directory contains a \',\' in the file name. This is a\n"
                   + "limitation of the SCPI command, which happens to use comma separators.\n\n");
    }
}

//**********************
//** CHANNEL ***********
//*********************/

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
    vna->bus->write(":INIT:SCOP SING\n");
    vna->bus->write(QString(buffer));
}

// CHANNEL:Status
bool Vna::_Channel::isEnabled() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d:MEAS?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Channel::isSweepDisabled() {
    return(!isEnabled());
}

bool Vna::_Channel::isCalibrationEnabled() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:CORR?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1" && isCalibrationPresent());
}
bool Vna::_Channel::isCalibrationDisabled() {
    return(!isCalibrationEnabled());
}
bool Vna::_Channel::isCalibrationPresent() {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:CORR:DATA:PAR:COUN?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toInt() > 0);
}
bool Vna::_Channel::isReceiverPowerCalEnabled_aWave(uint port) {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:CORR:POW%d:AWAV?\n", channel, port);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Channel::isReceiverPowerCalEnabled_aWave() {
    uint ports = vna->GetPorts();
    for (uint i = 1; i <= ports; i++) {
        if (isReceiverPowerCalEnabled_aWave(i))
            return(true);
    }
    // else
    return(false);
}
bool Vna::_Channel::isReceiverPowerCalDisabled_aWave(uint port) {
    return(!isReceiverPowerCalEnabled_aWave(port));
}
bool Vna::_Channel::isReceiverPowerCalDisabled_aWave() {
    return(!isReceiverPowerCalEnabled_aWave());
}
bool Vna::_Channel::isReceiverPowerCalEnabled_bWave(uint port) {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:CORR:POW%d?\n", channel, port);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Channel::isReceiverPowerCalEnabled_bWave() {
    uint ports = vna->GetPorts();
    for (uint i = 1; i <= ports; i++) {
        if (isReceiverPowerCalEnabled_bWave(i))
            return(true);
    }
    // else
    return(false);
}
bool Vna::_Channel::isReceiverPowerCalDisabled_bWave(uint port) {
    return(!isReceiverPowerCalEnabled_bWave(port));
}
bool Vna::_Channel::isReceiverPowerCalDisabled_bWave() {
    return(!isReceiverPowerCalEnabled_bWave());
}
bool Vna::_Channel::isSourcePowerCalEnabled(uint port) {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW%d:CORR:STAT?\n", channel, port);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Channel::isSourcePowerCalEnabled() {
    uint ports = vna->GetPorts();
    for (uint i = 1; i <= ports; i++) {
        if (isSourcePowerCalEnabled(i))
            return(true);
    }
    // else
    return(false);
}
bool Vna::_Channel::isSourcePowerCalDisabled(uint port) {
    return(!isSourcePowerCalEnabled(port));
}
bool Vna::_Channel::isSourcePowerCalDisabled() {
    return(!isSourcePowerCalEnabled());
}
bool Vna::_Channel::isPowerCalEnabled() {
    return(isReceiverPowerCalEnabled_aWave()
           || isReceiverPowerCalEnabled_bWave()
           || isSourcePowerCalEnabled());
}
bool Vna::_Channel::isPowerCalDisabled() {
    return(!isPowerCalEnabled());
}
bool Vna::_Channel::isPowerCalPresent() {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW:CORR:DATA:PAR:COUN?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toInt() > 0);
}
bool Vna::_Channel::isUserDefinedSParameterEnabled(uint port) {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:UDSP%d:ACT?\n", channel, port);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Channel::isUserDefinedSParameterDisabled(uint port) {
    return(!isUserDefinedSParameterEnabled(port));
}
bool Vna::_Channel::isContinuousSweepEnabled() {
    const uint BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":INIT%d:CONT?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Channel::isSingleSweepEnabled() {
    return(!isContinuousSweepEnabled());
}
bool Vna::_Channel::isCompressionCalculated() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:STAT:NLIN:COMP?", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Channel::isLinearFrequencySweep() {
    return(GetSweepType() == LINEAR_FREQUENCY_SWEEP);
}
bool Vna::_Channel::isLogFrequencySweep() {
    return(GetSweepType() == LOG_FREQUENCY_SWEEP);
}
bool Vna::_Channel::isSegmentedSweep() {
    return(GetSweepType() == SEGMENTED_SWEEP);
}
bool Vna::_Channel::isPowerSweep() {
    return(GetSweepType() == POWER_SWEEP);
}
bool Vna::_Channel::isCwMode() {
    return(GetSweepType() == CW_MODE_SWEEP);
}
bool Vna::_Channel::isTimeSweep() {
    return(GetSweepType() == TIME_SWEEP);
}
bool Vna::_Channel::isSingleEndedPort(uint logical_port) {
    return(GetPhysicalPorts(logical_port).size() == 1);
}
bool Vna::_Channel::isBalancedPort(uint logical_port) {
    return(GetPhysicalPorts(logical_port).size() == 2);
}

// CHANNEL:Get
QString Vna::_Channel::GetName() {
    const uint BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d:NAME?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).remove('\''));
}
double Vna::_Channel::GetSourceAttenuation_dB(uint port) {
    if (vna->model != ZVA_MODEL)
        return(0);
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW%d:ATT?\n", channel, port);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
QVector<double> Vna::_Channel::GetSourceAttenuations_dB() {
    QVector<double> attenuations;
    for (uint i = 1; i <= vna->ports; i++)
        attenuations << GetSourceAttenuation_dB(i);
    return(attenuations);
}
double Vna::_Channel::GetReceiverAttenuation_dB(uint port) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:POW:ATT? %d\n", channel, port);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
QVector<double> Vna::_Channel::GetReceiverAttenuations_dB() {
    QVector<double> attenuations;
    for (uint i = 1; i <= vna->ports; i++)
        attenuations << GetReceiverAttenuation_dB(i);
    return(attenuations);
}
void Vna::_Channel::GetUserDefinedPort(uint physical_port,
                                       uint &source_port,
                                       QChar &numerator_wave, uint &numerator_port,
                                       QChar &denominator_wave, uint &denominator_port) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:UDSP%d:PAR?\n", channel, physical_port);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    QStringList parameters = QString(buffer).remove('\'').split(":");
    source_port = parameters[0].toUInt();
    numerator_wave = parameters[1].at(0);
    numerator_port = parameters[1].remove(0, 1).toUInt();
    denominator_wave = parameters[2].at(0);
    denominator_port = parameters[2].remove(0, 1).toUInt();
}
QString Vna::_Channel::GetCalGroup() {
    const uint BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":MMEM:LOAD:CORR? %d\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    QString cal_file = QString(buffer).remove('\'');
    return(cal_file);
}
CorrectionState Vna::_Channel::GetCorrectionState() {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:CORR:SST?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    // Remove quotes
    QString state_scpi = QString(buffer).remove('\'');
    return(Scpi_To_CorrectionState(state_scpi));
}
SweepType Vna::_Channel::GetSweepType() {
    const uint BUFFER_SIZE = 25;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:TYPE?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(Scpi_To_SweepType(QString(buffer)));
}
void Vna::_Channel::GetStimulusValues(RowVector &stimulus_data) {
    uint points = GetPoints();
    uint buffer_size = StimulusBufferSize(points);
    QScopedPointer<char> buffer(new char[buffer_size]);
    sprintf(buffer.data(), ":CALC%d:DATA:STIM?\n", channel);
    vna->bus->query(QString(buffer.data()), buffer.data(), buffer_size);
    ParseStimulus(stimulus_data, buffer.data());
}
void Vna::_Channel::GetStimulusValues(QRowVector &stimulus_data) {
    RowVector std_stimulus_data;
    GetStimulusValues(std_stimulus_data);
    stimulus_data = QRowVector::fromStdVector(std_stimulus_data);
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
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    QStringList traces;
    Vna::ParseNamesFromRead(buffer, traces);
    return(traces);
}
QString Vna::_Channel::GetSelectedTrace() {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:SEL?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    QString selected_trace = QString(buffer);
    selected_trace.remove('\'');
    return(selected_trace);
}
double Vna::_Channel::GetDelay_s(uint port) {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:CORR:EDEL%d:TIME?\n", channel, port);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
QVector<double> Vna::_Channel::GetDelays_s() {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    QVector<double> delays;
    for (uint port = 1; port <= vna->ports; port++) {
        sprintf(buffer, "SENS%d:CORR:EDEL%d:TIME?\n", channel, port);
        vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
        delays.append(QString(buffer).toDouble());
    }
    return(delays);
}
double Vna::_Channel::GetChannelPower_dBm() {
    const uint BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
void Vna::_Channel::GetPortPower_dBm(uint port, ReferenceLevel &power_reference, double &power) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW%d:OFFS?\n", channel, port);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    QString reference_string;
    Vna::ParseValueFromRead(QString(buffer), power, reference_string);
    power_reference = Scpi_To_ReferenceLevel(reference_string);
}
double Vna::_Channel::GetStartFrequency_Hz() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:FREQ:STAR?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Channel::GetStopFrequency_Hz() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:FREQ:STOP?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Channel::GetFrequencyStepSize_Hz() {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:STEP?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}

double Vna::_Channel::GetCwFrequency_Hz() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:FREQ?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Channel::GetStartPower_dBm() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "SOUR%d:POW:STAR?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Channel::GetStopPower_dBm() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "SOUR%d:POW:STOP?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Channel::GetIfBandwidth() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:BAND?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
uint Vna::_Channel::GetPoints() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:POIN?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}
QVector<uint> Vna::_Channel::GetSweepSegments() {
    QVector<uint> segments;
    uint number_of_segments = GetNumberOfSweepSegments();
    if (number_of_segments == 0)
        return(segments);
    //else
    segments.resize((int)number_of_segments);
    for (int i = 0; i < (int)number_of_segments; i++)
        segments[i] = i+1;
    return(segments);
}
uint Vna::_Channel::GetNumberOfSweepSegments() {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SEGM:COUN?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}

double Vna::_Channel::GetCompressionLevel_dBm() {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:STAT:NLIN:COMP:LEV?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
void Vna::_Channel::GetCompressionPoints(double &input_dBm, double &output_dBm) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:STAT:NLIN:COMP:RES?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    QStringList result = QString(buffer).split(",");
    if (result.size() == 2) {
        input_dBm = result[0].toDouble();
        output_dBm = result[1].toDouble();
    }
}
QVector<uint> Vna::_Channel::GetSParameterGroupPorts() {
    const uint BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:DEF:SGR?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    QStringList result = QString(buffer).split(',');
    const int number_of_ports = result.size();
    QVector<uint> ports;
    for (int i = 0; i < number_of_ports; i++) {
        ports << result[i].toUInt();
    }
    return(ports);
}
void Vna::_Channel::GetSParameterGroupData(NetworkData &network) {
    // (Temporary?) Sanity check
    SweepType sweep_type = GetSweepType();
    if (sweep_type == POWER_SWEEP || sweep_type == CW_MODE_SWEEP || sweep_type == TIME_SWEEP)
        return;

    // info
    QVector<uint> ports = GetSParameterGroupPorts();
    network.date_time = QDateTime::currentDateTime();
    network.ports = ports.size();
    network.points = GetPoints();
    uint buffer_size = NetworkBufferSize(network.points, network.ports);

    // Query
    QScopedArrayPointer<char> buffer(new char[buffer_size]);
    sprintf(buffer.data(), ":CALC%d:DATA:SGR? MDAT\n", channel);
    vna->bus->query(QString(buffer.data()), buffer.data(), buffer_size);

    // Parse
    ParseNetworkData(network, buffer.data());
    network.stimulus_prefix = NO_PREFIX;
    GetStimulusValues(network.stimulus);
}
QVector<uint> Vna::_Channel::GetPhysicalPorts(uint logical_port) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:LPOR%d?\n", channel, logical_port);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    QStringList results = QString(buffer).split(',', QString::SkipEmptyParts);

    QVector<uint> physical_ports;
    foreach (const QString result, results) {
        physical_ports.append(result.toUInt());
    }

    return(physical_ports);
}

// CHANNEL:Set
void Vna::_Channel::SetName(QString name) {
    QByteArray c_name = name.toUtf8();

    const uint BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:CHAN%d:NAME \'%s\'\n", channel, c_name.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetCalGroup(QString cal_file) {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    if (!cal_file.contains(".cal", Qt::CaseInsensitive))
        cal_file = cal_file + QString(".cal");
    QByteArray c_string = cal_file.toUtf8();
    sprintf(buffer, ":MMEM:LOAD:CORR %d,\'%s\'\n", channel, c_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetSourceAttenuation(uint port, double attenuation_dB) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW%d:ATT %f\n", channel, port, attenuation_dB);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetSourceAttenuations(double attenuation_dB) {
    for (uint i = 1; i <= vna->ports; i++)
        SetSourceAttenuation(i, attenuation_dB);
}
void Vna::_Channel::SetSourceAttenuations(QVector<double> attenuations_dB) {
    if (attenuations_dB.size() != vna->ports)
        return;
    for (uint i = 1; i <= vna->ports; i++)
        SetSourceAttenuation(i, attenuations_dB[i-1]);
}
void Vna::_Channel::SetReceiverAttenuation(uint port, double attenuation_dB) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:POW:ATT %d, %f\n", channel, port, attenuation_dB);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetReceiverAttenuations(double attenuation_dB) {
    for (uint i = 1; i <= vna->ports; i++)
        SetReceiverAttenuation(i, attenuation_dB);
}
void Vna::_Channel::SetReceiverAttenuations(QVector<double> attenuations_dB) {
    if (attenuations_dB.size() != vna->ports)
        return;
    for (uint i = 1; i <= vna->ports; i++)
        SetReceiverAttenuation(i, attenuations_dB[i-1]);
}
void Vna::_Channel::SetUserDefinedSParameter(uint physical_port,
                                             uint source_port,
                                             QChar numerator_wave, uint numerator_port,
                                             QChar denominator_wave, uint denominator_port) {
    const uint BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    QString parameters = QVariant(source_port).toString() + ":"
            + denominator_wave + QVariant(denominator_port).toString() + ":"
            + numerator_wave + QVariant(numerator_port).toString();
    QByteArray c_string = parameters.toUtf8();
    sprintf(buffer, ":SENS%d:UDSP%d:PAR \'%s\'\n", channel, physical_port, c_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetSweepType(SweepType sweep_type) {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:TYPE %s\n", channel, ToScpi(sweep_type));
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetDelay(uint port, double delay_s, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = (ToString(prefix) + ToString(SECONDS_UNITS)).toUtf8();
    sprintf(buffer, ":SENS%d:CORR:EDEL%d:TIME %f%s\n", channel, port, delay_s, c_string.constData());
    vna->bus->write(QString(buffer));
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
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetPortPower(uint port, double power_dBm, ReferenceLevel power_reference) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString power_scpi = ValueQualifier_to_Scpi(power_dBm, ToScpi(power_reference));
    QByteArray c_string = power_scpi.toUtf8();
    sprintf(buffer, ":SOUR%d:POW%d:OFFS %s\n", channel, port, c_string.constData());
    vna->bus->write(QString(buffer));
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
void Vna::_Channel::SetStartFrequency(double start_frequency, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toUtf8();
    sprintf(buffer, ":SENS%d:FREQ:STAR %f%s\n", channel, start_frequency, c_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetStopFrequency(double stop_frequency, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toUtf8();
    sprintf(buffer, ":SENS%d:FREQ:STOP %f%s\n", channel, stop_frequency, c_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetFrequencyStepSize(double step_size, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toUtf8();
    sprintf(buffer, ":SENS%d:SWE:STEP %f%s\n", channel, step_size, c_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetCwFrequency(double cw_frequency, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toUtf8();
    sprintf(buffer, ":SOUR%d:FREQ %f%s\n", channel, cw_frequency, c_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetCustomFrequencySweep(QRowVector frequencies, SiPrefix prefix) {
    DeleteSweepSegments();
    int number_of_freq = frequencies.size();
    for (int i = 0; i < number_of_freq; i++) {
        uint segment = CreateSweepSegment();
        SweepSegment(segment).SetPoints(1);
        SweepSegment(segment).SetStopFrequency(frequencies[i], prefix);
    }
    SetSweepType(SEGMENTED_SWEEP);
}
void Vna::_Channel::SetStartPower(double power_dBm) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW:STAR %f\n", channel, power_dBm);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetStopPower(double power_dBm) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:POW:STOP %f\n", channel, power_dBm);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetIfBandwidth(double if_bandwidth_Hz, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QString units_string = ToString(prefix) + ToString(HERTZ_UNITS);
    QByteArray c_string = units_string.toUtf8();
    sprintf(buffer, "SENS%d:BAND %f%s\n", channel, if_bandwidth_Hz, c_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetPoints(uint points) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SWE:POIN %d\n", channel, points);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetCompressionLevel(double level_dB) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:STAT:NLIN:COMP:LEV %f\n", channel, level_dB);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::SetSidebandAboveLO() {
    QString scpi;
    scpi += ":SENS" + QVariant(channel).toString();
    scpi += ":FREQ:SBAN POS\n";
    vna->Write(scpi);
}
void Vna::_Channel::SetSidebandBelowLO() {
    QString scpi;
    scpi += ":SENS" + QVariant(channel).toString();
    scpi += ":FREQ:SBAN NEG\n";
    vna->Write(scpi);
}
void Vna::_Channel::SetSidebandToAuto() {
    QString scpi;
    scpi += ":SENS" + QVariant(channel).toString();
    scpi += ":FREQ:SBAN AUTO\n";
    vna->Write(scpi);
}


// CHANNEL:Enable
void Vna::_Channel::EnableCorrection(bool isEnabled) {
    const uint BUFFER_SIZE = 25;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":SENS%d:CORR 1\n", channel);
    else
        sprintf(buffer, ":SENS%d:CORR 0\n", channel);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::EnableUserDefinedSParameter(uint port, bool isEnabled) {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":SENS%d:UDSP%d:ACT 1\n", channel, port);
    else
        sprintf(buffer, ":SENS%d:UDSP%d:ACT 0\n", channel, port);
    vna->bus->write(QString(buffer));
}

void Vna::_Channel::EnableSweep(bool isEnabled) {
    const uint BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":CONF:CHAN%d:MEAS 1\n", channel);
    else
        sprintf(buffer, ":CONF:CHAN%d:MEAS 0\n", channel);

    vna->bus->write(QString(buffer));
}
void Vna::_Channel::EnableContinuousSweep(bool isEnabled) {
    const uint BUFFER_SIZE = 20;
    char buffer[BUFFER_SIZE];
    if (isEnabled) {
        sprintf(buffer, ":INIT%d:CONT 1\n", channel);
        vna->bus->write(QString(buffer));
    }
    else {
        sprintf(buffer, ":INIT%d:CONT 0\n", channel);
        vna->bus->write(QString(buffer));
    }
}
void Vna::_Channel::EnableCompressionCalc(bool isEnabled) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":CALC%d:STAT:NLIN:COMP 1", channel);
    else
        sprintf(buffer, ":CALC%d:STAT:NLIN:COMP 0", channel);
    vna->bus->write(QString(buffer));
}

// CHANNEL:Disable
void Vna::_Channel::DisableCorrection(bool isDisabled) {
    EnableCorrection(!isDisabled);
}
void Vna::_Channel::DisableCalGroup() {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":MMEM:LOAD:CORR:RES %d\n", channel);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::DisableUserDefinedSParameter(uint port, bool isDisabled) {
    EnableUserDefinedSParameter(port, !isDisabled);
}

void Vna::_Channel::DisableSweep(bool isDisabled) {
    EnableSweep(!isDisabled);
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
void Vna::_Channel::DisableCompressionCalc(bool isDisabled) {
    EnableCompressionCalc(!isDisabled);
}

// CHANNEL:Create
void Vna::_Channel::CreateSParameterGroup(QVector<uint> ports) {
    uint number_of_ports = ports.size();
    if (number_of_ports <= 0)
        return;

    qSort(ports);
    const uint BUFFER_SIZE = 400;
    char buffer[BUFFER_SIZE];
    QString ports_list = QVariant(ports[0]).toString();
    for (uint i = 1; i < number_of_ports; i++) {
        ports_list = ports_list + "," + QVariant(ports[i]).toString();
    }
    QByteArray c_ports_list = ports_list.toUtf8();
    sprintf(buffer, ":CALC%d:PAR:DEF:SGR %s\n", channel, c_ports_list.constData());
    vna->bus->write(QString(buffer));
}
uint Vna::_Channel::CreateSweepSegment() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    uint next_segment = GetNumberOfSweepSegments() + 1;
    sprintf(buffer, ":SENS%d:SEGM%d:ADD\n", channel, next_segment);
    vna->bus->write(QString(buffer));
    return(next_segment);
}
void Vna::_Channel::CreateLogicalPort(uint logical_port, uint physical_port) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:LPOR%d %d\n", channel, logical_port, physical_port);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::CreateLogicalPort(PortDefinition &port) {
    if (port.isBalanced())
        CreateBalancedLogicalPort(port.logicalPort(), port.physicalPort1(), port.physicalPort2());
    else
        CreateLogicalPort(port.logicalPort(), port.physicalPort1());
}

void Vna::_Channel::CreateBalancedLogicalPort(uint logical_port, uint port1, uint port2) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:LPOR%d %d, %d\n", channel, logical_port, port1, port2);
    vna->bus->write(QString(buffer));
}

// CHANNEL:Delete
void Vna::_Channel::DeleteCorrectionData() {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:CORR:COLL:DEL ALL\n", channel);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::DeleteSParameterGroup() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:DEL:SGR\n", channel);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::DeleteSweepSegment(uint segment) {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SEGM%d:DEL\n", channel, segment);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::DeleteSweepSegments() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SEGM:DEL:ALL\n", channel);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::DeleteLogicalPort(uint logical_port) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:LPOR%d:CLE\n", channel, logical_port);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::DeleteLogicalPorts() {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SOUR%d:LPOR:CLE ALL\n", channel);
    vna->bus->write(QString(buffer));
}

// CHANNEL:Math
void Vna::_Channel::SetMathExpression(QString expression) {
    QString scpi;
    scpi += ":CALC" + QVariant(channel).toString() + ":";
    scpi += "MATH:SDEF ";
    scpi += "\'" + expression.remove('\'') + "\'\n";
    vna->Write(scpi);
}
void Vna::_Channel::EnableMathExpressions(bool isEnabled) {
    QString scpi;
    scpi += ":CALC" + QVariant(channel).toString();
    scpi += ":MATH:STAT ";
    if (isEnabled)
        scpi += "1\n";
    else
        scpi += "0\n";
    vna->Write(scpi);
}
void Vna::_Channel::DisableMathExpressions(bool isDisabled) {
    EnableMathExpressions(!isDisabled);
}

void Vna::_Channel::EnableMathUnits(bool isEnabled) {
    QString scpi;
    scpi += ":CALC" + QVariant(channel).toString();
    scpi += ":MATH:WUN:STAT ";
    if (isEnabled)
        scpi += "1\n";
    else
        scpi += "0\n";
    vna->Write(scpi);
}
void Vna::_Channel::DisableMathUnits(bool isDisabled) {
    EnableMathUnits(!isDisabled);
}


// CHANNEL:Calibrate
Vna::_Calibration& Vna::_Channel::Calibration() {
    vna->_calibration = _Calibration(vna, channel);
    return(vna->_calibration);
}

// CHANNEL:Measure
void Vna::_Channel::MeasureNetwork(NetworkData &network, QVector<uint> ports) {
    // (Temporary?) Sanity check
    SweepType sweep_type = GetSweepType();
    if (sweep_type == CW_MODE_SWEEP || sweep_type == TIME_SWEEP)
        return;

    // info, buffer
    network.sweep_type = sweep_type;
    CreateSParameterGroup(ports);
    network.date_time = QDateTime::currentDateTime();
    network.ports = ports.size();
    network.points = GetPoints();
    uint buffer_size = NetworkBufferSize(network.points, network.ports);
    QScopedArrayPointer<char> buffer(new char[buffer_size]);
    // Should this be SDAT (MDAT includes trace mathematics...)
    sprintf(buffer.data(), ":CALC%d:DATA:SGR? MDAT\n", channel);

    // Measure
    if (isContinuousSweepEnabled()) {
        DisableContinuousSweep();
        InitiateSweep();
        vna->WaitForSweeps();
        vna->bus->query(QString(buffer.data()), buffer.data(), buffer_size);
        EnableContinuousSweep();
    }
    else {
        InitiateSweep();
        vna->WaitForSweeps();
        vna->bus->query(QString(buffer.data()), buffer.data(), buffer_size);
    }

    // Parse
    ParseNetworkData(network, buffer.data());
    network.stimulus_prefix = NO_PREFIX;
    GetStimulusValues(network.stimulus);

    // Clean up
    // DeleteSParameterGroup();
}

// CHANNEL:Save
void Vna::_Channel::SaveCalGroup(QString cal_file) {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    if (cal_file.contains(".cal", Qt::CaseInsensitive) == false)
        cal_file = cal_file + ".cal";
    QByteArray c_string = cal_file.toUtf8();
    sprintf(buffer, ":MMEM:STOR:CORR %d,\'%s\'\n", channel, c_string.constData());
    vna->bus->write(QString(buffer));
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
    const uint SIZE_PER_POINT = 20;
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
        network[freq].resize(network.ports);
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

// channel:SWEEP_SEGMENT
Vna::_Channel::_SweepSegment& Vna::_Channel::SweepSegment(uint segment) {
    sweep_segment = _SweepSegment(vna, this, segment);
    return(sweep_segment);
}

Vna::_Channel::_SweepSegment::_SweepSegment(Vna *vna, _Channel *channel, uint segment) {
    this->vna = vna;
    this->channel = channel;
    this->segment = segment;
}

// channel:SWEEP_SEGMENT:Status
bool Vna::_Channel::_SweepSegment::isPoint() {
    return(GetPoints() == 1 &&
           GetStartFrequency_Hz() == GetStopFrequency_Hz());
}
bool Vna::_Channel::_SweepSegment::isEnabled() {
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SEGM%d?\n", channel->channel, segment);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toInt() == 1);
}
bool Vna::_Channel::_SweepSegment::isDisabled() {
    return(!isEnabled());
}

// channel:SWEEP_SEGMENT:Get
uint Vna::_Channel::_SweepSegment::GetPoints() {
    const uint BUFFER_SIZE = 35;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SEGM%d:SWE:POIN?\n", channel->channel, segment);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}
double Vna::_Channel::_SweepSegment::GetStartFrequency_Hz() {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SEGM%d:FREQ:STAR?\n", channel->channel, segment);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Channel::_SweepSegment::GetStopFrequency_Hz() {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SEGM%d:FREQ:STOP?\n", channel->channel, segment);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}

// channel:SWEEP_SEGMENT:Set
void Vna::_Channel::_SweepSegment::SetPoints(uint points) {
    const uint BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SENS%d:SEGM%d:SWE:POIN %d\n", channel->channel, segment, points);
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::_SweepSegment::SetStartFrequency(double frequency, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QByteArray units = ToString(prefix).toUtf8() + "HZ";
    sprintf(buffer, ":SENS%d:SEGM%d:FREQ:STAR %f%s\n", channel->channel, segment, frequency, units.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Channel::_SweepSegment::SetStopFrequency(double frequency, SiPrefix prefix) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QByteArray units = ToString(prefix).toUtf8() + "HZ";
    sprintf(buffer, ":SENS%d:SEGM%d:FREQ:STOP %f%s\n", channel->channel, segment, frequency, units.constData());
    vna->bus->write(QString(buffer));
}

// channel:SWEEP_SEGMENT:Enable
void Vna::_Channel::_SweepSegment::Enable(bool isEnabled) {
    const uint BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    if (isEnabled == true)
        sprintf(buffer, ":SENS%d:SEGM%d 1\n", channel->channel, segment);
    else
        sprintf(buffer, ":SENS%d:SEGM%d 0\n", channel->channel, segment);
    vna->bus->write(QString(buffer));
}

// channel:SWEEP_SEGMENT:Disable
void Vna::_Channel::_SweepSegment::Disable(bool isDisabled) {
    Enable(!isDisabled);
}


//**********************
//** TRACE *************
//*********************/

Vna::_Trace& Vna::Trace(QString trace_name) {
    _trace = _Trace(this, trace_name);
    return(_trace);
}

Vna::_Trace::_Trace(Vna *vna, QString trace_name) {
    this->vna = vna;
    this->trace_name = trace_name;
}

// TRACE:Actions
void Vna::_Trace::Select() {
    QByteArray c_string = trace_name.toUtf8();
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    uint channel = GetChannel();
    sprintf(buffer, ":CALC%d:PAR:SEL \'%s\'\n", channel, c_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Trace::Autoscale() {
    QByteArray c_name = trace_name.toUtf8();
    const int BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:TRAC:Y:AUTO ONCE, \'%s\'\n", c_name.constData());
    vna->bus->write(buffer);
}

// TRACE:Status
bool Vna::_Trace::isShown() {
    QByteArray c_string = trace_name.toUtf8();
    const uint BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:TRAC:SHOW? \'%s\'\n", c_string.constData());
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toInt() == 1);
}
bool Vna::_Trace::isHidden() {
    return(!isShown());
}

// TRACE:Get
void Vna::_Trace::GetStimulusValues(RowVector &stimulus_data) {
    uint channel = GetChannel();
    uint points = vna->Channel(channel).GetPoints();
    uint buffer_size = StimulusBufferSize(points);
    QScopedPointer<char> buffer(new char[buffer_size]);
    sprintf(buffer.data(), ":CALC%d:DATA:STIM?\n", channel);
    vna->bus->query(QString(buffer.data()), buffer.data(), buffer_size);
    ParseStimulus(stimulus_data, buffer.data());
}
void Vna::_Trace::GetStimulusValues(QRowVector &stimulus_data) {
    RowVector std_stimulus_data;
    GetStimulusValues(std_stimulus_data);
    stimulus_data = QRowVector::fromStdVector(std_stimulus_data);
}
uint Vna::_Trace::GetChannel() {
    QByteArray c_string = trace_name.toUtf8();
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CONF:TRAC:CHAN:NAME:ID? \'%s\'\n", c_string.constData());
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}
void Vna::_Trace::GetParameters(NetworkParameter &parameter, PortDefinition &output_port, PortDefinition &input_port) {
    QByteArray trace_byte_array = trace_name.toUtf8();
    char * trace_name_c = trace_byte_array.data();
    uint channel = GetChannel();
    const uint BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:MEAS? \'%s\'\n", channel, trace_name_c);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    ParseParameters(QString(buffer), parameter, output_port, input_port);
}
TraceFormat Vna::_Trace::GetFormat() {
    uint channel = GetChannel();
    QString selected_trace = vna->Channel(channel).GetSelectedTrace();
    Select();
    const uint BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:FORM?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    if (trace_name != selected_trace)
        Vna::_Trace(vna, selected_trace).Select();
    return(Scpi_To_TraceFormat(QString(buffer)));
}
uint Vna::_Trace::GetDiagram() {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    QByteArray byte_array = trace_name.toUtf8();
    char *trace_c_string = byte_array.data();
    sprintf(buffer, ":CONF:TRAC:WIND:TRAC? \'%s\'\n", trace_c_string);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toUInt());
}

// TRACE:Set
void Vna::_Trace::SetParameters(NetworkParameter parameter, uint output_port, uint input_port) {
    QByteArray c_name = trace_name.toUtf8();
    QByteArray c_parameters = Parameters_to_Scpi(parameter, output_port, input_port).toUtf8();
    uint channel = GetChannel();
    const uint BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:MEAS \'%s\', \'%s\'\n", channel, c_name.constData(), c_parameters.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Trace::SetParameters(NetworkParameter parameter, PortDefinition &output_port, PortDefinition &input_port) {
    QByteArray c_name = trace_name.toUtf8();
    QByteArray c_parameters = Parameters_to_Scpi(parameter, output_port, input_port).toUtf8();
    uint channel = GetChannel();
    const uint BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:MEAS \'%s\', \'%s\'\n", channel, c_name.constData(), c_parameters.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Trace::SetWaveQuantity(WaveQuantity wave, uint port) {
    QByteArray c_name = trace_name.toUtf8();

    QByteArray c_parameters;
    if (wave == A_WAVE)
        c_parameters = (QString("A") + QVariant(port).toString()).toUtf8();
    else
        c_parameters = (QString("B") + QVariant(port).toString()).toUtf8();

    uint channel = GetChannel();

    const uint BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:MEAS \'%s\', \'%s\'\n", channel, c_name.constData(), c_parameters.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Trace::SetImpedance(uint output_port, uint input_port) {
    QString param = Parameters_to_Scpi(S_PARAMETER, output_port, input_port);
    param = "Z-" + param;
    QByteArray c_param = param.toUtf8();
    QByteArray c_name = trace_name.toUtf8();
    uint channel = GetChannel();

    const int BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:MEAS \'%s\', \'%s\'\n", channel, c_name.constData(), c_param.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Trace::SetImpedance(PortDefinition &output_port, PortDefinition &input_port) {
    QString param = Parameters_to_Scpi(S_PARAMETER, output_port, input_port);
    param = "Z-" + param;
    QByteArray c_param = param.toUtf8();
    QByteArray c_name = trace_name.toUtf8();
    uint channel = GetChannel();

    const int BUFFER_SIZE = 550;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:PAR:MEAS \'%s\', \'%s\'\n", channel, c_name.constData(), c_param.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Trace::SetFormat(TraceFormat format) {
    uint channel = GetChannel();
    QString selected_trace = vna->Channel(channel).GetSelectedTrace();
    Select();
    const uint BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:FORM %s\n", channel, ToScpi(format));
    vna->bus->write(QString(buffer));
    if (trace_name != selected_trace)
        vna->Trace(selected_trace).Select();
}
void Vna::_Trace::SetDiagram(uint diagram) {
    QVector<uint> numbers = vna->Diagram(diagram).GetTraceNumbers();
    uint new_number;
    if (numbers.size() > 0)
        new_number = numbers.last() + 1;
    else
        new_number = 1;

    QByteArray c_name = trace_name.toUtf8();
    const uint BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:TRAC%d:FEED \'%s\'\n", diagram, new_number, c_name.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Trace::SetDisplayProperties(QPen pen) {
    SetDisplayProperties(pen.color(), pen.style(), pen.width());
}
void Vna::_Trace::SetDisplayProperties(QColor color, Qt::PenStyle style, int width) {
    SetDisplayProperties(color.red(), color.green(), color.blue(), style, width);
}
void Vna::_Trace::SetDisplayProperties(int red, int green, int blue, Qt::PenStyle style, int width) {
    char const *c_style;
    switch(style) {
    case (Qt::SolidLine):
        c_style = "SOL";
        break;
    case (Qt::DashLine):
        c_style = "DASH";
        break;
    case (Qt::DotLine):
        c_style = "DOTT";
        break;
    case (Qt::DashDotLine):
        c_style = "DDOT";
        break;
    case (Qt::DashDotDotLine):
        c_style = "DDD";
        break;
    default:
        c_style = "SOL";
        break;
    }

    if (width < 1)
        width = 1;
    else if (width > 20)
        width = 20;

    if (red < 0)
        red = 0;
    else if (red > 255)
        red = 255;

    if (green < 0)
        green = 0;
    else if (green > 255)
        green = 255;

    if (blue < 0)
        blue = 0;
    else if (blue > 255)
        blue = 255;

    const uint BUFFER_SIZE = 200;
    char buffer[BUFFER_SIZE];
    QByteArray c_name = trace_name.toUtf8();

    sprintf(buffer, ":DISP:CMAP:TRAC:RGB \'%s\', %f, %f, %f, %s, %d\n", c_name.constData(), red/255.0, green/255.0, blue/255.0, c_style, width);
    vna->bus->write(buffer);
}
void Vna::_Trace::SetYAxisMinimum(double min) {
    QByteArray c_name = trace_name.toUtf8();

    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:TRAC:Y:BOTT %E, \'%s\'\n", min, c_name.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Trace::SetYAxisMaximum(double max) {
    QByteArray c_name = trace_name.toUtf8();

    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:TRAC:Y:TOP %E, \'%s\'\n", max, c_name.constData());
    vna->bus->write(QString(buffer));
}
//void Vna::_Trace::SetYAxis(double min, double max) {

//}

// TRACE:Show
void Vna::_Trace::Show(bool isShown) {
    QByteArray c_string = trace_name.toUtf8();
    const uint BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    if (isShown)
        sprintf(buffer, ":DISP:TRAC:SHOW \'%s\', 1\n", c_string.constData());
    else
        sprintf(buffer, ":DISP:TRAC:SHOW \'%s\', 0\n", c_string.constData());
    vna->bus->write(QString(buffer));
}

// TRACE:Hide
void Vna::_Trace::Hide(bool isHidden) {
    Show(!isHidden);
}

// TRACE:Copy
void Vna::_Trace::CopyDataTraceToMemory(QString memory_trace_name) {
    QByteArray c_data = trace_name.toUtf8();
    QByteArray c_mem = memory_trace_name.toUtf8();

    const uint BUFFER_SIZE = 300;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":TRAC:COPY \'%s\',\'%s\'\n", c_mem.constData(), c_data.constData());
    vna->bus->write(QString(buffer));
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
    QByteArray c_trace_name = trace_name.toUtf8();

    // Handle analyzer discrepancy
    if (vna->model == ZNB_MODEL || vna->model == ZNC_MODEL) {
        sprintf(buffer.data(), ":CALC:DATA:TRAC? \'%s\', FDAT\n", c_trace_name.constData());
    }
    else {
        // ZVA doesn't have "CALC:DATA:TRAC?" command. Use a different method.
        Select();
        sprintf(buffer.data(), ":CALC%d:DATA? FDAT\n", channel_index);
    }

    // Read data
    if (channel.isContinuousSweepEnabled()) {
        channel.DisableContinuousSweep();
        channel.InitiateSweep();
        vna->WaitForSweeps();
        vna->bus->query(QString(buffer.data()), buffer.data(), buffer_size);
        channel.EnableContinuousSweep();
    }
    else {
        // channel.InitiateSweep();
        // vna->FinishPreviousCommandsFirst();
        vna->bus->query(QString(buffer.data()), buffer.data(), buffer_size);
    }

    // Parse data
    PortDefinition output_port, input_port;
    GetParameters(trace.network_parameter, output_port, input_port);
    trace.output_port = output_port;
    trace.input_port = input_port;
    trace.points = points;
    trace.sweep_type = channel.GetSweepType();
    trace.format = format;
    trace.date_time = QDateTime::currentDateTime();
    GetUnits(trace);
    ParseData(trace, buffer.data());
    GetStimulusValues(trace.stimulus_points);
}

void Vna::_Trace::WriteData(QRowVector &data) {
    uint channel = GetChannel();
    ComplexRowVector complex;
    int size = data.size();
    if (size > 0)
        complex.resize(size);
    for (int i = 0; i < size; i++)
        complex[i] = std::complex<double>(data[i], 0);

    QString command;
    QByteArray c_data = ToString(complex, ",").toUtf8();
    command.sprintf(":CALC%d:DATA SDAT, %s\n", channel, c_data.constData());
    Select();
    vna->Write(command);
}


// Trace:TIME_DOMAIN
Vna::_Trace::_TimeDomain::_TimeDomain(Vna *vna, _Trace *trace) {
    this->vna = vna;
    this->trace = trace;
}
Vna::_Trace::_TimeDomain& Vna::_Trace::TimeDomain() {
    this->_time_domain = _TimeDomain(vna, this);
    return(_time_domain);
}

// Trace:TIME_DOMAIN:Status
bool Vna::_Trace::_TimeDomain::isEnabled() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:STAT?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Trace::_TimeDomain::isDisabled() {
    return(!isEnabled());
}
bool Vna::_Trace::_TimeDomain::isBandPassImpulseResponse() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 40;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).contains("BPAS", Qt::CaseInsensitive));
}
bool Vna::_Trace::_TimeDomain::isLowPassImpulseResponse() {
    if (isBandPassImpulseResponse())
        return(false);

    uint channel = trace->GetChannel();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:STIM?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).contains("IMP", Qt::CaseInsensitive));
}
bool Vna::_Trace::_TimeDomain::isLowPassStepResponse() {
    return(isBandPassImpulseResponse() == false &&
           isLowPassImpulseResponse() == false);
}
bool Vna::_Trace::_TimeDomain::isTimeAxis() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:XAX?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).contains("TIME", Qt::CaseInsensitive));
}
bool Vna::_Trace::_TimeDomain::isDistanceAxis() {
    return(isTimeAxis() == false);
}

// Trace:TIME_DOMAIN:Get
double Vna::_Trace::_TimeDomain::GetExtrapolatedDCValue() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:LPAS:DCSP?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
WindowFunction Vna::_Trace::_TimeDomain::GetWindowFunction() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:WIND?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);


    QString result(buffer);
    if (result.contains("RECT", Qt::CaseInsensitive))
        return(REGULAR_WINDOW_FUNCTION);
    if (result.contains("HAMM", Qt::CaseInsensitive))
        return(HAMMING_WINDOW_FUNCTION);
    if (result.contains("HANN", Qt::CaseInsensitive))
        return(HANN_WINDOW_FUNCTION);
    if (result.contains("BOHM", Qt::CaseInsensitive))
        return(BOHMAN_WINDOW_FUNCTION);
    if (result.contains("DCH", Qt::CaseInsensitive))
        return(DOLPH_CHEBYCHEV_WINDOW_FUNCTION);

    // default
    return(REGULAR_WINDOW_FUNCTION);
}
double Vna::_Trace::_TimeDomain::GetStartValue() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:STAR?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Trace::_TimeDomain::GetStopValue() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:STOP?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}

// Trace:TIME_DOMAIN:Set
void Vna::_Trace::_TimeDomain::SetBandPassImpulseResponse() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME BPAS\n", channel);
    vna->bus->write(buffer);
}
void Vna::_Trace::_TimeDomain::SetLowPassImpulseResponse() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME LPAS\n", channel);
    vna->bus->write(buffer);
    sprintf(buffer, ":CALC%d:TRAN:TIME:STIM IMP\n", channel);
    vna->bus->write(buffer);
}
void Vna::_Trace::_TimeDomain::SetLowPassStepResponse() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME LPAS\n", channel);
    vna->bus->write(buffer);
    sprintf(buffer, ":CALC%d:TRAN:TIME:STIM STEP\n", channel);
    vna->bus->write(buffer);
}
bool Vna::_Trace::_TimeDomain::SetHarmonicGrid_KeepStopFrequencyAndPoints() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:LPAS KFST\n", channel);

    vna->ClearStatus();
    vna->bus->write(buffer);
    if (vna->isError()) {
        vna->ClearErrors();
        return(false);
    }
    else
        return(true);
}
bool Vna::_Trace::_TimeDomain::SetHarmonicGrid_KeepFrequencySpacingAndPoints() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:LPAS KDFR\n", channel);

    vna->ClearErrors();
    vna->bus->write(buffer);
    if (vna->isError()) {
        vna->ClearErrors();
        return(false);
    }
    else
        return(true);
}
bool Vna::_Trace::_TimeDomain::SetHarmonicGrid_KeepStopFrequencyAndSpacing() {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:LPAS KSDF\n", channel);

    vna->ClearErrors();
    vna->bus->write(buffer);
    if (vna->isError()) {
        vna->ClearErrors();
        return(false);
    }
    else
        return(true);
}
void Vna::_Trace::_TimeDomain::SetWindowFunction(WindowFunction window) {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];

    switch(window) {
    case REGULAR_WINDOW_FUNCTION:
        sprintf(buffer, ":CALC%d:TRAN:TIME:WIND RECT\n", channel);
        break;
    case HAMMING_WINDOW_FUNCTION:
        sprintf(buffer, ":CALC%d:TRAN:TIME:WIND HAMM\n", channel);
        break;
    case HANN_WINDOW_FUNCTION:
        sprintf(buffer, ":CALC%d:TRAN:TIME:WIND HANN\n", channel);
        break;
    case BOHMAN_WINDOW_FUNCTION:
        sprintf(buffer, ":CALC%d:TRAN:TIME:WIND BOHM\n", channel);
        break;
    case DOLPH_CHEBYCHEV_WINDOW_FUNCTION:
        sprintf(buffer, ":CALC%d:TRAN:TIME:WIND DCH\n", channel);
        break;
    default:
        // REGULAR_WINDOW_FUNCTION
        sprintf(buffer, ":CALC%d:TRAN:TIME:WIND RECT\n", channel);
        break;
    }

    vna->bus->write(buffer);
}
void Vna::_Trace::_TimeDomain::SetStartValue(double start_value, SiPrefix prefix) {
    uint channel = trace->GetChannel();
    trace->Select();

    start_value = start_value * ToDouble(prefix);

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:STAR %E\n", channel, start_value);
    vna->bus->write(buffer);
}
void Vna::_Trace::_TimeDomain::SetStopValue(double stop_value, SiPrefix prefix) {
    uint channel = trace->GetChannel();
    trace->Select();

    stop_value = stop_value * ToDouble(prefix);

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:TRAN:TIME:STOP %E\n", channel, stop_value);
    vna->bus->write(buffer);
}

// Trace:TIME_DOMAIN:Enable
void Vna::_Trace::_TimeDomain::Enable(bool isEnabled) {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":CALC%d:TRAN:TIME:STAT 1\n", channel);
    else
        sprintf(buffer, ":CALC%d:TRAN:TIME:STAT 0\n", channel);
    vna->bus->write(buffer);
}
void Vna::_Trace::_TimeDomain::EnableContinuousDCExtrapolation(bool isEnabled) {
    uint channel = trace->GetChannel();
    trace->Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":CALC%d:TRAN:TIME:LPAS:DCSP:CONT 1\n", channel);
    else
        sprintf(buffer, ":CALC%d:TRAN:TIME:LPAS:DCSP:CONT 0\n", channel);
    vna->bus->write(buffer);
}

// Trace:TIME_DOMAIN:Diable
void Vna::_Trace::_TimeDomain::Disable(bool isDisabled) {
    Enable(!isDisabled);
}
void Vna::_Trace::_TimeDomain::DisableContinuousDCExtrapolation(bool isDisabled) {
    EnableContinuousDCExtrapolation(!isDisabled);
}


//  Trace:MARKER:Status
bool Vna::_Trace::isMarkerPresent() {
    Select();
    for (int i = 1; i <= 10; i++) {
        if (isMarkerPresent(i))
            return(true);
    }
    //else
    return(false);
}
bool Vna::_Trace::isMarkerPresent(uint index) {
    uint channel = GetChannel();
    Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d?\n", channel, index);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Trace::isReferenceMarkerPresent() {
    uint channel = GetChannel();
    Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK:REF?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}

//  Trace:MARKER:Get
QVector<uint> Vna::_Trace::GetMarkers() {
    QVector<uint> markers;

    for (int i = 1; i <= 10; i++) {
        if (isMarkerPresent(i) == true)
            markers.append(i);
    }
    return(markers);
}

//  Trace:MARKER:Create
void Vna::_Trace::CreateMarker(uint index) {
    if (index <= 0 || index > 10) {
        vna->log->print(QString()
                        + "ERROR: Cannot create marker "
                        + QVariant(index).toString() + "\n"
                        + "Marker indexes must be 1-10\n\n");
        return;
    }

    Select();

    uint channel = GetChannel();
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d 1\n", channel, index);
    vna->bus->write(buffer);
}
uint Vna::_Trace::CreateMarker() {
    QVector<uint> markers = GetMarkers();

    if (markers.isEmpty()) {
        CreateMarker(1);
        return(1);
    }

    uint new_marker = Max(markers) + 1;
    if (new_marker <= 10) {
        CreateMarker(new_marker);
        return(new_marker);
    }
    else {
        vna->log->print(QString()
                        + "ERROR: Could not create new marker.\n"
                        + "Marker indexes 1-10 are all full. Returning last index (10)...\n\n");
        return(10);
    }
}
void Vna::_Trace::CreateReferenceMarker() {
    uint channel = GetChannel();
    Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK:REF 1\n", channel);
    vna->bus->write(QString(buffer));
}

//  Trace:MARKER:Delete
void Vna::_Trace::DeleteMarker(uint index) {
    if (index <= 0 || index > 10) {
        vna->log->print(QString()
                        + "ERROR: Cannot delete marker "
                        + QVariant(index).toString() + "\n"
                        + "Marker indexes must be 1-10\n\n");
        return;
    }

    Select();

    uint channel = GetChannel();
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d 0\n", channel, index);
    vna->bus->write(buffer);
}
void Vna::_Trace::DeleteMarkers(QVector<uint> indexes) {
    foreach (const uint index, indexes)
        DeleteMarker(index);
}
void Vna::_Trace::DeleteMarkers() {
    Select();

    uint channel = GetChannel();
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK:AOFF\n", channel);
    vna->bus->write(buffer);
}
void Vna::_Trace::DeleteReferenceMarker() {
    uint channel = GetChannel();
    Select();

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK:REF 0\n", channel);
    vna->bus->write(QString(buffer));
}

// Trace::MARKER Accessor
Vna::_Trace::_Marker& Vna::_Trace::Marker(uint index) {
    _marker = _Marker(index, vna, this);
    return(_marker);
}

// Trace::MARKER:Constructor
Vna::_Trace::_Marker::_Marker(uint index, Vna *vna, _Trace *trace) {
    this->vna = vna;
    this->trace = trace;
    this->index = index;
    trace->Select();
    this->channel = trace->GetChannel();
}

// Trace:MARKER:Status
bool Vna::_Trace::_Marker::isDeltaEnabled() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:DELT?\n", channel, index);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_Trace::_Marker::isDeltaDisabled() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:DELT?\n", channel, index);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "0");
}

//  Trace:MARKER:Get
QString Vna::_Trace::_Marker::GetName() {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:NAME?\n", channel, index);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).remove('\''));
}
double Vna::_Trace::_Marker::GetYValue() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:Y?\n", channel, index);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Trace::_Marker::GetXValue() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:X?\n", channel, index);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
void Vna::_Trace::_Marker::GetValue(double &x, double &y) {
    x = GetXValue();
    y = GetYValue();
}

//  Trace:MARKER:Set
void Vna::_Trace::_Marker::SetName(QString name) {
    QByteArray c_name = name.toUtf8();

    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:NAME \'%s\'\n", channel, index, c_name.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Trace::_Marker::SetX(double x, SiPrefix prefix) {
    x *= ToDouble(prefix);

    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:X %E\n", channel, index, x);
    vna->bus->write(buffer);
}
void Vna::_Trace::_Marker::SearchForMax() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:FUNC:EXEC MAX\n", channel, index);
    vna->bus->write(buffer);
}
void Vna::_Trace::_Marker::SearchForMin() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:FUNC:EXEC MIN\n", channel, index);
    vna->bus->write(buffer);
}
void Vna::_Trace::_Marker::SearchFor(double y_value) {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:TARG %E;:CALC%d:MARK%d:FUNC:EXEC TARG\n", channel, index, y_value, channel, index);
    vna->bus->write(buffer);
}
void Vna::_Trace::_Marker::SearchRightFor(double y_value) {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:TARG %E;:CALC%d:MARK%d:FUNC:EXEC RTAR\n", channel, index, y_value, channel, index);
    vna->bus->write(buffer);
}
void Vna::_Trace::_Marker::SearchLeftFor(double y_value) {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:TARG %E;:CALC%d:MARK%d:FUNC:EXEC LTAR\n", channel, index, y_value, channel, index);
    vna->bus->write(buffer);
}
void Vna::_Trace::_Marker::SearchRightForPeak() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:FUNC:EXEC RPE\n", channel, index);
    vna->bus->write(buffer);
}
void Vna::_Trace::_Marker::SearchLeftForPeak() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:FUNC:EXEC LPE\n", channel, index);
    vna->bus->write(buffer);
}
void Vna::_Trace::_Marker::SearchForNextPeak() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:FUNC:EXEC NPE\n", channel, index);
    vna->bus->write(buffer);
}

void Vna::_Trace::_Marker::MeasureBandpassFilter() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK%d:FUNC:EXEC BFIL\n", channel, index);
    vna->bus->write(buffer);
}

// Trace:MARKER:Enable
void Vna::_Trace::_Marker::EnableDelta(bool isEnabled) {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":CALC%d:MARK%d:DELT 1\n", channel, index);
    else
        sprintf(buffer, ":CALC%d:MARK%d:DELT 0\n", channel, index);
    vna->bus->write(QString(buffer));
}

// Trace:MARKER:Disable
void Vna::_Trace::_Marker::DisableDelta(bool isDisabled) {
    EnableDelta(!isDisabled);
}

// Trace:REFERENCE_MARKER
Vna::_Trace::_ReferenceMarker::_ReferenceMarker(Vna *vna, _Trace *trace) {
    this->vna = vna;
    this->trace = trace;
    this->channel = trace->GetChannel();
    trace->Select();
}
Vna::_Trace::_ReferenceMarker& Vna::_Trace::ReferenceMarker() {
    _reference_marker = _ReferenceMarker(vna, this);
    return(_reference_marker);
}

// Trace::REFERENCE_MARKER:Get
QString Vna::_Trace::_ReferenceMarker::GetName() {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK:REF:NAME?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).remove('\''));
}
double Vna::_Trace::_ReferenceMarker::GetYValue() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK:REF:Y?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
double Vna::_Trace::_ReferenceMarker::GetXValue() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK:REF:X?\n", channel);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
void Vna::_Trace::_ReferenceMarker::GetValue(double &x, double &y) {
    x = GetXValue();
    y = GetYValue();
}

// Trace::REFERENCE_MARKER:Set
void Vna::_Trace::_ReferenceMarker::SetName(QString name) {
    QByteArray c_name = name.toUtf8();

    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK:REF:NAME \'%s\'\n", channel, c_name.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Trace::_ReferenceMarker::SetX(double x, SiPrefix prefix) {
    x *= ToDouble(prefix);

    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK:REF:X %E\n", channel, x);
    vna->bus->write(QString(buffer));
}
void Vna::_Trace::_ReferenceMarker::SetTo(uint marker_index) {
    double x = trace->Marker(marker_index).GetXValue();

    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":CALC%d:MARK:REF:X %E\n", channel, x);
    vna->bus->write(QString(buffer));
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
PortType Vna::_Trace::Scpi_To_PortType(QChar scpi) {
    switch(scpi.toLatin1()) {
    case 's':
        return(SINGLE_ENDED);
    case 'd':
        return(DIFFERENTIAL_MODE);
    case 'c':
        return(COMMON_MODE);
    default:
        return(SINGLE_ENDED);
    }
}
void Vna::_Trace::ParseParameters(QString readback, NetworkParameter &parameter, PortDefinition &output_port, PortDefinition &input_port) {
    readback.remove('\'');
    parameter = Scpi_To_NetworkParameter(readback.at(0));
    readback.remove(0,1);
    if (readback.at(0).isLetter()) {
        output_port.setPortType(Scpi_To_PortType(readback.at(0)));
        input_port.setPortType(Scpi_To_PortType(readback.at(1)));
        readback.remove(0,2);
    }
    if (readback.length() == 3) {
        // "%c%1d%1d" format
        output_port.setLogicalPort(readback.mid(1,1).toUInt());
        input_port.setLogicalPort(readback.mid(2,1).toUInt());
    }
    else if (readback.length() == 5) {
        // "%c%2d%2d" format
        output_port.setLogicalPort(readback.mid(1,2).toUInt());
        input_port.setLogicalPort(readback.mid(3,2).toUInt());
    }
    else {  //readback.length() is 7?!!
        // "%c%3d%3d" format
        output_port.setLogicalPort(readback.mid(1,3).toUInt());
        input_port.setLogicalPort(readback.mid(4,3).toUInt());
    }
}
QString Vna::_Trace::Parameters_to_Scpi(NetworkParameter parameter, uint output_port, uint input_port) {
    QString output_string = QVariant(output_port).toString();
    QString input_string = QVariant(input_port).toString();
    if (output_string.length() == input_string.length())
        return(ToString(parameter) + output_string + input_string);

    // Fix length mismatch
    if (output_string.length() < input_string.length())
        output_string =  "0" + output_string;
    else
        input_string = "0" + input_string;

    return(ToString(parameter) + output_string + input_string);
}
QString Vna::_Trace::Parameters_to_Scpi(NetworkParameter parameter, PortDefinition &output_port, PortDefinition &input_port) {
    QString scpi = Parameters_to_Scpi(parameter, output_port.logicalPort(), input_port.logicalPort());
    QString types = QString(output_port.portType()) + QString(input_port.portType());
    scpi.insert(1, types);
    return(scpi);
}

// TRACE:Private:Read Trace
uint Vna::_Trace::TraceBufferSize(TraceFormat format, uint points) {
    const uint SIZE_PER_POINT = 20;
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
    const uint SIZE_PER_POINT = 20;
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


//**********************
//** DIAGRAM ***********
//*********************/

Vna::_Diagram& Vna::Diagram(uint diagram) {
    _diagram = _Diagram(this, diagram);
    return(_diagram);
}

Vna::_Diagram::_Diagram(Vna *vna, uint diagram) {
    this->vna = vna;
    this->diagram = diagram;
}

// DIAGRAM:Actions
void Vna::_Diagram::Autoscale() {
    QStringList traces = GetTraces();

    foreach (const QString trace, traces) {
        vna->Trace(trace).Autoscale();
    }
}

// DIAGRAM:Get
QStringList Vna::_Diagram::GetTraces() {
    const uint BUFFER_SIZE = 4000;
    char buffer[BUFFER_SIZE];
    QStringList traces;
    sprintf(buffer, ":DISP:WIND%d:TRAC:CAT?\n", diagram);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
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
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":DISP:WIND%d:TITL:DATA?\n", diagram);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    QString title(buffer);
    title.remove('\'');
    return(title);
}

// DIAGRAM:Set
void Vna::_Diagram::SetTitle(QString title) {
    const uint BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    QByteArray c_string = title.toUtf8();
    sprintf(buffer, ":DISP:WIND%d:TITL:DATA \'%s\'\n", diagram, c_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Diagram::SetYMaximum(double max) {
    QStringList traces = GetTraces();
    foreach(const QString trace, traces) {
        vna->Trace(trace).SetYAxisMaximum(max);
    }
}
void Vna::_Diagram::SetYMinimum(double min) {
    QStringList traces = GetTraces();
    foreach(const QString trace, traces) {
        vna->Trace(trace).SetYAxisMinimum(min);
    }
}

// DIAGRAM:Private:Trace Info
QVector<uint> Vna::_Diagram::GetTraceNumbers() {
    const uint BUFFER_SIZE = 4000;
    char buffer[BUFFER_SIZE];
    QVector<uint> numbers;
    sprintf(buffer, ":DISP:WIND%d:TRAC:CAT?\n", diagram);
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    Vna::ParseIndicesFromRead(buffer, numbers);
    return(numbers);
}


//**********************
//** Calibration *******
//*********************/

Vna::_Calibration& Vna::Calibration() {
    _calibration = _Calibration(this);
    return(_calibration);
}
Vna::_Calibration::_Calibration(Vna *vna) {
    this->vna = vna;
    isSingleChannel = false;
    channel = 0;
}
Vna::_Calibration::_Calibration(Vna *vna, uint channel) {
    this->vna = vna;
    isSingleChannel = true;
    this->channel = channel;
}

void Vna::_Calibration::DefineConnector(uint port, Connector connector) {
    const int BUFFER_SIZE = 600;
    char buffer[BUFFER_SIZE];
    QByteArray type = ToScpi(connector).toUtf8();
    QByteArray gender = QString(ToScpi(connector.gender())).toUtf8();
    sprintf(buffer, ":CORR:COLL:SCON%d \'%s\',%s\n", port, type.constData(), gender.constData());
    vna->Write(QString(buffer));
}
void Vna::_Calibration::DefineConnectors(QVector<Connector> connectors) {
    uint num_connectors = (uint)connectors.size();
    for (uint i = 0; i < num_connectors; i++) {
        DefineConnector(i, connectors[i]);
    }
}
Connector Vna::_Calibration::GetConnector(uint port) {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];

    QString scpi = ":CORR:COLL:SCON%1?\n";
    scpi = scpi.arg(port);
    vna->Query(scpi, buffer, BUFFER_SIZE);
    QStringList results = QString(buffer).remove("\'").split(",");
    ConnectorType type = Scpi_To_ConnectorType(results.first());
    ConnectorGender gender = Scpi_To_ConnectorGender(results.last());
    if (type == CUSTOM_CONNECTOR)
        return(Connector(type, gender));
    else
        return(Connector(results.first(), gender));
}
QVector<Connector> Vna::_Calibration::GetConnectors() {
    uint num_ports = vna->GetTestPorts();
    QVector<Connector> conns;
    conns.resize((uint)num_ports);
    for (uint i = 0; i < num_ports; i++) {
        conns[i] = GetConnector(i+1);
    }
    return(conns);
}
void Vna::_Calibration::SelectKit(NameLabel name_label) {
    SelectKit(name_label.name(), name_label.label());
}
void Vna::_Calibration::SelectKit(QString kit_name, QString label) {
    Connector type = vna->CalKit(kit_name, label).GetConnectorType();
    SelectKit(kit_name, label, type);
}
void Vna::_Calibration::SelectKit(NameLabel name_label, Connector type) {
    SelectKit(name_label.name(), name_label.label(), type);
}
void Vna::_Calibration::SelectKit(QString kit_name, QString label, Connector type) {
    if (type.isCustomType())
        _SelectKit(kit_name, label, type.customType());
    else
        _SelectKit(kit_name, label, type.type());
}

NameLabel Vna::_Calibration::GetSelectedKit(Connector type) {
    const int BUFFER_SIZE = 200;
        char buffer[BUFFER_SIZE];
        if (isSingleChannel)
            sprintf(buffer, ":SENS%d:CORR:CKIT:LSEL? \'%s\'\n", channel, ToScpi(type).toUtf8().constData());
        else
            sprintf(buffer, ":CORR:CKIT:LSEL? \'%s\'\n", ToScpi(type).toUtf8().constData());
        vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
        QStringList results = QString(buffer).remove("\'").split(",");
        return(NameLabel(results.first(), results.last()));
}

void Vna::_Calibration::KeepRawData(bool isKept) {
    QString scpi;
    if (isSingleChannel)
        scpi = ":SENS" + QVariant(channel).toString();
    scpi += ":CORR:COLL:RSAV ";
    if (isKept)
        scpi += "1\n";
    else
        scpi += "0\n";
}

void Vna::_Calibration::Start(QString cal_name, CalType cal_type, QVector<uint> ports) {
    SelectSingleChannel(isSingleChannel);

    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    QByteArray cal_string = cal_name.toUtf8();
    QByteArray ports_string = ToString(ports, ",").toUtf8();
    if (isSingleChannel)
        sprintf(buffer, ":SENS%d:CORR:COLL:METH:DEF \'%s\',%s,%s\n", channel, cal_string.constData(), ToScpi(cal_type), ports_string.constData());
    else
        sprintf(buffer, ":CORR:COLL:METH:DEF \'%s\',%s,%s\n", cal_string.constData(), Vna::ToScpi(cal_type), ports_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Calibration::MeasureOpen(uint port) {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    if (isSingleChannel)
        sprintf(buffer, ":SENS%d:CORR:COLL:SEL OPEN,%d\n", channel, port);
    else
        sprintf(buffer, ":CORR:COLL:SEL OPEN,%d\n", port);
    vna->bus->write(QString(buffer));
}
void Vna::_Calibration::MeasureShort(uint port) {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    if (isSingleChannel)
        sprintf(buffer, ":SENS%d:CORR:COLL:SEL SHOR,%d\n", channel, port);
    else
        sprintf(buffer, ":CORR:COLL:SEL SHOR,%d\n", port);
    vna->bus->write(QString(buffer));
}
void Vna::_Calibration::MeasureMatch(uint port) {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    if (isSingleChannel)
        sprintf(buffer, ":SENS%d:CORR:COLL:SEL MATC,%d\n", channel, port);
    else
        sprintf(buffer, ":CORR:COLL:SEL MATC,%d\n", port);
    vna->bus->write(QString(buffer));
}
void Vna::_Calibration::MeasureThru(uint port1, uint port2) {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    if (isSingleChannel)
        sprintf(buffer, ":SENS%d:CORR:COLL:SEL THR,%d,%d\n", channel, port1, port2);
    else
        sprintf(buffer, ":CORR:COLL:SEL THR,%d,%d\n", port1, port2);
    vna->bus->write(QString(buffer));
}

void Vna::_Calibration::Apply() {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    if (isSingleChannel)
        sprintf(buffer, ":SENS%d:CORR:COLL:SAVE:SEL\n", channel);
    else
        sprintf(buffer, ":CORR:COLL:SAVE:SEL\n");
    vna->bus->write(QString(buffer));
}

// CALIBRATION:Private
void Vna::_Calibration::SelectAllChannels(bool isAll) {
    if (isAll)
        vna->bus->write(":CORR:COLL:CHAN:ALL 1\n");
    else
        vna->bus->write(":CORR:COLL:CHAN:ALL 0\n");
}
void Vna::_Calibration::SelectSingleChannel(bool isSingle) {
    SelectAllChannels(!isSingle);
}

void Vna::_Calibration::_SelectKit(QString kit_name, QString label, ConnectorType connector_type) {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    QByteArray kit_str = kit_name.toUtf8();
    QByteArray label_str = label.toUtf8();
    if (isSingleChannel)
        sprintf(buffer, ":SENS%d:CORR:CKIT:LSEL \'%s\',\'%s\',\'%s\'\n", channel, ToScpi(connector_type), kit_str.constData(), label_str.constData());
    else
        sprintf(buffer, ":CORR:CKIT:LSEL \'%s\',\'%s\',\'%s\'\n", ToScpi(connector_type), kit_str.constData(), label_str.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_Calibration::_SelectKit(QString kit_name, QString label, QString custom_connector_type) {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    QByteArray kit_str = kit_name.toUtf8();
    QByteArray label_str = label.toUtf8();
    QByteArray type_str = custom_connector_type.toUtf8();
    if (isSingleChannel)
        sprintf(buffer, ":SENS%d:CORR:CKIT:LSEL \'%s\',\'%s\',\'%s\'\n", channel, type_str.constData(), kit_str.constData(), label_str.constData());
    else
        sprintf(buffer, ":CORR:CKIT:LSEL \'%s\',\'%s\',\'%s\'\n", type_str.constData(), kit_str.constData(), label_str.constData());
    vna->bus->write(QString(buffer));
}


//**********************
//** Cal Units *********
//*********************/

Vna::_CalUnit& Vna::CalUnit() {
    _cal_unit = _CalUnit(this);
    return(_cal_unit);
}
Vna::_CalUnit& Vna::CalUnit(QString unit_name) {
    _cal_unit = _CalUnit(this, unit_name);
    return(_cal_unit);
}

Vna::_CalUnit::_CalUnit(Vna *vna) {
    this->vna = vna;
    isUnitSpecified = false;
}
Vna::_CalUnit::_CalUnit(Vna *vna, QString unit_name) {
    this->vna = vna;
    this->unit_name = unit_name;
    isUnitSpecified = true;
}

// CALUNIT:Select
void Vna::_CalUnit::Select() {
    if (isUnitSpecified) {
        const uint BUFFER_SIZE = 500;
        char buffer[BUFFER_SIZE];
        QByteArray unit_string = unit_name.toUtf8();
        sprintf(buffer, ":SYST:COMM:RDEV:AKAL:ADDR \'%s\'\n", unit_string.constData());
        vna->bus->write(QString(buffer));
    }
}

// CALUNIT:Status
bool Vna::_CalUnit::isWarmedUp() {
    const int BUFFER_SIZE = 30;
    char buffer[BUFFER_SIZE];
    vna->bus->query(":SYST:COMM:RDEV:AKAL:WARM?\n", buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Vna::_CalUnit::hasConnector(Connector connector) {
    QVector<Connector> connectors = GetPhysicalConnectors();
    int ports = (int)GetPorts();
    for (int i = 0; i < ports; i++) {
        if (connectors[i] == connector)
            return(true);
    }

    // else
    return(false);
}

// CALUNIT:Get
uint Vna::_CalUnit::GetPorts() {
    Select();
    const int BUFFER_SIZE = 200;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:COMM:RDEV:AKAL:PORT? \'Factory\'\n");
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).split(',').size()/3.0);
}
QVector<Connector> Vna::_CalUnit::GetPhysicalConnectors() {
    return(GetConnectors("Factory"));
}
QVector<Connector> Vna::_CalUnit::GetConnectorsFromLatestCal() {
    return(GetConnectors(""));
}
QVector<Connector> Vna::_CalUnit::GetConnectors(QString cal_name) {
    Select();
    const int BUFFER_SIZE = 200;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:COMM:RDEV:AKAL:PORT? \'%s\'\n", cal_name.toUtf8().constData());
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);

    QStringList result = QString(buffer).remove('\'').split(',');
    int ports = result.size()/3;
    QVector<Connector> connectors;
    connectors.resize(ports);
    for (int i = 0; i < ports; i++) {
        ConnectorType type = Scpi_To_ConnectorType(result[3*i+1]);
        ConnectorGender gender = Scpi_To_ConnectorGender(result[3*i+2]);
        if (type != CUSTOM_CONNECTOR)
            connectors[i] = Connector(type, gender);
        else
            connectors[i] = Connector(result[3*i+1], gender);
    }
    return(connectors);
}
QVector<uint> Vna::_CalUnit::GetPortsOfType(Connector connector) {
    QVector<uint> ports_of_type;
    QVector<Connector> connectors = GetPhysicalConnectors();
    int ports = (int)GetPorts();
    for (int i = 0; i < ports; i++) {
        if (connectors[i] == connector)
            ports_of_type.append(i);
    }
    return(ports_of_type);
}
double Vna::_CalUnit::GetMinimumFrequency_Hz() {
    Select();
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:COMM:RDEV:AKAL:FRAN? \'Factory\'\n");
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);

    QStringList freq = QString(buffer).split(',');
    if (freq.size() == 2)
        return(freq[0].toDouble());
    else
        return(0);
}
double Vna::_CalUnit::GetMaximumFrequency_Hz() {
    Select();
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:COMM:RDEV:AKAL:FRAN? \'Factory\'\n");
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);

    QStringList freq = QString(buffer).split(',');
    if (freq.size() == 2)
        return(freq[1].toDouble());
    else
        return(0);
}


QStringList Vna::_CalUnit::GetCalibrations() {
    Select();
    const int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:COMM:RDEV:AKAL:CKIT:CAT?\n");
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).split(','));
}
void Vna::_CalUnit::GetCalFrequency(QString cal_name, double &min_Hz, double &max_Hz) {
    Select();
    QByteArray kit_string = cal_name.toUtf8();

    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:COMM:RDEV:AKAL:FRAN? \'%s\'\n", kit_string.constData());
    vna->bus->query(QString(buffer), buffer, BUFFER_SIZE);

    QStringList freq = QString(buffer).split(',');
    if (freq.size() == 2) {
        min_Hz = freq[0].toDouble();
        max_Hz = freq[1].toDouble();
    }
    else {
        min_Hz = 0;
        max_Hz = 0;
    }
}
QString Vna::_CalUnit::GetCalDate(QString cal_name) {
    return("Right now!");
}

void Vna::_CalUnit::ExportFactoryCal(QString local_dir) {
    Select();

    QByteArray dir_string = local_dir.toUtf8();

    const int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":MMEM:AKAL:FACT:CONV \'%s\'\n", dir_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_CalUnit::ExportLatestCal(QString local_dir) {
    Select();

    QByteArray dir_string = local_dir.toUtf8();

    const int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":MMEM:AKAL:USER:CONV \'%s\'\n", dir_string.constData());
    vna->bus->write(QString(buffer));
}
void Vna::_CalUnit::ExportCal(QString cal_name, QString local_dir) {
    Select();

    QByteArray kit_string = cal_name.toUtf8();
    QByteArray dir_string = local_dir.toUtf8();

    const int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":MMEM:AKAL:USER:CONV \'%s\',\'%s\'\n", dir_string.constData(), kit_string.constData());
    vna->bus->write(QString(buffer));
}

// CALUNIT:Set
void Vna::_CalUnit::SetOpen() {
    uint ports = GetPorts();
    for (uint i = 1; i <= ports; i++)
        SetOpen(i);
}
void Vna::_CalUnit::SetOpen(uint port) {
    Select();

    const int BUFFER_SIZE = 60;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:COMM:AKAL:CONN OPEN,%d\n", port);
    vna->bus->write(buffer);
}
void Vna::_CalUnit::SetOpen(QVector<uint> ports) {
    foreach(uint port, ports) {
        SetOpen(port);
    }
}
void Vna::_CalUnit::SetShort() {
    uint ports = GetPorts();
    for (uint i = 1; i <= ports; i++)
        SetShort(i);
}
void Vna::_CalUnit::SetShort(uint port) {
    Select();

    const int BUFFER_SIZE = 60;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:COMM:AKAL:CONN SHOR,%d\n", port);
    vna->bus->write(buffer);
}
void Vna::_CalUnit::SetShort(QVector<uint> ports) {
    foreach(uint port, ports) {
        SetShort(port);
    }
}
void Vna::_CalUnit::SetMatch() {
    uint ports = GetPorts();
    for (uint i = 1; i <= ports; i++)
        SetMatch(i);
}
void Vna::_CalUnit::SetMatch(uint port) {
    Select();

    const int BUFFER_SIZE = 60;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:COMM:AKAL:CONN MATC,%d\n", port);
    vna->bus->write(buffer);
}
void Vna::_CalUnit::SetMatch(QVector<uint> ports) {
    foreach(uint port, ports) {
        SetMatch(port);
    }
}
void Vna::_CalUnit::SetThru(uint port1, uint port2) {
    Select();

    const int BUFFER_SIZE = 60;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:COMM:AKAL:CONN THR,%d,%d\n", port1, port2);
    vna->bus->write(buffer);
}


// CALUNIT:Private
QString Vna::ToScpi(Connector type) {
    if (type.isCustomType())
        return(type.customType());
    else
        return(ToScpi(type.type()));
}

const char* Vna::ToScpi(ConnectorType type) {
    switch(type) {
    case N_50_OHM_CONNECTOR:      return("N 50 Ohm");
    case N_75_OHM_CONNECTOR:      return("N 75 Ohm");
    case mm_7_CONNECTOR:          return("7 mm");
    case mm_3_5_CONNECTOR:        return("3.5 mm");
    case mm_2_92_CONNECTOR:       return("2.92 mm");
    case mm_2_4_CONNECTOR:        return("2.4 mm");
    case mm_1_85_CONNECTOR:       return("1.85 mm");
    case in_7_16_CONNECTOR:       return("7-16");
    case TYPE_F_75_OHM_CONNECTOR: return("Type F (75)");
    case BNC_50_OHM_CONNECTOR:    return("BNC 50 Ohm");
    case BNC_75_OHM_CONNECTOR:    return("BNC 75 Ohm");
    default:                      return("UNKNOWN_CONNECTOR");
    }
}
ConnectorType Vna::Scpi_To_ConnectorType(QString scpi) {
    if (scpi.contains("N 50 Ohm", Qt::CaseInsensitive))
        return(N_50_OHM_CONNECTOR);
    else if (scpi.contains("N 75 Ohm", Qt::CaseInsensitive))
        return(N_75_OHM_CONNECTOR);
    else if (scpi.contains("7 mm", Qt::CaseInsensitive))
        return(mm_7_CONNECTOR);
    else if (scpi.contains("3.5 mm", Qt::CaseInsensitive))
        return(mm_3_5_CONNECTOR);
    else if (scpi.contains("2.92 mm", Qt::CaseInsensitive))
        return(mm_2_92_CONNECTOR);
    else if (scpi.contains("2.4 mm", Qt::CaseInsensitive))
        return(mm_2_4_CONNECTOR);
    else if (scpi.contains("1.85 mm", Qt::CaseInsensitive))
        return(mm_1_85_CONNECTOR);
    else if (scpi.contains("7-16"))
        return(in_7_16_CONNECTOR);
    else if (scpi.contains("Type F (75)", Qt::CaseInsensitive))
        return(TYPE_F_75_OHM_CONNECTOR);
    else if (scpi.contains("BNC 50 Ohm", Qt::CaseInsensitive))
        return(BNC_50_OHM_CONNECTOR);
    else if (scpi.contains("BNC 75 Ohm", Qt::CaseInsensitive))
        return(BNC_75_OHM_CONNECTOR);
    else if (scpi.isEmpty() == false)
        return(CUSTOM_CONNECTOR);
    else
        return(UNKNOWN_CONNECTOR);
}

const char* Vna::ToScpi(ConnectorGender gender) {
    switch(gender) {
    case MALE_GENDER:    return("MALE");
    case FEMALE_GENDER:  return("FEM");
    case NEUTRAL_GENDER: return("");
    default:             return("");
    }
}
ConnectorGender Vna::Scpi_To_ConnectorGender(QString scpi) {
    if (scpi.contains("MALE", Qt::CaseInsensitive))
        return(MALE_GENDER);
    else if (scpi.contains("FEM", Qt::CaseInsensitive))
        return(FEMALE_GENDER);
    else
        return(NEUTRAL_GENDER);
}

const char* Vna::ToScpi(CalType type) {
    switch(type) {
    case OSM_CAL_TYPE:  return("FOP");
    case TOSM_CAL_TYPE: return("TOSM");
    case UOSM_CAL_TYPE: return("UOSM");
    default: return("UOSM");
    }
}
CalType Vna::Scpi_To_CalType(QString scpi) {
    if (scpi.contains("FOP", Qt::CaseInsensitive))
        return(OSM_CAL_TYPE);
    else if (scpi.contains("TOSM", Qt::CaseInsensitive))
        return(TOSM_CAL_TYPE);
    else
        return(UOSM_CAL_TYPE);
}

QString Vna::ToScpi(CalStandard standard) {
    if (standard.isSinglePort()) {
        if (standard.isNotPortSpecific())
            return(ToScpi(standard.type(), standard.connector().gender()));
        else
            return(ToScpi(standard.type(), standard.connector().gender(), standard.port()));
    }
    else {
        if (standard.isNotPortSpecific())
            return(ToScpi(standard.type(), standard.connector1().gender(), standard.connector2().gender()));
        else
            return(ToScpi(standard.type(), standard.connector1().gender(), standard.port1(), standard.connector2().gender(), standard.port2()));
    }
}
QString Vna::ToScpi(CalStandardType type, ConnectorGender gender) {
    QString scpi;
    switch(type) {
    case OPEN_STANDARD_TYPE:
        scpi = "OP";
        break;
    case SHORT_STANDARD_TYPE:
        scpi = "SH";
        break;
    case OFFSET_SHORT_STANDARD_TYPE:
        scpi = "OSH";
        break;
    case OFFSET_SHORT2_STANDARD_TYPE:
        scpi = "OSHORT2";
        break;
    case OFFSET_SHORT3_STANDARD_TYPE:
        scpi = "OSHORT3";
        break;
    case MATCH_STANDARD_TYPE:
        scpi = "MTC";
        break;
    case SLIDING_MATCH_STANDARD_TYPE:
        scpi = "SM";
        break;
    case REFLECT_STANDARD_TYPE:
        scpi = "REF";
        break;
    case THRU_STANDARD_TYPE:
    case LINE_STANDARD_TYPE:
    case LINE2_STANDARD_TYPE:
    case LINE3_STANDARD_TYPE:
    case ATTENUATION_STANDARD_TYPE:
    case SYMMETRIC_NETWORK_STANDARD_TYPE:
        return("GENDER_MISSING");
    default:
        return("UNKNOWN_STANDARD");
    }
    if (gender == FEMALE_GENDER)
        return("F" + scpi);
    else
        return("M" + scpi);
}
QString Vna::ToScpi(CalStandardType type, ConnectorGender gender, uint port) {
    QString scpi;
    switch(type) {
    case OPEN_STANDARD_TYPE:
        scpi = "OP";
        break;
    case SHORT_STANDARD_TYPE:
        scpi = "SH";
        break;
    case OFFSET_SHORT_STANDARD_TYPE:
        scpi = "OSH";
        break;
    case OFFSET_SHORT2_STANDARD_TYPE:
        scpi = "OSHORT2";
        break;
    case OFFSET_SHORT3_STANDARD_TYPE:
        scpi = "OSHORT3";
        break;
    case MATCH_STANDARD_TYPE:
        scpi = "MTC";
        break;
    case SLIDING_MATCH_STANDARD_TYPE:
        scpi = "SM";
        break;
    case REFLECT_STANDARD_TYPE:
        scpi = "REF";
        break;
    case THRU_STANDARD_TYPE:
    case LINE_STANDARD_TYPE:
    case LINE2_STANDARD_TYPE:
    case LINE3_STANDARD_TYPE:
    case ATTENUATION_STANDARD_TYPE:
    case SYMMETRIC_NETWORK_STANDARD_TYPE:
        return("GENDER_MISSING");
    default:
        return("UNKNOWN_STANDARD");
    }

    QString port_str = QVariant(port).toString();
    scpi += "(P" + port_str + ")";
    if (gender == FEMALE_GENDER)
        return("F" + scpi);
    else
        return("M" + scpi);
}
QString Vna::ToScpi(CalStandardType type, ConnectorGender gender1, ConnectorGender gender2) {
    QString scpi;
    switch(type) {
    case OPEN_STANDARD_TYPE:
    case SHORT_STANDARD_TYPE:
    case OFFSET_SHORT_STANDARD_TYPE:
    case OFFSET_SHORT2_STANDARD_TYPE:
    case OFFSET_SHORT3_STANDARD_TYPE:
    case MATCH_STANDARD_TYPE:
    case SLIDING_MATCH_STANDARD_TYPE:
    case REFLECT_STANDARD_TYPE:
        return(ToScpi(type, gender1));
    case THRU_STANDARD_TYPE:
        scpi = "TH";
        break;
    case LINE_STANDARD_TYPE:
        scpi = "LINE1";
        break;
    case LINE2_STANDARD_TYPE:
        scpi = "LINE2";
        break;
    case LINE3_STANDARD_TYPE:
        scpi = "LINE3";
        break;
    case ATTENUATION_STANDARD_TYPE:
        scpi = "AT";
        break;
    case SYMMETRIC_NETWORK_STANDARD_TYPE:
        scpi = "SN";
        break;
    default:
        return("UNKNOWN_STANDARD");
    }

    QString gender1_text;
    if (gender1 == FEMALE_GENDER)
        gender1_text = "F";
    else
        gender1_text = "M";

    QString gender2_text;
    if (gender2 == FEMALE_GENDER)
        gender2_text = "F";
    else
        gender2_text = "M";
    if (gender1_text != gender2_text)
        return("MF" + scpi);
    else
        return(gender1_text + gender2_text + scpi);
}
QString Vna::ToScpi(CalStandardType type, ConnectorGender gender1, uint port1, ConnectorGender gender2, uint port2) {
    QString scpi;
    switch(type) {
    case OPEN_STANDARD_TYPE:
    case SHORT_STANDARD_TYPE:
    case OFFSET_SHORT_STANDARD_TYPE:
    case OFFSET_SHORT2_STANDARD_TYPE:
    case OFFSET_SHORT3_STANDARD_TYPE:
    case MATCH_STANDARD_TYPE:
    case SLIDING_MATCH_STANDARD_TYPE:
    case REFLECT_STANDARD_TYPE:
        return(ToScpi(type, gender1));
    case THRU_STANDARD_TYPE:
        scpi = "TH";
        break;
    case LINE_STANDARD_TYPE:
        scpi = "LINE1";
        break;
    case LINE2_STANDARD_TYPE:
        scpi = "LINE2";
        break;
    case LINE3_STANDARD_TYPE:
        scpi = "LINE3";
        break;
    case ATTENUATION_STANDARD_TYPE:
        scpi = "AT";
        break;
    case SYMMETRIC_NETWORK_STANDARD_TYPE:
        scpi = "SN";
        break;
    default:
        return("UNKNOWN_STANDARD");
    }

    QString port1_text = QVariant(port1).toString();
    QString port2_text = QVariant(port2).toString();
    scpi += "(P" + port1_text + "P" + port2_text + ")";

    QString gender1_text;
    if (gender1 == FEMALE_GENDER)
        gender1_text = "F";
    else
        gender1_text = "M";

    QString gender2_text;
    if (gender2 == FEMALE_GENDER)
        gender2_text = "F";
    else
        gender2_text = "M";
    if (gender1_text != gender2_text)
        return("MF" + scpi);
    else
        return(gender1_text + gender2_text + scpi);
}
CalStandard Vna::Scpi_To_CalStandard(QString scpi) {
    CalStandard std;
    if (scpi.contains('(')) {
        QStringList scpi_split = scpi.remove(')').split('(');
        scpi = scpi_split.first();
        QStringList ports_list = scpi_split.last().remove(0,1).split('P', QString::SkipEmptyParts);
        if (ports_list.size() == 2) {
            std.setPort1(ports_list.first().toUInt());
            std.setPort2(ports_list.last().toUInt());
        }
        else {
            std.setPort(ports_list.first().toUInt());
        }
    }

    if (scpi.right(2).contains("OP", Qt::CaseInsensitive)) {
        std.setType(OPEN_STANDARD_TYPE);
        scpi.chop(2);
    }
    else if (scpi.right(3).contains("OSH", Qt::CaseInsensitive)) {
        std.setType(OFFSET_SHORT_STANDARD_TYPE);
        scpi.chop(3);
    }
    if (scpi.contains("OSHORT1", Qt::CaseInsensitive)) {
        std.setType(OFFSET_SHORT_STANDARD_TYPE);
        scpi.chop(7);
    }
    else if (scpi.contains("OSHORT2", Qt::CaseInsensitive)) {
        std.setType(OFFSET_SHORT2_STANDARD_TYPE);
        scpi.chop(7);
    }
    else if (scpi.contains("OSHORT3", Qt::CaseInsensitive)) {
        std.setType(OFFSET_SHORT3_STANDARD_TYPE);
        scpi.chop(7);
    }
    else if (scpi.right(2).contains("SH", Qt::CaseInsensitive)) {
        std.setType(SHORT_STANDARD_TYPE);
        scpi.chop(2);
    }
    else if (scpi.right(3).contains("MMT", Qt::CaseInsensitive)) {
        std.setType(MATCH_STANDARD_TYPE);
        scpi.chop(3);
    }
    else if (scpi.right(2).contains("SM", Qt::CaseInsensitive)) {
        std.setType(SLIDING_MATCH_STANDARD_TYPE);
        scpi.chop(2);
    }
    else if (scpi.right(3).contains("REF", Qt::CaseInsensitive)) {
        std.setType(REFLECT_STANDARD_TYPE);
        scpi.chop(3);
    }
    else if (scpi.right(2).contains("TH", Qt::CaseInsensitive)) {
        std.setType(THRU_STANDARD_TYPE);
        scpi.chop(2);
    }
    else if (scpi.right(1).contains("L", Qt::CaseInsensitive)) {
        std.setType(LINE_STANDARD_TYPE);
        scpi.chop(1);
    }
    else if (scpi.contains("LINE1", Qt::CaseInsensitive)) {
        std.setType(LINE_STANDARD_TYPE);
        scpi.chop(5);
    }
    else if (scpi.contains("LINE2", Qt::CaseInsensitive)) {
        std.setType(LINE2_STANDARD_TYPE);
        scpi.chop(5);
    }
    else if (scpi.contains("LINE3", Qt::CaseInsensitive)) {
        std.setType(LINE3_STANDARD_TYPE);
        scpi.chop(5);
    }
    else if (scpi.right(2).contains("AT", Qt::CaseInsensitive)) {
        std.setType(ATTENUATION_STANDARD_TYPE);
        scpi.chop(2);
    }
    if (scpi.right(2).contains("SN", Qt::CaseInsensitive)) {
        std.setType(SYMMETRIC_NETWORK_STANDARD_TYPE);
        scpi.chop(2);
    }


    if (std.isSinglePort() && scpi.size() >= 1) {
        switch(scpi[0].toUpper().toLatin1()) {
        case 'M': std.connector().setGender(MALE_GENDER);
            break;
        case 'F': std.connector().setGender(FEMALE_GENDER);
            break;
        default:
            std.connector().setGender(NEUTRAL_GENDER);
        }
    }
    else if (std.isTwoPort() && scpi.size() >= 2) {
        char port1 = scpi[0].toUpper().toLatin1();
        switch(port1) {
        case 'M': std.connector1().setGender(MALE_GENDER);
            break;
        case 'F': std.connector1().setGender(FEMALE_GENDER);
            break;
        default:
            std.connector1().setGender(NEUTRAL_GENDER);
        }

        char port2 = scpi[1].toUpper().toLatin1();
        switch(port2) {
        case 'M': std.connector2().setGender(MALE_GENDER);
            break;
        case 'F': std.connector2().setGender(FEMALE_GENDER);
            break;
        default:
            std.connector2().setGender(NEUTRAL_GENDER);
        }
    }

    return(std);
}
void Vna::ParseCalStandard(CalStandard &standard, QString scpi) {
    QStringList results = scpi.remove('\'').split(',');
    int length = results.size();


    if (length < 6) return;

    QString label = results[3];
    double min_freq = results[4].toDouble();
    double max_freq = results[5].toDouble();

    if (length == 6) {
        return;
    }

    if (length < 9) return;

    double e_length = results[6].toDouble();
    double loss = results[7].toDouble();
    double Z0 = results[8].toDouble();

    standard.setLabel(label);
    standard.setMinimumFrequency(min_freq);
    standard.setMaximumFrequency(max_freq);

    if (length == 9) {
        standard.SetModel(e_length, loss, Z0,
                          0,0,0,0, // C
                          0,0,0,0, // L
                          0); // R
        return;
    }

    if (length == 10) return;

    if (length == 11) {
        // thru, port-specific
        standard.setPort1(results[9].toDouble());
        standard.setPort2(results[10].toDouble());
        standard.SetModel(e_length, loss, Z0,
                          0,0,0,0, // C
                          0,0,0,0, // L
                          0); // R
        return;
    }

    if (length < 17) return;

    double C0, C1, C2, C3;
    double L0, L1, L2, L3;

    C0 = results[9].toDouble();
    C1 = results[10].toDouble();
    C2 = results[11].toDouble();
    C3 = results[12].toDouble();

    L0 = results[13].toDouble();
    L1 = results[14].toDouble();
    L2 = results[15].toDouble();
    L3 = results[16].toDouble();

    if (length == 17) {
        standard.SetModel(e_length, loss, Z0,
                          C0,C1,C2,C3,
                          L0,L1,L2,L3,
                          0); // R
        return;
    }

    double R = results[17].toDouble();

    if (length == 18) {
        standard.SetModel(e_length, loss, Z0,
                          C0,C1,C2,C3,
                          L0,L1,L2,L3,
                          R);
        return;
    }

    if (length == 19) {
        standard.setPort(results[18].toDouble());
        standard.SetModel(e_length, loss, Z0,
                          C0,C1,C2,C3,
                          L0,L1,L2,L3,
                          R);
    }

    if (length == 20) {
        standard.setPort1(results[18].toDouble());
        standard.setPort2(results[18].toDouble());
        standard.SetModel(e_length, loss, Z0,
                          C0,C1,C2,C3,
                          L0,L1,L2,L3,
                          R);
    }
}

//**********************
//** Cal Kits *********
//*********************/

// CalKit Interface
Vna::_CalKit& Vna::CalKit(NameLabel name_label) {
    return(CalKit(name_label.name(), name_label.label()));
}
Vna::_CalKit& Vna::CalKit(QString name, QString label) {
    _cal_kit = _CalKit(this, name, label);
    return(_cal_kit);
}

// CALKIT::Constructor
Vna::_CalKit::_CalKit(Vna *vna, QString name, QString label) {
    this->vna = vna;
    this->_name = name;
    this->_label = label;
}

// CALKIT::Status
bool Vna::_CalKit::isConnectorType(Connector type) {
    QVector<NameLabel> name_labels = vna->GetCalKits(type);
    return(name_labels.contains(NameLabel(_name, _label)));
}

bool Vna::_CalKit::has(CalStandard standard) {
    QVector<CalStandard> stds = _GetSimpleStandards();
    foreach (CalStandard std, stds) {
        if (std.isSameStandardAs(standard))
            return(true);
    }

    //else
    return(false);
}

bool Vna::_CalKit::has(CalStandardType type, ConnectorGender gender) {
    Connector connector;
    connector.setGender(gender);
    CalStandard std = CalStandard(type, connector);
    if (std.isTwoPort())
        return(false);

    return(has(std));
}
bool Vna::_CalKit::has(CalStandardType type, uint port) {
    CalStandard std = CalStandard(type, port);
    if (std.isTwoPort())
        return(false);

    return(has(std));
}
bool Vna::_CalKit::has(CalStandardType type, ConnectorGender gender1, ConnectorGender gender2) {
    Connector connector1;
    connector1.setGender(gender1);
    Connector connector2;
    connector2.setGender(gender2);
    CalStandard std = CalStandard(type, connector1, connector2);
    if (std.isSinglePort())
        return(false);

    return(has(std));
}
bool Vna::_CalKit::has(CalStandardType type, uint port1, uint port2) {
    CalStandard std = CalStandard(type, port1, port2);
    if (std.isSinglePort())
        return(false);

    return(has(std));
}

bool Vna::_CalKit::hasOpen(uint port) {
    return(has(OPEN_STANDARD_TYPE, port));
}
bool Vna::_CalKit::hasMaleOpen() {
    return(has(OPEN_STANDARD_TYPE, MALE_GENDER));
}
bool Vna::_CalKit::hasFemaleOpen() {
    return(has(OPEN_STANDARD_TYPE, FEMALE_GENDER));
}

bool Vna::_CalKit::hasShort(uint port) {
    return(has(SHORT_STANDARD_TYPE, port));
}
bool Vna::_CalKit::hasMaleShort() {
    return(has(SHORT_STANDARD_TYPE, MALE_GENDER));
}
bool Vna::_CalKit::hasFemaleShort() {
    return(has(SHORT_STANDARD_TYPE, FEMALE_GENDER));
}

bool Vna::_CalKit::hasMatch(uint port) {
    return(has(MATCH_STANDARD_TYPE, port));
}
bool Vna::_CalKit::hasMaleMatch() {
    return(has(MATCH_STANDARD_TYPE, MALE_GENDER));
}
bool Vna::_CalKit::hasFemaleMatch() {
    return(has(MATCH_STANDARD_TYPE, FEMALE_GENDER));
}

bool Vna::_CalKit::hasThru(ConnectorGender gender1, ConnectorGender gender2) {
    return(has(THRU_STANDARD_TYPE, gender1, gender2));
}
bool Vna::_CalKit::hasThru(uint port1, uint port2) {
    return(has(THRU_STANDARD_TYPE, port1, port2));
}

// CALKIT:Get
Connector Vna::_CalKit::GetConnectorType() {
    QVector<Connector> connectors = vna->GetConnectorTypes();
    foreach (Connector connector, connectors) {
        if (isConnectorType(connector))
            return(connector);
    }

    // else
    return(Connector());
}
QVector<CalStandard> Vna::_CalKit::GetStandards() {
    Connector type = GetConnectorType();

    QVector<CalStandard> stds = _GetSimpleStandards();
    int num_stds = stds.size();
    for (int i = 0; i < num_stds; i++) {
        _GetStandard(stds[i], type);
    }
    return(stds);
}

// CALKIT:Set
//void Vna::_CalKit::SetLabel(QString label) {

//}
void Vna::_CalKit::AddStandard(CalStandard &standard) {
    if (standard.isTouchstone())
        AddStandardByTouchstone(standard);
    else if (standard.isModel()) {

        // Values
        QString type_scpi;
        QString conn = standard.connector().displayType();
        QString label = standard.label();
        double min = standard.minimumFrequency_Hz();
        double max = standard.maximumFrequency_Hz();
        double e_length = standard._e_length;
        double loss = standard._loss;
        double Z0 = standard._Z0;
        double C0 = standard.C0;
        double C1 = standard.C1;
        double C2 = standard.C2;
        double C3 = standard.C3;
        double L0 = standard.L0;
        double L1 = standard.L1;
        double L2 = standard.L2;
        double L3 = standard.L3;
        double R = standard.R;




        if (standard.isSinglePort()) {
            if (standard.isPortSpecific()) {
                type_scpi = ToScpi(standard.type(), standard.gender());
                if (R == 0)
                    AddStandardByModel(type_scpi, conn, label, min, max, e_length,loss, Z0, C0, C1, C2, C3, L0, L1, L2, L3, standard.port());
                else
                    AddStandardByModel(type_scpi, conn, label, min, max, e_length,loss, Z0, C0, C1, C2, C3, L0, L1, L2, L3, R, standard.port());
            }
            else { // Not port specific
                type_scpi = ToScpi(standard.type(), standard.gender());
                if (R == 0)
                    AddStandardByModel(type_scpi, conn, label, min, max, e_length,loss, Z0, C0, C1, C2, C3, L0, L1, L2, L3);
                else
                    AddStandardByModel(type_scpi, conn, label, min, max, e_length,loss, Z0, C0, C1, C2, C3, L0, L1, L2, L3, R);
            }
        }
        else { // Two port
            if (standard.isPortSpecific()) {
                type_scpi = ToScpi(standard.type(), standard.gender1(), standard.gender2());
                if (standard.type() != SYMMETRIC_NETWORK_STANDARD_TYPE) {
                    AddStandardByModel(type_scpi, conn, label, min, max, e_length, loss, Z0, standard.port1(), standard.port2());
                }
                else { // Symm. Network
                    AddStandardByModel(type_scpi, conn, label, min, max, e_length,loss, Z0, C0, C1, C2, C3, L0, L1, L2, L3, standard.port1(), standard.port2());
                }
            }
            else { // Not port specific
                type_scpi = ToScpi(standard.type(), standard.gender1(), standard.gender2());
                if (standard.type() != SYMMETRIC_NETWORK_STANDARD_TYPE) {
                    AddStandardByModel(type_scpi, conn, label, min, max, e_length, loss, Z0);
                }
                else { // SYMM. Network
                    AddStandardByModel(type_scpi, conn, label, min, max, e_length,loss, Z0, C0, C1, C2, C3, L0, L1, L2, L3);
                }
            }
        }
    }
    else {
    }
}

// CALKIT:Delete
//void Vna::_CalKit::DeleteStandard(CalStandard standard) {}

//void Vna::_CalKit::DeleteStandard(CalStandardType type) {}
//void Vna::_CalKit::DeleteStandard(CalStandardType type, ConnectorGender gender) {}
//void Vna::_CalKit::DeleteStandard(CalStandardType type, uint port) {}

//void Vna::_CalKit::DeleteStandard(CalStandardType type, ConnectorGender gender1, ConnectorGender gender2) {}
//void Vna::_CalKit::DeleteStandard(CalStandardType type, uint port1, uint port2) {}


// CALKIT:Private
void Vna::_CalKit::_GetStandard(CalStandard &std, Connector type) {
    if (std.isPortSpecific())
        return;

    const int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    QString query_std = ":CORR:CKIT:" + ToScpi(std) + ":WLAB?"
            + " \'" + ToScpi(type) + "\',"
            + "\'" + _name + "\',"
            + "\'" + _label + "\'\n";
    vna->bus->query(query_std, buffer, BUFFER_SIZE);
    ParseCalStandard(std, buffer);
}
QStringList Vna::_CalKit::_GetStandards() {
    const int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    QString query_stds = ":CORR:CKIT:STAN:LCAT? \'" + _name + "\',\'" + _label + "\'\n";
    vna->bus->query(query_stds, buffer, BUFFER_SIZE);

    return(QString(buffer).remove('\'').split(',', QString::SkipEmptyParts));
}
QVector<CalStandard> Vna::_CalKit::_GetSimpleStandards() {
    QStringList stds_list = _GetStandards();
    int num_stds = stds_list.size();

    Connector type = GetConnectorType();

    QVector<CalStandard> stds;
    stds.resize(num_stds);
    for (int i = 0; i < num_stds; i++) {
        stds[i] = Scpi_To_CalStandard(stds_list[i]);
        stds[i].connector1().setType(type);
        stds[i].connector2().setType(type);
    }

    return(stds);
}

void Vna::_CalKit::AddStandardByTouchstone(CalStandard &standard) {
    const int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    if (standard.isTwoPort()) {
        if (standard.isPortSpecific()) {
            sprintf(buffer, ":MMEM:LOAD:CKIT:SDAT \'%s\',\'%s\',%s,\'%s\',\'%s\',%d,%d\n",
                    ToScpi(standard.connector()).toUtf8().constData(),
                    _name.toUtf8().constData(),
                    ToScpi(standard.type(), standard.connector1().gender(), standard.connector2().gender()).toUtf8().constData(),
                    standard.label().toUtf8().constData(),
                    standard.touchstone().toUtf8().constData(),
                    standard.port1(),
                    standard.port2());
        }
        else {
            sprintf(buffer, ":MMEM:LOAD:CKIT:SDAT \'%s\',\'%s\',%s,\'%s\',\'%s\'\n",
                    ToScpi(standard.connector()).toUtf8().constData(),
                    _name.toUtf8().constData(),
                    ToScpi(standard.type(), standard.connector1().gender(), standard.connector2().gender()).toUtf8().constData(),
                    standard.label().toUtf8().constData(),
                    standard.touchstone().toUtf8().constData());
        }
    }
    else {
        if (standard.isPortSpecific()) {
            sprintf(buffer, ":MMEM:LOAD:CKIT:SDAT \'%s\',\'%s\',%s,\'%s\',\'%s\',%d\n",
                    ToScpi(standard.connector()).toUtf8().constData(),
                    _name.toUtf8().constData(),
                    ToScpi(standard.type(), standard.connector().gender()).toUtf8().constData(),
                    standard.label().toUtf8().constData(),
                    standard.touchstone().toUtf8().constData(),
                    standard.port());
        }
        else {
            sprintf(buffer, ":MMEM:LOAD:CKIT:SDAT \'%s\',\'%s\',%s,\'%s\',\'%s\'\n",
                    ToScpi(standard.connector()).toUtf8().constData(),
                    _name.toUtf8().constData(),
                    ToScpi(standard.type(), standard.connector().gender()).toUtf8().constData(),
                    standard.label().toUtf8().constData(),
                    standard.touchstone().toUtf8().constData());
        }
    }
    vna->bus->write(QString(buffer));
}

// Single Port
void Vna::_CalKit::AddStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3) {
    QString scpi = ":CORR:CKIT:" + type_scpi + ":WLAB ";
    scpi += "\'" + connector + "\',";
    scpi += "\'" + _name + "\',";
    scpi += "\'" + _label + "\',";
    scpi += "\'" + label + "\',";
    scpi += QVariant(min_Hz).toString() + ",";
    scpi += QVariant(max_Hz).toString() + ",";
    scpi += QVariant(length).toString() + ",";
    scpi += QVariant(loss).toString() + ",";
    scpi += QVariant(Z0).toString() + ",";
    scpi += QVariant(C0).toString() + ",";
    scpi += QVariant(C1).toString() + ",";
    scpi += QVariant(C2).toString() + ",";
    scpi += QVariant(C3).toString() + ",";
    scpi += QVariant(L0).toString() + ",";
    scpi += QVariant(L1).toString() + ",";
    scpi += QVariant(L2).toString() + ",";
    scpi += QVariant(L3).toString() + "\n";
    vna->Write(scpi);
}
void Vna::_CalKit::AddStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, double R) {
    QString scpi = ":CORR:CKIT:" + type_scpi + ":WLAB ";
    scpi += "\'" + connector + "\',";
    scpi += "\'" + _name + "\',";
    scpi += "\'" + _label + "\',";
    scpi += "\'" + label + "\',";
    scpi += QVariant(min_Hz).toString() + ",";
    scpi += QVariant(max_Hz).toString() + ",";
    scpi += QVariant(length).toString() + ",";
    scpi += QVariant(loss).toString() + ",";
    scpi += QVariant(Z0).toString() + ",";
    scpi += QVariant(C0).toString() + ",";
    scpi += QVariant(C1).toString() + ",";
    scpi += QVariant(C2).toString() + ",";
    scpi += QVariant(C3).toString() + ",";
    scpi += QVariant(L0).toString() + ",";
    scpi += QVariant(L1).toString() + ",";
    scpi += QVariant(L2).toString() + ",";
    scpi += QVariant(L3).toString() + ",";
    scpi += QVariant(R).toString() + "\n";
    vna->Write(scpi);
}
void Vna::_CalKit::AddStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, double R, uint port) {
    QString scpi = ":CORR:CKIT:" + type_scpi + ":WLAB ";
    scpi += "\'" + connector + "\',";
    scpi += "\'" + _name + "\',";
    scpi += "\'" + _label + "\',";
    scpi += "\'" + label + "\',";
    scpi += QVariant(min_Hz).toString() + ",";
    scpi += QVariant(max_Hz).toString() + ",";
    scpi += QVariant(length).toString() + ",";
    scpi += QVariant(loss).toString() + ",";
    scpi += QVariant(Z0).toString() + ",";
    scpi += QVariant(C0).toString() + ",";
    scpi += QVariant(C1).toString() + ",";
    scpi += QVariant(C2).toString() + ",";
    scpi += QVariant(C3).toString() + ",";
    scpi += QVariant(L0).toString() + ",";
    scpi += QVariant(L1).toString() + ",";
    scpi += QVariant(L2).toString() + ",";
    scpi += QVariant(L3).toString() + ",";
    scpi += QVariant(R).toString() + ",";
    scpi += QVariant(port).toString() + "\n";
    vna->Write(scpi);
}

// Two Port (Including Symmetric Network...?)
void Vna::_CalKit::AddStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0) {
    QString scpi = ":CORR:CKIT:" + type_scpi + ":WLAB ";
    scpi += "\'" + connector + "\',";
    scpi += "\'" + _name + "\',";
    scpi += "\'" + _label + "\',";
    scpi += "\'" + label + "\',";
    scpi += QVariant(min_Hz).toString() + ",";
    scpi += QVariant(max_Hz).toString() + ",";
    scpi += QVariant(length).toString() + ",";
    scpi += QVariant(loss).toString() + ",";
    scpi += QVariant(Z0).toString() + "\n";
    vna->Write(scpi);
}
void Vna::_CalKit::AddStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, uint port1, uint port2) {
    QString scpi = ":CORR:CKIT:" + type_scpi + ":WLAB ";
    scpi += "\'" + connector + "\',";
    scpi += "\'" + _name + "\',";
    scpi += "\'" + _label + "\',";
    scpi += "\'" + label + "\',";
    scpi += QVariant(min_Hz).toString() + ",";
    scpi += QVariant(max_Hz).toString() + ",";
    scpi += QVariant(length).toString() + ",";
    scpi += QVariant(loss).toString() + ",";
    scpi += QVariant(Z0).toString() + ",";
    scpi += QVariant(port1).toString() + ",";
    scpi += QVariant(port2).toString() + "\n";
    vna->Write(scpi);
}
void Vna::_CalKit::AddStandardByModel(QString type_scpi, QString connector, QString label, double min_Hz, double max_Hz, double length, double loss, double Z0, double C0, double C1, double C2, double C3, double L0, double L1, double L2, double L3, uint port1, uint port2) {
    QString scpi = ":CORR:CKIT:" + type_scpi + ":WLAB ";
    scpi += "\'" + connector + "\',";
    scpi += "\'" + _name + "\',";
    scpi += "\'" + _label + "\',";
    scpi += "\'" + label + "\',";
    scpi += QVariant(min_Hz).toString() + ",";
    scpi += QVariant(max_Hz).toString() + ",";
    scpi += QVariant(length).toString() + ",";
    scpi += QVariant(loss).toString() + ",";
    scpi += QVariant(Z0).toString() + ",";
    scpi += QVariant(C0).toString() + ",";
    scpi += QVariant(C1).toString() + ",";
    scpi += QVariant(C2).toString() + ",";
    scpi += QVariant(C3).toString() + ",";
    scpi += QVariant(L0).toString() + ",";
    scpi += QVariant(L1).toString() + ",";
    scpi += QVariant(L2).toString() + ",";
    scpi += QVariant(L3).toString() + ",";
    scpi += QVariant(port1).toString() + ",";
    scpi += QVariant(port2).toString() + "\n";
    vna->Write(scpi);
}

