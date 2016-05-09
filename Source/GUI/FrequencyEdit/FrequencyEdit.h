#ifndef FREQUENCYEDIT_H
#define FREQUENCYEDIT_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QLineEdit>


namespace RsaToolbox {


class FrequencyEdit : public QLineEdit
{
    Q_OBJECT

public:
    FrequencyEdit(QWidget *parent = 0);
    ~FrequencyEdit();

    void setParameterName(const QString &name);

    double frequency_Hz() const;

    void clearMinimum();
    void clearMaximum();
    void setMinimum(double frequency_Hz);
    void setMinimum(double value, SiPrefix prefix);
    void setMaximum(double frequency_Hz);
    void setMaximum(double value, SiPrefix prefix);

    void clearAcceptedValues();
    void setAcceptedValues(const QRowVector &frequencies_Hz);

    void clearLimits();

public slots:
    void setText(const QString &text); // Override?
    void setFrequency(double frequency_Hz);
    void setFrequency(double value, SiPrefix prefix);

signals:
    void outOfRange(const QString &message);
    void frequencyChanged(double frequency_Hz);
    void frequencyEdited(double frequency_Hz);

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);

private slots:
    void handleReturnPressed();

private:
    QString _name;
    double _frequency_Hz;

    static bool containsT(const QString &text);
    static bool containsG(const QString &text);
    static bool containsM(const QString &text);
    static bool containsK(const QString &text);
    static QString chopNonDigits(QString text);
    void updateText();
    void updateText(const double &frequency_Hz);
    void processText();

    bool _isMinimum;
    bool _isMaximum;
    double _minimum_Hz;
    double _maximum_Hz;

    bool isAcceptedValues() const;
    QRowVector _acceptedValues_Hz;

}; // FrequencyEdit
} // RsaToolbox


#endif // FREQUENCYEDIT_H

