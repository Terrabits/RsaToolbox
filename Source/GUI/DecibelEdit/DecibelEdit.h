#ifndef DECIBELEDIT_H
#define DECIBELEDIT_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QLineEdit>


namespace RsaToolbox {


class DecibelEdit : public QLineEdit
{
    Q_OBJECT

public:
    DecibelEdit(QWidget *parent = 0);
    ~DecibelEdit();

    void setParameterName(const QString &name);

    double value_dB() const;

    void clearMinimum();
    void clearMaximum();
    void setMinimum(double value_dB);
    void setMaximum(double value_dB);

    void clearLimits();

public slots:
    void setText(const QString &text); // Override?
    void setValue(double value_dB);

signals:
    void outOfRange(const QString &message);
    void valueChanged(double value_dB);
    void DecibelEdited(double value_dB);

protected:
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);

private slots:
    void handleReturnPressed();

private:
    QString _name;
    double _value_dB;

    static QString chopNonDigits(QString text);
    void updateText();
    void updateText(const double &value_dB);
    void processText();

    bool _isMinimum;
    bool _isMaximum;
    double _minimum_dB;
    double _maximum_dB;

}; // DecibelEdit
} // RsaToolbox


#endif // DECIBELEDIT_H

