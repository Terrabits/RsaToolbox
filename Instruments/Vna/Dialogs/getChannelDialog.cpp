#include "getChannelDialog.h"
#include "ui_getChannelDialog.h"


//RsaToolbox
#include "General.h"
using namespace RsaToolbox;

///
/// \brief getChannelDialog::getChannelDialog
/// \param parent
///
getChannelDialog::getChannelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getChannelDialog)
{
    ui->setupUi(this);
    clearSelection();
    _numberOfChannels = 0;
    _isOkClicked =false;
    clearDefault();
}
///
/// \brief getChannelDialog::getChannelDialog
/// \param vna
/// \param parent
///
getChannelDialog::getChannelDialog(RsaToolbox::Vna &vna, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getChannelDialog)
{
    ui->setupUi(this);

    clearSelection();
    clearDefault();
    _isOkClicked = false;
    update(vna);
}
///
/// \brief getChannelDialog::getChannelDialog
/// \param ports
/// \param parent
///
getChannelDialog::getChannelDialog(QVector<uint> ports, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getChannelDialog)
{
    ui->setupUi(this);

    clearSelection();
    clearDefault();
    _isOkClicked = false;
    update(ports);
}
getChannelDialog::~getChannelDialog()
{
    delete ui;
}

QVector<uint> getChannelDialog::channels() {
    return(_channels);
}

void getChannelDialog::selectDefault() {
    if (_isDefault == false)
        return;

    if (_isChannelSelected == false) {
        select(_defaultChannel);
    }
    else {
        uint backup = _selectedChannel;
        _selectedChannel = 0;
        select(_defaultChannel);
        if (_selectedChannel == 0)
            select(backup);
    }
}
void getChannelDialog::select(uint channel) {
    if (_channels.contains(channel))
        _selectedChannel = channel;
}

void getChannelDialog::clearDefault() {
    _isDefault = false;
    _defaultChannel = 0;
}
void getChannelDialog::setDefault(uint channel) {
    _isDefault = true;
    _defaultChannel = channel;
}

void getChannelDialog::update(RsaToolbox::Vna &vna) {
    update(vna.channels());
}
void getChannelDialog::update(QVector<uint> channels) {
    _isOkClicked = false;

    _numberOfChannels = channels.size();
    _channels = channels;
    _validateSelection();

    _displayChannels();
    _displaySelection();
}
void getChannelDialog::clearSelection() {
    _isChannelSelected = false;
    _selectedChannel = 0;
}
void getChannelDialog::_displayChannels() {
    qSort(_channels);
    ui->channelList->clear();
    ui->channelList->addItems(channelLabels(_channels));
}
void getChannelDialog::_selectChannelOnGui(uint channel) {
    int i = _channels.indexOf(channel);
    if (i != -1) {
        ui->channelList->item(i)->setSelected(true);
    }
}
void getChannelDialog::_displaySelection() {
    if (_isChannelSelected)
        _selectChannelOnGui(_selectedChannel);
    else if (_isDefault)
        _selectChannelOnGui(_defaultChannel);
    else
        ui->channelList->clearSelection();
}

void getChannelDialog::_validateSelection() {
    if (_isChannelSelected == false)
        return;

    if (_channels.contains(_selectedChannel) == false) {
        _isChannelSelected = false;
        _selectedChannel = 0;
    }
}

bool getChannelDialog::isOkClicked() {
    return(_isOkClicked);
}
bool getChannelDialog::isCancelClicked() {
    return(!_isOkClicked);
}

bool getChannelDialog::isChannelSelected() {
    return(_isChannelSelected);
}
uint getChannelDialog::channel() {
    return(_selectedChannel);
}

int getChannelDialog::exec() {
    _isOkClicked = false;
    _displaySelection();
    return(QDialog::exec());
}
int getChannelDialog::exec(RsaToolbox::Vna &vna) {
    _isOkClicked = false;
    update(vna);
    return(QDialog::exec());
}
int getChannelDialog::exec(QVector<uint> ports) {
    _isOkClicked = false;
    update(ports);
    return(QDialog::exec());
}

void getChannelDialog::on_buttonBox_accepted() {
    _isOkClicked = true;

    for (int i = 0; i < _numberOfChannels; i++) {
        if (ui->channelList->item(i)->isSelected()) {
            _isChannelSelected = true;
            _selectedChannel = _channels[i];
            break;
        }
    }
    close();
}
void getChannelDialog::on_buttonBox_rejected() {
    close();
}
