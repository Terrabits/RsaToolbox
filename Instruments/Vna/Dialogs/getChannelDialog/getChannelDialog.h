#ifndef GETPORTSDIALOG_H
#define GETPORTSDIALOG_H


// RsaToolbox
#include "Vna.h"

// Qt
#include <QDialog>

namespace RsaToolbox {

namespace Ui {
class getChannelDialog;
}
class getChannelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit getChannelDialog(QWidget *parent = 0);
    getChannelDialog(RsaToolbox::Vna &vna, QWidget *parent = 0);
    getChannelDialog(QVector<uint> channels, QWidget *parent = 0);
    ~getChannelDialog();

    QVector<uint> channels();
    void selectDefault();
    void select(uint channel);
    void clearSelection();

    void clearDefault();
    void setDefault(uint channel);

    bool isOkClicked();
    bool isCancelClicked();

    bool isChannelSelected();
    uint channel();

    void update(RsaToolbox::Vna &vna);
    void update(QVector<uint> channels);

    int exec();
    int exec(RsaToolbox::Vna &vna);
    int exec(QVector<uint> channels);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::getChannelDialog *ui;

    void _displayChannels();
    void _selectChannelOnGui(uint channel);

    void _validateSelection();

    bool _isDefault;
    uint _defaultChannel;
    void _displaySelection();

    bool _isOkClicked;

    int _numberOfChannels;
    QVector<uint> _channels;

    bool _isChannelSelected;
    uint _selectedChannel;
};
} // RsaToolbox


#endif // GETPORTSDIALOG_H
