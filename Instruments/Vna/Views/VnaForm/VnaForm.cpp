#include "VnaForm.h"
#include "ui_VnaForm.h"
using namespace RsaToolbox;


#include <QDebug>


VnaForm::VnaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VnaForm)
{
    ui->setupUi(this);

    QObject::connect(ui->connect, SIGNAL(clicked()),
                     this, SLOT(submit()));
}
VnaForm::~VnaForm()
{
    delete ui;
}

SharedVnaModel VnaForm::model() const {
    return _model;
}
void VnaForm::setModel(SharedVnaModel model) {

    if (!_model.isNull()) {
        QObject::disconnect(_model.data(), SIGNAL(dataChanged(QModelIndex,QModelIndex)),
                         this, SLOT(dataChanged(QModelIndex,QModelIndex)));
        QObject::disconnect(_model.data(), SIGNAL(error(QString)),
                            this, SLOT(displayError(QString)));
    }

    _model = model;
    dataChanged(QModelIndex(), QModelIndex());
    if (!_model.isNull()) {
        QObject::connect(_model.data(), SIGNAL(dataChanged(QModelIndex,QModelIndex)),
                         this, SLOT(dataChanged(QModelIndex,QModelIndex)));
        QObject::connect(_model.data(), SIGNAL(error(QString)),
                            this, SLOT(displayError(QString)));
    }
}

void VnaForm::displayError(QString message) {
    qDebug() << "VnaForm::displayError" << message;
    ui->error->showMessage(message, 5000);
}

void VnaForm::submit() {
    qDebug() << "VnaForm::submit";
    if (_model == 0)
        return;

    ui->error->clearMessage();
    bool isConnect = !ui->connect->connected();
    if (isConnect) {
        _model->setData(typeIndex(), ui->connectionType->currentIndex(), Qt::EditRole);
        _model->setData(addressIndex(), ui->address->text(), Qt::EditRole);
    }
    _model->setData(connectedIndex(), isConnect, Qt::EditRole);
}
void VnaForm::dataChanged(QModelIndex topLeft, QModelIndex bottomRight) {
    Q_UNUSED(topLeft);
    Q_UNUSED(bottomRight);
    if (_model == 0)
        return;

    Qt::ItemDataRole role = Qt::DisplayRole;
    bool isConnected = _model->data(connectedIndex(), role).toBool();
    ui->connect->setConnected(isConnected);
    ui->connectionType->setEnabled(!isConnected);
    ui->address->setEnabled(!isConnected);

    QVariant value;
    value = _model->data(typeIndex(), role);
    if (value.isValid())
        ui->connectionType->setCurrentIndex(value.toInt());
    ui->address->setText(_model->data(addressIndex(), role).toString());
    if (isConnected) {
        ui->make->setText(_model->data(makeIndex(), role).toString());
        ui->make->setEnabled(true);
        ui->model->setText(_model->data(modelIndex(), role).toString());
        ui->model->setEnabled(true);
        ui->serial->setText(_model->data(serialIndex(), role).toString());
        ui->serial->setEnabled(true);
        ui->firmware->setText(_model->data(firmwareIndex(), role).toString());
        ui->firmware->setEnabled(true);
        ui->frequency->setText(_model->data(freqIndex(), role).toString());
        ui->frequency->setEnabled(true);
        ui->power->setText(_model->data(powerIndex(), role).toString());
        ui->power->setEnabled(true);
    }
    else {
        ui->make->clear();
        ui->make->setDisabled(true);
        ui->model->clear();
        ui->model->setDisabled(true);
        ui->serial->clear();
        ui->serial->setDisabled(true);
        ui->firmware->clear();
        ui->firmware->setDisabled(true);
        ui->frequency->clear();
        ui->frequency->setDisabled(true);
        ui->power->clear();
        ui->power->setDisabled(true);
    }
}

QModelIndex VnaForm::index(VnaModel::COLUMN column) {
    return _model->index(0, column);
}
QModelIndex VnaForm::typeIndex() {
    return index(VnaModel::CONNECTION_TYPE_COLUMN);
}
QModelIndex VnaForm::addressIndex() {
    return index(VnaModel::ADDRESS_COLUMN);
}
QModelIndex VnaForm::connectedIndex() {
    return index(VnaModel::CONNECTED_COLUMN);
}
QModelIndex VnaForm::makeIndex() {
    return index(VnaModel::MAKE_COLUMN);
}
QModelIndex VnaForm::modelIndex() {
    return index(VnaModel::MODEL_COLUMN);
}
QModelIndex VnaForm::serialIndex() {
    return index(VnaModel::SERIAL_COLUMN);
}
QModelIndex VnaForm::firmwareIndex() {
    return index(VnaModel::FIRMWARE_COLUMN);
}
QModelIndex VnaForm::freqIndex() {
    return index(VnaModel::FREQ_DISPLAY_COLUMN);
}
QModelIndex VnaForm::powerIndex() {
    return index(VnaModel::POWER_DISPLAY_COLUMN);
}
