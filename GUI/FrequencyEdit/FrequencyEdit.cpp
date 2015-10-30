

// FrequencyEdit
#include "FrequencyEdit.h"
#include "ui_FrequencyEdit.h"

// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QApplication>
#include <QRegExp>
#include <QRegExpValidator>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDebug>



FrequencyEdit::FrequencyEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrequencyEdit),
    _name("Frequency"),
    _isMinimum(false),
    _minimum_Hz(0),
    _isMaximum(false),
    _maximum_Hz(DBL_INF)
{
    ui->setupUi(this);

    clear();
    QRegExp regex("(([0-9]+\\.?[0-9]*)|(\\.[0-9]+))[GMK]?", Qt::CaseInsensitive);
    QRegExpValidator * validator = new QRegExpValidator(regex, ui->value);
    ui->value->setValidator(validator);
    connect(ui->value, SIGNAL(textEdited(QString)),
            this, SLOT(valueEdited(QString)));
    connect(ui->value, SIGNAL(lostFocus()),
            this, SLOT(childLostFocus()));
    connect(ui->units, SIGNAL(lostFocus()),
            this, SLOT(childLostFocus()));
}

FrequencyEdit::~FrequencyEdit()
{

}

// Public:
void FrequencyEdit::setParameterName(const QString &name) {
    _name = name;
}

bool FrequencyEdit::hasAcceptableInput() const {
    if (!ui->value->hasAcceptableInput())
        return false;
    const double freq_Hz = displayedFrequency();
    if (_isMinimum && freq_Hz < _minimum_Hz)
        return false;
    if (_isMaximum && freq_Hz > _maximum_Hz)
        return false;
    if (isMantissaValues() && !_mantissaValues_Hz.contains(freq_Hz))
        return false;

    return true;
}

double FrequencyEdit::frequency_Hz() const {
    return displayedFrequency();
}

void FrequencyEdit::clearMinimum() {
    _isMinimum = false;
    _minimum_Hz = 0;
}
void FrequencyEdit::clearMaximum() {
    _isMaximum = false;
    _maximum_Hz = 1.0E15;
}
void FrequencyEdit::setMinimum(double frequency_Hz) {
    if (frequency_Hz < 0)
        frequency_Hz = 0;
    _isMinimum = true;
    _minimum_Hz = frequency_Hz;
}
void FrequencyEdit::setMinimum(double value, SiPrefix prefix) {
    setMinimum(value * toDouble(prefix));
}
void FrequencyEdit::setMaximum(double frequency_Hz) {
    if (frequency_Hz < 0)
        frequency_Hz = 0;
    _isMaximum = true;
    _maximum_Hz = frequency_Hz;
}
void FrequencyEdit::setMaximum(double value, SiPrefix prefix) {
    setMaximum(value * toDouble(prefix));
}

void FrequencyEdit::clearMantissaValues() {
    _mantissaValues_Hz.clear();
}
void FrequencyEdit::setMantissaValues(QRowVector frequencies_Hz) {
    _mantissaValues_Hz = frequencies_Hz;
    for (int i = 0; i < _mantissaValues_Hz.size(); i++) {
        if (_mantissaValues_Hz[i] < 0)
            _mantissaValues_Hz.removeAt(i);
    }
}

// Slots:
void FrequencyEdit::clear() {
    bool isBlocked = blockSignals(true);
    ui->value->clear();
    ui->units->setCurrentText("GHz");
    blockSignals(isBlocked);
    _frequency_Hz = 0;
}
void FrequencyEdit::selectAll() {
    ui->value->selectAll();
}
void FrequencyEdit::setFrequency(double frequency_Hz) {
    if (frequency_Hz < 0)
        frequency_Hz = 0;
    if (_isMinimum && frequency_Hz < _minimum_Hz)
        frequency_Hz = _minimum_Hz;
    if (_isMaximum && frequency_Hz > _maximum_Hz)
        frequency_Hz = _maximum_Hz;
    if (isMantissaValues())
        frequency_Hz = findClosest(frequency_Hz, _mantissaValues_Hz);

    if (frequency_Hz == _frequency_Hz)
        return;

    _frequency_Hz = frequency_Hz;
    displayFrequency(frequency_Hz);
    emit frequencyChanged(_frequency_Hz);
}
void FrequencyEdit::setFrequency(double value, SiPrefix prefix) {
    double frequency_Hz = value * toDouble(prefix);
    if (frequency_Hz < 0)
        frequency_Hz = 0;
    if (_isMinimum && frequency_Hz < _minimum_Hz)
        frequency_Hz = _minimum_Hz;
    if (_isMaximum && frequency_Hz > _maximum_Hz)
        frequency_Hz = _maximum_Hz;
    if (isMantissaValues())
        frequency_Hz = findClosest(frequency_Hz, _mantissaValues_Hz);

    if (frequency_Hz == _frequency_Hz)
        return;

    _frequency_Hz = frequency_Hz;
    if (_frequency_Hz == value * toDouble(prefix))
        displayFrequency(value, prefix);
    else
        displayFrequency(_frequency_Hz);
    emit frequencyChanged(_frequency_Hz);
}

