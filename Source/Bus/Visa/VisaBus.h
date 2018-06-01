#ifndef VISA_BUS_H
#define VISA_BUS_H

// RsaToolbox:
#include "GenericBus.h"

// NI-VISA
#include "visa.h"
#define VISA32 "visa32"
#define RSVISA32 "RsVisa32"

// Qt
#include <QObject>
#include <QString>
#include <QTextStream>
#include <QLibrary>


namespace RsaToolbox {

class VisaBus : public GenericBus {
private: Q_OBJECT

public:
    explicit VisaBus(QObject *parent = 0);
    VisaBus(ConnectionType connectionType, QString address,
            uint bufferSize_B = 500, uint timeout_ms = 1000,
            QObject *parent = 0);
    ~VisaBus();

    static bool isVisaInstalled();

    virtual bool isOpen() const;
    virtual void setTimeout(uint time_ms);
    virtual bool read(char *buffer, uint bufferSize_B);
    virtual bool write(QString scpi);
    virtual bool binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead);
    virtual bool binaryWrite(QByteArray scpi);
    virtual QString status() const;

public slots:
    virtual bool lock();
    virtual bool unlock();
    virtual bool local();
    virtual bool remote();

private:
    // Function pointer typedefs
    typedef ViStatus (_VI_FUNC *StatusDescFuncter   )(ViObject, ViStatus, ViChar _VI_FAR []);
    typedef ViStatus (_VI_FUNC *OpenDefaultRmFuncter)(ViPSession  );
    typedef ViStatus (_VI_FUNC *OpenFuncter  )(ViSession, ViRsrc, ViAccessMode,
                                              ViUInt32, ViPSession);
    typedef ViStatus (_VI_FUNC *GetAttributeFuncter )(ViObject, ViAttr, void _VI_PTR attrValue);
    typedef ViStatus (_VI_FUNC *SetAttributeFuncter )(ViObject, ViAttr, ViAttrState  );
    typedef ViStatus (_VI_FUNC *ReadFuncter  )(ViSession, ViPBuf, ViUInt32, ViPUInt32);
    typedef ViStatus (_VI_FUNC *WriteFuncter )(ViSession, ViBuf, ViUInt32, ViPUInt32 );
    typedef ViStatus (_VI_FUNC *ClearFuncter )(ViSession);
    typedef ViStatus (_VI_FUNC *LockFuncter  )(ViSession, ViAccessMode, ViUInt32,
                                              ViKeyId, ViChar _VI_FAR []);
    typedef ViStatus (_VI_FUNC *UnlockFuncter)(ViSession);
    typedef ViStatus (_VI_FUNC *CloseFuncter )(ViObject );

    // Visa32 interface
    QLibrary visa_library;
    bool                  _isOpen;
    StatusDescFuncter    _viStatusDesc;
    OpenDefaultRmFuncter _viOpenDefaultRM;
    OpenFuncter          _viOpen;
    GetAttributeFuncter  _viGetAttribute;
    SetAttributeFuncter  _viSetAttribute;
    ReadFuncter          _viRead;
    WriteFuncter         _viWrite;
    ClearFuncter         _viClear;
    LockFuncter          _viLock;
    UnlockFuncter        _viUnlock;
    CloseFuncter         _viClose;
    void clearFuncters();
    bool getFuncters();

    // Visa access resources
    ViStatus  _status;
    ViSession _resourceManager;
    ViSession _instrument;
    ViUInt32  _byteCount;
    static const int MAX_PRINT = 100;

    // VisaBus
    bool connectVisa(const QString &dll, const QString &resource);
    static QString resourceString(ConnectionType type, QString address);

    bool isError();
    bool open(const QString &filename, const QString &resource);
    void clear();
};
}


#endif


