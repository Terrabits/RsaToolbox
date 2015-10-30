#include "FocusAwareLineEdit.h"

using namespace RsaToolbox;

#include <QApplication>


FocusAwareLineEdit::FocusAwareLineEdit(QWidget *parent) :
    QLineEdit(parent)
{

}
FocusAwareLineEdit::~FocusAwareLineEdit()
{

}

void FocusAwareLineEdit::focusInEvent(QFocusEvent *event) {
    Q_UNUSED(event);
    emit gainedFocus();
}
void FocusAwareLineEdit::focusOutEvent(QFocusEvent *event) {
    Q_UNUSED(event);
    emit lostFocus();
}
