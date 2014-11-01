#include "ConnectionTypeComboBox.h"
using namespace RsaToolbox;


ConnectionTypeComboBox::ConnectionTypeComboBox(QWidget *parent) :
    QComboBox(parent)
{
    QStringList items;
    items << "TCPIP" << "GPIB" << "USB";
    addItems(items);
}

ConnectionType ConnectionTypeComboBox::currentType() {
    QString text = currentText();
    if (text == "TCPIP")
        return TCPIP_CONNECTION;
    if (text == "GPIB")
        return GPIB_CONNECTION;
    if (text == "USB")
        return USB_CONNECTION;
    // Else
    return NO_CONNECTION;
}
void ConnectionTypeComboBox::setCurrentType(ConnectionType type) {
    if (type == currentType())
        return;

    if (type == TCPIP_CONNECTION)
        setCurrentText("TCPIP");
    else if (type == GPIB_CONNECTION)
        setCurrentText("GPIB");
    else if (type == USB_CONNECTION)
        setCurrentText("USB");
    else
        setCurrentIndex(-1); // UNKNOWN
}

