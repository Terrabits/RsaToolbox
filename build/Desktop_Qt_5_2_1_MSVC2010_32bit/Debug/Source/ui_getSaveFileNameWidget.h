/********************************************************************************
** Form generated from reading UI file 'getSaveFileNameWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETSAVEFILENAMEWIDGET_H
#define UI_GETSAVEFILENAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

namespace RsaToolbox {

class Ui_getSaveFileNameWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *displayEdit;
    QPushButton *getButton;

    void setupUi(QWidget *RsaToolbox__getSaveFileNameWidget)
    {
        if (RsaToolbox__getSaveFileNameWidget->objectName().isEmpty())
            RsaToolbox__getSaveFileNameWidget->setObjectName(QStringLiteral("RsaToolbox__getSaveFileNameWidget"));
        RsaToolbox__getSaveFileNameWidget->resize(305, 23);
        RsaToolbox__getSaveFileNameWidget->setFocusPolicy(Qt::StrongFocus);
        horizontalLayout = new QHBoxLayout(RsaToolbox__getSaveFileNameWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        displayEdit = new QLineEdit(RsaToolbox__getSaveFileNameWidget);
        displayEdit->setObjectName(QStringLiteral("displayEdit"));
        displayEdit->setFocusPolicy(Qt::NoFocus);
        displayEdit->setReadOnly(true);

        horizontalLayout->addWidget(displayEdit);

        getButton = new QPushButton(RsaToolbox__getSaveFileNameWidget);
        getButton->setObjectName(QStringLiteral("getButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(getButton->sizePolicy().hasHeightForWidth());
        getButton->setSizePolicy(sizePolicy);
        getButton->setMinimumSize(QSize(31, 23));
        getButton->setMaximumSize(QSize(31, 23));
        getButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(getButton);


        retranslateUi(RsaToolbox__getSaveFileNameWidget);

        QMetaObject::connectSlotsByName(RsaToolbox__getSaveFileNameWidget);
    } // setupUi

    void retranslateUi(QWidget *RsaToolbox__getSaveFileNameWidget)
    {
        RsaToolbox__getSaveFileNameWidget->setWindowTitle(QApplication::translate("RsaToolbox::getSaveFileNameWidget", "Form", 0));
        getButton->setText(QApplication::translate("RsaToolbox::getSaveFileNameWidget", "...", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class getSaveFileNameWidget: public Ui_getSaveFileNameWidget {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_GETSAVEFILENAMEWIDGET_H
