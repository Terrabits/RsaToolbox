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

    void clearMinimum();
    void clearMaximum();
    void setMinimum(double frequency_Hz);
    void setMinimum(double value, SiPrefix prefix);
    void setMaximum(double frequency_Hz);
    void setMaximum(double value, SiPrefix prefix);

    void clearMantissaValues();
    void setMantissaValues(QRowVector frequencies_Hz);

public slots:
    void clear();
    void selectAll();
    void setFrequency(double frequency_Hz);
    void setFrequency(double value, SiPrefix prefix);

signals:
    void invalidEdit(const QString &message);
    void frequencyChanged(double frequency_Hz);
    void frequencyEdited(double frequency_Hz);

private slots:
    void processEdit();
    void processChange();

private:
    Ui::FrequencyEdit *ui;

    double _frequency_Hz;
    static void parseFrequency(double frequency_Hz, double &value, SiPrefix &prefix);
    void parseDisplay(double &value, SiPrefix &prefix);
    void displayFrequency(double frequency_Hz);
    void displayFrequency(double value, SiPrefix prefix);

    void displayValue(double value);
    void displayValue(const QString &value);
    void displayPrefix(const QChar prefix);
    void displayPrefix(const SiPrefix prefix);
    double displayedFrequency() const;

    bool _isMinimum;
    bool _isMaximum;
    double _minimum_Hz;
    double _maximum_Hz;

    bool isMantissaValues() const;
    QRowVector _mantissaValues();

    double validateFrequency(double frequency_Hz);

}; // FrequencyEdit
}


#endif // FREQUENCYEDIT_H

