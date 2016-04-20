/********************************************************************************
** Form generated from reading UI file 'getChannelDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETCHANNELDIALOG_H
#define UI_GETCHANNELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

namespace RsaToolbox {

class Ui_getChannelDialog
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *channelList;

    void setupUi(QDialog *RsaToolbox__getChannelDialog)
    {
        if (RsaToolbox__getChannelDialog->objectName().isEmpty())
            RsaToolbox__getChannelDialog->setObjectName(QStringLiteral("RsaToolbox__getChannelDialog"));
        RsaToolbox__getChannelDialog->resize(400, 327);
        buttonBox = new QDialogButtonBox(RsaToolbox__getChannelDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 284, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        channelList = new QListWidget(RsaToolbox__getChannelDialog);
        new QListWidgetItem(channelList);
        new QListWidgetItem(channelList);
        new QListWidgetItem(channelList);
        channelList->setObjectName(QStringLiteral("channelList"));
        channelList->setGeometry(QRect(70, 50, 256, 201));
        channelList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        channelList->setSelectionMode(QAbstractItemView::SingleSelection);
        QWidget::setTabOrder(channelList, buttonBox);

        retranslateUi(RsaToolbox__getChannelDialog);

        QMetaObject::connectSlotsByName(RsaToolbox__getChannelDialog);
    } // setupUi

    void retranslateUi(QDialog *RsaToolbox__getChannelDialog)
    {
        RsaToolbox__getChannelDialog->setWindowTitle(QApplication::translate("RsaToolbox::getChannelDialog", "Choose VNA channel...", 0));

        const bool __sortingEnabled = channelList->isSortingEnabled();
        channelList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = channelList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("RsaToolbox::getChannelDialog", "Channel 1", 0));
        QListWidgetItem *___qlistwidgetitem1 = channelList->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("RsaToolbox::getChannelDialog", "Channel 2", 0));
        QListWidgetItem *___qlistwidgetitem2 = channelList->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("RsaToolbox::getChannelDialog", "Channel 3", 0));
        channelList->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class getChannelDialog: public Ui_getChannelDialog {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_GETCHANNELDIALOG_H
