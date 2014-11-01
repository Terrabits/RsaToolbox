#ifndef CONNECTBUTTON_H
#define CONNECTBUTTON_H

#include <QPushButton>

class ConnectButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ connected WRITE setConnected NOTIFY connectedChanged)
public:
    explicit ConnectButton(QWidget *parent = 0);

    bool connected();

signals:
    void connectedChanged(bool isConnected);

public slots:
    void setConnected(bool isConnected);

private:
    bool _isConnected;
};

#endif // CONNECTBUTTON_H
