#ifndef ABOUT_H
#define ABOUT_H


// Qt
#include <QDialog>
#include <QDir>


namespace RsaToolbox {


namespace Ui {
class About;
}
class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

    QString appName() const;
    void setAppName(QString name);

    QString version() const;
    void setVersion(QString version);

    QString description() const;
    void setDescription(QString text);

    QString contactInfo() const;
    void setContactInfo(QString text);

private:
    Ui::About *ui;

    void initializeLicenses();

    static QDir licenseDir();
    static QString rsLicensePath();
    static QString qtLicensePath();
    static QString msvcLicensePath();
    static QString quaZipLicensePath();
    static QString zLibLicensePath();
    static QString qCustomPlotLicensePath();
};
} // RsaToolbox


#endif // ABOUT_H
