#ifndef WIZARDBUTTONS_H
#define WIZARDBUTTONS_H

#include <QWidget>
#include <QPushButton>


namespace RsaToolbox {

namespace Ui {
class WizardButtons;
}
class WizardButtons : public QWidget
{
    Q_OBJECT

public:
    explicit WizardButtons(QWidget *parent = 0);
    ~WizardButtons();

    QPushButton *previous() const;
    QPushButton *customA() const;
    QPushButton *customB() const;
    QPushButton *customC() const;
    QPushButton *cancel() const;
    QPushButton *next() const;

private:
    Ui::WizardButtons *ui;
};
} // RsaToolbox


#endif // WIZARDBUTTONS_H
