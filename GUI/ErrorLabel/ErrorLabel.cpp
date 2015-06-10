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
    QPalette _palette = palette();
    _palette.setColor(QPalette::WindowText, Qt::red);
    QStatusBar::showMessage(message, timeout);
}
void ErrorLabel::showMessage(const QString &message, Qt::GlobalColor color, int timeout) {
    QPalette _palette = palette();
    _palette.setColor(QPalette::WindowText, color);
    setPalette(_palette);
    QStatusBar::showMessage(message, timeout);
}
void ErrorLabel::showMessage(const QString &message, QColor color, int timeout) {
    QPalette _palette = palette();
    _palette.setColor(QPalette::WindowText, color);
    setPalette(_palette);
    QStatusBar::showMessage(message, timeout);
}
