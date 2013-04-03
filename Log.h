#ifndef IO_H
#define IO_H

// Qt Library:
#include <QString>
#include <QFile>
#include <QTextStream>

// RsaToolbox:
#include "Definitions.h"

namespace RsaToolbox {
	
    class Log {
	public:

        // Properties
        QString program_name;
        QString version;
        QFile logfile;
        QString path;
        QTextStream q_text_stream;

		// Constructor / Destructor
        Log(QString directory, QString filename, QString program_name, QString version);
        ~Log();

		// Actions
        void ReOpen(QString directory, QString filename, QString program_name, QString version); // Closes current
        void Write(QString text);
        void WriteLine(QString text);

		// Logfile
        void PrintLogHeader();
        void Rename(QString directory, QString filename); // Closes, re-opens and appends to the end

    private:

        // Action helpers
        void PrintInstrumentStatus();
		void PrintTruncatedRead(char *buffer);

		// Logfile helpers
		void PrintTime(void);
        void PrintProgramInfo(QString programName, QString version);
        static void CopyTextfile(QString sourceName, QString destinationName);
	};
}

#endif
