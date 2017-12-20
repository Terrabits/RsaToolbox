#ifndef WIZARD_H
#define WIZARD_H


#include "BreadCrumbs.h"
#include "ErrorLabel.h"
#include "TimedProgressBar.h"
#include "WizardButtons.h"
#include "WizardPage.h"

#include <QWidget>
#include <QLabel>
#include <QWizard>


namespace RsaToolbox {

class BreadCrumbs;
class WizardButtons;
class WizardPage;
typedef QList<WizardPage*> WizardPages;

namespace Ui {
class Wizard;
}
class Wizard : public QWidget
{
    Q_OBJECT
    friend class WizardPage;

public:

    explicit Wizard(QWidget *parent = 0);
    ~Wizard();

    int currentIndex() const;
    const WizardPage *currentPage() const;
    QString currentName() const;

    void addPage(WizardPage *page);
    void insertPage(int index, WizardPage *page);
    void removePage(int index);

    void setRestartOnCancel(bool restart);
    void setStartPage(int index = 0);
    int startPageIndex() const;
    int numberOfPages() const;

    void showBreadcrumbs();
    void hideBreadcrumbs();

    QList<int> history() const;

signals:
    void currentPageChanged(int index);
    void historyChanged(QStringList past, QString current);
    void pageAdded(int index);
    void pageRemoved(int index);

public slots:
    virtual void back(int count = 1);
    virtual void next();
    virtual void restart();

    void setEnabled();
    void setEnabled(bool isEnabled);
    void setDisabled();
    void setDisabled(bool isDisabled);

    void enableLoadingImage();
    void disableLoadingImage();

    void shake();

protected:
    void keyPressEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);

    WizardPage *_start;
    WizardPage *_current;
    WizardPages _pages;
    WizardPages _history;

    WizardPage *page(int index) const;
    int index(WizardPage *page) const;

    virtual void connectPage();
    virtual void disconnectPage();
    int leaveForward();
    int leaveBackward();
    void enterForward(int index);
    void enterBackward(int index);

    BreadCrumbs      *breadCrumbs() const;
    ErrorLabel       *errorLabel () const;
    WizardButtons    *buttons()     const;
    TimedProgressBar *progressBar() const;

    QStringList nameHistory() const;
    void clearHistory();
    void pushToHistory(WizardPage *page);
    WizardPage *popFromHistory();
    void updateHistory();

private:
    Ui::Wizard *ui;
    QLabel *_loadingImage;
    bool _isRestart;

    void backWithoutAsking();
    int leaveBackwardWithoutAsking();
}; // Wizard
} // RsaToolbox


#endif // WIZARD_H
