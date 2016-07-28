

// DecibelEdit
#include "DecibelEdit.h"

// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QRegExp>
#include <QRegExpValidator>
#include <QKeyEvent>
#include <QDebug>

// C++ std lib
#include <climits>


DecibelEdit::DecibelEdit(QWidget *parent) :
    QLineEdit(parent),
    _name("Value"),
    _value_dB(0),
    _isMinimum(true),
    _isMaximum(true),
    _minimum_dB(-200.0),
    _maximum_dB(200.0)
{
    QRegExp regex("-?(([0-9]+\\.?[0-9]*)|(\\.0*[1-9]+0*))(\\s?dB)?", Qt::CaseInsensitive);
    QRegExpValidator * validator = new QRegExpValidator(regex, this);
    setValidator(validator);

    connect(this, SIGNAL(returnPressed()),
            this, SLOT(handleReturnPressed()));
}
DecibelEdit::~DecibelEdit()
{

}

// Public:
void DecibelEdit::setParameterName(const QString &name) {
    _name = name;
}

double DecibelEdit::value_dB() const {
    return _value_dB;
}

void DecibelEdit::clearMinimum() {
    _isMinimum = false;
    _minimum_dB = -200.0;
}
void DecibelEdit::clearMaximum() {
    _isMaximum = false;
    _maximum_dB = 200.0;
}
void DecibelEdit::setMinimum(double value_dB) {
    value_dB = round(value_dB, 2);
    _isMinimum = true;
    _minimum_dB = value_dB;

    // Check for validity
    if (!text().isEmpty())
        setValue(_value_dB);
}
void DecibelEdit::setMaximum(double value_dB) {
    value_dB = round(value_dB, 2);
    _isMaximum = true;
    _maximum_dB = value_dB;

    // Check for validity
    if (!text().isEmpty())
        setValue(_value_dB);
}

void DecibelEdit::clearLimits() {
    clearMinimum();
    clearMaximum();
    //clearAcceptableValues();
}

// Slots:
void DecibelEdit::setValue(double value_dB) {
    value_dB = round(value_dB, 2);
    if (_isMinimum && value_dB < _minimum_dB)
        value_dB = _minimum_dB;
    if (_isMaximum && value_dB > _maximum_dB)
        value_dB = _maximum_dB;

    if (value_dB == _value_dB) {
        updateText();
        return;
    }

    _value_dB = value_dB;
    updateText();
    emit valueChanged(value_dB);
}
void DecibelEdit::setText(const QString &text) {
    QLineEdit::setText(text);
    processText();
}

// Protected
void DecibelEdit::focusInEvent(QFocusEvent *event) {
    selectAll();
    QLineEdit::focusInEvent(event);
}
void DecibelEdit::focusOutEvent(QFocusEvent *event) {
    processText();
    QLineEdit::focusOutEvent(event);
}

// Private slots
void DecibelEdit::handleReturnPressed() {
    processText();
    selectAll();
}

// Private
QString DecibelEdit::chopNonDigits(QString text) {
    int last = text.size() - 1;
    while (!text.isEmpty() && !text[last].isDigit()) {
        text.chop(1);
        last = text.size() - 1;
    }
    return text;
}
void DecibelEdit::updateText() {
    updateText(_value_dB);
}
void DecibelEdit::updateText(const double &value_dB) {
    QString text = formatDouble(value_dB, 2);
    text += " dB";

    bool isBlocked = blockSignals(true);
    QLineEdit::setText(text);
    blockSignals(isBlocked);
}
void DecibelEdit::processText() {
    QString text = this->text();
    if (text.isEmpty() && _value_dB == 0)
        return;

    text = chopNonDigits(text);
    double value_dB = text.toDouble();
    value_dB = round(value_dB, 2);

    // Acceptable value?
    if (_isMinimum && value_dB < _minimum_dB) {
        QString name = _name;
        if (name.isEmpty())
            name = "Points";
        QString msg = "*%1 must be at least %2 dB";
        msg = msg.arg(name);
        msg = msg.arg(QVariant(_minimum_dB).toString());
        emit outOfRange(msg);
        value_dB = _minimum_dB;
    }
    else if (_isMaximum && value_dB > _maximum_dB) {
        QString name = _name;
        if (name.isEmpty())
            name = "Points";
        QString msg = "*%1 must be at most %2 dB";
        msg = msg.arg(name);
        msg = msg.arg(QVariant(_maximum_dB).toString());
        emit outOfRange(msg);
        value_dB = _maximum_dB;
    }

    // If value is unchanged, clean up
    // display and return
    if (value_dB == _value_dB) {
        updateText();
        return;
    }

    // Change value
    _value_dB = value_dB;
    updateText();
    emit valueChanged(_value_dB);
    emit DecibelEdited(_value_dB);
}

