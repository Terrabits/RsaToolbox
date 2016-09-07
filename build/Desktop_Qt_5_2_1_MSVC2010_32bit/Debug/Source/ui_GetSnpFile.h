/********************************************************************************
** Form generated from reading UI file 'GetSnpFile.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETSNPFILE_H
#define UI_GETSNPFILE_H

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

class Ui_GetSnpFile
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *displayEdit;
    QPushButton *getButton;

    void setupUi(QWidget *RsaToolbox__GetSnpFile)
    {
        if (RsaToolbox__GetSnpFile->objectName().isEmpty())
            RsaToolbox__GetSnpFile->setObjectName(QStringLiteral("RsaToolbox__GetSnpFile"));
        RsaToolbox__GetSnpFile->resize(305, 23);
        RsaToolbox__GetSnpFile->setFocusPolicy(Qt::StrongFocus);
        horizontalLayout = new QHBoxLayout(RsaToolbox__GetSnpFile);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        displayEdit = new QLineEdit(RsaToolbox__GetSnpFile);
        displayEdit->setObjectName(QStringLiteral("displayEdit"));
        displayEdit->setFocusPolicy(Qt::NoFocus);
        displayEdit->setReadOnly(true);

        horizontalLayout->addWidget(displayEdit);

        getButton = new QPushButton(RsaToolbox__GetSnpFile);
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


        retranslateUi(RsaToolbox__GetSnpFile);

        QMetaObject::connectSlotsByName(RsaToolbox__GetSnpFile);
    } // setupUi

    void retranslateUi(QWidget *RsaToolbox__GetSnpFile)
    {
        RsaToolbox__GetSnpFile->setWindowTitle(QApplication::translate("RsaToolbox::GetSnpFile", "Form", 0));
        getButton->setText(QApplication::translate("RsaToolbox::GetSnpFile", "...", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class GetSnpFile: public Ui_GetSnpFile {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_GETSNPFILE_H
