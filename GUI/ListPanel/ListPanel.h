#ifndef LISTPANEL_H
#define LISTPANEL_H

#include <QWidget>
#include <QItemSelectionModel>
//#include <QtDesigner/QDesignerExportWidget>


namespace RsaToolbox {

namespace Ui {
class ListPanel;
}
class /*QDESIGNER_WIDGET_EXPORT*/ ListPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ListPanel(QWidget *parent = 0);
    ~ListPanel();

    bool isModels() const;
    void clearModels();
    void setSelectionModel(QItemSelectionModel *selectionModel);
    QItemSelectionModel *selectionModel() const;
    void setModel(QAbstractItemModel *model);
    QAbstractItemModel *model() const;

public slots:
    void addNew();
    void deleteCurrent();
    void moveCurrentUp();
    void moveCurrentDown();

private:
    Ui::ListPanel *ui;
    QItemSelectionModel *_selection;
    QModelIndex currentIndex();
    int currentRow();
    int currentColumn();
    QModelIndex currentParent();
    int rowCount();

    QAbstractItemModel *_model;
};
} // RsaToolbox


#endif // LISTPANEL_H
