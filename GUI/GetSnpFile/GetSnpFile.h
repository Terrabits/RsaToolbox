#ifndef GETSNPFILE_H
#define GETSNPFILE_H

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

    QString filePath() const;
    void setFilePath(QString filePath);

signals:
    void filePathChanged(const QString &filePath);

private slots:
    void on_getButton_clicked();

private:
    Ui::GetSnpFile *ui;
    QString _filePath;
};

} // RsaToolbox


#endif // GETSNPFILE_H
