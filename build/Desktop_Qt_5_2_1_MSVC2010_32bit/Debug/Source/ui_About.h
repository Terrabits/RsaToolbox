/********************************************************************************
** Form generated from reading UI file 'About.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace RsaToolbox {

class Ui_About
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *appName;
    QSpacerItem *horizontalSpacer_3;
    QLabel *version;
    QSpacerItem *horizontalSpacer_2;
    QLabel *description;
    QSpacerItem *verticalSpacer_2;
    QLabel *contact;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *licenseCombo;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *licenses;
    QWidget *landing;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QWidget *rs;
    QGridLayout *gridLayout_2;
    QTextEdit *rsLicense;
    QWidget *qt;
    QGridLayout *gridLayout_3;
    QTextEdit *qtLicense;
    QWidget *msvc;
    QGridLayout *gridLayout_4;
    QTextEdit *msvcLicense;
    QWidget *quaZip;
    QGridLayout *gridLayout_5;
    QTextEdit *quaZipLicense;
    QWidget *zLib;
    QGridLayout *gridLayout_6;
    QTextEdit *zLibLicense;
    QWidget *qCustomPlot;
    QGridLayout *gridLayout_7;
    QTextEdit *qCustomPlotLicense;

    void setupUi(QWidget *RsaToolbox__About)
    {
        if (RsaToolbox__About->objectName().isEmpty())
            RsaToolbox__About->setObjectName(QStringLiteral("RsaToolbox__About"));
        RsaToolbox__About->resize(545, 510);
        QIcon icon;
        icon.addFile(QStringLiteral(":/About/Icons/RS.ico"), QSize(), QIcon::Normal, QIcon::Off);
        RsaToolbox__About->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(RsaToolbox__About);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        widget_2 = new QWidget(RsaToolbox__About);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        appName = new QLabel(widget_2);
        appName->setObjectName(QStringLiteral("appName"));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        appName->setFont(font);

        horizontalLayout_2->addWidget(appName);

        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        version = new QLabel(widget_2);
        version->setObjectName(QStringLiteral("version"));
        version->setFont(font);

        horizontalLayout_2->addWidget(version);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_2);

        description = new QLabel(RsaToolbox__About);
        description->setObjectName(QStringLiteral("description"));
        QFont font1;
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        description->setFont(font1);
        description->setWordWrap(true);

        verticalLayout->addWidget(description);

        verticalSpacer_2 = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        contact = new QLabel(RsaToolbox__About);
        contact->setObjectName(QStringLiteral("contact"));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        contact->setFont(font2);

        verticalLayout->addWidget(contact);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        widget = new QWidget(RsaToolbox__About);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        licenseCombo = new QComboBox(widget);
        licenseCombo->setObjectName(QStringLiteral("licenseCombo"));

        horizontalLayout->addWidget(licenseCombo);

        horizontalSpacer = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        licenses = new QStackedWidget(RsaToolbox__About);
        licenses->setObjectName(QStringLiteral("licenses"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        licenses->setPalette(palette);
        landing = new QWidget();
        landing->setObjectName(QStringLiteral("landing"));
        gridLayout = new QGridLayout(landing);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        label = new QLabel(landing);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(515, 249));
        label->setPixmap(QPixmap(QString::fromUtf8(":/About/Images/RS_Munich.png")));
        label->setScaledContents(false);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        licenses->addWidget(landing);
        rs = new QWidget();
        rs->setObjectName(QStringLiteral("rs"));
        gridLayout_2 = new QGridLayout(rs);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        rsLicense = new QTextEdit(rs);
        rsLicense->setObjectName(QStringLiteral("rsLicense"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        rsLicense->setPalette(palette1);
        rsLicense->setReadOnly(true);

        gridLayout_2->addWidget(rsLicense, 0, 0, 1, 1);

        licenses->addWidget(rs);
        qt = new QWidget();
        qt->setObjectName(QStringLiteral("qt"));
        gridLayout_3 = new QGridLayout(qt);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        qtLicense = new QTextEdit(qt);
        qtLicense->setObjectName(QStringLiteral("qtLicense"));
        qtLicense->setReadOnly(true);

        gridLayout_3->addWidget(qtLicense, 0, 0, 1, 1);

        licenses->addWidget(qt);
        msvc = new QWidget();
        msvc->setObjectName(QStringLiteral("msvc"));
        gridLayout_4 = new QGridLayout(msvc);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        msvcLicense = new QTextEdit(msvc);
        msvcLicense->setObjectName(QStringLiteral("msvcLicense"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        msvcLicense->setPalette(palette2);
        msvcLicense->setReadOnly(true);

        gridLayout_4->addWidget(msvcLicense, 0, 0, 1, 1);

        licenses->addWidget(msvc);
        quaZip = new QWidget();
        quaZip->setObjectName(QStringLiteral("quaZip"));
        gridLayout_5 = new QGridLayout(quaZip);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        quaZipLicense = new QTextEdit(quaZip);
        quaZipLicense->setObjectName(QStringLiteral("quaZipLicense"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        quaZipLicense->setPalette(palette3);
        quaZipLicense->setReadOnly(true);

        gridLayout_5->addWidget(quaZipLicense, 0, 0, 1, 1);

        licenses->addWidget(quaZip);
        zLib = new QWidget();
        zLib->setObjectName(QStringLiteral("zLib"));
        gridLayout_6 = new QGridLayout(zLib);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        zLibLicense = new QTextEdit(zLib);
        zLibLicense->setObjectName(QStringLiteral("zLibLicense"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        zLibLicense->setPalette(palette4);
        zLibLicense->setReadOnly(true);

        gridLayout_6->addWidget(zLibLicense, 0, 0, 1, 1);

        licenses->addWidget(zLib);
        qCustomPlot = new QWidget();
        qCustomPlot->setObjectName(QStringLiteral("qCustomPlot"));
        gridLayout_7 = new QGridLayout(qCustomPlot);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        qCustomPlotLicense = new QTextEdit(qCustomPlot);
        qCustomPlotLicense->setObjectName(QStringLiteral("qCustomPlotLicense"));
        qCustomPlotLicense->setReadOnly(true);

        gridLayout_7->addWidget(qCustomPlotLicense, 0, 0, 1, 1);

        licenses->addWidget(qCustomPlot);

        verticalLayout->addWidget(licenses);

        verticalLayout->setStretch(6, 1);

        retranslateUi(RsaToolbox__About);

        licenses->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RsaToolbox__About);
    } // setupUi

    void retranslateUi(QWidget *RsaToolbox__About)
    {
        RsaToolbox__About->setWindowTitle(QApplication::translate("RsaToolbox::About", "About", 0));
        appName->setText(QApplication::translate("RsaToolbox::About", "Application Name", 0));
        version->setText(QApplication::translate("RsaToolbox::About", "Version", 0));
        description->setText(QApplication::translate("RsaToolbox::About", "Description", 0));
        contact->setText(QApplication::translate("RsaToolbox::About", "<html><head/><body><p>Nick Lalic<br/>VNA Software Developer<br/>Cupertino, CA USA<br/>+1 424 200 2846<br/>nick.lalic@rsa.rohde-schwarz.com<br/><a href=\"http://vna.rs-us.net\"><span style=\" text-decoration: underline; color:#0000ff;\">http://vna.rs-us.net</span></a></p></body></html>", 0));
        label_2->setText(QApplication::translate("RsaToolbox::About", "License:", 0));
        licenseCombo->clear();
        licenseCombo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("RsaToolbox::About", "Rohde & Schwarz", 0)
         << QApplication::translate("RsaToolbox::About", "Qt", 0)
         << QApplication::translate("RsaToolbox::About", "Microsoft Visual C++", 0)
         << QApplication::translate("RsaToolbox::About", "QuaZIP", 0)
         << QApplication::translate("RsaToolbox::About", "ZLib", 0)
         << QApplication::translate("RsaToolbox::About", "QCustomPlot", 0)
        );
        label->setText(QString());
    } // retranslateUi

};

} // namespace RsaToolbox

namespace RsaToolbox {
namespace Ui {
    class About: public Ui_About {};
} // namespace Ui
} // namespace RsaToolbox

#endif // UI_ABOUT_H
