#ifndef GENERIC_BUS_H
#define GENERIC_BUS_H

// RsaToolbox:
#include "Definitions.h"

// Qt
#include <QObject>
#include <QString>


namespace RsaToolbox {
    class GenericBus : public QObject {
    private: Q_OBJECT

	public:
		// Instrument connection info
        ConnectionType connection_type;
        QString address;
        short timeout_ms;

        // Constructor
        GenericBus();
        GenericBus(ConnectionType connection_type, QString address, short timeout_ms);

        // Status
        virtual bool isOpen() = 0;
        virtual void PrintStatus(void) = 0;

		// Actions
        virtual bool Lock(void) = 0;
        virtual bool Unlock(void) = 0;
        virtual bool Read(char *buffer, unsigned int buffer_size) = 0;
        virtual bool Write(QString scpi_command) = 0;
        virtual bool Query(QString scpi_command, char *buffer, unsigned int buffer_size) = 0;

    signals:
        void Print(QString formatted_text);
	};
}


#endif
