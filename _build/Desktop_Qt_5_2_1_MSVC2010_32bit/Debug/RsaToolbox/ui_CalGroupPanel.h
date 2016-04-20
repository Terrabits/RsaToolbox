/********************************************************************************
** Form generated from reading UI file 'CalGroupPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALGROUPPANEL_H
#define UI_CALGROUPPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

namespace RsaToolbox {

class Ui_CalGroupPanel
{
public:
    QGridLayout *gridLayout;
    QRadioButton *noCal;
    QRadioButton *applyCal;
    QLineEdit *calEdit;
    QPushButton *calButton;

    void setupUi(QWidget *RsaToolbox__CalGroupPanel)
    {
        if (RsaToolbox__CalGroupPanel->objectName().isEmpty())
            RsaToolbox__CalGroupPanel->setObjectName(QStringLiteral("RsaToolbox__CalGroupPanel"));
        RsaToolbox__CalGroupPanel->resize(265, 87);
        gridLayout = new QGridLayout(RsaToolbox__CalGroupPanel);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        noCal = new QRadioButton(RsaToolbox__CalGroupPanel);
        noCal->setObjectName(QStringLiteral("noCal"));
        noCal->setChecked(true);

        gridLayout->addWidget(noCal, 0, 0, 1, 1);

        applyCal = new QRadioButton(RsaToolbox__CalGroupPanel);
        applyCal->setObjectName(QStringLiteral("applyCal"));

        gridLayout->addWidget(applyCal, 1, 0, 1, 1);

        calEdit = new QLineEdit(RsaToolbox__CalGroupPanel);
        calEdit->setObjectName(QStringLiteral("calEdit"));
        calEdit->setReadOnly(true);

        gridLayout->addWidget(calEdit, 2, 0, 1, 1);

        calButton = new QPushButton(RsaToolbox__CalGroupPanel);
        calButton->setObjectName(QStringLiteral("calButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calButton->sizePolicy().hasHeightForWidth());
        calButton->setSizePolicy(sizePolicy);
        calButton->setMinimumSize(QSize(31, 23));
        calButton->setMaximumSize(QSize(31, 23));

        gridLayout->addWidget(calButton, 2, 1, 1, 1);


        retranslateUi(RsaToolbox__CalGroupPanel);

        QMetaObject::connectSlotsByName(RsaToolbox__CalGroupPanel);
    } // setupUi

    void retranslateUi(QWidget *RsaToolbox__CalGroupPanel)
    {
        RsaToolbox__CalGroupPanel->setWindowTitle(QApplication::translate("RsaToolbox::CalGroupPanel", "Form", 0));
        noCal->setText(QApplication::translate("RsaToolbox::CalGroupPanel", "Use channel as-is", 0));
        applyCal->setText(QApplication::translate("RsaToolbox::CalGroupPanel", "Apply calibration:", 0));
        calButton->setText(QApplication::translate("RsaToolbox::CalGroupPanel", "...", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class CalGroupPanel: public Ui_CalGroupPanel {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_CALGROUPPANEL_H
