#include "CalDialog.h"
#include "ui_CalDialog.h"

#include <QDebug>

CalDialog::CalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalDialog)
{
    ui->setupUi(this);
    _model = NULL;
    _previous = QModelIndex();
}
CalDialog::~CalDialog()
{
    delete ui;
}

void CalDialog::setModel(CalGroupsModel *model, int column) {
    if (model == _model && ui->listView->modelColumn() == column)
        return;

    _model = model;
    ui->listView->setModel(model);
    ui->listView->setModelColumn(column);
}
CalGroupsModel *CalDialog::model() const {
    return _model;
}

QItemSelectionModel *CalDialog::selectionModel() const {
    return ui->listView->selectionModel();
}

QModelIndex CalDialog::selectedIndex() const {
    QModelIndexList list = selectionModel()->selectedIndexes();
    if (!list.isEmpty())
        return list.first();
    else
        return QModelIndex();
}

void CalDialog::accept() {
    if (!selectedIndex().isValid()) {
        ui->error->showMessage("*Please select cal group.", 5000);
        return;
    }

    emit selectionChanged(selectionModel()->selection(),
                          QItemSelection(_previous, _previous));
    _previous = selectedIndex();
    QDialog::accept();
}
void CalDialog::reject() {
    selectionModel()->clear();
    QDialog::reject();
}
void CalDialog::reset() {
    selectionModel()->clearSelection();
    _previous = QModelIndex();
}

