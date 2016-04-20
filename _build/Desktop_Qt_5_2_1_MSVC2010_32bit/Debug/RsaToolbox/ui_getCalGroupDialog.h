/********************************************************************************
** Form generated from reading UI file 'getCalGroupDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETCALGROUPDIALOG_H
#define UI_GETCALGROUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include "ErrorLabel.h"

namespace RsaToolbox {

class Ui_getCalGroupDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListView *listView;
    ErrorLabel *error;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RsaToolbox__getCalGroupDialog)
    {
        if (RsaToolbox__getCalGroupDialog->objectName().isEmpty())
            RsaToolbox__getCalGroupDialog->setObjectName(QStringLiteral("RsaToolbox__getCalGroupDialog"));
        RsaToolbox__getCalGroupDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(RsaToolbox__getCalGroupDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listView = new QListView(RsaToolbox__getCalGroupDialog);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setProperty("showDropIndicator", QVariant(false));
        listView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(listView);

        error = new ErrorLabel(RsaToolbox__getCalGroupDialog);
        error->setObjectName(QStringLiteral("error"));

        verticalLayout->addWidget(error);

        buttonBox = new QDialogButtonBox(RsaToolbox__getCalGroupDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(RsaToolbox__getCalGroupDialog);

        QMetaObject::connectSlotsByName(RsaToolbox__getCalGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *RsaToolbox__getCalGroupDialog)
    {
        RsaToolbox__getCalGroupDialog->setWindowTitle(QApplication::translate("RsaToolbox::getCalGroupDialog", "Dialog", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class getCalGroupDialog: public Ui_getCalGroupDialog {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_GETCALGROUPDIALOG_H
