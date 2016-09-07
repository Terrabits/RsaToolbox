#ifndef UPDATE_H
#define UPDATE_H


// RsaToolbox
#include "Keys.h"

// Qt
#include <QWidget>
#include <QString>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QDateTime>
#include <QScopedPointer>


namespace RsaToolbox {


namespace Ui {
class Update;
}
class Update : public QWidget
{
    Q_OBJECT

public:
    enum /*class*/ Interval {
        daily = 0,
        weekly = 1,
        monthly = 2,
        never = 3
    };

    explicit Update(QWidget *parent = 0);
    Update(Keys *keys, QWidget *parent = 0);
    ~Update();

    bool isUpdateDue() const;
    Interval interval() const;
    void setInterval(Interval interval);

    void setApplicationName(const QString &name);
    void setApplicationVersion(const QString &version);
    void setJsonUrl(const QString &url);

public slots:
    void automaticUpdate();
    void manualUpdate();

signals:
    void updateAvailable();
    void error(const QString &message);

private slots:
    void downloadJson();
    void jsonFinished();

    void requestDownloadHeader();
    void downloadUpdate();
    void updateDownloadProgress(qint64 bytesReceived, qint64 totalBytes);
    void writeDownloadDataToFile();
    void downloadFinished();
//    void downloadError(const QString &error);

    void on_updateFrequency_currentIndexChanged(int index);

private:
    Ui::Update *ui;
    void initializeGui();

    bool isKeys() const;
    Keys *_keys;
    Interval _interval;
    QDateTime _lastUpdate;
    void loadKeys();
    void saveIntervalKey();
    void saveLastUpdateKey();

    // State
    bool _isAutomaticUpdate;

    // Application Info:
    QString _applicationName;
    QString _version;
    QString _jsonUrl;

    // Http
    QNetworkAccessManager _manager;
    QNetworkRequest _request;
    QNetworkReply *_reply;

    // Json
    QByteArray _jsonBuffer;
    QJsonObject _json; // .isEmpty()?
    QString latestVersion() const;
    QString changeLog() const;
    QUrl downloadUrl() const;

    // Download
    QFile _file;
};
} // RsaToolbox


#endif // UPDATE_H
