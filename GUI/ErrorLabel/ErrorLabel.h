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

};
}

#endif // ERRORLABEL_H
