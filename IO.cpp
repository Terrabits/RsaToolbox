
// RsaToolbox includes
#include "IO.h"
#include "Definitions.h"
using namespace RsaToolbox;

// Instrument Communications
#include <Windows.h>
#include <rsib.h>

// C++ Standard Library
#include <ctime>
using namespace std;

// Constructor, Destructor
IO::IO(ConnectionType connectionType, string address, string filename, string path, short timeout) {
	// RSIB Status, Error and Count/Control buffers
	short ibsta, iberr;
	unsigned long ibcntl;

	// Connect to instrument
	// Only handles TCPIP via RSIB at the moment
	if (connectionType == TCPIP_CONNECTION) {
		rsibInstrumentHandle = RSDLLibfind((char *)address.c_str(), &ibsta, &iberr, &ibcntl); }
	else
		rsibInstrumentHandle = -1;

	// Check connection
	if (rsibInstrumentHandle != -1)
		isConnected = true;
	else
		isConnected = false;

	// Set timeout
	if (isConnected)
		RSDLLibtmo(rsibInstrumentHandle, timeout, &ibsta, &iberr, &ibcntl);

	// Setup logfile
	this->filename = filename;
	if (path.length() != 0 && path[path.length() - 1] != '\\')
		path = path + "\\";
	this->path = path;
	AppendThisPath(filename);
	log.open(filename);


}
IO::~IO() {
	log.close();
	if (isConnected) {
		RSDLLibloc(rsibInstrumentHandle, &ibsta, &iberr, &ibcntl);
		RSDLLibonl(rsibInstrumentHandle, 0, &ibsta, &iberr, &ibcntl); }


}

// Actions + Helpers
void IO::Read(char *buffer, unsigned int bufferSize) {
	RSDLLilrd(rsibInstrumentHandle, buffer, bufferSize, &ibsta, &iberr, &ibcntl);
	if (isError())
		{ log << "Error reading from instrument." << endl; }
	else {
		NullTerminateRead(buffer, bufferSize);
		PrintTruncatedRead(buffer);
	}
	PrintInstrumentStatus();
	log << endl;


}
void IO::Write(std::string scpiCommand) {
	RSDLLibwrt(rsibInstrumentHandle, (char *)scpiCommand.c_str(), &ibsta, &iberr, &ibcntl);
	if (isError())
		log << "Error sending \"" << scpiCommand << "\"" << endl;
	else
		log << "Sent \"" << scpiCommand <<  "\"" << endl;
		
	PrintInstrumentStatus();
	log << endl;


}
void IO::Query(std::string scpiCommand, char *buffer, unsigned int bufferSize) {
	Write(scpiCommand);
	if (!isError())
		Read(buffer, bufferSize);


}
void IO::PrintInstrumentStatus() {
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


}
void IO::NullTerminateRead(char *buffer, unsigned long bufferSize) {
	// Null-terminate string
	if (ibcntl < bufferSize)
		buffer[ibcntl] = '\0';
	else
		buffer[bufferSize - 1] = '\0'; // Could overwrite last byte?


}
void IO::PrintTruncatedRead(char *buffer) {
		const unsigned long MAX_PRINT = 100;
		log << "Received \"";
		if (ibcntl <= MAX_PRINT)
			log << buffer;
		else {
			char read[MAX_PRINT + 1];
			sprintf(read, "%.*s", MAX_PRINT, buffer);
			log << read << "...";
		}
		log  <<  "\"" << endl;


}

// Logfile
void IO::AppendThisPath(string &filename) {
	filename = path + filename;

}
void IO::PrintLogHeader(string programName, string version) {
	string filename = this->filename;
	AppendThisPath(filename);
	if (!log.is_open())
		log.open(filename);
	const unsigned long BUFFER_SIZE = 200;
	string scpi_id = "*IDN?";
	char id[BUFFER_SIZE];
	Query(scpi_id, id, BUFFER_SIZE);
	string scpi_options = "*OPT?";
	char options[BUFFER_SIZE];
	Query(scpi_options, options, BUFFER_SIZE);
	// Re-open to clear log of last command.
	log.close(); log.open(filename);
	PrintProgramInfo(programName, version);
	log << "Instrument ID: " << id << endl;
	log << "Options: " << options << endl << endl;
	PrintTime();
	log << endl;


}
void IO::KeepErrorFile(string directory) {
	time_t currentTime;
	time(&currentTime);
	tm *timeinfo;
	timeinfo = localtime (&currentTime);
	char timestamp[16];
	strftime(timestamp, 16, "%Y%m%d %H%M%S", timeinfo);
	string filename = string("ERRORLOG ") + timestamp + ".txt";
	if (*(directory.end() - 1) != '\\')
		filename = directory + "\\" + filename;
	CopyTextfile(filename, filename);


}

// Get Instrument Status
bool IO::isError() {
	return((ibsta & IBSTA_ERR) != 0);


}

// Logfile Helpers
void IO::PrintTime(void) {
	time_t currentTime;
	time(&currentTime);
	log << ctime(&currentTime) << endl;


}
void IO::PrintProgramInfo(string programName, string version) {
	log << programName << " Version " << version << endl;
	log << "Rohde & Schwarz America, Inc." << endl;


}
void IO::CopyTextfile(string sourceName, string destinationName) {
	ifstream source(sourceName);
	ofstream destination(destinationName);
	destination << source.rdbuf();
	source.close();
	destination.close();


}
