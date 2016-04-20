/********************************************************************************
** Form generated from reading UI file 'TimedProgressBar.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEDPROGRESSBAR_H
#define UI_TIMEDPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

namespace RsaToolbox {

class Ui_TimedProgressBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QWidget *RsaToolbox__TimedProgressBar)
    {
        if (RsaToolbox__TimedProgressBar->objectName().isEmpty())
            RsaToolbox__TimedProgressBar->setObjectName(QStringLiteral("RsaToolbox__TimedProgressBar"));
        RsaToolbox__TimedProgressBar->resize(400, 27);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RsaToolbox__TimedProgressBar->sizePolicy().hasHeightForWidth());
        RsaToolbox__TimedProgressBar->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(RsaToolbox__TimedProgressBar);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(RsaToolbox__TimedProgressBar);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        progressBar = new QProgressBar(RsaToolbox__TimedProgressBar);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        horizontalLayout->setStretch(1, 1);

        retranslateUi(RsaToolbox__TimedProgressBar);

        QMetaObject::connectSlotsByName(RsaToolbox__TimedProgressBar);
    } // setupUi

    void retranslateUi(QWidget *RsaToolbox__TimedProgressBar)
    {
        RsaToolbox__TimedProgressBar->setWindowTitle(QApplication::translate("RsaToolbox::TimedProgressBar", "Form", 0));
        label->setText(QApplication::translate("RsaToolbox::TimedProgressBar", "text", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class TimedProgressBar: public Ui_TimedProgressBar {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_TIMEDPROGRESSBAR_H
