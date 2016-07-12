#include "Wizard.h"
#include "ui_Wizard.h"
using namespace RsaToolbox;


#include <QPropertyAnimation>
#include <QKeyEvent>
#include <QStringList>
#include <QMovie>
#include <QDebug>


Wizard::Wizard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wizard),
    _isRestart(true)
{
    ui->setupUi(this);
    _start = NULL;
    _current = NULL;
    _loadingImage = NULL;
    QObject::connect(ui->breadCrumbs, SIGNAL(back(int)),
                     this, SLOT(back(int)));
    QObject::connect(this, SIGNAL(historyChanged(QStringList,QString)),
                     ui->breadCrumbs, SLOT(setLinks(QStringList,QString)));
    QObject::connect(buttons()->previous(), SIGNAL(clicked()),
                     this, SLOT(back()));
    QObject::connect(buttons()->cancel(), SIGNAL(clicked()),
                     this, SLOT(restart()));
    QObject::connect(buttons()->next(), SIGNAL(clicked()),
                     this, SLOT(next()));
    buttons()->customA()->hide();
    buttons()->customB()->hide();
    buttons()->customC()->hide();
}

Wizard::~Wizard()
{
    qDebug() << "~Wizard, pages: " << numberOfPages();
    while (numberOfPages() > 0)
        removePage(numberOfPages()-1);
    delete ui;
}

int Wizard::currentIndex() const {
    return index(_current);
}
QString Wizard::currentName() const {
    if (_current == NULL)
        return "";

    return _current->name();
}
const WizardPage *Wizard::currentPage() const {
    return _current;
}
WizardPage *Wizard::page(int index) const {
    return _pages[index];
}
int Wizard::index(WizardPage *page) const {
    return _pages.indexOf(page);
}

void Wizard::addPage(WizardPage *page) {
    qDebug() << "Wizard::addPage " << page;
    ui->stack->addWidget(page);
    _pages.append(page);
    page->setWizard(this);
    if (!_current) {
        setStartPage();
    }
    emit pageAdded(numberOfPages()-1);
}
void Wizard::insertPage(int index, WizardPage *page) {
    qDebug() << "Wizard::insertPage " << index << page;
    ui->stack->insertWidget(index, page);
    _pages.insert(index, page);
    page->setWizard(this);
    if (_start == NULL)
        _start = _pages.first();
    emit pageAdded(index);
}
void Wizard::removePage(int index) {
    qDebug() << "Wizard::removePage " << index;
    WizardPage *page = this->page(index);
    if (page == _start) {
        if (!page->isFinalPage()
                && page->nextIndex() >= 0
                && page->nextIndex() < _pages.size())
        {
            const int next = page->nextIndex();
            _start = this->page(next);
        }
        else {
            _start = NULL;
        }
    }

    if (page == _current) {
        back();
    }
    else if (_history.contains(page)) {
        _history.removeAll(page);
        page->back();
    }

    page->setWizard(NULL);
    _pages.removeAt(index);
    ui->stack->removeWidget(page);
    page->deleteLater();
    emit pageRemoved(index);
}

void Wizard::setRestartOnCancel(bool restart) {

}
void Wizard::setStartPage(int index) {
    qDebug() << "Wizard::setStartPage " << index;
    restart();

    buttons()->next()->setText("Next");
    buttons()->next()->setVisible(true);
    buttons()->next()->setEnabled(true);
    buttons()->previous()->setText("Previous");
    buttons()->previous()->setVisible(false);
    buttons()->previous()->setEnabled(false);

    _start = page(index);
    _current = page(index);
    connectPage();
    _current->initialize();
    ui->stack->setCurrentWidget(_current);
    emit currentPageChanged(currentIndex());
    updateHistory();
}
int Wizard::numberOfPages() const {
    return _pages.size();
}

void Wizard::showBreadcrumbs() {
    ui->breadCrumbs->show();
}

void Wizard::hideBreadcrumbs() {
    ui->breadCrumbs->hide();
}

//bool Wizard::validateCurrentPage() {
//    if (current == NULL)
//        return true;

//    return _current->validate();
//}
QList<int> Wizard::history() const {
    QList<int> indexes;
    for (int i = 0; i < _history.size(); i++)
        indexes << _pages.indexOf(_history[i]);
    return indexes;
}
void Wizard::clearHistory() {
    qDebug() << "Wizard::clearHistory";
    _history.clear();
    updateHistory();
}

void Wizard::back(int count) {
    qDebug() << "Wizard::back " << count;
    if (count <= 0)
        return;

    int index = leaveBackward();
    if (index == -1)
        return;
    enterBackward(index);

    count--;
    if (count > 0)
        back(count);
    else if (_current->skipBackwards())
        back(1);
}

void Wizard::next() {
    qDebug() << "Wizard::next";
    int index = leaveForward();
    if (index == -1)
        return;
    enterForward(index);

    if (_current->skip()) {
        qDebug() << "Skipping " + _current->name();
        next();
    }
    qDebug() << "Entering " << _current->name();
}
void Wizard::restart() {
    qDebug() << "Wizard::restart";
    if (!_isRestart) {
        close();
        return;
    }

    if (_pages.isEmpty())
        return;
    if (!_start)
        return;
    if (!_current)
        return;

    while (_current && _start
           && _current != _start)
    {
        backWithoutAsking();
    }
}

