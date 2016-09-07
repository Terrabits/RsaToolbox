#ifndef CALGROUPSMODEL_H
#define CALGROUPSMODEL_H

#include "VnaModel.h"

#include <QAbstractListModel>


namespace RsaToolbox {

class CalGroupsModel;
typedef QSharedPointer<CalGroupsModel> SharedCalGroupsModel;

class CalGroupsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CalGroupsModel(QObject *parent = 0);

    static const int COLUMNS = 1;

    void setVnaModel(VnaModel *model);
    VnaModel *vnaModel() const;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    QVariant data(const QModelIndex &index, int role) const;

signals:

public slots:
    void reset();

private slots:
    void vnaDataChanged(QModelIndex topLeft, QModelIndex bottomRight);
    void vnaModelReset();

private:
    uint _calGroups;

    bool isMissingRef() const;
    bool isVnaConnected() const;
    RsaToolbox::Vna *_vna;
    VnaModel *_vnaModel;
};
} // RsaToolbox


#endif // CALGROUPSMODEL_H
