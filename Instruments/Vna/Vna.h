#ifndef VNA_H
#define VNA_H


// Rsa
#include "Definitions.h"
#include "GenericInstrument.h"
#include "Connector.h"
#include "NameLabel.h"
#include "VnaProperties.h"
#include "VnaSettings.h"
#include "VnaFileSystem.h"
#include "VnaSet.h"
#include "VnaCalKit.h"
#include "VnaChannel.h"
#include "VnaCalibrate.h"
#include "VnaTrace.h"
#include "VnaDiagram.h"
#include "VnaSwitchMatrix.h"
#include "VnaCalUnit.h"

// Qt
#include <QString>
#include <QStringList>


namespace RsaToolbox {

class Vna : public GenericInstrument
{
    Q_OBJECT

public:
    explicit Vna(QObject *parent = 0);
    Vna(GenericBus *bus, QObject *parent = 0);
    Vna(ConnectionType type, QString address, QObject *parent = 0);

    using GenericInstrument::printInfo;
    virtual void printInfo(QString &info);

    QRowVector readVector(uint bufferSize_B = 5000, uint timeout_ms = 1000);
    ComplexRowVector readComplexVector(uint bufferSize_B = 5000, uint timeout_ms = 1000);
    QRowVector queryVector(QString scpi, uint bufferSize_B = 5000, uint timeout_ms = 1000);
    ComplexRowVector queryComplexVector(QString scpi, uint bufferSize_B = 5000, uint timeout_ms = 1000);

    // Error handling
    bool isError();
    bool nextError(QString &message);
    bool nextError(int &code, QString &message);
    bool errors(QStringList &messages);
    bool errors(QList<int> &codes, QStringList &messages);

    // Sets
    QStringList sets();
    QString activeSet();
    QString newSet();
    void newSet(const QString &name);
    void openSet(QString filePathName);
    void closeActiveSet();
    void closeSet(const QString &name);
    void closeSets();
    bool saveActiveSet(const QString &filePathName);
    void deleteSet(QString filePathName);
    VnaSet &set(const QString &name = "Set1");

    // Properties
    VnaProperties &properties();
    VnaProperties *takeProperties();

    // Settings
    VnaSettings &settings();
    VnaSettings *takeSettings();

    // File System
    VnaFileSystem &fileSystem();
    VnaFileSystem *takeFileSystem();

    // Cal Kit
    QVector<Connector> connectorTypes();
    bool isConnectorType(Connector type);
    bool isConnectorType(QString userDefinedType);
    bool isConnectorGenderNeutral(Connector type);
    bool isCalKit(NameLabel nameLabel);
    bool isCalKit(QString name, QString label);
    bool isNotCalKit(NameLabel nameLabel);
    bool isNotCalKit(QString name, QString label);
    QVector<NameLabel> calKits();
    QVector<NameLabel> calKits(Connector type);
    QVector<NameLabel> calKits(Connector::Type type);
    QVector<NameLabel> calKits(QString userDefinedConnectorType);
    void importCalKit(QString pathName);
    void exportCalKit(NameLabel calkit, QString pathName);
    void deleteCalKit(NameLabel calkit);
    VnaCalKit &calKit(NameLabel nameLabel);

     // Calibration
    QVector<uint> calibratedChannels();
    VnaCalibrate &calibrate();
    VnaCalibrate *takeCalibrate();

    // Cal Group
//    bool isCalGroup(QString calGroup);
//    bool isNotCalGroup(QString calGroup);
//    void importCalGroup(QString calGroupPathName);
//    void deleteCalGroup(QString calGroup);
    QStringList calGroups();
//    void applyToChannel(uint channelIndex);
//    void applyToChannels();
    // VnaCalGroup &calGroup(QString name);

    // Channel
    bool isChannel(uint index);
    bool isChannel(QString name);
    bool isNotChannel(uint index);
    bool isNotChannel(QString name);
    uint numberOfChannels();
    QVector<uint> channels();
    uint channelId(QString name);
    uint createChannel();
    void createChannel(uint index);
    void deleteChannel(uint index);
    void deleteChannel(QString name);
    void deleteChannels(QVector<uint> indices);
    void deleteChannels();

    VnaChannel &channel(uint index = 1);
    VnaChannel *takeChannel(uint index = 1);
    VnaChannel *takeChannels();

    // Trace
    bool isTrace(QString name);
    uint numberOfTraces();
    QStringList traces();
    void createTrace(QString name, uint channel);
    QString createTrace(uint channel);
    void deleteTrace(QString name);
    void deleteTraces(QStringList traces);
    void deleteTraces();
    VnaTrace &trace(QString name = "Trc1");
    VnaTrace *takeTrace(QString name = "Trc1");
    VnaTrace *takeTraces();

    // Diagram
    bool isDiagram(uint index);
    bool isNotDiagram(uint index);
    uint numberOfDiagrams();
    QVector<uint> diagrams();
    void createDiagram(uint index);
    uint createDiagram();
    void deleteDiagram(uint index);
    void deleteDiagrams(QVector<uint> diagrams);
    void deleteDiagrams();
    void autoscaleDiagrams();
    VnaDiagram &diagram(uint index = 1);
    VnaDiagram *takeDiagram(uint index = 1);
    VnaDiagram *takeDiagrams();

    // Measurement
    uint sweepTime_ms();
    uint calibrationSweepTime_ms();
    void startSweeps();

    // Test ports
    uint testPorts();
    bool isVnaPort(uint testPort);
    uint vnaPort(uint testPort);
    QVector<uint> vnaTestPorts();
    PortMap testPortToVnaMap();

    // Switch matrix
    bool areSwitchMatrices();
    uint switchMatrices();
    bool isSwitchMatrixPort(uint testPort);
    uint switchMatrixWithPort(uint testPort);
    void disconnectSwitchMatrices();
    void removeSwitchMatrices();
    VnaSwitchMatrix &switchMatrix(uint index = 1);
    VnaSwitchMatrix *takeSwitchMatrix(uint index = 1);

    // Cal Unit
    bool isCalUnit(QString id);
    QStringList calUnits();
    VnaCalUnit &calUnit(QString id);
    VnaCalUnit *takeCalUnit(QString id);

    // Pass/Fail
    bool isGlobalLimitsPass();
    bool isGlobalLimitsFail();

private:
    VnaProperties _properties;
    VnaSettings _settings;
    VnaFileSystem _fileSystem;
    VnaSet _set;
    VnaCalKit _calKit;
    VnaCalibrate _calibrate;
    //VnaCalGroup _calGroup;
    VnaChannel _channel;
    VnaTrace _trace;
    VnaDiagram _diagram;
    VnaSwitchMatrix _switchMatrix;
    VnaCalUnit _calUnit;
};
}

#endif // VNA_H
