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
	
    class Log : public QObject {
    private: Q_OBJECT

	public:
        // Properties
        QString program_name;
        QString program_version;
        QDir path;
        QFile file;
        QTextStream stream;

		// Constructor / Destructor
        Log(void);
        Log(QDir path, QString filename, QString program_name, QString program_version);
        ~Log();

        // Status
        bool isOpen(void);
        bool isClosed(void);

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

	};
}


#endif
