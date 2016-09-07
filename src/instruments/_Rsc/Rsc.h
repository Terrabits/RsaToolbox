#ifndef RSC_H
#define RSC_H


// Rsa
#include "Definitions.h"
#include "GenericBus.h"
#include "Log.h"

// Qt
#include <QObject>
#include <QScopedPointer>
#include <QVector>
#include <QString>
#include <QStringList>


namespace RsaToolbox {

enum RscCalibrationState {
    AF_RSC_CAL,
    FULL_RSC_CAL,
    OFF_RSC_CAL,
    OFS_RSC_CAL
};

enum RscModel {
    RSC_02_MODEL,
    RSC_03_MODEL,
    RSC_04_MODEL,
    RSC_05_MODEL,
    RSC_13_MODEL,
    RSC_14_MODEL,
    RSC_15_MODEL,
    RSC_Z405_MODEL,
    RSC_Z675_MODEL,
    RSC_UNKNOWN_MODEL
};

QString RscCalState_To_String(RscCalibrationState state);
RscCalibrationState Scpi_To_RscCalState(QString scpi);

QString ToString(RscModel model);
RscModel Scpi_to_RscModel(QString scpi);

class Rsc : public QObject
{
    Q_OBJECT
public:
    explicit Rsc();
    explicit Rsc(ConnectionType connection_type, QString address, uint timeout_ms, QObject *parent = 0);
    ~Rsc();

    void ConnectLog(Log &log);
    void DisconnectLog();

signals:
    void Print(QString formatted_text);

public:
    QString GetIdString();
    RscModel GetModel();
    QString GetSerialNumber();
    QString GetFirmwareVersion();

    bool isConnected();
    bool isOperationComplete();
    bool isError();
    bool isCorrectionEnabled();
    bool isCorrectionDisabled();
    bool isBaseUnit();

    void ClearErrors();

    QVector<QStringList> GetAvailableUnits();
    uint GetUnitIndex();
    double GetAttenuation_dB();
    RscCalibrationState GetUserCalibrationState();
    double GetMinimumFrequency_Hz();
    double GetMaximumFrequency_Hz();
    double GetMaximumPower_dBm();
    double GetMaximumAttenuation_dB();
    double GetStepSize_dB();

public slots:
    void EnableCorrection(bool isEnabled = true);
    void DisableCorrection(bool isDisabled = true);

    void SetUnitIndex(uint index);
    void SetAttenuation(double value);
    void SetUserCalibrationState(RscCalibrationState state);

    void LoadUserCalibrationFile(QString filename);

private:
    QString id_string;
    QScopedPointer<RsaToolbox::GenericBus> bus;
    Log *log;
    RscModel model;
    QString serial_no;
    QString firmware_version;
    uint unit_index;

    void GetInstrumentInfo();
    void PrintInstrumentInfo();
};

}

#endif // RSC_H
