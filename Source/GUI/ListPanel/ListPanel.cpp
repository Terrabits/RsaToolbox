#include "ListPanel.h"
#include "ui_ListPanel.h"
using namespace RsaToolbox;

#include <QDebug>

ListPanel::ListPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListPanel)
{
    ui->setupUi(this);

    clearModels();
    QObject::connect(ui->addButton, SIGNAL(clicked()),
                     this, SLOT(addNew()));
    QObject::connect(ui->deleteButton, SIGNAL(clicked()),
                     this, SLOT(deleteCurrent()));
    QObject::connect(ui->moveUpButton, SIGNAL(clicked()),
                     this, SLOT(moveCurrentUp()));
    QObject::connect(ui->moveDownButton, SIGNAL(clicked()),
                     this, SLOT(moveCurrentDown()));
}

ListPanel::~ListPanel()
{
    delete ui;
}

bool ListPanel::isModels() const {
    return _selection != NULL && _model != NULL;
}
void ListPanel::clearModels() {
    _selection = NULL;
    _model = NULL;
}
void ListPanel::setSelectionModel(QItemSelectionModel *selectionModel) {
    _selection = selectionModel;
}
QItemSelectionModel *ListPanel::selectionModel() const {
    return _selection;
}
void ListPanel::setModel(QAbstractItemModel *model) {
    _model = model;
}

QAbstractItemModel *ListPanel::model() const {
    return _model;
}

void ListPanel::addNew() {
    if (!isModels())
        return;

    if (currentIndex().isValid()) {
        int row = currentRow();
        int column = currentColumn();
        _model->insertRow(row+1, currentParent());
        _selection->setCurrentIndex(_model->index(row+1, column), QItemSelectionModel::ClearAndSelect);
        _selection->select(_model->index(row+1, column), QItemSelectionModel::ClearAndSelect);
    }
    else {
        _model->insertRow(0);
        _selection->setCurrentIndex(_model->index(0,0), QItemSelectionModel::ClearAndSelect);
        _selection->select(_model->index(0, 0), QItemSelectionModel::ClearAndSelect);
    }
}
void ListPanel::deleteCurrent() {
    if (!isModels())
        return;
    if (!isCurrentIndex())
        return;

    // Current row/col
    int row = currentRow();
    int column = currentColumn();

    // Remove row, request count
    _model->removeRow(row, currentParent());
    int count = rowCount();

    // Select
    if (_model->rowCount() > 0) {
        if (row < count) {
            _selection->setCurrentIndex(_model->index(row, column), QItemSelectionModel::ClearAndSelect);
            _selection->select(_model->index(row, column), QItemSelectionModel::ClearAndSelect);
        }
        else {
            _selection->setCurrentIndex(_model->index(count-1, column), QItemSelectionModel::ClearAndSelect);
            _selection->select(_model->index(count-1, column), QItemSelectionModel::ClearAndSelect);
        }
    }
}
void ListPanel::moveCurrentUp() {
    if (!isModels())
        return;
    if (!isCurrentIndex())
        return;

    // Can't move up
    if (currentRow() <= 0)
        return;

    const int row = currentRow();
    _model->moveRow(currentParent(), row, currentParent(), row-1);
    _selection->setCurrentIndex(_model->index(row-1,0), QItemSelectionModel::ClearAndSelect);
    _selection->select(_model->index(row-1, 0), QItemSelectionModel::ClearAndSelect);
}
void ListPanel::moveCurrentDown() {
    if (!isModels())
        return;
    if (!isCurrentIndex())
        return;

    if (currentRow() >= _model->rowCount(currentParent()) - 1)
        return;

    const int row = currentRow();
    _model->moveRow(currentParent(), row, currentParent(), row+1);
    _selection->setCurrentIndex(_model->index(row+1,0), QItemSelectionModel::ClearAndSelect);
    _selection->select(_model->index(row+1, 0), QItemSelectionModel::ClearAndSelect);
}

bool ListPanel::isCurrentIndex() {
    return currentIndex().isValid();
}
QModelIndex ListPanel::currentIndex() {
    return _selection->currentIndex();
}
int ListPanel::currentRow() {
    return currentIndex().row();
}
int ListPanel::currentColumn() {
    return currentIndex().column();
}
QModelIndex ListPanel::currentParent() {
    return currentIndex().parent();
}
int ListPanel::rowCount() {
    return _model->rowCount();
}

