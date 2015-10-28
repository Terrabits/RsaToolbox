

// FrequencyEdit
#include "FrequencyEdit.h"
#include "ui_FrequencyEdit.h"

// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QRegExp>
#include <QRegExpValidator>
#include <QDebug>

FrequencyEdit::FrequencyEdit(QWidget *parent) :
    QWidget(parent),
    ui(new RsaToolbox::Ui::FrequencyEdit)
{
    ui->setupUi(this);

    QRegExp regex("[0-9]+\\.?[0-9]*[GMK]?", Qt::CaseInsensitive);
    QRegExpValidator * validator = new QRegExpValidator(regex, ui->value);
    ui->value->setValidator(validator);
    connect(ui->value, SIGNAL(textEdited(QString)),
            this, SLOT(processEdit()));
}

FrequencyEdit::~FrequencyEdit()
{
    delete ui;
}

// Public:
double FrequencyEdit::frequency_Hz() const {
    return _frequency_Hz;
}

// Slots:
void FrequencyEdit::clear() {
    bool isBlocked = blockSignals(true);
    ui->value->clear();
    ui->units->setCurrentText("GHz");
    blockSignals(isBlocked);
    processChange();
}
void FrequencyEdit::selectAll() {
    ui->value->selectAll();
}
void FrequencyEdit::setFrequency(double frequency_Hz) {
    if (frequency_Hz < 0)
        return;
    if (frequency_Hz == _frequency_Hz)
        return;

    _frequency_Hz = frequency_Hz;
    displayFrequency(frequency_Hz);
    emit frequencyChanged(_frequency_Hz);
}
void FrequencyEdit::setFrequency(double value, SiPrefix prefix) {
    if (value < 0)
        return;

    const double frequency_Hz = value * toDouble(prefix);
    if (_frequency_Hz == frequency_Hz)
        return;

    _frequency_Hz = frequency_Hz;
    displayFrequency(value, prefix);
    emit frequencyChanged(_frequency_Hz);
}

// Private slots:
void FrequencyEdit::processEdit() {
    if (!ui->value->text().isEmpty()) {
        const int last = ui->value->text().size()-1;
        if (ui->value->text().at(last).isLetter()) {
            QChar letter = ui->value->text().at(last).toUpper().toLatin1();
            QString value = ui->value->text();
            value.chop(1);

            bool isBlocked = blockSignals(true);
            displayPrefix(letter);
            ui->value->setText(value);
            blockSignals(isBlocked);
        }
    }
    double frequency = displayedFrequency();
    if (frequency == _frequency_Hz)
        return;
    if (_isMinimum && frequency < _minimum_Hz) {
        setFrequency(_minimum_Hz);
        emit frequencyEdited(_frequency_Hz);
        return;
    }
    if (_isMaximum && frequency > _maximum_Hz) {
        setFrequency(_maximum_Hz);
        emit frequencyEdited(_frequency_Hz);
        return;
    }
    if (isMantissaValues()) {
        setFrequency(findClosest(frequency, _mantissaValues()));
        emit frequencyEdited(_frequency_Hz);
    }

    _frequency_Hz = frequency;
    emit frequencyChanged(_frequency_Hz);
    emit frequencyEdited(_frequency_Hz);
}
void FrequencyEdit::processChange() {
    double frequency_Hz = displayedFrequency();
    if (frequency_Hz != _frequency_Hz) {
        _frequency_Hz = frequency_Hz;
        emit frequencyChanged(_frequency_Hz);
    }
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
void FrequencyEdit::displayFrequency(double frequency_Hz) {
    double value;
    SiPrefix prefix;
    parseFrequency(frequency_Hz, value, prefix);
    displayFrequency(value, prefix);
}
void FrequencyEdit::displayFrequency(double value, SiPrefix prefix) {
    bool isBlocked = blockSignals(true);
    displayValue(value);
    displayPrefix(prefix);
    blockSignals(isBlocked);
}
void FrequencyEdit::displayValue(double value) {
    displayValue(QVariant(value).toString());
}
void FrequencyEdit::displayValue(const QString &value) {
    ui->value->setText(value);
}
void FrequencyEdit::displayPrefix(const QChar prefix) {
    displayPrefix(toSiPrefix(prefix));
}
void FrequencyEdit::displayPrefix(const SiPrefix prefix) {
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
