

// Qt
#include "PortsLineEdit.h"
#include <QRegExp>
#include <QRegExpValidator>

PortsLineEdit::PortsLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    QRegExp ports("^\\s*(\\d+\\s*(-\\s*\\d+)?\\s*,\\s*)*(\\s*\\d+\\s*(-\\s*\\d+)?\\s*)$");
    setValidator(new QRegExpValidator(ports));
}

QVector<uint> PortsLineEdit::ports() {
    _ports.clear();
    if (!hasAcceptableInput())
        return(_ports);

    QString text = this->text().simplified().remove(" ");
    QStringList words = text.split(",");
    foreach(QString word, words)
        parsePortEntry(word);
    //qSort(_ports);
    return(_ports);
}
QVector<uint> PortsLineEdit::sortedPorts() {
    QVector<uint> ports = this->ports();
    qSort(ports);
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

