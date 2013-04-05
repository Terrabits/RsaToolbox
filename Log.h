#ifndef IO_H
#define IO_H

// Qt Library:
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>

// RsaToolbox:
#include "Definitions.h"

// Qt
#include <QObject>
#include <QTextStream>


namespace RsaToolbox {
	
    class Log : QObject {
	public:
        // Properties
        QString program_name;
        QString program_version;
        QDir path;
        QFile file;
        QTextStream stream;

		// Constructor / Destructor
        Log(QDir path, QString filename, QString program_name, QString program_version);
        ~Log();

		// Actions
        void Open();
        void Close();
        void PrintProgramHeader();
        void Rename(QString filename);

        // Operators
        template <class T>
        QTextStream& operator<<(T item) {
            stream << item;
            return(stream);
        }

    public slots:
        void Print(QString formatted_text);

    private:
        // Action helpers
        void PrintInstrumentStatus();
		void PrintTruncatedRead(char *buffer);

		// Logfile helpers
		void PrintTime(void);
        void PrintProgramInfo(QString programName, QString version);
	};
}


#endif
