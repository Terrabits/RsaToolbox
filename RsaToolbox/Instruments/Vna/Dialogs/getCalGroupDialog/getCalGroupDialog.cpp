#include "getCalGroupDialog.h"
#include "ui_getCalGroupDialog.h"
using namespace RsaToolbox;

#include <QDebug>

getCalGroupDialog::getCalGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getCalGroupDialog)
{
    ui->setupUi(this);
    _model = NULL;
    _previous = QModelIndex();
}
getCalGroupDialog::~getCalGroupDialog()
{
    delete ui;
}

void getCalGroupDialog::setModel(CalGroupsModel *model, int column) {
    if (model == _model && ui->listView->modelColumn() == column)
        return;

    _model = model;
    ui->listView->setModel(model);
    ui->listView->setModelColumn(column);
}
CalGroupsModel *getCalGroupDialog::model() const {
    return _model;
}

QItemSelectionModel *getCalGroupDialog::selectionModel() const {
    return ui->listView->selectionModel();
}

QModelIndex getCalGroupDialog::selectedIndex() const {
    QModelIndexList list = selectionModel()->selectedIndexes();
    if (!list.isEmpty())
        return list.first();
    else
        return QModelIndex();
}

void getCalGroupDialog::accept() {
    if (!selectedIndex().isValid()) {
        ui->error->showMessage("*Please select cal group.", 5000);
        return;
    }

    emit selectionChanged(selectionModel()->selection(),
                          QItemSelection(_previous, _previous));
    _previous = selectedIndex();
    QDialog::accept();
}
void getCalGroupDialog::reject() {
    selectionModel()->clear();
    QDialog::reject();
}
void getCalGroupDialog::reset() {
    selectionModel()->clearSelection();
    _previous = QModelIndex();
}

