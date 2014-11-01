#include "GetSnpFile.h"
#include "ui_GetSnpFile.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
using namespace RsaToolbox;

GetSnpFile::GetSnpFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GetSnpFile)
{
    ui->setupUi(this);
    setFocusProxy(ui->getButton);
}

GetSnpFile::~GetSnpFile()
{
    delete ui;
}

QString GetSnpFile::filePath() const {
    return(_filePath);
}
void GetSnpFile::setFilePath(QString filePath) {
    if (_filePath != filePath) {
        _filePath = filePath;
        ui->displayEdit->setText(QFileInfo(_filePath).fileName());
        emit filePathChanged(_filePath);
    }
}

void GetSnpFile::on_getButton_clicked() {
    QString start = QFileInfo(_filePath).path();
    if (start == ".")
        start = QDir::homePath();
    QString filePath =
            QFileDialog::getOpenFileName(this,
                                         "Choose touchstone file...",
                                         start,
                                         "Touchstone file (*.s*p)");
    if (filePath.isEmpty())
        return;
    // Else
    setFilePath(filePath);
}
