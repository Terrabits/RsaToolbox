#include "Update.h"
#include "ui_Update.h"


// RsaToolbox
#include "Version.h"
using namespace RsaToolbox;

// Qt
#include <QJsonDocument>
#include <QFileDialog>
#include <QDir>
#include <QStandardPaths>
#include <QMessageBox>
#include <QDebug>


Update::Update(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Update),
    _keys(NULL),
    _interval(Interval::daily),
    _reply(NULL),
    _isAutomaticUpdate(false)
{
    ui->setupUi(this);
    initializeGui();
}

Update::Update(Keys *keys, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Update),
    _keys(keys),
    _interval(Interval::daily),
    _reply(NULL),
    _isAutomaticUpdate(false)
{
    ui->setupUi(this);
    initializeGui();
}

Update::~Update()
{
    delete ui;
}

bool Update::isUpdateDue() const {
    if (_interval == Interval::never)
        return false;
    if (_lastUpdate.isNull())
        return true;

    QDateTime nextUpdate(_lastUpdate);
    switch(_interval) {
    case Interval::daily:
        nextUpdate = nextUpdate.addDays(1);
        break;
    case Interval::weekly:
        nextUpdate = nextUpdate.addDays(7);
        break;
    case Interval::monthly:
        nextUpdate = nextUpdate.addMonths(1);
        break;
    }

    return QDateTime::currentDateTime() >= nextUpdate;
}
Update::Interval Update::interval() const {
    return _interval;
}
void Update::setInterval(Interval interval) {
    _interval = interval;
    ui->updateFrequency->setCurrentIndex(_interval);
    saveIntervalKey();
}

void Update::setApplicationName(const QString &name) {
    _applicationName = name;
    ui->name->setText(name);
}
void Update::setApplicationVersion(const QString &version) {
    _version = version;
    ui->version->setText(version);
}
void Update::setJsonUrl(const QString &url) {
    _jsonUrl = url;
}

void Update::automaticUpdate() {
    _isAutomaticUpdate = true;
    ui->checkForUpdates->hide();
    ui->changeLog->setDisabled(true);
    ui->download->setDisabled(true);
    downloadJson();
}
void Update::manualUpdate() {
    _isAutomaticUpdate = false;
    ui->checkForUpdates->show();
    ui->checkForUpdates->setEnabled(true);
    ui->changeLog->setDisabled(true);
    ui->download->setDisabled(true);
    this->show();
}

void Update::downloadJson() {
    connect(&_manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(jsonFinished()));
    _request.setUrl(QUrl(_jsonUrl));
    _reply = _manager.get(_request);
}
void Update::jsonFinished() {
    if (_reply == NULL) {
        return;
    }
    if (!_reply->isFinished()) {
        return;
    }
    if (_reply->error() != QNetworkReply::NoError) {
        emit error(_reply->errorString());
        ui->error->showMessage(_reply->errorString());
        _reply->deleteLater();
        return;
    }

    QJsonDocument document = QJsonDocument::fromJson(_reply->readAll());
    if (document.isNull() || document.isEmpty() || !document.isObject()) {
        _json = QJsonObject();
        QString msg = "*Error retrieving update info.";
        emit error(msg);
        ui->error->showMessage(msg);
        _reply->deleteLater();
        return;
    }
    _json = document.object();
    if (latestVersion().isEmpty() || downloadUrl().isEmpty()) {
        _json = QJsonObject();
        QString msg = "*Error retrieving update info.";
        emit error(msg);
        ui->error->showMessage(msg);
        _reply->deleteLater();
        return;
    }

    ui->latestVersion->setText(latestVersion());

    bool isNewVersion = (Version(_version) < Version(latestVersion()));
    if (isNewVersion) {
        if (!changeLog().isEmpty())
            ui->changeLog->setEnabled(true);
        ui->download->setEnabled(true);
        ui->error->showMessage("*An update is available", Qt::darkGreen);
        if (_isAutomaticUpdate)
            this->show();
    }
    else {
        ui->download->setDisabled(true);
        ui->error->showMessage("*Application is up to date", Qt::darkGreen);
    }

    disconnect(&_manager, SIGNAL(finished(QNetworkReply*)),
               this, SLOT(jsonFinished()));
    _reply->deleteLater();
    saveLastUpdateKey();
}

void Update::requestDownloadHeader() {
    _request.setUrl(downloadUrl());
    connect(&_manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(downloadUpdate()));
    _reply = _manager.head(_request);
}

