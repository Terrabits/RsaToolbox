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
private: Q_OBJECT

public:
    explicit Vna(QObject *parent = 0);
    Vna(GenericBus *bus, QObject *parent = 0);
    Vna(ConnectionType type, QString address, QObject *parent = 0);

    void printInfo();
    void printInfo(QTextStream &stream);

    QRowVector readVector(uint bufferSize_B = 5000, uint timeout_ms = 1000);
    ComplexRowVector readComplexVector(uint bufferSize_B = 5000, uint timeout_ms = 1000);
    QRowVector queryVector(QString scpi, uint bufferSize_B = 5000, uint timeout_ms = 1000);
    ComplexRowVector queryComplexVector(QString scpi, uint bufferSize_B = 5000, uint timeout_ms = 1000);

    // Error handling
    bool isError();
    bool isError(QString &errorString);
    bool isError(QStringList &errors);

    // Sets
//    void SelectSet(QString name);
//    void newSet(QString name);
//    void openSet(QString name);
//    void closeSet(QString name);
//    void closeSets();
//    void saveSet(QString name);
//    void deleteSet(QString name);

//    void startSweeps();

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
    bool isCalKit(NameLabel nameLabel);
    bool isCalKit(QString name, QString label);
    bool isNotCalKit(NameLabel nameLabel);
    bool isNotCalKit(QString name, QString label);
    QVector<NameLabel> calKits();
    QVector<NameLabel> calKits(Connector type);
    QVector<NameLabel> calKits(ConnectorType type);
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
    void startSweeps();

    // Switch Matrix
    uint testPorts();
    bool isSwitchMatrix(uint index = 1);
    uint numberOfSwitchMatrices();
    QVector<uint> switchMatrices();
    void addSwitchMatrix(uint index);
    uint addSwitchMatrix();
    void deleteSwitchMatrix(uint index);
    void deleteSwitchMatrices();
    VnaSwitchMatrix &switchMatrix(uint index = 1);
    VnaSwitchMatrix *takeSwitchMatrix(uint index = 1);

    // Cal Unit
    void isCalUnit(QString id);
    uint numberOfCalUnits();
    QStringList calUnits();
    VnaCalUnit &calUnit(QString id);
    VnaCalUnit *takeCalUnit(QString id);

    // QObject
//    void moveToThread(QThread *thread);

private:
    VnaProperties _properties;
    VnaSettings _settings;
    VnaFileSystem _fileSystem;
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
