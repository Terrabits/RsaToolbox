

// PowerEdit
#include "PowerEdit.h"

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


PowerEdit::PowerEdit(QWidget *parent) :
    QLineEdit(parent),
    _name("Value"),
    _power_dBm(0),
    _isMinimum(true),
    _minimum_dBm(-150.0),
    _isMaximum(true),
    _maximum_dBm(150.0)
{
    QRegExp regex("-?(([0-9]+\\.?[0-9]*)|(\\.0*[1-9]+0*))(\\s?dBm)?", Qt::CaseInsensitive);
    QRegExpValidator * validator = new QRegExpValidator(regex, this);
    setValidator(validator);

    connect(this, SIGNAL(returnPressed()),
            this, SLOT(handleReturnPressed()));
}

PowerEdit::~PowerEdit()
{

}

// Public:
void PowerEdit::setParameterName(const QString &name) {
    _name = name;
}

double PowerEdit::power_dBm() const {
    return _power_dBm;
}

void PowerEdit::clearMinimum() {
    _isMinimum = false;
    _minimum_dBm = -150.0;
}
void PowerEdit::clearMaximum() {
    _isMaximum = false;
    _maximum_dBm = 150.0;
}
void PowerEdit::setMinimum(double power_dBm) {
    clearAcceptedValues();

    power_dBm = round(power_dBm, 2);
    _isMinimum = true;
    _minimum_dBm = power_dBm;

    // Check for validity
    if (!text().isEmpty())
        setPower(_power_dBm);
}
void PowerEdit::setMaximum(double power_dBm) {
    clearAcceptedValues();

    power_dBm = round(power_dBm, 2);
    _isMaximum = true;
    _maximum_dBm = power_dBm;

    // Check for validity
    if (!text().isEmpty())
        setPower(_power_dBm);
}

void PowerEdit::clearAcceptedValues() {
    _acceptedValues_dBm.clear();
}
void PowerEdit::setAcceptedValues(const QRowVector &powers_dBm) {
    clearMinimum();
    clearMaximum();

    _acceptedValues_dBm = powers_dBm;
    if (!text().isEmpty()) {
        setPower(_power_dBm);
    }
}

// Slots:
void PowerEdit::setPower(double power_dBm) {
    power_dBm = round(power_dBm, 2);
    if (_isMinimum && power_dBm < _minimum_dBm)
        power_dBm = _minimum_dBm;
    if (_isMaximum && power_dBm > _maximum_dBm)
        power_dBm = _maximum_dBm;

    if (power_dBm == _power_dBm)
        return;

    _power_dBm = power_dBm;
    updateText();
    emit powerChanged(power_dBm);
}
void PowerEdit::setText(const QString &text) {
    QLineEdit::setText(text);
    processText();
}

// Protected
void PowerEdit::focusInEvent(QFocusEvent *event) {
    selectAll();
    QLineEdit::focusInEvent(event);
}
void PowerEdit::focusOutEvent(QFocusEvent *event) {
    processText();
    QLineEdit::focusOutEvent(event);
}

// Private slots
void PowerEdit::handleReturnPressed() {
    processText();
    selectAll();
}

// Private
QString PowerEdit::chopNonDigits(QString text) {
    int last = text.size() - 1;
    while (!text.isEmpty() && !text[last].isDigit()) {
        text.chop(1);
        last = text.size() - 1;
    }
    return text;
}
void PowerEdit::updateText() {
    updateText(_power_dBm);
}
void PowerEdit::updateText(const double &power_dBm) {
    QString text = formatDouble(power_dBm, 2);
    text += " dBm";

    bool isBlocked = blockSignals(true);
    QLineEdit::setText(text);
    blockSignals(isBlocked);
}
void PowerEdit::processText() {
    QString text = this->text();
    if (text.isEmpty() && _power_dBm == 0)
        return;

    text = chopNonDigits(text);
    double power_dBm = text.toDouble();
    power_dBm = round(power_dBm, 2);

    // Acceptable value?
    if (_isMinimum && power_dBm < _minimum_dBm) {
        QString name = _name;
        if (name.isEmpty())
            name = "Points";
        QString msg = "*%1 must be at least %2 dBm";
        msg = msg.arg(name);
        msg = msg.arg(QVariant(_minimum_dBm).toString());
        emit outOfRange(msg);
        power_dBm = _minimum_dBm;
    }
    else if (_isMaximum && power_dBm > _maximum_dBm) {
        QString name = _name;
        if (name.isEmpty())
            name = "Points";
        QString msg = "*%1 must be at most %2 dBm";
        msg = msg.arg(name);
        msg = msg.arg(QVariant(_maximum_dBm).toString());
        emit outOfRange(msg);
        power_dBm = _maximum_dBm;
    }
    else if (isAcceptedValues() && !_acceptedValues_dBm.contains(power_dBm)) {
        power_dBm = findClosest(power_dBm, _acceptedValues_dBm);
    }

    // If value is unchanged, clean up
    // display and return
    if (power_dBm == _power_dBm) {
        updateText();
        return;
    }

    // Change value
    _power_dBm = power_dBm;
    updateText();
    emit powerChanged(_power_dBm);
    emit PowerEdited(_power_dBm);
}

bool PowerEdit::isAcceptedValues() const {
    return !_acceptedValues_dBm.isEmpty();
}
