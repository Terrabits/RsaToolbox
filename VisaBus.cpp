
// RsaToolbox includes
#include "Definitions.h"
#include "VisaBus.h"

// C/C++
#include <cstdio>

// Qt
#include <QByteArray>
#include <QTextStream>
#include <QMessageBox>

using namespace RsaToolbox;


// Constructor, Destructor
VisaBus::VisaBus()
    :GenericBus() {
    resource_manager = NULL;
    instrument = NULL;
}
VisaBus::VisaBus(ConnectionType connection_type, QString instrument_address, short timeout_ms)
    :GenericBus(connection_type, instrument_address, timeout_ms) {
    visa_library.setFileName(FILENAME);
    QString resource_string;
    if (visa_library.load()) {
        if (connection_type == TCPIP_CONNECTION) {
            resource_string = QString("TCPIP::") + instrument_address + QString("::INSTR");
        }
        else if (connection_type == GPIB_CONNECTION) {
            resource_string = QString("GPIB::") + instrument_address + QString("::INSTR");
        }
        else {
            UnknownDevice();
            return;
        }
        RetrieveInterface();
        status = _viOpenDefaultRM(&resource_manager);
        if (status < VI_SUCCESS) {
            UnknownDevice();
            return;
        }
        QByteArray c_string = resource_string.toLocal8Bit();
        status = _viOpen(resource_manager, c_string.data(), (ViUInt32)VI_NULL, (ViUInt32)timeout_ms, &instrument);
        if (status < VI_SUCCESS) {
            UnknownDevice();
            return;
        }
        return;
    }
    else {
        // VISA dll cannot be found on the system.
        UnknownDevice();
    }
}
VisaBus::~VisaBus() {
    if (connection_type != NO_CONNECTION) {
        _viClose(instrument);
        _viClose(resource_manager);
    }
}

// Status
bool VisaBus::isVisaPresent() {
    return(QLibrary(FILENAME).load());
}
bool VisaBus::isOpen() {
    return(connection_type != NO_CONNECTION);
}
void VisaBus::PrintStatus() {
    QString formatted_text;
    QTextStream log(&formatted_text);
    const unsigned int BUFFER_SIZE = 200;
    char buffer[BUFFER_SIZE];
    status = _viStatusDesc(instrument, status, buffer);
    log << "ViStatus: 0x" << hex << status << dec << endl;
    log << "         " << QString(buffer).trimmed() << endl;

    // Print
    log.flush();
    emit Print(formatted_text);
}

// Actions
bool VisaBus::Lock() {
    status = _viLock(instrument, VI_EXCLUSIVE_LOCK, (ViUInt32)timeout_ms, VI_NULL, VI_NULL);
    return(status >= VI_SUCCESS);
}
bool VisaBus::Unlock() {
    status = _viUnlock(instrument);
    return(status >= VI_SUCCESS);
}
bool VisaBus::Read(char *buffer, unsigned int buffer_size) {
    QString formatted_text;
    QTextStream log(&formatted_text);
    ViUInt32 read_size;
    status = _viRead(instrument, (unsigned char *)buffer, (ViUInt32)buffer_size, &read_size);
    if (status >= VI_SUCCESS) {
        NullTerminateRead(buffer, buffer_size, read_size);
        log << ToTruncatedString(buffer);
        log.flush();
        emit Print(formatted_text);
        PrintStatus();
        emit Print("\n");
        return(true);
    }
    else {
        log << "Error reading from instrument." << endl;
        log.flush();
        emit Print(formatted_text);
        PrintStatus();
        emit Print("\n");
        return(false);
    }
}
bool VisaBus::Write(QString scpi_command) {
    QString formatted_text;
    QTextStream log(&formatted_text);
    QByteArray c_string = scpi_command.toLocal8Bit();
    ViUInt32 write_count;
    status = _viWrite(instrument, (unsigned char *)c_string.data(), c_string.size(), &write_count);
    if (status >= VI_SUCCESS) {
        log << "Sent:     \"" << scpi_command.trimmed() <<  "\"" << endl;
        log.flush();
        emit Print(formatted_text);
        PrintStatus();
        emit Print("\n");
        return(true);
    }
    else {
        log << "Error sending \"" << scpi_command.trimmed() << "\"" << endl;
        log.flush();
        emit Print(formatted_text);
        PrintStatus();
        emit Print("\n");
        return(false);
    }
}
bool VisaBus::Query(QString scpi_command, char *buffer, unsigned int buffer_size) {
    bool isWritten = Write(scpi_command);
    if (isWritten == false)
        return(false);
    // else
    bool isRead = Read(buffer, buffer_size);
    if (isRead == false)
        return(false);
    else
        return(true);
}

// Private
void VisaBus::UnknownDevice() {
    // Handle unknown/unconnectable device situation
    connection_type = NO_CONNECTION;
    resource_manager = NULL;
    instrument = NULL;
}
void VisaBus::RetrieveInterface() {
    _viStatusDesc = (StatusDesc_Functer)visa_library.resolve("viStatusDesc");
    _viOpenDefaultRM = (OpenDefaultRM_Functer)visa_library.resolve("viOpenDefaultRM");
    _viOpen = (Open_Functer)visa_library.resolve("viOpen");
    _viRead = (Read_Functer)visa_library.resolve("viRead");
    _viWrite = (Write_Functer)visa_library.resolve("viWrite");
    _viClear = (Clear_Functer)visa_library.resolve("viClear");
    _viLock = (Lock_Functer)visa_library.resolve("viLock");
    _viUnlock = (Unlock_Functer)visa_library.resolve("viUnlock");
    _viClose = (Close_Functer)visa_library.resolve("viClose");
}
bool VisaBus::isError() {
    return(status < VI_SUCCESS);
}
void VisaBus::NullTerminateRead(char *buffer, unsigned long buffer_size, ViUInt32 read_size) {
    // Null-terminate string
    if (read_size < buffer_size)
        buffer[read_size] = '\0';
    else
        buffer[buffer_size - 1] = '\0'; // Could overwrite last byte?
}
QString VisaBus::ToTruncatedString(char *buffer) {
    QString formatted_text(buffer);
    formatted_text.truncate(MAX_PRINT);
    formatted_text = QString("Received: \"")
            + formatted_text
            + QString("\"\n");
    return(formatted_text);
}
