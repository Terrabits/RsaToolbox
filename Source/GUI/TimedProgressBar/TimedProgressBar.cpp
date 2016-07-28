#include "TimedProgressBar.h"
#include "ui_TimedProgressBar.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QDebug>

// std lib
#include <cmath>


TimedProgressBar::TimedProgressBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimedProgressBar),
    _ticks(0)
{
    ui->setupUi(this);

    ui->progressBar->setRange(0, 1000);
    ui->progressBar->setTextVisible(false);
    ui->progressBar->reset();
    ui->progressBar->setVisible(false);
    ui->label->clear();

    connect(&_timer, SIGNAL(timeout()),
            this, SLOT(tick()));
}

TimedProgressBar::~TimedProgressBar()
{
    delete ui;
}

void TimedProgressBar::showPercentage() {
    ui->progressBar->setTextVisible(true);
}
void TimedProgressBar::hidePercentage() {
    ui->progressBar->setTextVisible(false);
}

void TimedProgressBar::start(uint stopTime_ms) {
    reset();

    ui->progressBar->setVisible(true);

    _stopTime_ms = stopTime_ms;
    _timer.start(10);
}
void TimedProgressBar::start(const QString &caption, uint stopTime_ms) {
    reset();

    ui->label->setText(caption);
    ui->progressBar->setVisible(true);

    _stopTime_ms = stopTime_ms;
    _timer.start(10);
}
void TimedProgressBar::stop() {
    reset();
}

void TimedProgressBar::tick() {
    _ticks++;
    ui->progressBar->setValue(value());
}

double TimedProgressBar::value() const {
    return 1000.0 * (1 - std::exp(-30.0 * double(_ticks) / double(_stopTime_ms+1000)));
}
void TimedProgressBar::reset() {
    if (_timer.isActive())
        _timer.stop();

    _ticks = 0;

    ui->progressBar->reset();
    ui->progressBar->setVisible(false);
    ui->label->clear();
}
