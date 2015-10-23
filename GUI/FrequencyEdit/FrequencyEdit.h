#ifndef FREQUENCYEDIT_H
#define FREQUENCYEDIT_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QWidget>


namespace RsaToolbox {

namespace Ui {
class FrequencyEdit;
}

class FrequencyEdit : public QWidget
{
    Q_OBJECT

public:
    FrequencyEdit(QWidget *parent = 0);
    ~FrequencyEdit();

    double frequency_Hz() const;

public slots:
    void clear();
    void selectAll();
    void setFrequency(double frequency_Hz);
    void setFrequency(double value, SiPrefix prefix);

signals:
    void frequencyChanged(double frequency_Hz);
    void frequencyEdited(double frequency_Hz);

private slots:
    void processEdit();
    void processChange();

private:
    Ui::FrequencyEdit *ui;

    double _frequency_Hz;
    void displayPrefix(const QChar prefix);
    void displayPrefix(const SiPrefix prefix);
    double displayedFrequency() const;


}; // FrequencyEdit
}


#endif // FREQUENCYEDIT_H

