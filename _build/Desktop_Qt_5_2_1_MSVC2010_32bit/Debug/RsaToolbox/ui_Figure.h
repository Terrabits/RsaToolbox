/********************************************************************************
** Form generated from reading UI file 'Figure.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGURE_H
#define UI_FIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Figure
{
public:

    void setupUi(QWidget *Figure)
    {
        if (Figure->objectName().isEmpty())
            Figure->setObjectName(QStringLiteral("Figure"));
        Figure->resize(400, 300);

        retranslateUi(Figure);

        QMetaObject::connectSlotsByName(Figure);
    } // setupUi

    void retranslateUi(QWidget *Figure)
    {
        Figure->setWindowTitle(QApplication::translate("Figure", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Figure: public Ui_Figure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGURE_H
