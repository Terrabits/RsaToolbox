#ifndef DOUBLEEDIT_H
#define DOUBLEEDIT_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QLineEdit>


namespace RsaToolbox {

class DoubleEdit : public QLineEdit
{
    Q_OBJECT

public:
    DoubleEdit(QWidget *parent = 0);
    ~DoubleEdit();

    void setParameterName(const QString &name);

    void setDecimalPlaces(int places);
    void setUnits(Units units);
    void setUnitAbbrev(const QString &abbreviation);

    void interpretMKeyAsMilli(bool isMilli = true);
    void disableSiPrefixes(bool disable = true);

    double value() const;

    void clearMinimum();
    void clearMaximum();
    void setMinimum(double value);
    void setMinimum(double value, SiPrefix prefix);
    void setMaximum(double value);
    void setMaximum(double value, SiPrefix prefix);

    void clearAcceptedValues();
    void setAcceptedValues(const QRowVector &values);

    void clearLimits();

public slots:
    void setText(const QString &text); // Override?
    void setValue(double value);
    void setValue(double value, SiPrefix prefix);

signals:
    void outOfRange(const QString &message);
    void valueChanged(double value);
    void valueEdited(double value);

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);

private slots:
    void handleReturnPressed();

private:
    QString _parameterName;

    int     _decimalPlaces;
    bool    _displayWithSiPrefix;
    bool    _useMKeyAsMilli;
    QString _unitAbbr;
    void    _setValidator();

    bool isNaN() const;
    double  _value;

    static bool containsF(const QString &text);
    static bool containsP(const QString &text);
    static bool containsN(const QString &text);
    static bool containsU(const QString &text);
    static bool containsT(const QString &text);
    static bool containsG(const QString &text);
    static bool containsM(const QString &text);
    static bool containsK(const QString &text);
    static QString chopNonDigits(QString text);
    void updateText();
    void updateText(const double &value);
    void processText();

    bool   _isMinimum;
    bool   _isMaximum;
    double _minimumValue;
    double _maximumValue;

    bool isAcceptedValues() const;
    QRowVector _acceptedValues;

}; // DoubleEdit
} // RsaToolbox


#endif // FREQUENCYEDIT_H
