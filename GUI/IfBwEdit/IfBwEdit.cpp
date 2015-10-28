

// IfBwEdit
#include "IfBwEdit.h"
#include "ui_IfBwEdit.h"

// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QRegExp>
#include <QRegExpValidator>
#include <QDebug>

IfBwEdit::IfBwEdit(QWidget *parent) :
    QWidget(parent),
    ui(new RsaToolbox::Ui::IfBwEdit)
{
    ui->setupUi(this);

    connect(ui->value, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(processEdit()));
    connect(ui->value, SIGNAL(textEdited(QString)),
            this, SLOT(processEdit()));
}

IfBwEdit::~IfBwEdit()
{
    delete ui;
}

// Public:
double IfBwEdit::frequency_Hz() const {
    return _frequency_Hz;
}

// Slots:
bool IfBwEdit::setFrequency(double frequency_Hz) {
    if (frequency_Hz < 0)
        return false;
    if (frequency_Hz == _frequency_Hz)
        return false;

    _frequency_Hz = frequency_Hz;

    SiPrefix prefix = getPrefix(frequency_Hz);
    const double value = frequency_Hz / toDouble(prefix);

    bool isBlocked = blockSignals(true);
    ui->value->setText(QVariant(value).toString());
    displayPrefix(prefix);
    blockSignals(isBlocked);

    emit frequencyChanged(_frequency_Hz);
    return true;
}
bool IfBwEdit::setFrequency(double value, SiPrefix prefix) {
    if (value < 0)
        return false;

    double frequency_Hz = value * toDouble(prefix);
    if (_frequency_Hz == frequency_Hz)
        return false;

    bool isBlocked = blockSignals(true);
    ui->value->setText(QVariant(value).toString());
    displayPrefix(prefix);
    blockSignals(isBlocked);
    emit frequencyChanged(_frequency_Hz);
    return true;
}

// Private slots:
void IfBwEdit::processEdit() {
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
void IfBwEdit::processChange() {
    double frequency_Hz = displayedFrequency();
    if (frequency_Hz != _frequency_Hz) {
        _frequency_Hz = frequency_Hz;
        emit frequencyChanged(_frequency_Hz);
    }
}

// Private:
void IfBwEdit::displayPrefix(const QChar prefix) {
    displayPrefix(toSiPrefix(prefix));
}
void IfBwEdit::displayPrefix(const SiPrefix prefix) {
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
double IfBwEdit::displayedFrequency() const {
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
