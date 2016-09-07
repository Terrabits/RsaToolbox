/********************************************************************************
** Form generated from reading UI file 'Wizard.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIZARD_H
#define UI_WIZARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BreadCrumbs.h"
#include "WizardButtons.h"

namespace RsaToolbox {

class Ui_Wizard
{
public:
    QVBoxLayout *verticalLayout_2;
    BreadCrumbs *breadCrumbs;
    QWidget *body;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stack;
    WizardButtons *buttons;

    void setupUi(QWidget *RsaToolbox__Wizard)
    {
        if (RsaToolbox__Wizard->objectName().isEmpty())
            RsaToolbox__Wizard->setObjectName(QStringLiteral("RsaToolbox__Wizard"));
        RsaToolbox__Wizard->resize(550, 450);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Wizard/Icons/RS.ico"), QSize(), QIcon::Normal, QIcon::Off);
        RsaToolbox__Wizard->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(RsaToolbox__Wizard);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        breadCrumbs = new BreadCrumbs(RsaToolbox__Wizard);
        breadCrumbs->setObjectName(QStringLiteral("breadCrumbs"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(breadCrumbs->sizePolicy().hasHeightForWidth());
        breadCrumbs->setSizePolicy(sizePolicy);
        breadCrumbs->setMinimumSize(QSize(0, 35));
        breadCrumbs->setMaximumSize(QSize(16777215, 35));

        verticalLayout_2->addWidget(breadCrumbs);

        body = new QWidget(RsaToolbox__Wizard);
        body->setObjectName(QStringLiteral("body"));
        verticalLayout = new QVBoxLayout(body);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        stack = new QStackedWidget(body);
        stack->setObjectName(QStringLiteral("stack"));

        verticalLayout->addWidget(stack);

        buttons = new WizardButtons(body);
        buttons->setObjectName(QStringLiteral("buttons"));
        buttons->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(buttons);


        verticalLayout_2->addWidget(body);


        retranslateUi(RsaToolbox__Wizard);

        stack->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(RsaToolbox__Wizard);
    } // setupUi

    void retranslateUi(QWidget *RsaToolbox__Wizard)
    {
        RsaToolbox__Wizard->setWindowTitle(QApplication::translate("RsaToolbox::Wizard", "Form", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class Wizard: public Ui_Wizard {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_WIZARD_H
