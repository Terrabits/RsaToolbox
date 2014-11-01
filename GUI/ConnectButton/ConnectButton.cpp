#include "ConnectButton.h"
using namespace RsaToolbox;


#include <QDebug>


ConnectButton::ConnectButton(QWidget *parent) :
    QPushButton(parent)
{
    _isConnected = false;
    setText("Connect");
}

bool ConnectButton::connected() {
    return _isConnected;
}
void ConnectButton::setConnected(bool isConnected) {
//    qDebug() << "ConnectButton::setConnected" << isConnected;
    if (isConnected == _isConnected)
        return;

    _isConnected = isConnected;
    if (isConnected)
        setText("Disconnect");
    else
        setText("Connect");
    emit connectedChanged(isConnected);
}
