#ifndef ERRORLABEL_H
#define ERRORLABEL_H

#include <QStatusBar>

namespace RsaToolbox {

class ErrorLabel : public QStatusBar
{
    Q_OBJECT
public:
    explicit ErrorLabel(QWidget *parent = 0);

signals:

public slots:
    void showMessage(const QString &message, int timeout = 5000);
    void showMessage(const QString &message, Qt::GlobalColor color, int timeout = 5000);
    void showMessage(const QString &message, QColor color, int timeout = 5000);

};
}

#endif // ERRORLABEL_H
