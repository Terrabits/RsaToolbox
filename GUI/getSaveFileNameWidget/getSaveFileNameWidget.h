#ifndef GETSAVEFILENAMEWIDGET_H
#define GETSAVEFILENAMEWIDGET_H


// RsaToolbox
#include <LastPath.h>

// Qt
#include <QWidget>

namespace RsaToolbox {

namespace Ui {
class getSaveFileNameWidget;
}
class getSaveFileNameWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged USER true)

public:
    explicit getSaveFileNameWidget(QWidget *parent = 0);
    ~getSaveFileNameWidget();

    SharedLastPath lastPath() const;
    void setLastPath(SharedLastPath lastPath);

    bool isFilters() const;
    QString filters() const;
    void setFilters(const QString &filters);

    bool isFilePath() const;
    QString filePath() const;
    void setFilePath(const QString &filePath);

private slots:
    void on_getButton_clicked();

signals:
    void filePathChanged(const QString &filePath);

private:
    Ui::getSaveFileNameWidget *ui;
    QString _filePath;
    QString fileName() const;
    QString path() const;

    QString _filters;
    SharedLastPath _lastPath;
};
} // RsaToolbox


#endif // GETSAVEFILENAMEWIDGET_H
