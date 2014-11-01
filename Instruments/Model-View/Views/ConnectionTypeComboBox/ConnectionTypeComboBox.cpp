#include "ConnectionTypeComboBox.h"

ConnectionTypeComboBox::ConnectionTypeComboBox(QWidget *parent) :
    QComboBox(parent)
{
    QStringList items;
    items << "TCPIP" << "GPIB" << "USB";
    addItems(items);
}

RsaToolbox::ConnectionType ConnectionTypeComboBox::currentType() {
    QString text = currentText();
    if (text == "TCPIP")
        return RsaToolbox::TCPIP_CONNECTION;
    if (text == "GPIB")
        return RsaToolbox::GPIB_CONNECTION;
    if (text == "USB")
        return RsaToolbox::USB_CONNECTION;
    // Else
    return RsaToolbox::NO_CONNECTION;
}
void ConnectionTypeComboBox::setCurrentType(RsaToolbox::ConnectionType type) {
    if (type == currentType())
        return;

    if (type == RsaToolbox::TCPIP_CONNECTION)
        setCurrentText("TCPIP");
    else if (type == RsaToolbox::GPIB_CONNECTION)
        setCurrentText("GPIB");
    else if (type == RsaToolbox::USB_CONNECTION)
        setCurrentText("USB");
    else
        setCurrentIndex(-1); // UNKNOWN
}

