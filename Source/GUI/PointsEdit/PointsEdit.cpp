

// PointsEdit
#include "PointsEdit.h"

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


PointsEdit::PointsEdit(QWidget *parent) :
    QLineEdit(parent),
    _name("Value"),
    _points(0),
    _isMinimum(true),
    _isMaximum(true),
    _minimum(1),
    _maximum(1000000000)
{
    QRegExp regex("[1-9][0-9]*", Qt::CaseInsensitive);
    QRegExpValidator * validator = new QRegExpValidator(regex, this);
    setValidator(validator);

    connect(this, SIGNAL(returnPressed()),
            this, SLOT(handleReturnPressed()));
}

PointsEdit::~PointsEdit()
{

}

// Public:
void PointsEdit::setParameterName(const QString &name) {
    _name = name;
}

uint PointsEdit::points() const {
    return _points;
}

void PointsEdit::clearMinimum() {
    _isMinimum = false;
    _minimum = 1;
}
void PointsEdit::clearMaximum() {
    _isMaximum = false;
    _maximum = 1000000000;
}
void PointsEdit::setMinimum(uint points) {
    if (points < 1)
        points = 1;
    _isMinimum = true;
    _minimum = points;

    // Check for validity
    if (!text().isEmpty())
        setPoints(_points);
}
void PointsEdit::setMaximum(uint points) {
    if (points < 1)
        points = 1;
    _isMaximum = true;
    _maximum = points;

    // Check for validity
    if (!text().isEmpty())
        setPoints(_points);
}

void PointsEdit::clearLimits() {
    clearMinimum();
    clearMaximum();
}

// Slots:
void PointsEdit::setPoints(uint points) {
    if (points < 1)
        points = 1;
    if (_isMinimum && points < _minimum)
        points = _minimum;
    if (_isMaximum && points > _maximum)
        points = _maximum;

    if (points == _points) {
        updateText();
        return;
    }

    _points = points;
    updateText();
    emit pointsChanged(points);
}
void PointsEdit::setText(const QString &text) {
    QLineEdit::setText(text);
    processText();
}

// Protected
void PointsEdit::focusInEvent(QFocusEvent *event) {
    selectAll();
    QLineEdit::focusInEvent(event);
}
void PointsEdit::focusOutEvent(QFocusEvent *event) {
    processText();
    QLineEdit::focusOutEvent(event);
}

// Private slots
void PointsEdit::handleReturnPressed() {
    processText();
    selectAll();
}

// Private
void PointsEdit::updateText() {
    updateText(_points);
}
void PointsEdit::updateText(const uint &points) {
    QString text = QVariant(points).toString();

    bool isBlocked = blockSignals(true);
    QLineEdit::setText(text);
    blockSignals(isBlocked);
}
void PointsEdit::processText() {
    QString text = this->text();
    if (text.isEmpty() && _points == 0)
        return;

    uint points;
    if (text.toDouble() > UINT_MAX)
        points = UINT_MAX;
    else
        points = text.toUInt();

    // Round to acceptable value
    if (_isMinimum && points < _minimum) {
        QString name = _name;
        if (name.isEmpty())
            name = "Points";
        QString msg = "*%1 must be at least %2";
        msg = msg.arg(name);
        msg = msg.arg(QVariant(_minimum).toString());
        emit outOfRange(msg);
        points = _minimum;
    }
    else if (_isMaximum && points > _maximum) {
        QString name = _name;
        if (name.isEmpty())
            name = "Points";
        QString msg = "*%1 must be at most %2";
        msg = msg.arg(name);
        msg = msg.arg(QVariant(_maximum).toString());
        emit outOfRange(msg);
        points = _maximum;
    }

    // If value is unchanged, clean up
    // display and return
    if (points == _points) {
        updateText();
        return;
    }

    // Change value
    _points = points;
    updateText();
    emit pointsChanged(_points);
    emit pointsEdited(_points);
}

