#ifndef VNAFORM_H
#define VNAFORM_H

#include "VnaModel.h"

#include <QWidget>
#include <QDataWidgetMapper>


namespace RsaToolbox {

namespace Ui {
class VnaForm;
}
class VnaForm : public QWidget
{
    Q_OBJECT

public:
    explicit VnaForm(QWidget *parent = 0);
    ~VnaForm();

    SharedVnaModel model() const;
    void setModel(SharedVnaModel model);

public slots:
    void displayError(QString message);

private slots:
    void submit();
    void dataChanged(QModelIndex topLeft, QModelIndex bottomRight);

private:
    Ui::VnaForm *ui;

    SharedVnaModel _model;
    QModelIndex index(VnaModel::COLUMN column);
    QModelIndex typeIndex();
    QModelIndex addressIndex();
    QModelIndex connectedIndex();
    QModelIndex makeIndex();
    QModelIndex modelIndex();
    QModelIndex serialIndex();
    QModelIndex firmwareIndex();
    QModelIndex freqIndex();
    QModelIndex powerIndex();
};
} // RsaToolbox


#endif // VNAFORM_H
