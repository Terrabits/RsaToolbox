

#include "General.h"
#include "Rsc.h"
#include "RsibBus.h"
#include "VisaBus.h"
using namespace RsaToolbox;

RscCalibrationState RsaToolbox::Scpi_To_RscCalState(QString scpi) {
    if (scpi.contains("AF", Qt::CaseInsensitive))
        return(AF_RSC_CAL);
    if (scpi.contains("FULL", Qt::CaseInsensitive))
        return(FULL_RSC_CAL);
    if (scpi.contains("OFF", Qt::CaseInsensitive))
        return(OFF_RSC_CAL);
    if (scpi.contains("OFS", Qt::CaseInsensitive))
        return(OFS_RSC_CAL);
    // Default
    return(OFF_RSC_CAL);
}
QString RsaToolbox::RscCalState_To_String(RscCalibrationState state) {
    switch(state) {
    case AF_RSC_CAL:
        return("AF");
        break;
    case FULL_RSC_CAL:
        return("FULL");
        break;
    case OFF_RSC_CAL:
        return("OFF");
        break;
    case OFS_RSC_CAL:
        return("OFS");
        break;
    default:
        return("OFF");
    }
}

QString RsaToolbox::ToString(RscModel model) {
    switch(model) {
    case RSC_02_MODEL:
        return("RSC 1313.8004.02");
    case RSC_03_MODEL:
        return("RSC 1313.8004.03");
    case RSC_04_MODEL:
        return("RSC 1313.8004.04");
    case RSC_05_MODEL:
        return("RSC 1313.8004.05");
    case RSC_13_MODEL:
        return("RSC 1313.8004.13");
    case RSC_14_MODEL:
        return("RSC 1313.8004.14");
    case RSC_15_MODEL:
        return("RSC 1313.8004.15");
    case RSC_Z405_MODEL:
        return("RSC-Z405");
    case RSC_Z675_MODEL:
        return("RSC-Z675");
    default:
        return("RSC 1313.8004.02");
        break;
    }
}
RscModel RsaToolbox::Scpi_to_RscModel(QString scpi) {
    if (scpi.contains("1313.9952.02") || scpi.contains("Z405"))
        return(RSC_Z405_MODEL);

    if (scpi.contains("1314.0065.02") || scpi.contains("Z675"))
        return(RSC_Z675_MODEL);

    int model_no = scpi.split('.').last().toInt();
    switch(model_no) {
    case 2:
        return(RSC_02_MODEL);
    case 3:
        return(RSC_03_MODEL);
    case 4:
        return(RSC_04_MODEL);
    case 5:
        return(RSC_05_MODEL);
    case 13:
        return(RSC_13_MODEL);
    case 14:
        return(RSC_14_MODEL);
    case 15:
        return(RSC_15_MODEL);
    default:
        return(RSC_03_MODEL);
    }
}

Rsc::Rsc() {
    bus.reset(new RsibBus());
}
Rsc::Rsc(ConnectionType connection_type, QString address, uint timeout_ms, QObject *parent) :
    QObject(parent)
{
    if (connection_type == NO_CONNECTION)
        bus.reset(new RsibBus());
    else if (connection_type == TCPIP_CONNECTION)
        bus.reset(new VisaBus(connection_type, address, timeout_ms));
    else
        bus.reset(new VisaBus(connection_type, address, timeout_ms));

    GetInstrumentInfo();
}
Rsc::~Rsc() {
    bus->disconnect();
}

void Rsc::ConnectLog(Log &log) {
    this->log = &log;
    QObject::connect(bus.data(), SIGNAL(Print(QString)),
                     &log, SLOT(Print(QString)));
    QObject::connect(this, SIGNAL(Print(QString)),
                     &log, SLOT(Print(QString)));

    PrintInstrumentInfo();
}
void Rsc::DisconnectLog() {
    QObject::disconnect(bus.data(), SIGNAL(Print(QString)),
                        log, SLOT(Print(QString)));
    QObject::disconnect(this, SIGNAL(Print(QString)),
                        log, SLOT(Print(QString)));
}

QString Rsc::GetIdString() {
    const int BUFFER_SIZE = 200;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "*IDN?\n");
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer));
}
RscModel Rsc::GetModel() {
    return(model);
}
QString Rsc::GetSerialNumber() {
    return(serial_no);
}
QString Rsc::GetFirmwareVersion() {
    return(firmware_version);
}


bool Rsc::isConnected() {
    return(bus->isOpen());
}
bool Rsc::isOperationComplete() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "*OPC?\n");
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Rsc::isError() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":SYST:ERR?\n");
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).at(0) != '0');
}
bool Rsc::isCorrectionEnabled() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":ATT%d:CORR?\n", unit_index);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer) == "1");
}
bool Rsc::isBaseUnit() {
    if (model == RSC_02_MODEL)
        return(true);
    else
        return(false);
}

void Rsc::ClearErrors() {
    bus->Write(":SYST:ERR:CLE:ERR\n");
}

