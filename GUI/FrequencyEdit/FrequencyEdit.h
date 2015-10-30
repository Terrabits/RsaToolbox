#ifndef FREQUENCYEDIT_H
#define FREQUENCYEDIT_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QWidget>
#include <QApplication>


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

    void setParameterName(const QString &name);

    bool hasAcceptableInput() const;
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
    void outOfRange(const QString &message);
    void frequencyChanged(double frequency_Hz);
    void frequencyEdited(double frequency_Hz);

private slots:
    void childLostFocus();
    void valueEdited(QString value);

private:
    Ui::FrequencyEdit *ui;

    QString _name;
    double _frequency_Hz;

    static void parseFrequency(double frequency_Hz, double &value, SiPrefix &prefix);
    void parseDisplay(double &value, SiPrefix &prefix);
    double displayedFrequency() const;

    void displayFrequency(const double &frequency_Hz);
    void displayFrequency(const double &value, const SiPrefix &prefix);
    void displayValue(const double &value);
    void displayValue(const QString &value);
    void displayPrefix(const QChar &prefix);
    void displayPrefix(const SiPrefix &prefix);

    bool _isMinimum;
    bool _isMaximum;
    double _minimum_Hz;
    double _maximum_Hz;

    bool isMantissaValues() const;
    QRowVector _mantissaValues_Hz;
}; // FrequencyEdit

} // RsaToolbox


#endif // FREQUENCYEDIT_H

