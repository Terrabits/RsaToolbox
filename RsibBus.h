#ifndef RSIB_BUS_H
#define RSIB_BUS_H

// RsaToolbox:
#include "Definitions.h"
#include "GenericBus.h"

// Qt
#include <QObject>
#include <QString>


namespace RsaToolbox {
    class RsibBus : GenericBus {
    public:
        short ibsta, iberr;
        unsigned long ibcntl;
        static const unsigned long MAX_PRINT = 100;

        // Constructor, Destructor
        RsibBus(ConnectionType connectionType, QString address, short timeout_ms);
        ~RsibBus();

        // Actions
        bool Lock(void);
        bool Unlock(void);
        bool Read(char *buffer, unsigned int bufferSize);
        bool Write(QString scpiCommand);
        bool Query(QString scpiCommand, char *buffer, unsigned int bufferSize);

    private:
        short instrument;

        bool isError();
        void NullTerminateRead(char *buffer, unsigned long bufferSize);
        QString ToTruncatedString(char *buffer);
        void PrintStatus(void);

    };
}


#endif // RSIB_BUS_H
