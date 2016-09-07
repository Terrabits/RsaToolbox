#ifndef SPEEDTRACKER_H
#define SPEEDTRACKER_H


// Project
#include "SpeedTrackerChild.h"

// Qt
#include <QString>
#include <QElapsedTimer>
#include <QList>


class SpeedTracker
{
public:
    SpeedTracker();
    ~SpeedTracker();

    bool isRunning() const;
    void startTask(const QString &name);
    qint64 stopTask();

    bool save(const QString &filename) const;

private:
    QElapsedTimer _timer;

    bool isRunningChild() const;
    QList<SpeedTrackerChild> _children;
};

#endif // SPEEDTRACKER_H
