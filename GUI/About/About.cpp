#include "About.h"
#include "ui_About.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QCoreApplication>
#include <QMessageBox>


About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    initializeLicenses();
    ui->licenseCombo->setCurrentIndex(0);
    ui->licenses->setCurrentIndex(0);
    QObject::connect(ui->licenseCombo, SIGNAL(currentIndexChanged(int)),
                     ui->licenses, SLOT(setCurrentIndex(int)));

#ifdef DEBUG_MODE
    QMessageBox::warning(this, "Debug warning",
                         "The about window may not display licenses in debug mode.");
#endif
}

About::~About()
{
    delete ui;
}

QString About::appName() const {
    return ui->appName->text();
}
void About::setAppName(QString name) {
    ui->appName->setText(name);
}

QString About::version() const {
    return ui->version->text();
}
void About::setVersion(QString version) {
    ui->version->setText(version);
}

QString About::description() const {
    return ui->description->text();
}
void About::setDescription(QString text) {
    ui->description->setText(text);
}

QString About::contactInfo() const {
    return ui->contact->text();
}
void About::setContactInfo(QString text) {
    ui->contact->setText(text);
}

void About::initializeLicenses() {

    // R&S
    QFile file(rsLicensePath());
    if (file.open(QFile::ReadOnly)) {
        ui->rsLicense->setText(file.readAll());
        file.close();
    }
    else {
        ui->rsLicense->clear();
    }

    // Qt
    file.setFileName(qtLicensePath());
    if (file.open(QFile::ReadOnly)) {
        ui->qtLicense->setText(file.readAll());
        file.close();
    }
    else {
        ui->qtLicense->clear();
    }

    // Msvc
    file.setFileName(msvcLicensePath());
    if (file.open(QFile::ReadOnly)) {
        ui->msvcLicense->setText(file.readAll());
        file.close();
    }
    else {
        ui->msvcLicense->clear();
    }

    // QuaZIP
    file.setFileName(quaZipLicensePath());
    if (file.open(QFile::ReadOnly)) {
        ui->quaZipLicense->setText(file.readAll());
        file.close();
    }
    else {
        ui->quaZipLicense->clear();
    }

    // ZLib
    file.setFileName(zLibLicensePath());
    if (file.open(QFile::ReadOnly)) {
        ui->zLibLicense->setText(file.readAll());
        file.close();
    }
    else {
        ui->zLibLicense->clear();
    }

    // QCustomPlot
    file.setFileName(qCustomPlotLicensePath());
    if (file.open(QFile::ReadOnly)) {
        ui->qCustomPlotLicense->setText(file.readAll());
        file.close();
    }
    else {
        ui->qCustomPlotLicense->clear();
    }
}

QDir About::licenseDir() {
    QDir dir(QCoreApplication::applicationDirPath());
    dir.cd("Licenses");
    return dir;
}
QString About::rsLicensePath() {
    QRegExp regexp("^.*R&S.*(\\.txt)$", Qt::CaseInsensitive);
    QDir dir = licenseDir();
    QStringList files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name);
    foreach (QString file, files) {
        if (file.contains(regexp))
            return dir.filePath(file);
    }

    return "";
}
QString About::qtLicensePath() {
    QRegExp regexp("^.*Qt.*(\\.txt)$", Qt::CaseInsensitive);
    QDir dir = licenseDir();
    QStringList files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name);
    foreach (QString file, files) {
        if (file.contains(regexp))
            return dir.filePath(file);
    }

    return "";
}
QString About::msvcLicensePath() {
    QRegExp regexp("^.*Microsoft.*(\\.txt)$", Qt::CaseInsensitive);
    QDir dir = licenseDir();
    QStringList files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
    foreach (QString file, files) {
        if (file.contains(regexp))
            return dir.filePath(file);
    }

    return "";
}
QString About::quaZipLicensePath() {
    QRegExp regexp("^.*QuaZip.*(\\.txt)$", Qt::CaseInsensitive);
    QDir dir = licenseDir();
    QStringList files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
    foreach (QString file, files) {
        if (file.contains(regexp))
            return dir.filePath(file);
    }

    return "";
}
QString About::zLibLicensePath() {
    QRegExp regexp("^.*ZLib.*(\\.txt)$", Qt::CaseInsensitive);
    QDir dir = licenseDir();
    QStringList files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
    foreach (QString file, files) {
        if (file.contains(regexp))
            return dir.filePath(file);
    }

    return "";
}
QString About::qCustomPlotLicensePath() {
    QRegExp regexp("^.*QCustomPlot.*(\\.txt)$", Qt::CaseInsensitive);
    QDir dir = licenseDir();
    QStringList files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
    foreach (QString file, files) {
        if (file.contains(regexp))
            return dir.filePath(file);
    }

    return "";
}
