#ifndef VnaChannel_H
#define VnaChannel_H


// RsaToolbox
#include "Definitions.h"
#include "BalancedPort.h"

#include "VnaUserDefinedPort.h"
#include "VnaLinearSweep.h"
#include "VnaLogSweep.h"
#include "VnaSegmentedSweep.h"
#include "VnaPowerSweep.h"
#include "VnaCwSweep.h"
#include "VnaTimeSweep.h"
#include "VnaAveraging.h"
#include "VnaCalibrate.h" // ?
// * #include "VnaCorrections.h"
// * See note at end of file


// Qt
#include <QString>
#include <QStringList>
#include <QVector>
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaCorrections;

class VnaChannel : public QObject
{
    Q_OBJECT

public:

    enum class SweepType {
        Linear,
        Log,
        Segmented,
        Power,
        Cw,
        Time
    };

    explicit VnaChannel(QObject *parent = 0);
    VnaChannel(VnaChannel const &other);
    VnaChannel(Vna *_vna, uint index, QObject *parent = 0);

    uint index();
    QString name();
    void setName(QString name);

    QVector<uint> diagrams();
    QStringList traces();

    // Triggering
    void startSweep();
    uint numberOfSweeps();
    void setNumberOfSweeps(uint sweeps);
    bool isSweepOn();
    bool isSweepOff();
    void sweepOn(bool isOn = true);
    void sweepOff(bool isOff = true);
    bool isContinuousSweep();
    bool isManualSweep();
    void continuousSweepOn(bool isOn = true);
    void manualSweepOn(bool isOn = true);

    uint sweepCount();
    void setSweepCount(uint count = 1);

    // Sweep
    bool isFrequencySweep();
    bool isLinearSweep();
    bool isLogarithmicSweep();
    bool isSegmentedSweep();
    bool isPowerSweep();
    bool isCwSweep();
    bool isTimeSweep();
    SweepType sweepType();
    void setSweepType(SweepType sweepType);
    void setFrequencies(QRowVector values, SiPrefix prefix = SiPrefix::None);

    VnaLinearSweep &linearSweep();
    VnaLinearSweep *takeLinearSweep();
    VnaLogSweep &logSweep();
    VnaLogSweep *takeLogSweep();
    VnaSegmentedSweep &segmentedSweep();
    VnaSegmentedSweep *takeSegmentedSweep();
    VnaPowerSweep &powerSweep();
    VnaPowerSweep *takePowerSweep();
    VnaCwSweep &cwSweep();
    VnaCwSweep *takeCwSweep();
    VnaTimeSweep &timeSweep();
    VnaTimeSweep *takeTimeSweep();

    // Balanced ports
    uint numberOfLogicalPorts();
    bool isSingleEndedPort(uint logicalPort);
    uint physicalPort(uint logicalPort);
    bool isBalancedPort(uint logicalPort);
    void physicalPorts(uint logicalPort, uint &physicalPort1, uint &physicalPort2);
    void createSingleEndedPort(uint logicalPort, uint physicalPort);
    void createBalancedPort(uint logicalPort, uint physicalPort1, uint physicalPort2);
    void deleteBalancedPort(uint logicalPort);
    void deleteBalancedPorts();

    // User-defined ports
    bool isUserDefinedPort(uint physicalPort);
    bool isNotUserDefinedPort(uint physicalPort);
    VnaUserDefinedPort userDefinedPort(uint physicalPort);
    void setUserDefinedPort(uint physicalPort, VnaUserDefinedPort userDefinedPort);
    void deleteUserDefinedPort(uint physicalPort);
    void deleteUserDefinedPorts();

    // Averaging
    VnaAveraging &averaging();

    // Corrections
    bool isCalibrated();
    bool isCalGroup();
    void saveCalibration(QString calGroup);
    void setCalGroup(QString calGroup);
    QString calGroup();
    QString calGroupFile();
    void dissolveCalGroup();
    VnaCorrections &corrections();
    VnaCalibrate &calibrate();
    VnaCalibrate *takeCalibrate();

    // Power corrections
    // bool isPowerCalibrated();
    // VnaPowerCorrections &powerCorrections();
    // VnaPowerCalibrate &powerCalibrate();

    void operator=(VnaChannel const &other);

//    void moveToThread(QThread *thread);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    uint _index;
    QScopedPointer<VnaLinearSweep> _frequencySweep;
    QScopedPointer<VnaLogSweep> _logSweep;
    QScopedPointer<VnaSegmentedSweep> _segmentedSweep;
    QScopedPointer<VnaPowerSweep> _powerSweep;
    QScopedPointer<VnaCwSweep> _cwSweep;
    QScopedPointer<VnaTimeSweep> _timeSweep;
    QScopedPointer<VnaAveraging> _averaging;
    QScopedPointer<VnaCorrections> _corrections;
    QScopedPointer<VnaCalibrate> _calibrate;

    bool isFullyInitialized() const;
    QStringList zvaTraces();

    // Balanced Ports
    QVector<uint> physicalPorts(uint logicalPort);

    // User-defined ports
    bool isUserDefinedPortOn(uint physicalPort);
    bool isUserDefinedPortOff(uint physicalPort);
    void userDefinedPortOn(uint physicalPort);
    void userDefinedPortOff(uint physicalPort);
};
} // RsaToolbox

Q_DECLARE_METATYPE(RsaToolbox::VnaChannel::SweepType)

// Classes that depend
// on VnaChannel::SweepType :
// Cannot forward declare class,
// Must provide definition first.
// This unusual include placement
// allows reference in
// child classes and header
// inclusion in parent.
#include "VnaCorrections.h"


#endif // VnaChannel_H
