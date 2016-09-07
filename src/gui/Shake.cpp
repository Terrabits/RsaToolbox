#include "Shake.h"


// Qt
#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QRect>
#include <QWidget>


void RsaToolbox::shake(QWidget *widget) {
    QRect startPosition = widget->geometry();
    startPosition.moveRight(startPosition.right() + 10);

    QEasingCurve curve(QEasingCurve::OutElastic);
    curve.setAmplitude(2);
    curve.setPeriod(0.3);

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setStartValue(startPosition);
    animation->setEndValue(widget->geometry());
    animation->setDuration(500);
    animation->setEasingCurve(curve);
    animation->start();
}

