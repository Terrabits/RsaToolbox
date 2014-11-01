#include "ChannelsModel.h"
using namespace RsaToolbox;


#include "General.h"
#include "VnaChannel.h"
#include "VnaLinearSweep.h"

#include <QDebug>


ChannelsModel::ChannelsModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    _vna = NULL;
    _vnaModel = NULL;
    _channels = 0;
}

void ChannelsModel::setVnaModel(VnaModel *model) {
    if (_vnaModel == model)
        return;

    beginResetModel();
    if (_vnaModel != NULL) {
        QObject::disconnect(_vnaModel, SIGNAL(modelAboutToBeReset()),
                            this, SIGNAL(modelAboutToBeReset()));
        QObject::disconnect(_vnaModel, SIGNAL(modelReset()),
                            this, SLOT(vnaReset()));
        QObject::disconnect(_vnaModel, SIGNAL(modelReset()),
                            this, SIGNAL(modelReset()));
        QObject::disconnect(_vnaModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)),
                            this, SLOT(vnaDataChanged(QModelIndex,QModelIndex)));
    }
    _channels = 0;
    _vna = NULL;
    _vnaModel = model;
    if (_vnaModel != NULL) {
        _vna = _vnaModel->vna();
        QObject::connect(_vnaModel, SIGNAL(modelAboutToBeReset()),
                            this, SIGNAL(modelAboutToBeReset()));
        QObject::connect(_vnaModel, SIGNAL(modelReset()),
                            this, SLOT(vnaReset()));
        QObject::connect(_vnaModel, SIGNAL(modelReset()),
                            this, SIGNAL(modelReset()));
        QObject::connect(_vnaModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)),
                            this, SLOT(vnaDataChanged(QModelIndex,QModelIndex)));

    }
    if (!isMissingRef() && isVnaConnected())
        _channels = _vna->channels().size();
    endResetModel();
}
VnaModel *ChannelsModel::vnaModel() const {
    return _vnaModel;
}

int ChannelsModel::rowCount(const QModelIndex &parent) const {
    if (isMissingRef())
        return 0;
    if (parent.isValid())
        return 0;
    if (!isVnaConnected())
        return 0;
    // Else
    return _vna->channels().size();
}
int ChannelsModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    // Else
    return COLUMNS;
}

Qt::ItemFlags ChannelsModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::NoItemFlags;
    if (!hasIndex(index.row(), index.column(), index.parent()))
        return Qt::NoItemFlags;

    switch (index.column()) {
    case INDEX_COLUMN:
    case NAME_COLUMN:
    case CAL_STATUS_COLUMN:
    case FREQ_RANGE_COLUMN:
    case POINTS_COLUMN:
    case IF_BW_COLUMN:
    case POWER_COLUMN:
    case AVERAGING_COLUMN:
        return QAbstractTableModel::flags(index);
    default:
        return QAbstractTableModel::flags(index);
    }
}
QVariant ChannelsModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (section < 0 || section >= COLUMNS)
        return QVariant();
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return QVariant();

    switch (section) {
    case INDEX_COLUMN: return "Index";
    case NAME_COLUMN: return "Name";
    case CAL_STATUS_COLUMN: return "Calibration?";
    case IS_FREQ_SWEEP_COLUMN: return "Frequency Sweep?";
    case FREQ_RANGE_COLUMN: return "Frequency Range";
    case POINTS_COLUMN: return "Points";
    case IF_BW_COLUMN: return "IF Bw";
    case POWER_COLUMN: return "Power";
    case AVERAGING_COLUMN: return "Averaging?";
    default: return QVariant();
    }
}

