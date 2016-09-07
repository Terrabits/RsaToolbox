#ifndef GETPORTSDIALOG_H
#define GETPORTSDIALOG_H


// RsaToolbox
#include "Vna.h"

// Qt
#include <QDialog>

namespace RsaToolbox {

namespace Ui {
class getPortsDialog;
}
class getPortsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit getPortsDialog(QWidget *parent = 0);
    explicit getPortsDialog(RsaToolbox::Vna &vna, QWidget *parent = 0);
    explicit getPortsDialog(QVector<uint> selectedPorts, QWidget *parent = 0);

    ~getPortsDialog();

    QVector<uint> ports();
    void selectDefault();
    void selectPort(uint port);
    void unselectPort(uint port);
    void selectPorts(QVector<uint> selectedPorts);
    void clearSelection();

    void clearDefault();
    void addDefault(uint port);
    void removeDefault(uint port);
    void setDefault(QVector<uint> selectedPorts);

    bool isOkClicked();
    bool isCancelClicked();

    bool isPortsSelected();
    QVector<uint> selectedPorts();

    void update(RsaToolbox::Vna &vna);
    void update(QVector<uint> selectedPorts);

    int exec();
    int exec(RsaToolbox::Vna &vna);
    int exec(QVector<uint> selectedPorts);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_selectAllCheckbox_toggled(bool checked);

private:
    Ui::getPortsDialog *ui;

    void _displayPorts();

    void _checkAll(bool checked = true);
    void _uncheckAll(bool unchecked = true);
    void _selectPortsOnGui(QVector<uint> selectedPorts);

    void _validateSelection();

    bool _isDefault;
    QVector<uint> _defaultPorts;
    void _displaySelection();

    bool _isOkClicked;

    int _numberOfPorts;
    QVector<uint> _ports;

    bool _isPortsSelected;
    QVector<uint> _selectedPorts;
};
} // RsaToolbox


#endif // GETPORTSDIALOG_H
