/********************************************************************************
** Form generated from reading UI file 'VnaForm.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VNAFORM_H
#define UI_VNAFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ConnectButton.h"
#include "ConnectionTypeComboBox.h"
#include "ErrorLabel.h"

namespace RsaToolbox {

class Ui_VnaForm
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *connectionPanel;
    QGridLayout *gridLayout;
    QLabel *addressLabel;
    ConnectionTypeComboBox *connectionType;
    QLineEdit *address;
    QLabel *typeLabel;
    ConnectButton *connect;
    QSpacerItem *horizontalSpacer;
    ErrorLabel *error;
    QFrame *line;
    QWidget *propertiesPanel;
    QGridLayout *gridLayout_2;
    QLabel *modelLabel;
    QLabel *makeLabel;
    QLineEdit *make;
    QLineEdit *model;
    QLabel *serialLabel;
    QLineEdit *serial;
    QLabel *firmwareLabel;
    QLabel *powerLabel;
    QLabel *freqLabel;
    QLineEdit *firmware;
    QLineEdit *frequency;
    QLineEdit *power;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *RsaToolbox__VnaForm)
    {
        if (RsaToolbox__VnaForm->objectName().isEmpty())
            RsaToolbox__VnaForm->setObjectName(QStringLiteral("RsaToolbox__VnaForm"));
        RsaToolbox__VnaForm->resize(550, 348);
        verticalLayout = new QVBoxLayout(RsaToolbox__VnaForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        connectionPanel = new QWidget(RsaToolbox__VnaForm);
        connectionPanel->setObjectName(QStringLiteral("connectionPanel"));
        gridLayout = new QGridLayout(connectionPanel);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        addressLabel = new QLabel(connectionPanel);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));

        gridLayout->addWidget(addressLabel, 1, 0, 1, 1);

        connectionType = new ConnectionTypeComboBox(connectionPanel);
        connectionType->setObjectName(QStringLiteral("connectionType"));

        gridLayout->addWidget(connectionType, 0, 1, 1, 1);

        address = new QLineEdit(connectionPanel);
        address->setObjectName(QStringLiteral("address"));

        gridLayout->addWidget(address, 1, 1, 1, 1);

        typeLabel = new QLabel(connectionPanel);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));

        gridLayout->addWidget(typeLabel, 0, 0, 1, 1);

        connect = new ConnectButton(connectionPanel);
        connect->setObjectName(QStringLiteral("connect"));

        gridLayout->addWidget(connect, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        gridLayout->setColumnStretch(2, 1);

        verticalLayout->addWidget(connectionPanel);

        error = new ErrorLabel(RsaToolbox__VnaForm);
        error->setObjectName(QStringLiteral("error"));

        verticalLayout->addWidget(error);

        line = new QFrame(RsaToolbox__VnaForm);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        propertiesPanel = new QWidget(RsaToolbox__VnaForm);
        propertiesPanel->setObjectName(QStringLiteral("propertiesPanel"));
        gridLayout_2 = new QGridLayout(propertiesPanel);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        modelLabel = new QLabel(propertiesPanel);
        modelLabel->setObjectName(QStringLiteral("modelLabel"));

        gridLayout_2->addWidget(modelLabel, 1, 0, 1, 1);

        makeLabel = new QLabel(propertiesPanel);
        makeLabel->setObjectName(QStringLiteral("makeLabel"));

        gridLayout_2->addWidget(makeLabel, 0, 0, 1, 1);

        make = new QLineEdit(propertiesPanel);
        make->setObjectName(QStringLiteral("make"));
        make->setEnabled(false);
        make->setReadOnly(true);

        gridLayout_2->addWidget(make, 0, 1, 1, 1);

        model = new QLineEdit(propertiesPanel);
        model->setObjectName(QStringLiteral("model"));
        model->setEnabled(false);
        model->setReadOnly(true);

        gridLayout_2->addWidget(model, 1, 1, 1, 1);

        serialLabel = new QLabel(propertiesPanel);
        serialLabel->setObjectName(QStringLiteral("serialLabel"));

        gridLayout_2->addWidget(serialLabel, 2, 0, 1, 1);

        serial = new QLineEdit(propertiesPanel);
        serial->setObjectName(QStringLiteral("serial"));
        serial->setEnabled(false);
        serial->setReadOnly(true);

        gridLayout_2->addWidget(serial, 2, 1, 1, 1);

        firmwareLabel = new QLabel(propertiesPanel);
        firmwareLabel->setObjectName(QStringLiteral("firmwareLabel"));

        gridLayout_2->addWidget(firmwareLabel, 3, 0, 1, 1);

        powerLabel = new QLabel(propertiesPanel);
        powerLabel->setObjectName(QStringLiteral("powerLabel"));

        gridLayout_2->addWidget(powerLabel, 5, 0, 1, 1);

        freqLabel = new QLabel(propertiesPanel);
        freqLabel->setObjectName(QStringLiteral("freqLabel"));

        gridLayout_2->addWidget(freqLabel, 4, 0, 1, 1);

        firmware = new QLineEdit(propertiesPanel);
        firmware->setObjectName(QStringLiteral("firmware"));
        firmware->setEnabled(false);
        firmware->setReadOnly(true);

        gridLayout_2->addWidget(firmware, 3, 1, 1, 1);

        frequency = new QLineEdit(propertiesPanel);
        frequency->setObjectName(QStringLiteral("frequency"));
        frequency->setEnabled(false);
        frequency->setReadOnly(true);

        gridLayout_2->addWidget(frequency, 4, 1, 1, 1);

        power = new QLineEdit(propertiesPanel);
        power->setObjectName(QStringLiteral("power"));
        power->setEnabled(false);
        power->setReadOnly(true);

        gridLayout_2->addWidget(power, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 1, 1, 1);

        gridLayout_2->setColumnStretch(1, 1);

        verticalLayout->addWidget(propertiesPanel);


        retranslateUi(RsaToolbox__VnaForm);

        QMetaObject::connectSlotsByName(RsaToolbox__VnaForm);
    } // setupUi

    void retranslateUi(QWidget *RsaToolbox__VnaForm)
    {
        RsaToolbox__VnaForm->setWindowTitle(QApplication::translate("RsaToolbox::VnaForm", "Form", 0));
        addressLabel->setText(QApplication::translate("RsaToolbox::VnaForm", "Address:", 0));
        typeLabel->setText(QApplication::translate("RsaToolbox::VnaForm", "Connection Type:", 0));
        connect->setText(QApplication::translate("RsaToolbox::VnaForm", "Connect", 0));
        modelLabel->setText(QApplication::translate("RsaToolbox::VnaForm", "Model:", 0));
        makeLabel->setText(QApplication::translate("RsaToolbox::VnaForm", "Make:", 0));
        serialLabel->setText(QApplication::translate("RsaToolbox::VnaForm", "Serial No:", 0));
        firmwareLabel->setText(QApplication::translate("RsaToolbox::VnaForm", "Firmware Version:", 0));
        powerLabel->setText(QApplication::translate("RsaToolbox::VnaForm", "Power Range:", 0));
        freqLabel->setText(QApplication::translate("RsaToolbox::VnaForm", "Freq Range:", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class VnaForm: public Ui_VnaForm {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_VNAFORM_H
