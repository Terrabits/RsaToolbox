#ifndef CONNECTIONTYPECOMBOBOX_H
#define CONNECTIONTYPECOMBOBOX_H

#include "GenericBus.h"

#include <QComboBox>

class ConnectionTypeComboBox : public QComboBox
{
    Q_OBJECT
    Q_PROPERTY(RsaToolbox::ConnectionType currentType READ currentType WRITE setCurrentType NOTIFY currentTypeChanged)
//    Q_ENUMS(RsaToolbox::ConnectionType)
public:
    explicit ConnectionTypeComboBox(QWidget *parent = 0);

    RsaToolbox::ConnectionType currentType();

signals:
    void currentTypeChanged(RsaToolbox::ConnectionType newType);

public slots:
    void setCurrentType(RsaToolbox::ConnectionType type);

};

#endif // CONNECTIONTYPECOMBOBOX_H
