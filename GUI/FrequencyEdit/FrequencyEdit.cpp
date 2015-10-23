

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
    if (frequency_Hz == _frequency_Hz)
        return;

    _frequency_Hz = frequency_Hz;

    SiPrefix prefix = getPrefix(frequency_Hz);
    const double value = frequency_Hz / toDouble(prefix);

    bool isBlocked = blockSignals(true);
    ui->value->setText(QVariant(value).toString());
    displayPrefix(prefix);
    blockSignals(isBlocked);

    emit frequencyChanged(_frequency_Hz);
}
void FrequencyEdit::setFrequency(double value, SiPrefix prefix) {
    double frequency_Hz = value * toDouble(prefix);
    if (_frequency_Hz == frequency_Hz)
        return;

    bool isBlocked = blockSignals(true);
    ui->value->setText(QVariant(value).toString());
    displayPrefix(prefix);
    blockSignals(isBlocked);
    emit frequencyChanged(_frequency_Hz);
}

// Private slots:
void FrequencyEdit::processEdit() {
    qDebug() << "FrequencyEdit::processEdit";
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
    if (frequency != _frequency_Hz) {
        _frequency_Hz = frequency;
        emit frequencyEdited(_frequency_Hz);
        emit frequencyChanged(_frequency_Hz);
    }
}
void FrequencyEdit::processChange() {
    double frequency_Hz = displayedFrequency();
    if (frequency_Hz != _frequency_Hz) {
        _frequency_Hz = frequency_Hz;
        emit frequencyChanged(_frequency_Hz);
    }
}

// Private:
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