void Update::downloadUpdate() {
    disconnect(&_manager, SIGNAL(finished(QNetworkReply*)),
               this, SLOT(downloadUpdate()));

    QString headerFilename;
    if (_reply->hasRawHeader("Content-Disposition")) {
        headerFilename = QString::fromUtf8(_reply->rawHeader("Content-Disposition"));
        if (!headerFilename.isEmpty() && headerFilename.contains('=')) {
            int i = headerFilename.indexOf('=');
            headerFilename = headerFilename.mid(i+1);
            headerFilename.remove('\"');
            headerFilename = QUrl::fromPercentEncoding(headerFilename.toUtf8());
        }
        else {
            headerFilename.clear();
        }
    }
    if (headerFilename.isEmpty()) {
        headerFilename = "R&S %1 %2.msi";
        headerFilename = headerFilename.arg(_applicationName);
        headerFilename = headerFilename.arg(latestVersion());
    }

    QDir downloadDir(QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).first());
    QString filename = QFileDialog::getSaveFileName(this,
                                                    "Save as...",
                                                    downloadDir.filePath(headerFilename),
                                                    "Windows Installer (*.msi)");
    if (filename.isEmpty())
        return;

    _file.setFileName(filename);
    if (!_file.open(QFile::WriteOnly)) {
        QString msg = "*Could not write to file";
        emit error(msg);
        ui->error->showMessage(msg);
        return;
    }

    connect(&_manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(downloadFinished()));
    _request.setUrl(downloadUrl());
    _reply = _manager.get(_request);
    connect(_reply, SIGNAL(readyRead()),
            this, SLOT(writeDownloadDataToFile()));
    connect(_reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(updateDownloadProgress(qint64,qint64)));
}
void Update::updateDownloadProgress(qint64 bytesReceived, qint64 totalBytes) {
    ui->progressBar->show();
    ui->progressBar->setMinimum(0);
    if (totalBytes <= 0) {
        ui->progressBar->setMaximum(0);
    }
    else {
        ui->progressBar->setMaximum(totalBytes);
        ui->progressBar->setValue(bytesReceived);
    }
}
void Update::writeDownloadDataToFile() {
    _file.write(_reply->readAll());
}

void Update::downloadFinished() {
    disconnect(&_manager, SIGNAL(finished(QNetworkReply*)),
               this, SLOT(downloadFinished()));
    disconnect(_reply, SIGNAL(readyRead()),
            this, SLOT(writeDownloadDataToFile()));
    disconnect(_reply, SIGNAL(downloadProgress(qint64,qint64)),
               this, SLOT(updateDownloadProgress(qint64,qint64)));
    ui->progressBar->hide();
    _file.flush();
    _file.close();
    QMessageBox::information(this,
                             "Update",
                             "Download finished!\nPlease close this application and run the installer.");
}

void Update::initializeGui() {
    setWindowTitle("Update");
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    ui->progressBar->hide();
    connect(ui->checkForUpdates, SIGNAL(clicked()),
            this, SLOT(downloadJson()));
    connect(ui->download, SIGNAL(clicked()),
            this, SLOT(requestDownloadHeader()));
    ui->updateFrequency->setCurrentIndex(int(_interval));
    loadKeys();
}

bool Update::isKeys() const {
    return _keys != NULL;
}

void Update::loadKeys() {
    if (!isKeys())
        return;

    if (_keys->exists("UPDATE_INTERVAL")) {
        uint interval;
        _keys->get("UPDATE_INTERVAL", interval);
        _interval = Interval(interval);
        ui->updateFrequency->setCurrentIndex(interval);
    }

    if (_keys->exists("LAST_UPDATE")) {
        _keys->get("LAST_UPDATE", _lastUpdate);
    }
}
void Update::saveIntervalKey() {
    if (!isKeys())
        return;

    _keys->set("UPDATE_INTERVAL", uint(_interval));
}
void Update::saveLastUpdateKey() {
    if (!isKeys())
        return;

    _keys->set("LAST_UPDATE", QDateTime::currentDateTime());
}

QString Update::latestVersion() const {
    return _json["version"].toString();
}
QString Update::changeLog() const {
    return _json["change_log"].toString();
}
QUrl Update::downloadUrl() const {
    return QUrl(_json["download_url"].toString());
}

void RsaToolbox::Update::on_updateFrequency_currentIndexChanged(int index)
{
    _interval = Interval(index);
    saveIntervalKey();
}
