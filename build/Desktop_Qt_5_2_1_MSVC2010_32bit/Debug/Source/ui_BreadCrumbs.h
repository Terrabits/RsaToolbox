/********************************************************************************
** Form generated from reading UI file 'BreadCrumbs.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREADCRUMBS_H
#define UI_BREADCRUMBS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

namespace RsaToolbox {

class Ui_BreadCrumbs
{
public:
    QGridLayout *gridLayout;
    QWidget *backgroundWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *links;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *RsaToolbox__BreadCrumbs)
    {
        if (RsaToolbox__BreadCrumbs->objectName().isEmpty())
            RsaToolbox__BreadCrumbs->setObjectName(QStringLiteral("RsaToolbox__BreadCrumbs"));
        RsaToolbox__BreadCrumbs->resize(373, 35);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RsaToolbox__BreadCrumbs->sizePolicy().hasHeightForWidth());
        RsaToolbox__BreadCrumbs->setSizePolicy(sizePolicy);
        RsaToolbox__BreadCrumbs->setMinimumSize(QSize(0, 35));
        RsaToolbox__BreadCrumbs->setMaximumSize(QSize(16777215, 35));
        QFont font;
        font.setPointSize(12);
        RsaToolbox__BreadCrumbs->setFont(font);
        RsaToolbox__BreadCrumbs->setStyleSheet(QLatin1String("#backgroundWidget {\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"												stop: 0.0 rgb(205, 210, 255),\n"
"												stop: 0.7 rgb(205, 210, 255),\n"
"												stop: 1.0 rgb(45, 66, 255))\n"
"}"));
        gridLayout = new QGridLayout(RsaToolbox__BreadCrumbs);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        backgroundWidget = new QWidget(RsaToolbox__BreadCrumbs);
        backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));
        horizontalLayout = new QHBoxLayout(backgroundWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 3, 0, -1);
        links = new QLabel(backgroundWidget);
        links->setObjectName(QStringLiteral("links"));
        links->setFont(font);

        horizontalLayout->addWidget(links);

        horizontalSpacer = new QSpacerItem(286, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(backgroundWidget, 0, 0, 1, 1);


        retranslateUi(RsaToolbox__BreadCrumbs);

        QMetaObject::connectSlotsByName(RsaToolbox__BreadCrumbs);
    } // setupUi

    void retranslateUi(QWidget *RsaToolbox__BreadCrumbs)
    {
        RsaToolbox__BreadCrumbs->setWindowTitle(QApplication::translate("RsaToolbox::BreadCrumbs", "Form", 0));
        links->setText(QApplication::translate("RsaToolbox::BreadCrumbs", "First Page", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class BreadCrumbs: public Ui_BreadCrumbs {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_BREADCRUMBS_H