// Private slots:
void FrequencyEdit::childLostFocus() {
    if (ui->value->hasFocus() || ui->units->hasFocus())
        return;
    if (!ui->value->hasAcceptableInput())
        return;

    // Add leading zero if number
    // starts with '.'
    QString text = ui->value->text();
    if (text[0].isPunct()) {
        text.prepend("0");
        ui->value->setText(text);
    }

    // Remove unnecessary trailing '.'
    const int last = text.size()-1;
    if (text[last].isPunct()) {
        text.chop(1);
        ui->value->setText(text);
    }

    double freq_Hz = displayedFrequency();
    if (_isMinimum && freq_Hz < _minimum_Hz) {
        freq_Hz = _minimum_Hz;
        displayFrequency(freq_Hz);

        // Emit error
        QString msg = "*%1 must be greater than %2";
        msg = msg.arg(_name);
        msg = msg.arg(formatValue(_minimum_Hz, 3, Units::Hertz));
        emit outOfRange(msg);
    }
    else if (_isMaximum && freq_Hz > _maximum_Hz) {
        freq_Hz = _maximum_Hz;
        displayFrequency(freq_Hz);

        // Emit error
        QString msg = "*%1 must be less than %2";
        msg = msg.arg(_name);
        msg = msg.arg(formatValue(_maximum_Hz, 3, Units::Hertz));
        emit outOfRange(msg);
    }
    else if (isMantissaValues()) {
        // Round to mantissa value quietly
        double closestFreq_Hz = findClosest(freq_Hz, _mantissaValues_Hz);
        if (freq_Hz != closestFreq_Hz) {
            freq_Hz = closestFreq_Hz;
            displayFrequency(freq_Hz);
        }
    }

    if (freq_Hz == _frequency_Hz)
        return;

    _frequency_Hz = freq_Hz;
    emit frequencyChanged(_frequency_Hz);
    emit frequencyEdited(_frequency_Hz);
}
void FrequencyEdit::valueEdited(QString value) {
    if (value.isEmpty())
        return;

    const int last = value.size()-1;
    if (!value[last].isLetter())
        return;

    QChar letter = value[last].toUpper();
    value.chop(1);
    ui->value->setText(value);
    displayPrefix(letter);
}

// Private:
void FrequencyEdit::parseFrequency(double frequency_Hz, double &value, SiPrefix &prefix) {
    prefix = getPrefix(frequency_Hz);
    value = frequency_Hz / toDouble(prefix);
}
void FrequencyEdit::parseDisplay(double &value, SiPrefix &prefix) {
    if (ui->value->text().isEmpty()) {
        value = 0;
        prefix = SiPrefix::None;
        return;
    }

    value = ui->value->text().toDouble();
    const QString units = ui->units->currentText();
    if (units == "Hz")
        prefix = SiPrefix::None;
    else if (units == "KHz")
        prefix = SiPrefix::Kilo;
    else if (units == "MHz")
        prefix = SiPrefix::Mega;
    else if (units == "GHz")
        prefix = SiPrefix::Giga;
    else if (units == "THz")
        prefix = SiPrefix::Tera;
    else
        prefix = SiPrefix::None;
}
void FrequencyEdit::displayFrequency(const double &frequency_Hz) {
    double value;
    SiPrefix prefix;
    parseFrequency(frequency_Hz, value, prefix);
    displayFrequency(value, prefix);
}
void FrequencyEdit::displayFrequency(const double &value, const SiPrefix &prefix) {
    bool isBlocked = blockSignals(true);
    displayValue(value);
    displayPrefix(prefix);
    blockSignals(isBlocked);
}
void FrequencyEdit::displayValue(const double &value) {
    displayValue(QVariant(value).toString());
}
void FrequencyEdit::displayValue(const QString &value) {
    ui->value->setText(value);
}
void FrequencyEdit::displayPrefix(const QChar &prefix) {
    displayPrefix(toSiPrefix(prefix));
}
void FrequencyEdit::displayPrefix(const SiPrefix &prefix) {
    QString units;
    switch(prefix) {
    case SiPrefix::Tera:
        units = "THz";
        break;
    case SiPrefix::Giga:
        units = "GHz";
        break;
    case SiPrefix::Mega:
        units = "MHz";
        break;
    case SiPrefix::Kilo:
        units = "KHz";
        break;
    default:
        units = "Hz";
    }
    ui->units->setCurrentText(units);
}

bool FrequencyEdit::isMantissaValues() const {
    return !_mantissaValues_Hz.isEmpty();
}

double FrequencyEdit::displayedFrequency() const {
    if (ui->value->text().isEmpty())
        return 0;

    double value = ui->value->text().toDouble();
    const QString units = ui->units->currentText();

    if (units.size() == 3) {
        const SiPrefix prefix = toSiPrefix(units.at(0));
        value *= toDouble(prefix);
    }

    return value;
}
