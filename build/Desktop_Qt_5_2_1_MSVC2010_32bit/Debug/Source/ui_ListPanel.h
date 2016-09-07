/********************************************************************************
** Form generated from reading UI file 'ListPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTPANEL_H
#define UI_LISTPANEL_H

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

class Ui_ListPanel
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *moveDownButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *moveUpButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *deleteButton;

    void setupUi(QWidget *RsaToolbox__ListPanel)
    {
        if (RsaToolbox__ListPanel->objectName().isEmpty())
            RsaToolbox__ListPanel->setObjectName(QStringLiteral("RsaToolbox__ListPanel"));
        RsaToolbox__ListPanel->resize(92, 23);
        horizontalLayout = new QHBoxLayout(RsaToolbox__ListPanel);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(RsaToolbox__ListPanel);
        addButton->setObjectName(QStringLiteral("addButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);
        addButton->setMinimumSize(QSize(23, 23));
        addButton->setMaximumSize(QSize(23, 23));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        addButton->setFont(font);

        horizontalLayout->addWidget(addButton);

        horizontalSpacer_5 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        moveDownButton = new QPushButton(RsaToolbox__ListPanel);
        moveDownButton->setObjectName(QStringLiteral("moveDownButton"));
        sizePolicy.setHeightForWidth(moveDownButton->sizePolicy().hasHeightForWidth());
        moveDownButton->setSizePolicy(sizePolicy);
        moveDownButton->setMinimumSize(QSize(23, 23));
        moveDownButton->setMaximumSize(QSize(23, 23));

        horizontalLayout->addWidget(moveDownButton);

        horizontalSpacer_6 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        moveUpButton = new QPushButton(RsaToolbox__ListPanel);
        moveUpButton->setObjectName(QStringLiteral("moveUpButton"));
        sizePolicy.setHeightForWidth(moveUpButton->sizePolicy().hasHeightForWidth());
        moveUpButton->setSizePolicy(sizePolicy);
        moveUpButton->setMinimumSize(QSize(23, 23));
        moveUpButton->setMaximumSize(QSize(23, 23));

        horizontalLayout->addWidget(moveUpButton);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        deleteButton = new QPushButton(RsaToolbox__ListPanel);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setMinimumSize(QSize(23, 23));
        deleteButton->setMaximumSize(QSize(23, 23));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        deleteButton->setFont(font1);

        horizontalLayout->addWidget(deleteButton);


        retranslateUi(RsaToolbox__ListPanel);

        QMetaObject::connectSlotsByName(RsaToolbox__ListPanel);
    } // setupUi

    void retranslateUi(QWidget *RsaToolbox__ListPanel)
    {
        RsaToolbox__ListPanel->setWindowTitle(QApplication::translate("RsaToolbox::ListPanel", "Form", 0));
        addButton->setText(QApplication::translate("RsaToolbox::ListPanel", "+", 0));
        moveDownButton->setText(QApplication::translate("RsaToolbox::ListPanel", "\342\226\274", 0));
        moveUpButton->setText(QApplication::translate("RsaToolbox::ListPanel", "\342\226\262", 0));
        deleteButton->setText(QApplication::translate("RsaToolbox::ListPanel", "-", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class ListPanel: public Ui_ListPanel {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_LISTPANEL_H
