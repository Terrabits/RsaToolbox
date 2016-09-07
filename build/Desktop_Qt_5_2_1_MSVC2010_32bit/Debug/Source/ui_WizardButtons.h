/********************************************************************************
** Form generated from reading UI file 'WizardButtons.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIZARDBUTTONS_H
#define UI_WIZARDBUTTONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

namespace RsaToolbox {

class Ui_WizardButtons
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *leftButtons;
    QHBoxLayout *horizontalLayout;
    QPushButton *previous;
    QPushButton *customA;
    QPushButton *customB;
    QSpacerItem *horizontalSpacer;
    QWidget *rightButtons;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *customC;
    QPushButton *cancel;
    QPushButton *next;

    void setupUi(QWidget *RsaToolbox__WizardButtons)
    {
        if (RsaToolbox__WizardButtons->objectName().isEmpty())
            RsaToolbox__WizardButtons->setObjectName(QStringLiteral("RsaToolbox__WizardButtons"));
        RsaToolbox__WizardButtons->resize(530, 41);
        horizontalLayout_3 = new QHBoxLayout(RsaToolbox__WizardButtons);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        leftButtons = new QWidget(RsaToolbox__WizardButtons);
        leftButtons->setObjectName(QStringLiteral("leftButtons"));
        horizontalLayout = new QHBoxLayout(leftButtons);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 3, 0);
        previous = new QPushButton(leftButtons);
        previous->setObjectName(QStringLiteral("previous"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(previous->sizePolicy().hasHeightForWidth());
        previous->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(previous);

        customA = new QPushButton(leftButtons);
        customA->setObjectName(QStringLiteral("customA"));

        horizontalLayout->addWidget(customA);

        customB = new QPushButton(leftButtons);
        customB->setObjectName(QStringLiteral("customB"));

        horizontalLayout->addWidget(customB);


        horizontalLayout_3->addWidget(leftButtons);

        horizontalSpacer = new QSpacerItem(47, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        rightButtons = new QWidget(RsaToolbox__WizardButtons);
        rightButtons->setObjectName(QStringLiteral("rightButtons"));
        horizontalLayout_2 = new QHBoxLayout(rightButtons);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 0, 0, 0);
        customC = new QPushButton(rightButtons);
        customC->setObjectName(QStringLiteral("customC"));
        sizePolicy.setHeightForWidth(customC->sizePolicy().hasHeightForWidth());
        customC->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(customC);

        cancel = new QPushButton(rightButtons);
        cancel->setObjectName(QStringLiteral("cancel"));
        sizePolicy.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(cancel);

        next = new QPushButton(rightButtons);
        next->setObjectName(QStringLiteral("next"));
        sizePolicy.setHeightForWidth(next->sizePolicy().hasHeightForWidth());
        next->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(next);


        horizontalLayout_3->addWidget(rightButtons);


        retranslateUi(RsaToolbox__WizardButtons);

        QMetaObject::connectSlotsByName(RsaToolbox__WizardButtons);
    } // setupUi

    void retranslateUi(QWidget *RsaToolbox__WizardButtons)
    {
        RsaToolbox__WizardButtons->setWindowTitle(QApplication::translate("RsaToolbox::WizardButtons", "Form", 0));
        previous->setText(QApplication::translate("RsaToolbox::WizardButtons", "Previous", 0));
        customA->setText(QApplication::translate("RsaToolbox::WizardButtons", "customA", 0));
        customB->setText(QApplication::translate("RsaToolbox::WizardButtons", "customB", 0));
        customC->setText(QApplication::translate("RsaToolbox::WizardButtons", "customC", 0));
        cancel->setText(QApplication::translate("RsaToolbox::WizardButtons", "Cancel", 0));
        next->setText(QApplication::translate("RsaToolbox::WizardButtons", "Next", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class WizardButtons: public Ui_WizardButtons {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_WIZARDBUTTONS_H
