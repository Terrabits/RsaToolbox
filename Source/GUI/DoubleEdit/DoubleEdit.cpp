#include "DoubleEdit.h"


// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QDebug>
#include <QKeyEvent>
#include <QRegExp>
#include <QRegExpValidator>
#include <QScopedPointer>


DoubleEdit::DoubleEdit(QWidget *parent) :
    QLineEdit(parent),
    _parameterName("Value"),
    _decimalPlaces(3),
    _displayWithSiPrefix(true),
    _useMKeyAsMilli(false),
    _unitAbbr("U"),
    _value(DBL_NAN),
    _isMinimum(false),
    _isMaximum(false),
    _minimumValue(0),
    _maximumValue(1.0)
{
    _setValidator();
    connect(this, SIGNAL(returnPressed()),
            this, SLOT(handleReturnPressed()));
}

DoubleEdit::~DoubleEdit()
{

}

// Public:
void DoubleEdit::setParameterName(const QString &name) {
    _parameterName = name;
}

double DoubleEdit::value() const {
    return _value;
}

void DoubleEdit::clearMinimum() {
    _isMinimum = false;
    _minimumValue = 1;
}
void DoubleEdit::clearMaximum() {
    _isMaximum = false;
    _maximumValue = 1.0E12;
}
void DoubleEdit::setMinimum(double value) {
    clearAcceptedValues();

    if (value < 1)
        value = 1;
    _isMinimum = true;
    _minimumValue = value;

    // Check for validity
    if (!text().isEmpty())
        setValue(_value);
}
void DoubleEdit::setMinimum(double value, SiPrefix prefix) {
    setMinimum(value * toDouble(prefix));
}
void DoubleEdit::setMaximum(double value) {
    clearAcceptedValues();

    if (value < 1)
        value = 1;
    _isMaximum = true;
    _maximumValue = value;

    // Check for validity
    if (!text().isEmpty())
        setValue(_value);
}
void DoubleEdit::setMaximum(double value, SiPrefix prefix) {
    setMaximum(value * toDouble(prefix));
}

void DoubleEdit::clearAcceptedValues() {
    _acceptedValues.clear();
}
void DoubleEdit::setAcceptedValues(const QRowVector &frequencies_Hz) {
    clearMinimum();
    clearMaximum();

    _acceptedValues = frequencies_Hz;
    for (int i = 0; i < _acceptedValues.size(); i++) {
        if (_acceptedValues[i] < 0)
            _acceptedValues.removeAt(i);
    }
    if (!text().isEmpty())
        setValue(_value);
}

void DoubleEdit::clearLimits() {
    clearMinimum();
    clearMaximum();
    clearAcceptedValues();
}

// Slots:
void DoubleEdit::setValue(double value) {
    if (value < 1)
        value = 1;
    if (_isMinimum && value < _minimumValue)
        value = _minimumValue;
    if (_isMaximum && value > _maximumValue)
        value = _maximumValue;
    if (isAcceptedValues())
        value = findClosest(value, _acceptedValues);

    if (value == _value) {
        updateText();
        return;
    }

    _value = value;
    updateText();
    emit valueChanged(_value);
}
void DoubleEdit::setValue(double value, SiPrefix prefix) {
    const double _value = value * toDouble(prefix);
    setValue(_value);
}
void DoubleEdit::setText(const QString &text) {
    QLineEdit::setText(text);
    processText();
}

// Protected
void DoubleEdit::keyPressEvent(QKeyEvent *event) {
    Qt::Key key = Qt::Key(event->key());
    if (key != Qt::Key_T &&
        key != Qt::Key_G &&
        key != Qt::Key_M &&
        key != Qt::Key_K &&
        key != Qt::Key_U &&
        key != Qt::Key_N &&
        key != Qt::Key_P &&
        key != Qt::Key_F)
    {
        QLineEdit::keyPressEvent(event);
        return;
    }

    event->accept();

    SiPrefix prefix;
    switch (key) {
    case Qt::Key_T:
        prefix = SiPrefix::Tera;
        break;
    case Qt::Key_G:
        prefix = SiPrefix::Giga;
        break;
    case Qt::Key_M:
        if (_useMKeyAsMilli) {
            prefix = SiPrefix::Milli;
        }
        else {
            prefix = SiPrefix::Mega;
        }
        break;
    case Qt::Key_K:
        prefix = SiPrefix::Kilo;
        break;
    case Qt::Key_U:
        prefix = SiPrefix::Micro;
        break;
    case Qt::Key_N:
        prefix = SiPrefix::Nano;
        break;
    case Qt::Key_P:
        prefix = SiPrefix::Pico;
        break;
    case Qt::Key_F:
        prefix = SiPrefix::Femto;
        break;
    default:
        prefix = SiPrefix::None;
        break;
    }
    QString text = this->text();
    text = chopNonDigits(text);
    updateText(text.toDouble() * toDouble(prefix));
    processText();
    selectAll();
}
void DoubleEdit::focusInEvent(QFocusEvent *event) {
    selectAll();
    QLineEdit::focusInEvent(event);
}
void DoubleEdit::focusOutEvent(QFocusEvent *event) {
    processText();
    QLineEdit::focusOutEvent(event);
}

// Private slots
void DoubleEdit::handleReturnPressed() {
    processText();
    selectAll();
}

