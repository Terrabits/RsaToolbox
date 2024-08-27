#include "PortsLineEdit.h"
using namespace RsaToolbox;

// Qt
#include <QRegularExpression>
#include <QRegularExpressionValidator>


// std lib
#include <algorithm>


PortsLineEdit::PortsLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    QRegularExpression ports("^\\s*(\\d+\\s*(-\\s*\\d+)?\\s*,\\s*)*(\\s*\\d+\\s*(-\\s*\\d+)?\\s*)$");
    setValidator(new QRegularExpressionValidator(ports));
}

QVector<uint> PortsLineEdit::ports() {
    _ports.clear();
    if (!hasAcceptableInput())
        return(_ports);

    QString text = this->text().simplified().remove(" ");
    QStringList words = text.split(",");
    foreach(QString word, words) {
        parsePortEntry(word);
    }
    //qSort(_ports); // Why'd I remove this?
    return(_ports);
}
QVector<uint> PortsLineEdit::sortedPorts() {
    QVector<uint> ports = this->ports();
    std::sort(ports.begin(), ports.end());
    return(ports);
}

void PortsLineEdit::setValidator(const QValidator *validator) {
    QLineEdit::setValidator(validator);
}

void PortsLineEdit::parsePortEntry(QString word) {
    if (word.contains("-")) {
        QStringList list = word.split("-");
        addPorts(list.first().toUInt(), list.last().toUInt());
    }
    else {
        addPort(word.toUInt());
    }
}
void PortsLineEdit::addPort(uint i) {
    if (!_ports.contains(i))
        _ports.append(i);
}
void PortsLineEdit::addPorts(uint start, uint stop) {
    if (start > stop) {
        uint x = start;
        start = stop;
        stop = x;
    }
    for (uint i = start; i <= stop; i++)
        addPort(i);
}

