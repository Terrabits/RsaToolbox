#ifndef CALGROUP_PANEL_H
#define CALGROUP_PANEL_H


#include "CalGroupsModel.h"
#include "getCalGroupDialog.h"

#include <QWidget>
#include <QItemSelectionModel>


namespace RsaToolbox {

namespace Ui {
class CalGroupPanel;
}
class CalGroupPanel : public QWidget
{
    Q_OBJECT

public:
    explicit CalGroupPanel(QWidget *parent = 0);
    ~CalGroupPanel();

    void setModel(CalGroupsModel *model);
    CalGroupsModel *model() const;
    QItemSelectionModel *selectionModel() const;
    void reset();

signals:
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

private slots:
    void dialogAccepted();
    void changeSelection(const QItemSelection &selected, const QItemSelection &deselected);

private:
    Ui::CalGroupPanel *ui;

    CalGroupsModel *_model;
    QScopedPointer<QItemSelectionModel> _selection;
    getCalGroupDialog _dialog;
};
} // RsaToolbox


#endif // CALGROUP_PANEL_H
