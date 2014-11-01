#include "CalGroupPanel.h"
#include "ui_CalGroupPanel.h"
using namespace RsaToolbox;


#include <QDebug>


CalGroupPanel::CalGroupPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalGroupPanel)
{
    ui->setupUi(this);

    _model = NULL;
    QObject::connect(ui->calButton, SIGNAL(clicked()),
                     &_dialog, SLOT(exec()));
    QObject::connect(&_dialog, SIGNAL(accepted()),
                     this, SLOT(dialogAccepted()));
    QObject::connect(ui->applyCal, SIGNAL(toggled(bool)),
                     ui->calButton, SLOT(setEnabled(bool)));
    QObject::connect(ui->applyCal, SIGNAL(toggled(bool)),
                     ui->calEdit, SLOT(setEnabled(bool)));

    ui->noCal->setChecked(true);
    ui->calButton->setDisabled(true);
    ui->calEdit->setDisabled(true);
}

CalGroupPanel::~CalGroupPanel()
{
    delete ui;
}

void CalGroupPanel::setModel(CalGroupsModel *model) {
    _model = model;
    _dialog.setModel(model, 0);
    _selection.reset(new QItemSelectionModel(model));
    QObject::connect(_selection.data(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
                     this, SIGNAL(selectionChanged(QItemSelection,QItemSelection)));
    QObject::connect(_selection.data(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
                     this, SLOT(changeSelection(QItemSelection,QItemSelection)));
    QObject::connect(ui->noCal, SIGNAL(clicked()),
                     _selection.data(), SLOT(clearSelection()));
    QObject::connect(ui->applyCal, SIGNAL(clicked()),
                     this, SLOT(dialogAccepted()));
}
CalGroupsModel *CalGroupPanel::model() const {
    return _model;
}
QItemSelectionModel *CalGroupPanel::selectionModel() const {
    return _selection.data();
}

void CalGroupPanel::reset() {
    ui->calEdit->clear();
    _dialog.reset();
}

void CalGroupPanel::dialogAccepted() {
    if (_selection.isNull())
        return;

    _selection->clearSelection();
    _selection->select(_dialog.selectedIndex(), QItemSelectionModel::Select);
    ui->calEdit->setText(_dialog.selectedIndex().data(Qt::DisplayRole).toString());
}
void CalGroupPanel::changeSelection(const QItemSelection &selected, const QItemSelection &deselected) {
    Q_UNUSED(deselected);
    if (selected.isEmpty()) {
        ui->noCal->setChecked(true);
    }
    else {
        ui->applyCal->setChecked(true);
        ui->calEdit->setText(selected.indexes().first().data(Qt::DisplayRole).toString());
    }
}
