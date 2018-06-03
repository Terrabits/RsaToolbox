#include "VnaModel.h"

// RsaToolbox
#include "General.h"
#include "VisaBus.h"
#include "VnaProperties.h"
using namespace RsaToolbox;

#include <QDebug>

VnaModel::VnaModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    _vna = nullptr;
    _connectionType = ConnectionType::VisaTcpConnection;
    _address.clear();
}


void VnaModel::setVna(RsaToolbox::Vna *vna) {
    if (vna == _vna)
        return;

    beginResetModel();
    _vna = vna;
    if (_vna && _vna->isOpen()) {
        _connectionType = _vna->connectionType();
        _address = _vna->address();
    }
    else {
        _connectionType = ConnectionType::VisaTcpConnection;
        _address.clear();
    }
    endResetModel();
}
RsaToolbox::Vna *VnaModel::vna() const {
    return _vna;
}

int VnaModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    // Else
    return 1;
}
int VnaModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    // Else
    return COLUMNS;
}

QVariant VnaModel::data(const QModelIndex &index, int role) const {
    if (!_vna) {
        return QVariant();
    }
    if (!index.isValid()) {
        return QVariant();
    }
    if (index.parent().isValid()) {
        return QVariant();
    }
    if (role != Qt::DisplayRole && role != Qt::EditRole) {
        return QVariant();
    }
    if (!hasIndex(index.row(), index.column())) {
        return QVariant();
    }

    switch (index.column()) {
    case CONNECTION_TYPE_COLUMN: return _connectionType;
    case ADDRESS_COLUMN:         return _address;
    case CONNECTED_COLUMN:       return _vna->isOpen();
    case MAKE_COLUMN:            return make();
    case MODEL_COLUMN:           return model();
    case SERIAL_COLUMN:          return serial();
    case FIRMWARE_COLUMN:        return firmware();
    case FREQ_DISPLAY_COLUMN:    return displayFrequency();
    case POWER_DISPLAY_COLUMN:   return displayPower();
    default:                     return QVariant();
    }
}
bool VnaModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!_vna)
        return false;
    if (!index.isValid())
        return false;
    if (index.parent().isValid())
        return false;
    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return false;
    if (!hasIndex(index.row(), index.column()))
        return false;
    
    switch (index.column()) {
    case CONNECTION_TYPE_COLUMN:
        if (_vna->isOpen()) {
            return false;
        }
        if (_connectionType == value.value<int>()) {
            return false;
        }
        _connectionType = RsaToolbox::ConnectionType(value.value<int>());
        emit dataChanged(index, index);
        return true;

    case ADDRESS_COLUMN:
        if (_vna->isOpen()) {
            return false;
        }
        if (_address == value.toString()) {
            return false;
        }
        _address = value.toString();
        emit dataChanged(index, index);
        return true;

    case CONNECTED_COLUMN:
        if (value.toBool() && !_vna->isOpen()) {
            if (!_vna->open(_connectionType, _address)) {
                return false;
            }
            emit dataChanged(index, this->index(0, COLUMNS-1));
            return true;
        }
        if (!value.toBool() && _vna->isOpen()) {
            _vna->close();
            emit dataChanged(index, this->index(0, COLUMNS-1));
            return true;
        }
        // nothing to set
        return false;
    case MAKE_COLUMN:
    case MODEL_COLUMN:
    case SERIAL_COLUMN:
    case FIRMWARE_COLUMN:
    case FREQ_DISPLAY_COLUMN:
    case POWER_DISPLAY_COLUMN:
    default:
        return false;
    }
}
Qt::ItemFlags VnaModel::flags(const QModelIndex &index) const {
    if (!_vna)
        return Qt::NoItemFlags;
    if (!index.isValid())
        return Qt::NoItemFlags;
    if (index.row() != 0)
        return Qt::NoItemFlags;

    switch (index.column()) {
    case CONNECTION_TYPE_COLUMN:
    case ADDRESS_COLUMN:
    case CONNECTED_COLUMN:
        return QAbstractTableModel::flags(index)
                | Qt::ItemIsEditable
                | Qt::ItemIsSelectable
                | Qt::ItemIsEnabled;
    case MAKE_COLUMN:
    case MODEL_COLUMN:
    case SERIAL_COLUMN:
    case FIRMWARE_COLUMN:
    case FREQ_DISPLAY_COLUMN:
    case POWER_DISPLAY_COLUMN:
        return QAbstractTableModel::flags(index);
    default:
        return QAbstractTableModel::flags(index);
    }
}

void VnaModel::reset() {
    setVna(nullptr);
}

bool VnaModel::toggleConnection() {
    if (!_vna) {
        return false;
    }
    if (_vna->isOpen()) {
        _vna->close();
        return true;
    }

    if (_address.isEmpty()) {
        emit error("*Instrument address is required.");
        return false;
    }

    bool isVisa = VisaBus::isVisaInstalled();
    if (!isVisa && _connectionType == ConnectionType::VisaGpibConnection) {
        emit error("*VISA is required for GPIB connections.");
        return false;
    }

    if (!_vna->open(_connectionType, _address)) {
        emit error("*Could not connect to instrument.");
        return false;
    }
    if (_vna->properties().isUnknownModel()) {
        emit error(QString("*Unknown instrument:  ") + _vna->idString());
        return false;
    }

    return true;
}
QString VnaModel::make() const {
    if (!_vna->isOpen())
        return "";
    if (_vna->isRohdeSchwarz())
        return "Rohde & Schwarz";
    // Else
    return "Unknown";
}
QString VnaModel::model() const {
    if (!_vna->isOpen())
        return "";
    VnaProperties::Model model = _vna->properties().model();
    if (model == VnaProperties::Model::Unknown)
        return "";
    // Else
    return toString(model);
}
QString VnaModel::serial() const {
    if (!_vna->isOpen())
        return "";
    if (_vna->properties().isUnknownModel())
        return "";
    // Else
    return _vna->properties().serialNumber();
}
QString VnaModel::firmware() const {
    if (!_vna->isOpen())
        return "";
    if (_vna->properties().isUnknownModel())
        return "";
    // Else
    return _vna->properties().firmwareVersion();
}
QString VnaModel::displayFrequency() const {
    if (!_vna->isOpen())
        return "";
    VnaProperties::Model model = _vna->properties().model();
    if (model == VnaProperties::Model::Unknown)
        return "";
    
    // Else
    QString text;
    text += RsaToolbox::formatValue(
                _vna->properties().minimumFrequency_Hz(),
                1,
                RsaToolbox::Units::Hertz);
    text += " to ";
    text += RsaToolbox::formatValue(
                _vna->properties().maximumFrequency_Hz(),
                1,
                RsaToolbox::Units::Hertz);
    return text;
}
QString VnaModel::displayPower() const {
    if (!_vna->isOpen())
        return "";
    VnaProperties::Model model = _vna->properties().model();
    if (model == VnaProperties::Model::Unknown)
        return "";
    
    // Else
    QString text;
    text += RsaToolbox::formatValue(
                _vna->properties().minimumPower_dBm(),
                1,
                RsaToolbox::Units::dBm);
    text += " to ";
    text += RsaToolbox::formatValue(
                _vna->properties().maximumPower_dBm(),
                1,
                RsaToolbox::Units::dBm);
    return text;
}

