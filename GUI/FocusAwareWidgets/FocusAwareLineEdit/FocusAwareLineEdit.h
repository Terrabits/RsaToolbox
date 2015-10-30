#ifndef FOCUS_AWARE_LINE_EDIT_H
#define FOCUS_AWARE_LINE_EDIT_H

#include <QLineEdit>


namespace RsaToolbox {

class FocusAwareLineEdit : public QLineEdit {
    Q_OBJECT
public:
    explicit FocusAwareLineEdit(QWidget *parent = 0);
    ~FocusAwareLineEdit();

signals:
    void gainedFocus();
    void lostFocus();

protected:
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};
}

#endif // FOCUS_AWARE_LINE_EDIT_H
