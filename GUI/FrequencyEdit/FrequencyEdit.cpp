

// FrequencyEdit
#include "FrequencyEdit.h"

// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QRegExp>
#include <QRegExpValidator>
#include <QKeyEvent>
#include <QDebug>



FrequencyEdit::FrequencyEdit(QWidget *parent) :
    QLineEdit(parent),
    _name("Value"),
    _frequency_Hz(-1),
    _isMinimum(true),
    _minimum_Hz(1),
    _isMaximum(true),
    _maximum_Hz(1.0E12)
{
    QRegExp regex("(([0-9]+\\.?[0-9]*)|(\\.0*[1-9]+0*))(\\s?[TGMK]?Hz)?", Qt::CaseInsensitive);
    QRegExpValidator * validator = new QRegExpValidator(regex, this);
    setValidator(validator);

    connect(this, SIGNAL(returnPressed()),
            this, SLOT(handleReturnPressed()));
}

FrequencyEdit::~FrequencyEdit()
{

}

// Public:
void FrequencyEdit::setParameterName(const QString &name) {
    _name = name;
}

double FrequencyEdit::frequency_Hz() const {
    return _frequency_Hz;
}

void FrequencyEdit::clearMinimum() {
    _isMinimum = false;
    _minimum_Hz = 1;
}
void FrequencyEdit::clearMaximum() {
    _isMaximum = false;
    _maximum_Hz = 1.0E12;
}
void FrequencyEdit::setMinimum(double frequency_Hz) {
    clearAcceptedValues();

    if (frequency_Hz < 1)
        frequency_Hz = 1;
    _isMinimum = true;
    _minimum_Hz = frequency_Hz;

    // Check for validity
    if (!text().isEmpty())
        setFrequency(_frequency_Hz);
}
void FrequencyEdit::setMinimum(double value, SiPrefix prefix) {
    setMinimum(value * toDouble(prefix));
}
void FrequencyEdit::setMaximum(double frequency_Hz) {
    clearAcceptedValues();

    if (frequency_Hz < 1)
        frequency_Hz = 1;
    _isMaximum = true;
    _maximum_Hz = frequency_Hz;

    // Check for validity
    if (!text().isEmpty())
        setFrequency(_frequency_Hz);
}
void FrequencyEdit::setMaximum(double value, SiPrefix prefix) {
    setMaximum(value * toDouble(prefix));
}

void FrequencyEdit::clearAcceptedValues() {
    _acceptedValues_Hz.clear();
}
void FrequencyEdit::setAcceptedValues(const QRowVector &frequencies_Hz) {
    clearMinimum();
    clearMaximum();

    _acceptedValues_Hz = frequencies_Hz;
    for (int i = 0; i < _acceptedValues_Hz.size(); i++) {
        if (_acceptedValues_Hz[i] < 0)
            _acceptedValues_Hz.removeAt(i);
    }
    if (!text().isEmpty())
        setFrequency(_frequency_Hz);
}

// Slots:
void FrequencyEdit::setFrequency(double frequency_Hz) {
    if (frequency_Hz < 1)
        frequency_Hz = 1;
    if (_isMinimum && frequency_Hz < _minimum_Hz)
        frequency_Hz = _minimum_Hz;
    if (_isMaximum && frequency_Hz > _maximum_Hz)
        frequency_Hz = _maximum_Hz;
    if (isAcceptedValues())
        frequency_Hz = findClosest(frequency_Hz, _acceptedValues_Hz);

    if (frequency_Hz == _frequency_Hz) {
        updateText();
        return;
    }

    _frequency_Hz = frequency_Hz;
    updateText();
    emit frequencyChanged(_frequency_Hz);
}
void FrequencyEdit::setFrequency(double value, SiPrefix prefix) {
    const double frequency_Hz = value * toDouble(prefix);
    setFrequency(frequency_Hz);
}
void FrequencyEdit::setText(const QString &text) {
    QLineEdit::setText(text);
    processText();
}

