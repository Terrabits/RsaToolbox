#ifndef VISA_BUS_H
#define VISA_BUS_H

// RsaToolbox:
#include "GenericBus.h"

// NI-VISA
#include "visa.h"
#define FILENAME "visa32"

// Qt
#include <QObject>
#include <QString>
#include <QTextStream>
#include <QLibrary>


namespace RsaToolbox {

class VisaBus : public GenericBus {
private: Q_OBJECT

public:
    VisaBus(QObject *parent = 0);
    VisaBus(ConnectionType connectionType, QString address,
            uint bufferSize_B = 500, uint timeout_ms = 1000,
            QObject *parent = 0);
    ~VisaBus();

    static bool isVisaPresent();
    bool isOpen() const;

    void setTimeout(uint time_ms);

public slots:
    bool lock();
    bool unlock();
    bool local();
    bool remote();

    void printStatus() const;

protected:
    bool _read(char *buffer, uint bufferSize);
    bool _write(QString scpiCommand);

    bool _binaryRead(char *buffer, uint bufferSize,
                     uint &bytesRead);
    bool _binaryWrite(QByteArray scpiCommand);

private:
    void printStatus(QTextStream &stream) const;

    // Function pointers
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

    // Visa access resources
    ViStatus _status;
    ViSession _resourceManager;
    ViSession _instrument;
    ViUInt32 _bytesRead;
    static const uint MAX_PRINT = 100;

    // VisaBus
    void notConnected();
    void retrieveFunctors();
    bool isError();
    void terminateCString(char *buffer, uint bufferSize);
    static QString truncateCString(const char *buffer);
};
}


#endif


