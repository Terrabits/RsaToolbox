#include "WizardPage.h"
using namespace RsaToolbox;


#include "Wizard.h"

#include <QDebug>


WizardPage::WizardPage(QWidget *parent) :
    QWidget(parent)
{
    _isFinal = false;
    _next = -1;
    _wizard = NULL;
}

WizardPage::~WizardPage()
{
}

QString WizardPage::name() const {
    return _name;
}
void WizardPage::setName(QString name) {
    _name = name;
}
bool WizardPage::isFinalPage() const {
    return _isFinal;
}
void WizardPage::setFinalPage(bool isFinalPage) {
    _isFinal = isFinalPage;
}

void WizardPage::initialize() {
}
bool WizardPage::skip() {
    return false;
}

bool WizardPage::isReadyForNext() {
    return nextIndex() != -1;
}
int WizardPage::next() {
    return nextIndex();
}
void WizardPage::setNextIndex(int index) {
    _next = index;
}
int WizardPage::nextIndex() const {
    return _next;
}

bool WizardPage::isReadyForBack() {
    return true;
}
void WizardPage::back() {
}
bool WizardPage::skipBackwards() const {
    return false;
}
void WizardPage::backToThis() {
}
void WizardPage::resetContents() {
}

void WizardPage::displayError(QString message) {
    Q_UNUSED(message);
}

Wizard *WizardPage::wizard() const {
    return _wizard;
}
void WizardPage::setWizard(Wizard *wizard) {
    _wizard = wizard;
}
WizardPage *WizardPage::pageAt(int index) {
    return wizard()->page(index);
}

WizardButtons *WizardPage::buttons() const {
    return wizard()->buttons();
}
void WizardPage::clearHistory() {
    wizard()->clearHistory();
}

BreadCrumbs *WizardPage::breadCrumbs() const {
    return wizard()->breadCrumbs();
}
