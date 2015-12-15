#include "SpeedTracker.h"


// RsaToolbox
#include <General.h>
using namespace RsaToolbox;

// Qt
#include <QDebug>
#include <QFile>
#include <QTextStream>


SpeedTracker::SpeedTracker()
{

}

SpeedTracker::~SpeedTracker()
{

}

bool SpeedTracker::isRunning() const {
    return isRunningChild();
}
void SpeedTracker::startTask(const QString &name) {
    if (isRunningChild()) {
        _children.last().start(name);
    }
    else {
        _children.append(SpeedTrackerChild());
        _children.last().start(name);
    }


    // Start timer immediately
    // before returning!
    _timer.invalidate();
    _timer.start();
}
qint64 SpeedTracker::stopTask() {
    // Stop timer immediately!
    qint64 time_ms = _timer.elapsed();

    // If timer was invalid,
    // then stopping a parent test.
    // Else finished child test
    // and invalidate timer
    if (!_timer.isValid())
        time_ms = 0;
    else
        _timer.invalidate();

    if (!isRunningChild()) {
        // No child to stop!
        return -1;
    }

    _children.last().stop(time_ms);
    return time_ms;
}

bool SpeedTracker::save(const QString &filename) const {
    QFile file(filename);
    if (!file.open(QFile::WriteOnly))
            return false;

    QTextStream stream(&file);
    for (int i = 0; i < _children.size(); i++) {
        _children[i].print(stream, 0);
    }
    stream.flush();
    file.close();
    return true;
}

bool SpeedTracker::isRunningChild() const {
    return !_children.isEmpty() && _children.last().isRunning();
}
