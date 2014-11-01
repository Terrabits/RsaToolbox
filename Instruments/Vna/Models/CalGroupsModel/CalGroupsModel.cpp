#include "CalGroupsModel.h"
using namespace RsaToolbox;


#include <QDebug>


CalGroupsModel::CalGroupsModel(QObject *parent) :
    QAbstractListModel(parent)
{
    _vna = NULL;
    _vnaModel = NULL;
    _calGroups = 0;
}

void CalGroupsModel::setVnaModel(VnaModel *model) {
    if (_vnaModel == model)
        return;

    beginResetModel();
    if (_vnaModel != NULL) {
        QObject::disconnect(_vnaModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)),
                            this, SLOT(vnaDataChanged(QModelIndex,QModelIndex)));
        QObject::disconnect(_vnaModel, SIGNAL(modelAboutToBeReset()),
                            this, SIGNAL(modelAboutToBeReset()));
        QObject::disconnect(_vnaModel, SIGNAL(modelReset()),
                            this, SLOT(vnaModelReset()));
        QObject::disconnect(_vnaModel, SIGNAL(modelReset()),
                            this, SIGNAL(modelReset()));
    }
    _vna = NULL;
    _vnaModel = model;
    if (_vnaModel != NULL) {
        _vna = _vnaModel->vna();
        if (!isMissingRef() && isVnaConnected())
            _calGroups = _vna->calGroups().size();
        else
            _calGroups = 0;
        QObject::connect(_vnaModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)),
                            this, SLOT(vnaDataChanged(QModelIndex,QModelIndex)));
        QObject::connect(_vnaModel, SIGNAL(modelAboutToBeReset()),
                            this, SIGNAL(modelAboutToBeReset()));
        QObject::connect(_vnaModel, SIGNAL(modelReset()),
                            this, SLOT(vnaModelReset()));
        QObject::connect(_vnaModel, SIGNAL(modelReset()),
                            this, SIGNAL(modelReset()));
    }
    endResetModel();
}
VnaModel *CalGroupsModel::vnaModel() const {
    return _vnaModel;
}

int CalGroupsModel::rowCount(const QModelIndex &parent) const {
    if (isMissingRef())
        return 0;
    if (parent.isValid())
        return 0;
    if (!isVnaConnected())
        return 0;
    // Else
    return _vna->calGroups().size();
}
int CalGroupsModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return -1;
    // Else
    return COLUMNS;
}

Qt::ItemFlags CalGroupsModel::flags(const QModelIndex &index) const {
    if (isMissingRef())
        return Qt::NoItemFlags;
    if (!index.isValid())
        return Qt::NoItemFlags;
    if (!hasIndex(index.row(), index.column(), index.parent()))
        return Qt::NoItemFlags;

    return QAbstractListModel::flags(index);
}
QVariant CalGroupsModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (section < 0 || section >= COLUMNS)
        return QVariant();
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return QVariant();

    return "Cal Groups";
}

QModelIndex CalGroupsModel::index(int row, int column, const QModelIndex &parent) const {
    if (isMissingRef())
        return QModelIndex();
    if (parent.isValid())
        return QModelIndex();
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    // Else
    return createIndex(row, column);
}
QModelIndex CalGroupsModel::parent(const QModelIndex &child) const {
    Q_UNUSED(child);
    return QModelIndex();
}
QVariant CalGroupsModel::data(const QModelIndex &index, int role) const {
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

    QStringList calGroups = _vna->calGroups();
    if (row < calGroups.size())
        return calGroups[row];
    else
        return QVariant();
}

void CalGroupsModel::reset() {
    setVnaModel(NULL);
}

void CalGroupsModel::vnaDataChanged(QModelIndex topLeft, QModelIndex bottomRight) {
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

    uint calGroups = 0;
    if (isVnaConnected())
        calGroups = _vna->calGroups().size();
    if (calGroups > _calGroups) {
        beginInsertRows(QModelIndex(), _calGroups, calGroups-1);
        _calGroups = calGroups;
        endInsertRows();
    }
    else if (calGroups < _calGroups) {
        beginRemoveRows(QModelIndex(), calGroups, _calGroups-1);
        _calGroups = calGroups;
        endRemoveRows();
    }
}
void CalGroupsModel::vnaModelReset() {
    _vna = _vnaModel->vna();
}

bool CalGroupsModel::isMissingRef() const {
    if (_vna == NULL)
        return true;
    if (_vnaModel == NULL)
        return true;
    // Else
    return false;
}
bool CalGroupsModel::isVnaConnected() const {
    QModelIndex index = _vnaModel->index(0, VnaModel::CONNECTED_COLUMN);
    return _vnaModel->data(index, Qt::DisplayRole).toBool();
}
