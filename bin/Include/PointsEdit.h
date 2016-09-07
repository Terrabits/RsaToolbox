#ifndef POINTSEDIT_H
#define POINTSEDIT_H


// RsaToolbox
#include "Definitions.h"

// Qt
#include <QLineEdit>


namespace RsaToolbox {


class PointsEdit : public QLineEdit
{
    Q_OBJECT

public:
    PointsEdit(QWidget *parent = 0);
    ~PointsEdit();

    void setParameterName(const QString &name);

    uint points() const;

    void clearMinimum();
    void clearMaximum();
    void setMinimum(uint points);
    void setMaximum(uint points);

    void clearLimits();

public slots:
    void setText(const QString &text); // Override?
    void setPoints(uint points);

signals:
    void outOfRange(const QString &message);
    void pointsChanged(double points);
    void pointsEdited(double points);

protected:
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);

private slots:
    void handleReturnPressed();

private:
    QString _name;
    uint _points;

    void updateText();
    void updateText(const uint &points);
    void processText();

    bool _isMinimum;
    bool _isMaximum;
    double _minimum;
    double _maximum;

}; // PointsEdit
} // RsaToolbox


#endif // POINTSEDIT_H

