#ifndef IO_H
#define IO_H

// C\C++ standard library:
#include <QString>
#include <QFile>
#include <QTextStream>

// RsaToolbox:
#include "Definitions.h"

namespace RsaToolbox {
	
	class IO {
	public:
		// Instrument connection info
		ConnectionType connectionType;
        QString address;
		// Logfile info
        QString filename;
        QString path;
        QTextStream log;
		// RSIB Status, Error and Count/Control buffers
		short ibsta, iberr;
		unsigned long ibcntl;

		// Connection status
		bool isConnected;

		// Constructor / Destructor
        IO(ConnectionType connectionType, QString address, QString filename, QString path, short timeout);
		~IO();

		// Status Methods
		// bool isLocked(void);
		// bool isUnlocked(void);
		bool isError(void);

		// Actions
		//void Lock(void);
		//void Unlock(void);
		void Read(char *buffer, unsigned int bufferSize);
        void Write(QString scpiCommand);
        void Query(QString scpiCommand, char *buffer, unsigned int bufferSize);

		// Logfile
        void AppendThisPath(QString &filename);
        void PrintLogHeader(QString programName, QString version);
        void KeepErrorFile(QString directory);

	private:
		// Instrument handle
		short rsibInstrumentHandle;

        // Action helpers
		void PrintInstrumentStatus();
		void NullTerminateRead(char *buffer, unsigned long bufferSize);
		void PrintTruncatedRead(char *buffer);

		// Logfile helpers
		void PrintTime(void);
        void PrintProgramInfo(QString programName, QString version);
        static void CopyTextfile(QString sourceName, QString destinationName);
	};
}

#endif
