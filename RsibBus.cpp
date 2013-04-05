
// RsaToolbox includes
#include "Definitions.h"
#include "RsibBus.h"

// C/C++
#include <cstdio>

// Qt
#include <QByteArray>
#include <QTextStream>

// Rsib
#include "rsib.h"

using namespace RsaToolbox;


// Constructor, Destructor
RsibBus::RsibBus(ConnectionType connectionType, QString address, short timeout_ms)
    :GenericBus(connectionType, address, timeout_ms) {
    // Only handles TCPIP
    if (connectionType == TCPIP_CONNECTION) {
        QByteArray c_string = address.toLocal8Bit();
        instrument = RSDLLibfind(c_string.data(), &ibsta, &iberr, &ibcntl);
    }
    else {
        instrument = -1;
        return;
    }

	// Set timeout
    RSDLLibtmo(instrument, timeout_ms, &ibsta, &iberr, &ibcntl);
}
RsibBus::~RsibBus() {
    if (instrument != -1) {
        RSDLLibloc(instrument, &ibsta, &iberr, &ibcntl);
        RSDLLibonl(instrument, 0, &ibsta, &iberr, &ibcntl);
    }
}

// Actions
bool RsibBus::Read(char *buffer, unsigned int bufferSize) {
    QString formatted_text;
    QTextStream log(&formatted_text);

    RSDLLilrd(instrument, buffer, bufferSize, &ibsta, &iberr, &ibcntl);
    if (isError()) {
        log << "Error reading from instrument." << endl;
        log.flush();
        emit Print(formatted_text);
        PrintStatus();
        formatted_text.clear();
        emit Print("\n");
        return(false);
    }
	else {
		NullTerminateRead(buffer, bufferSize);
        log << ToTruncatedString(buffer);
        log.flush();
        emit Print(formatted_text);
        PrintStatus();
        formatted_text.clear();
        emit Print("\n");
        return(true);
	}
}
bool RsibBus::Write(QString scpiCommand) {
    QString formatted_text;
    QTextStream log(&formatted_text);

    QByteArray c_string = scpiCommand.toLocal8Bit();
    RSDLLibwrt(instrument, c_string.data(), &ibsta, &iberr, &ibcntl);
    if (isError()) {
		log << "Error sending \"" << scpiCommand << "\"" << endl;
        log.flush();
        emit Print(formatted_text);
        PrintStatus();
        emit Print("\n");
        return(false);
    }
    else {
		log << "Sent \"" << scpiCommand <<  "\"" << endl;
        log.flush();
        emit Print(formatted_text);
        PrintStatus();
        emit Print("\n");
        return(true);
    }
}
bool RsibBus::Query(QString scpiCommand, char *buffer, unsigned int bufferSize) {
    if (Write(scpiCommand))
        return(Read(buffer, bufferSize));
    else
        return(false);
}

// Private
bool RsibBus::isError() {
    return((ibsta & IBSTA_ERR) != 0);
}
void RsibBus::PrintStatus() {
    QString formatted_text;
    QTextStream log(&formatted_text);

	// Print ibsta
	log << "ibsta: 0x" << hex << ibsta;
	if ((ibsta & IBSTA_ERR) != 0) log << " (IBSTA_ERR)";
	if ((ibsta & IBSTA_TIMO) != 0) log << " (IBSTA_TIMO)";
	if ((ibsta & IBSTA_CMPL) != 0) log << " (IBSTA_CMPL)";
	log << endl;

	// Print iberr
	log << "iberr: " << dec << iberr;
	if (isError()) {
		if ((iberr & IBERR_DEVICE_REGISTER) != 0) log << " (IBERR_DEVICE_REGISTER)";
		if ((iberr & IBERR_CONNECT) != 0) log << " (IBERR_CONNECT)";
		if ((iberr & IBERR_NO_DEVICE) != 0) log << " (IBERR_NO_DEVICE)";
		if ((iberr & IBERR_MEM) != 0) log << " (IBERR_MEM)";
		if ((iberr & IBERR_TIMEOUT) != 0) log << " (IBERR_TIMEOUT)";
		if ((iberr & IBERR_BUSY) != 0) log << " (IBERR_BUSY)";
		if ((iberr & IBERR_FILE) != 0) log << " (IBERR_FILE)";
		if ((iberr & IBERR_UNKNOWN) != 0) log << " (IBERR_UNKNOWN)";
	}
	log << endl;

	// Print ibcntl
	log << "ibcntl: " << ibcntl << " (bytes)" << endl;

    // Print
    log.flush();
    emit Print(formatted_text);
}
void RsibBus::NullTerminateRead(char *buffer, unsigned long bufferSize) {
	// Null-terminate string
	if (ibcntl < bufferSize)
		buffer[ibcntl] = '\0';
	else
		buffer[bufferSize - 1] = '\0'; // Could overwrite last byte?
}
QString RsibBus::ToTruncatedString(char *buffer) {
    QString formatted_text;
    QTextStream log(&formatted_text);

    log << "Received \"";
    if (ibcntl <= MAX_PRINT)
        log << buffer;
    else {
        char read[MAX_PRINT + 1];
        sprintf(read, "%.*s", MAX_PRINT, buffer);
        log << read << "...";
    }
    log  <<  "\"" << endl;

    return(formatted_text);
}
