/********************************************************************************
** Form generated from reading UI file 'getPortsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETPORTSDIALOG_H
#define UI_GETPORTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

namespace RsaToolbox {

class Ui_getPortsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *portsList;
    QCheckBox *selectAllCheckbox;

    void setupUi(QDialog *RsaToolbox__getPortsDialog)
    {
        if (RsaToolbox__getPortsDialog->objectName().isEmpty())
            RsaToolbox__getPortsDialog->setObjectName(QStringLiteral("RsaToolbox__getPortsDialog"));
        RsaToolbox__getPortsDialog->resize(400, 327);
        buttonBox = new QDialogButtonBox(RsaToolbox__getPortsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 284, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        portsList = new QListWidget(RsaToolbox__getPortsDialog);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(portsList);
        __qlistwidgetitem->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(portsList);
        __qlistwidgetitem1->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(portsList);
        __qlistwidgetitem2->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(portsList);
        __qlistwidgetitem3->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(portsList);
        __qlistwidgetitem4->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(portsList);
        __qlistwidgetitem5->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(portsList);
        __qlistwidgetitem6->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(portsList);
        __qlistwidgetitem7->setCheckState(Qt::Checked);
        portsList->setObjectName(QStringLiteral("portsList"));
        portsList->setGeometry(QRect(70, 50, 256, 201));
        portsList->setSelectionMode(QAbstractItemView::NoSelection);
        selectAllCheckbox = new QCheckBox(RsaToolbox__getPortsDialog);
        selectAllCheckbox->setObjectName(QStringLiteral("selectAllCheckbox"));
        selectAllCheckbox->setGeometry(QRect(75, 28, 81, 20));
        QWidget::setTabOrder(selectAllCheckbox, portsList);
        QWidget::setTabOrder(portsList, buttonBox);

        retranslateUi(RsaToolbox__getPortsDialog);

        QMetaObject::connectSlotsByName(RsaToolbox__getPortsDialog);
    } // setupUi

    void retranslateUi(QDialog *RsaToolbox__getPortsDialog)
    {
        RsaToolbox__getPortsDialog->setWindowTitle(QApplication::translate("RsaToolbox::getPortsDialog", "Choose Ports...", 0));

        const bool __sortingEnabled = portsList->isSortingEnabled();
        portsList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = portsList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("RsaToolbox::getPortsDialog", "Port 1", 0));
        QListWidgetItem *___qlistwidgetitem1 = portsList->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("RsaToolbox::getPortsDialog", "Port 2", 0));
        QListWidgetItem *___qlistwidgetitem2 = portsList->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("RsaToolbox::getPortsDialog", "Port 3", 0));
        QListWidgetItem *___qlistwidgetitem3 = portsList->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("RsaToolbox::getPortsDialog", "Port 4", 0));
        QListWidgetItem *___qlistwidgetitem4 = portsList->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("RsaToolbox::getPortsDialog", "Port 5", 0));
        QListWidgetItem *___qlistwidgetitem5 = portsList->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("RsaToolbox::getPortsDialog", "Port 6", 0));
        QListWidgetItem *___qlistwidgetitem6 = portsList->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("RsaToolbox::getPortsDialog", "Port 7", 0));
        QListWidgetItem *___qlistwidgetitem7 = portsList->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("RsaToolbox::getPortsDialog", "Port 8", 0));
        portsList->setSortingEnabled(__sortingEnabled);

        selectAllCheckbox->setText(QApplication::translate("RsaToolbox::getPortsDialog", "Select All", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class getPortsDialog: public Ui_getPortsDialog {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_GETPORTSDIALOG_H
