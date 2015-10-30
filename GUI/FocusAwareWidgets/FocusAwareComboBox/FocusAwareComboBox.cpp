#include "FocusAwareComboBox.h"

using namespace RsaToolbox;

#include <QApplication>


FocusAwareComboBox::FocusAwareComboBox(QWidget *parent) :
    QComboBox(parent)
{

}
FocusAwareComboBox::~FocusAwareComboBox()
{

}

void FocusAwareComboBox::focusInEvent(QFocusEvent *event) {
    Q_UNUSED(event);
    emit gainedFocus();
}
void FocusAwareComboBox::focusOutEvent(QFocusEvent *event) {
    Q_UNUSED(event);
    QWidget *focusWidget = QApplication::focusWidget();
    if (focusWidget != (QWidget *)view())
        emit lostFocus();
}
