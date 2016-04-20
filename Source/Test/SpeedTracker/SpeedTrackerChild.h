#ifndef SPEEDTRACKERCHILD_H
#define SPEEDTRACKERCHILD_H


// Qt
#include <QString>
#include <QTextStream>
#include <QList>


class SpeedTrackerChild
{
public:
    SpeedTrackerChild();
    ~SpeedTrackerChild();

    bool isRunning() const;
    void start(const QString &name);
    void stop(qint64 &time_ms);

    void print(QTextStream &stream, uint depth) const;

private:
    bool _isRunning;
    QString _name;
    qint64 _time_ms;
    QList<SpeedTrackerChild> _children;

    bool isRunningChild() const;
    void startSelf(const QString &name);
    void createAndStartChild(const QString &name);
    void stopChild(qint64 &time_ms);
    void stopSelf(qint64 &time_ms);
};

#endif // SPEEDTRACKERCHILD_H
