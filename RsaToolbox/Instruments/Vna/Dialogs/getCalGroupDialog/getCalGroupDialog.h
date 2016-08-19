#ifndef GET_CALGROUP_DIALOG_H
#define GET_CALGROUP_DIALOG_H

#include "CalGroupsModel.h"
#include "QItemSelectionModel"

#include <QDialog>
#include <QStatusBar>

namespace RsaToolbox {

namespace Ui {
class getCalGroupDialog;
}
class getCalGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit getCalGroupDialog(QWidget *parent = 0);
    ~getCalGroupDialog();

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
    Ui::getCalGroupDialog *ui;
    CalGroupsModel *_model;
    QPersistentModelIndex _previous;

    QItemSelectionModel *selectionModel() const;
};
} // RsaToolbox


#endif // GET_CALGROUP_DIALOG_H
