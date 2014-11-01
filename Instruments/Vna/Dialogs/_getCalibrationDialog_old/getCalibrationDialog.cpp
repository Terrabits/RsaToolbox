#include "getCalibrationDialog.h"
#include "ui_getCalibrationDialog.h"


// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QDebug>


getCalibrationDialog::getCalibrationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getCalibrationDialog)
{
    ui->setupUi(this);
    clearDefault();
    clearSelection();
    _isOkClicked = false;
}
getCalibrationDialog::getCalibrationDialog(Vna &vna, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getCalibrationDialog)
{
    ui->setupUi(this);
    clearDefault();
    clearSelection();
    _isOkClicked = false;
    update(vna);
}
getCalibrationDialog::getCalibrationDialog(QVector<uint> calibratedChannels, QStringList calGroups, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getCalibrationDialog)
{
    ui->setupUi(this);
    clearDefault();
    clearSelection();
    _isOkClicked = false;
    update(calibratedChannels, calGroups);
}

getCalibrationDialog::~getCalibrationDialog() {
    delete ui;
}

QVector<uint> getCalibrationDialog::calibratedChannels() {
    return(_channels);
}
void getCalibrationDialog::selectChannel(uint index) {
    if (_channels.contains(index)) {
        clearSelection();
        _isCalibrationSelected = true;
        _isCalibratedChannel = true;
        _channel = index;
    }
}
QStringList getCalibrationDialog::calGroups() {
    return(_calGroups);
}
void getCalibrationDialog::selectCalGroup(QString name) {
    if (_calGroups.contains(name, Qt::CaseInsensitive)) {
        clearSelection();
        _isCalibrationSelected = true;
        _isCalGroup = true;
        _calGroup = name;
    }
}
void getCalibrationDialog::selectDefault() {
    if (_isDefaultChannel)
        selectChannel(_defaultChannel);
    else if (_isDefaultCalGroup)
        selectCalGroup(_defaultCalGroup);
}
void getCalibrationDialog::clearSelection() {
    _isCalibrationSelected = false;
    _isCalibratedChannel = false;
    _isCalGroup = false;
}
void getCalibrationDialog::update(Vna &vna) {
    update(vna.calibratedChannels(), vna.calGroups());
}
void getCalibrationDialog::update(QVector<uint> calibratedChannels, QStringList calGroups) {
    _channels = calibratedChannels;
    QStringList channelList = channelLabels(calibratedChannels);
    ui->channelList->clear();
    ui->channelList->addItems(channelList);

    _calGroups = calGroups;
    ui->calPoolList->clear();
    ui->calPoolList->addItems(calGroups);

    _selectDefaultOnGui();
}

void getCalibrationDialog::_unselectGui() {
    ui->channelList->clearSelection();
    ui->calPoolList->clearSelection();
}
void getCalibrationDialog::clearDefault() {
    _isDefaultChannel = false;
    _isDefaultCalGroup = false;
}
void getCalibrationDialog::setDefaultChannel(uint channel) {
    clearDefault();
    _isDefaultChannel = true;
    _defaultChannel = channel;
}
void getCalibrationDialog::setDefaultCalGroup(QString calGroup) {
    clearDefault();
    _isDefaultCalGroup = true;
    _defaultCalGroup = calGroup;
}
void getCalibrationDialog::_selectDefaultOnGui() {
    // User choice is present
    if (_isCalibrationSelected) {
        if (_isCalibratedChannel)
            _selectChannelOnGui(_channel);
        else if (_isCalGroup)
            _selectCalGroupOnGui(_calGroup);
    }
    else if (_isDefaultChannel)
        _selectChannelOnGui(_defaultChannel);
    else if (_isDefaultCalGroup)
        _selectCalGroupOnGui(_defaultCalGroup);
}
void getCalibrationDialog::_selectChannelOnGui(uint index) {
    if (_channels.contains(index)) {
        int i = _channels.indexOf(index);
        ui->channelList->item(i)->setSelected(true);
    }

}
void getCalibrationDialog::_selectCalGroupOnGui(QString name) {
    name = name.toLower();
    name.remove(".cal");
    if (_calGroups.contains(name, Qt::CaseInsensitive)) {
        int size = _calGroups.size();
        for (int i = 0; i < size; i++) {
            if (_calGroups[i].toLower() == name) {
                ui->calPoolList->item(i)->setSelected(true);
                return;
            }
        }
    }
}

int getCalibrationDialog::exec() {
    _isOkClicked = false;
    _selectDefaultOnGui();
    return(QDialog::exec());
}
int getCalibrationDialog::exec(Vna &vna) {
    _isOkClicked = false;
    update(vna);
    return(QDialog::exec());
}
int getCalibrationDialog::exec(QVector<uint> calibratedChannels, QStringList calGroups) {
    _isOkClicked = false;
    update(calibratedChannels, calGroups);
    return(QDialog::exec());
}

bool getCalibrationDialog::isOkClicked() {
    return(_isOkClicked);
}
bool getCalibrationDialog::isCalibrationSelected() {
    return(_isCalibrationSelected);
}
bool getCalibrationDialog::isCancelClicked() {
    return(!_isOkClicked);
}

bool getCalibrationDialog::isCalibratedChannel() {
    return(_isCalibratedChannel);
}
void getCalibrationDialog::saveChannelCalibration(Vna &vna, QString calGroup) {
    if (_isCalibratedChannel) {
        vna.channel(_channel).saveCalibration(calGroup);
    }
}
uint getCalibrationDialog::channel() {
    return(_channel);
}

bool getCalibrationDialog::isCalGroup() {
    return(_isCalGroup);
}
QString getCalibrationDialog::calGroup() {
    return(_calGroup);
}

void getCalibrationDialog::on_channelList_itemSelectionChanged() {
    if (ui->channelList->selectedItems().isEmpty())
        return;

    ui->calPoolList->clearSelection();
}
void getCalibrationDialog::on_calPoolList_itemSelectionChanged() {
    if (ui->calPoolList->selectedItems().isEmpty())
        return;

    ui->channelList->clearSelection();
}
void getCalibrationDialog::on_buttonBox_accepted()
{
    _isOkClicked = true;
    if (ui->channelList->selectedItems().isEmpty() == false) {
        QListWidgetItem *item;
        item = ui->channelList->selectedItems().first();
        uint row = ui->channelList->row(item);
        selectChannel(_channels[row]);
    }
    else if (ui->calPoolList->selectedItems().isEmpty() == false) {
        QString calGroup;
        calGroup
            = ui->calPoolList->selectedItems().first()->text();
        selectCalGroup(calGroup);
    }
    close();
}
void getCalibrationDialog::on_buttonBox_rejected()
{
    close();
}
