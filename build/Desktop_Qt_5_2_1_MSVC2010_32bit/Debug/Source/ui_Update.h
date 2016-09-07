/********************************************************************************
** Form generated from reading UI file 'Update.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_H
#define UI_UPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ErrorLabel.h"

namespace RsaToolbox {

class Ui_Update
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *updateFrequencyLabel;
    QComboBox *updateFrequency;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLabel *name;
    QLabel *versionLabel;
    QLabel *version;
    QLabel *latestVersionLabel;
    QLabel *latestVersion;
    QSpacerItem *verticalSpacer;
    RsaToolbox::ErrorLabel *error;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *checkForUpdates;
    QSpacerItem *horizontalSpacer;
    QPushButton *changeLog;
    QPushButton *download;
    QSpacerItem *verticalSpacer_3;
    QProgressBar *progressBar;

    void setupUi(QWidget *RsaToolbox__Update)
    {
        if (RsaToolbox__Update->objectName().isEmpty())
            RsaToolbox__Update->setObjectName(QStringLiteral("RsaToolbox__Update"));
        RsaToolbox__Update->resize(511, 203);
        verticalLayout = new QVBoxLayout(RsaToolbox__Update);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(15, 5, 15, 4);
        widget_3 = new QWidget(RsaToolbox__Update);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        updateFrequencyLabel = new QLabel(widget_3);
        updateFrequencyLabel->setObjectName(QStringLiteral("updateFrequencyLabel"));

        horizontalLayout_2->addWidget(updateFrequencyLabel);

        updateFrequency = new QComboBox(widget_3);
        updateFrequency->setObjectName(QStringLiteral("updateFrequency"));

        horizontalLayout_2->addWidget(updateFrequency);

        horizontalLayout_2->setStretch(0, 1);

        verticalLayout->addWidget(widget_3);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        widget = new QWidget(RsaToolbox__Update);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(15);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        nameLabel->setFont(font);

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        name = new QLabel(widget);
        name->setObjectName(QStringLiteral("name"));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        versionLabel = new QLabel(widget);
        versionLabel->setObjectName(QStringLiteral("versionLabel"));
        versionLabel->setFont(font);

        gridLayout->addWidget(versionLabel, 1, 0, 1, 1);

        version = new QLabel(widget);
        version->setObjectName(QStringLiteral("version"));

        gridLayout->addWidget(version, 1, 1, 1, 1);

        latestVersionLabel = new QLabel(widget);
        latestVersionLabel->setObjectName(QStringLiteral("latestVersionLabel"));
        latestVersionLabel->setFont(font);

        gridLayout->addWidget(latestVersionLabel, 2, 0, 1, 1);

        latestVersion = new QLabel(widget);
        latestVersion->setObjectName(QStringLiteral("latestVersion"));

        gridLayout->addWidget(latestVersion, 2, 1, 1, 1);

        gridLayout->setColumnStretch(1, 1);

        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        error = new RsaToolbox::ErrorLabel(RsaToolbox__Update);
        error->setObjectName(QStringLiteral("error"));

        verticalLayout->addWidget(error);

        widget_2 = new QWidget(RsaToolbox__Update);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkForUpdates = new QPushButton(widget_2);
        checkForUpdates->setObjectName(QStringLiteral("checkForUpdates"));

        horizontalLayout->addWidget(checkForUpdates);

        horizontalSpacer = new QSpacerItem(102, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        changeLog = new QPushButton(widget_2);
        changeLog->setObjectName(QStringLiteral("changeLog"));
        changeLog->setEnabled(false);

        horizontalLayout->addWidget(changeLog);

        download = new QPushButton(widget_2);
        download->setObjectName(QStringLiteral("download"));

        horizontalLayout->addWidget(download);


        verticalLayout->addWidget(widget_2);

        verticalSpacer_3 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        progressBar = new QProgressBar(RsaToolbox__Update);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);


        retranslateUi(RsaToolbox__Update);

        QMetaObject::connectSlotsByName(RsaToolbox__Update);
    } // setupUi

    void retranslateUi(QWidget *RsaToolbox__Update)
    {
        RsaToolbox__Update->setWindowTitle(QApplication::translate("RsaToolbox::Update", "Form", 0));
        updateFrequencyLabel->setText(QApplication::translate("RsaToolbox::Update", "Check for updates:", 0));
        updateFrequency->clear();
        updateFrequency->insertItems(0, QStringList()
         << QApplication::translate("RsaToolbox::Update", "daily", 0)
         << QApplication::translate("RsaToolbox::Update", "weekly", 0)
         << QApplication::translate("RsaToolbox::Update", "monthly", 0)
         << QApplication::translate("RsaToolbox::Update", "never", 0)
        );
        nameLabel->setText(QApplication::translate("RsaToolbox::Update", "Application Name:", 0));
        name->setText(QApplication::translate("RsaToolbox::Update", "R&S Application Name", 0));
        versionLabel->setText(QApplication::translate("RsaToolbox::Update", "Version:", 0));
        version->setText(QApplication::translate("RsaToolbox::Update", "1.0", 0));
        latestVersionLabel->setText(QApplication::translate("RsaToolbox::Update", "Latest Version:", 0));
        latestVersion->setText(QString());
        checkForUpdates->setText(QApplication::translate("RsaToolbox::Update", "Check for Updates", 0));
        changeLog->setText(QApplication::translate("RsaToolbox::Update", "Change Log", 0));
        download->setText(QApplication::translate("RsaToolbox::Update", "Download", 0));
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class Update: public Ui_Update {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_UPDATE_H
