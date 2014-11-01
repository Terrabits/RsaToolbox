#ifndef CALDIALOG_H
#define CALDIALOG_H

#include "CalGroupsModel.h"
#include "QItemSelectionModel"

#include <QDialog>
#include <QStatusBar>

namespace RsaToolbox {

namespace Ui {
class CalDialog;
}
class CalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalDialog(QWidget *parent = 0);
    ~CalDialog();

    void setModel(CalGroupsModel *model, int column = 0);
    CalGroupsModel *model() const;

    QModelIndex selectedIndex() const;

signals:
    void selectionChanged(QItemSelection,QItemSelection);

public slots:
    void accept();
    void reject();
    void reset();

private:
    Ui::CalDialog *ui;
    CalGroupsModel *_model;
    QPersistentModelIndex _previous;

    QItemSelectionModel *selectionModel() const;
};
} // RsaToolbox


#endif // CALDIALOG_H
