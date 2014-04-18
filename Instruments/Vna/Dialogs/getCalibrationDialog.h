#ifndef GETCALIBRATIONDIALOG_H
#define GETCALIBRATIONDIALOG_H

// RsaToolbox
#include "Vna.h"

// Qt
#include <QVector>
#include <QStringList>
#include <QDialog>


namespace Ui {
class getCalibrationDialog;
}

class getCalibrationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit getCalibrationDialog(QWidget *parent = 0);
    explicit getCalibrationDialog(RsaToolbox::Vna &vna, QWidget *parent = 0);
    explicit getCalibrationDialog(QVector<uint> calibratedChannels, QStringList calGroups, QWidget *parent = 0);

    ~getCalibrationDialog();

    // Manual (non-GUI) use
    QVector<uint> calibratedChannels();
    void selectChannel(uint index);
    QStringList calGroups();
    void selectCalGroup(QString name);
    void selectDefault();
    void clearSelection();


    // GUI defaults
    void clearDefault();
    void setDefaultChannel(uint channel);
    void setDefaultCalGroup(QString calGroup);

    // Choices
    void update(RsaToolbox::Vna &vna);
    void update(QVector<uint> calibratedChannels, QStringList calGroups);


    // Handle selection (or lack thereof)
    int exec();
    int exec(RsaToolbox::Vna &vna);
    int exec(QVector<uint> calibratedChannels, QStringList calGroups);

    bool isOkClicked();
    bool isCancelClicked();

    bool isCalibrationSelected();

    bool isCalibratedChannel();
    void saveChannelCalibration(RsaToolbox::Vna &vna, QString calGroup);
    uint channel();

    bool isCalGroup();
    QString calGroup();


private slots:
    void on_channelList_itemSelectionChanged();
    void on_calPoolList_itemSelectionChanged();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::getCalibrationDialog *ui;

    bool _isDefaultChannel;
    uint _defaultChannel;

    bool _isDefaultCalGroup;
    QString _defaultCalGroup;


    QVector<uint> _channels;
    QStringList _calGroups;

    bool _isOkClicked;
    bool _isCalibrationSelected;

    bool _isCalibratedChannel;
    uint _channel;

    bool _isCalGroup;
    QString _calGroup;

    // Select in the Gui sense.
    // Better name?
    void _unselectGui();
    void _selectDefaultOnGui();
    void _selectChannelOnGui(uint index);
    void _selectCalGroupOnGui(QString name);

};

#endif // GETCALIBRATIONDIALOG_H
