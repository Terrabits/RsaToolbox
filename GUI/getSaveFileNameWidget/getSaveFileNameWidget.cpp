#include "getSaveFileNameWidget.h"
#include "ui_getSaveFileNameWidget.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>


getSaveFileNameWidget::getSaveFileNameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::getSaveFileNameWidget)
{
	ui->setupUi(this);
    setFocusProxy(ui->getButton);
    _lastPath = newLastPath(QDir::homePath());
}

getSaveFileNameWidget::~getSaveFileNameWidget()
{
	delete ui;
}

SharedLastPath getSaveFileNameWidget::lastPath() const {
    return _lastPath;
}
void getSaveFileNameWidget::setLastPath(SharedLastPath lastPath) {
    _lastPath = lastPath;
}

bool getSaveFileNameWidget::isFilters() const {
    return !_filters.isEmpty();
}
QString getSaveFileNameWidget::filters() const {
    return _filters;
}
void getSaveFileNameWidget::setFilters(const QString &filters) {
    _filters = filters;
}

bool getSaveFileNameWidget::isFilePath() const {
    return !_filePath.isEmpty();
}
QString getSaveFileNameWidget::filePath() const {
    return _filePath;
}
void getSaveFileNameWidget::setFilePath(const QString &filePath) {
    if (_filePath == filePath)
        return;

        _filePath = filePath;
        _lastPath->setFromFilePath(filePath);
        ui->displayEdit->setText(fileName());
        emit filePathChanged(_filePath);
}

void getSaveFileNameWidget::on_getButton_clicked() {
    QString dir;
    if (isFilePath())
        dir = path();
    else
        dir = _lastPath->toString();

    QString result =
            QFileDialog::getSaveFileName(this,
                                         "Save as...",
                                         dir,
                                         _filters);
    if (!result.isEmpty())
        setFilePath(result);
}

QString getSaveFileNameWidget::fileName() const {
    return QFileInfo(_filePath).fileName();
}
QString getSaveFileNameWidget::path() const {
    return QFileInfo(_filePath).path();
}
