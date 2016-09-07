#ifndef POWEREDIT_H
#define POWEREDIT_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QLineEdit>


namespace RsaToolbox {


class PowerEdit : public QLineEdit
{
    Q_OBJECT

public:
    PowerEdit(QWidget *parent = 0);
    ~PowerEdit();

    void setParameterName(const QString &name);

    double power_dBm() const;

    void clearMinimum();
    void clearMaximum();
    void setMinimum(double power_dBm);
    void setMaximum(double power_dBm);

    void clearAcceptedValues();
    void setAcceptedValues(const QRowVector &powers_dBm);

    void clearLimits();

public slots:
    void setText(const QString &text); // Override?
    void setPower(double power_dBm);

signals:
    void outOfRange(const QString &message);
    void powerChanged(double power_dBm);
    void PowerEdited(double power_dBm);

protected:
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);

private slots:
    void handleReturnPressed();

private:
    QString _name;
    double _power_dBm;

    static QString chopNonDigits(QString text);
    void updateText();
    void updateText(const double &power_dBm);
    void processText();

    bool _isMinimum;
    bool _isMaximum;
    double _minimum_dBm;
    double _maximum_dBm;

    // Add
    bool isAcceptedValues() const;
    QRowVector _acceptedValues_dBm;

}; // PowerEdit
} // RsaToolbox


#endif // POWEREDIT_H

