#include "ErrorLabel.h"
using namespace RsaToolbox;

ErrorLabel::ErrorLabel(QWidget *parent) :
    QStatusBar(parent)
{
    setSizeGripEnabled(false);
    QPalette palette = this->palette();
    palette.setColor(QPalette::WindowText, Qt::red);
    setPalette(palette);
    QFont font = this->font();
    font.setItalic(true);
    setFont(font);
}

void ErrorLabel::showMessage(const QString &message, int timeout) {
    QStatusBar::showMessage(message, timeout);
}
