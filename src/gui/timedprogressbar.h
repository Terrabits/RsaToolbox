#ifndef TIMEDPROGRESSBAR_H
#define TIMEDPROGRESSBAR_H

#include <QWidget>
#include <QTimer>


namespace RsaToolbox {


namespace Ui {
class TimedProgressBar;
}

class TimedProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit TimedProgressBar(QWidget *parent = 0);
    ~TimedProgressBar();

    void showPercentage();
    void hidePercentage();

public slots:
    void start(uint stopTime_ms);
    void start(const QString &caption, uint stopTime_ms);
    void stop();

private slots:
    void tick();

private:
    Ui::TimedProgressBar *ui;

    QTimer _timer;
    uint _stopTime_ms;
    uint _ticks;
    double value() const;
    void reset();
};
} // RsaToolbox


#endif // TIMEDPROGRESSBAR_H