QModelIndex ChannelsModel::index(int row, int column, const QModelIndex &parent) const {
    if (isMissingRef())
        return QModelIndex();
    if (parent.isValid())
        return QModelIndex();
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    // Else
    return createIndex(row, column);
}
QModelIndex ChannelsModel::parent(const QModelIndex &child) const {
    Q_UNUSED(child);
    return QModelIndex();
}
QVariant ChannelsModel::data(const QModelIndex &index, int role) const {
    if (isMissingRef())
        return QVariant();
    if (!index.isValid())
        return QVariant();
    int column = index.column();
    int row = index.row();
    if (!hasIndex(row, column, index.parent()))
        return QVariant();
    if (role != Qt::DisplayRole)
        return QVariant();
    if (!isVnaConnected())
        return QVariant();

    QVector<uint> channels = _vna->channels();
    uint cIndex = channels[row];
    RsaToolbox::VnaChannel channel
            = _vna->channel(cIndex);
    bool isFreqSweep = this->isFreqSweep(channel);
    RsaToolbox::VnaLinearSweep sweep;
    if (isFreqSweep)
        sweep = channel.linearSweep();

    switch (column) {
    case INDEX_COLUMN:
        return cIndex;
    case NAME_COLUMN:
        return channel.name();
    case CAL_STATUS_COLUMN:
        return channel.isCalibrated()?
                    "Yes" : "No";
    case IS_FREQ_SWEEP_COLUMN:
        return isFreqSweep?
                    "Yes" : "No";
    case FREQ_RANGE_COLUMN:
        return isFreqSweep?
                    FrequencyRange(sweep) : QVariant();
    case POINTS_COLUMN:
        return isFreqSweep?
                    sweep.points() : QVariant();
    case IF_BW_COLUMN:
        return isFreqSweep?
                    iFBw(sweep) : QVariant();
    case POWER_COLUMN:
        return isFreqSweep?
                    power(sweep) : QVariant();
    case AVERAGING_COLUMN:
        return isFreqSweep?
                    (channel.averaging().isOn()? "Yes" : "No")
                  : QVariant();
    default: return QVariant();
    }
}

void ChannelsModel::reset() {
    setVnaModel(NULL);
}

void ChannelsModel::vnaReset() {
    _vna = _vnaModel->vna();
    uint channels = 0;
    if (!isMissingRef() && isVnaConnected())
        channels = _vna->channels().size();
    if (channels > _channels) {
        beginInsertRows(QModelIndex(), _channels, channels-1);
        _channels = channels;
        endInsertRows();
    }
    else if (channels < _channels) {
        beginRemoveRows(QModelIndex(), channels, _channels-1);
        _channels = channels;
        endRemoveRows();
    }
}
void ChannelsModel::vnaDataChanged(QModelIndex topLeft, QModelIndex bottomRight) {
    if (isMissingRef())
        return;

    if (!topLeft.isValid() || !bottomRight.isValid())
        return;
    if (topLeft.parent().isValid() || bottomRight.parent().isValid())
        return;
    if (topLeft.row() != 0 || bottomRight.row() != 0)
        return;
    if (topLeft.column() > VnaModel::CONNECTED_COLUMN || bottomRight.column() < VnaModel::CONNECTED_COLUMN)
        return;

    uint channels = 0;
    if (isVnaConnected())
        channels = _vna->channels().size();
    if (channels > _channels) {
        beginInsertRows(QModelIndex(), _channels, channels-1);
        _channels = channels;
        endInsertRows();
    }
    else if (channels < _channels) {
        beginRemoveRows(QModelIndex(), channels, _channels-1);
        _channels = channels;
        endRemoveRows();
    }
}

bool ChannelsModel::isMissingRef() const {
    if (_vna == NULL)
        return true;
    if (_vnaModel == NULL)
        return true;
    // Else
    return false;
}
bool ChannelsModel::isVnaConnected() const {
    QModelIndex index = _vnaModel->index(0, VnaModel::CONNECTED_COLUMN);
    return _vnaModel->data(index, Qt::DisplayRole).toBool();
}

bool ChannelsModel::isFreqSweep(RsaToolbox::VnaChannel &channel) const {
    using namespace RsaToolbox;
    VnaSweepType type = channel.sweepType();
    if (type != LINEAR_SWEEP
            && type != LOG_SWEEP
            && type != SEGMENTED_SWEEP)
        return false;
    else
        return true;
}
QString ChannelsModel::FrequencyRange(RsaToolbox::VnaLinearSweep &sweep) const {
    using namespace RsaToolbox;
    QString text;
    text += formatValue(sweep.start_Hz(), 1, HERTZ_UNITS);
    text += " to ";
    text += formatValue(sweep.stop_Hz(), 1, HERTZ_UNITS);
    return text;
}
QString ChannelsModel::iFBw(RsaToolbox::VnaLinearSweep &sweep) const {
    using namespace RsaToolbox;
    return formatValue(sweep.ifBandwidth_Hz(),1,HERTZ_UNITS);
}
QString ChannelsModel::power(RsaToolbox::VnaLinearSweep &sweep) const {
    using namespace RsaToolbox;
    return formatValue(sweep.power_dBm(), 1, DECIBEL_MILLIWATTS_UNITS);
}