// Private
void DoubleEdit::_setValidator() {
    QString regexStr;

    // No prefix
    if (_displayWithSiPrefix) {
        regexStr = "-?(([0-9]+\\.?[0-9]*)|(\\.0*[1-9]+0*))(\\s*%1)?";
    }
    else {
        // Prefix
        regexStr = "-?(([0-9]+\\.?[0-9]*)|(\\.0*[1-9]+0*))(\\s*[TGMKmupf]?%1)?";
    }
    regexStr = regexStr.arg(_unitAbbr);

    QRegExp regex(regexStr, Qt::CaseInsensitive);
    QScopedPointer<QRegExpValidator> validator(new QRegExpValidator(regex, this));
    setValidator(validator.take());
}

bool DoubleEdit::isNaN() const {
    return _value != _value;
}
bool DoubleEdit::containsF(const QString &text) {
    return text.contains("F", Qt::CaseInsensitive);
}
bool DoubleEdit::containsP(const QString &text) {
    return text.contains("P", Qt::CaseInsensitive);
}
bool DoubleEdit::containsN(const QString &text) {
    return text.contains("N", Qt::CaseInsensitive);
}

bool DoubleEdit::containsU(const QString &text) {
    return text.contains("U", Qt::CaseInsensitive);
}
bool DoubleEdit::containsT(const QString &text) {
    return text.contains("T", Qt::CaseInsensitive);
}
bool DoubleEdit::containsG(const QString &text) {
    return text.contains("G", Qt::CaseInsensitive);
}
bool DoubleEdit::containsM(const QString &text) {
    // ...milli?
    return text.contains("M", Qt::CaseInsensitive);
}
bool DoubleEdit::containsK(const QString &text) {
    return text.contains("K", Qt::CaseInsensitive);
}
QString DoubleEdit::chopNonDigits(QString text) {
    int last = text.size() - 1;
    while (!text.isEmpty() && !text[last].isDigit()) {
        text.chop(1);
        last = text.size() - 1;
    }
    return text;
}
void DoubleEdit::updateText() {
    updateText(_value);
}
void DoubleEdit::updateText(const double &value) {
    QString text;
    if (_displayWithSiPrefix) {
        text = formatValue(value, _decimalPlaces, _unitAbbr);
    }
    else {
        text = "%1 %2";
        text = text.arg(formatDouble(value, _decimalPlaces));
        text = text.arg(_unitAbbr);
        text = text.trimmed();
    }

    bool isBlocked = blockSignals(true);
    QLineEdit::setText(text);
    blockSignals(isBlocked);
}
void DoubleEdit::processText() {
    QString text = this->text();
    if (text.isEmpty() && isNaN()) {
        return;
    }

    if (text.endsWith(_unitAbbr, Qt::CaseInsensitive)) {
        text.chop(_unitAbbr.size());
    }

    SiPrefix prefix = SiPrefix::None;
    if (containsT(text)) {
        prefix = SiPrefix::Tera;
    }
    else if (containsG(text)) {
        prefix = SiPrefix::Giga;
    }
    else if (containsM(text)) {
        if (text.endsWith("m")) {
            prefix = SiPrefix::Milli;
        }
        else {
            prefix = SiPrefix::Mega;
        }
    }
    else if (containsK(text)) {
        prefix = SiPrefix::Kilo;
    }
    else if (containsU(text)) {
        prefix = SiPrefix::Micro;
    }
    else if (containsN(text)) {
        prefix = SiPrefix::Nano;
    }
    else if (containsP(text)) {
        prefix = SiPrefix::Pico;
    }
    else if (containsF(text)) {
        prefix = SiPrefix::Femto;
    }

    // Apply prefix
    text = chopNonDigits(text);
    double value = text.toDouble() * toDouble(prefix);

    // Round to acceptable value
    if (_isMinimum && value < _minimumValue) {
        QString name = _parameterName;
        if (name.isEmpty())
            name = "Value";
        QString msg = "*%1 must be at least %2";
        msg = msg.arg(name);
        msg = msg.arg(formatValue(_minimumValue, 3, Units::Hertz));
        emit outOfRange(msg);
        value = _minimumValue;
    }
    else if (_isMaximum && value > _maximumValue) {
        QString name = _parameterName;
        if (name.isEmpty())
            name = "Value";
        QString msg = "*%1 must be at most %2";
        msg = msg.arg(name);
        msg = msg.arg(formatValue(_maximumValue, 3, Units::Hertz));
        emit outOfRange(msg);
        value = _maximumValue;
    }
    else if (isAcceptedValues() && !_acceptedValues.contains(value)) {
        double newValue = findClosest(value, _acceptedValues);
        if (newValue != value) {
            QString msg = "*%1 Rounded to closest value: %2";
            msg = msg.arg(formatValue(value, 3, Units::Hertz));
            msg = msg.arg(formatValue(newValue, 3, Units::Hertz));
            emit outOfRange(msg);

            value = newValue;
        }
    }

    // If value is unchanged, clean up
    // display and return
    if (value == _value) {
        updateText();
        return;
    }

    // Change value
    _value = value;
    updateText();
    emit valueChanged(_value);
    emit valueEdited(_value);
}

bool DoubleEdit::isAcceptedValues() const {
    return !_acceptedValues.isEmpty();
}

