#ifndef BREADCRUMBS_H
#define BREADCRUMBS_H

#include <QWidget>

namespace RsaToolbox {

namespace Ui {
class BreadCrumbs;
}
class BreadCrumbs : public QWidget
{
    Q_OBJECT

public:
    explicit BreadCrumbs(QWidget *parent = 0);
    ~BreadCrumbs();

signals:
    void back(int pagesBack);

public slots:
    void setLinks(QStringList previousPages, QString currentPage);

private slots:
    void processLinkActivated(const QString &link);

private:
    Ui::BreadCrumbs *ui;


};
} // RsaToolbox


#endif // BREADCRUMBS_H
