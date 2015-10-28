#ifndef IFBWEDIT_H
#define IFBWEDIT_H


// RsaToolbox
#include "Definitions.h"


// RsaToolbox
#include <Vna.h>

// Qt
#include <QWidget>


namespace RsaToolbox {

namespace Ui {
class IfBwEdit;
}

class IfBwEdit : public QWidget
{
    Q_OBJECT

public:
    IfBwEdit(QWidget *parent = 0);
    ~IfBwEdit();

    double frequency_Hz() const;

    void setMHzValues(const QRowVector &values);
    void setKHzValues(const QRowVector &values);
    void setHzValues(const QRowVector &values);

public slots:
    bool setFrequency(double frequency_Hz);
    bool setFrequency(double value, SiPrefix prefix);

signals:
    void frequencyChanged(double frequency_Hz);

private slots:
    void processEdit();
    void processChange();

private:
    Ui::IfBwEdit *ui;
    QRowVector _mhzValues;
    QRowVector _khzValues;
    QRowVector _hzValues;

    double _frequency_Hz;
    void displayPrefix(const QChar prefix);
    void displayPrefix(const SiPrefix prefix);
    double displayedFrequency() const;


}; // IfBwEdit
}


#endif // IFBWEDIT_H