QVector<QStringList> Rsc::GetAvailableUnits() {
    const int BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    bus->Query(QString(":ATT:CAT?\n"), buffer, BUFFER_SIZE);
    QStringList units = QString(buffer).remove('\"').split('|');
    QVector<QStringList> parsed_units;
    parsed_units.resize(units.size());
    for (int i = 0; i < units.size(); i++) {
        parsed_units[i] = units[i].split(',');
    }
    return(parsed_units);
}
uint Rsc::GetUnitIndex() {
    return(unit_index);
}
double Rsc::GetAttenuation_dB() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":ATT%d:ATT?\n", unit_index);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(QString(buffer).toDouble());
}
RscCalibrationState Rsc::GetUserCalibrationState() {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":ATT%d:UCAL?\n", unit_index);
    bus->Query(QString(buffer), buffer, BUFFER_SIZE);
    return(Scpi_To_RscCalState(QString(buffer)));
}
double Rsc::GetMinimumFrequency_Hz() {
    return(0);
}
double Rsc::GetMaximumFrequency_Hz() {
    switch(model) {
    case RSC_03_MODEL:
        return(6E9);
        break;
    case RSC_04_MODEL:
        return(6E9);
        break;
    case RSC_05_MODEL:
        return(18E9);
        break;
    case RSC_13_MODEL:
        return(6E9);
        break;
    case RSC_14_MODEL:
        return(6E9);
        break;
    case RSC_15_MODEL:
        return(18E9);
        break;
    default:
        return(0);
        break;
    }
}
double Rsc::GetMaximumPower_dBm() {
    // 1 W in CW mode
    // and 200 W in pulsed mode (for pulses < 10 μs)
//    switch(model) {
//    case RSC_03_MODEL:
//        return(6E9);
//        break;
//    case RSC_04_MODEL:
//        return(6E9);
//        break;
//    case RSC_05_MODEL:
//        return(18E9);
//        break;
//    case RSC_13_MODEL:
//        return(6E9);
//        break;
//    case RSC_14_MODEL:
//        return(6E9);
//        break;
//    case RSC_15_MODEL:
//        return(18E9);
//        break;
//    default:
//        return(0);
//        break;
//    }
    return(30);
}

double Rsc::GetMaximumAttenuation_dB() {
    switch(model) {
    case RSC_03_MODEL:
        return(139);
        break;
    case RSC_04_MODEL:
        return(139.9);
        break;
    case RSC_05_MODEL:
        return(115);
        break;
    case RSC_13_MODEL:
        return(139);
        break;
    case RSC_14_MODEL:
        return(139.9);
        break;
    case RSC_15_MODEL:
        return(115);
        break;
    default:
        return(0);
        break;
    }
}
double Rsc::GetStepSize_dB() {
    switch(model) {
    case RSC_03_MODEL:
        return(1);
        break;
    case RSC_04_MODEL:
        return(0.1);
        break;
    case RSC_05_MODEL:
        return(5);
        break;
    case RSC_13_MODEL:
        return(1);
        break;
    case RSC_14_MODEL:
        return(0.1);
        break;
    case RSC_15_MODEL:
        return(5);
        break;
    default:
        return(0);
        break;
    }
}

void Rsc::EnableCorrection(bool isEnabled) {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    if (isEnabled)
        sprintf(buffer, ":ATT%d:CORR 1\n", unit_index);
    else
        sprintf(buffer, ":ATT%d:CORR 0\n", unit_index);
    bus->Write(QString(buffer));
}
void Rsc::DisableCorrection(bool isDisabled) {
    EnableCorrection(!isDisabled);
}

void Rsc::SetUnitIndex(uint index) {
    unit_index = index;
}
void Rsc::SetAttenuation(double value) {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    sprintf(buffer, ":ATT%d:ATT %f\n", unit_index, value);
    bus->Write(QString(buffer));
}
void Rsc::SetUserCalibrationState(RscCalibrationState state) {
    const int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    QByteArray c_scpi = RscCalState_To_String(state).toUtf8();
    sprintf(buffer, ":ATT%d:UCAL %s\n", unit_index, c_scpi.constData());
    bus->Write(QString(buffer));
}

void Rsc::LoadUserCalibrationFile(QString filename) {
    const int BUFFER_SIZE = 500;
    char buffer[BUFFER_SIZE];
    QByteArray c_filename = filename.toUtf8();
    sprintf(buffer, ":ATT%d:UCAL:LOAD %s\n", unit_index, c_filename.constData());
    bus->Write(QString(buffer));
}
void Rsc::GetInstrumentInfo() {
    id_string = GetIdString();
    QStringList id = id_string.split(',');
    // id[0] = "Rohde&Schwarz"
    // id[1] = "RSC"
    // id[2] = "_MODEL_/SERIAL_NO"
    // id[3] = "_FIRMWARE_VERSION_"

    if (id.size() < 4 || id[0] != "Rohde&Schwarz" || id[1].contains("RSC") == false) {
        model = RSC_UNKNOWN_MODEL;
        return;
    }

    QStringList model_serial = id[2].split('/');
    model = Scpi_to_RscModel(model_serial.first());
    serial_no = model_serial.last();
    firmware_version = id.last();
}
void Rsc::PrintInstrumentInfo() {
    QString info_text;
    QTextStream stream(&info_text);
    stream << "RSC INSTRUMENT INFO:" << endl;
    if (bus->isOpen()) {
        if (model != RSC_UNKNOWN_MODEL) {
            stream << "Connection:       " << ToString(bus->connection_type) << endl;
            stream << "Address:          " << bus->address << endl;
            stream << "Make:             Rohde & Schwarz" << endl;
            stream << "Model:            " << ToString(model) << endl;
            stream << "Serial No:        " << serial_no << endl;
            stream << "Firmware Version: " << firmware_version << endl;
        }
        else {
            stream << "Unknown instrument model" << endl;
            stream << "*IDN?:  " << id_string << endl;
        }
    }
    else {
        stream << "Instrument not found" << endl;
        stream << "Connection:       " << ToString(bus->connection_type) << endl;
        stream << "Address:          " << bus->address << endl;
    }
    stream << endl << endl;
    stream.flush();
    emit Print(info_text);
}
