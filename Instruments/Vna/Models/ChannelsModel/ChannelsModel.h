#ifndef CHANNELSMODEL_H
#define CHANNELSMODEL_H


#include "VnaModel.h"

#include "Vna.h"

#include <QSharedPointer>
#include <QAbstractTableModel>


namespace RsaToolbox {

class ChannelsModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ChannelsModel(QObject *parent = 0);

    enum COLUMNS {
        INDEX_COLUMN = 0,
        NAME_COLUMN,
        CAL_STATUS_COLUMN,
        IS_FREQ_SWEEP_COLUMN,
        FREQ_RANGE_COLUMN,
        POINTS_COLUMN,
        IF_BW_COLUMN,
        POWER_COLUMN,
        AVERAGING_COLUMN
    };
    static const int COLUMNS = 9;

    void setVnaModel(VnaModel *model);
    VnaModel *vnaModel() const;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    QVariant data(const QModelIndex &index, int role) const;
//    bool setData(const QModelIndex &index, const QVariant &value, int role);

signals:
//    void errorMessage(QString message);

public slots:
    void reset();

private slots:
    void vnaReset();
    void vnaDataChanged(QModelIndex topLeft, QModelIndex bottomRight);

private:
    bool isMissingRef() const;
    bool isVnaConnected() const;
    RsaToolbox::Vna *_vna;
    VnaModel *_vnaModel;
    uint _channels;

    bool isFreqSweep(RsaToolbox::VnaChannel &channel) const;
    QString FrequencyRange(RsaToolbox::VnaLinearSweep &sweep) const;
    QString iFBw(RsaToolbox::VnaLinearSweep &sweep) const;
    QString power(RsaToolbox::VnaLinearSweep &sweep) const;
};
} // RsaToolbox


#endif // CHANNELSMODEL_H
