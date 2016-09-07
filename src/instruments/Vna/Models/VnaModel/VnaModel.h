#ifndef VNAMODEL_H
#define VNAMODEL_H

#include "Vna.h"

#include <QAbstractTableModel>


namespace RsaToolbox {

class VnaModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit VnaModel(QObject *parent = 0);

    void setVna(Vna *vna);
    Vna *vna() const;

    enum COLUMN {
        CONNECTION_TYPE_COLUMN = 0,
        ADDRESS_COLUMN = 1,
        CONNECTED_COLUMN = 2,
        MAKE_COLUMN = 3,
        MODEL_COLUMN = 4,
        SERIAL_COLUMN = 5,
        FIRMWARE_COLUMN = 6,
        FREQ_DISPLAY_COLUMN = 7,
        POWER_DISPLAY_COLUMN = 8
    };
    static const int COLUMNS = 9;

    int rowCount(const QModelIndex &parent) const; // 1
    int columnCount(const QModelIndex &parent) const;

//    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);


signals:
    void error(QString errorMessage);

public slots:
    void reset();

private:
    Vna *_vna;
    ConnectionType _connectionType;
    QString _address;
    bool toggleConnection();
    QString make() const;
    QString model() const;
    QString serial() const;
    QString firmware() const;
    QString displayFrequency() const;
    QString displayPower() const;
    QList<uint> channels();

};
} // RsaToolbox


#endif // VNAMODEL_H
