#ifndef CONNECTIONTYPECOMBOBOX_H
#define CONNECTIONTYPECOMBOBOX_H


#include "GenericBus.h"

#include <QComboBox>


namespace RsaToolbox {

class ConnectionTypeComboBox : public QComboBox
{
    Q_OBJECT
    Q_PROPERTY(ConnectionType currentType READ currentType WRITE setCurrentType NOTIFY currentTypeChanged)

public:
    explicit ConnectionTypeComboBox(QWidget *parent = 0);

    ConnectionType currentType();

signals:
    void currentTypeChanged(ConnectionType newType);

public slots:
    void setCurrentType(ConnectionType type);
};
} // RsaToolbox


#endif // CONNECTIONTYPECOMBOBOX_H
