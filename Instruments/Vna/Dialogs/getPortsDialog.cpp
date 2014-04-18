#include "getPortsDialog.h"
#include "ui_getPortsDialog.h"


//RsaToolbox
#include "General.h"
using namespace RsaToolbox;

getPortsDialog::getPortsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getPortsDialog)
{
    ui->setupUi(this);
    clearSelection();
    _numberOfPorts = 0;
    _isOkClicked =false;
    clearDefault();
}
getPortsDialog::getPortsDialog(Vna &vna, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getPortsDialog)
{
    ui->setupUi(this);

    clearSelection();
    clearDefault();
    _isOkClicked = false;
    update(vna);
}
getPortsDialog::getPortsDialog(QVector<uint> ports, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getPortsDialog)
{
    ui->setupUi(this);

    clearSelection();
    clearDefault();
    _isOkClicked = false;
    update(ports);
}

getPortsDialog::~getPortsDialog()
{
    delete ui;
}

QVector<uint> getPortsDialog::ports() {
    return(_ports);
}

void getPortsDialog::selectDefault() {
    if (_isDefault == false)
        return;

    if (_isPortsSelected == false) {
        selectPorts(_defaultPorts);
    }
    else {
        QVector<uint> backup = _selectedPorts;
        selectPorts(_defaultPorts);
        if (_selectedPorts.isEmpty())
            selectPorts(backup);
    }
}
void getPortsDialog::selectPort(uint port) {
    if (_isPortsSelected) {
        if (_selectedPorts.contains(port) == false
                && _ports.contains(port))
        {
            _selectedPorts.append(port);
            qSort(_selectedPorts);
        }
    }
    else if (_ports.contains(port)) {
        _isPortsSelected = true;
        _selectedPorts.clear();
        _selectedPorts.append(port);
    }
}
void getPortsDialog::unselectPort(uint port) {
    if (_selectedPorts.contains(port))
        _selectedPorts.remove(port);
    if (_selectedPorts.isEmpty())
        _isDefault = false;
}
void getPortsDialog::selectPorts(QVector<uint> ports) {
    QVector<uint> selectedPorts;
    foreach(uint port, ports) {
        if (_ports.contains(port))
            selectedPorts.append(port);
    }

    if (selectedPorts.isEmpty())
        return;

    qSort(selectedPorts);
    _isPortsSelected = true;
    _selectedPorts = selectedPorts;
}

void getPortsDialog::clearDefault() {
    _isDefault = false;
    _defaultPorts.clear();
}
void getPortsDialog::addDefault(uint port) {
    if (_isDefault == false)
        _defaultPorts.clear();

    _isDefault = true;
    if (_defaultPorts.contains(port) == false) {
        _defaultPorts.append(port);
    }
}
void getPortsDialog::removeDefault(uint port) {
    if (_defaultPorts.contains(port))
        _defaultPorts.remove(port);
    if (_defaultPorts.isEmpty())
        _isDefault = false;
}
void getPortsDialog::setDefault(QVector<uint> ports) {
    _isDefault = true;
    _defaultPorts = ports;
}

void getPortsDialog::update(Vna &vna) {
    QVector<uint> ports = range(uint(1), vna.testPorts());
    update(ports);
}
void getPortsDialog::update(QVector<uint> ports) {
    _isOkClicked = false;

    _numberOfPorts = ports.size();
    _ports = ports;
    _validateSelection();

    _displayPorts();
    _displaySelection();
}
void getPortsDialog::clearSelection() {
    _isPortsSelected = false;
    _selectedPorts.clear();
}
void getPortsDialog::_displayPorts() {
    ui->selectAllCheckbox->setChecked(false);

    qSort(_ports);
    ui->portsList->clear();
    ui->portsList->addItems(portLabels(_ports));
}
void getPortsDialog::_checkAll(bool checked) {
    Qt::CheckState checkState;
    if (checked)
        checkState = Qt::Checked;
    else
        checkState = Qt::Unchecked;

    for (int i = 0; i < _numberOfPorts; i++)
        ui->portsList->item(i)->setCheckState(checkState);
}
void getPortsDialog::_uncheckAll(bool unchecked) {
    _checkAll(!unchecked);
}
void getPortsDialog::_selectPortsOnGui(QVector<uint> ports) {
    _uncheckAll();
    foreach(uint port, ports) {
        int row = _ports.indexOf(port);
        if (row != -1) {
            ui->portsList->item(row)->setCheckState(Qt::Checked);
        }
    }
}
void getPortsDialog::_displaySelection() {
    if (_isPortsSelected)
        _selectPortsOnGui(_selectedPorts);
    else if (_isDefault)
        _selectPortsOnGui(_defaultPorts);
    else
        _uncheckAll();
}

void getPortsDialog::_validateSelection() {
    if (_isPortsSelected == false)
        return;

    QVector<uint> selectedPorts = _selectedPorts;
    _selectedPorts.clear();
    foreach(uint port, selectedPorts) {
        if (_ports.contains(port)) {
            _selectedPorts.append(port);
        }
    }

    if (_selectedPorts.isEmpty()) {
        _isPortsSelected = false;
    }
    else {
        _isPortsSelected = true;
        qSort(_selectedPorts);
    }
}

bool getPortsDialog::isOkClicked() {
    return(_isOkClicked);
}
bool getPortsDialog::isCancelClicked() {
    return(!_isOkClicked);
}

bool getPortsDialog::isPortsSelected() {
    return(_isPortsSelected);
}
QVector<uint> getPortsDialog::selectedPorts() {
    return(_selectedPorts);
}

int getPortsDialog::exec() {
    _isOkClicked = false;
    _displaySelection();
    return(QDialog::exec());
}
int getPortsDialog::exec(Vna &vna) {
    _isOkClicked = false;
    update(vna);
    return(QDialog::exec());
}
int getPortsDialog::exec(QVector<uint> ports) {
    _isOkClicked = false;
    update(ports);
    return(QDialog::exec());
}

void getPortsDialog::on_buttonBox_accepted() {
    _isOkClicked = true;

    QVector<uint> selectedPorts;
    for(int i = 0; i < _numberOfPorts; i++) {
        if (ui->portsList->item(i)->checkState() == Qt::Checked)
            selectedPorts.append(_ports[i]);
    }

    if (selectedPorts.isEmpty() == false) {
        _isPortsSelected = true;
        _selectedPorts = selectedPorts;
    }
    close();
}
void getPortsDialog::on_buttonBox_rejected() {
    close();
}
void getPortsDialog::on_selectAllCheckbox_toggled(bool checked) {
    _checkAll(checked);
}