void Wizard::setEnabled() {
    setEnabled(true);
}
void Wizard::setEnabled(bool isEnabled) {
    qDebug() << "Wizard::setEnabled " << isEnabled;
    foreach (WizardPage *page, _pages)
        page->setEnabled(isEnabled);
    QWidget::setEnabled(isEnabled);
}
void Wizard::setDisabled() {
    setEnabled(false);
}
void Wizard::setDisabled(bool isDisabled) {
    setEnabled(!isDisabled);
}
void Wizard::enableLoadingImage() {
    qDebug() << "Wizard::enableLoadingImage";
    if (_loadingImage != NULL)
        _loadingImage->deleteLater();

    _loadingImage = new QLabel(this);
    _loadingImage->setMovie(new QMovie(":/TestRun/Animation/loading.gif"));
    _loadingImage->resize(32, 32);
    _loadingImage->move(width()/2 - _loadingImage->width()/2,
                        height()/2 - _loadingImage->height()/2);
    _loadingImage->raise();
    _loadingImage->movie()->start();
    _loadingImage->show();
}
void Wizard::disableLoadingImage() {
    qDebug() << "Wizard::disableLoadingImage";
    if (_loadingImage != NULL) {
        _loadingImage->deleteLater();
        _loadingImage = NULL;
    }
}

void Wizard::shake() {
    QRect _geometry = geometry();
    _geometry.moveRight(_geometry.right() + 10);

    QEasingCurve curve(QEasingCurve::OutElastic);
    curve.setAmplitude(2);
    curve.setPeriod(0.3);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setStartValue(_geometry);
    animation->setEndValue(geometry());
    animation->setDuration(500);
    animation->setEasingCurve(curve);
    animation->start();
}

void Wizard::keyPressEvent(QKeyEvent *event) {
    if (event->key() != Qt::Key_Escape) {
        QWidget::keyPressEvent(event);
        return;
    }

    if (_current == NULL || _current->isReadyForBack()) {
        event->accept(); // Not necessary?
        if (_history.isEmpty() && _current == _start)
            close();
        else
            restart();
    }
}
void Wizard::resizeEvent(QResizeEvent *event) {
    if (_loadingImage != NULL)
        _loadingImage->move(width()/2 - _loadingImage->width()/2,
                            height()/2 - _loadingImage->height()/2);
    QWidget::resizeEvent(event);
}
void Wizard::closeEvent(QCloseEvent *event) {
    if (!_current || _current->isReadyForBack()) {
        restart();
        QWidget::closeEvent(event);
    }
    else {
        event->ignore();
    }
}


void Wizard::connectPage() {
    if (_current == NULL)
        return;

    QObject::connect(_current, SIGNAL(enableNext(bool)),
                     buttons()->next(), SLOT(setEnabled(bool)));
    QObject::connect(_current, SIGNAL(enableBack(bool)),
                     buttons()->previous(), SLOT(setEnabled(bool)));
}
void Wizard::disconnectPage() {
    if (_current == NULL)
        return;

    QObject::disconnect(_current, SIGNAL(enableNext(bool)),
                     buttons()->next(), SLOT(setEnabled(bool)));
    QObject::disconnect(_current, SIGNAL(enableBack(bool)),
                     buttons()->previous(), SLOT(setEnabled(bool)));
}
int Wizard::leaveForward() {
    if (_current == NULL)
        return -1;
    if (!_current->isReadyForNext())
        return -1;

    int next = _current->next();
    if (_current->isFinalPage()) {
        close();
        return -1;
    }
    disconnectPage();
    pushToHistory(_current);
    _current = NULL;
    return next;
}
int Wizard::leaveBackward() {
    if (_current == NULL)
        return -1;
    if (!_current->isReadyForBack())
        return -1;

    disconnectPage();
    _current->back();
    _current = NULL;
    return index(popFromHistory());
}

void Wizard::enterForward(int index) {
    buttons()->next()->setText("Next");
    buttons()->next()->setVisible(true);
    buttons()->next()->setEnabled(true);
    buttons()->previous()->setText("Previous");
    buttons()->previous()->setVisible(true);
    buttons()->previous()->setEnabled(true);

    _current = page(index);
    connectPage();
    _current->initialize();
    ui->stack->setCurrentWidget(_current);
    emit currentPageChanged(currentIndex());
    updateHistory();
}
void Wizard::enterBackward(int index) {
    buttons()->next()->setText("Next");
    buttons()->next()->setVisible(true);
    buttons()->next()->setEnabled(true);
    buttons()->previous()->setText("Previous");
    buttons()->previous()->setVisible(true);
    buttons()->previous()->setEnabled(true);

    _current = page(index);
    connectPage();
    _current->backToThis();
    ui->stack->setCurrentWidget(_current);
    emit currentPageChanged(currentIndex());
    updateHistory();
}

WizardButtons *Wizard::buttons() const {
    return ui->buttons;
}
BreadCrumbs *Wizard::breadCrumbs() const {
    return ui->breadCrumbs;
}

void Wizard::updateHistory() {
    if (_history.isEmpty())
        buttons()->previous()->hide();
    else
        buttons()->previous()->show();
    emit historyChanged(nameHistory(), currentName());
}

QStringList Wizard::nameHistory() const {
    QStringList result;
    for (int i = 0; i < _history.size(); i++)
        result << _history[i]->name();

    return result;
}
void Wizard::pushToHistory(WizardPage *page) {
    _history.prepend(page);
}
WizardPage *Wizard::popFromHistory() {
    if (_history.isEmpty())
        return NULL;

    return _history.takeFirst();
}


// Private

void Wizard::backWithoutAsking() {
    qDebug() << "Wizard::backWithoutAsking";
    int index = leaveBackwardWithoutAsking();
    if (index == -1)
        return;
    enterBackward(index);
}
int Wizard::leaveBackwardWithoutAsking() {
    if (_current == NULL)
        return -1;

    disconnectPage();
    _current->back();
    _current = NULL;
    return index(popFromHistory());
}
