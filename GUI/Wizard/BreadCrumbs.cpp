#include "BreadCrumbs.h"
#include "ui_BreadCrumbs.h"
using namespace RsaToolbox;

BreadCrumbs::BreadCrumbs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BreadCrumbs)
{
    ui->setupUi(this);
    QObject::connect(ui->links, SIGNAL(linkActivated(QString)),
                     this, SLOT(processLinkActivated(QString)));
}

BreadCrumbs::~BreadCrumbs()
{
    delete ui;
}

void BreadCrumbs::setLinks(QStringList previousPages, QString currentPage) {
    QString text = currentPage;
    for (int i = 0; i < previousPages.size(); i++) {
        QString add = "<a href=\"%1\">%2</a><b> >> </b>";
        add = add.arg(i+1);
        add = add.arg(previousPages[i]);
        text.prepend(add);
    }
    ui->links->setText(text);
}
void BreadCrumbs::processLinkActivated(const QString &link) {
    emit back(link.toInt());
}
