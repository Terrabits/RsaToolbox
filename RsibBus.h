#ifndef RSIB_BUS_H
#define RSIB_BUS_H

// RsaToolbox:
#include "Definitions.h"
#include "GenericBus.h"

// Qt
#include <QObject>
#include <QString>


namespace RsaToolbox {
    class RsibBus : public GenericBus {
    // private: Q_OBJECT

    public:
        // Instrument Connection info
        short ibsta, iberr;
        unsigned long ibcntl;

        // Constructor, Destructor
        RsibBus();
        RsibBus(ConnectionType connection_type, QString instrument_address, short timeout_ms);
        ~RsibBus();

        // Status
        bool isOpen();
        void PrintStatus(void);

        // Actions
        bool Lock(void);
        bool Unlock(void);
        bool Local(void);
        bool Remote(void);
        bool Read(char *buffer, unsigned int bufferSize);
        bool Write(QString scpiCommand);
        bool Query(QString scpiCommand, char *buffer, unsigned int bufferSize);

    private:
        short instrument;
        static const unsigned long MAX_PRINT = 100;

        bool isError();
        void NullTerminateRead(char *buffer, unsigned long bufferSize);
        QString ToTruncatedString(char *buffer);
    };
}


#endif // RSIB_BUS_H
