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

    using GenericBus::read;
    using GenericBus::query;
    using GenericBus::binaryRead;
    using GenericBus::binaryQuery;

    bool isOpen() const;
    void setTimeout(uint time_ms);
    bool read(char *buffer, uint bufferSize_B);
    bool write(QString scpi);
    bool binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead);
    bool binaryWrite(QByteArray scpi);
    QString status() const;

public slots:
    bool lock();
    bool unlock();
    bool local();
    bool remote();

private:
    // Function pointer typedefs
    typedef ViStatus (_VI_FUNC *_statusDescFuncter)(ViObject, ViStatus, ViChar _VI_FAR []);
    typedef ViStatus (_VI_FUNC *_openDefaultRmFuncter)(ViPSession);
    typedef ViStatus (_VI_FUNC *_openFuncter)(ViSession, ViRsrc, ViAccessMode,
                                              ViUInt32, ViPSession);
    typedef ViStatus (_VI_FUNC *_getAttributeFuncter)(ViObject, ViAttr, void _VI_PTR attrValue);
    typedef ViStatus (_VI_FUNC *_setAttributeFuncter)(ViObject, ViAttr, ViAttrState);
    typedef ViStatus (_VI_FUNC *_readFuncter)(ViSession, ViPBuf, ViUInt32, ViPUInt32);
    typedef ViStatus (_VI_FUNC *_writeFuncter)(ViSession, ViBuf, ViUInt32, ViPUInt32);
    typedef ViStatus (_VI_FUNC *_clearFuncter)(ViSession);
    typedef ViStatus (_VI_FUNC *_lockFuncter)(ViSession, ViAccessMode, ViUInt32,
                                              ViKeyId, ViChar _VI_FAR []);
    typedef ViStatus (_VI_FUNC *_unlockFuncter)(ViSession);
    typedef ViStatus (_VI_FUNC *_closeFuncter)(ViObject);

    // Visa32 interface
    QLibrary visa_library;
    _statusDescFuncter _viStatusDesc;
    _openDefaultRmFuncter _viOpenDefaultRM;
    _openFuncter _viOpen;
    _getAttributeFuncter _viGetAttribute;
    _setAttributeFuncter _viSetAttribute;
    _readFuncter _viRead;
    _writeFuncter _viWrite;
    _clearFuncter _viClear;
    _lockFuncter _viLock;
    _unlockFuncter _viUnlock;
    _closeFuncter _viClose;
    void getFuncters();

    // Visa access resources
    ViStatus _status;
    ViSession _resourceManager;
    ViSession _instrument;
    ViUInt32 _byteCount;
    static const int MAX_PRINT = 100;

    // VisaBus
    bool connectVisa(const QString &dll, const QString &resource);
    static QString resourceString(ConnectionType type, QString address);
    bool parseResourceString(QString resourceString);

    bool isError();
    void setDisconnected();
};
}


#endif