// Protected
void FrequencyEdit::keyPressEvent(QKeyEvent *event) {
    Qt::Key key = Qt::Key(event->key());
    if (key != Qt::Key_T
            && key != Qt::Key_G
            && key != Qt::Key_M
            && key != Qt::Key_K)
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
        prefix = SiPrefix::Mega;
        break;
    case Qt::Key_K:
        prefix = SiPrefix::Kilo;
        break;
    default:
        prefix = SiPrefix::None;
    }
    QString text = this->text();
    text = chopNonDigits(text);
    updateText(text.toDouble() * toDouble(prefix));
    processText();
    selectAll();
}
void FrequencyEdit::focusInEvent(QFocusEvent *event) {
    selectAll();
    QLineEdit::focusInEvent(event);
}
void FrequencyEdit::focusOutEvent(QFocusEvent *event) {
    processText();
    QLineEdit::focusOutEvent(event);
}

// Private slots
void FrequencyEdit::handleReturnPressed() {
    processText();
    selectAll();
}

// Private
bool FrequencyEdit::containsT(const QString &text) {
    return text.contains("T", Qt::CaseInsensitive);
}

bool FrequencyEdit::containsG(const QString &text) {
    return text.contains("G", Qt::CaseInsensitive);
}
bool FrequencyEdit::containsM(const QString &text) {
    return text.contains("M", Qt::CaseInsensitive);
}
bool FrequencyEdit::containsK(const QString &text) {
    return text.contains("K", Qt::CaseInsensitive);
}
QString FrequencyEdit::chopNonDigits(QString text) {
    int last = text.size() - 1;
    while (!text.isEmpty() && !text[last].isDigit()) {
        text.chop(1);
        last = text.size() - 1;
    }
    return text;
}
void FrequencyEdit::updateText() {
    updateText(_frequency_Hz);
}
void FrequencyEdit::updateText(const double &frequency_Hz) {
    QString text = formatValue(frequency_Hz, 6, Units::Hertz);

    bool isBlocked = blockSignals(true);
    QLineEdit::setText(text);
    blockSignals(isBlocked);
}
void FrequencyEdit::processText() {
    QString text = this->text();
    if (text.isEmpty() && _frequency_Hz == -1)
        return;

    SiPrefix prefix = SiPrefix::None;
    if (containsT(text))
        prefix = SiPrefix::Tera;
    else if (containsG(text))
        prefix = SiPrefix::Giga;
    else if (containsM(text))
        prefix = SiPrefix::Mega;
    else if (containsK(text))
        prefix = SiPrefix::Kilo;

    // Apply prefix
    text = chopNonDigits(text);
    double frequency_Hz = text.toDouble() * toDouble(prefix);

    // Round to acceptable value
    if (_isMinimum && frequency_Hz < _minimum_Hz) {
        QString name = _name;
        if (name.isEmpty())
            name = "Value";
        QString msg = "*%1 must be at least %2";
        msg = msg.arg(name);
        msg = msg.arg(formatValue(_minimum_Hz, 3, Units::Hertz));
        emit outOfRange(msg);
        frequency_Hz = _minimum_Hz;
    }
    else if (_isMaximum && frequency_Hz > _maximum_Hz) {
        QString name = _name;
        if (name.isEmpty())
            name = "Value";
        QString msg = "*%1 must be at most %2";
        msg = msg.arg(name);
        msg = msg.arg(formatValue(_maximum_Hz, 3, Units::Hertz));
        emit outOfRange(msg);
        frequency_Hz = _maximum_Hz;
    }
    else if (isAcceptedValues() && !_acceptedValues_Hz.contains(frequency_Hz)) {
        double newFrequency_Hz = findClosest(frequency_Hz, _acceptedValues_Hz);
        if (newFrequency_Hz != frequency_Hz) {
            QString msg = "*%1 Rounded to closest value: %2";
            msg = msg.arg(formatValue(frequency_Hz, 3, Units::Hertz));
            msg = msg.arg(formatValue(newFrequency_Hz, 3, Units::Hertz));
            emit outOfRange(msg);

            frequency_Hz = newFrequency_Hz;
        }
    }

    // If value is unchanged, clean up
    // display and return
    if (frequency_Hz == _frequency_Hz) {
        updateText();
        return;
    }

    // Change value
    _frequency_Hz = frequency_Hz;
    updateText();
    emit frequencyChanged(_frequency_Hz);
    emit frequencyEdited(_frequency_Hz);
}

bool FrequencyEdit::isAcceptedValues() const {
    return !_acceptedValues_Hz.isEmpty();
}

