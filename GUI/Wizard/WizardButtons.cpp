#include "WizardButtons.h"
#include "ui_WizardButtons.h"
using namespace RsaToolbox;


WizardButtons::WizardButtons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WizardButtons)
{
    ui->setupUi(this);
}

WizardButtons::~WizardButtons()
{
    delete ui;
}

QPushButton *WizardButtons::previous() const {
    return ui->previous;
}
QPushButton *WizardButtons::customA() const {
    return ui->customA;
}
QPushButton *WizardButtons::customB() const {
    return ui->customB;
}
QPushButton *WizardButtons::customC() const {
    return ui->customC;
}
QPushButton *WizardButtons::cancel() const {
    return ui->cancel;
}
QPushButton *WizardButtons::next() const {
    return ui->next;
}
