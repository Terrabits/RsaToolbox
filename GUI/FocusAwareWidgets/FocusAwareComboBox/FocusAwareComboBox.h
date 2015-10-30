#ifndef FOCUS_AWARE_COMBO_BOX_H
#define FOCUS_AWARE_COMBO_BOX_H

#include <QComboBox>


namespace RsaToolbox {

class FocusAwareComboBox : public QComboBox {
    Q_OBJECT
public:
    explicit FocusAwareComboBox(QWidget *parent = 0);
    ~FocusAwareComboBox();

signals:
    void gainedFocus();
    void lostFocus();

protected:
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};
}

#endif // FOCUS_AWARE_COMBO_BOX_H
