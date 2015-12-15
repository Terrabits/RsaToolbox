#include "SpeedTrackerChild.h"


// RsaToolbox
#include <General.h>
using namespace RsaToolbox;

// Qt
#include <QDebug>
#include <QVariant>


SpeedTrackerChild::SpeedTrackerChild() :
    _isRunning(false),
    _time_ms(0)
{

}

SpeedTrackerChild::~SpeedTrackerChild()
{

}

bool SpeedTrackerChild::isRunning() const {
    return _isRunning;
}
void SpeedTrackerChild::start(const QString &name) {
    if (!isRunning()) {
        startSelf(name);
    }
    else if (isRunningChild()) {
        _children.last().start(name);
    }
    else {
        createAndStartChild(name);
    }
}

void SpeedTrackerChild::stop(qint64 &time_ms) {
    if (!isRunningChild()) {
        stopSelf(time_ms);
    }
    else {
        stopChild(time_ms);
    }
}

void SpeedTrackerChild::print(QTextStream &stream, uint depth) const {
    const int LEFT_COLUMN_WIDTH = 20;
    QString indent(2*depth, QChar(' '));
    QString label = "%1%2";
    label = label.arg(indent);
    label = label.arg(_name);
    label.truncate(LEFT_COLUMN_WIDTH - 2);
    label += ": ";

    stream.setFieldAlignment(QTextStream::AlignLeft);
    stream.setFieldWidth(LEFT_COLUMN_WIDTH);
    stream << label;

    stream.setFieldWidth(0);
    if (_time_ms >= 1000)
        stream << formatDouble(double(_time_ms)/1000.0, 3) + " s";
    else
        stream << QVariant(_time_ms).toString() + " ms";
    stream << "\n";

    depth++;
    for (int i = 0; i < _children.size(); i++) {
        _children[i].print(stream, depth);
    }
}

bool SpeedTrackerChild::isRunningChild() const {
    return !_children.isEmpty() && _children.last().isRunning();
}
void SpeedTrackerChild::startSelf(const QString &name) {
    _isRunning = true;
    _name = name;
    _time_ms = 0;
}
void SpeedTrackerChild::createAndStartChild(const QString &name) {
    _children.append(SpeedTrackerChild());
    _children.last().start(name);
}
void SpeedTrackerChild::stopChild(qint64 &time_ms) {
    _children.last().stop(time_ms);

    if (!_children.last().isRunning()) {
        _time_ms += time_ms;
    }
}
void SpeedTrackerChild::stopSelf(qint64 &time_ms) {
    _isRunning = false;
    _time_ms += time_ms;
    time_ms = _time_ms;
}
