#ifndef GETSNPFILE_H
#define GETSNPFILE_H


// RsaToolbox
#include <LastPath.h>

// Qt
#include <QWidget>


namespace RsaToolbox {

namespace Ui {
class GetSnpFile;
}
class GetSnpFile : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged USER true)

public:
    explicit GetSnpFile(QWidget *parent = 0);
    ~GetSnpFile();

    SharedLastPath lastPath() const;
    void setLastPath(SharedLastPath lastPath);

    void setPorts(uint ports);
    void clearPorts();

    bool isFilePath() const;
    QString filePath() const;
    void setFilePath(QString filePath);

signals:
    void filePathChanged(const QString &filePath);

private slots:
    void on_getButton_clicked();

private:
    Ui::GetSnpFile *ui;
    QString _filePath;

    SharedLastPath _lastPath;

    bool isAnyPorts() const;
    uint    _ports;
    QString fileFilter() const;


    QString fileName() const;
    QString path() const;
};
} // RsaToolbox


#endif // GETSNPFILE_H
