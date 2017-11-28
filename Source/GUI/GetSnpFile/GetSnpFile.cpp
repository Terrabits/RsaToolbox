#include "GetSnpFile.h"
#include "ui_GetSnpFile.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>


GetSnpFile::GetSnpFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GetSnpFile)
{
    ui->setupUi(this);
    setFocusProxy(ui->getButton);
    _lastPath = newLastPath(QDir::homePath());
    clearPorts();
}

GetSnpFile::~GetSnpFile()
{
    delete ui;
}

SharedLastPath GetSnpFile::lastPath() const {
    return _lastPath;
}
void GetSnpFile::setLastPath(SharedLastPath lastPath) {
    _lastPath = lastPath;
}

void GetSnpFile::setPorts(uint ports) {
    _ports = ports;
}
void GetSnpFile::clearPorts() {
    _ports = 0;
}

bool GetSnpFile::isFilePath() const {
    return !_filePath.isEmpty();
}
QString GetSnpFile::filePath() const {
    return _filePath;
}
void GetSnpFile::setFilePath(QString filePath) {
    if (_filePath == filePath)
        return;

        _filePath = filePath;
        _lastPath->setFromFilePath(filePath);
        ui->displayEdit->setText(fileName());
        emit filePathChanged(_filePath);
}

void GetSnpFile::on_getButton_clicked() {
    QString dir;
    if (isFilePath())
        dir = path();
    else
        dir = _lastPath->toString();

    QString result =
            QFileDialog::getOpenFileName(this,
                                         "Choose touchstone file...",
                                         dir,
                                         fileFilter());
    if (!result.isEmpty())
        setFilePath(result);
}

bool GetSnpFile::isAnyPorts() const {
    return _ports == 0;
}
QString GetSnpFile::fileFilter() const {
    const QString filter = "Touchstone file (*.s%1p)";
    if (isAnyPorts()) {
        return filter.arg("*");
    }
    else {
        return filter.arg(_ports);
    }
}

QString GetSnpFile::fileName() const {
    return QFileInfo(_filePath).fileName();
}
QString GetSnpFile::path() const {
    return QFileInfo(_filePath).path();
}
