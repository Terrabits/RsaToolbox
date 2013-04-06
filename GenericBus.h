#ifndef GENERIC_BUS_H
#define GENERIC_BUS_H

// RsaToolbox:
#include "Definitions.h"

// Qt
#include <QObject>
#include <QString>


namespace RsaToolbox {
    class GenericBus : QObject {
	public:
		// Instrument connection info
		ConnectionType connectionType;
        QString address;
        short timeout_ms;

        // Constructor
        GenericBus(ConnectionType connectionType, QString address, short timeout_ms);

        // Status
        bool isOpen() = 0;

		// Actions
        virtual bool Lock(void) = 0;
        virtual bool Unlock(void) = 0;
        virtual bool Read(char *buffer, unsigned int bufferSize) = 0;
        virtual bool Write(QString scpiCommand) = 0;
        virtual bool Query(QString scpiCommand, char *buffer, unsigned int bufferSize) = 0;

    signals:
        void Print(QString formatted_text);
	};
}


#endif
