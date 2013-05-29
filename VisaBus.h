#ifndef VISA_BUS_H
#define VISA_BUS_H

// RsaToolbox:
#include "Definitions.h"
#include "GenericBus.h"

// NI-VISA
#include "visa.h"
#define FILENAME "visa32"

// Qt
#include <QObject>
#include <QString>
#include <QLibrary>


namespace RsaToolbox {

    class VisaBus : public GenericBus {
	public:
        // Constructor
        VisaBus();
        VisaBus(ConnectionType connection_type, QString instrument_address, short timeout_ms);
        ~VisaBus();

        // Status
        static bool isVisaPresent();
        bool isOpen();
        void PrintStatus();

		// Actions
        bool Lock();
        bool Unlock();
        bool Local();
        bool Remote();
        bool Read(char *buffer, unsigned int buffer_size);
        bool Write(QString scpi_command);
        bool Query(QString scpi_command, char *buffer, unsigned int buffer_size);

    private:
        // Function pointers
        typedef ViStatus (_VI_FUNC *StatusDesc_Functer)(ViObject, ViStatus, ViChar _VI_FAR []);
        typedef ViStatus (_VI_FUNC *OpenDefaultRM_Functer)(ViPSession);
        typedef ViStatus (_VI_FUNC *Open_Functer)(ViSession, ViRsrc, ViAccessMode,
                                                  ViUInt32, ViPSession);
        typedef ViStatus (_VI_FUNC *Read_Functer)(ViSession, ViPBuf, ViUInt32, ViPUInt32);
        typedef ViStatus (_VI_FUNC *Write_Functer)(ViSession, ViBuf, ViUInt32, ViPUInt32);
        typedef ViStatus (_VI_FUNC *Clear_Functer)(ViSession);
        typedef ViStatus (_VI_FUNC *Lock_Functer)(ViSession, ViAccessMode, ViUInt32,
                                                  ViKeyId, ViChar _VI_FAR []);
        typedef ViStatus (_VI_FUNC *Unlock_Functer)(ViSession);
        typedef ViStatus (_VI_FUNC *Close_Functer)(ViObject);

        // Visa32 interface
        QLibrary visa_library;
        StatusDesc_Functer _viStatusDesc;
        OpenDefaultRM_Functer _viOpenDefaultRM;
        Open_Functer _viOpen;
        Read_Functer _viRead;
        Write_Functer _viWrite;
        Clear_Functer _viClear;
        Lock_Functer _viLock;
        Unlock_Functer _viUnlock;
        Close_Functer _viClose;

        // Visa access resources
        ViStatus status;
        ViSession resource_manager;
        ViSession instrument;
        static const unsigned long MAX_PRINT = 100;

        // VisaBus
        void UnknownDevice();
        void RetrieveInterface();
        bool isError();
        void NullTerminateRead(char *buffer, unsigned long buffer_size, ViUInt32 read_size);
        QString ToTruncatedString(char *buffer);

	};
}


#endif
